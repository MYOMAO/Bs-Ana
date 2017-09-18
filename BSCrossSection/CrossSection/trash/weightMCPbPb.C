#include "uti.h"
#include "parameters.h"
#include "TLegendEntry.h"

TString weightfunctiongen = "1";
TString weightfunctionreco = "1";
TString selmc;

void weightPbPbvertex(){

TFile*fMC=new TFile("/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root");
TTree *ntDkpiMC = (TTree*)fMC->Get("ntDkpi");
TTree *ntSkimMC = (TTree*)fMC->Get("ntSkim");
TTree *ntHiMC = (TTree*)fMC->Get("ntHi");
ntDkpiMC->AddFriend(ntSkimMC);
ntDkpiMC->AddFriend(ntHiMC);

TFile*fData=new TFile("/data/jisun/PbPb2015/HF2and_ncand_skim_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root");
TTree *ntDkpiData = (TTree*)fData->Get("ntDkpi");
TTree *ntSkimData = (TTree*)fData->Get("ntSkim");
TTree *ntHiData = (TTree*)fData->Get("ntHi");
TTree *ntHltData = (TTree*)fData->Get("ntHlt");
ntDkpiData->AddFriend(ntSkimData);
ntDkpiData->AddFriend(ntHiData);
ntDkpiData->AddFriend(ntHltData);

TH1F*hpzData=new TH1F("hpzData","hpzData",200,-15,15);
TH1F*hpzMC=new TH1F("hpzMC","hpzMC",200,-15,15);

TCut weighpthat="1";
TString cut="abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3";
TString hlt="HLT_HIL1MinimumBiasHF2AND_part1_v1||HLT_HIL1MinimumBiasHF2AND_part2_v1||HLT_HIL1MinimumBiasHF2AND_part3_v1";

TCut weighttest="1";
//TCut weighttest="1.26077+PVz*(0.00887442)+PVz*PVz*(-0.00782056)+PVz*PVz*PVz*(-3.51063e-05)+PVz*PVz*PVz*PVz*(-3.51063e-05)";

ntDkpiMC->Project("hpzMC","PVz",TCut(weighpthat)*(TCut(cut.Data()*TCut(weighttest))));
ntDkpiData->Project("hpzData","PVz",(TCut(cut.Data())*TCut(hlt.Data())));

hpzMC->Scale(1./hpzMC->Integral(hpzMC->FindBin(-15.),hpzMC->FindBin(15)));
hpzData->Scale(1./hpzData->Integral(hpzMC->FindBin(-15.),hpzMC->FindBin(15)));

TCanvas*cRatioVtx=new TCanvas("cRatioVtx","cRatioVtx",500,500);
cRatioVtx->Divide(2,1);
cRatioVtx->cd(1);
hpzMC->SetLineColor(2);
hpzMC->Draw();
hpzData->Draw("same");
cRatioVtx->cd(2);
TH1D*hRatio=(TH1D*)hpzData->Clone("hRatio");
hRatio->Divide(hpzMC);
hRatio->Draw();


TF1 *myfit = new TF1("myfit","[0]+[1]*x+x*x*[2]+x*x*x*[3]+x*x*x*x*[4]", -15, 15);  
hRatio->Fit("myfit","","",-15,15);
double par0=myfit->GetParameter(0);
double par1=myfit->GetParameter(1);
double par2=myfit->GetParameter(2);
double par3=myfit->GetParameter(3);
double par4=myfit->GetParameter(4);
std::cout<<"weight="<<par0<<"+PVz*("<<par1<<")+PVz*PVz*("<<par2<<")+PVz*PVz*PVz*("<<par3<<")+PVz*PVz*PVz*PVz*("<<par4<<")"<<endl;

}

