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
//#include <TMathText.h>

TString particle="Bplus";
const int nbinsRFB = 2;
Double_t xbinsRFB[nbinsRFB]={0.5,1.465};
Double_t exlRFB[nbinsRFB]={0.5,0.465};
Double_t yRFBSystTotHighRel[nbinsRFB]= {0.162,0.196};
Double_t yRFBSystTotLowRel[nbinsRFB]= {0.162,0.196};

const int nbins = 5;
Double_t xbins[nbins]={-2.4,-1.465,-0.5,0.5,1.465};
Double_t xhbins[nbins+1]={-2.865,-1.935,-1.0,0.0,1.0,1.935};

Double_t exl[nbins]={0.465,0.465,0.5,0.5,0.465};
Double_t exl2[nbins]={0.415,0.415,0.45,0.45,0.415};
Double_t exl0[nbins]={0.0,0.0,0.0,0.0,0.0};


Double_t yPercSigmapPbSystTotHigh[nbins]={0.148,0.150,0.149,0.154,0.148};
Double_t yPercSigmapPbSystTotLow[nbins]={0.148,0.150,0.149,0.154,0.148};

Double_t commonErrorP = TMath::Sqrt(0.035*0.035+0.031*0.031);
Double_t commonErrorN = TMath::Sqrt(0.035*0.035+0.031*0.031);
//Double_t tagandprobcorrection[nbins]={1.054,1.044,1.037,1.034,1.036};
//Double_t tagandprobcorrection[nbins]={1.077,1.053,1.048,1.067,1.081};//new correction
Double_t tagandprobcorrection[nbins]={1.059,1.063,1.056,1.070,1.058};//new correction, abs eta binning

