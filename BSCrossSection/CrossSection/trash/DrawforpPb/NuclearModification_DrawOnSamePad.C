#include <math.h>
#include <iostream>
#include "TROOT.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TString.h"
#include "TFile.h"
#include "TGraphAsymmErrors.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TLine.h"
#include "TLegendEntry.h"
#include "TPad.h"
#include "TBox.h"
using namespace std;

  TString   Bs_particle="Bs";
  const int Bs_nbins=1;
  Double_t  Bs_xbins[Bs_nbins]={35};
  Double_t  Bs_xhbins[Bs_nbins+1]={10,60};
  Double_t  Bs_exl[Bs_nbins]={25};
  Double_t  Bs_exl2[Bs_nbins]={24.0};
 Double_t  Bs_exl0[Bs_nbins]={0.};
  Double_t  Bs_yPercSigmapPbSystTotHigh[Bs_nbins]={0.218};
  Double_t  Bs_yPercSigmapPbSystTotLow[Bs_nbins]={0.218};
  //Double_t  Bs_commonErrorP = TMath::Sqrt(0.22*0.22+0.035*0.035);//old BR
  //Double_t  Bs_commonErrorN = TMath::Sqrt(0.24*0.24+0.035*0.035);//old BR
  Double_t  Bs_commonErrorP = TMath::Sqrt(0.085*0.085+0.035*0.035);//new BR
  Double_t  Bs_commonErrorN = TMath::Sqrt(0.085*0.085+0.035*0.035);//new BR
  //Double_t  Bs_FFsysterror=0.6/10.4;//old BR
  Double_t  Bs_FFsysterror=0.6/10.5;//new BR
//  Double_t  Bs_tagandprobcorrection[Bs_nbins]={1.041};
//  Double_t  Bs_tagandprobcorrection[Bs_nbins]={1.069};//new correction
  Double_t  Bs_tagandprobcorrection[Bs_nbins]={1.065};//new correction, abs eta binning

  TString   B0_particle="Bzero";
  const int B0_nbins=3;
  Double_t  B0_xbins[B0_nbins]={12.5,17.5,40};
  Double_t  B0_xhbins[B0_nbins+1]={10,15,20,60};
  Double_t  B0_exl[B0_nbins]={2.5,2.5,20};
  Double_t  B0_exl2[B0_nbins]={1.5,1.5,19.0};
  Double_t  B0_exl0[B0_nbins]={0.,0.,0.};
  Double_t  B0_yPercSigmapPbSystTotHigh[B0_nbins]={0.186,0.181,0.180};
  Double_t  B0_yPercSigmapPbSystTotLow[B0_nbins]={0.186,0.181,0.180};
  Double_t  B0_commonErrorP = TMath::Sqrt(0.035*0.035+0.046*0.046);
  Double_t  B0_commonErrorN = TMath::Sqrt(0.035*0.035+0.046*0.046);
  Double_t  B0_FFsysterror=0.7/40.2;
//  Double_t  B0_tagandprobcorrection[B0_nbins]={1.052,1.032,1.016};
//  Double_t  B0_tagandprobcorrection[B0_nbins]={1.078,1.061,1.058};//new correction
  Double_t  B0_tagandprobcorrection[B0_nbins]={1.073,1.060,1.054};//new correction, abs eta binning

  TString   Bp_particle="Bplus";
  const int Bp_nbins=5;
  Double_t  Bp_xbins[Bp_nbins]={12.5,17.5,22.5,27.5,45.};
  Double_t  Bp_xhbins[Bp_nbins+1]={10,15,20,25,30,60};
  Double_t  Bp_exl[Bp_nbins]={2.5,2.5,2.5,2.5,15.};
  Double_t  Bp_exl2[Bp_nbins]={1.5,1.5,1.5,1.5,14.0};
  Double_t  Bp_exl0[Bp_nbins]={0.,0.,0.,0.,0.};
  Double_t  Bp_yPercSigmapPbSystTotHigh[Bp_nbins]={0.150,0.143,0.143,0.141,0.149};
  Double_t  Bp_yPercSigmapPbSystTotLow[Bp_nbins]={0.150,0.143,0.143,0.141,0.149};
  Double_t  Bp_commonErrorP = TMath::Sqrt(0.035*0.035+0.031*0.031);
  Double_t  Bp_commonErrorN = TMath::Sqrt(0.035*0.035+0.031*0.031);
  //Double_t  Bp_FFsysterror=0.7/40.1;//old BR
  Double_t  Bp_FFsysterror=0.7/40.2;//new BR
//  Double_t  Bp_tagandprobcorrection[Bp_nbins]={1.049,1.030,1.019,1.012,1.006};
//  Double_t  Bp_tagandprobcorrection[Bp_nbins]={1.071,1.057,1.058,1.045,1.061};//new correciton
  Double_t  Bp_tagandprobcorrection[Bp_nbins]={1.069,1.050,1.050,1.045,1.065};//new correciton, abs eta binning
/*
  Double_t Bs_padratio=0.326899;
  Double_t B0_padratio=0.307285;
  Double_t Bp_padratio=0.365816;
*/
  Double_t Bs_padratio=1.0;
  Double_t B0_padratio=1.0;
  Double_t Bp_padratio=1.0;

void makeMultiPanelCanvas(TCanvas*& canv, 
const Int_t columns,
const Int_t rows,
bool  setlogy,
const Float_t leftOffset= 0.,
const Float_t bottomOffset= 0.,
const Float_t leftMargin= 0.16,
const Float_t bottomMargin= 0.16,
//###const Float_t edge=0.05
const Float_t edge=0.06
);

void makeIndepPadCanvas(TCanvas*& canv, 
bool  setlogy
);

