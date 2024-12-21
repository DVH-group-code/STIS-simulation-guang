//This project calculate washboard potential, CPR etc.
#define _USE_MATH_DEFINES
#include<iostream>
#include<ostream>
#include<fstream>
#include<cmath>
#include"ygdll.hpp"

using namespace std;

int main()
{
	ofstream CPR_out("cpr.dat"), Wash_output("wash.dat");
	int i(0);
	double p(0), f(0), icp(0), icn(0), pp0(0), pn0(0);

	//see ygdll for parameter define
	setparameters(0, 1001, /*JJ width steps*/
		4.0 * M_PI,
		1001, /*phase steps*/
		0, /*CPR type: 0, regular; 1, sin(phi)+sin(phi/2); 2, sin(phi/2) with gaussian localization; 3, MBS localized with parity pattern, CPR has to have peroid of PhaseRange*/
		0.5, 0.2, /*amp of MBS, width of gaussian*/
		NULL, 0 /*define parity*/
	);
	CPR_out << "Phase" << '\t' << "CPR" << endl;
	for (i=0; i < 1001; i++) {
		p = -2*M_PI + 4*M_PI / (1001 - 1)*i;
		CPR_out << p << '\t' << cpr_multi(p) << endl;
		if(i%100==0) cout << '<';
	}

	Wash_output << "Phase" << '\t' << "potential" << endl;
	for (i = 0; i < 1001; i++) {
		p = -2 * M_PI + 10 * M_PI / (1001 - 1)*i;
		Wash_output << p << '\t' << washboard_extend(0.5, 0, p,0) << endl;
		if (i % 100 == 0) cout << '>';
	}

	CPR_out.close();
	Wash_output.close();
	cout << "\nDone\n";
	cin.get();
	return 0;
}