void NuclearModificationY(){

  gROOT->SetStyle("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
/*
  gStyle->SetPadRightMargin(0.010);//###0.020
  gStyle->SetPadLeftMargin(0.165);
  gStyle->SetPadTopMargin(0.075);
  gStyle->SetPadBottomMargin(0.145);
*/

    
  TFile*filePPReference=new TFile(Form("../../../fonll/output%sY.root",particle.Data()));  
  //TFile*filePPReference=new TFile(Form("../../fonll/output%sY.root",particle.Data()));  
  TGraphAsymmErrors*gaeBplusReference=(TGraphAsymmErrors*)filePPReference->Get(Form("gaeSigmaDecay%s",particle.Data()));
  gaeBplusReference->SetName(Form("gae%sReference",particle.Data()));
  
  TFile*filepPb=new TFile(Form("../Results%s_y/Sigma%s.root",particle.Data(),particle.Data()));
  TH1F*hSigmapPbStat=(TH1F*)filepPb->Get("hPtSigma");  
  
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
    hSigmapPbStat->SetBinContent(i+1,(1./tagandprobcorrection[i])*(hSigmapPbStat->GetBinContent(i+1)));
    hSigmapPbStat->SetBinError(i+1,(1./tagandprobcorrection[i])*(hSigmapPbStat->GetBinError(i+1)));
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

  Double_t yRFB[nbinsRFB];
  Double_t yRFBStat[nbinsRFB];
  Double_t yRFBSystTotHigh[nbinsRFB];
  Double_t yRFBSystTotLow[nbinsRFB];

  double x,y;

  for (Int_t i=0;i<nbins;i++) {
    gaeBplusReference->GetPoint(i,xRefPP[i],yRefPP[i]);
    yPPsystFONLLhigh[i]=gaeBplusReference->GetEYhigh()[i];
    yPPsystFONLLlow[i]=gaeBplusReference->GetEYlow()[i];
    yPercPPsystFONLLhigh[i]=yPPsystFONLLhigh[i]/yRefPP[i];
    yPercPPsystFONLLlow[i]=yPPsystFONLLlow[i]/yRefPP[i];
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
  }

  //RFB stuff
  //central value
  yRFB[0] =  ySigmapPb[3]/ySigmapPb[2];
  yRFB[1] =  ySigmapPb[4]/ySigmapPb[1];
  //Stat.
  yRFBStat[0] =  yRFB[0]*sqrt(pow(ySigmapPbStat[2]/ySigmapPb[2],2)+pow(ySigmapPbStat[3]/ySigmapPb[3],2));
  yRFBStat[1] =  yRFB[1]*sqrt(pow(ySigmapPbStat[4]/ySigmapPb[4],2)+pow(ySigmapPbStat[1]/ySigmapPb[1],2));
  //Syst.

  yRFBSystTotHigh[0] = yRFB[0]*yRFBSystTotHighRel[0];
  yRFBSystTotLow[0] = yRFB[0]*yRFBSystTotLowRel[0];
  yRFBSystTotHigh[1] = yRFB[1]*yRFBSystTotHighRel[1];
  yRFBSystTotLow[1] = yRFB[1]*yRFBSystTotLowRel[1];
    
  TGraphAsymmErrors *gSigmasyst = new TGraphAsymmErrors(nbins,xbins,ySigmapPb,exl2,exl2,ySigmapPbSystTotLow,ySigmapPbSystTotHigh);
  //###TGraphAsymmErrors *gSigmasyst = new TGraphAsymmErrors(nbins,xbins,ySigmapPb,exl,exl,ySigmapPbSystTotLow,ySigmapPbSystTotHigh);

  gSigmasyst->SetTitle("Sigma syst uncertainty from pPb");
  gSigmasyst->SetMarkerColor(1);
  gSigmasyst->SetLineColor(1);
  gSigmasyst->SetLineWidth(3);   
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
  gSigmasyst2->SetLineWidth(3);


  //###TGraphAsymmErrors *gSigmastat = new TGraphAsymmErrors(nbins,xbins,ySigmapPb,exl,exl,ySigmapPbStat,ySigmapPbStat);
  TGraphAsymmErrors *gSigmastat = new TGraphAsymmErrors(nbins,xbins,ySigmapPb,exl0,exl0,ySigmapPbStat,ySigmapPbStat);


  gSigmastat->SetTitle("Sigma stat uncertainty from pPb");
  gSigmastat->SetMarkerColor(1);
  gSigmastat->SetLineColor(1);
  gSigmastat->SetLineWidth(3);   
  gSigmastat->SetMarkerStyle(21);
  gSigmastat->SetMarkerColor(1);
  
  gSigmastat->SetFillColor(0);
  gSigmastat->SetFillStyle(0);


  //###TCanvas *canvasSigma=new TCanvas("canvasSigma","canvasSigma",600,500);   
  TCanvas *canvasSigma=new TCanvas("canvasSigma","canvasSigma",500,500);   
  canvasSigma->cd();
  canvasSigma->Range(-1.989924,-0.2917772,25.49622,2.212202);
  canvasSigma->SetFillColor(0);
  canvasSigma->SetBorderMode(0);
  canvasSigma->SetBorderSize(2);
  canvasSigma->SetLeftMargin(0.200);
  canvasSigma->SetRightMargin(0.025);
  canvasSigma->SetTopMargin(0.080);
  canvasSigma->SetBottomMargin(0.150);
  canvasSigma->SetFrameBorderMode(0);
  
  TH2F* hempty=new TH2F("hempty","",10,-3.5,2.5,10,0,650.);  
  hempty->GetXaxis()->SetTitle("y_{CM}");
  hempty->GetXaxis()->CenterTitle();
  hempty->GetYaxis()->CenterTitle();
  //###hempty->GetYaxis()->SetTitle("d#sigma / dy_{CM}(#mub GeV^{-1}c)");
  hempty->GetYaxis()->SetTitle("d#sigma / dy_{CM}(#mub)");
  hempty->GetXaxis()->SetTitleOffset(0.90);
  hempty->GetYaxis()->SetTitleOffset(1.34);
  hempty->GetXaxis()->SetTitleSize(0.070);//###0.045
  hempty->GetYaxis()->SetTitleSize(0.070);//###0.045
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.060);//###0.037
  hempty->GetYaxis()->SetLabelSize(0.060);//###0.037  
  hempty->SetMaximum(2);
  hempty->SetMinimum(0.);
  hempty->Draw();
    
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
}

  //hBplusReference->SetMarkerColor(1);
  //hBplusReference->SetMarkerStyle(25);  
  //hBplusReference->SetFillColor(kYellow-7);//5
  //hBplusReference->SetFillStyle(1001);
  hBplusReference->SetLineColor(kAzure-3);
  hBplusReference->SetLineWidth(3);
  hBplusReferenceEYhigh->SetLineColor(kAzure-3);
  hBplusReferenceEYhigh->SetLineWidth(3);
  hBplusReferenceEYhigh->SetLineStyle(2);
  hBplusReferenceEYlow->SetLineColor(kAzure-3);
  hBplusReferenceEYlow->SetLineWidth(3);
  hBplusReferenceEYlow->SetLineStyle(2);

