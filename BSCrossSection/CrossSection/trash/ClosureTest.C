#include "uti.h"
#include "TLegendEntry.h"
#include "parameters.h"


void ClosureTest(TString inputfile="ROOTfiles/hPtSpectrumDzeroPbPbMBMCClosure.root",TString label="PbPbMBClosure"){


  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);

  TFile *f=new TFile(inputfile.Data());

  TH1D *hPtCor=(TH1D*)f->Get("hPtCor");
  TH1D *hPtGen=(TH1D*)f->Get("hPtGen");

  hPtCor->Divide(hPtGen);
  TCanvas*canvas=new TCanvas("canvas","canvas",550,500);
  canvas->cd();
  TH2F* hemptyClosure=new TH2F("hemptyClosure","",50,ptBins[0]-2,ptBins[nBins]+2,10,0.0,1.5);  
  hemptyClosure->GetXaxis()->CenterTitle();
  hemptyClosure->GetYaxis()->CenterTitle();
  hemptyClosure->GetYaxis()->SetTitle("Corrected Yield/Generated Yield");
  hemptyClosure->GetXaxis()->SetTitle("p_{T}");
  hemptyClosure->GetXaxis()->SetTitleOffset(.9);
  hemptyClosure->GetYaxis()->SetTitleOffset(1.);
  hemptyClosure->GetXaxis()->SetTitleSize(0.05);
  hemptyClosure->GetYaxis()->SetTitleSize(0.05);
  hemptyClosure->GetXaxis()->SetTitleFont(42);
  hemptyClosure->GetYaxis()->SetTitleFont(42);
  hemptyClosure->GetXaxis()->SetLabelFont(42);
  hemptyClosure->GetYaxis()->SetLabelFont(42);
  hemptyClosure->GetXaxis()->SetLabelSize(0.035);
  hemptyClosure->GetYaxis()->SetLabelSize(0.035);  
  hemptyClosure->Draw();
  hPtCor->SetLineWidth(2);
  hPtCor->SetLineColor(1);
  hPtCor->Draw("same");
  canvas->SaveAs(Form("canvasClosure%s.pdf",label.Data()));
}

int main(int argc, char *argv[])
{
  if((argc !=3))
  {
    std::cout << "Wrong number of inputs" << std::endl;
    return 1;
  }
  
  if(argc == 3)
    ClosureTest(argv[1],argv[2]);
  return 0;
}
