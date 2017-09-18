using namespace std;
#include "uti.h"
#include "mva.h"

double minhisto=5.0;
double maxhisto=6.0;
double nbinsmasshisto=50;
double binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weightMC = "1";
TString weight = "1";
TString seldata;
TString selmc;
TString selmva;
TString collisionsystem;
bool  isPbPb;
float centmin,centmax,hiBinMin,hiBinMax;
float ptmin, ptmax;

void savehisto(TString inputdata="",
                   TString inputmc="",
                   TString trgselection="",
                   TString cut="",
                   int isMC=0, int doweight=0, TString collsyst="pp", TString mvatype ="", int ptnum = 0,
		   float centMin=0,
                   float centMax=100,
	           TString outputfile="outMVA")
{

  ptmin = ptBins[ptnum];
  ptmax = ptBins[ptnum+1];
  collisionsystem=collsyst;
  centmin = centMin;
  centmax = centMax;
  hiBinMin = centMin*2;
  hiBinMax = centMax*2;

  if(collisionsystem=="pp")
  {
      isPbPb = false;
      for(int i=0;i<4;i++)
      {
	memcpy(cutsSA[i],cutsSA_pp[i],sizeof(cutsSA[i]));
	memcpy(cutsGA[i],cutsGA_pp[i],sizeof(cutsGA[i]));
      }
      memcpy(cutsBDT,cutsBDT_pp,sizeof(cutsBDT));
      memcpy(cutsBDTB,cutsBDTB_pp,sizeof(cutsBDTB));
      memcpy(cutsBDTD,cutsBDTD_pp,sizeof(cutsBDTD));
      memcpy(cutsBDTG,cutsBDTG_pp,sizeof(cutsBDTG));
      memcpy(cutsBDTMitFisher,cutsBDTMitFisher_pp,sizeof(cutsBDTMitFisher));
      memcpy(cutsMLP,cutsMLP_pp,sizeof(cutsMLP));
      memcpy(cutsMLPBNN,cutsMLPBNN_pp,sizeof(cutsMLPBNN));
      memcpy(cutsMLPBFGS,cutsMLPBFGS_pp,sizeof(cutsMLPBFGS));
  }
  else
  {
      isPbPb = true;
      for(int i=0;i<4;i++)
      {
	memcpy(cutsSA[i],cutsSA_PbPb[i],sizeof(cutsSA[i]));
	memcpy(cutsGA[i],cutsGA_PbPb[i],sizeof(cutsGA[i]));
      }
      memcpy(cutsBDT,cutsBDT_PbPb,sizeof(cutsBDT));
      memcpy(cutsBDTB,cutsBDTB_PbPb,sizeof(cutsBDTB));
      memcpy(cutsBDTD,cutsBDTD_PbPb,sizeof(cutsBDTD));
      memcpy(cutsBDTG,cutsBDTG_PbPb,sizeof(cutsBDTG));
      memcpy(cutsBDTMitFisher,cutsBDTMitFisher_PbPb,sizeof(cutsBDTMitFisher));
      memcpy(cutsMLP,cutsMLP_PbPb,sizeof(cutsMLP));
      memcpy(cutsMLPBNN,cutsMLPBNN_PbPb,sizeof(cutsMLPBNN));
      memcpy(cutsMLPBFGS,cutsMLPBFGS_PbPb,sizeof(cutsMLPBFGS));
  }
  // if(!doweight) weight="1";

  TFile* inf = new TFile(inputdata.Data());
  TFile* infMC = new TFile(inputmc.Data());
  if(mvatype != "CutsSA" && mvatype != "CutsGA") TFile* infMVA = new TFile(Form("/afs/cern.ch/user/a/aturner/public/TMVA/mva/MVAfiles/%s_%s_%.0f_%.0f_DATA.root",mvatype.Data(),collisionsystem.Data(),ptmin,ptmax));

  if(!isPbPb) seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
  else seldata = Form("%s&&%s&&hiBin>=%f&&hiBin<=%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
  selmc = Form("%s",cut.Data());
  
  if(mvatype == "CutsSA")
  {
    selmva = Form("Btrk1Pt>%f && Bchi2cl>%f && cos(Bdtheta)>%f && (BsvpvDistance/BsvpvDisErr)>%f",cutsSA[ptnum][0],cutsSA[ptnum][1],cutsSA[ptnum][2],cutsSA[ptnum][3]);
  }

  else if(mvatype == "CutsGA")
  {
    selmva = Form("Btrk1Pt>%f && Bchi2cl>%f && cos(Bdtheta)>%f && (BsvpvDistance/BsvpvDisErr)>%f",cutsGA[ptnum][0],cutsGA[ptnum][1],cutsGA[ptnum][2],cutsGA[ptnum][3]);
  }

  //if(mvatype == "CutsSA"){selmva = Form("CutsSA>%f",cutsSA[ptnum]);}
  //else if(mvatype == "CutsGA"){selmva = Form("CutsGA>%f",cutsGA[ptnum]);}
  else if(mvatype == "MLP"){ selmva = Form("MLP>%f",cutsMLP[ptnum]); }
  else if(mvatype == "MLPBNN"){ selmva = Form("MLPBNN>%f",cutsMLPBNN[ptnum]); }
  else if(mvatype == "MLPBFGS"){ selmva = Form("MLPBFGS>%f",cutsMLPBFGS[ptnum]); }
  else if(mvatype == "BDT"){ selmva = Form("BDT>%f",cutsBDT[ptnum]); }
  else if(mvatype == "BDTB"){ selmva = Form("BDTB>%f",cutsBDTB[ptnum]); }
  else if(mvatype == "BDTD"){ selmva = Form("BDTD>%f",cutsBDTD[ptnum]); }
  else if(mvatype == "BDTG"){ selmva = Form("BDTG>%f",cutsBDTG[ptnum]); }
  else { selmva = Form("BDTMitFisher>%f",cutsBDTMitFisher[ptnum]); }

  if(mvatype != "CutsSA" && mvatype != "CutsGA") TTree* ntMVA = (TTree*)infMVA->Get("mvaTree");

  TTree* nt = (TTree*)inf->Get("ntKp");
  nt->AddFriend("ntHlt");
  nt->AddFriend("ntHi");
  nt->AddFriend("ntSkim");
  nt->AddFriend("bdtTree");
  if(mvatype != "CutsSA" && mvatype != "CutsGA") nt->AddFriend(ntMVA);

  TTree* ntGen = (TTree*)infMC->Get("ntGen");
  ntGen->AddFriend("ntHlt");
  ntGen->AddFriend("ntHi");

  TTree* ntMC = (TTree*)infMC->Get("ntKp");
  ntMC->AddFriend("ntHlt");
  ntMC->AddFriend("ntHi");
  ntMC->AddFriend("ntSkim");
  ntMC->AddFriend("bdtTree");
  ntMC->AddFriend(ntGen);
  if(mvatype != "CutsSA" && mvatype != "CutsGA") ntMC->AddFriend(ntMVA);
  
  cout<<"  -- Filling histograms"<<endl;
  cout<<"     "<<inputdata<<endl;
  cout<<"     "<<inputmc<<endl;

      TH1D* h = new TH1D("h","", nbinsmasshisto,minhisto,maxhisto);
      h->Sumw2();
      TH1D* hMCSignal = new TH1D("hMCSignal","",nbinsmasshisto,minhisto,maxhisto);
      hMCSignal->Sumw2();
      TH1D* hMCSwapped = new TH1D("hMCSwapped","",nbinsmasshisto,minhisto,maxhisto);
      hMCSwapped->Sumw2(); 

      if(isPbPb) nt->Project("h","Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f&&hiBin>=%f&&hiBin<=%f&&%s)",weight.Data(),seldata.Data(),ptmin,ptmax,hiBinMin,hiBinMax,selmva.Data()));
      else nt->Project("h","Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f&&%s)",weight.Data(),seldata.Data(),ptmin,ptmax,selmva.Data()));
      ntMC->Project("hMCSignal","Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f&&(Bgen==23333)&&%s)",weightMC.Data(),selmc.Data(),ptmin,ptmax,selmva.Data()));   
      ntMC->Project("hMCSwapped","Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f&&(Bgen==23344)&&%s)",weightMC.Data(),selmc.Data(),ptmin,ptmax,selmva.Data())); 

      TFile* outf = new TFile(Form("%s/%s_%s_%.0f_%.0f.root",outputfile.Data(),mvatype.Data(),collisionsystem.Data(),ptmin,ptmax),"recreate");
       
      outf->cd();
      h->Write();
      hMCSignal->Write();
      hMCSwapped->Write();
      outf->Close();
      delete h;
      delete hMCSignal;
      delete hMCSwapped;

  cout<<endl;
}

void mvahisto(TString inputdata="",
                   TString inputmc="",
                   TString trgselection="",
                   TString cut="",
                   int isMC=0, int doweight=0, TString collsyst="pp",
		   float centMin=0,
                   float centMax=100,
	           TString outputfile="outMVA")
{
    for(int i=0;i<nBins;i++)
    {
	for(int k=0;k<nMVA;k++)
	{
	    if(i != nBins-1 || k<2)
	    //if(i != nBins-1)
	    //{
		savehisto(inputdata,inputmc,trgselection,cut,isMC,doweight,collsyst,mvatypes[k],i,centMin,centMax,outputfile);
	    }
	}
    }
}

int main(int argc, char *argv[])
{
  if(argc==10)
    {
      mvahisto(argv[1], argv[2], argv[3], argv[4], atoi(argv[5]), atoi(argv[6]), argv[7], atof(argv[8]), atof(argv[9]));
      return 0;
    }
  else if(argc==8)
    {
      cout << "TESTING CALL" << endl;
      mvahisto(argv[1], argv[2], argv[3], argv[4], atoi(argv[5]), atoi(argv[6]), argv[7]);
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}