for (int i=0;i<nbins;i++){
        double xgae,ygae;
        gaeBplusReference->GetPoint(i,xgae,ygae);
        hBplusReference->SetBinContent(i+1,ygae);
        hBplusReferenceEYhigh->SetBinContent(i+1,ygae+gaeBplusReference->GetEYhigh()[i]);
        hBplusReferenceEYlow->SetBinContent(i+1,ygae-gaeBplusReference->GetEYlow()[i]);
        std::cout << "### FONLL (" << i << ") : " << ygae << " + " << gaeBplusReference->GetEYhigh()[i] << " - " << gaeBplusReference->GetEYlow()[i] << std::endl;
}

  for (int i=0;i<nbins;i++){
        double xgae,ygae;
        gSigmastat->GetPoint(i,xgae,ygae);
        std::cout << "### cross section (" << i << ") : " << ygae << " stat: " << gSigmastat->GetEYhigh()[i] << " syst: " << gSigmasyst->GetEYhigh()[i]     << std::endl;
  }
/*
  hBplusReference->Draw("][,same");

  hBplusReferenceEYhigh->Draw("][,same");
  hBplusReferenceEYlow->Draw("][,same");
*/
/*  
  gaeBplusReference->SetMarkerColor(1);
  gaeBplusReference->SetMarkerStyle(25);  
  gaeBplusReference->SetFillColor(kYellow-7);//5
  gaeBplusReference->SetFillStyle(1001);
  gaeBplusReference->SetLineColor(kAzure-3);//5
  gaeBplusReference->SetLineStyle(1);
  gaeBplusReference->SetLineWidth(0);
  gaeBplusReference->Draw("2psame");

  TGraphAsymmErrors*gaeBplusReference2=(TGraphAsymmErrors*)gaeBplusReference->Clone(); 
  gaeBplusReference2->SetMarkerColor(1);
  gaeBplusReference2->SetMarkerStyle(25);  
  gaeBplusReference2->SetFillColor(0);
  gaeBplusReference2->SetFillStyle(0);
  gaeBplusReference2->SetLineColor(kAzure-3);//5
  gaeBplusReference2->SetLineStyle(1);
  gaeBplusReference2->SetLineWidth(1);
  gaeBplusReference2->Draw("2psame");
*/
  //gSigmasyst->SetFillColor(0);
  //gSigmasyst->SetFillStyle(0);
  gSigmasyst->Draw("2esame");//2same
  gSigmasyst2->Draw("2esame");

  hBplusReference->Draw("][,same");

  hBplusReferenceEYhigh->Draw("][,same");
  hBplusReferenceEYlow->Draw("][,same");

  gSigmastat->SetMarkerColor(1);
  gSigmastat->SetLineColor(1);
  gSigmastat->SetLineWidth(3);   
  gSigmastat->SetMarkerStyle(21);
  gSigmastat->SetMarkerColor(1);
  gSigmastat->SetFillColor(0);
  gSigmastat->Draw("epsame");

  //###TLegend *legendSigma=new TLegend(0.233871,0.6701903,0.5322581,0.7526427,"");
  //TLegend *legendSigma=new TLegend(0.40,0.60,0.70,0.78,"");
  TLegend *legendSigma=new TLegend(0.23,0.56,0.57,0.77,"");

  legendSigma->SetBorderSize(0);
  legendSigma->SetLineColor(0);
  legendSigma->SetFillColor(0);
  legendSigma->SetFillStyle(1001);
  legendSigma->SetTextFont(42);
  legendSigma->SetTextSize(0.055);//###0.045
/*
  TBox *c = new TBox(0.1,1-commonErrorN,4,1+commonErrorP);
  c->SetLineColor(5);
  c->SetFillColor(5);
  c->Draw();
*/  
  gSigmastat->SetMarkerSize(1);

  TLegendEntry *ent_SigmapPb=legendSigma->AddEntry(gSigmastat,"pPb data","p");
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
/*
///
  TLegendEntry *ent_SigmapPb=legendSigma->AddEntry(gSigmasyst,"pPb","pf");
  ent_SigmapPb->SetTextFont(42);
  ent_SigmapPb->SetLineColor(1);
  ent_SigmapPb->SetMarkerColor(1);
  ent_SigmapPb->SetMarkerStyle(25);
  //ent_SigmapPb->SetFillColor(kYellow-7);//5
  //ent_SigmapPb->SetFillStyle(1001);
  ent_SigmapPb->SetLineColor(1);
  ent_SigmapPb->SetLineWidth(0);
  ent_SigmapPb->SetLineStyle(0);
////
*/
/*
  TLegendEntry *ent_Sigmapp=legendSigma->AddEntry(gaeBplusReference,"FONLL pp ref.","fp");
  ent_Sigmapp->SetTextFont(42);
  ent_Sigmapp->SetLineColor(kAzure-3);//5
  ent_Sigmapp->SetLineStyle(1);
  ent_Sigmapp->SetMarkerColor(1);
  ent_Sigmapp->SetMarkerStyle(25);
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

  legendSigma->Draw("psame");
/*
  TBox *d = new TBox(0.1,1-commonErrorN,4,1+commonErrorP);
  d->SetLineColor(1);
  d->SetFillColor(0);
  d->Draw();
*/
  //###TLatex * tlatex1=new TLatex(0.23,0.84,"CMS");
  TLatex * tlatex1=new TLatex(0.24,0.85,"CMS");

  tlatex1->SetNDC();
  tlatex1->SetTextColor(1);
  tlatex1->SetTextFont(62);//###42
  tlatex1->SetTextSize(0.07);//###0.045
  tlatex1->Draw();
