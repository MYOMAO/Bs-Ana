#include "uti.h"
#include "parameters.h"
#include "TLegendEntry.h"
#include "../Systematics/systematics.C"
#include "ChargedHad/RAA_0_10.C"
#include "ChargedHad/RAA_0_100.C"
#include "theoryPrediction/drawTheory.h"
#include "Draw_DRAA.h"

bool drawDRAA = false;
bool drawChHad = false;
bool drawThm = false;

void NuclearModificationFactor(TString inputPP="ROOTfiles/CrossSectionPP.root",
    TString inputPbPb="ROOTfiles/CrossSectionPbPb.root",TString label="PbPb",
    TString outputfile="RAAfile.root", Float_t centMin=0.,
    Float_t centMax=100.) {

  float pti = ptBins[0]-2.;
  float pte = ptBins[nBins]+5.;
  if(drawDRAA) {
    pti = 1;
    pte = 400.;
  }
  if(drawThm) {
    pti = 5;
    pte = 110.;
  }

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

  TH1D*hSigmaPPStat=(TH1D*)fpp->Get("hPtSigma");
  hSigmaPPStat->SetName("hSigmaPPStat");
  TH1D*hNuclearModification=(TH1D*)fPbPb->Get("hPtSigma");
  hNuclearModification->SetName("hNuclearModification");
  hNuclearModification->Divide(hSigmaPPStat);

  double apt[nBins];
  
  //bin half width
  double aptl[nBins];
  
  //number of every rebined bin
  double bin_num[nBins];

  for (int ibin=0; ibin<nBins; ibin++){
    apt[ibin]=(ptBins[ibin+1]+ptBins[ibin])/2.;
    aptl[ibin] = (ptBins[ibin+1]-ptBins[ibin])/2;
    bin_num[ibin]=aptl[ibin]/binsize*2;
  }

  Double_t xr[nBins], yr[nBins], xrlow[nBins], yrlow[nBins],xrhigh[nBins],yrhigh[nBins];
  for(int i=0;i<nBins;i++) {
    yr[i] = hNuclearModification->GetBinContent(i+1);
    double systematic=0.01*systematicsForRAA(
        hNuclearModification->GetBinCenter(i+1),centMin,centMax,0.,0.);
    yrlow[i] = hNuclearModification->GetBinContent(i+1)*systematic;
    yrhigh[i] =hNuclearModification->GetBinContent(i+1)*systematic;
  }

  TGraphAsymmErrors* gNuclearModification =
    new TGraphAsymmErrors(nBins,apt,yr,aptl,aptl,yrlow,yrhigh);
  gNuclearModification->SetName("gNuclearModification");

  TCanvas*canvasRAA=new TCanvas("canvasRAA","canvasRAA",600,600);
  canvasRAA->cd();
  canvasRAA->SetLogx();

  TH2F* hemptyEff=new TH2F("hemptyEff","",50,pti,pte,10.,0,1.55);  
  hemptyEff->GetXaxis()->CenterTitle();
  hemptyEff->GetYaxis()->CenterTitle();
  hemptyEff->GetYaxis()->SetTitle("R_{AA}");
  hemptyEff->GetXaxis()->SetTitle("p_{T} (GeV/c)");
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

  gNuclearModification->SetFillColor(kAzure+7);//1
  gNuclearModification->SetFillStyle(3001);//0
  gNuclearModification->SetLineWidth(1);//3
  gNuclearModification->SetMarkerSize(1);
  gNuclearModification->SetMarkerStyle(21);
  gNuclearModification->SetLineColor(kAzure+7);//kGreen+4
  gNuclearModification->SetMarkerColor(kViolet+3);//kGreen+4

  hNuclearModification->SetLineWidth(3);
  hNuclearModification->SetLineColor(kViolet+3);
  hNuclearModification->SetMarkerColor(kViolet+3);
  hNuclearModification->SetMarkerStyle(21);

  Float_t systnorm = normalizationUncertaintyForRAA()*1.e-2;
  TBox* bSystnorm = new TBox(pti,1-systnorm,pti+0.35,1+systnorm);

  cout<<systnorm<<endl;
  
  if(drawDRAA) bSystnorm = new TBox(pti,1-systnorm,pti+0.2,1+systnorm);
  bSystnorm->SetLineColor(16);
  bSystnorm->SetFillColor(16);
  bSystnorm->Draw();

  TLatex * tlatexeff2=new TLatex(0.38,0.595,"Centrality 0-100%");
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

  TLatex* texlumi = new TLatex(0.13,0.936,
      "27.4 pb^{-1} (5.02 TeV pp) + 350.68 #mub^{-1} (5.02 TeV PbPb)");
  texlumi->SetNDC();
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

  TLegend *legendSigma=new TLegend(0.6036242,0.7474695,0.942953,0.8457592,"");
  if(drawDRAA)legendSigma=
    new TLegend(0.4236242,0.6774695,0.812953,0.8757592,"");
  if(drawThm)legendSigma=new TLegend(0.5636242,0.6774695,0.922953,0.8757592,"");
  legendSigma->SetBorderSize(0);
  legendSigma->SetLineColor(0);
  legendSigma->SetFillColor(0);
  legendSigma->SetFillStyle(1001);
  legendSigma->SetTextFont(42);
  legendSigma->SetTextSize(0.04);

  TLegendEntry *ent_B =
    legendSigma->AddEntry(gNuclearModification,"B^{+} |y| < 2.4","pf");
  ent_B->SetTextFont(42);
  ent_B->SetLineColor(4);
  ent_B->SetMarkerColor(4);
  ent_B->SetTextSize(0.038);//0.03

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

  if(drawChHad){
    RAA_0_100();
  }

  if(drawDRAA){
    TGraphAsymmErrors* gDNuclearModification = new TGraphAsymmErrors();
    Draw_DRAA(canvasRAA, gDNuclearModification);
    gDNuclearModification->SetFillColor(kYellow-9);
    TLegendEntry *ent_Dhighpt =
      legendSigma->AddEntry(gDNuclearModification,"D^{0} |y| < 1.0","pf");
    ent_Dhighpt->SetTextFont(42);
    ent_Dhighpt->SetMarkerColor(4);
    ent_Dhighpt->SetTextSize(0.038);//0.03
  }

  if(drawChHad){
    TGraphAsymmErrors* gChHadDummy = new TGraphAsymmErrors();
    gChHadDummy->SetFillColor(TColor::GetColor("#ffcc00"));
    gChHadDummy->SetMarkerColor(kRed);
    TLegendEntry *ent_ChHad =
      legendSigma->AddEntry(gChHadDummy,"charged hadrons |y| < 1.0","pf");
    ent_ChHad->SetTextFont(42);
    ent_ChHad->SetLineColor(4);
    ent_ChHad->SetMarkerColor(4);
    ent_ChHad->SetTextSize(0.038);//0.03
  }
  if(drawThm){
    plotTheory();
    TGraphAsymmErrors* gThmDummy1 = new TGraphAsymmErrors();
    TGraphAsymmErrors* gThmDummy2 = new TGraphAsymmErrors();
    TGraphAsymmErrors* gThmDummy3 = new TGraphAsymmErrors();
    gThmDummy1->SetLineColor(kGreen+4);
    gThmDummy2->SetLineColor(kOrange+8);
    gThmDummy3->SetLineColor(4);
    gThmDummy1->SetLineWidth(4.5);
    gThmDummy2->SetLineWidth(4.5);
    gThmDummy3->SetLineWidth(4.5);
    TLegendEntry *ent_thm1 =
      legendSigma->AddEntry(gThmDummy1,"M. Djordjevic et al.","l");
    TLegendEntry *ent_thm2 =
      legendSigma->AddEntry(gThmDummy2,"M. He et al.","l");
    TLegendEntry *ent_thm3 =
      legendSigma->AddEntry(gThmDummy3,"CUJET3.0 0-20%","l");
    ent_thm1->SetTextSize(0.038);//0.03
    ent_thm2->SetTextSize(0.038);//0.03
    ent_thm3->SetTextSize(0.038);//0.03
  }

  gNuclearModification->Draw("5same");
  hNuclearModification->Draw("same");

  legendSigma->Draw();

  canvasRAA->Update();
  canvasRAA->RedrawAxis();

  TString AddOn = "";
  if(drawDRAA){
    AddOn = AddOn += "_DRAA";
  }
  if(drawChHad){
    AddOn = AddOn += "_ChHadRAA";
  }
  if(drawThm){
    AddOn = AddOn += "_ThmRAA";
  }

  canvasRAA->SaveAs(Form("plotRAA/canvasRAA%s_%.0f_%.0f%s.pdf",label.Data(),
        centMin,centMax,AddOn.Data()));
  canvasRAA->SaveAs(Form("plotRAA/canvasRAA%s_%.0f_%.0f%s.png",label.Data(),
        centMin,centMax,AddOn.Data()));
  canvasRAA->SaveAs(Form("plotRAA/canvasRAA%s_%.0f_%.0f%s.C",label.Data(),
        centMin,centMax,AddOn.Data()));
  TFile *fRAA=new TFile(outputfile.Data(),"recreate");
  fRAA->cd();
  gNuclearModification->Write();
  hNuclearModification->Write();
}


int main(int argc, char *argv[]) {
  if(argc==7) {
    NuclearModificationFactor(
        argv[1], argv[2], argv[3], argv[4], atof(argv[5]), atof(argv[6]));
    return 0;
  }
  else {
    std::cout << "Wrong number of inputs" << std::endl;
    return 1;
  }
}