void NuclearModification(
  TString  particle,
  const int      nbins,
  Double_t xbins[],
  Double_t xhbins[],
  Double_t exl[],
  Double_t exl2[],
  Double_t exl0[],
  Double_t yPercSigmapPbSystTotHigh[],
  Double_t yPercSigmapPbSystTotLow[],
  Double_t commonErrorP,
  Double_t commonErrorN,
  Double_t FFsysterror,
  Double_t tagandprobcorrection[],
  TCanvas *canvasSigma,
  TCanvas *canvasRpA,
  int PadNum
){
  TBox *gRpAsystFONLL_box;

  gROOT->SetStyle("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  
  TFile*filePPReference=new TFile(Form("../../../fonll/output%s.root",particle.Data()));  
  //###TFile*filePPReference=new TFile(Form("../../fonll/output%s.root",particle.Data()));  
  TGraphAsymmErrors*gaeBplusReference=(TGraphAsymmErrors*)filePPReference->Get(Form("gaeSigmaDecay%s",particle.Data()));
  gaeBplusReference->SetName(Form("gae%sReference",particle.Data()));
  
  TFile*filepPb=new TFile(Form("../Results%s/Sigma%s.root",particle.Data(),particle.Data()));
  TH1F*hSigmapPbStat=(TH1F*)filepPb->Get("hPtSigma");  
  TH1F*hPt=(TH1F*)filepPb->Get("hPt");
  TH1F*hEff=(TH1F*)filepPb->Get("hEff");
  
  double scalingfactor=1e-6;
  double yvalue,xvalue,yerrorhigh,yerrorlow;
  
  for (int i=0;i<nbins;i++){
    hSigmapPbStat->SetBinContent(i+1,scalingfactor*hSigmapPbStat->GetBinContent(i+1));
    hSigmapPbStat->SetBinError(i+1,scalingfactor*hSigmapPbStat->GetBinError(i+1));
    
    yvalue=-1.;
    xvalue=-1.;
    yerrorhigh=-1.;
    yerrorlow=-1.;
    
    gaeBplusReference->GetPoint(i,xvalue,yvalue);
    yerrorhigh=gaeBplusReference->GetEYhigh()[i];
    yerrorlow=gaeBplusReference->GetEYlow()[i];
  
    gaeBplusReference->SetPoint(i,xvalue,yvalue*scalingfactor);
    gaeBplusReference->SetPointEYhigh(i,yerrorhigh*scalingfactor);
    gaeBplusReference->SetPointEYlow(i,yerrorlow*scalingfactor);

  } 
  
  
  for (int i=0;i<nbins;i++){
    hSigmapPbStat->SetBinContent(i+1,(1./tagandprobcorrection[i])*hSigmapPbStat->GetBinContent(i+1));
    hSigmapPbStat->SetBinError(i+1,(1./tagandprobcorrection[i])*hSigmapPbStat->GetBinError(i+1));
  
  } 
  Double_t yRefPP[nbins];                        //value y reference
  Double_t xRefPP[nbins];                        //value x reference
  Double_t yPPsystFONLLhigh[nbins];              //y err syst FONLL high
  Double_t yPPsystFONLLlow[nbins];               //y err syst FONLL low
  Double_t yPercPPsystFONLLhigh[nbins];          //y percentuale err syst FONLL high
  Double_t yPercPPsystFONLLlow[nbins];           //y percentuale err syst FONLL low
    
  Double_t ySigmapPb[nbins];                     //value y pPb 
  Double_t xSigmapPb[nbins];                     //value x pPb
  Double_t ySigmapPbStat[nbins];                 //y err stat pPb
  Double_t yPercSigmapPbStat[nbins];             //y err stat pPb
  
  Double_t yFONLL[nbins];                        //1
  Double_t yRpA[nbins];                          //value y RpA 
  Double_t yRpAStat[nbins];                      //y err stat RpA 
  Double_t yRpAsystFONLLhigh[nbins];             //y err syst FONLL RpA high
  Double_t yRpAsystFONLLlow[nbins];              //y err syst FONLL RpA lzow
  Double_t yPercRpAsystFONLLhigh[nbins];         //y percentuale err syst FONLL RpA high
  Double_t yPercRpAsystFONLLlow[nbins];          //y percentuale err syst FONLL RpA low
    
  Double_t ySigmapPbSystTotHigh[nbins];              //y percentuale err syst pPb TOT
  Double_t ySigmapPbSystTotLow[nbins];              //y percentuale err syst pPb TOT

  Double_t yPercRpPbSystTotHigh[nbins];          //y percentuale err syst RpPb TOT
  Double_t yPercRpPbSystTotLow[nbins];          //y percentuale err syst RpPb TOT
  
  Double_t yRpPbSystTotHigh[nbins];              //y percentuale err syst RpPb TOT
  Double_t yRpPbSystTotLow[nbins];              //y percentuale err syst RpPb TOT

  
  double x,y;
  for (Int_t i=0;i<nbins;i++) {
    gaeBplusReference->GetPoint(i,xRefPP[i],yRefPP[i]);
    yPPsystFONLLhigh[i]=gaeBplusReference->GetEYhigh()[i];
    yPPsystFONLLlow[i]=gaeBplusReference->GetEYlow()[i];
    yPercPPsystFONLLhigh[i]=yPPsystFONLLhigh[i]/yRefPP[i];
    yPercPPsystFONLLlow[i]=yPPsystFONLLlow[i]/yRefPP[i];
    yPercPPsystFONLLhigh[i]=TMath::Sqrt(yPercPPsystFONLLhigh[i]*yPercPPsystFONLLhigh[i]+FFsysterror*FFsysterror);
    yPercPPsystFONLLlow[i]=TMath::Sqrt(yPercPPsystFONLLlow[i]*yPercPPsystFONLLlow[i]+FFsysterror*FFsysterror);
    
  }
  
  for(Int_t i=0;i<nbins;i++) {
    ySigmapPb[i]=hSigmapPbStat->GetBinContent(i+1);
    ySigmapPbStat[i]=hSigmapPbStat->GetBinError(i+1);
    yPercSigmapPbStat[i]=ySigmapPbStat[i]/ySigmapPb[i];
    ySigmapPbSystTotHigh[i]=yPercSigmapPbSystTotHigh[i]*ySigmapPb[i];
    ySigmapPbSystTotLow[i]=yPercSigmapPbSystTotLow[i]*ySigmapPb[i];
  }
  
  for(Int_t i=0;i<nbins;i++) {
    yRpA[i]=ySigmapPb[i]/yRefPP[i];
    yRpAStat[i]=ySigmapPbStat[i]/yRefPP[i];
    yFONLL[i]=yRpA[i];
    yPercRpAsystFONLLhigh[i]=(yPercPPsystFONLLlow[i]/(1-yPercPPsystFONLLlow[i]));
    yPercRpAsystFONLLlow[i]=(yPercPPsystFONLLhigh[i]/(1+yPercPPsystFONLLhigh[i]));
    yRpAsystFONLLhigh[i]=yPercRpAsystFONLLhigh[i]*yRpA[i];
    yRpAsystFONLLlow[i]=yPercRpAsystFONLLlow[i]*yRpA[i];

    yRpPbSystTotHigh[i]=yPercSigmapPbSystTotHigh[i]*yRpA[i];
    yRpPbSystTotLow[i]=yPercSigmapPbSystTotLow[i]*yRpA[i];   

	std::cout << i << " , " << xbins[i] << " , " << ySigmapPb[i] << " , sta: " << ySigmapPbStat[i] << " , syslow: " << ySigmapPbSystTotLow[i] << " ,syshigh: " << ySigmapPbSystTotHigh[i] << std::endl;
	std::cout << "FONLL: " << yRefPP[i] << " - " << yPPsystFONLLlow[i] << " + " << yPPsystFONLLhigh[i] << std::endl;
	std::cout << i << " ####### " << xbins[i] << " , " << yRpA[i] << " , sta: " << yRpAStat[i] << " , syslow: " << yRpPbSystTotLow[i] << " ,syshigh: " << yRpPbSystTotHigh[i] << " ,FONLLlow: " << yRpAsystFONLLlow[i] << " , FONLLhigh: " << yRpAsystFONLLhigh[i] << std::endl;

  TGraphAsymmErrors *gRpAstat = new TGraphAsymmErrors(nbins,xbins,yRpA,exl0,exl0,yRpAStat,yRpAStat);
  TGraphAsymmErrors *gRpAsyst = new TGraphAsymmErrors(nbins,xbins,yRpA,exl,exl,yRpPbSystTotLow,yRpPbSystTotHigh);
  TGraphAsymmErrors *gRpAsystFONLL = new TGraphAsymmErrors(nbins,xbins,yFONLL,exl,exl,yRpAsystFONLLlow,yRpAsystFONLLhigh);
 

  }
  
  TGraphAsymmErrors *gSigmasyst = new TGraphAsymmErrors(nbins,xbins,ySigmapPb,exl2,exl2,ySigmapPbSystTotLow,ySigmapPbSystTotHigh);
  //###TGraphAsymmErrors *gSigmasyst = new TGraphAsymmErrors(nbins,xbins,ySigmapPb,exl,exl,ySigmapPbSystTotLow,ySigmapPbSystTotHigh);


  gSigmasyst->SetTitle("Sigma syst uncertainty from pPb");
  gSigmasyst->SetName("gSigmasyst");
  gSigmasyst->SetLineColor(1);
  gSigmasyst->SetLineWidth(1);   
  gSigmasyst->SetMarkerStyle(21);
  gSigmasyst->SetMarkerColor(1);
  gSigmasyst->SetFillColor(kYellow-7);//5
  gSigmasyst->SetFillStyle(1001);
  TGraphAsymmErrors*gSigmasyst2=(TGraphAsymmErrors*)gSigmasyst->Clone();
  gSigmasyst2->SetMarkerColor(1);
  gSigmasyst2->SetMarkerStyle(25);
  gSigmasyst2->SetFillColor(0);
  gSigmasyst2->SetFillStyle(0);
  gSigmasyst2->SetLineColor(1);//5
  gSigmasyst2->SetLineStyle(1);
  gSigmasyst2->SetLineWidth(1);
 

  //###TGraphAsymmErrors *gSigmastat = new TGraphAsymmErrors(nbins,xbins,ySigmapPb,exl,exl,ySigmapPbStat,ySigmapPbStat);
  TGraphAsymmErrors *gSigmastat = new TGraphAsymmErrors(nbins,xbins,ySigmapPb,exl0,exl0,ySigmapPbStat,ySigmapPbStat);


  gSigmastat->SetTitle("Sigma stat uncertainty from pPb");
  gSigmastat->SetMarkerColor(1);
  gSigmastat->SetLineColor(1);
  gSigmastat->SetLineWidth(2);//###   
  gSigmastat->SetMarkerStyle(21);
  gSigmastat->SetMarkerColor(1);
  
  gSigmastat->SetFillColor(0);
  gSigmastat->SetFillStyle(0);
  gSigmastat->SetFillStyle(0);

  Double_t padcorrection;
  if (particle=="Bplus") padcorrection=Bp_padratio/Bp_padratio;
  else if (particle=="Bzero") padcorrection=Bp_padratio/B0_padratio;
  else if (particle=="Bs") padcorrection=Bp_padratio/Bs_padratio;
  std::cout << "padcorrection: " << padcorrection << std::endl;
  canvasSigma->cd(PadNum);
  //canvasSigma->Range(-1.989924,-0.2917772,25.49622,2.212202);
  canvasSigma->SetFillColor(0);
  canvasSigma->SetBorderMode(0);
  canvasSigma->SetBorderSize(2);
  //canvasSigma->SetLeftMargin(0.1451613);
  //canvasSigma->SetRightMargin(0.05443548);
  //canvasSigma->SetTopMargin(0.005);//0.08474576
  //canvasSigma->SetBottomMargin(0.1165254);
  canvasSigma->SetFrameBorderMode(0);
  canvasSigma->SetFrameBorderMode(0);
  canvasSigma->SetLogy();
  
  //###TH2F* hempty=new TH2F("hempty","", 10, 0.1, 65., 10., 0.1, 1e3);    
  TH2F* hempty=new TH2F("hempty","", 10, 0.1, 65., 10., 0.3, 1e3);    
  hempty->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  //if(particle=="Bplus") hempty->GetYaxis()->SetTitle("d#sigma / dp_{T} (B^{+}) (pb GeV^{-1}c)");
  //if(particle=="Bzero") hempty->GetYaxis()->SetTitle("d#sigma / dp_{T} (B^{0}) (pb GeV^{-1}c)");
  //if(particle=="Bs") hempty->GetYaxis()->SetTitle("d#sigma / dp_{T} (B_{s}) (pb GeV^{-1}c)");
  hempty->GetXaxis()->CenterTitle();
  hempty->GetYaxis()->CenterTitle();
  //###hempty->GetYaxis()->SetTitle("d#sigma / dp_{T}( #mub GeV^{-1}c)");
  hempty->GetYaxis()->SetTitle("d#sigma / dp_{T}(#mub/(GeV/c))");
  //###hempty->GetXaxis()->SetTitleOffset(1.0);//###1.0
  if (particle=="Bplus") hempty->GetXaxis()->SetTitleOffset(0.90);//###1.0
  else if (particle=="Bzero") hempty->GetXaxis()->SetTitleOffset(0.90);//###0.80
  else if (particle=="Bs") hempty->GetXaxis()->SetTitleOffset(0.90);//###0.85

  hempty->GetYaxis()->SetTitleOffset(1.0);//###1.3
  hempty->GetXaxis()->SetTitleSize(0.070*padcorrection);//###0.055
  hempty->GetYaxis()->SetTitleSize(0.070*padcorrection);//###0.055
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.060*padcorrection);//###0.055
  hempty->GetYaxis()->SetLabelSize(0.060*padcorrection);//###0.055
  if (particle=="Bplus") hempty->GetXaxis()->SetLabelOffset(0.005);//###0.005
  else if (particle=="Bzero") hempty->GetXaxis()->SetLabelOffset(0.005);//###0.0001
  else if (particle=="Bs") hempty->GetXaxis()->SetLabelOffset(0.005);//###0.0005
  //###hempty->GetXaxis()->SetLabelOffset(0.005);//###0.005
  hempty->SetMaximum(2);
  hempty->SetMinimum(0.);
  hempty->Draw();
  
  gaeBplusReference->SetMarkerColor(1);
  gaeBplusReference->SetMarkerStyle(25);  
  gaeBplusReference->SetFillColor(kYellow-7);//5
  gaeBplusReference->SetFillStyle(1001);
  gaeBplusReference->SetLineColor(kAzure-3);
  gaeBplusReference->SetLineWidth(1);
  
  
  gSigmastat->SetMarkerColor(1);
  gSigmastat->SetLineColor(1);
  gSigmastat->SetLineWidth(2);   
  gSigmastat->SetMarkerStyle(21);
  gSigmastat->SetMarkerColor(1);

  // Histogram style
  TH1D* hBplusReference = new TH1D("hBplusReference","",nbins,xhbins);
  TH1D* hBplusReferenceEYhigh = new TH1D("hBplusReferenceEYhigh","",nbins,xhbins);
  TH1D* hBplusReferenceEYlow = new TH1D("hBplusReferenceEYlow","",nbins,xhbins);



  for (int i=0;i<nbins;i++){
	double xgae,ygae;
	gaeBplusReference->GetPoint(i,xgae,ygae);
	hBplusReference->SetBinContent(i+1,ygae);
	hBplusReferenceEYhigh->SetBinContent(i+1,ygae+gaeBplusReference->GetEYhigh()[i]);
	hBplusReferenceEYlow->SetBinContent(i+1,ygae-gaeBplusReference->GetEYlow()[i]);
	std::cout << "### FONLL (" << i << ") : " << ygae << " + " << gaeBplusReference->GetEYhigh()[i] << " - " << gaeBplusReference->GetEYlow()[i] << std::endl;
}

  //hBplusReference->SetMarkerColor(1);
  //hBplusReference->SetMarkerStyle(25);  
  //hBplusReference->SetFillColor(kYellow-7);//5
  //hBplusReference->SetFillStyle(1001);
  hBplusReference->SetLineColor(kAzure-3);
  hBplusReference->SetLineWidth(2);
  hBplusReferenceEYhigh->SetLineColor(kAzure-3);
  hBplusReferenceEYhigh->SetLineWidth(2);
  hBplusReferenceEYhigh->SetLineStyle(2);
  hBplusReferenceEYlow->SetLineColor(kAzure-3);
  hBplusReferenceEYlow->SetLineWidth(2);
  hBplusReferenceEYlow->SetLineStyle(2);


/*
  hBplusReference->Draw("][,same");

  hBplusReferenceEYhigh->Draw("][,same");
  hBplusReferenceEYlow->Draw("][,same");
*/


/*
  gaeBplusReference->Draw("2psame");//2same
  TGraphAsymmErrors*gaeBplusReference2=(TGraphAsymmErrors*)gaeBplusReference->Clone();
  gaeBplusReference2->SetMarkerColor(1);
  gaeBplusReference2->SetMarkerStyle(25);  
  gaeBplusReference2->SetFillColor(0);
  gaeBplusReference2->SetFillStyle(0);
  gaeBplusReference2->SetLineColor(kAzure-3);
  gaeBplusReference2->SetLineWidth(1);
  gaeBplusReference2->Draw("2psame");//2same
*/
 
  //coord.  for legend for sigma in the B+ pannel 
  //###TLegend *legendSigma=new TLegend(0.468298,0.7045614,0.7678185,0.8757895,"");
  //###TLegend *legendSigma=new TLegend(0.55,0.63,0.85,0.80,"");
  TLegend *legendSigma=new TLegend(0.38,0.65,0.68,0.86,"");


  legendSigma->SetBorderSize(0);
  legendSigma->SetLineColor(0);
  legendSigma->SetFillColor(0);
  legendSigma->SetFillStyle(1001);
  legendSigma->SetTextFont(42);
  legendSigma->SetTextSize(0.060);//###0.045
/* 
  TBox *c = new TBox(3,1-commonErrorN,7,1+commonErrorP);
  c->SetLineColor(5);
  c->SetFillColor(5);
  c->Draw();

  TBox *c2 = c->Clone();
  c2->SetLineColor(1);
  c2->SetFillStyle(0);
  c2->Draw();
*/  
  TLegendEntry *ent_SigmapPb=legendSigma->AddEntry(gSigmastat,"pPb data","p");
  //###TLegendEntry *ent_SigmapPb=legendSigma->AddEntry(gSigmasyst,"pPb","pf");
/*
  ent_SigmapPb->SetTextFont(42);
  ent_SigmapPb->SetLineColor(1);
  ent_SigmapPb->SetMarkerColor(1);
  ent_SigmapPb->SetFillColor(0);
  ent_SigmapPb->SetFillStyle(0);
*/
/*
////
  ent_SigmapPb->SetTextFont(42);
  ent_SigmapPb->SetMarkerColor(1);
  ent_SigmapPb->SetMarkerStyle(25);  
  //ent_SigmapPb->SetFillColor(kYellow-7);//5
  //ent_SigmapPb->SetFillStyle(1001);
  ent_SigmapPb->SetLineColor(1);
  ent_SigmapPb->SetLineWidth(0);
  ent_SigmapPb->SetLineStyle(0);
/////
*/ 
//
  ent_SigmapPb->SetTextFont(42);
  ent_SigmapPb->SetMarkerColor(1);
  ent_SigmapPb->SetMarkerStyle(25);
  ent_SigmapPb->SetLineColor(1);
  ent_SigmapPb->SetLineWidth(2);
  ent_SigmapPb->SetLineStyle(0);

  TLegendEntry *ent_SigmapPbsyst=legendSigma->AddEntry(gSigmasyst,"Syst. pPb data","f");
  ent_SigmapPbsyst->SetTextFont(42);
  ent_SigmapPbsyst->SetMarkerColor(1);
  ent_SigmapPbsyst->SetMarkerStyle(25);
  ent_SigmapPbsyst->SetLineColor(1);
  ent_SigmapPbsyst->SetLineWidth(2);
  ent_SigmapPbsyst->SetLineStyle(0);
 
//

/*
  TLegendEntry *ent_Sigmapp=legendSigma->AddEntry(gaeBplusReference,"FONLL pp ref.","pf");
  ent_Sigmapp->SetTextFont(42);
  ent_Sigmapp->SetLineColor(kAzure-3);//5
  ent_Sigmapp->SetLineStyle(1);
  ent_Sigmapp->SetMarkerColor(1);
  ent_Sigmapp->SetMarkerStyle(21);
*/
  TLegendEntry *ent_Sigmapp=legendSigma->AddEntry(hBplusReference,"Scaled FONLL pp ref.","l");
  ent_Sigmapp->SetTextFont(42);
  ent_Sigmapp->SetLineColor(kAzure-3);//5
  ent_Sigmapp->SetLineStyle(1);
  ent_Sigmapp->SetMarkerColor(1);
  ent_Sigmapp->SetMarkerStyle(21);

  TLegendEntry *ent_Sigmapperr=legendSigma->AddEntry(hBplusReferenceEYhigh,"FONLL pp ref. uncert.","l");
  ent_Sigmapperr->SetTextFont(42);
  ent_Sigmapperr->SetLineColor(kAzure-3);//5
  ent_Sigmapperr->SetLineStyle(2);
  ent_Sigmapperr->SetMarkerColor(1);
  ent_Sigmapperr->SetMarkerStyle(21);


  //###gSigmasyst->SetFillColor(0);
  //###gSigmasyst->SetFillStyle(0);

for (int i=0;i<nbins;i++){
        double xgae,ygae;
        gSigmastat->GetPoint(i,xgae,ygae);
        std::cout << "### cross section (" << i << ") : " << ygae << " stat: " << gSigmastat->GetEYhigh()[i] << " syst: " << gSigmasyst->GetEYhigh()[i] << std::endl;
}

  gSigmasyst->Draw("2esame");//###2psame
  gSigmasyst2->Draw("2esame");

  hBplusReference->Draw("][,same");

  hBplusReferenceEYhigh->Draw("][,same");
  hBplusReferenceEYlow->Draw("][,same");

  gSigmastat->SetFillColor(0);
  gSigmastat->Draw("epsame");
/*  
  TBox *d = new TBox(0.1,1-commonErrorN,4,1+commonErrorP);
  d->SetLineColor(1);
  d->SetFillColor(0);
  d->Draw();
*/  
  //if(PadNum==0 || PadNum==1){
  if(PadNum==3 || PadNum==1 || PadNum==2){


    legendSigma->Draw("same");
    
    //TLatex * tlatex1=new TLatex(0.21,0.88801268,"CMS");
    TLatex * tlatex1=new TLatex(0.19,0.86,"CMS");
    tlatex1->SetNDC();
    tlatex1->SetTextColor(1);
    tlatex1->SetTextFont(62);//42
    tlatex1->SetTextSize(0.07);//0.045
    tlatex1->Draw();
/*
    TLatex * tlatex12=new TLatex(0.35,0.86,"Preliminary");
    tlatex12->SetNDC();
    tlatex12->SetTextColor(1);
    tlatex12->SetTextFont(52);//42
    tlatex12->SetTextSize(0.05);//0.045
    tlatex12->Draw();
*/   
    //TLatex * tlatexlumi=new TLatex(0.471371,0.88801268,"L = 34.8 nb^{-1} (pPb 5.02 TeV)");
    //TLatex * tlatexlumi=new TLatex(0.471371,0.88801268,"34.6 nb^{-1} (pPb 5.02 TeV)");
    TLatex * tlatexlumi;
//###TLatex * tlatexlumi=new TLatex(0.390,0.950,"34.6 nb^{-1} (pPb 5.02 TeV)");
   if (PadNum==1) tlatexlumi = new TLatex(0.41,0.94,"34.6 nb^{-1} (pPb 5.02 TeV)");
   else tlatexlumi = new TLatex(0.39,0.94,"34.6 nb^{-1} (pPb 5.02 TeV)");
    tlatexlumi->SetNDC();
    tlatexlumi->SetTextColor(1);
    tlatexlumi->SetTextFont(42);
    tlatexlumi->SetTextSize(0.06);//0.045
    tlatexlumi->Draw();
  }

   //if(PadNum==2){
    if(PadNum==3 || PadNum==1 || PadNum==2) {
    //TLatex * tlatex4=new TLatex(0.60,0.73,"|y_{lab}| < 2.4");
    TLatex * tlatex4=new TLatex(0.65,0.50,"|y_{lab}| < 2.4");


    tlatex4->SetNDC();
    tlatex4->SetTextColor(1);
    tlatex4->SetTextFont(42);//42
    tlatex4->SetTextSize(0.07);//0.045
    tlatex4->Draw();
	 }

	double GloUnc;
	double xtl5=0.54;

   if(PadNum==1) {GloUnc=Bp_commonErrorP*100;xtl5=0.54;}//###0.57
   if(PadNum==2) {GloUnc=B0_commonErrorP*100;xtl5=0.47;}
   if(PadNum==3) {GloUnc=Bs_commonErrorP*100;xtl5=0.42;}

	xtl5=0.54;


//TLegend *legendSigma=new TLegend(0.55,0.63,0.85,0.80,"");
   TLatex * tlatex5=new TLatex(xtl5,0.60,Form("Global uncert. %2.1f%%",GloUnc));
    tlatex5->SetNDC();
    tlatex5->SetTextColor(1);
    tlatex5->SetTextFont(42);//42
    tlatex5->SetTextSize(0.05*padcorrection);//0.045
    tlatex5->Draw();

  //###double xpos=0.8528226;
  //###double ypos=0.6849894;
  double xpos=0.90;//0.86
  double ypos=0.85;//0.86
  
  TString mypar;
  if(particle=="Bplus") mypar="B^{+}";
  if(particle=="Bzero") mypar="B^{0}";
  if(particle=="Bs") mypar="B_{s}^{0}";  

  double xlgap=0.04;
/*
  if(particle=="Bplus") xpos=(0.365816-xlgap)/0.365816;
  if(particle=="Bzero") xpos=1-xlgap/(0.673101-0.365816);
  if(particle=="Bs") xpos=0.94-xlgap/(1-0.673101);;  
*/
  TLatex * tlatex3=new TLatex(xpos,ypos,mypar.Data());
  tlatex3->SetNDC();
  tlatex3->SetTextColor(1);
  tlatex3->SetTextFont(42);
  tlatex3->SetTextSize(0.07*padcorrection);
  tlatex3->Draw();

  TGraphAsymmErrors *gRpAstat = new TGraphAsymmErrors(nbins,xbins,yRpA,exl0,exl0,yRpAStat,yRpAStat);
  gRpAstat->SetTitle("RpA stat uncertainty from pPb");
  gRpAstat->SetMarkerStyle(21);
  gRpAstat->SetMarkerColor(1);
  gRpAstat->SetLineColor(1);
  gRpAstat->SetLineWidth(2);  
  gRpAstat->SetFillColor(0);


  TGraphAsymmErrors *gRpAsyst = new TGraphAsymmErrors(nbins,xbins,yRpA,exl,exl,yRpPbSystTotLow,yRpPbSystTotHigh);
  gRpAsyst->SetTitle("RpA syst uncertainty from pPb");
  gRpAsyst->SetName("gRpAsyst");
/*
  gRpAsyst->SetFillColor(0);
  gRpAsyst->SetMarkerSize(0);
  gRpAsyst->SetLineColor(1);
  gRpAsyst->SetLineWidth(2);
  gRpAsyst->SetFillStyle(0);
*/
  gRpAsyst->SetFillColor(kYellow-7);//###0
  //gRpAsyst->SetMarkerSize(0);
  gRpAsyst->SetLineColor(1);
  gRpAsyst->SetLineWidth(2);
  gRpAsyst->SetFillStyle(1001);
  gRpAsyst->SetMarkerStyle(21);
  gRpAsyst->SetMarkerColor(1);
  TGraphAsymmErrors*gRpAsyst2=(TGraphAsymmErrors*)gRpAsyst->Clone();
  gRpAsyst2->SetMarkerColor(1);
  gRpAsyst2->SetMarkerStyle(25);
  gRpAsyst2->SetFillColor(0);
  gRpAsyst2->SetFillStyle(0);
  gRpAsyst2->SetLineColor(1);//5
  gRpAsyst2->SetLineStyle(1);
  gRpAsyst2->SetLineWidth(2);
  
  TGraphAsymmErrors *gRpAsystFONLL = new TGraphAsymmErrors(nbins,xbins,yFONLL,exl,exl,yRpAsystFONLLlow,yRpAsystFONLLhigh);
  gRpAsystFONLL->SetTitle("RpA syst uncertainty from FONLL reference");
/*
  gRpAsystFONLL->SetFillColor(kYellow-7);//5
  gRpAsystFONLL->SetLineColor(kAzure-3);//5
  gRpAsystFONLL->SetMarkerColor(4);//kAzure-3);

  TGraphAsymmErrors *gRpAsystFONLL2 = (TGraphAsymmErrors*)gRpAsystFONLL->Clone();
  gRpAsystFONLL2->SetFillStyle(0);
  gRpAsystFONLL2->SetLineColor(kAzure-3);//5
  gRpAsystFONLL2->SetMarkerColor(4);//kAzure-3);
*/
  gRpAsystFONLL->SetFillColor(0);//5,kYellow-7
  gRpAsystFONLL->SetLineColor(kAzure-3);//5
  gRpAsystFONLL->SetMarkerColor(4);//kAzure-3);
  gRpAsystFONLL->SetLineStyle(2);
  gRpAsystFONLL->SetLineWidth(2);

  TGraphAsymmErrors*gRpAsystFONLL2=(TGraphAsymmErrors*)gRpAsystFONLL->Clone();
  gRpAsystFONLL2->SetMarkerColor(1);
  gRpAsystFONLL2->SetMarkerStyle(25);
  gRpAsystFONLL2->SetFillColor(0);
  gRpAsystFONLL2->SetFillStyle(0);
  gRpAsystFONLL2->SetLineColor(kAzure-3);//5
  gRpAsystFONLL2->SetLineStyle(1);
  gRpAsystFONLL2->SetLineWidth(2);


  canvasRpA->cd(PadNum);
  //canvasRpA->Range(-1.989924,-0.2917772,25.49622,2.212202);
  canvasRpA->SetFillColor(0);
  canvasRpA->SetBorderMode(0);
  canvasRpA->SetBorderSize(2);
/*
  canvasRpA->SetLeftMargin(0.1451613);
  canvasRpA->SetRightMargin(0.05443548);
  canvasRpA->SetTopMargin(0.08474576);
  canvasRpA->SetBottomMargin(0.1165254);
*/
  canvasRpA->SetFrameBorderMode(0);
  canvasRpA->SetFrameBorderMode(0);
  
  hempty=new TH2F("hempty","",10,0.1, 62. ,30.,0.,3.0);  
  hempty->GetXaxis()->CenterTitle();
  hempty->GetYaxis()->CenterTitle();
  hempty->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hempty->GetYaxis()->SetTitle("R^{FONLL}_{pA}");
  //###hempty->GetXaxis()->SetTitleOffset(1.0);//###1.3
  hempty->GetYaxis()->SetTitleOffset(1.0);//###1.1
  hempty->GetXaxis()->SetTitleSize(0.070*padcorrection);//###0.055
  hempty->GetYaxis()->SetTitleSize(0.070*padcorrection);//###0.055
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.060*padcorrection);//###0.055
  hempty->GetYaxis()->SetLabelSize(0.060*padcorrection);//###0.055  
  if (particle=="Bplus") hempty->GetXaxis()->SetTitleOffset(0.90);//###1.0
  else if (particle=="Bzero") hempty->GetXaxis()->SetTitleOffset(0.90);//###0.80
  else if (particle=="Bs") hempty->GetXaxis()->SetTitleOffset(0.90);//###0.85
  if (particle=="Bplus") hempty->GetXaxis()->SetLabelOffset(0.005);//###0.005
  else if (particle=="Bzero") hempty->GetXaxis()->SetLabelOffset(0.005);//###0.0001
  else if (particle=="Bs") hempty->GetXaxis()->SetLabelOffset(0.005);//###0.0005
  //###hempty->SetMaximum(2);
  hempty->SetMaximum(3.0);
  hempty->SetMinimum(0.);

  hempty->Draw();
  
  TLine *l = new TLine(0,1, 65.,1);
  l->SetLineStyle(2);

  //TLine *line = new TLine(8.740882,1.017445,61,1.008586);
  //###TLine *line = new TLine(4.740882,1.017445,61,1.008586);
  TLine *line = new TLine(4.740882,1.00,61,1.00);


  line->SetLineColor(kRed);//###
  line->SetLineStyle(2);  
  line->SetLineWidth(2);
