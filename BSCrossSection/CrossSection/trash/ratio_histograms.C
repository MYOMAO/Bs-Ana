/**
This Macro gets two histogram and makes ratio plot.
CDozen. 
*/

void ratio_histograms(int minfit=2,int maxfit=100){
    /// step1-) open your root files..
bool PbPb=false;

  
  gROOT->ForceStyle();
  gStyle->SetOptTitle(1);
  gStyle->SetOptStat(111111);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);
  gStyle->SetOptFit(1);
  
  gStyle->SetStatX(0.9);
  gStyle->SetStatY(0.9);
  gStyle->SetStatW(0.19);
  gStyle->SetStatH(0.10);
  gStyle->SetStatFontSize(0.02);

TString filename1,filename2;
TString hist1name,hist2name,hist3name;
TString pdfname1,pdfname2,pdfname3;
TString mytext;

if(PbPb){
filename1= "/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/ROOTfiles/MCstudiesPbPb_weighted.root";
filename2="/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/ROOTfiles/MCstudiesPbPb.root";
hist1name="PbPb_efficiency";
hist2name="PbPb_ratio";
hist3name="PbPb_fit";
pdfname1="/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/WeightNoWeightPlots/plot_PbPb_efficiency_weight_noweight.pdf";
pdfname2="/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/WeightNoWeightPlots/plot_PbPb_ratio_eff.pdf";
pdfname3="/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/WeightNoWeightPlots/plot_PbPb_fit_ratio_eff.pdf";
mytext="B+ PbPb #sqrt{s}= 5.02 TeV";
}else
{
 filename1= "/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/ROOTfiles/MCstudiesPP_weighted.root";
 filename2="/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/ROOTfiles/MCstudiesPP.root"; 
 hist1name="PP_efficiency";
 hist2name="PP_ratio";
 hist3name="PP_fit";
pdfname1="/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/WeightNoWeightPlots/plot_pp_efficiency_weight_noweight.pdf";
pdfname2="/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/WeightNoWeightPlots/plot_pp_ratio_eff.pdf";
pdfname3="/afs/cern.ch/work/c/cdozen/BRUNII/CMSSW_7_5_5_patch4/src/BntupleRunII/CrossSection/WeightNoWeightPlots/plot_pp_fit_ratio_eff.pdf";
mytext="B+ pp #sqrt{s}= 5.02 TeV";
}


    TFile*  f1 = new TFile(filename1);
    TFile*  f2 = new TFile(filename2);

    ///Step2-) get your histograms..
    TH1F * h1 = (TH1F*)f1->Get("hEff"); //get your histogram from the first file
    TH1F * h2 = (TH1F*)f2->Get("hEff"); //get your histogram from the second file
    h1->Sumw2(); ///calculate sum of weights
    h2->Sumw2();
   
   ///Step3-) clone your firts histogram
   TH1F *h3 = (TH1F*)h1->Clone("h3");
   h3->Sumw2();
 ///Step4-) Divide 3rd histogram with seconde one
   h3->Divide(h2);

   TH1F* h4 = (TH1F*)h3->Clone("h4");

   //TF1 *myfit = new TF1("myfit","pow(10,[0]*x+[1]+x*x*[2])+pow(10,[3]*x+[4]+x*x*[5])", 10, 50);
   //TF1 *myfit = new TF1("myfit","[0]*x+[1]+x*x*[2]+x*x*x*[3]+x*x*x*x*[4]+x*x*x*x*x*[5]+x*x*x*x*x*x*[6]", 2, 100);
   TF1 *myfit = new TF1("myfit","pow(10,[0]+[1]*x+x*x*[2])+pow(10,[3]*x*x+[4]*x*x*x+[5])", 2, 100);   
   TCanvas*cFit=new TCanvas("Fit","Fit on Efficiency Ratio",800.,500.);
   cFit->cd();
   h4->Fit("myfit","","",minfit,maxfit);
   h4->SetName(hist3name);
   //h4->SetName("pp Efficiency pT weigt/no_weight");
   h4->GetYaxis()->SetTitleOffset(1.2);
   h4->SetXTitle("Gen p_{T}(GeV)");
   h4->SetYTitle("Efficiency p_{T} weight / no weight");
   h4->SetMinimum(0);
   h4->SetMaximum(2.5);
   
   TLatex l1;
   l1.DrawLatex(15,2,mytext);

   cFit->Print(pdfname3);

   ///Step5-) Define your canvas
   ///5a-) our histograms 
   TCanvas *c1= new TCanvas("Efficiency vs Gen pT","Efficiency vs Gen pT",800,600);
   c1->Divide(2,1);
   c1->cd(1);
   //gPad->SetLogy();
   h1->SetName(hist1name);
   //h1->SetName("pp Eff.pT weight");
   h1->SetXTitle("Gen p_{T}(GeV)");
   h1->SetYTitle("Efficiency p_{T} weight");
   h1->GetYaxis()->SetTitleOffset(1.4);
   //h1->SetMinimum(0);
   h1->SetMaximum(0.4);
   h1->Draw();
   c1->cd(2);
   //gPad->SetLogy();
   h2->SetName(hist1name);
   //h2->SetName("pp Eff.pT unweight");
   h2->SetXTitle("Gen p_{T}(GeV)");
   h2->SetYTitle("Efficiency p_{T} no_weight");
   h2->GetYaxis()->SetTitleOffset(1.4);
   //h2->SetMinimum(0);
   h2->SetMaximum(0.4);
   h2->Draw();
   c1->Print(pdfname1);
   ///5b-) Ratio of two histograms.
   TCanvas *c2= new TCanvas("Ratio Histogram","Ratio Efficiency weight/no_weight",800,600);
   c2->cd(1);
   h3->SetName(hist2name);
   //h3->SetName("pp Efficiency pT weight/no_weight ");
   h3->SetXTitle("Gen p_{T}(GeV)");
   h3->SetYTitle("Efficiency p_{T} weight/no_weight");
   h3->GetYaxis()->SetTitleOffset(1.4);
   //h3->SetMinimum(0);
   h3->SetMaximum(1.4);
   h3->Draw();
   c2->Print(pdfname2);

}
