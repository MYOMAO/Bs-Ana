#include "uti.h"
#include "parameters.h"

Double_t setparam0=100.;
Double_t setparam1=1.865;
Double_t setparam2=0.03;
Double_t setparam10=0.005;
Double_t setparam8=0.1;
Double_t setparam9=0.1;
Double_t fixparam1=1.865;
Double_t minhisto=	1.7;
Double_t maxhisto=2.0;
Double_t nbinsmasshisto=60;
Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weightfunctiongen = "1";
TString weightfunctionreco = "1";
Float_t hiBinMin,hiBinMax,centMin,centMax;

int _nBins = nBinsY;
double *_ptBins = ptBinsY;

void MCefficiencyY(int isPbPb=0,TString inputmc="/data/wangj/MC2015/Dntuple/pp/revised/ntD_pp_Dzero_kpi_prompt/ntD_EvtBase_20160303_Dfinder_20160302_pp_Pythia8_prompt_D0_dPt0tkPt0p5_pthatweight.root", TString selmcgen="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))",TString selmcgenacceptance="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))&&abs(Gtk1eta)<2.0&&abs(Gtk2eta)<2.0&&Gtk1pt>2.0&&Gtk2pt>2.0", TString cut_recoonly="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>2.0&&Dtrk2Pt>2.0&&Dtrk1PtErr/Dtrk1Pt<0.1&&Dtrk2PtErr/Dtrk2Pt<0.1&&abs(Dtrk1Eta)<2.0&&abs(Dtrk2Eta)<2.0&&Dtrk1Algo>3&&Dtrk1Algo<8&&(Dtrk1PixelHit+Dtrk1StripHit)>=11", TString cut="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>2.0&&Dtrk2Pt>2.0&&(DsvpvDistance/DsvpvDisErr)>3.5&&(DlxyBS/DlxyBSErr)>1.5&&Dchi2cl>0.05&&Dalpha<0.12&&Dtrk1PtErr/Dtrk1Pt<0.1&&Dtrk2PtErr/Dtrk2Pt<0.1&&abs(Dtrk1Eta)<2.0&&abs(Dtrk2Eta)<2.0&&Dtrk1Algo>3&&Dtrk1Algo<8&&Dtrk2Algo>3&&Dtrk2Algo<8&&(Dtrk1PixelHit+Dtrk1StripHit)>=11&&(Dtrk1Chi2ndf/(Dtrk1nStripLayer+Dtrk1nPixelLayer)<0.15)&&(Dtrk2Chi2ndf/(Dtrk2nStripLayer+Dtrk2nPixelLayer)<0.15)",TString label="PP",TString outputfile="test", int useweight=1,Float_t centmin=0., Float_t centmax=100.)
{ 
  if(label=="ppInc"){
    _nBins = nBinsInc;
    _ptBins = ptBinsInc;
  }
  
  std::string str = label.Data();
  std::size_t found = str.find("Fine");
  //if(label=="ppFine"||label=="PbPbFine"){
  if (found!=std::string::npos){
    _nBins = nBinsFine;
    _ptBins = ptBinsFine;
  }

  hiBinMin = centmin*2;
  hiBinMax = centmax*2;
  centMin = centmin;
  centMax = centmax;
  
  if(isPbPb==1)
    {
      selmcgen = selmcgen+Form("&&hiBin>=%f&&hiBin<=%f",hiBinMin,hiBinMax);
      selmcgenacceptance=selmcgenacceptance+Form("&&hiBin>=%f&&hiBin<=%f",hiBinMin,hiBinMax);
      cut_recoonly=cut_recoonly+Form("&&hiBin>=%f&&hiBin<=%f",hiBinMin,hiBinMax);
      cut=cut+Form("&&hiBin>=%f&&hiBin<=%f",hiBinMin,hiBinMax);
    }

     std::cout<<"selmcgen="<<selmcgen<<std::endl;
     std::cout<<"selmcgenacceptance="<<selmcgenacceptance<<std::endl;
     std::cout<<"cut_recoonly"<<cut_recoonly<<std::endl;
     std::cout<<"cut="<<cut<<std::endl;

   std::cout<<"option="<<useweight<<std::endl;
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);
 
  TFile* infMC = new TFile(inputmc.Data());
  TTree* ntMC = (TTree*)infMC->Get("ntKp");
  TTree* ntGen = (TTree*)infMC->Get("ntGen");
  TTree* ntSkim = (TTree*)infMC->Get("ntSkim");
  TTree* ntmvaTree = (TTree*)infMC->Get("mvaTree");
  TTree* ntHlt = (TTree*)infMC->Get("ntHlt");

  ntMC->AddFriend(ntmvaTree);
  ntMC->AddFriend(ntGen);
  ntMC->AddFriend(ntSkim);
  ntMC->AddFriend(ntHlt);

  TTree* nthi = (TTree*)infMC->Get("ntHi");
  ntGen->AddFriend(nthi);
  ntGen->AddFriend(ntSkim);
  ntGen->AddFriend(ntHlt);
  nthi->AddFriend(ntMC);
  ntMC->AddFriend(nthi);

  // optimal weigths
  TCut weighpthat = "1";
  TCut weightGpt = "1";
  TCut weightBgenpt = "1";
  TCut weightHiBin = "1";
  if(useweight==0) {
    weightfunctiongen="1";
    weightfunctionreco="1";
    weighpthat = "pthatweight";
    weightGpt = "(pow(10,-0.094152+0.008102*Gpt+Gpt*Gpt*0.000171+Gpt*Gpt*Gpt*-0.000005+Gpt*Gpt*Gpt*Gpt*-0.000000+Gpt*Gpt*Gpt*Gpt*Gpt*0.000000))";
    weightBgenpt = "(pow(10,-0.094152+0.008102*Bgenpt+Bgenpt*Bgenpt*0.000171+Bgenpt*Bgenpt*Bgenpt*-0.000005+Bgenpt*Bgenpt*Bgenpt*Bgenpt*-0.000000+Bgenpt*Bgenpt*Bgenpt*Bgenpt*Bgenpt*0.000000))";
    }
  
  if(useweight==1) {
    weightfunctiongen="6.08582+hiBin*(-0.155739)+hiBin*hiBin*(0.00149946)+hiBin*hiBin*hiBin*(-6.41629e-06)+hiBin*hiBin*hiBin*hiBin*(1.02726e-08)";
    weightfunctionreco="6.08582+hiBin*(-0.155739)+hiBin*hiBin*(0.00149946)+hiBin*hiBin*hiBin*(-6.41629e-06)+hiBin*hiBin*hiBin*hiBin*(1.02726e-08)";
    weighpthat = "pthatweight";
    weightGpt = "(pow(10,-0.107832+0.010248*Gpt+Gpt*Gpt*0.000079+Gpt*Gpt*Gpt*-0.000003+Gpt*Gpt*Gpt*Gpt*-0.000000+Gpt*Gpt*Gpt*Gpt*Gpt*0.000000))";
    weightBgenpt = "(pow(10,-0.107832+0.010248*Bgenpt+Bgenpt*Bgenpt*0.000079+Bgenpt*Bgenpt*Bgenpt*-0.000003+Bgenpt*Bgenpt*Bgenpt*Bgenpt*-0.000000+Bgenpt*Bgenpt*Bgenpt*Bgenpt*Bgenpt*0.000000))";
    weightHiBin = "(6.08582+hiBin*(-0.155739)+hiBin*hiBin*(0.00149946)+hiBin*hiBin*hiBin*(-6.41629e-06)+hiBin*hiBin*hiBin*hiBin*(1.02726e-08))";
    }

  std::cout<<"fit function parameters="<<weightfunctiongen<<std::endl;

  TH1D* hPtMC = new TH1D("hPtMC","",_nBins,_ptBins);
  TH1D* hPtMCrecoonly = new TH1D("hPtMCrecoonly","",_nBins,_ptBins);
  TH1D* hPtGen = new TH1D("hPtGen","",_nBins,_ptBins);
  TH1D* hPtGenAcc = new TH1D("hPtGenAcc","",_nBins,_ptBins);
  TH1D* hPtGenAccWeighted = new TH1D("hPtGenAccWeighted","",_nBins,_ptBins);
  TH1D* hPthat = new TH1D("hPthat","",100,0,500);
  TH1D* hPthatweight = new TH1D("hPthatweight","",100,0,500);

  //ntMC->Project("hPtMC","abs(By)",TCut(weightfunctionreco)*(TCut(cut.Data())&&"(Bgen==23333)"));
  ntMC->Project("hPtMC","abs(By)",TCut(weighpthat)*TCut(weightBgenpt)*TCut(weightHiBin)*(TCut(cut.Data())&&"(Bgen==23333)"));
  divideBinWidth(hPtMC);
  //ntMC->Project("hPtMCrecoonly","abs(By)",TCut(weightfunctionreco)*(TCut(cut_recoonly.Data())&&"(Bgen==23333)"));
  ntMC->Project("hPtMCrecoonly","abs(By)",TCut(weighpthat)*TCut(weightBgenpt)*TCut(weightHiBin)*(TCut(cut_recoonly.Data())&&"(Bgen==23333)"));
  divideBinWidth(hPtMCrecoonly);
  //ntGen->Project("hPtGen","Gy",(TCut(selmcgen.Data())));
  ntGen->Project("hPtGen","Gy",TCut(weighpthat)*TCut(weightGpt)*(TCut(selmcgen.Data())));
  divideBinWidth(hPtGen);
  //ntGen->Project("hPtGenAcc","Gy",(TCut(selmcgenacceptance.Data())));
  ntGen->Project("hPtGenAcc","Gy",TCut(weighpthat)*TCut(weightGpt)*(TCut(selmcgenacceptance.Data())));
  divideBinWidth(hPtGenAcc);
  //ntGen->Project("hPtGenAccWeighted","Gy",TCut(weightfunctiongen)*(TCut(selmcgenacceptance.Data())));
  ntGen->Project("hPtGenAccWeighted","Gy",TCut(weighpthat)*TCut(weightGpt)*TCut(weightHiBin)*(TCut(selmcgenacceptance.Data())));
  divideBinWidth(hPtGenAccWeighted);

  ntMC->Project("hPthat","pthat","1");
  ntMC->Project("hPthatweight","pthat",TCut("1"));

  hPtMC->Sumw2();
  hPtGenAcc->Sumw2();
  hPtMCrecoonly->Sumw2();
  //Acceptance
  TH1D* hEffAcc = (TH1D*)hPtGenAcc->Clone("hEffAcc");
  hEffAcc->Sumw2();
  hEffAcc->Divide(hEffAcc,hPtGen,1,1,"b");
  //Selection
  TH1D* hEffSelection = (TH1D*)hPtMC->Clone("hEffSelection");
  hEffSelection->Sumw2();
  hEffSelection->Divide(hEffSelection,hPtGenAccWeighted,1,1,"b");
  //Acc * Eff (one shot)
  TH1D* hEffReco = (TH1D*)hPtMCrecoonly->Clone("hEffReco");
  hEffReco->Sumw2();
  hEffReco->Divide(hEffReco,hPtGen,1,1,"b");
  //Acc * Eff
  TH1D* hEff = (TH1D*)hEffSelection->Clone("hEff");
  hEff->Sumw2();
  //hEff->Divide(hPtMC,hPtGen,1,1,"");
  hEff->Multiply(hEff,hEffAcc,1,1);

  TH2F* hemptyEff=new TH2F("hemptyEff","",50,_ptBins[0]-1.,_ptBins[_nBins]+1.,10.,0,0.6);  
  hemptyEff->GetXaxis()->CenterTitle();
  hemptyEff->GetYaxis()->CenterTitle();
  //hemptyEff->GetYaxis()->SetTitle("acceptance x #epsilon_{reco} x #epsilon_{sel} ");
  hemptyEff->GetYaxis()->SetTitle("#alpha x #epsilon");
  hemptyEff->GetXaxis()->SetTitle("|y|");
  hemptyEff->GetXaxis()->SetTitleOffset(0.9);
  hemptyEff->GetYaxis()->SetTitleOffset(0.95);
  hemptyEff->GetXaxis()->SetTitleSize(0.05);
  hemptyEff->GetYaxis()->SetTitleSize(0.05);
  hemptyEff->GetXaxis()->SetTitleFont(42);
  hemptyEff->GetYaxis()->SetTitleFont(42);
  hemptyEff->GetXaxis()->SetLabelFont(42);
  hemptyEff->GetYaxis()->SetLabelFont(42);
  hemptyEff->GetXaxis()->SetLabelSize(0.035);
  hemptyEff->GetYaxis()->SetLabelSize(0.035);  
  hemptyEff->SetMaximum(1.0);
  hemptyEff->SetMinimum(0.);
  hemptyEff->Draw();

  TH2F* hemptyEffAcc=(TH2F*)hemptyEff->Clone("hemptyEffAcc");
  TH2F* hemptyEffReco=(TH2F*)hemptyEff->Clone("hemptyEffReco");
  TH2F* hemptyEffSelection=(TH2F*)hemptyEff->Clone("hemptyEffSelection");
 

  TCanvas*canvasEff=new TCanvas("canvasEff","canvasEff",1000.,500);
  canvasEff->Divide(2,1);
  canvasEff->cd(1);
  
  hemptyEffAcc->SetYTitle("#alpha");
  hemptyEffAcc->Draw();
  hEffAcc->Draw("same");
  canvasEff->cd(2);
  hemptyEff->Draw();
  hEff->Draw("same");
  canvasEff->SaveAs(Form("plotEffY/canvasEff_study%s.pdf",Form(label.Data())));
  
  TH2F* hemptyPthat=new TH2F("hemptyPthat","",50,0.,500.,10,1e-5,1e9);  
  hemptyPthat->GetXaxis()->CenterTitle();
  hemptyPthat->GetYaxis()->CenterTitle();
  hemptyPthat->GetYaxis()->SetTitle("Entries");
  hemptyPthat->GetXaxis()->SetTitle("pthat");
  hemptyPthat->GetXaxis()->SetTitleOffset(0.9);
  hemptyPthat->GetYaxis()->SetTitleOffset(0.95);
  hemptyPthat->GetXaxis()->SetTitleSize(0.05);
  hemptyPthat->GetYaxis()->SetTitleSize(0.05);
  hemptyPthat->GetXaxis()->SetTitleFont(42);
  hemptyPthat->GetYaxis()->SetTitleFont(42);
  hemptyPthat->GetXaxis()->SetLabelFont(42);
  hemptyPthat->GetYaxis()->SetLabelFont(42);
  hemptyPthat->GetXaxis()->SetLabelSize(0.035);
  hemptyPthat->GetYaxis()->SetLabelSize(0.035);  
  hemptyPthat->SetMaximum(1.0);
  hemptyPthat->SetMinimum(0.);


  TH2F* hemptySpectra=new TH2F("hemptySpectra","",50,0.,130.,10,1,1e5);  
  hemptySpectra->GetXaxis()->CenterTitle();
  hemptySpectra->GetYaxis()->CenterTitle();
  hemptySpectra->GetYaxis()->SetTitle("Entries");
  hemptySpectra->GetXaxis()->SetTitle("|y|");
  hemptySpectra->GetXaxis()->SetTitleOffset(0.9);
  hemptySpectra->GetYaxis()->SetTitleOffset(0.95);
  hemptySpectra->GetXaxis()->SetTitleSize(0.05);
  hemptySpectra->GetYaxis()->SetTitleSize(0.05);
  hemptySpectra->GetXaxis()->SetTitleFont(42);
  hemptySpectra->GetYaxis()->SetTitleFont(42);
  hemptySpectra->GetXaxis()->SetLabelFont(42);
  hemptySpectra->GetYaxis()->SetLabelFont(42);
  hemptySpectra->GetXaxis()->SetLabelSize(0.035);
  hemptySpectra->GetYaxis()->SetLabelSize(0.035);  

  TH2F* hemptyPthatWeighted=(TH2F*)hemptyPthat->Clone("hemptyPthatWeighted");
  hemptyPthatWeighted->GetXaxis()->SetTitle("pthat reweighted");
  
  TCanvas*canvasPthat=new TCanvas("canvasPthat","canvasPthat",1000.,500);
  canvasPthat->Divide(2,1);
  canvasPthat->cd(1);
  gPad->SetLogy();
  hemptyPthat->Draw("same");
  hPthat->Draw("same");
  canvasPthat->cd(2);
  gPad->SetLogy();
  hemptyPthatWeighted->Draw();
  hPthatweight->Draw("same");
  canvasPthat->SaveAs(Form("plotEffY/canvasPthat_%s.pdf",Form(label.Data())));
  
  TCanvas*canvasSpectra=new TCanvas("canvasSpectra","canvasSpectra",1000.,500);
  canvasSpectra->Divide(2,1);
  canvasSpectra->cd(1);
  gPad->SetLogy();
  hemptySpectra->Draw();
  hPtMC->Draw("same");
  canvasSpectra->cd(2);
  gPad->SetLogy();
  hemptySpectra->Draw();
  hPtGen->Draw("same");
  canvasSpectra->SaveAs(Form("plotEffY/canvasSpectra_%s.pdf",Form(label.Data())));

  //### 1D histogram
  //hEff = hPtMC / hPtGen
  //hEffReco = hPtMCrecoonly / hPtGen
  //hEffAcc = hPtGenAcc / hPtGen
  //hEffSelection = hPtMC / hPtMCrecoonly
 