/*  
  gRpAsystFONLL->Draw("2same");
  gRpAsystFONLL2->Draw("2same");
  line->Draw();
  gRpAsyst->Draw("2esame");
  gRpAstat->Draw("psame");
*/
  gRpAstat->SetMarkerStyle(21);
  gRpAstat->SetLineColor(1);
  gRpAstat->SetMarkerColor(1);

for (int i=0;i<nbins;i++){
         double xgae,ygae;
         gRpAstat->GetPoint(i,xgae,ygae);
         std::cout << "####### RpA (" << i << ") : " << ygae << " stat: " << gRpAstat->GetEYhigh()[i] << " syst: " << gRpAsyst->GetEYhigh()[i] << std::endl;
	 std::cout << "########### FONLL (" << i << ") : " << " + " << gRpAsystFONLL->GetEYhigh()[i] << " - " << gRpAsystFONLL->GetEYlow()[i] << std::    endl;
}

  //###gRpAsystFONLL->Draw("2same");
  //###gRpAsystFONLL2->Draw("2same");
  //######line->Draw();
  for (int i=0;i<nbins;i++) {
    gRpAsystFONLL_box = new TBox(xbins[i]-exl[i],yFONLL[i]-yRpAsystFONLLlow[i],xbins[i]+exl[i],yFONLL[i]+yRpAsystFONLLhigh[i]);
    gRpAsystFONLL_box->SetLineColor(kAzure-3);
	 gRpAsystFONLL_box->SetLineWidth(3);
    gRpAsystFONLL_box->SetLineStyle(2);
    gRpAsystFONLL_box->SetFillColor(0);
    gRpAsystFONLL_box->SetFillStyle(0);
    //###gRpAsystFONLL_box->Draw("");
  }

