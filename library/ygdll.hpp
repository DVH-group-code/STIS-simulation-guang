#pragma once
#include<sstream>
#ifdef ygDLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
extern  DLL_API void findIc(double flux, double* icp, double* icn, double *pp0,double *pn0);
extern  DLL_API double cpr_multi(double phase);
extern  DLL_API double i_y_F(double y, double p0, double flux);
extern  DLL_API void setJnoise(double* noise);
extern  DLL_API void setparameters(int Jnt0, int nw, int phaserange0, int nphase, int cpr0, double a0, double gw0, int* parity0, int parity_l0);
extern DLL_API double Gt_dll(double current);
extern DLL_API double Gq_dll(double current);
extern DLL_API void setup_dist_para(double temp, double c, double ic, double r, double im, double tsw, int nstep, double lcut, double ic_d, double fparity, double icr, int sweeps, int pmode);
extern DLL_API double Get_Ic(int gtype);
extern DLL_API double washboard_extend(double i, double flux, double p0, double c0);
extern DLL_API void get_parity_data(char *data, int size);
extern DLL_API int p_data_len();