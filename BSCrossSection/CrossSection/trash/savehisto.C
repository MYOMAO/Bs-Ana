using namespace std;
#include "uti.h"
#include "parameters.h"

double minhisto=5.0;
double maxhisto=6.0;
double nbinsmasshisto=50;
double binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weightMC = "1";
TString weight = "1";
TString seldata;
TString selmc;
TString collisionsystem;
bool  isPbPb;
float centmin,centmax,hiBinMin,hiBinMax;

void savehisto(TString inputdata="",
                   TString inputmc="",
                   TString trgselection="",
                   TString cut="",
                   int isMC=0, int doweight=0, TString collsyst="pp",
		   float centMin=0,
                   float centMax=100,
	           TString outputfile="outHisto")
{

  collisionsystem=collsyst;
  centmin = centMin;
  centmax = centMax;
  hiBinMin = centMin*2;
  hiBinMax = centMax*2;

  isPbPb = true;
  if(collisionsystem=="pp") isPbPb = false;
  // if(!doweight) weight="1";

  TFile* inf = new TFile(inputdata.Data());
  TFile* infMC = new TFile(inputmc.Data());

  if(!isPbPb) seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
  else seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
  selmc = Form("%s",cut.Data());  
  
  TTree* nt = (TTree*)inf->Get("ntKp");
  nt->AddFriend("ntHlt");
  nt->AddFriend("ntHi");
  nt->AddFriend("ntSkim");
  nt->AddFriend("bdtTree");

  TTree* ntGen = (TTree*)infMC->Get("ntGen");
  ntGen->AddFriend("ntHlt");
  ntGen->AddFriend("ntHi");

  TTree* ntMC = (TTree*)infMC->Get("ntKp");
  ntMC->AddFriend("ntHlt");
  ntMC->AddFriend("ntHi");
  ntMC->AddFriend("ntSkim");
  ntMC->AddFriend("bdtTree");
  ntMC->AddFriend(ntGen);

  if(!isPbPb) seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
  else seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
  selmc = Form("%s",cut.Data());  
  
  cout<<"  -- Filling histograms"<<endl;
  cout<<"     "<<inputdata<<endl;
  cout<<"     "<<inputmc<<endl;
  for(int i=0;i<nBins;i++)
    {
      cout<<setiosflags(ios::left)<<"   - Processing ptbin "<<setw(3)<<ptBins[i]<<" "<<setw(3)<<ptBins[i+1]<<endl;
      TH1D* h = new TH1D("h","", nbinsmasshisto,minhisto,maxhisto);
      h->Sumw2();
      TH1D* hMCSignal = new TH1D("hMCSignal","",nbinsmasshisto,minhisto,maxhisto);
      hMCSignal->Sumw2();
      TH1D* hMCSwapped = new TH1D("hMCSwapped","",nbinsmasshisto,minhisto,maxhisto);
      hMCSwapped->Sumw2(); 

      if(isPbPb) nt->Project("h","Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f&&hiBin>=%f&&hiBin<=%f)",weight.Data(),seldata.Data(),ptBins[i],ptBins[i+1],hiBinMin,hiBinMax));
      else nt->Project("h","Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f)",weight.Data(),seldata.Data(),ptBins[i],ptBins[i+1]));
      ntMC->Project("hMCSignal","Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f&&(Bgen==23333))",weightMC.Data(),selmc.Data(),ptBins[i],ptBins[i+1]));   
      ntMC->Project("hMCSwapped","Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f&&(Bgen==23344))",weightMC.Data(),selmc.Data(),ptBins[i],ptBins[i+1])); 

      TFile* outf = new TFile(Form("%s/%s_%.0f_%.0f.root",outputfile.Data(),collisionsystem.Data(),ptBins[i],ptBins[i+1]),"recreate");
       
      outf->cd();
      h->Write();
      hMCSignal->Write();
      hMCSwapped->Write();
      outf->Close();
      delete h;
      delete hMCSignal;
      delete hMCSwapped;
    }

  cout<<endl;
}

int main(int argc, char *argv[])
{
  if(argc==10)
    {
      savehisto(argv[1], argv[2], argv[3], argv[4], atoi(argv[5]), atoi(argv[6]), argv[7], atof(argv[8]), atof(argv[9]));
      return 0;
    }
  else if(argc==8)
    {
      cout << "TESTING CALL" << endl;
      savehisto(argv[1], argv[2], argv[3], argv[4], atoi(argv[5]), atoi(argv[6]), argv[7]);
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}

