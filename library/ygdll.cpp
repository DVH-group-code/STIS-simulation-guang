#define _USE_MATH_DEFINES
#include"ygdll.hpp"
#include<omp.h>
#include<cmath>
#include<sstream>
#include<ostream>
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include"escape_rate.hpp"

//assume the magnetic field is in unit of flux quanta
//assume the critical current density is 1
//assume the junction width is 1, [-0.5,0.5] range along y direction
#define Flux_0 1.0 //flux quanta
#define Jc 1.0 //supercurrent density along the junction
#define w 1.0 //width of the JJ, along the barrier perpendicular to the current, y direction, -w/2~+w/2
int Nw = 1001; //total steps of w 
double PhaseRange = (4.0*M_PI); //range of phase space, say -PhaseRange/2~+PhaseRange/2, this value has to be larger than Flux_max*2Pi+range of phase parity can vary.
int Nphase = 1001; //total steps of phase
double a = 0.5;//amplitude of MBS current
double gw = 0.2;// gaussian width
int* parity; //array of parities
int parity_l=0; //length of the parity array
int cprt = 0;//type of cpr: 0, regular; 1, sin(phi)+sin(phi/2); 2, sin(phi/2) with gaussian localization; 3, MBS localized with parity pattern, CPR has to have peroid of PhaseRange
int abc = 0;
double *Jnoise=NULL;//array of noise factor, the length equal to the number of y steps.
int Jnt = 0; //geometry disorder type for the J along y. 0 is uniform, 1 is user defined noise profile.
double T(0.05); //temperature in K
double C0(0.5e-12); //default capacitance F
double Ic(4.0e-6); //critical current of the JJ
double R(18);  //resistance R of RCSJ module
double Imax(5e-6); //max current at the end of the ramp
double Tsw(10.0e-3); //max time length of current ramp
int Nstep(10000); //time step for max time length
double Lcut(0.9); //below such ratio the escape rate is cosidered zero
double Ic_d(0.02); //bi-modulation width
double F_parity(10e3);// parity change frequency Hz
double Ic_md_ratio(0.5);//time over total the system in Ic-d/2 state
int Nsweeps(10000); //number of sweeps for distribution
int P_mode(0); //parity change style, 0 for no parity, 1 for simple parity change, 2 for Ic-Ic_d/2, 3 for Ic+Ic_d/2, 4 for constant parity state lifetime. 
//5, sin(wt) change of two states ratio
//int G_mode(0); // escaping rate gtype=0 for TA, 1 for MQT, 2 for TA+MQT

void setup_dist_para(double temp, double c, double ic, double r, double im, double tsw, int nstep, double lcut, double ic_d, double fparity, double icr, int sweeps, int pmode)
{
	T = temp;
	C0 = c;
	Ic = ic;
	R = r;
	Imax = im;
	Tsw = tsw;
	Nstep = nstep;
	Lcut = lcut;
	Ic_d = ic_d;
	F_parity = fparity;
	Ic_md_ratio = icr;
	Nsweeps = sweeps;
	P_mode = pmode;
}

void setparameters(int Jnt0, int nw, int phaserange0, int nphase, int cpr0,double a0, double gw0,int* parity0, int parity_l0)
{
	Nw = nw;
	PhaseRange = M_PI*phaserange0;
	Nphase = nphase;
	parity = parity0;
	parity_l = parity_l0;
	gw = gw0;
	a = a0;
	cprt = cpr0;
	Jnt = Jnt0;
}

void setJnoise(double* noise)
{
	Jnoise = noise;
}

double gaussian(double x, double x0, double gw)
{
	return exp(-(x - x0)*(x-x0)/2/gw/gw);
}

double cpr_multi(double phase)
{
	int n;
	double r=0,quo=0,frac=0,pp=1,pn=1;

	switch (cprt) 
	{
	case 0:
		return sin(phase);
	case 1:
		return sin(phase)+a*sin(phase/2);
	case 2:
		n = (int)(PhaseRange / M_PI/4);
		frac = modf((phase+PhaseRange/2) / PhaseRange, &quo);
		if (frac >= 0)
			phase = PhaseRange * frac - PhaseRange / 2;
		else
			phase = PhaseRange * frac + PhaseRange / 2;
		r = sin(phase);
		for (int i = 0; i <n; i++) {
			r += a * gaussian(phase, 2.0*i * M_PI+M_PI, gw) * sin(phase / 2)+ a * gaussian(phase, -2.0*i* M_PI-M_PI, gw) * sin(phase/2);
		}
		return r;
	case 3:
		n = (int)(PhaseRange / M_PI / 4);
		frac = modf((phase + PhaseRange / 2) / PhaseRange, &quo);
		if (frac >= 0)
			phase = PhaseRange * frac - PhaseRange / 2;
		else
			phase = PhaseRange * frac + PhaseRange / 2;
		r = sin(phase);
		for (int i = 0; i < n; i++) {
			if (i < parity_l / 2) {
				pn = parity[parity_l / 2 + i];
				pp = parity[parity_l/2-i-1];
			}
			else{ 
				pn = pp = 1; 
			}
			r += a * gaussian(phase, 2.0*i * M_PI + M_PI, gw) * sin(phase / 2)*pn + a * gaussian(phase, -2.0 * i * M_PI - M_PI, gw) * sin(phase/2)*pp;
		}
		return r;
	default:
		return 0;
	}
}