void weightPPFONLLpthat(int minfit=2,int maxfit=100,TString pthat="pthatall")
{
  TString label;
  //TString selmcgen="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))";
  TString selmcgen="TMath::Abs(Gy)<2.4&&abs(GpdgId)==521&&GisSignal==1";
  TString myweightfunctiongen,myweightfunctionreco;
  
  //TCut weighpthat="pow(10,-0.075415*Gpt+1.748668+Gpt*Gpt*0.000388)+pow(10,-0.166406*Gpt+2.887856+Gpt*Gpt*0.000105) +0.003157";
  //TCut weighpthat="1";
  //TCut weighpthat="pthatweight*(pow(10,-0.107832+0.010248*Gpt+Gpt*Gpt*0.000079+Gpt*Gpt*Gpt*-0.000003+Gpt*Gpt*Gpt*Gpt*-0.000000+Gpt*Gpt*Gpt*Gpt*Gpt*0.000000))";//cross check
  TCut weighpthat="pthatweight";
  
  TCut weightCentrality="6.08582+hiBin*(-0.155739)+hiBin*hiBin*(0.00149946)+hiBin*hiBin*hiBin*(-6.41629e-06)+hiBin*hiBin*hiBin*hiBin*(1.02726e-08)";

  gStyle->SetOptTitle(1);
  //gStyle->SetOptStat(111111);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);

  gStyle->SetStatX(0.9);
  gStyle->SetStatY(0.9);
  gStyle->SetStatW(0.30);
  gStyle->SetStatH(0.04);
  gStyle->SetStatFontSize(0.03); 
  //TFile*infMC=new TFile("/data/HeavyFlavourRun2/MC2015/Bntuple/PbPb/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_PbPb_Pythia8_BuToJpsiK_Bpt0_Pthat5_TuneCUEP8M1_20160816_bPt5jpsiPt0tkPt0p8_Bp.root");
  TFile*infMC=new TFile("/data/HeavyFlavourRun2/MC2015/Bntuple/PbPb/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_PbPb_Pythia8_BuToJpsiK_TuneCUEP8M1_20160816_bPt5jpsiPt0tkPt0p8_Bp_pthatweight.root");
  TTree* ntGen = (TTree*)infMC->Get("ntGen");
  TTree *ntHiMC = (TTree*)infMC->Get("ntHi");
  ntGen->AddFriend(ntHiMC);
  
  TH1D* hPtGenFONLL = new TH1D("hPtGenFONLL","",nBinsReweight,ptBinsReweight);
  ntGen->Project("hPtGenFONLL","Gpt",(TCut(weighpthat)*TCut(selmcgen.Data())));
  //ntGen->Project("hPtGenFONLL","Gpt",(TCut(weighpthat)*TCut(weightCentrality)*TCut(selmcgen.Data())));
  divideBinWidth(hPtGenFONLL);
    
  TString fonll="ROOTfiles/fonllOutput_pp_Bplus_5p03TeV_y2p4.root";
  TFile* filePPReference = new TFile(fonll.Data());  
  TGraphAsymmErrors* gaeBplusReference = (TGraphAsymmErrors*)filePPReference->Get("gaeSigmaBplus");

  TH1D* hFONLL = new TH1D("hFONLL","",nBinsReweight,ptBinsReweight);
  double x,y;
  for(int i=0;i<nBinsReweight;i++){
    gaeBplusReference->GetPoint(i,x,y);
    hFONLL->SetBinContent(i+1,y);
  }
  TH1D* hFONLLOverPt=(TH1D*)hFONLL->Clone("hFONLLOverPt");
  TH1D* hFONLLOverPtWeight=(TH1D*)hFONLL->Clone("hFONLLOverPtWeight");
  
  hFONLL->Sumw2();
  hPtGenFONLL->Sumw2();
  hFONLLOverPt->Sumw2();
  hFONLL->Scale(1/hFONLL->Integral());
  hFONLLOverPt->Scale(1/hFONLLOverPt->Integral());
  hPtGenFONLL->Scale(1/hPtGenFONLL->Integral());
  hFONLLOverPt->Divide(hPtGenFONLL);
  
  //TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2])+pow(10,[3]*x*x+[4]*x*x*x+x*[5])", 2, 100);
  TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2]+x*x*x*[3]+x*x*x*x*[4]+x*x*x*x*x*[5])",0, 100);  
  //TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2]+x*x*x*[3])",0, 100);  
  //TF1 *myfit = new TF1("myfit","[0]+[1]*x+x*x*[2]+x*x*x*[3]+x*x*x*x*[4]+x*x*x*x*x*[5]",0, 100);  
   
  TCanvas*c1=new TCanvas("c1","c1",1000.,600.);
  c1->cd();
  gPad->SetLogy();
  gStyle->SetOptStat(111111111);
  hFONLLOverPt->Fit("myfit","","",minfit,maxfit);
  hFONLLOverPt->Fit("myfit","L m","",minfit,maxfit);
  TLegend* leg0 = myLegend(0.13,0.83,0.40,0.89);
  leg0->AddEntry(hFONLLOverPt,"Pythia8 MC_2015 B^{+}","");
  leg0->Draw();
  TLegend* leg1 = myLegend(0.15,0.75,0.40,0.88);
  leg1->AddEntry(hFONLLOverPt,"PbPb #sqrt{s}= 5.02 TeV","");
  leg1->Draw();

  double par0=myfit->GetParameter(0);
  double par1=myfit->GetParameter(1);
  double par2=myfit->GetParameter(2);
  double par3=myfit->GetParameter(3);
  double par4=myfit->GetParameter(4);
  double par5=myfit->GetParameter(5);
  //double par6=myfit->GetParameter(6);

  //myweightfunctiongen=Form("pow(10,%f*Gpt+%f+Gpt*Gpt*%f)+pow(10,%f*Gpt+%f+Gpt*Gpt*%f)",par0,par1,par2,par3,par4,par5);
  //myweightfunctiongen=Form("%f+%f*x+x*x*%f+x*x*x*%f+x*x*x*x*%f+x*x*x*x*x*%f",par0,par1,par2,par3,par4,par5);
  myweightfunctiongen=Form("pow(10,%f+%f*x+x*x*%f+x*x*x*%f+x*x*x*x*%f+x*x*x*x*x*%f)",par0,par1,par2,par3,par4,par5);
  std::cout<<"myweightfunctiongen="<<myweightfunctiongen<<std::endl;

  //myweightfunctionreco=Form("pow(10,%f*Gpt+%f+Gpt*Gpt*%f)+pow(10,%f*Gpt+%f+Gpt*Gpt*%f)",par0,par1,par2,par3,par4,par5);
  //std::cout<<"myweightfunctionreco="<<myweightfunctionreco<<std::endl;
  //std::cout<<"fit function parameters="<<weightfunctiongen<<std::endl;

  TCanvas*canvasPtReweight=new TCanvas("canvasPtReweight","canvasPtReweight_PbPb_MC_B+",1253.,494.); 
  canvasPtReweight->Divide(3,1);
  canvasPtReweight->cd(1);
  gPad->SetLogy();
  gPad->SetLeftMargin(0.15);
  hPtGenFONLL->SetXTitle("Gen p_{T}(GeV)");
  hPtGenFONLL->SetYTitle("PYTHIA, #entries");
  hPtGenFONLL->SetMinimum(1e-4);  
  hPtGenFONLL->SetMaximum(1e2);  
  hPtGenFONLL->GetYaxis()->SetTitleOffset(1.2);
  hPtGenFONLL->Draw();
  canvasPtReweight->cd(2);
  gPad->SetLogy();
  gPad->SetLeftMargin(0.15);
  hFONLL->SetXTitle("Gen, p_{T}(GeV)");
  hFONLL->SetYTitle("FONLL_PbPb, #entries");
  hFONLL->SetMinimum(1e-4);  
  hFONLL->SetMaximum(1e2);  
  hFONLL->GetYaxis()->SetTitleOffset(1.2);
  hFONLL->GetYaxis()->CenterTitle();
  hFONLL->GetXaxis()->CenterTitle();
  hFONLL->Draw();
  canvasPtReweight->cd(3);
  gPad->SetLogy();
  gPad->SetLeftMargin(0.15);
  hFONLLOverPt->SetXTitle("Gen p_{T}(GeV)");
  hFONLLOverPt->SetYTitle("FONLL_PbPb/PYTHIA ");
  hFONLLOverPt->SetMinimum(0.01);  
  hFONLLOverPt->SetMaximum(10.);  
  hFONLLOverPt->GetYaxis()->SetTitleOffset(1.2);
  hFONLLOverPt->GetYaxis()->CenterTitle();
  hFONLLOverPt->GetXaxis()->CenterTitle();
  hFONLLOverPt->Draw();
  canvasPtReweight->SaveAs("Reweightplots/canvasPtReweightPbPb.pdf");
}

