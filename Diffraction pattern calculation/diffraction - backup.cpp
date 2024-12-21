#include<iostream>
#include<istream>
#include<ostream>
#include<cmath>
#include<fstream>
#include<ctime>

const double PI = std::atan(1.0) * 4;
const double Flux_0=1.0; //flux quanta
const double Jc=1.0; //supercurrent density along the junction
const double w=1.0; //width of the JJ, along the barrier perpendicular to the current, y direction, -w/2~+w/2
const int Nw =1001; //total steps of w
const double FluxRange =5; //field range in terms of Flux_0, -FluxRange~+FluxRange
const int Nflux =1000; //total steps of flux
const double PhaseRange =(4 * PI); //range of phase space, say -PhaseRange/2~+PhaseRange/2
const int Nphase =1000; //total steps of phase



double cpr_regular(double phase)
{
	return std::sin(phase);
}

double i_y_F(double y, double p0, double flux)
{
	double t,p;

	p = y / w * flux / Flux_0 * 2 * PI+p0;
	t = cpr_regular(p);
	return t;
}

double totalCurrent(double p0, double flux)
{
	double sum(0);

	for (int i = 0; i < Nw; i++) {
		sum += Jc / Nw * i_y_F(-w / 2.0 + w / (Nw - 1) * i,p0, flux);
	}
	return sum;
}

void findIc(double flux,double *icp,double *icn)
{
	double t(0),p(0);
	*icp = *icn = 0;

	
	for (int i(0); i < Nphase; i++) {
		p = -1.0 * PhaseRange/2 + PhaseRange / ((double)Nphase-1) * i;
		t = totalCurrent(p, flux);
		if (t > * icp) *icp = t;
		if (t < *icn) *icn = t;
	}
	
}


int main()
{
	double flux(0), icp[Nflux], icn[Nflux];
	FILE * pipe;
	clock_t t;
	
	std::ofstream data("data.dat");
	t = clock();
	for (int i = 0; i < Nflux; i++) {
		flux = -1.0*FluxRange + i * FluxRange * 2.0 / Nflux;
		findIc(flux, &icp[i], &icn[i]);
		data << flux << "\t" << icp[i] << "\t" << icn[i] << "\n";
		//if(i%10==0)
		//	std::cout << (float)i/Nflux*100 << "%\t"<< flux << "\t" << icp[i] << "\t" << icn[i] << "\n";
	}
	t = clock() - t;
	printf("%f\n", (double)t / CLOCKS_PER_SEC);
	data.close();

	pipe = _popen("C:\\\"Program Files\"\\gnuplot\\bin\\gnuplot.exe", "w");
	fprintf(pipe, "plot \'data.dat\'\n");
	fflush(pipe);
	getchar();
	_pclose(pipe);

	return 0;
}