//////////////////////////////////////////////
  // Histogram style
  TH1D* hRpAsystFONLL = new TH1D("hRpAsystFONLL","",nbins,xhbins);
  TH1D* hRpAsystFONLLEYhigh = new TH1D("hRpAsystFONLLEYhigh","",nbins,xhbins);
  TH1D* hRpAsystFONLLEYlow = new TH1D("hRpAsystFONLLEYlow","",nbins,xhbins);

  for (int i=0;i<nbins;i++){
	hRpAsystFONLL->SetBinContent(i+1,yFONLL[i]);
	hRpAsystFONLLEYhigh->SetBinContent(i+1,yFONLL[i]+yRpAsystFONLLhigh[i]);
	hRpAsystFONLLEYlow->SetBinContent(i+1,yFONLL[i]-yRpAsystFONLLlow[i]);
   }

   hRpAsystFONLLEYhigh->SetLineColor(kAzure-3);
	hRpAsystFONLLEYhigh->SetLineWidth(3);
   hRpAsystFONLLEYhigh->SetLineStyle(2);
   hRpAsystFONLLEYhigh->SetFillColor(0);
   hRpAsystFONLLEYhigh->SetFillStyle(0);
   hRpAsystFONLLEYhigh->Draw("][,same");

   hRpAsystFONLLEYlow->SetLineColor(kAzure-3);
	hRpAsystFONLLEYlow->SetLineWidth(3);
   hRpAsystFONLLEYlow->SetLineStyle(2);
   hRpAsystFONLLEYlow->SetFillColor(0);
   hRpAsystFONLLEYlow->SetFillStyle(0);
   hRpAsystFONLLEYlow->Draw("][,same");