/*
  TLatex * tlatex12=new TLatex(0.24,0.80,"Preliminary");
  tlatex12->SetNDC();
  tlatex12->SetTextColor(1);
  tlatex12->SetTextFont(52);//###42
  tlatex12->SetTextSize(0.05);//###0.045
  tlatex12->Draw();
*/  

  TString mypar="B^{+}";
  
  //###TLatex * tlatexlumi=new TLatex(0.671371,0.7801268,"L = 34.8 nb^{-1}");
  TLatex * tlatexlumi=new TLatex(0.40,0.94,"34.6 nb^{-1} (pPb 5.02 TeV)");
  tlatexlumi->SetNDC();
  tlatexlumi->SetTextColor(1);
  tlatexlumi->SetTextFont(42);
  tlatexlumi->SetTextSize(0.06);//###0.045
  tlatexlumi->Draw();

  //###double xpos=0.8528226;
  //###double ypos=0.6849894;
  double xpos=0.85;
  double ypos=0.75;
  
  TLatex * tlatex3=new TLatex(xpos,ypos,mypar.Data());
   tlatex3->SetNDC();
  tlatex3->SetTextColor(1);
  tlatex3->SetTextFont(42);
  tlatex3->SetTextSize(0.07);//###0.06
  tlatex3->Draw();
  
  //###TLatex * tlatex4=new TLatex(0.51,0.84,"10 < p_{T}^{B} < 60 GeV/c");
  TLatex * tlatex4=new TLatex(0.51,0.84,"10 < p_{T} < 60 GeV/c");
  tlatex4->SetNDC();
  tlatex4->SetTextColor(1);
  tlatex4->SetTextFont(42);
  tlatex4->SetTextSize(0.06);
  tlatex4->Draw();
 
  TLatex * tlatex5=new TLatex(0.62,0.20,Form("Global uncert. %2.1f%%",commonErrorP*100));
  tlatex5->SetNDC();
  tlatex5->SetTextColor(1);
  tlatex5->SetTextFont(42);
  tlatex5->SetTextSize(0.04);
  tlatex5->Draw();


  canvasSigma->SaveAs(Form("../Results%s_y/canvasSigma%s.pdf",particle.Data(),particle.Data()));  
  canvasSigma->SaveAs(Form("../Results%s_y/canvasSigma%s.png",particle.Data(),particle.Data()));  

  canvasSigma->SaveAs(Form("../Results%s_y/canvasSigma%s.eps",particle.Data(),particle.Data()));  
  
  TGraphAsymmErrors *gRpAstat = new TGraphAsymmErrors(nbins,xbins,yRpA,exl,exl,yRpAStat,yRpAStat);
  gRpAstat->SetTitle("RpA stat uncertainty from pPb");
  gRpAstat->SetMarkerStyle(21);
  gRpAstat->SetMarkerColor(1);
  gRpAstat->SetLineColor(1);
  gRpAstat->SetLineWidth(3);  
  gRpAstat->SetFillColor(0);
  
  TGraphAsymmErrors *gRpAsyst = new TGraphAsymmErrors(nbins,xbins,yRpA,exl,exl,yRpPbSystTotLow,yRpPbSystTotHigh);
  gRpAsyst->SetTitle("RpA syst uncertainty from pPb");
  gRpAsyst->SetFillColor(kYellow-7);//###0
  //gRpAsyst->SetMarkerSize(0);
  gRpAsyst->SetLineColor(1);
  gRpAsyst->SetLineWidth(3);
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
  gRpAsyst2->SetLineWidth(3);


   
  TGraphAsymmErrors *gRpAsystFONLL = new TGraphAsymmErrors(nbins,xbins,yFONLL,exl,exl,yRpAsystFONLLlow,yRpAsystFONLLhigh);
  gRpAsystFONLL->SetTitle("RpA syst uncertainty from FONLL reference");
  gRpAsystFONLL->SetFillColor(0);//5,kYellow-7
  gRpAsystFONLL->SetLineColor(kAzure-3);//5
  gRpAsystFONLL->SetMarkerColor(4);//kAzure-3);
  gRpAsystFONLL->SetLineStyle(2);//###1
  gRpAsystFONLL->SetLineWidth(3);


  TGraphAsymmErrors*gRpAsystFONLL2=(TGraphAsymmErrors*)gRpAsystFONLL->Clone(); 
  gRpAsystFONLL2->SetMarkerColor(1);
  gRpAsystFONLL2->SetMarkerStyle(25);  
  gRpAsystFONLL2->SetFillColor(0);
  gRpAsystFONLL2->SetFillStyle(0);
  gRpAsystFONLL2->SetLineColor(kAzure-3);//5
  gRpAsystFONLL2->SetLineStyle(2);//###1
  gRpAsystFONLL2->SetLineStyle(3);
  gRpAsystFONLL2->SetLineWidth(3);

