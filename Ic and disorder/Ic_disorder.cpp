#include<random>
#include<chrono>
#include<sstream>
#include<ostream>
#include<iostream>
#include<fstream>
#include<iomanip>
#include"ygdll.hpp"

using namespace std;

string gettime()
{
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    ostringstream r;
    r << (now->tm_year + 1900)
        << setw(2) << setfill('0') << (now->tm_mon + 1)
        << setw(2) << setfill('0') << now->tm_mday << '-'
        << setw(2) << setfill('0') << now->tm_hour
        << setw(2) << setfill('0') << now->tm_min
        << setw(2) << setfill('0') << now->tm_sec;

    return r.str();
}

//generate disorder array, vpp is the peak to peak of the disorder which is the width of the normal distribution
//for the length of each piece of disorder, we have normal distribution with certain average and width.
void disorder_gen(double App, double La, double Lw, int points, mt19937& gen, double *disorder)
{
    double* l_array(new double[points + 1]);
    double t(0), r(1), s(0),lsum(0);
    int l_end(0),n(0);
    normal_distribution<double> r_length(La, Lw);
    normal_distribution<double> r_a(1, App);

    while (lsum <= 1.0) {
        l_array[l_end] = abs(r_length(gen));
        lsum += l_array[l_end];
        l_end++;
        //cout << l_array[l_end - 1] <<',' << lsum <<','<<l_end << '\n';
    }
    
    r = r_a(gen);
    for (int i = 0; i < points; i++) {
        t = 1.0 / (points - 1.0) *i;
        //cout <<"t=" << t << endl;
        while (!(t>=s && t<=s+l_array[n])) {
            //cout << n<<' '<< s << ',' << s+l_array[n] << endl;
            s += l_array[n];
            n++;
            r = r_a(gen);
        }
        disorder[i] = r;
        //cout << disorder[i]<<"r value\n";
    }
    delete[] l_array;
}

int main()
{
    int nw(1001), NIc(1000),Nphase(1001),PhaseRange(4);
    int r_seed(0),cprt(2);
    double* disorder(new double[nw]);
    double a0(0.4), gw0(0.2);
    double flux(2.0), start(0.02), step(0.02), nsteps(25);
    double l_avg(0.05), l_std(0.02);

    string t_start = gettime();
    ofstream pfile((t_start + "_parameters.dat").c_str());
    if (not pfile) perror("pfile error\n");
    ofstream dfile((t_start + "_disorder.dat").c_str());
    if (not dfile) perror("dfile error\n");
    ofstream ifile((t_start + "_Ics.dat").c_str());
    if (not ifile) perror("ifile error\n");
    pfile << "Simulate Ic vs different disorder profile\n";
    pfile << "CPR type: " << cprt << " a0: " << a0 << " gw0: "<< gw0 <<endl;
    pfile << "rand seed: " << r_seed << endl;
    pfile << "y points: " << nw << endl;
    pfile << "flux interested: " << flux << endl;
    pfile << "Number Ic calculation: " << NIc << endl;
    pfile << "Vary the App start, step, # of steps: " << start << ' ' << step << ' ' << nsteps << endl;

    setparameters(1, nw, PhaseRange, Nphase, cprt, a0, gw0, NULL, 0);
    double icp(0), icn(0), pp0(0), pn0(0), p(0);
    mt19937 generator(r_seed);
    auto t_begin = chrono::high_resolution_clock::now();
    for (int i = 0; i < nsteps; i++) {
        p = start + step * i;
        //cout << p << endl;
        for (int j = 0; j < NIc; j++) {
            disorder_gen(p, l_avg, l_std, nw, generator, disorder);
            if (j == 0) {
                for (int k = 0; k < nw; k++) {
                    dfile << disorder[k] << '\t';
                }
                dfile << '\n';
            }
            setJnoise(disorder);
            findIc(flux, &icp, &icn, &pp0, &pn0);
            ifile << icp << '\t';
            cout << '\r' << setw(7)<<(double)(i * NIc + j+1) / nsteps / NIc*100 << '%' << flush;
        }
        ifile << '\n';
    }
    auto t_end= chrono::high_resolution_clock::now();
    chrono::duration<double> duration = t_end - t_begin;
    cout << "\n" << "Total time: "<< duration.count()<<"s"<< endl;
    delete[] disorder;
    pfile.close();
    dfile.close();
    ifile.close();
    return 0;
}