/////////////////////////////////////////////

  gRpAsyst->Draw("2esame");
  gRpAsyst2->Draw("2esame");
  gRpAstat->Draw("psame");  
  line->Draw();

 
  TBox *a = new TBox(0.1,1-commonErrorN,4,1+commonErrorP);
  a->SetLineColor(1);
  a->SetFillColor(0);
  a->Draw();
  std::cout << "%%%%%%% RpA commonError " << " - " << commonErrorN << " + " << commonErrorP << std::endl;
  TBox *b = new TBox(0.1,1-commonErrorN,4,1+commonErrorP);
  b->SetLineColor(1);
  b->SetFillColor(kGray);
  b->Draw();
  TBox *b2 = (TBox*)b->Clone();
  b2->SetLineColor(1);
  b2->SetFillStyle(0);
  b2->Draw();

  TLegend *legendRpA=new TLegend(0.22,0.60,0.51,0.83,"");

  legendRpA->SetBorderSize(0);
  legendRpA->SetLineColor(0);
  legendRpA->SetFillColor(0);
  legendRpA->SetFillStyle(1001);
  legendRpA->SetTextFont(42);
  legendRpA->SetTextSize(0.060);//###0.045

  TLegendEntry *ent_RpAstat=legendRpA->AddEntry(gRpAstat,"R^{FONLL}_{pA}","p");
  //###TLegendEntry *ent_RpAstat=legendRpA->AddEntry(gRpAstat,"pPb data","pf");

