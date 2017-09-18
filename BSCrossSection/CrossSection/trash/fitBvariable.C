using namespace std;
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

Bool_t isPbPb;
Bool_t isMC;
TString weight;
TString seldata;
TString selmc;
TString collisionsystem;
TString tMC;
Float_t hiBinMin,hiBinMax,centmin,centmax;
TString npfit;

int fitBvariable(TString variable, TString variableplot, TString variablename,
                 int usePbPb, int useMC,
                 TString inputdata, TString inputmc, 
                 TString trgselection, TString cut,
                 int doweight,
                 TString outputfile, TString npfitfunction,
                 Float_t centMin=0., Float_t centMax=0.)
{
  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);

  void clean0 (TH1D* h);
  TF1* fit(TString variable, TString variableplot, TString variablename, TTree *nt, TTree *ntMC, Double_t ptmin, Double_t ptmax);
  
  npfit = npfitfunction;

  hiBinMin = centMin*2;
  hiBinMax = centMax*2;
  centMin = centmin;
  centMax = centmax;
  
  if(!(usePbPb==1||usePbPb==0))
    {
      cout<<" ERROR: invalide usePbPb"<<endl;
      return 1;
    }
  isPbPb = (Bool_t)(usePbPb);
  collisionsystem = (isPbPb)?"PbPb":"pp";

  if(!(useMC==1||useMC==0))
    {
      cout<<" ERROR: invalide useMC"<<endl;
      return 1;
    }
  isMC = (Bool_t)(useMC);
  tMC = (isMC)?"MC":"Data";
  
  cout<<endl;
  cout<<"  -- Processing - "<<collisionsystem<<" - "<<tMC<<endl;
  cout<<"   - variable - "<<variable<<endl;
  cout<<endl;
  
  TString inclpT = "(Bpt>7.&&Bpt<50.)";
  if(!isPbPb)
    {
      seldata = Form("%s&&%s&&%s",trgselection.Data(),cut.Data(),inclpT.Data());
      selmc = Form("%s&&%s",cut.Data(),inclpT.Data());
    }
  else
    {
      seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f&&%s",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax,inclpT.Data());
      selmc = Form("%s&&%s",cut.Data(),inclpT.Data());
    }

  if(doweight==0)
    {
      weight = "1";
    }
  else if(doweight==1)
    {
      if(!isPbPb)
        {
          weight = "pthatweight*(pow(10,-0.094152+0.008102*Bgenpt+Bgenpt*Bgenpt*0.000171+Bgenpt*Bgenpt*Bgenpt*-0.000005+Bgenpt*Bgenpt*Bgenpt*Bgenpt*-0.000000+Bgenpt*Bgenpt*Bgenpt*Bgenpt*Bgenpt*0.000000))";
        }
      else
        {
          weight = "pthatweight*(pow(10,-0.107832+0.010248*Bgenpt+Bgenpt*Bgenpt*0.000079+Bgenpt*Bgenpt*Bgenpt*-0.000003+Bgenpt*Bgenpt*Bgenpt*Bgenpt*-0.000000+Bgenpt*Bgenpt*Bgenpt*Bgenpt*Bgenpt*0.000000))*(6.08582+hiBin*(-0.155739)+hiBin*hiBin*(0.00149946)+hiBin*hiBin*hiBin*(-6.41629e-06)+hiBin*hiBin*hiBin*hiBin*(1.02726e-08))";
        }
    }
  else
    {
      cout<<" ERROR: invalide doweight"<<endl;
      return 1;
    }
  
  cout<<"  -- weight"<<endl;
  cout<<"   - reco weight"<<endl;
  cout<<"     "<<weight<<endl;
  cout<<endl;
  
  TFile* inf = new TFile(inputdata.Data());
  TFile* infMC = new TFile(inputmc.Data());

  TTree* nt = (TTree*)inf->Get("ntKp");
  nt->AddFriend("ntHlt");
  nt->AddFriend("ntHi");
  nt->AddFriend("ntSkim");
  nt->AddFriend("mvaTree");

  TTree* ntMC = (TTree*)infMC->Get("ntKp");
  ntMC->AddFriend("ntHlt");
  ntMC->AddFriend("ntHi");
  ntMC->AddFriend("ntSkim");
  ntMC->AddFriend("mvaTree");
  
  TH1D* hPt = new TH1D("hPt","",nBins,ptBins);

  for(int i=0;i<nBins;i++)
    {
      TF1* f = fit(variable, variableplot, variablename, nt, ntMC, ptBins[i], ptBins[i+1]);
      double yield = f->Integral(minhisto,maxhisto)/binwidthmass;
      double yieldErr = f->Integral(minhisto,maxhisto)/binwidthmass*f->GetParError(0)/f->GetParameter(0);
      hPt->SetBinContent(i+1,yield/(ptBins[i+1]-ptBins[i]));
      hPt->SetBinError(i+1,yieldErr/(ptBins[i+1]-ptBins[i]));
    }  

  TCanvas* cPt =  new TCanvas("cPt","",600,600);
  cPt->SetLogy();
  hPt->SetXTitle(Form("B^{+} %s",variable.Data()));
  hPt->SetYTitle("Uncorrected dN(B^{+})/dp_{T}");
  hPt->Sumw2();
  hPt->Draw();
  
  TFile* outf = new TFile(Form("%s_%s_%s.root",outputfile.Data(),collisionsystem.Data(),variablename.Data()),"recreate");
  outf->cd();
  hPt->Write();
  outf->Close();

  return 0;
}

