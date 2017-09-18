#include "uti.h"
#include "parameters.h"
#include "TLegendEntry.h"
#include "../Systematics/systematics.C"
#include "Draw_DRAA.h"

//bool drawDRAA = true;
bool drawDRAA = false;

int _nBins = nBinsY;
double *_ptBins = ptBinsY;

void NuclearModificationFactorY(TString inputPP="ROOTfiles/CrossSectionPP.root", TString inputPbPb="ROOTfiles/CrossSectionPbPb.root", TString inputEffPP = "ROOTfiles/MCstudiesPP_INC.root", TString inputEffPbPb = "ROOTfiles/MCstudiesPbPb_CENT.root", TString label="PbPb", TString outputfile="RAAfile.root", int doDataCor = 0, double PPlumi=1., double PbPblumi=1., Float_t centMin=0., Float_t centMax=100.)
{
  float pti = _ptBins[0];
  float pte = _ptBins[_nBins];

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);
  gStyle->SetPadRightMargin(0.03);//###0.020
  gStyle->SetPadLeftMargin(0.12);
  gStyle->SetPadTopMargin(0.075);
  gStyle->SetPadBottomMargin(0.12);

  TFile *fpp=new TFile(inputPP.Data());
  TFile *fPbPb=new TFile(inputPbPb.Data());
  TFile *fEffpp=new TFile(inputEffPP.Data());
  TFile *fEffPbPb=new TFile(inputEffPbPb.Data());

  TH1D*hSigmaPPStat=(TH1D*)fpp->Get("hPt");
  TH1D*hSigmaPbPbStat=(TH1D*)fPbPb->Get("hPt");
  TH1D*hEffPP=(TH1D*)fEffpp->Get("hEff");
  TH1D*hEffPbPb=(TH1D*)fEffPbPb->Get("hEff");

  if(doDataCor != 1) hSigmaPPStat->Divide(hEffPP);
  hSigmaPPStat->Scale(1./(2*PPlumi*BRchain));

  hSigmaPbPbStat->SetName("hSigmaPbPbStat");
  if(doDataCor != 1) hSigmaPbPbStat->Divide(hEffPbPb);
  hSigmaPbPbStat->Scale(1./(2*PbPblumi*BRchain));
  hSigmaPbPbStat->Divide(hSigmaPPStat);

  /*
  double mod_ptBins[_nBins+1];
  for(int i=0;i<_nBins+1;i++){
    mod_ptBins[i] = _ptBins[i]/2.;
  }  
  TH1D*hNuclearModification = new TH1D("hNuclearModification","",_nBins,mod_ptBins);
  for(int i=0;i<_nBins;i++){
    hNuclearModification->SetBinContent(i+1, hSigmaPbPbStat->GetBinContent(i+1));
    hNuclearModification->SetBinError(i+1, hSigmaPbPbStat->GetBinError(i+1));
  }

  double apt[_nBins];
  //bin half width
  double aptl[_nBins];
  //number of every rebined bin
  double bin_num[_nBins];

  for (int ibin=0; ibin<_nBins; ibin++){
    apt[ibin]=(mod_ptBins[ibin+1]+mod_ptBins[ibin])/2.;
    aptl[ibin] = (mod_ptBins[ibin+1]-mod_ptBins[ibin])/2;
    bin_num[ibin]=aptl[ibin]/binsize*2;
  }
  pti = pti/2.;
  pte = pte/2.;

  Double_t xr[_nBins], yr[_nBins], xrlow[_nBins], yrlow[_nBins],xrhigh[_nBins],yrhigh[_nBins];
  for(int i=0;i<_nBins;i++)
  {
    yr[i] = hNuclearModification->GetBinContent(i+1);
    double systematic=0.01*systematicsForRAAY(hNuclearModification->GetBinCenter(i+1),centMin,centMax,0.,0.);
    //double systematic=0.;
    yrlow[i] = hNuclearModification->GetBinContent(i+1)*systematic;
    yrhigh[i] =hNuclearModification->GetBinContent(i+1)*systematic;
  }
  */

  double apt[_nBins];
  //bin half width
  double aptl[_nBins];
  //number of every rebined bin
  double bin_num[_nBins];

  for (int ibin=0; ibin<_nBins; ibin++){
    apt[ibin]=(_ptBins[ibin+1]+_ptBins[ibin])/2.;
    aptl[ibin] = (_ptBins[ibin+1]-_ptBins[ibin])/2;
    bin_num[ibin]=aptl[ibin]/binsize*2;
  }

  pti = pti-1;
  pte = pte+1;

  Double_t xr[_nBins], yr[_nBins], xrlow[_nBins], yrlow[_nBins],xrhigh[_nBins],yrhigh[_nBins];
  Double_t yrStatlow[_nBins], yrStathigh[_nBins];
  for(int i=0;i<_nBins;i++)
  {
    yr[i] = hSigmaPbPbStat->GetBinContent(i+1);
    double systematic=0.01*systematicsForRAAY(hSigmaPbPbStat->GetBinCenter(i+1),centMin,centMax,0.,0.);
    //double systematic=0.;
    yrStatlow[i]  = hSigmaPbPbStat->GetBinError(i+1);
    yrStathigh[i] = hSigmaPbPbStat->GetBinError(i+1);
    yrlow[i] = hSigmaPbPbStat->GetBinContent(i+1)*systematic;
    yrhigh[i] = hSigmaPbPbStat->GetBinContent(i+1)*systematic;
  }

  TGraphAsymmErrors* hNuclearModification = new TGraphAsymmErrors(_nBins,apt,yr,aptl,aptl,yrStatlow,yrStathigh);
  hNuclearModification->SetName("hNuclearModification");

  TGraphAsymmErrors* gNuclearModification = new TGraphAsymmErrors(_nBins,apt,yr,aptl,aptl,yrlow,yrhigh);
  gNuclearModification->SetName("gNuclearModification");

  TCanvas*canvasRAA=new TCanvas("canvasRAA","canvasRAA",600,600);
  canvasRAA->cd();
  //canvasRAA->SetLogx();

  TH2F* hemptyEff=new TH2F("hemptyEff","",50,pti,pte,10.,0,1.55);  
  hemptyEff->GetXaxis()->CenterTitle();
  hemptyEff->GetYaxis()->CenterTitle();
  hemptyEff->GetYaxis()->SetTitle("B^{+} R_{AA}");
  hemptyEff->GetXaxis()->SetTitle("y");
  hemptyEff->GetXaxis()->SetTitleOffset(1.0);
  hemptyEff->GetYaxis()->SetTitleOffset(1.1);
  hemptyEff->GetXaxis()->SetTitleSize(0.05);
  hemptyEff->GetYaxis()->SetTitleSize(0.05);
  hemptyEff->GetXaxis()->SetTitleFont(42);
  hemptyEff->GetYaxis()->SetTitleFont(42);
  hemptyEff->GetXaxis()->SetLabelFont(42);
  hemptyEff->GetYaxis()->SetLabelFont(42);
  hemptyEff->GetXaxis()->SetLabelSize(0.04);
  hemptyEff->GetYaxis()->SetLabelSize(0.04);  
  hemptyEff->SetMaximum(2);
  hemptyEff->SetMinimum(0.);
  hemptyEff->Draw();

  TLine *line = new TLine(pti,1,pte,1);
  line->SetLineStyle(2);
  line->SetLineWidth(2);
  line->Draw();

  //gNuclearModification->SetFillColor(5);//1
  gNuclearModification->SetFillColor(kOrange);//1
  gNuclearModification->SetFillStyle(3001);//0
  gNuclearModification->SetLineWidth(1);//3
  gNuclearModification->SetMarkerSize(1);
  gNuclearModification->SetMarkerStyle(21);
  //gNuclearModification->SetLineColor(1);//kGreen+4
  //gNuclearModification->SetMarkerColor(1);//kGreen+4
  gNuclearModification->SetLineColor(kOrange);//kGreen+4
  //gNuclearModification->SetMarkerColor(kOrange);//kGreen+4
  gNuclearModification->SetMarkerColor(kRed);//kGreen+4
  gNuclearModification->Draw("5same");

  hNuclearModification->SetLineWidth(3);
  hNuclearModification->SetLineColor(kRed);
  hNuclearModification->SetMarkerColor(kRed);
  hNuclearModification->SetMarkerStyle(21);
  //hNuclearModification->Draw("same");
  hNuclearModification->Draw("same p");

  Float_t systnorm = normalizationUncertaintyForRAA()*1.e-2;
  TBox* bSystnorm = new TBox(pti,1-systnorm,pti+0.25,1+systnorm);
  if(drawDRAA) bSystnorm = new TBox(pti,1-systnorm,pti+0.25,1+systnorm);
  bSystnorm->SetLineColor(16);
  bSystnorm->SetFillColor(16);
  bSystnorm->Draw();

  TLatex * tlatexeff2=new TLatex(0.41,0.58,Form("p_{T} %.0f-%.0f (GeV/c)",ptBinsInc[0], ptBinsInc[1]));
  tlatexeff2->SetNDC();
  tlatexeff2->SetTextColor(1);
  tlatexeff2->SetTextFont(42);
  tlatexeff2->SetTextSize(0.050);
  tlatexeff2->Draw();
  TLatex * texY = new TLatex(0.41,0.53,"|y| < 2.4");//0.2612903,0.8425793
  texY->SetNDC();
  texY->SetTextColor(1);
  texY->SetTextFont(42);
  texY->SetTextSize(0.045);
  texY->SetLineWidth(2);
  //texY->Draw();

  TLatex* texlumi = new TLatex(0.13,0.936,"27.4 pb^{-1} (5.02 TeV pp) + 350.68 #mub^{-1} (5.02 TeV PbPb)");
  texlumi->SetNDC();
  //texlumi->SetTextAlign(31);
  texlumi->SetTextFont(42);
  texlumi->SetTextSize(0.038);
  texlumi->SetLineWidth(2);
  texlumi->Draw();
  TLatex* texcms = new TLatex(0.15,0.90,"CMS");
  texcms->SetNDC();
  texcms->SetTextAlign(13);
  texcms->SetTextFont(62);//61
  texcms->SetTextSize(0.06);
  texcms->SetLineWidth(2);
  texcms->Draw();
  TLatex* texpre = new TLatex(0.15,0.84,"Preliminary");
  texpre->SetNDC();
  texpre->SetTextAlign(13);
  texpre->SetTextFont(52);
  texpre->SetTextSize(0.05);
  texpre->SetLineWidth(2);
  texpre->Draw();

  //TLegend *legendSigma=new TLegend(0.40,0.5168644,0.8084677,0.6605932,"");
  TLegend *legendSigma=new TLegend(0.4036242,0.7474695,0.942953,0.8457592,"");
  if(drawDRAA)legendSigma=new TLegend(0.4036242,0.6774695,0.942953,0.8757592,"");
  legendSigma->SetBorderSize(0);
  legendSigma->SetLineColor(0);
  legendSigma->SetFillColor(0);
  legendSigma->SetFillStyle(1001);
  legendSigma->SetTextFont(42);
  legendSigma->SetTextSize(0.045);

