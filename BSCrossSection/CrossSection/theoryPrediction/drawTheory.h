#include <iostream>
#include <fstream>
#include "TGraph.h"
const int n = 1000;
Float_t aCx[n],aCy[n],aCyl[n],aCyh[n];
Int_t nbin=0;
Float_t temp;
using namespace std;
void plotTheory()
{

  TGraph* gMagdalenaB5TeV = new TGraph("theoryPrediction/theorypre/Magdalena.dat");
  gMagdalenaB5TeV->SetName("gMagdalenaB5TeV");
  gMagdalenaB5TeV->SetLineColor(kGreen+4);
  gMagdalenaB5TeV->SetLineWidth(3);
  //gMagdalenaB5TeV->SetFillColor(kGreen+4);
  //gMagdalenaB5TeV->SetFillStyle(3004);
  //gMagdalenaB5TeV->Draw("f same");
  gMagdalenaB5TeV->Draw("c same");

  //

  ifstream getdata("theoryPrediction/theorypre/TAMUminbiasB.txt");
  if(!getdata.is_open()) cout<<"Opening the file fails: TAMU"<<endl;
  nbin=0;
  while(!getdata.eof())
    {
      getdata>>aCx[nbin]>>aCyh[nbin]>>aCyl[nbin];
      nbin++;
    }
  Float_t* aTAMUB5TeVx = new Float_t[nbin];
  Float_t* aTAMUB5TeVxe = new Float_t[nbin];
  Float_t* aTAMUB5TeVy = new Float_t[nbin];
  Float_t* aTAMUB5TeVye = new Float_t[nbin];
  for(int i=0;i<nbin;i++)
    {
      aTAMUB5TeVx[i] = aCx[i];
      aTAMUB5TeVxe[i] = 0;
      aTAMUB5TeVy[i] = (aCyh[i]+aCyl[i])/2.;
      aTAMUB5TeVye[i] = abs(aCyh[i]-aCyl[i])/2.;
    }
  TGraphErrors* gTAMUB5TeV = new TGraphErrors(nbin, aTAMUB5TeVx, aTAMUB5TeVy, aTAMUB5TeVxe, aTAMUB5TeVye);
  gTAMUB5TeV->SetName("gTAMUB5TeV");
  //gTAMUB5TeV->SetLineColor(kViolet-6);
  //gTAMUB5TeV->SetFillColor(kViolet-6);
  gTAMUB5TeV->SetLineColor(kOrange+8);
  gTAMUB5TeV->SetFillColor(kOrange+8);
  gTAMUB5TeV->SetFillStyle(1001);
  gTAMUB5TeV->Draw("4 same");

  //

  ifstream getcujet("theoryPrediction/theorypre/CUJET3_RAA-pT_0-20.dat");
  if(!getcujet.is_open()) cout<<"Opening the file fails: CUJET"<<endl;
  nbin=0;
  while(!getcujet.eof())
    {
      getcujet>>aCx[nbin]>>temp>>temp>>aCy[nbin]>>temp>>temp>>temp;
      nbin++;
    }
  TGraph* gCUJETB5TeV = new TGraph(nbin,aCx,aCy);
  gCUJETB5TeV->SetLineColor(4);
  gCUJETB5TeV->SetMarkerColor(4);
  gCUJETB5TeV->SetLineWidth(3);
  gCUJETB5TeV->SetMarkerSize(0.15);
  gCUJETB5TeV->Draw("c same");

}
