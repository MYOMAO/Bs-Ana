#include <TF1.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TFile.h>
#include "parameters.h"
#include "iostream"
using namespace std;

void printMCstatErr(){
TFile* ppMCEfffile = new TFile("ROOTfiles/MCstudiesPP.root");
TH1D* ppEff = (TH1D*)ppMCEfffile->Get("hEff");
TFile* PbPbMCEfffile = new TFile("ROOTfiles/MCstudiesPbPb.root");
TH1D* PbPbEff = (TH1D*)PbPbMCEfffile->Get("hEff");
printf("MC stat.");
for(int i=0;i<nBins;i++){
	printf(" & %.3f", ppEff->GetBinError(ppEff->FindBin(ptBins[i]))/ppEff->GetBinContent(ppEff->FindBin(ptBins[i]))*100);
}
printf(" \\\\ \n");
printf("MC stat.");
for(int i=0;i<nBins;i++){
	printf(" & %.3f", PbPbEff->GetBinError(PbPbEff->FindBin(ptBins[i]))/PbPbEff->GetBinContent(PbPbEff->FindBin(ptBins[i]))*100);
}
printf(" \\\\ \n");
}