//  TLegendEntry *ent_SigmaPP=legendSigma->AddEntry(hNuclearModification,"R_{AA} stat. unc.","pf");
//  ent_SigmaPP->SetTextFont(42);
//  ent_SigmaPP->SetLineColor(1);
//  ent_SigmaPP->SetMarkerColor(1);
//  ent_SigmaPP->SetTextSize(0.045);
//
//  TLegendEntry *ent_Sigmapp=legendSigma->AddEntry(gNuclearModification,"R_{AA} syst.","f");
//  ent_Sigmapp->SetTextFont(42);
//  ent_Sigmapp->SetLineColor(5);
//  ent_Sigmapp->SetMarkerColor(1);
//  ent_Sigmapp->SetTextSize(0.045);

  TLegendEntry *ent_B = legendSigma->AddEntry(gNuclearModification,"R_{AA} B^{+} Centrality 0-100%","pf");
  ent_B->SetTextFont(42);
  ent_B->SetLineColor(4);
  ent_B->SetMarkerColor(4);
  ent_B->SetTextSize(0.043);//0.03

  TLatex* texSystnorm = new TLatex(0.23,0.70,"T_{AA} and lumi.");
  if(drawDRAA) texSystnorm = new TLatex(0.17,0.70,"T_{AA} and lumi.");
  texSystnorm->SetNDC();
  texSystnorm->SetTextColor(1);
  texSystnorm->SetTextFont(42);
  texSystnorm->SetTextSize(0.04);
  texSystnorm->SetLineWidth(2);
  texSystnorm->Draw();
  texSystnorm = new TLatex(0.23,0.65,"uncertainty");
  if(drawDRAA) texSystnorm = new TLatex(0.17,0.65,"uncertainty");
  texSystnorm->SetNDC();
  texSystnorm->SetTextColor(1);
  texSystnorm->SetTextFont(42);
  texSystnorm->SetTextSize(0.04);
  texSystnorm->SetLineWidth(2);
  texSystnorm->Draw();

  if(drawDRAA){
    TGraphAsymmErrors* gDNuclearModification = new TGraphAsymmErrors();
    Draw_DRAA(canvasRAA, gDNuclearModification);
    gDNuclearModification->SetFillColor(kYellow-9);
    TLegendEntry *ent_Dhighpt = legendSigma->AddEntry(gDNuclearModification,"R_{AA} D^{0} |y| < 1.0","pf");
    ent_Dhighpt->SetTextFont(42);
    ent_Dhighpt->SetLineColor(4);
    ent_Dhighpt->SetMarkerColor(4);
    ent_Dhighpt->SetTextSize(0.043);//0.03
  }

  legendSigma->Draw();

  canvasRAA->Update();
  canvasRAA->RedrawAxis();

  TString _postfix = "";
  if(doDataCor==1) _postfix = "_EFFCOR";
  if(!drawDRAA){
    canvasRAA->SaveAs(Form("plotRAA/canvasRAA%s_%.0f_%.0f_Y%s.pdf",label.Data(),centMin,centMax,_postfix.Data()));
    canvasRAA->SaveAs(Form("plotRAA/canvasRAA%s_%.0f_%.0f_Y%s.png",label.Data(),centMin,centMax,_postfix.Data()));
  }
  if(drawDRAA){
    canvasRAA->SaveAs(Form("plotRAA/canvasRAA_DRAA_%s_%.0f_%.0f_Y%s.pdf",label.Data(),centMin,centMax,_postfix.Data()));
    canvasRAA->SaveAs(Form("plotRAA/canvasRAA_DRAA_%s_%.0f_%.0f_Y%s.png",label.Data(),centMin,centMax,_postfix.Data()));
  }
  TFile *fRAA=new TFile(outputfile.Data(),"recreate");
  fRAA->cd();
  gNuclearModification->Write();
  hNuclearModification->Write();
}


int main(int argc, char *argv[])
{
  if(argc==12)
    {
      //NuclearModificationFactorY(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], atof(argv[7]), atof(argv[8]), atof(argv[9]), atof(argv[10]));
      NuclearModificationFactorY(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], atoi(argv[7]), atof(argv[8]), atof(argv[9]), atof(argv[10]), atof(argv[11]));
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}