//###
  TBox *gRpAsystFONLL_box0 = new TBox(xbins[0]-exl[0],yFONLL[0]-yRpAsystFONLLlow[0],xbins[0]+exl[0],yFONLL[0]+yRpAsystFONLLhigh[0]);
  gRpAsystFONLL_box0->SetLineColor(kAzure-3);
  gRpAsystFONLL_box0->SetLineWidth(3);
  gRpAsystFONLL_box0->SetLineStyle(2);
  gRpAsystFONLL_box0->SetFillColor(0);
  gRpAsystFONLL_box0->SetFillStyle(0);

  TBox *gRpAsystFONLL_box1 = new TBox(xbins[1]-exl[1],yFONLL[1]-yRpAsystFONLLlow[1],xbins[1]+exl[1],yFONLL[1]+yRpAsystFONLLhigh[1]);
  gRpAsystFONLL_box1->SetLineColor(kAzure-3);
  gRpAsystFONLL_box1->SetLineWidth(3);
  gRpAsystFONLL_box1->SetLineStyle(2);
  gRpAsystFONLL_box1->SetFillColor(0);
  gRpAsystFONLL_box1->SetFillStyle(0);

  TBox *gRpAsystFONLL_box2 = new TBox(xbins[2]-exl[2],yFONLL[2]-yRpAsystFONLLlow[2],xbins[2]+exl[2],yFONLL[2]+yRpAsystFONLLhigh[2]);
  gRpAsystFONLL_box2->SetLineColor(kAzure-3);
  gRpAsystFONLL_box2->SetLineWidth(3);
  gRpAsystFONLL_box2->SetLineStyle(2);
  gRpAsystFONLL_box2->SetFillColor(0);
  gRpAsystFONLL_box2->SetFillStyle(0);

  TBox *gRpAsystFONLL_box3 = new TBox(xbins[3]-exl[3],yFONLL[3]-yRpAsystFONLLlow[3],xbins[3]+exl[3],yFONLL[3]+yRpAsystFONLLhigh[3]);
  gRpAsystFONLL_box3->SetLineColor(kAzure-3);
  gRpAsystFONLL_box3->SetLineWidth(3);
  gRpAsystFONLL_box3->SetLineStyle(2);
  gRpAsystFONLL_box3->SetFillColor(0);
  gRpAsystFONLL_box3->SetFillStyle(0);

  TBox *gRpAsystFONLL_box4 = new TBox(xbins[4]-exl[4],yFONLL[4]-yRpAsystFONLLlow[4],xbins[4]+exl[4],yFONLL[4]+yRpAsystFONLLhigh[4]);
  gRpAsystFONLL_box4->SetLineColor(kAzure-3);
  gRpAsystFONLL_box4->SetLineWidth(3);
  gRpAsystFONLL_box4->SetLineStyle(2);
  gRpAsystFONLL_box4->SetFillColor(0);
  gRpAsystFONLL_box4->SetFillStyle(0);

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

    hRpAsystFONLLEYlow->SetLineColor(kAzure-3);
    hRpAsystFONLLEYlow->SetLineWidth(3);
    hRpAsystFONLLEYlow->SetLineStyle(2);
    hRpAsystFONLLEYlow->SetFillColor(0);
    hRpAsystFONLLEYlow->SetFillStyle(0);
    hRpAsystFONLLEYlow->Draw("][,same");


  //###TCanvas *canvasRpA=new TCanvas("canvasRpA","canvasRpA",600,500);   
  TCanvas *canvasRpA=new TCanvas("canvasRpA","canvasRpA",500,500);   
  
  canvasRpA->Range(-1.989924,-0.2917772,25.49622,2.212202);
  canvasRpA->SetFillColor(0);
  canvasRpA->SetBorderMode(0);
  canvasRpA->SetBorderSize(2);
  canvasRpA->SetLeftMargin(0.200);
  canvasRpA->SetRightMargin(0.025);
  canvasRpA->SetTopMargin(0.080);
  canvasRpA->SetBottomMargin(0.150);
  canvasRpA->SetFrameBorderMode(0);
  canvasRpA->SetFrameBorderMode(0);
  
  //###TLegend *legendRpA=new TLegend(0.23,0.58,0.57,0.77,"");
  TLegend *legendRpA=new TLegend(0.23,0.56,0.57,0.77,"");

  legendRpA->SetBorderSize(0);
  legendRpA->SetLineColor(0);
  legendRpA->SetFillColor(0);
  legendRpA->SetFillStyle(1001);
  legendRpA->SetTextFont(42);
  legendRpA->SetTextSize(0.055);//###0.04

  hempty=new TH2F("hempty","",4,-3.5,2.7,40.,0.,4.0);  
  hempty->GetXaxis()->SetTitle("y_{CM}");
  /*
  if(particle=="Bplus") hempty->GetYaxis()->SetTitle("R^{FONLL}_{pA}  (B^{+})");
  if(particle=="Bzero") hempty->GetYaxis()->SetTitle("R^{FONLL}_{pA}  (B^{0})");
  if(particle=="Bs") hempty->GetYaxis()->SetTitle("R^{FONLL}_{pA}  (B_{s})");
  */
  hempty->GetYaxis()->SetTitle("R^{FONLL}_{pA}");

  hempty->GetXaxis()->CenterTitle();
  hempty->GetYaxis()->CenterTitle();
  hempty->GetXaxis()->SetTitleOffset(0.90);
  hempty->GetYaxis()->SetTitleOffset(1.34);
  hempty->GetXaxis()->SetTitleSize(0.070);//###0.045
  hempty->GetYaxis()->SetTitleSize(0.070);//###0.045
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.060);//###0.040
  hempty->GetYaxis()->SetLabelSize(0.060);//###0.040  
  hempty->SetMaximum(4.0);
  hempty->SetMinimum(0.);
  hempty->Draw();
  
  TLine *l = new TLine(0,1,70,1);
  l->SetLineStyle(2);
  
  legendRpA->Draw();
  gRpAstat->SetMarkerStyle(21);
  gRpAstat->SetLineColor(1);
  gRpAstat->SetMarkerColor(1);