/*
  ntMC->Project("hPtMC","abs(By)",TCut(weightfunctionreco)*(TCut(cut.Data())&&"(Bgen==23333)"));
  ntMC->Project("hPtMCrecoonly","abs(By)",TCut(weightfunctionreco)*(TCut(cut_recoonly.Data())&&"(Bgen==23333)"));
  ntGen->Project("hPtGen","Gy",TCut(weightfunctiongen)*(TCut(selmcgen.Data())));
  ntGen->Project("hPtGenAcc","Gy",TCut(weightfunctiongen)*(TCut(selmcgenacceptance.Data())));
*/  
  TString text;
  if (isPbPb) { text="350.68 #mub^{-1} (5.02 TeV PbPb)";}
  else {text="25.8 pb^{-1} (5.02 TeV pp)";}
  TLatex* texlumi = new TLatex(0.9,0.92,text.Data());
  texlumi->SetNDC();
  texlumi->SetTextAlign(31);
  texlumi->SetTextFont(42);
  texlumi->SetTextSize(0.038);
  texlumi->SetLineWidth(2);

  TString texper="%";
  TLatex* texCent = new TLatex(0.5,0.815,Form("Centrality %.0f - %.0f%s",centMin,centMax,texper.Data()));
  texCent->SetNDC();
  texCent->SetTextFont(42);
  texCent->SetTextSize(0.05);

  TLatex* texY = new TLatex(0.5,0.750,Form("%.0f < p_{T} < %.0f (GeV/c)",ptBinsInc[0], ptBinsInc[1]));
  texY->SetNDC();
  texY->SetTextFont(42);
  texY->SetTextSize(0.05);
  texY->SetLineWidth(2);

  TLatex* texCms = new TLatex(0.08,0.95, "CMS Preliminary");
  texCms->SetNDC();
  texCms->SetTextAlign(13);
  texCms->SetTextSize(0.038);
  texCms->SetTextFont(62);

  TCanvas*canvas1D=new TCanvas("canvas1D","",600,600);
  canvas1D->cd();
  gPad->SetLogy(0);
  //hemptyEff->SetYTitle("hPtMC / hPtGen");
  hemptyEff->SetMaximum(0.6);
  hemptyEff->SetYTitle("#alpha x #epsilon");
  hemptyEff->GetXaxis()->SetTitle("|y|");
  hemptyEff->Draw();
  hEff->SetLineColor(2);
  hEff->SetMarkerColor(2);
  hEff->Draw("same");
  if(isPbPb) texCent->Draw();
  texY->Draw();
  texCms->Draw();
  texlumi->Draw();
  canvas1D->SaveAs(Form("plotEffY/canvas1DhEff_%s.pdf",Form(label.Data())));
  canvas1D->SaveAs(Form("plotEffY/canvas1DhEff_%s.C",Form(label.Data())));
  canvas1D->Clear();

  canvas1D=new TCanvas("canvas1D","",600,600);
  canvas1D->cd();
  gPad->SetLogy();
  hemptySpectra->SetYTitle("Entries of hPtMC");
  hemptySpectra->Draw(); 
  hPtMC->Draw("same");
  canvas1D->SaveAs(Form("plotEffY/canvas1DhPtMC_%s.pdf",Form(label.Data())));
  canvas1D->Clear();

  canvas1D=new TCanvas("canvas1D","",600,600);
  canvas1D->cd();
  gPad->SetLogy();
  hemptySpectra->SetYTitle("Entries of hPtMCrecoonly");
  hemptySpectra->Draw(); 
  hPtMCrecoonly->Draw("same");
  canvas1D->SaveAs(Form("plotEffY/canvas1DhPtMCrecoonly_%s.pdf",Form(label.Data())));
  canvas1D->Clear();

  canvas1D=new TCanvas("canvas1D","",600,600);
  canvas1D->cd();
  gPad->SetLogy();
  hemptySpectra->SetYTitle("Entries of hPtGen");
  hemptySpectra->Draw(); 
  hPtGen->Draw("same");
  canvas1D->SaveAs(Form("plotEffY/canvas1DhPtGen_%s.pdf",Form(label.Data())));
  canvas1D->Clear();

  canvas1D=new TCanvas("canvas1D","",600,600);
  canvas1D->cd();
  gPad->SetLogy();
  hemptySpectra->SetYTitle("Entries of hPtGenAcc");
  hemptySpectra->Draw(); 
  hPtGenAcc->Draw("same");
  canvas1D->SaveAs(Form("plotEffY/canvas1DhPtGenAcc_%s.pdf",Form(label.Data())));
  canvas1D->Clear();

  canvas1D=new TCanvas("canvas1D","",600,600);
  canvas1D->cd();
  hemptyEff->SetYTitle("hPtMCrecoonly / hPtGen");
  hemptyEff->Draw(); 
  hEffReco->Draw("same");
  canvas1D->SaveAs(Form("plotEffY/canvas1DhEffReco_%s.pdf",Form(label.Data())));
  canvas1D->Clear();

  canvas1D=new TCanvas("canvas1D","",600,600);
  canvas1D->cd();
  hemptyEff->SetYTitle("hPtGenAcc / hPtGen");
  hemptyEff->Draw(); 
  hEffAcc->Draw("same");
  canvas1D->SaveAs(Form("plotEffY/canvas1DhEffAcc_%s.pdf",Form(label.Data())));
  canvas1D->Clear();

  canvas1D=new TCanvas("canvas1D","",600,600);
  canvas1D->cd();
  hemptyEff->SetYTitle("hPtMC / hPtGenAcc");
  hemptyEff->Draw(); 
  hEffSelection->Draw("same");
  canvas1D->SaveAs(Form("plotEffY/canvas1DhEffSelection_%s.pdf",Form(label.Data())));
  canvas1D->Clear();


  gStyle->SetPalette(55);
  TCanvas* canvas2D=new TCanvas("canvas2D","",600,600);

  TFile *fout=new TFile(outputfile.Data(),"recreate");
  fout->cd();
  hPtGen->Write();
  hEffAcc->Write();
  hEffReco->Write();
  hEffSelection->Write();
  hEff->Write();
  hPtMC->Write();
  fout->Close();  

}

int main(int argc, char *argv[])
{
  if((argc !=12))
  {
    std::cout << "Wrong number of inputs" << std::endl;
    return 1;
  }
  
  if(argc == 12)
    MCefficiencyY(atoi(argv[1]),argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],atoi(argv[9]),atof(argv[10]),atof(argv[11]));
  return 0;
}




