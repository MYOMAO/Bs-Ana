#include "TROOT.h"
#include "TTree.h"
#include "TH1.h"
#include "TF1.h"
#include "iostream"
#include "iomanip"
#include "utility"
#include "TFile.h"
#include "TDirectoryFile.h"
#include "TDirectory.h"
#include "TNtuple.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"
#include "TBox.h"
#include "TCut.h"
#include "TMath.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "TStyle.h"
#include "TProfile.h"

void comparison()
{
  TFile* data_pp = new TFile("/afs/cern.ch/user/a/aturner/B_Meson/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/ROOTfiles/data_pp.root");
  TFile* mc_pp = new TFile("/afs/cern.ch/user/a/aturner/B_Meson/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/ROOTfiles/mc_pp.root");
  TFile* data_PP = new TFile("/afs/cern.ch/user/a/aturner/B_Meson/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/ROOTfiles/data_PbPb.root");
  TFile* mc_PP = new TFile("/afs/cern.ch/user/a/aturner/B_Meson/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/ROOTfiles/mc_PbPb.root");

  TH1F* h_data_pp = (TH1F*)data_pp->Get("hMean");
  TH1F* h_mc_pp = (TH1F*)mc_pp->Get("hMean");
  TH1F* h_data_PP = (TH1F*)data_PP->Get("hMean");
  TH1F* h_mc_PP = (TH1F*)mc_PP->Get("hMean");

  h_data_pp->SetMarkerStyle(25);
  h_mc_pp->SetMarkerStyle(8);
  h_data_PP->SetMarkerStyle(25);
  h_mc_PP->SetMarkerStyle(8);

  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);

  TF1* bmass = new TF1("bmass","[0]",10,50);
  bmass->SetTitle(";B^{+} p_{T} (GeV/c);m_{#piK} (GeV/c^{2})");
  bmass->SetMinimum(5.27);
  bmass->SetMaximum(5.29);
  bmass->SetParameter(0,5.279);
  bmass->SetLineWidth(1);
  bmass->SetLineColor(kRed);
  bmass->SetLineStyle(2);
  bmass->GetXaxis()->SetTitleOffset(1.3);
  bmass->GetYaxis()->SetTitleOffset(1.8);
  bmass->GetXaxis()->SetLabelOffset(0.007);
  bmass->GetYaxis()->SetLabelOffset(0.007);
  bmass->GetXaxis()->SetTitleSize(0.045);
  bmass->GetYaxis()->SetTitleSize(0.045);
  bmass->GetXaxis()->SetTitleFont(42);
  bmass->GetYaxis()->SetTitleFont(42);
  bmass->GetXaxis()->SetLabelFont(42);
  bmass->GetYaxis()->SetLabelFont(42);
  bmass->GetXaxis()->SetLabelSize(0.04);
  bmass->GetYaxis()->SetLabelSize(0.04);
  
  TLegend* leg_pp = new TLegend(0.2,0.74,0.33,0.9,NULL,"brNDC");
  leg_pp->SetBorderSize(0);
  leg_pp->SetTextSize(0.04);
  leg_pp->SetTextFont(42);
  leg_pp->SetFillStyle(0);
  leg_pp->AddEntry(h_data_pp, "pp Data", "pl");
  leg_pp->AddEntry(h_mc_pp,"Monte Carlo","pl");
  leg_pp->AddEntry(bmass,"B^{+} Mass","l");

  TLegend* leg_PP = new TLegend(0.2,0.74,0.33,0.9,NULL,"brNDC");
  leg_PP->SetBorderSize(0);
  leg_PP->SetTextSize(0.04);
  leg_PP->SetTextFont(42);
  leg_PP->SetFillStyle(0);
  leg_PP->AddEntry(h_data_PP, "PbPb Data", "pl");
  leg_PP->AddEntry(h_mc_PP,"Monte Carlo","pl");
  leg_PP->AddEntry(bmass,"B^{+} Mass","l");

  TLatex* Title_pp = new TLatex(0.18,0.97, "Mean of fitted gaussians in pp collision");
  Title_pp->SetNDC();
  Title_pp->SetTextAlign(12);
  Title_pp->SetTextSize(0.04);
  Title_pp->SetTextFont(42);

  TLatex* Title_PP = new TLatex(0.18,0.97, "Mean of fitted gaussians in PbPb collision");
  Title_PP->SetNDC();
  Title_PP->SetTextAlign(12);
  Title_PP->SetTextSize(0.04);
  Title_PP->SetTextFont(42);
  
  h_data_pp->Sumw2();
  h_mc_pp->Sumw2();
  h_data_PP->Sumw2();
  h_mc_PP->Sumw2();

  TCanvas* cpp = new TCanvas("cpp","",600,600);
  bmass->Draw();
  h_data_pp->Draw("Same");
  h_mc_pp->Draw("Same");
  leg_pp->Draw("Same");
  Title_pp->Draw("Same");
  cpp->SaveAs("plotFits/mean_pp.pdf");  

  TCanvas* cPP = new TCanvas("cPP","",600,600);
  bmass->Draw();
  h_data_PP->Draw("Same");
  h_mc_PP->Draw("Same");
  leg_PP->Draw("Same");
  Title_PP->Draw("Same");
  cPP->SaveAs("plotFits/mean_PbPb.pdf");  
} 

int main()
{
    comparison();
    return 0;
}
 




