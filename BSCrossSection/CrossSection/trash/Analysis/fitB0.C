#include "utilities.h"

Double_t setparam0=100.;
Double_t setparam1=5.28;
Double_t setparam2=0.03;
Double_t fixparam1=5.279;
Double_t setparam3=0.03;
Double_t fixparam2=0.04;

TString inputdata = "/data/wangj/Data2015/Bntuple/ntB_DoubleMu_pp_20151130_bPt0jpsiPt0tkPt0p5.root"; Bool_t isMC = false; TString tMC = "Data";
//TString inputdata = "/data/wangj/MC2015/Bntuple/ntB_Pythia8_BdToJpsiKstar_TuneCUEP8M1_5020GeV_BPHMod_filter_GEN_SIM_PU_20151105.root"; Bool_t isMC = true; TString tMC = "MC";
TString inputmc = "/data/wangj/MC2015/Bntuple/ntB_Pythia8_BdToJpsiKstar_TuneCUEP8M1_5020GeV_BPHMod_filter_GEN_SIM_PU_20151105.root";
const Int_t nBins = 1; Double_t ptBins[nBins+1] = {5,100};
//const Int_t nBins = 4; Double_t ptBins[nBins+1] = {5,7,10,20,50};

TString weight = "1";
Double_t luminosity=5400*1e-3;
TString cut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&Btrk1Pt>0.7&&Btrk2Pt>0.7&&Bchi2cl>9.94e-02&&(Bd0/Bd0Err)>6.08&&cos(Bdtheta)>7.93e-01&&abs(Btktkmass-0.89594)<0.10&&BtktkmassKK>1.04&&Bmu1pt>1.5&&Bmu2pt>1.5&&Blxy>0.02";
TString seldata=Form("%s",cut.Data());
TString selmc=Form("%s",cut.Data());
TString selmcgen="TMath::Abs(Gy)<2.4&&TMath::Abs(GpdgId)==511&&GisSignal>0";

void fitB0(TString infname="", Bool_t doweight=false)
{
  void clean0(TH1D *h);
  TF1* fit(TTree *nt, TTree *ntMC, Double_t ptmin, Double_t ptmax);

  if (!doweight) weight="1";
  TFile* inf = new TFile(inputdata.Data());
  TTree* nt = (TTree*) inf->Get("ntKstar");
  TFile* infMC = new TFile(inputmc.Data());
  TTree* ntMC = (TTree*)infMC->Get("ntKstar");
  TTree* ntGen = (TTree*)infMC->Get("ntGen");

  TH1D *hPt = new TH1D("hPt","",nBins,ptBins);
  TH1D *hPtRecoTruth = new TH1D("hPtRecoTruth","",nBins,ptBins);
  TH1D *hPtMC = new TH1D("hPtMC","",nBins,ptBins);
  TH1D *hPtGen = new TH1D("hPtGen","",nBins,ptBins);

  for (Int_t i=0;i<nBins;i++)
    {
      TF1 *f = fit(nt,ntMC,ptBins[i],ptBins[i+1]);
      Double_t yield = f->Integral(5,6)/0.02;
      Double_t yieldErr = f->Integral(5,6)/0.02*f->GetParError(0)/f->GetParameter(0);
      hPt->SetBinContent(i+1,yield/(ptBins[i+1]-ptBins[i]));
      hPt->SetBinError(i+1,yieldErr/(ptBins[i+1]-ptBins[i]));
    }  

  TCanvas *c=  new TCanvas("cResult","",600,600);
  c->SetLogy();
  hPt->SetXTitle("B^{0} p_{T} (GeV/c)");
  hPt->SetYTitle("Uncorrected B^{0} dN/dp_{T}");
  hPt->Sumw2();
  hPt->Draw();
  c->SaveAs(Form("../plots/pp/ResultsBzero/c%s_cResult.pdf",tMC.Data()));

  ntMC->Project("hPtRecoTruth","Bpt",TCut(seldata.Data())&&"(Bgen==23333||Bgen==41000)");
  ntGen->Project("hPtGen","Gpt",TCut(weight)*TCut(selmcgen.Data()));
  divideBinWidth(hPtRecoTruth);
  divideBinWidth(hPtGen);
  TH1D* hPtGenDraw = (TH1D*)hPtGen->Clone("hPtGenDraw");
  hPtGenDraw->SetLineColor(kRed);

  hPtRecoTruth->Sumw2();
  hPtGen->Sumw2();
  TH1D* hEff = (TH1D*)hPtRecoTruth->Clone("hEff");
  hEff->Divide(hPtGen);

  TH1D* hPtCor = (TH1D*)hPt->Clone("hPtCor");
  hPtCor->Divide(hEff);
  TCanvas* cCor=  new TCanvas("cCorResult","",600,600);
  cCor->SetLogy();
  hPtCor->SetYTitle("Corrected B^{0} dN/dp_{T}");
  hPtCor->Draw();
  if(isMC) hPtGenDraw->Draw("same hist");
  cCor->SaveAs(Form("../plots/pp/ResultsBzero/c%s_cCor.pdf",tMC.Data()));

  TH1D* hPtSigma = (TH1D*)hPtCor->Clone("hPtSigma");
  Double_t BRchain = 6.09604e-5;
  hPtSigma->Scale(1./(2*luminosity*BRchain));
  hPtSigma->SetYTitle("d#sigma (B^{0})/dp_{T}");
  TCanvas *cSigma=  new TCanvas("cSigma","",600,600);
  cSigma->SetLogy();
  hPtSigma->Draw();
  cSigma->SaveAs(Form("../plots/pp/ResultsBzero/c%s_cSigma.pdf",tMC.Data()));

  TFile *outf = new TFile(Form("../files/pp/f%s_outputBzero.root",tMC.Data()),"recreate");
  outf->cd();
  hPt->Write();
  hEff->Write();
  hPtGen->Write();
  hPtCor->Write();
  hPtSigma->Write();
  outf->Close();
  delete outf;
}