for (int i=0;i<nbins;i++){
         double xgae,ygae;
         gRpAstat->GetPoint(i,xgae,ygae);
         std::cout << "####### RpA (" << i << ") : " << ygae << " stat: " << gRpAstat->GetEYhigh()[i] << " syst: " << gRpAsyst->GetEYhigh()[i] << std::endl;
         std::cout << "########### FONLL (" << i << ") : " << " + " << gRpAsystFONLL->GetEYhigh()[i] << " - " << gRpAsystFONLL->GetEYlow()[i] << std::    endl;
}

  //###gRpAsystFONLL->Draw("e2same");//###2same
  //###gRpAsystFONLL2->Draw("2esame");//###2same
/*
  gRpAsystFONLL_box0->Draw("same");
  gRpAsystFONLL_box1->Draw("same");
  gRpAsystFONLL_box2->Draw("same");
  gRpAsystFONLL_box3->Draw("same");
  gRpAsystFONLL_box4->Draw("same");
*/
  hRpAsystFONLLEYlow->Draw("][,same");
  hRpAsystFONLLEYhigh->Draw("][,same");
 
  gRpAsyst->Draw("2esame");
  gRpAsyst2->Draw("2esame");
  gRpAstat->Draw("psame");
  
  std::cout << "%%%%%%% RpA commonError " << " - " << commonErrorN << " + " << commonErrorP << std::endl;
  TBox *b = new TBox(-3.49,1-commonErrorN,-3.1,1+commonErrorP);
  b->SetLineColor(1);
  b->SetLineWidth(1);
  b->SetLineStyle(1);
  b->SetFillColor(kGray);
  b->Draw();
  
  TBox *b2=(TBox*)b->Clone();
  b2->SetFillStyle(0);
  b2->SetLineStyle(1);
  b2->SetLineWidth(1);
  b2->Draw();

  TGraphAsymmErrors*gRpAstat2=(TGraphAsymmErrors*)gRpAstat->Clone();
  gRpAstat2->SetTitle("RpA stat uncertainty from pPb");
  gRpAstat2->SetMarkerStyle(21);
  gRpAstat2->SetMarkerColor(1);
  gRpAstat2->SetLineColor(1);
  gRpAstat2->SetLineWidth(3);  
  gRpAstat2->SetFillColor(0);
  gRpAstat2->SetMarkerSize(1.5);
  
  TLegendEntry *ent_RpAstat=legendRpA->AddEntry(gRpAstat2,"R^{FONLL}_{pA}","p");
  ent_RpAstat->SetTextFont(42);
  ent_RpAstat->SetMarkerColor(1);
  ent_RpAstat->SetMarkerStyle(25);
  ent_RpAstat->SetMarkerSize(30);//###3
  //ent_RpAstat->SetFillColor(kYellow-7);//5
  //ent_RpAstat->SetFillStyle(1001);
  ent_RpAstat->SetLineColor(1);
  ent_RpAstat->SetLineWidth(3);
  ent_RpAstat->SetLineStyle(0);
 
   //TLegendEntry *ent_RpAsyst=legendRpA->AddEntry(gRpAsyst,"R^{FONLL}_{pA}","pf");
  TLegendEntry *ent_RpAsyst=legendRpA->AddEntry(gRpAsyst,"Syst. pPb data","f");
  ent_RpAsyst->SetTextFont(42);
  ent_RpAsyst->SetMarkerColor(1);
  ent_RpAsyst->SetMarkerStyle(25);
  //ent_RpAsyst->SetFillColor(kYellow-7);//5
  //ent_RpAsyst->SetFillStyle(1001);
  ent_RpAsyst->SetLineColor(1);
  ent_RpAsyst->SetLineWidth(3);
  ent_RpAsyst->SetLineStyle(0);
 
  TLegendEntry *ent_RpAsystFONLL=legendRpA->AddEntry(gRpAsystFONLL,"Syst. FONLL pp ref.","f");
  ent_RpAsystFONLL->SetTextFont(42);
  ent_RpAsystFONLL->SetLineColor(kAzure-3);//###5
  ent_RpAsystFONLL->SetLineStyle(1);//###0
  ent_RpAsystFONLL->SetLineWidth(3);
  ent_RpAsystFONLL->SetMarkerColor(kYellow-7);//5

   //###TLegendEntry *ent_RpAsystData=legendRpA->AddEntry(b,"Syst. int. lumi + BR","f");
  TLegendEntry *ent_RpAsystData=legendRpA->AddEntry(b,"Syst. int. lumi + B","f");
  ent_RpAsystData->SetTextFont(42);
  ent_RpAsystData->SetLineColor(2);
  ent_RpAsystData->SetMarkerColor(2);
  
  tlatex1->Draw();
  //###tlatex12->Draw();


  tlatexlumi->Draw();
  tlatex3->Draw();
  tlatex4->Draw();


  canvasRpA->SaveAs(Form("../Results%s_y/canvasRpA%s.pdf",particle.Data(),particle.Data()));  
  canvasRpA->SaveAs(Form("../Results%s_y/canvasRpA%s.png",particle.Data(),particle.Data()));  

  canvasRpA->SaveAs(Form("../Results%s_y/canvasRpA%s.eps",particle.Data(),particle.Data()));  
  canvasRpA->SaveAs(Form("../Results%s_y/canvasRpA%s.ps",particle.Data(),particle.Data()));  


