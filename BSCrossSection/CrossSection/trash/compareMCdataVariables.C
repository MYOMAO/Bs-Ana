using namespace std;
#include "uti.h"
#include "parameters.h"

int compareMCdataVariables(TString promptfile, TString datafile,
                           TString variableplot, TString variablename,
                           Int_t usePbPb)
{
  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);

  if(!(usePbPb==1||usePbPb==0))
    {
      cout<<" ERROR: invalide usePbPb"<<endl;
      return 1;
    }
  Bool_t isPbPb = (Bool_t)(usePbPb);
  TString collisionsystem = (isPbPb)?"PbPb":"pp";

  TFile* infMCprompt = new TFile(Form("%s_%s_%s.root",promptfile.Data(),collisionsystem.Data(),variablename.Data()));
  TH1F* hPtprompt = (TH1F*)infMCprompt->Get("hPt");
  TFile* infData = new TFile(Form("%s_%s_%s.root",datafile.Data(),collisionsystem.Data(),variablename.Data()));
  TH1F* hPtData= (TH1F*)infData->Get("hPt");

  hPtprompt->Scale(1./hPtprompt->Integral(1,nBins));
  hPtData->Scale(1./hPtData->Integral(1,nBins));

  TH2F* hempty = new TH2F("hempty","",100,limitlow,limithigh,10,limitmin,limitmax);
  hempty->GetXaxis()->CenterTitle();
  hempty->GetYaxis()->CenterTitle();
  hempty->GetYaxis()->SetTitle("Probability");
  hempty->GetXaxis()->SetTitle(variableplot.Data());
  hempty->GetXaxis()->SetTitleOffset(0.9);
  hempty->GetYaxis()->SetTitleOffset(1.3);
  hempty->GetXaxis()->SetTitleSize(0.045);
  hempty->GetYaxis()->SetTitleSize(0.045);
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.035);
  hempty->GetYaxis()->SetLabelSize(0.035);  

  hPtprompt->SetMarkerStyle(20);
  hPtprompt->SetMarkerColor(kRed);
  hPtprompt->SetMarkerSize(1.1);
  hPtprompt->SetLineColor(kRed);
  hPtprompt->SetLineWidth(1);
  hPtData->SetMarkerStyle(20);
  hPtData->SetMarkerColor(kBlue+1);
  hPtData->SetMarkerSize(1.1);
  hPtData->SetLineColor(kBlue+1);
  hPtData->SetLineWidth(1);

  TCanvas* canvas = new TCanvas("canvas","",600,600);
  canvas->cd(1);
  gPad->SetLogy();
  hempty->Draw();
  hPtData->Draw("same");
  hPtprompt->Draw("same");

  TLegend* legPtY = new TLegend(0.08,0.75,0.60,0.86);
  legPtY->SetTextSize(0.045);
  legPtY->SetBorderSize(0);
  legPtY->SetFillStyle(0);
  legPtY->AddEntry((TObject*)0,"|y| < 2.4",NULL);
  legPtY->AddEntry((TObject*)0,"7 < p_{T} < 50 GeV/c",NULL);
  legPtY->Draw("same");

  TLegend* leg = new TLegend(0.62,0.75,0.95,0.86);
  leg->SetTextSize(0.045);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->AddEntry(hPtprompt,"Monte-Carlo","pl");
  leg->AddEntry(hPtData,"Data","pl");
  leg->Draw("same");

  TLatex* texCms = new TLatex(0.18,0.93, "#scale[1.25]{CMS} Preliminary");
  texCms->SetNDC();
  texCms->SetTextAlign(12);
  texCms->SetTextSize(0.04);
  texCms->SetTextFont(42);
  texCms->Draw();

  TLatex* texCol = new TLatex(0.96,0.93, Form("%s #sqrt{s_{NN}} = 5.02 TeV",collisionsystem.Data()));
  texCol->SetNDC();
  texCol->SetTextAlign(32);
  texCol->SetTextSize(0.04);
  texCol->SetTextFont(42);
  texCol->Draw();

  canvas->SaveAs(Form("plotVariablesResults/Comparison_%s_%s.pdf",collisionsystem.Data(),variablename.Data()));
  return 0;
}


int main(int argc, char *argv[])
{
  if(argc==6)
    {
      compareMCdataVariables(argv[1], argv[2], argv[3], argv[4], atoi(argv[5]));
      return 0;
    }
  else
    {
      cout<<"  ERROR: Wrong number of inputs"<<endl;
      return 1;
    }
}