/*
  ent_RpAstat->SetTextFont(42);
  ent_RpAstat->SetLineColor(2);
  ent_RpAstat->SetMarkerColor(2);
*/
  ent_RpAstat->SetTextFont(42);
  ent_RpAstat->SetMarkerColor(1);
  ent_RpAstat->SetMarkerStyle(25);
  //ent_RpAstat->SetFillColor(kYellow-7);//5
  //ent_RpAstat->SetFillStyle(1001);
  ent_RpAstat->SetLineColor(1);
  ent_RpAstat->SetLineWidth(2);
  ent_RpAstat->SetLineStyle(0);

  TLegendEntry *ent_RpAsyst=legendRpA->AddEntry(gRpAsyst,"Syst. pPb data","f");
  ent_RpAsyst->SetTextFont(42);
  ent_RpAsyst->SetMarkerColor(1);
  ent_RpAsyst->SetMarkerStyle(25);
  //ent_RpAsyst->SetFillColor(kYellow-7);//5
  //ent_RpAsyst->SetFillStyle(1001);
  ent_RpAsyst->SetLineColor(1);
  ent_RpAsyst->SetLineWidth(2);
  ent_RpAsyst->SetLineStyle(0);
  
  TLegendEntry *ent_RpAsystFONLL=legendRpA->AddEntry(gRpAsystFONLL,"Syst. FONLL pp ref.","f");
