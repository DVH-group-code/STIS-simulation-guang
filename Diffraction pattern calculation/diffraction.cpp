//this program demo the usage of the code to generate diffraction pattern
#define _USE_MATH_DEFINES
#include<chrono>
#include<cmath>
#include<iostream>
#include<ostream>
#include<fstream>
#include"ygdll.hpp"

using namespace std;
#define FluxRange 5.0 //field range in terms of Flux_0, -FluxRange~+FluxRange
#define Nflux 10001 //total steps of flux

int main()
{
	double flux(0), icp(0), icn(0), pp0(0), pn0(0);
	ofstream Dist_out("diffraction.dat");
		
	Dist_out << "Flux\tIc\n";
	//see ygdll for parameter define
	setparameters(0, /*disorder type, 0 means uniform*/
		1001, /*JJ width steps*/
		4.0, /*phase_range in unit of Pi*/
		1001, /*phase steps*/
		0, /*CPR type: 0, regular; 1, sin(phi)+sin(phi/2); 2, sin(phi/2) with gaussian localization; 3, MBS localized with parity pattern, CPR has to have peroid of PhaseRange*/
		0.5,0.2, /*amp of MBS, width of gaussian*/
		NULL,0 /*define parity*/
	);
	auto t_begin = chrono::high_resolution_clock::now();
	for (int i = 0; i < Nflux; i++) {
		flux = -1.0*FluxRange + i * FluxRange * 2.0 / Nflux;
		findIc(flux, &icp, &icn,&pp0,&pn0);
		Dist_out << flux << '\t' << icp << '\n';
		cout << '\r' << (float)(i+1) / Nflux * 100 << "%       ";
	}
	auto t_end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = t_end - t_begin;
	cout << "\n" << "Time on main calculation: " << duration.count() << "\nDone!" << endl;
	Dist_out.close();
	cin.get();
	
	return 0;
}