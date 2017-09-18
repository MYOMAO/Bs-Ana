#include "uti.h"
#include "parameters.h"
#include "TF1.h"

Double_t setparam0=100.;
Double_t setparam1=5.28;
Double_t setparam2=0.05;
Double_t setparam3=0.03;
Double_t fixparam1=5.279;

Double_t minhisto=5.0;
Double_t maxhisto=6.0;
Double_t nbinsmasshisto=50;
Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weight;
TString weightgen;
TString seldata;
TString selmc;
TString selmceff;
TString selmcgen;
TString collisionsystem;
Float_t hiBinMin,hiBinMax,centMin,centMax;

void fitB_comp(int usePbPb=0, TString inputdata="/data/wangj/Data2015/Bntuple/pp/ntB_EvtBase_20160420_BfinderData_pp_20160419_bPt0jpsiPt0tkPt0p5.root" , TString inputmc="/data/HeavyFlavourRun2/MC2015/Bntuple/pp/Bntuple20160606_pp_Pythia8_BuToJpsiK_Bpt5p0_Pthat5.root", TString trgselection="1",  TString cut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&Btrk1Pt>0.9&&Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>3.41&&cos(Bdtheta)>-3.46e-01&&Bmu1pt>1.5&&Bmu2pt>1.5&&Blxy>0.025", TString cutmcgen="TMath::Abs(Gy)<2.4&&abs(GpdgId)==521&&GisSignal==1", int isMC=0, Double_t luminosity=1., int doweight=0, TString collsyst="PP", TString outputfile="ROOTfiles/mytest.root", TString npfile="ROOTfiles/NPFitPP.root", Float_t centmin=0., Float_t centmax=0., TString compname="Comp", int compnBins=10, double compmin=0.0, double compmax=10.0, TString rmkname="test")
{
  collisionsystem=collsyst;
  hiBinMin = centmin*2;
  hiBinMax = centmax*2;
  centMin = centmin;
  centMax = centmax;
  
  double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing);
  
  if (!(usePbPb==1||usePbPb==0)) std::cout<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!, you are using a non valid isPbPb option"<<std::endl;
  bool isPbPb=(bool)(usePbPb);

  if(!isPbPb)
    {
      seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
      selmceff = Form("%s",cut.Data());
      selmcgen = Form("%s",cutmcgen.Data());
    }
  else
    {
      seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
      selmceff = Form("%s&&hiBin>=%f&&hiBin<=%f",cut.Data(),hiBinMin,hiBinMax);
      selmcgen = Form("%s&&hiBin>=%f&&hiBin<=%f",cutmcgen.Data(),hiBinMin,hiBinMax);
    }

  selmc = Form("%s",cut.Data());

  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);

  void clean0 (TH1D* h);
  void getNPFnPar(TString npfname, float par[]);
  TF1* fit (TTree* nt, TTree* ntMC, double ptmin, double ptmax, int isMC,bool, TF1* &total,Float_t centmin, Float_t centmax, float NPpar[], TString compname, TString rmkname);
  float NPpar[2];
  getNPFnPar(npfile, NPpar);
  std::cout<<"NP parameter 0: "<<NPpar[0]<<std::endl;
  std::cout<<"NP parameter 1: "<<NPpar[1]<<std::endl;

  if(doweight==0) {
     weightgen="1";
     weight="1";
  }
  else if (doweight==1) {weightgen="1"; weight="pow(10,0.069193*Bpt+1.791038+Bpt*Bpt*-0.001178)+pow(10,0.091031*Bpt+-8.663444+Bpt*Bpt*0.000248)"; }
  //if (doweight<0 || doweight>=1) std::cout<<"ERROR, this weighting option is not defined"<<std::endl;
  
  std::cout<<"we are using weight="<<weight<<std::endl;
  
  TFile* inf = new TFile(inputdata.Data());
  TFile* infMC = new TFile(inputmc.Data());

  TTree* nt = (TTree*)inf->Get("ntKp");
  nt->AddFriend("ntHlt");
  nt->AddFriend("ntHi");
  nt->AddFriend("ntSkim");

  TTree* ntGen = (TTree*)infMC->Get("ntGen");
  ntGen->AddFriend("ntHlt");
  ntGen->AddFriend("ntHi");

  TTree* ntMC = (TTree*)infMC->Get("ntKp");
  ntMC->AddFriend("ntHlt");
  ntMC->AddFriend("ntHi");
  ntMC->AddFriend("ntSkim");
  ntMC->AddFriend(ntGen);
 /* 
  TH1D* hPt = new TH1D("hPt","",nBins,ptBins);
  TH1D* hPtRecoTruth = new TH1D("hPtRecoTruth","",nBins,ptBins);
  TH1D* hPtMC = new TH1D("hPtMC","",nBins,ptBins);
  TH1D* hPtGen = new TH1D("hPtGen","",nBins,ptBins);

  TH1D* hMean = new TH1D("hMean","",nBins,ptBins);                       
  TH1D* hSigmaGaus1 = new TH1D("hSigmaGaus1","",nBins,ptBins); 
  TH1D* hSigmaGaus2 = new TH1D("hSigmaGaus2","",nBins,ptBins); 
*/
  TH1D* hPt = new TH1D("hPt","",compnBins,compmin,compmax);
  TH1D* hPtRecoTruth = new TH1D("hPtRecoTruth","",compnBins,compmin,compmax);
  TH1D* hPtMC = new TH1D("hPtMC","",compnBins,compmin,compmax);
  TH1D* hPtGen = new TH1D("hPtGen","",compnBins,compmin,compmax);

  TH1D* hMean = new TH1D("hMean","",compnBins,compmin,compmax);                       
  TH1D* hSigmaGaus1 = new TH1D("hSigmaGaus1","",compnBins,compmin,compmax); 
  TH1D* hSigmaGaus2 = new TH1D("hSigmaGaus2","",compnBins,compmin,compmax); 

  TF1 *totalmass;

  for(int i=0;i<compnBins;i++)
    {
      TF1* f = fit(nt,ntMC,compmin+(compmax-compmin)/compnBins*i,compmin+(compmax-compmin)/compnBins*(i+1),isMC,isPbPb, totalmass,centmin, centmax, NPpar, compname, rmkname);
      hMean->SetBinContent(i+1,f->GetParameter(1));
      hMean->SetBinError(i+1,f->GetParError(1));  
      double yield = f->Integral(minhisto,maxhisto)/binwidthmass;
      double yieldErr = f->Integral(minhisto,maxhisto)/binwidthmass*f->GetParError(0)/f->GetParameter(0);
      hPt->SetBinContent(i+1,yield/((compmax-compmin)/compnBins));
      hPt->SetBinError(i+1,yieldErr/((compmax-compmin)/compnBins));
    }  

  ntMC->Project("hPtMC","Bpt",TCut(weight)*(TCut(selmceff.Data())&&"(Bgen==23333)"));
  divideBinWidth(hPtMC);
  ntMC->Project("hPtRecoTruth","Bpt",TCut(selmceff.Data())&&"(Bgen==23333)");
  divideBinWidth(hPtRecoTruth);
  ntGen->Project("hPtGen","Gpt",TCut(weightgen)*(TCut(selmcgen.Data())));
  divideBinWidth(hPtGen);

  TCanvas* cPt =  new TCanvas("cPt","",600,600);
  cPt->SetLogy();
  hPt->SetXTitle("D^{0} p_{T} (GeV/c)");
  hPt->SetYTitle("Uncorrected dN(D^{0})/dp_{T}");
  hPt->Sumw2();
  hPt->Draw();
  if(isMC==1)
    {
      hPtMC->Draw("same hist");
      TLegend* legPt = myLegend(0.55,0.80,0.90,0.94);
      legPt->AddEntry(hPt,"Signal extraction","pl");
      legPt->AddEntry(hPtMC,"Matched reco","lf");
      legPt->Draw("same");  
    }
  hPtMC->Sumw2();
  TH1D* hEff = (TH1D*)hPtMC->Clone("hEff");
  hEff->SetTitle(";B^{+} p_{T} (GeV/c);Efficiency");
  hEff->Sumw2();
  hEff->Divide(hPtGen);
  TCanvas* cEff = new TCanvas("cEff","",600,600);
  hEff->Draw();
  
  TH1D* hPtCor = (TH1D*)hPt->Clone("hPtCor");
  hPtCor->SetTitle(";B^{+} p_{T} (GeV/c);Corrected dN(B^{+})/dp_{T}");
  hPtCor->Divide(hEff);
  TCanvas* cPtCor=  new TCanvas("cCorResult","",600,600);
  cPtCor->SetLogy();
  hPtCor->Draw();
  if(isMC==1)
    {
      hPtGen->Draw("same hist");
      TLegend* legPtCor = myLegend(0.55,0.80,0.90,0.94);
      legPtCor->AddEntry(hPtCor,"Corrected signal","pl");
      legPtCor->AddEntry(hPtGen,"Generated B^{+}","lf");
      legPtCor->Draw("same");  
    }

  TH1D* hPtSigma= (TH1D*)hPtCor->Clone("hPtSigma");
  hPtSigma->SetTitle(";B^{+} p_{T} (GeV/c);d#sigma(B^{+})/dp_{T} (pb/GeV)");
  hPtSigma->Scale(1./(2*luminosity*BRchain));
  TCanvas* cPtSigma=  new TCanvas("cPtSigma","",600,600);
  cPtSigma->SetLogy();
  hPtSigma->Draw();
  
  TFile* outf = new TFile(outputfile.Data(),"recreate");
  outf->cd();
  hPt->Write();
  hEff->Write();
  hMean->Write();
  hPtGen->Write();
  hPtMC->Write();
  hPtCor->Write();
  hPtSigma->Write();
  outf->Close();

}