void weightPbPbCentrality(){

//TFile*fMC=new TFile("/data/HeavyFlavourRun2/MC2015/Bntuple/PbPb/Bntuple20160606_Pythia8_BuToJpsiK_Bpt5p0_Pthat5.root");
TFile*fMC=new TFile("/data/HeavyFlavourRun2/MC2015/Bntuple/PbPb/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_PbPb_Pythia8_BuToJpsiK_TuneCUEP8M1_20160816_bPt5jpsiPt0tkPt0p8_Bp_pthatweight_JingBDT.root");
//TFile*fMC=new TFile("/data/HeavyFlavourRun2/MC2015/Bntuple/PbPb/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_PbPb_Pythia8_BuToJpsiK_Bpt0_Pthat5_TuneCUEP8M1_20160816_bPt5jpsiPt0tkPt0p8_Bp_JingBDT.root");
TTree *ntDkpiMC = (TTree*)fMC->Get("ntKp");
TTree *ntSkimMC = (TTree*)fMC->Get("ntSkim");
TTree *ntHiMC = (TTree*)fMC->Get("ntHi");
TTree *ntHltMC = (TTree*)fMC->Get("ntHlt");
ntDkpiMC->AddFriend(ntSkimMC);
ntDkpiMC->AddFriend(ntHiMC);
ntDkpiMC->AddFriend(ntHltMC);

//TFile*fData=new TFile("/data/HeavyFlavourRun2/Data2015/Bntuple/Bntuple20160610_crab_BfinderData_PbPb_20160607_bPt5jpsiPt0tkPt0p8_Bp.root");
TFile*fData=new TFile("/data/HeavyFlavourRun2/Data2015/Bntuple/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderData_PbPb_20160816_bPt5jpsiPt0tkPt0p8_Bp_JingBDT.root");
TTree *ntDkpiData = (TTree*)fData->Get("ntKp");
TTree *ntSkimData = (TTree*)fData->Get("ntSkim");
TTree *ntHiData = (TTree*)fData->Get("ntHi");
TTree *ntHltData = (TTree*)fData->Get("ntHlt");
ntDkpiData->AddFriend(ntSkimData);
ntDkpiData->AddFriend(ntHiData);
ntDkpiData->AddFriend(ntHltData);

TH1F*hCenData=new TH1F("hCenData","hCenData",200,0,200);
TH1F*hCenMC=new TH1F("hCenMC","hCenMC",200,0,200);

//TCut weighpthat="6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09)";
TCut weighpthat="1";
//TCut weighpthat="pthatweight";
TString cut="abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3";
TString hlt="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)";

//ntDkpiMC->Project("hCenMC","hiBin",TCut(weighpthat)*(TCut(cut.Data())));
ntDkpiMC->Project("hCenMC","hiBin",TCut(weighpthat)*TCut(cut.Data())*TCut(hlt.Data()));
ntDkpiData->Project("hCenData","hiBin",(TCut(cut.Data())*TCut(hlt.Data())));

hCenMC->Scale(1./hCenMC->Integral(hCenMC->FindBin(0.),hCenMC->FindBin(200)));
hCenData->Scale(1./hCenData->Integral(hCenMC->FindBin(0.),hCenMC->FindBin(200)));

TH2F* hempty1=new TH2F("hempty1","",50,0.,200.,10,0,0.05);  
hempty1->GetXaxis()->CenterTitle();
hempty1->GetYaxis()->CenterTitle();
hempty1->GetYaxis()->SetTitle("Entries");
hempty1->GetXaxis()->SetTitle("Centrality (HiBin)");
hempty1->GetXaxis()->SetTitleOffset(0.9);
hempty1->GetYaxis()->SetTitleOffset(1.5);
hempty1->GetXaxis()->SetTitleSize(0.05);
hempty1->GetYaxis()->SetTitleSize(0.05);
hempty1->GetXaxis()->SetTitleFont(42);
hempty1->GetYaxis()->SetTitleFont(42);
hempty1->GetXaxis()->SetLabelFont(42);
hempty1->GetYaxis()->SetLabelFont(42);
hempty1->GetXaxis()->SetLabelSize(0.035);
hempty1->GetYaxis()->SetLabelSize(0.035);  

TH2F* hempty2=new TH2F("hempty2","",50,0.,200.,10,0,10);  
hempty2->GetXaxis()->CenterTitle();
hempty2->GetYaxis()->CenterTitle();
hempty2->GetYaxis()->SetTitle("Ratio Data/MC");
hempty2->GetXaxis()->SetTitle("Centrality (HiBin)");
hempty2->GetXaxis()->SetTitleOffset(0.9);
hempty2->GetYaxis()->SetTitleOffset(1.5);
hempty2->GetXaxis()->SetTitleSize(0.05);
hempty2->GetYaxis()->SetTitleSize(0.05);
hempty2->GetXaxis()->SetTitleFont(42);
hempty2->GetYaxis()->SetTitleFont(42);
hempty2->GetXaxis()->SetLabelFont(42);
hempty2->GetYaxis()->SetLabelFont(42);
hempty2->GetXaxis()->SetLabelSize(0.035);
hempty2->GetYaxis()->SetLabelSize(0.035);  

TLegend *legendSigma=new TLegend(0.5100806,0.5168644,0.8084677,0.6605932,"");
legendSigma->SetBorderSize(0);
legendSigma->SetLineColor(0);
legendSigma->SetFillColor(0);
legendSigma->SetFillStyle(1001);
legendSigma->SetTextFont(42);
legendSigma->SetTextSize(0.045);

TLegendEntry *ent_SigmaPP=legendSigma->AddEntry(hCenMC,"Monte Carlo.","pf");
ent_SigmaPP->SetTextFont(42);
ent_SigmaPP->SetLineColor(2);
ent_SigmaPP->SetMarkerColor(2);
ent_SigmaPP->SetTextSize(0.03);

TLegendEntry *ent_Sigmapp=legendSigma->AddEntry(hCenData,"Data","f");
ent_Sigmapp->SetTextFont(42);
ent_Sigmapp->SetLineColor(1);
ent_Sigmapp->SetMarkerColor(1);
ent_Sigmapp->SetTextSize(0.03);

TCanvas*canvas=new TCanvas("canvas","canvas",1000,500);
canvas->Divide(2,1);
canvas->cd(1);
hempty1->Draw();
hCenMC->SetLineColor(2);
hCenMC->SetMarkerColor(2);
hCenMC->Draw("same");
hCenData->Draw("same");
legendSigma->Draw();
canvas->cd(2);
TH1D*hRatio=(TH1D*)hCenData->Clone("hRatio");
hRatio->Divide(hCenMC);
hempty2->Draw();
hRatio->Draw("same");

TF1 *myfit = new TF1("myfit","[0]+[1]*x+x*x*[2]+x*x*x*[3]+x*x*x*x*[4]", 0, 200);  
hRatio->Fit("myfit","","",0, 200);
double par0=myfit->GetParameter(0);
double par1=myfit->GetParameter(1);
double par2=myfit->GetParameter(2);
double par3=myfit->GetParameter(3);
double par4=myfit->GetParameter(4);

TString myweight;
std::cout<<"weight="<<par0<<"+hiBin*("<<par1<<")+hiBin*hiBin*("<<par2<<")+hiBin*hiBin*hiBin*("<<par3<<")"<<"+hiBin*hiBin*hiBin*hiBin*("<<par4<<")"<<endl;
canvas->SaveAs("Reweightplots/CentralityWeight.pdf");
}
