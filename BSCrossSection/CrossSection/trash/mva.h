#include "parameters.h"

const int nMVA = 10;
TString mvatypes[nMVA] = {"CutsSA","CutsGA","MLP","MLPBFGS","MLPBNN","BDT","BDTB","BDTD","BDTG","BDTMitFisher"};
//TString mvatypes[nMVA] = {"MLP","MLPBFGS","MLPBNN","BDT","BDTB","BDTD","BDTG","BDTMitFisher"};

float cutsSA[nBins][4];
float cutsGA[nBins][4];
float cutsBDT[nBins];
float cutsBDTB[nBins];
float cutsBDTD[nBins];
float cutsBDTG[nBins];
float cutsBDTMitFisher[nBins];
float cutsMLP[nBins];
float cutsMLPBNN[nBins];
float cutsMLPBFGS[nBins];

float cutsSA_PbPb[nBins][4] = { 
			    {1.05,0.0561,0.999,12.8},
			    {1.44,0.171,-0.127,7.7},
			    {2.11,0.0137,0.74,4.84},
			    {0,0,0,0},
			    {0,0,0,0} 
			 };

float cutsGA_PbPb[nBins][4] = { 
			    {1.26,0.98,-0.0571,22.7},
			    {2.02,0.996,0.953,8.93},
			    {2.1,0.991,0.827,4.7},
			    {2.17,1,-0.666,3.85},
			    {0,0,0,0} 
			 };

//float cutsSA_PbPb[nBins] = {0.89,0.77,0.85,0.94,0.95};
//float cutsGA_PbPb[nBins] = {0.86,0.80,0.83,0.94,0.84};
float cutsMLP_PbPb[nBins] = {0.14,0.09,0.21,0.34,0};
float cutsMLPBNN_PbPb[nBins] = {0.12,0.09,0.18,0.25,0};
float cutsMLPBFGS_PbPb[nBins] = {0.11,0.09,0.18,0.19,0};
float cutsBDT_PbPb[nBins] = {-0.21,-0.13,-0.25,0.18,0};
float cutsBDTB_PbPb[nBins] = {-0.32,0.40,0.76,-0.41,0};
float cutsBDTD_PbPb[nBins] = {-0.08,-0.04,-0.07,-0.09,0};
float cutsBDTG_PbPb[nBins] = {-0.39,0.33,-0.20,-0.83,0};
float cutsBDTMitFisher_PbPb[nBins] = {0.01,-0.06,-0.07,-0.11,0};


float cutsSA_pp[nBins][4] = { 
			    {0.919,0.121,0.997,6.78},
			    {1.55,0.0703,0.984,5.55},
			    {1.26,0.000982,0.996,-4.78},
			    {1.07,0.0264,-0.486,-8.6},
			    {0,0,0,0} 
			 };

float cutsGA_pp[nBins][4] = { 
			    {0.939,1,0.994,-24.3},
			    {1.77,1.01,0.968,4.88},
			    {1.53,0.986,0.82,3.56},
			    {1.61,1,0.767,-20.8},
			    {0,0,0,0} 
			 };

//float cutsSA_pp[nBins] = {0.90,0.86,0.91,0.83,0.99};
//float cutsGA_pp[nBins] = {0.88,0.87,0.92,0.94,0.97};
float cutsMLP_pp[nBins] = {0.23,0.16,0.43,0.49,0};
float cutsMLPBNN_pp[nBins] = {0.12,0.21,0.43,0.48,0};
float cutsMLPBFGS_pp[nBins] = {0.92,0.22,0.45,0.37,0};
float cutsBDT_pp[nBins] = {-0.15,-0.07,0.06,-0.08,0};
float cutsBDTB_pp[nBins] = {0.41,-0.26,-0.62,-0.29,0};
float cutsBDTD_pp[nBins] = {-0.05,-0.04,-0.07,-0.08,0};
float cutsBDTG_pp[nBins] = {-0.49,-0.35,-0.28,-0.93,0};
float cutsBDTMitFisher_pp[nBins] = {-0.04,-0.23,-0.04,-0.18,0};
