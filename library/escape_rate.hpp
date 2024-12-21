#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include<random>

#define Phi_0 2.07e-15 //Wb
#define kB 1.38e-23 //boltzman constant J/K
#define hbar 1.0545718e-34 //hbar
#define Tstep (Tsw/Nstep) //time step
#define Istep (Imax/Nstep)//current step

using namespace std;
extern double wp(double current, double ic);
extern double Uheight(double current, double ic);
extern double Gt(double current, double ic);
extern double Gq(double current, double ic);
extern double oneswitch(int ptype,int gtype);
extern double Gtp(double current, double ic, int gtype);
//these global parameters will be defined in escape_rate.cpp or initialized with dll function
extern double T; //temperature in K
extern double C0; //default capacitance F
extern double Ic;//default Ic A
extern double R;  //resistance R of RCSJ module
extern double Imax; //max current at the end of the ramp
extern  double Tsw;//max time length of current ramp
extern  int Nstep; //time step for max time length
extern double Lcut; //below such ratio the escape rate is cosidered zero
extern double Ic_d; //bi-modulation width
extern double F_parity;// parity change frequency Hz
extern double Ic_md_ratio;//time over total the system in Ic-d/2 state
extern int Nsweeps; //number of sweeps for distribution
extern int P_mode; //parity change style, 0 for no parity, 1 for simple parity change, 2 for Ic-Ic_d/2, 3 for Ic+Ic_d/2, 4 for constant parity state lifetime. 
//5, sin(wt) change of two states ratio
//extern int G_mode; //escaping rate gtype=0 for TA, 1 for MQT, 2 for TA+MQT

//class define
//return parity value at certain time, the time has to start 0 and increase gradually
class Parity {
	double start, end, length, p, phase;
	//random number generator DEFINE
	mt19937 rand_gen;
	uniform_real_distribution<double> rand01;
	exponential_distribution<double> erand1;
	exponential_distribution<double> erand2;
public:
	Parity(unsigned seed);
	int parity_exp(double time);
	int random_event(double probability);
	int current_parity(int mode, double time);
	int parity_flat(double time);
};