/*
  ent_RpAsystFONLL->SetTextFont(42);
  ent_RpAsystFONLL->SetLineColor(kAzure-3);//5
  ent_RpAsystFONLL->SetLineStyle(1);
  ent_RpAsystFONLL->SetLineWidth(1);
  ent_RpAsystFONLL->SetMarkerColor(kYellow-7);//5
*/

  ent_RpAsystFONLL->SetTextFont(42);
  ent_RpAsystFONLL->SetLineColor(2);//###5
  ent_RpAsystFONLL->SetLineStyle(1);
  ent_RpAsystFONLL->SetMarkerColor(kYellow-7);//5

   TLegendEntry *ent_RpAsystData=legendRpA->AddEntry(b,"Syst. int. lumi + B","f");
/*
  ent_RpAsystData->SetTextFont(42);
  ent_RpAsystData->SetLineColor(1);
  ent_RpAsystData->SetMarkerColor(2);
*/
  ent_RpAsystData->SetTextFont(42);
  ent_RpAsystData->SetLineColor(1);//###2
  ent_RpAsystData->SetMarkerColor(2);
 
  //if(PadNum==1||PadNum==3){
    if(PadNum==3 || PadNum==1 || PadNum==2) {

    legendRpA->Draw();

    //TLatex * tlatex4=new TLatex(0.21,0.88801268,"CMS");
    TLatex * tlatex4=new TLatex(0.19,0.85,"CMS");

    tlatex4->SetNDC();
    tlatex4->SetTextColor(1);
    tlatex4->SetTextFont(62);//42
    tlatex4->SetTextSize(0.07);//0.045
    tlatex4->Draw();
/* 
    TLatex * tlatex42=new TLatex(0.35,0.86,"Preliminary");
    tlatex42->SetNDC();
    tlatex42->SetTextColor(1);
    tlatex42->SetTextFont(52);//42
    tlatex42->SetTextSize(0.05);//0.045
    tlatex42->Draw();
*/ 
    //TLatex * tlatex2=new TLatex(0.471371,0.88801268,"L = 34.8 nb^{-1} (pPb 5.02 TeV)");
    //TLatex * tlatex2=new TLatex(0.471371,0.88801268,"34.6 nb^{-1} (pPb 5.02 TeV)");
    //###TLatex * tlatex2=new TLatex(0.390,0.950,"34.6 nb^{-1} (pPb 5.02 TeV)");
    TLatex * tlatex2;

   if (PadNum==1) tlatex2 = new TLatex(0.41,0.94,"34.6 nb^{-1} (pPb 5.02 TeV)");
   else tlatex2 = new TLatex(0.39,0.94,"34.6 nb^{-1} (pPb 5.02 TeV)");

    tlatex2->SetNDC();
    tlatex2->SetTextColor(1);
    tlatex2->SetTextFont(42);
    tlatex2->SetTextSize(0.06);//0.045
   tlatex2->Draw();
  }
    //if(PadNum==2){
    if(PadNum==3 || PadNum==1 || PadNum==2) {

    TLatex * tlatex4=new TLatex(0.65,0.23,"|y_{lab}| < 2.4");
    tlatex4->SetNDC();
    tlatex4->SetTextColor(1);
    tlatex4->SetTextFont(42);//42
    tlatex4->SetTextSize(0.07);//0.045
    tlatex4->Draw();
	 }

  
  tlatex3->Draw();
  
  
  
  TFile *fout=new TFile(Form("../Results%s/fileRpA%s.root",particle.Data(),particle.Data()),"recreate");  
  fout->cd();
  gSigmasyst->SetName("gSigmasyst");
  gSigmasyst->Write();
  gaeBplusReference->Write();
  hSigmapPbStat->Write();
}