/*
  TCanvas *canvasRFB=new TCanvas("canvasRFB","canvasRFB",500,500);   
  canvasRFB->cd();
  canvasRFB->Range(-1.989924,-0.2917772,25.49622,2.212202);
  canvasRFB->SetFillColor(0);
  canvasRFB->SetBorderMode(0);
  canvasRFB->SetBorderSize(2);
  canvasRFB->SetLeftMargin(0.1451613);
  canvasRFB->SetRightMargin(0.05443548);
  canvasRFB->SetTopMargin(0.08474576);
  canvasRFB->SetBottomMargin(0.1165254);
  canvasRFB->SetFrameBorderMode(0);
  canvasRFB->SetFrameBorderMode(0);
 
  TLegend *legendRFB=new TLegend(0.2560484,0.6490486,0.5483871,0.7716702,"");
  legendRFB->SetBorderSize(0);
  legendRFB->SetLineColor(0);
  legendRFB->SetFillColor(0);
  legendRFB->SetFillStyle(1001);
  legendRFB->SetTextFont(42);
  legendRFB->SetTextSize(0.045);

  TH2F* hempty=new TH2F("hempty","",4,-0.1,2.,10.,0.,2.5);  
  hempty->GetXaxis()->SetTitle("|y_{CM}|");
  hempty->GetYaxis()->SetTitle("R_{FB}");
  hempty->GetXaxis()->SetTitleOffset(1.1);
  hempty->GetYaxis()->SetTitleOffset(1.3);
  hempty->GetXaxis()->SetTitleSize(0.045);
  hempty->GetYaxis()->SetTitleSize(0.045);
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.04);
  hempty->GetYaxis()->SetLabelSize(0.04);  
  hempty->GetXaxis()->CenterTitle();
  hempty->GetYaxis()->CenterTitle();
  hempty->SetMaximum(3);
  hempty->SetMinimum(0.);
  hempty->Draw();
  legendRFB->Draw();

  TGraphAsymmErrors *gRFBsyst = new TGraphAsymmErrors(nbinsRFB,xbinsRFB,yRFB,exlRFB,exlRFB,yRFBSystTotLow,yRFBSystTotHigh);
  gRFBsyst->SetTitle("gRFBsyst");
   gRFBsyst->SetName("gRFBsyst");
  gRFBsyst->SetMarkerColor(4);
  gRFBsyst->SetLineColor(4);
  gRFBsyst->SetLineWidth(2);   
  gRFBsyst->SetMarkerStyle(0);
  gRFBsyst->SetMarkerColor(1);


  


  TGraphAsymmErrors *gRFBstat = new TGraphAsymmErrors(nbinsRFB,xbinsRFB,yRFB,exlRFB,exlRFB,yRFBStat, yRFBStat);
  gRFBstat->SetTitle("gRFBstat");
  gRFBstat->SetName("gRFBstat");
  gRFBstat->SetMarkerColor(1);
  gRFBstat->SetLineColor(1);
  gRFBstat->SetLineWidth(2);   
  gRFBstat->SetMarkerStyle(21);
  gRFBstat->SetMarkerColor(1);
  gRFBstat->SetFillColor(0);
  gRFBstat->SetFillStyle(0);

  gRFBsyst->SetFillColor(0);
  gRFBsyst->SetFillStyle(0);
  
  gRFBsyst->Draw("2same");
  gRFBstat->Draw("psame");



  TLegendEntry *ent_RFB=legendRFB->AddEntry(gRFBstat,"R_{FB} stat.","pl");
  ent_RFB->SetTextFont(42);
  ent_RFB->SetLineColor(2);
  ent_RFB->SetMarkerColor(2);

  TLegendEntry *ent_RFB=legendRFB->AddEntry(gRFBsyst,"R_{FB} syst.","l");
  ent_RFB->SetTextFont(42);
  ent_RFB->SetLineColor(4);
  // ent_RFB->SetMarkerColor(2);

  TLatex * tlatex1=new TLatex(0.1612903,0.8625793,"CMS                 pPb #sqrt{s_{NN}}= 5.02 TeV");
  tlatex1->SetNDC();
  tlatex1->SetTextColor(1);
  tlatex1->SetTextFont(42);
  tlatex1->SetTextSize(0.045);
  tlatex1->Draw();

    
  TLatex * tlatexlumi=new TLatex(0.671371,0.7801268,"L = 34.8 nb^{-1}");
  tlatexlumi->SetNDC();
  tlatexlumi->SetTextColor(1);
  tlatexlumi->SetTextFont(42);
  tlatexlumi->SetTextSize(0.045);
  tlatexlumi->Draw();

  
  //double xpos1=0.6528226;
  // double ypos1=0.6849894;
  TLatex * tlatex3=new TLatex(xpos,ypos,mypar.Data());
   tlatex3->SetNDC();
  tlatex3->SetTextColor(1);
  tlatex3->SetTextFont(42);
  tlatex3->SetTextSize(0.06);
  tlatex3->Draw();
  canvasRFB->SaveAs(Form("../Results%s_y/CanvasRDFB.pdf",particle.Data(),particle.Data()));

  */


//  l->Draw();  
//  canvasRpA->SaveAs(Form("../Results%sY/canvasRpA%s.pdf",particle.Data(),particle.Data()));  
//  canvasRpA->SaveAs(Form("../Results%s_y/canvasRpA%s.pdf",particle.Data(),particle.Data()));  
  
//  TFile *fout=new TFile(Form("../Results%sY/fileRpA%s.root",particle.Data(),particle.Data()),"recreate");  
  TFile *fout=new TFile(Form("../Results%s_y/fileRpA%s.root",particle.Data(),particle.Data()),"recreate");  
  fout->cd();
  gSigmasyst->SetName("gSigmasyst");
  gSigmasyst->Write();
  gaeBplusReference->Write();
  hSigmapPbStat->Write();






}