void clean0(TH1D *h)
{
  for (Int_t i=1;i<=h->GetNbinsX();i++)
    {
      if(h->GetBinContent(i)==0) h->SetBinError(i,1);
    }
}

TF1 *fit(TTree *nt, TTree *ntMC, Double_t ptmin, Double_t ptmax)
{
   static Int_t count=0;
   count++;
   TCanvas* c= new TCanvas(Form("c%d",count),"",600,600);
   TH1D* h = new TH1D(Form("h%d",count),"",50,5,6);
   TH1D* hMC = new TH1D(Form("hMC%d",count),"",50,5,6);

   TString iNP="2.28629e1*Gaus(x,5.02606,6.84e-2)/(sqrt(2*3.14159)*(6.84e-2))+3.85695*Gaus(x,5.27701,0.04305)/(sqrt(2*3.14159)*(0.04305))";
   TF1 *f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[6]*("+iNP+")");
   nt->Project(Form("h%d",count),"Bmass",Form("%s&&Bpt>%f&&Bpt<%f",seldata.Data(),ptmin,ptmax));
   ntMC->Project(Form("hMC%d",count),"Bmass",Form("%s&&Bpt>%f&&Bpt<%f",Form("%s&&(Bgen==23333||Bgen==41000)",selmc.Data()),ptmin,ptmax));

   clean0(h);
   h->Draw();
   h->Draw();
   f->SetParLimits(4,-1000,0);
   f->SetParLimits(2,0.01,0.08);
   f->SetParLimits(8,0.01,0.1);
   f->SetParLimits(7,0,1);
   f->SetParLimits(6,0,1000);

   f->SetParameter(0,setparam0);
   f->SetParameter(1,setparam1);
   f->SetParameter(2,setparam2);
   f->SetParameter(8,setparam3);
   f->FixParameter(1,fixparam1);
   f->FixParameter(6,0);
   h->GetEntries();

   hMC->Fit(Form("f%d",count),"q","",5,6);
   hMC->Fit(Form("f%d",count),"q","",5,6);
   f->ReleaseParameter(1);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L q","",5,6);
   hMC->Fit(Form("f%d",count),"L m","",5,6);

   f->FixParameter(1,f->GetParameter(1));
   f->FixParameter(2,f->GetParameter(2));
   f->FixParameter(7,f->GetParameter(7));
   f->FixParameter(8,f->GetParameter(8));
   f->ReleaseParameter(6);
   
   h->Fit(Form("f%d",count),"q","",5,6);
   h->Fit(Form("f%d",count),"q","",5,6);
   f->ReleaseParameter(1);
   h->Fit(Form("f%d",count),"L q","",5,6);
   h->Fit(Form("f%d",count),"L q","",5,6);
   h->Fit(Form("f%d",count),"L q","",5,6);
   h->Fit(Form("f%d",count),"L m","",5,6);
   h->SetMarkerSize(0.8);
   h->SetMarkerStyle(20);
   cout <<h->GetEntries()<<endl;

   TF1 *background = new TF1(Form("background%d",count),"[0]+[1]*x");
   background->SetParameter(0,f->GetParameter(3));
   background->SetParameter(1,f->GetParameter(4));
   background->SetLineColor(4);
   background->SetRange(5,6);
   background->SetLineStyle(2);
   
   TF1 *Bkpi = new TF1(Form("fBkpi%d",count),"[0]*("+iNP+")");
   Bkpi->SetParameter(0,f->GetParameter(6));
   Bkpi->SetLineColor(kGreen+1);
   Bkpi->SetFillColor(kGreen+1);
   Bkpi->SetRange(5.00,6.00);
   Bkpi->SetLineStyle(1);
   Bkpi->SetFillStyle(3004);

   TF1 *mass = new TF1(Form("fmass%d",count),"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))");
   mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8));
   mass->SetParError(0,f->GetParError(0));
   mass->SetParError(1,f->GetParError(1));
   mass->SetParError(2,f->GetParError(2));
   mass->SetParError(7,f->GetParError(7));
   mass->SetParError(8,f->GetParError(8));
   mass->SetLineColor(2);
   mass->SetLineStyle(2);

   h->SetMarkerStyle(24);
   h->SetStats(0);
   h->Draw("e");
   h->SetXTitle("M_{B} (GeV/c^{2})");
   h->SetYTitle("Entries / (20 MeV/c^{2})");
   h->GetXaxis()->CenterTitle();
   h->GetYaxis()->CenterTitle();
   h->SetTitleOffset(1.3,"Y");
   h->SetAxisRange(0,h->GetMaximum()*1.4,"Y");
   Bkpi->Draw("same");
   background->Draw("same");   
   mass->SetRange(5,6);
   mass->Draw("same");
   mass->SetLineStyle(2);
   mass->SetFillStyle(3004);
   mass->SetFillColor(2);
   f->Draw("same");

   Double_t yield = mass->Integral(5,6)/0.02;
   Double_t yieldErr = mass->Integral(5,6)/0.02*mass->GetParError(0)/mass->GetParameter(0);

   TLegend* leg0 = myLegend(0.1,0.86,0.52,0.94);
   leg0->AddEntry(h,"CMS Preliminary","");
   leg0->Draw();
   TLegend* leg1 = myLegend(0.11,0.82,0.52,0.86);
   leg1->AddEntry(h,"pp #sqrt{s}= 5.02 TeV","");
   leg1->Draw();
   TLegend* leg2 = myLegend(0.50,0.55,0.87,0.87);
   leg2->AddEntry(h,"|y| < 2.4","");
   leg2->AddEntry(h,Form("%.0f< p_{T}^{B} <%.0f GeV/c",ptmin,ptmax),"");
   leg2->AddEntry(h,"Data","pl");
   leg2->AddEntry(f,"Fit","l");
   leg2->AddEntry(mass,"Signal","f");
   leg2->AddEntry(background,"Comb. Background","l");
   leg2->AddEntry(Bkpi,"Non-prompt J/#psi","f");
   leg2->Draw();
   TLegend *leg3 = myLegend(0.40,0.40,0.89,0.55);
   leg3->AddEntry(h,"B^{0} meson","");
   leg3->AddEntry(h,Form("M_{B}=%.2f #pm %.2f MeV/c^{2}",mass->GetParameter(1)*1000.,mass->GetParError(1)*1000.),"");
   leg3->AddEntry(h,Form("N_{B}=%.0f #pm %.0f", yield, yieldErr),"");
   leg3->Draw();

   c->SaveAs(Form("../plots/pp/ResultsBzero/c%s_BMass-%d.pdf",tMC.Data(),count));
   return mass;
}