void NuclearModification_DrawOnSamePad(){

  gStyle->SetTextSize(0.060);
  gStyle->SetTextFont(42);
  //gStyle->SetPadRightMargin(0.000);
  //gStyle->SetPadLeftMargin(0.000);
  gStyle->SetPadRightMargin(0.020);
  gStyle->SetPadLeftMargin(0.165);//0.145
  gStyle->SetPadTopMargin(0.075);
  gStyle->SetPadBottomMargin(0.145);

  //TCanvas *cSigma=new TCanvas("canvasSigma","canvasSigma",1150,500);
  //TCanvas *cRpA=new TCanvas("canvasRpA","canvasRpA",1150,500);
  TCanvas *cSigma=new TCanvas("canvasSigma","canvasSigma",1128,390);
  TCanvas *cRpA=new TCanvas("canvasRpA","canvasRpA",1128,390);


/*
  makeMultiPanelCanvas(cSigma, 3, 1, true);
  makeMultiPanelCanvas(cRpA, 3, 1, false);
*/
  makeIndepPadCanvas(cSigma, true);
  makeIndepPadCanvas(cRpA, false);

  NuclearModification(
    Bp_particle,
    Bp_nbins,
    Bp_xbins,
    Bp_xhbins,
    Bp_exl,
    Bp_exl2,
    Bp_exl0,
    Bp_yPercSigmapPbSystTotHigh,
    Bp_yPercSigmapPbSystTotLow,
    Bp_commonErrorP,
    Bp_commonErrorN,
    Bp_FFsysterror,
    Bp_tagandprobcorrection,
    cSigma,
    cRpA,
	1
  );
  NuclearModification(
    B0_particle,
    B0_nbins,
    B0_xbins,
    B0_xhbins,
    B0_exl,
    B0_exl2,
    B0_exl0,
    B0_yPercSigmapPbSystTotHigh,
    B0_yPercSigmapPbSystTotLow,
    B0_commonErrorP,
    B0_commonErrorN,
    B0_FFsysterror,
    B0_tagandprobcorrection,
    cSigma,
    cRpA,
	2
  );
  NuclearModification(
    Bs_particle,
    Bs_nbins,
    Bs_xbins,
    Bs_xhbins,
    Bs_exl,
    Bs_exl2,
    Bs_exl0,
    Bs_yPercSigmapPbSystTotHigh,
    Bs_yPercSigmapPbSystTotLow,
    Bs_commonErrorP,
    Bs_commonErrorN,
    Bs_FFsysterror,
    Bs_tagandprobcorrection,
    cSigma,
    cRpA,
	3
  );
  cSigma->SaveAs(Form("../ResultsAll/canvasSigma.pdf"));  
  cRpA->SaveAs(Form("../ResultsAll/canvasRpA.pdf"));  
  cSigma->SaveAs(Form("../ResultsAll/canvasSigma.eps"));  
  cRpA->SaveAs(Form("../ResultsAll/canvasRpA.eps"));  
  cSigma->SaveAs(Form("../ResultsAll/canvasSigma.png"));  
  cRpA->SaveAs(Form("../ResultsAll/canvasRpA.png"));  

}

void makeIndepPadCanvas(TCanvas*& canv, 
bool  setlogy
) 
{
  canv->Clear();
  int columns=3;
  TPad* pad[columns];
  TString padName;
  double Xlow[3] = {0.000,0.342,0.671};
  double Xup[3] = {0.342,0.671,1.000};
  for(Int_t i=0;i<columns;i++) {
      canv->cd();
      padName = Form("p_%d_%d",i,0);
      pad[i] = new TPad(padName.Data(),padName.Data(),
      Xlow[i],0.01,Xup[i],0.99);
      pad[i]->Draw();
      pad[i]->cd();
      pad[i]->SetNumber(i+1);
      if(setlogy) pad[i]->SetLogy();
    }

}
void makeMultiPanelCanvas(TCanvas*& canv, 
const Int_t columns,
const Int_t rows,
bool  setlogy,
const Float_t leftOffset,
const Float_t bottomOffset,
const Float_t leftMargin,
const Float_t bottomMargin,
const Float_t edge
) 
{
  if (canv==0) {
    cout << "makeMultiPanelCanvas","Got null canvas.";
    return;
  }
  canv->Clear();
 //  Float_t pad_width  = 0.;
//   Float_t   pad_height = 0.;
//    Float_t charheight = 0.05;
//   Float_t textsize= 0.05;
  TPad* pad[columns][rows];
  Float_t Xlow[columns];
  Float_t Xup[columns];
  Float_t Ylow[rows];
  Float_t Yup[rows];
  Float_t PadWidth = (1.0-leftOffset)/((1.0/(1.0-leftMargin)) + (1.0/(1.0-edge))+(Float_t)columns-2.0);
  Float_t PadHeight = (1.0-bottomOffset)/((1.0/(1.0-bottomMargin)) + (1.0/(1.0-edge))+(Float_t)rows-2.0);
  std::cout << "PadWidth: " << PadWidth << ",PadHeight: " << PadHeight << std::endl;
  Xlow[0] = leftOffset;
  Xup[0] = leftOffset + PadWidth/(1.0-leftMargin);
  Xup[columns-1] = 1;
  Xlow[columns-1] = 1.0-PadWidth/(1.0-edge);
  Yup[0] = 1;
  Ylow[0] = 1.0-PadHeight/(1.0-edge);
  Ylow[rows-1] = bottomOffset;
  Yup[rows-1] = bottomOffset + PadHeight/(1.0-bottomMargin);
  for(Int_t i=1;i<columns-1;i++) {
    Xlow[i] = Xup[0] + (i-1)*PadWidth;
    Xup[i] = Xup[0] + (i)*PadWidth;
  }
  Int_t ct = 0;
  for(Int_t i=rows-2;i>0;i--) {
    Ylow[i] = Yup[rows-1] + ct*PadHeight;
    Yup[i] = Yup[rows-1] + (ct+1)*PadHeight;
    ct++;
  }
  TString padName;
  for(Int_t i=0;i<columns;i++) {
    for(Int_t j=0;j<rows;j++) {
      canv->cd();
      padName = Form("p_%d_%d",i,j);
      pad[i][j] = new TPad(padName.Data(),padName.Data(),
      Xlow[i],Ylow[j],Xup[i],Yup[j]);
      std::cout << i << " , " << j << " - " << Xlow[i] << "," << Ylow[j] << "," << Xup[i] << "," << Yup[j] << std::endl;
      if(i==0) pad[i][j]->SetLeftMargin(leftMargin);
      else pad[i][j]->SetLeftMargin(0);
      if(i==(columns-1)) pad[i][j]->SetRightMargin(edge);
      else pad[i][j]->SetRightMargin(0);
      if(j==0) pad[i][j]->SetTopMargin(edge);
      else pad[i][j]->SetTopMargin(0);
      if(j==(rows-1)) pad[i][j]->SetBottomMargin(bottomMargin);
      else pad[i][j]->SetBottomMargin(0);
      pad[i][j]->Draw();
      pad[i][j]->cd();
      pad[i][j]->SetNumber(columns*j+i+1);
      if(setlogy) pad[i][j]->SetLogy();
    }
  }
}
