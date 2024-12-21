// Ic distribution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES
#include<chrono>
#include<cmath>
#include<iostream>
#include<ostream>
#include<fstream>
#include<omp.h>
#include"ygdll.hpp"

using namespace std;

#define FluxRange 5.0 //field range in terms of Flux_0, -FluxRange~+FluxRange
#define Nflux 1001 //total steps of flux

int main()
{
	ofstream Dist_out("Ic.dat"), Info_out("info.dat");
	double p(0), t(0),current(0),progress(0),ic(0);
	double flux(0), icp(0),icn(0),pp0(0),pn0(0);
	double *ic_data;
	char *p_data;
	int pmode(1), nsweeps(100000),nthread(0);

	auto t_begin = chrono::high_resolution_clock::now();

	//see ygdll and escape_rate.cpp for parameter define
	//setup JJ diffraction simulation parameter
	setparameters(0, 1001, /*JJ width steps*/
		4.0 * M_PI,
		1001, /*phase steps*/
		0, /*CPR type: 0, regular; 1, sin(phi)+sin(phi/2); 2, sin(phi/2) with gaussian localization; 3, MBS localized with parity pattern, CPR has to have peroid of PhaseRange*/
		0.5, 0.2, /*amp of MBS, width of gaussian*/
		NULL, 0 /*define parity*/
	);
	setup_dist_para(
		0.1, /*temperature K*/
		0.5e-12, /*capacitance*/
		4.0e-6, /*Ic0*/
		18, /*R of JJ*/
		5e-6, /*Ic max*/
		10.0e-3, /*time of current ramp*/
		10000, /*Nstep*/
		0.9, /*cut off bias current percentage*/
		0.02, /*Ic_d*/
		10000, /*parity frequency*/
		0.5, /*Ic_md_ratio*/
		nsweeps, /*Nsweep*/
		pmode /*parity state change mode:0 for no parity, 1 for simple parity change, 2 for Ic-Ic_d/2, 3 for Ic+Ic_d/2, 4 for constant parity state lifetime. */
	);
	
	cout << "calculate supply info.dat which contains time dependent data of parity, excape rate1,2 for one sweep.\n";
	p_data = new char[p_data_len() + 1];
	get_parity_data(p_data, p_data_len() + 1);
	Info_out << p_data;
	cout << "done";
	cout << "\ncalculate Ic distribution with parity type:"<<pmode<<endl;
	
	ic_data = new double[nsweeps];
	nthread = omp_get_max_threads();
#pragma omp parallel for
	for (int i=0; i < nsweeps; i++) {
		ic = Get_Ic(0); // escaping rate gtype=0 for TA, 1 for MQT, 2 for TA+MQT
		ic_data[i] = ic * 1e6;
		if (omp_get_thread_num() == 0) {
			progress += 1.0 / nsweeps*nthread;
			cout <<'\r' << progress * 100 << "\t%";
		}
	}
	
	for (int i = 0; i < nsweeps; i++)
		Dist_out << ic_data[i]<<endl;
	
	auto t_end = chrono::high_resolution_clock::now();
	Dist_out.close();
	Info_out.close();
	chrono::duration<double> duration = t_end - t_begin;
	cout << "\n" << "Total time: " << duration.count() << "\nDone!"<< endl;
	cin.get();
	return 0;
}
