#include"escape_rate.hpp"
#include<chrono>
#include<sstream>
#include<ostream>
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>


//plasma frequency
double wp(double current, double ic)
{
	return sqrt(2.0 * M_PI * ic / Phi_0 / C0) * pow(1 - pow(current / ic,2), 0.25);
}

//barrier height
double Uheight(double current, double ic)
{
	return 2 * sqrt(2) * ic * Phi_0 / 3 / M_PI * pow(1 - current / ic, 1.5);
}

//Thermal activated escaping rate
double Gt(double current, double ic)
{
	if (current < ic)
		return wp(current, ic) / 2 / M_PI * exp(-Uheight(current, ic) / kB / T);
	else return 0;
}
//MQT escaping rate
double Gq(double current, double ic)
{
	double q(0);

	q = wp(current, ic) * R * C0;
	if (current < ic)
		return sqrt(120*M_PI)*exp(1.43/q)*sqrt(7.2*Uheight(current,ic)/hbar/wp(current,ic))*wp(current,ic)/2/M_PI*exp(-7.2*(1+0.87/q)*Uheight(current,ic)/hbar/wp(current,ic));
	else return 0;
}
//combine both escaping rate gtype=0 for TA, 1 for MQT, 2 for TA+MQT
double Gtp(double current, double ic, int gtype)
{
	if (gtype == 0) return Gt(current, ic);
	else if (gtype == 1) return Gq(current, ic);
	else if (gtype == 2) return Gt(current, ic) + Gq(current, ic);
	else return 0;
}

//see if a event happen or not according to the probability to happen
int Parity::random_event(double probability)
{
	double number = rand01(rand_gen);
	if (number < probability)
		return 1;
	else return 0;
}

//return parity value at certain time, the time has to start 0 and increase gradually
Parity::Parity(unsigned seed)
	:rand_gen(seed),rand01(0.0,1.0), erand1(F_parity / Ic_md_ratio), erand2(F_parity / (1.0 - Ic_md_ratio))
{
	int tmp(0);
	start = end = Ic * (1 - Ic_d / 2) * Lcut / Istep * Tstep * 0.99;
	tmp=random_event(Ic_md_ratio);
	if (tmp == 1) p = -1;
	else p = 1;
	length = 0;
	phase = rand01(rand_gen);
}

//parity switch with exponential lifetime
int Parity::parity_exp(double time)
{
	while (!(time >= start && time < end)) {
		if (p == -1)
			length = erand2(rand_gen);
		else length = erand1(rand_gen);
		start = end;
		end = start + length;
		p = -1 * p;
	}
	return (int)p;
}
//parity assume constant time lentgh of two states.
int Parity::parity_flat(double time)
{
	double i(0),f(0);

	f=modf(time / 2.0 * F_parity+phase,&i);
	if (f > Ic_md_ratio) return 1;
	else return -1;
}

int Parity::current_parity(int mode, double time)
{
	if (mode == 1)
		return parity_exp(time);
	else if (mode == 4) return parity_flat(time);
	else return 0;
}


//simulate one current ramp and get one switch current
//type: 0 thermal single escape rate 1 thermal double escape rate etc. see head file.
//ptype is the 
double oneswitch(int ptype,int gtype)
{
	double current(0), Ict(0),t(0),p(0);

	unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
	Parity pt(seed1);
	current = Ic*(1-Ic_d/2) * Lcut;
	while (current <= Imax) {
		t = current / Istep*Tstep;
		if (ptype == 0) Ict = Ic;
		if (ptype == 2) Ict = Ic * (1 - Ic_d / 2);
		if (ptype == 3) Ict = Ic * (1 + Ic_d / 2);
		if (ptype == 1 || ptype==4) {
			p = pt.current_parity(ptype,t);
			Ict = Ic *(1+ Ic_d / 2.0 *p);
		}
		if (pt.random_event(Gtp(current, Ict,gtype) * Tstep) == 1 ||current>=Ict)
			break;
		else
			current += Istep;
	}

	return current;
}