double i_y_F(double y, double p0, double flux)
{
	double t, p;

	p = y / w * flux / Flux_0 * 2 * M_PI + p0;
	if (Jnt==0)
		t = Jc / Nw * cpr_multi(p);
	else
		t = Jc / Nw * Jnoise[(int)((y+w/2)/w*(Nw-1))] * cpr_multi(p);
	return t;
}

double totalCurrent(double p0, double flux)
{
	double sum = 0;

	for (int i = 0; i < Nw; i++) {
		sum += i_y_F(-w / 2.0 + i*w /((double)Nw - 1), p0, flux);
	}
	return sum;
}

void findIc(double flux, double* icp, double* icn, double *pp0,double *pn0)
{
	double* icpp, * icnp, * pp0p, * pn0p;
	int maxThreads,nt;

	*icp = *icn =*pp0=*pn0=0;
	maxThreads = omp_get_max_threads();
	icpp = new double[maxThreads];
	icnp = new double[maxThreads];
	pp0p = new double[maxThreads];
	pn0p = new double[maxThreads];
#pragma omp parallel
	{
		int id, istart, iend,NThread;
		double t = 0, p = 0;
		id = omp_get_thread_num();
		NThread = omp_get_num_threads();
		if (id == 0) nt = NThread;
		istart = id * Nphase / NThread;
		if (id == NThread - 1) 
			iend = Nphase;
		else 
			iend = (id + 1) * Nphase / NThread;
		icpp[id] = icnp[id] = pp0p[id] = pn0p[id] = 0;
		for (int i = istart; i < iend; i++) {
			p = -1.0 * PhaseRange / 2 + PhaseRange / ((double)Nphase - 1) * i;
			t = totalCurrent(p, flux);
			if (t > icpp[id]) {
				icpp[id] = t;
				pp0p[id] = p;
			}
			if (t < icnp[id]) {
				icnp[id] = t;
				pn0p[id] = p;
			}
		}
	}
	for (int i = 0; i < nt; i++) {
		if (*icp < icpp[i]) {
			*icp = icpp[i];
			*pp0 = pp0p[i];
		}
		if (*icn > icnp[i]) {
			*icn = icnp[i];
			*pn0 = pn0p[i];
		}
	}
	*pp0 = *pp0 / M_PI;
	*pn0 = *pn0 / M_PI;
	delete[] icpp;
	delete[] icnp;
	delete[] pp0p;
	delete[] pn0p;
}

double Gt_dll(double current) 
{
	return Gt(current, Ic);
}

double Gq_dll(double current) 
{
	return Gq(current, Ic);
}

double Get_Ic(int gtype) 
{
	return oneswitch(P_mode, gtype);
}

//integral of supercurrent
double Int_It(double p_i, double p_f, double flux)
{
	double p_step(0), p(0);
	double sum(0);

	p = p_i;
	p_step = PhaseRange / (Nphase - 1.0);
	if (p_i > p_f) p_step = -p_step;
	for (int i=0; i< abs((p_f-p_i)/p_step); i++){
		sum += totalCurrent(p, flux) * p_step;
		p += p_step;
	}
	return sum;
}

//washboard potential
double washboard_extend(double i, double flux, double p0, double c0)
{
	return -i * p0 + Int_It(0, p0, flux) + c0;
}

int p_data_len()
{
	return (int)(50 + 12.0 * Imax / Istep);
}

void get_parity_data(char* data, int size)
{
	Parity p_info(5489u);
	double current(0), t(0), p(0);

	ostringstream sdata;
	current = Ic * (1 - Ic_d / 2) * Lcut;
	t = current / Istep * Tstep;
	sdata << "Time\tCurrent\tGt\tparity\tGtm\tGtp\n";
	cout << "ygdll: calculate parity data:\n";
	while (current <= Imax) {
		p = p_info.current_parity(P_mode, t);
		sdata
			<< t << '\t' << current * 1e6 << '\t'
			<< Gt(current, Ic) << '\t' << p << '\t'
			<< Gt(current, Ic * (1 - Ic_d / 2)) << '\t' << Gt(current, Ic * (1 + Ic_d / 2))
			<< endl;
		current += Istep;
		t += Tstep;
		cout << '\r' << current / Imax * 100 << "\t%";
	}
	strcpy_s(data, p_data_len()+1, sdata.str().c_str());
}