void clean0(TH1D* h)
{
  for (int i=1;i<=h->GetNbinsX();i++)
    {
      if(h->GetBinContent(i)==0) h->SetBinError(i,1);
    }
}

void getNPFnPar(TString npfname, float par[]){
	TFile* npf = new TFile(npfname.Data());
	TF1* f = (TF1*)npf->Get("f1");
	par[0] = f->GetParameter(1);
	par[1] = f->GetParameter(2);
}

TF1 *fit(TTree *nt, TTree *ntMC, Double_t ptmin, Double_t ptmax, int isMC,bool isPbPb,TF1* &total,Float_t centmin, Float_t centmax, float NPpar[], TString compname, TString rmkname)
{
   //cout<<cut.Data()<<endl;
   static Int_t count=0;
   count++;
   TCanvas* c= new TCanvas(Form("c%d",count),"",600,600);
   TH1D* h = new TH1D(Form("h-%d",count),"",nbinsmasshisto,minhisto,maxhisto);
   TH1D* hMCSignal = new TH1D(Form("hMCSignal-%d",count),"",nbinsmasshisto,minhisto,maxhisto);

   //TString iNP="7.26667e+00*Gaus(x,5.10472e+00,2.63158e-02)/(sqrt(2*3.14159)*2.63158e-02)+4.99089e+01*Gaus(x,4.96473e+00,9.56645e-02)/(sqrt(2*3.14159)*9.56645e-02)+3.94417e-01*(3.74282e+01*Gaus(x,5.34796e+00,3.11510e-02)+1.14713e+01*Gaus(x,5.42190e+00,1.00544e-01))";

   TString iNP=Form("TMath::Erf((x-%f)/%f)", NPpar[0], NPpar[1]);
   TF1* f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*("+iNP+")+[5]");
/*
   if(isMC==1) nt->Project(Form("h-%d",count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)","1",seldata.Data(),compname.Data(),ptmin,compname.Data(),ptmax));   
   else nt->Project(Form("h-%d",count),"Bmass",Form("(%s&&%s>%f&&%s<%f)",seldata.Data(),compname.Data(),ptmin,compname.Data(),ptmax));   
*/
   if(isMC==1) nt->Project(Form("h-%d",count),"Bmass",Form("%s*(%s&&%s>%f&&%s<%f)",weight.Data(),seldata.Data(),compname.Data(),ptmin,compname.Data(),ptmax));   
   else nt->Project(Form("h-%d",count),"Bmass",Form("(%s&&%s>%f&&%s<%f)",seldata.Data(),compname.Data(),ptmin,compname.Data(),ptmax));   

   ntMC->Project(Form("hMCSignal-%d",count),"Bmass",Form("%s&&%s>%f&&%s<%f",Form("%s&&Bgen==23333",selmc.Data()),compname.Data(),ptmin,compname.Data(),ptmax));
   clean0(h);
/*
   TFile*fout=new TFile("testout.root","recreate");
   fout->cd();
   h->Write();
   hMCSignal->Write();
   fout->Close();
*/
  
   h->Draw();
   f->SetParLimits(4,-1000,0);
   f->SetParLimits(2,0.01,0.05);
   f->SetParLimits(8,0.01,0.05);
   f->SetParLimits(7,0,1);
   f->SetParLimits(5,0,1000);

   f->SetParameter(0,setparam0);
   f->SetParameter(1,setparam1);
   f->SetParameter(2,setparam2);
   f->SetParameter(8,setparam3);
   f->FixParameter(1,fixparam1);
   f->FixParameter(5,0);
   h->GetEntries();

   hMCSignal->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
   hMCSignal->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
   f->ReleaseParameter(1);
   hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
   hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
   hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
   hMCSignal->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);

   f->FixParameter(1,f->GetParameter(1));
   f->FixParameter(2,f->GetParameter(2));
   f->FixParameter(7,f->GetParameter(7));
   f->FixParameter(8,f->GetParameter(8));
   f->ReleaseParameter(5);
   
   h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
   h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
   f->ReleaseParameter(1);
   h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
   h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
   h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
   h->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);
   h->SetMarkerSize(0.8);
   h->SetMarkerStyle(20);

   TF1 *background = new TF1(Form("background%d",count),"[0]+[1]*x");
   background->SetParameter(0,f->GetParameter(3));
   background->SetParameter(1,f->GetParameter(4));
   background->SetLineColor(4);
   background->SetRange(minhisto,maxhisto);
   background->SetLineStyle(2);
   
   TF1 *Bkpi = new TF1(Form("fBkpi%d",count),"[0]*("+iNP+")");
   Bkpi->SetParameter(0,f->GetParameter(5));
   Bkpi->SetLineColor(kGreen+1);
   Bkpi->SetRange(minhisto,maxhisto);
   Bkpi->SetLineStyle(1);
   Bkpi->SetFillStyle(3004);
   Bkpi->SetFillColor(kGreen+1);

   TF1 *mass = new TF1(Form("fmass%d",count),"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))");
   mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8));
   mass->SetParError(0,f->GetParError(0));
   mass->SetParError(1,f->GetParError(1));
   mass->SetParError(2,f->GetParError(2));
   mass->SetParError(7,f->GetParError(7));
   mass->SetParError(8,f->GetParError(8));
   mass->SetLineColor(2);

  h->SetXTitle("m_{#mu#muK} (GeV/c^{2})");
  h->SetYTitle("Entries / (5 MeV/c^{2})");
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
  h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
  h->GetXaxis()->SetTitleOffset(1.3);
  h->GetYaxis()->SetTitleOffset(1.8);
  h->GetXaxis()->SetLabelOffset(0.007);
  h->GetYaxis()->SetLabelOffset(0.007);
  h->GetXaxis()->SetTitleSize(0.045);
  h->GetYaxis()->SetTitleSize(0.045);
  h->GetXaxis()->SetTitleFont(42);
  h->GetYaxis()->SetTitleFont(42);
  h->GetXaxis()->SetLabelFont(42);
  h->GetYaxis()->SetLabelFont(42);
  h->GetXaxis()->SetLabelSize(0.04);
  h->GetYaxis()->SetLabelSize(0.04);
  h->SetMarkerSize(0.8);
  h->SetMarkerStyle(20);
  h->SetStats(0);
  h->Draw("e");
   Bkpi->Draw("same");
   background->Draw("same");   
   mass->SetRange(minhisto,maxhisto);
   mass->Draw("same");
   mass->SetLineStyle(2);
   mass->SetFillStyle(3004);
   mass->SetFillColor(2);
   f->Draw("same");

   Double_t yield = mass->Integral(minhisto,maxhisto)/binwidthmass;
   Double_t yieldErr = mass->Integral(minhisto,maxhisto)/binwidthmass*mass->GetParError(0)/mass->GetParameter(0);

  TLegend* leg = new TLegend(0.65,0.58,0.82,0.88,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);
  leg->SetFillStyle(0);
  leg->AddEntry(h,"Data","pl");
  leg->AddEntry(f,"Fit","l");
  leg->AddEntry(mass,"B^{+} Signal","f");
  leg->AddEntry(background,"Combinatorial","l");
  leg->Draw("same");

  TLatex* texCms = new TLatex(0.18,0.93, "#scale[1.25]{CMS} Preliminary");
  texCms->SetNDC();
  texCms->SetTextAlign(12);
  texCms->SetTextSize(0.04);
  texCms->SetTextFont(42);
  texCms->Draw();

  TLatex* texCol;
  if(collisionsystem=="pp"||collisionsystem=="PP") texCol= new TLatex(0.96,0.93, Form("%s #sqrt{s_{NN}} = 5.02 TeV","pp"));
  else texCol= new TLatex(0.96,0.93, Form("%s #sqrt{s_{NN}} = 5.02 TeV","PbPb"));
  texCol->SetNDC();
  texCol->SetTextAlign(32);
  texCol->SetTextSize(0.04);
  texCol->SetTextFont(42);
  texCol->Draw();

  TLatex* tex;

  tex = new TLatex(0.22,0.78,Form("%.2f < %s < %.2f",ptmin,compname.Data(),ptmax));
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.04);
  tex->SetLineWidth(2);
  tex->Draw();
  
  if(centMax>0){
  TString texper="%";
  tex = new TLatex(0.22,0.71,Form("Centrality %.0f-%.0f%s",centMin,centMax,texper.Data()));//0.2612903,0.8425793
  tex->SetNDC();
  tex->SetTextColor(1);
  tex->SetTextFont(42);
  tex->SetTextSize(0.045);
  tex->SetLineWidth(2);
  tex->Draw();
  }

  tex = new TLatex(0.22,0.83,"|y| < 2.4");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.04);
  tex->SetLineWidth(2);
  tex->Draw();
     
   total=f;
   
  //if(!isPbPb) c->SaveAs(Form("plotFits/BMass%s_%d.pdf",collisionsystem.Data(),count));
  //else c->SaveAs(Form("plotFits/BMass%s_%.0f_%.0f_%d.pdf",collisionsystem.Data(),centMin,centMax,count));

  if(isPbPb && isMC==0) 
      c->SaveAs(Form("plotFits/data_PbPb_%s_%d.pdf",rmkname.Data(),count));
  else if(isPbPb && isMC==1) 
      c->SaveAs(Form("plotFits/mc_PbPb_%s_%d.pdf",rmkname.Data(),count));
  else if(!isPbPb && isMC==0) 
      c->SaveAs(Form("plotFits/data_pp_%s_%d.pdf",rmkname.Data(),count));
  else 
      c->SaveAs(Form("plotFits/mc_pp_%s_%d.pdf",rmkname.Data(),count));

  return mass;
}


int main(int argc, char *argv[])
{
  if(argc==20)
    {
      fitB_comp(atoi(argv[1]),argv[2], argv[3], argv[4], argv[5], argv[6], atoi(argv[7]), atof(argv[8]), atoi(argv[9]),argv[10],argv[11],argv[12],atof(argv[13]),atof(argv[14]),argv[15],atoi(argv[16]),atof(argv[17]),atof(argv[18]),argv[19]);
      return 0;
    }
  else if(argc==18)
    {
      fitB_comp(atoi(argv[1]), argv[2], argv[3], argv[4], argv[5], argv[6], atoi(argv[7]), atof(argv[8]), atoi(argv[9]),argv[10],argv[11],argv[12],-100,100,argv[13],atoi(argv[14]),atof(argv[15]),atof(argv[16]),argv[17]);
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}


double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing){
double squarederroronsigma=(1+smear)*(1+smear)*errwidth*errwidth+width*width*errsmearing*errsmearing;
double erroronsigma=TMath::Sqrt(squarederroronsigma);
return erroronsigma;

}