void clean0(TH1D* h)
{
  for(int i=1;i<=h->GetNbinsX();i++)
    {
      if(h->GetBinContent(i)==0) h->SetBinError(i,1);
    }
}

TF1* fit(TString variable, TString variableplot, TString variablename, TTree *nt, TTree *ntMC, Double_t ptmin, Double_t ptmax)
{
  static Int_t count = 0;
  count++;
  TCanvas* c = new TCanvas(Form("c%d",count),"",600,600);
  TH1D* h = new TH1D(Form("h-%d",count),"",nbinsmasshisto,minhisto,maxhisto);
  TH1D* hMCSignal = new TH1D(Form("hMCSignal-%d",count),"",nbinsmasshisto,minhisto,maxhisto);
  
  TString iNP = npfit;
  TF1* f = new TF1(Form("f%d",count),"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*("+iNP+")");
  
  if(isMC==1) nt->Project(Form("h-%d",count),"Bmass",Form("%s*(%s&&(%s)>%f&&(%s)<%f)",weight.Data(),seldata.Data(),variable.Data(),ptmin,variable.Data(),ptmax));
  else nt->Project(Form("h-%d",count),"Bmass",Form("(%s&&(%s)>%f&&(%s)<%f)",seldata.Data(),variable.Data(),ptmin,variable.Data(),ptmax));
  ntMC->Project(Form("hMCSignal-%d",count),"Bmass",Form("%s*(%s&&(%s)>%f&&(%s)<%f&&(Bgen==23333))",weight.Data(),selmc.Data(),variable.Data(),ptmin,variable.Data(),ptmax));   
  
  clean0(h);
  
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
  
  TF1* background = new TF1(Form("background%d",count),"[0]+[1]*x");
  background->SetParameter(0,f->GetParameter(3));
  background->SetParameter(1,f->GetParameter(4));
  background->SetLineColor(4);
  background->SetRange(minhisto,maxhisto);
  background->SetLineStyle(2);
  
  TF1* Bkpi = new TF1(Form("fBkpi%d",count),"[0]*("+iNP+")");
  Bkpi->SetParameter(0,f->GetParameter(5));
  Bkpi->SetLineColor(kGreen+1);
  Bkpi->SetRange(minhisto,maxhisto);
  Bkpi->SetLineStyle(1);
  Bkpi->SetFillStyle(3004);
  Bkpi->SetFillColor(kGreen+1);
  
  TF1* mass = new TF1(Form("fmass%d",count),"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))");
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
  
  TLatex* texCol = new TLatex(0.96,0.93, Form("%s #sqrt{s_{NN}} = 5.02 TeV",collisionsystem.Data()));
  texCol->SetNDC();
  texCol->SetTextAlign(32);
  texCol->SetTextSize(0.04);
  texCol->SetTextFont(42);
  texCol->Draw();
  
  TLatex* tex;
  
  tex = new TLatex(0.22,0.78,Form("%.1f < %s  < %.1f",ptmin,variableplot.Data(),ptmax));
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.04);
  tex->SetLineWidth(2);
  tex->Draw();
  
  if(isPbPb)
    {
      TString texper="%";
      tex = new TLatex(0.22,0.71,Form("Centrality %.0f-%.0f%s",centmin,centmax,texper.Data()));//0.2612903,0.8425793
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
  
  c->SaveAs(Form("plotVariablesFits/BMass_%s_%s_%s_%d.pdf",collisionsystem.Data(),tMC.Data(),variablename.Data(),count));
  return mass;
}


int main(int argc, char *argv[])
{
  if(argc==15)
    {
      fitBvariable(argv[1], argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), argv[6], argv[7], argv[8], argv[9], atoi(argv[10]), argv[11],argv[12], atof(argv[13]), atof(argv[14]));
      return 0;
    }
  else if(argc==13)
    {
      fitBvariable(argv[1], argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), argv[6], argv[7], argv[8], argv[9], atoi(argv[10]), argv[11],argv[12]);
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}
