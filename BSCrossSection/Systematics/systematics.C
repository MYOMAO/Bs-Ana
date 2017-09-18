#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TLine.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TFile.h>


// Yen-Jie: systematics table for B meson
// Unit: In percentage
const int nPtBins=1;
double PtBins[nPtBins+1] = {7.,50.};//add a margin so that "FindBin" can work at the bin end
const int AnaBins=5;
double AnaPtBins[AnaBins+1] = {7.,10.,15.,20.,30.,50.};

const int nCentBins=4;
double CentBins[nCentBins+1] = {0.,10.,30.,50.,100.};

// =============================================================================================================
// D meson decay
// =============================================================================================================
double BtomumuKBRUncertainty  = 3.07;     // from PDG
// =============================================================================================================
// pp uncertainty
// =============================================================================================================

// Normalization uncertainty
double ppLumiUncertainty  = 12;     // updated by YJ to the lumi POG number       

// Point-to-point
double ppTrackingEfficiency   = 4;            // single track systematics from D* studies
double PbPbTrackingEfficiency   = 5;        // single track systematics from D* studies
double ppAlignment = 2.8; //alignment systematic from pp 13 TeV analysis
double PbPbAlignment = 2.8; //alignment systematic from pp 13 TeV analysis
double ppLifetime = 0.3; //from 13 TeV analysis
double PbPbLifetime = 0.3; //from 13 TeV analysis

TH1D*  ppSignalExtraction;                        // (6/29/2016)
TH1D*  ppMesonSelection;                        // (6/29/2016)
TH1D*  ppTagAndProbe;                       // (6/29/2016)

TF1 *fPPPtShape = new TF1("fPPPtShapeSig","[0]+[1]/(x)+[2]/x/x+[3]*x");

TFile* ppMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPP.root");
TH1D* ppEff = (TH1D*)ppMCEfffile->Get("hEff");

// =============================================================================================================
// PbPb uncertainty
// =============================================================================================================

// Normalization uncertainty
double PbPbNMBUncertainty = 2;      // uncertainty associated with minbias events,
double TAAUncertainty0to100 = 8.9;      // Updated number (4/7/2016)
double TAAUncertainty0to10  = 1.7;      // Updated number (4/7/2016)
double PbPbLumiUncertainty  = 10;     // 10% for the moment, to be updated (from Daniel), NOT used

// Point-to-point

TH1D*  PbPbSignalExtraction;                        // (6/29/2016)
TH1D*  PbPbMesonSelection;                        // (6/29/2016)
TH1D*  PbPbTagAndProbe;                       // (6/29/2016)
TF1 *fPbPbPtShape= new TF1("fPbPbPtShapeSig","[0]+[1]/(x)+[2]/x/x+[3]*x");

TFile* PbPbMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPbPb.root");
TH1D* PbPbEff = (TH1D*)PbPbMCEfffile->Get("hEff");

// RAA uncertainty, for systematic that can cancel such as PDF variation
TH1D*  RAASignalExtraction;

bool initialized = 0;

void initializationPP()
{
   ppMesonSelection = new TH1D("ppMesonSelection","",nPtBins,PtBins);
   ppMesonSelection->SetBinContent(1,   2.7);

   ppSignalExtraction = new TH1D("ppSignalExtraction","",AnaBins,AnaPtBins);
   ppSignalExtraction->SetBinContent(1,   3.8);
   ppSignalExtraction->SetBinContent(2,   3.8);
   ppSignalExtraction->SetBinContent(3,   3.8);
   ppSignalExtraction->SetBinContent(4,   3.8);
   ppSignalExtraction->SetBinContent(5,   3.8);

   ppTagAndProbe = new TH1D("ppTagAndProbe","",nPtBins,PtBins);
   ppTagAndProbe->SetBinContent(1,    10.0);
   
   fPPPtShape->SetParameters(0.999265,-0.0458006,-0.181359,0);
   }

void initializationPbPbCent0100()
{

   PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBins,PtBins);
   PbPbMesonSelection->SetBinContent(1,   8.7);

   PbPbSignalExtraction = new TH1D("PbPbSignalExtraction","",AnaBins,AnaPtBins);
   PbPbSignalExtraction->SetBinContent(1, 12.0);
   PbPbSignalExtraction->SetBinContent(2, 12.0);
   PbPbSignalExtraction->SetBinContent(3, 12.0);
   PbPbSignalExtraction->SetBinContent(4, 12.0);
   PbPbSignalExtraction->SetBinContent(5, 12.0);

   PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",nPtBins,PtBins);
   PbPbTagAndProbe->SetBinContent(1,    13.0);

   fPbPbPtShape->SetParameters(0.984161,0.0593406,-0.3992,0.000271564);
   }

void initializationRAA()
{
   RAASignalExtraction = new TH1D("RAASignalExtraction","",nPtBins,PtBins);
   RAASignalExtraction->SetBinContent(1,  0.5);
}

void initializationPbPbCent010()
{

   PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBins,PtBins);
   PbPbMesonSelection->SetBinContent(1,   0.);


   PbPbSignalExtraction = new TH1D("PbPbSignalExtraction","",nPtBins,PtBins);
   PbPbSignalExtraction->SetBinContent(1, 0.);
   
   PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",nPtBins,PtBins);
   PbPbTagAndProbe->SetBinContent(1,    10.0);
    
   fPbPbPtShape->SetParameters(0.984161,0.0593406,-0.3992,0.000271564);
}

void initialization(double centL=0,double centH=100){

initializationPP();
initializationRAA();
if (centL==0&&centH==100) initializationPbPbCent0100();
if (centL==0&&centH==10) initializationPbPbCent010();
initialized=1;

}

// =============================================================================================================
// RAA systematics
// =============================================================================================================
float normalizationUncertaintyForRAA(double centL=0,double centH=100)
{
   double sys = 0;
   sys+=ppLumiUncertainty*ppLumiUncertainty;
   sys+=PbPbNMBUncertainty*PbPbNMBUncertainty;
   if (centL==0&&centH==10) {
      // 0-10%
      sys+=TAAUncertainty0to10*TAAUncertainty0to10;
   } else {
      // 0-100%
      sys+=TAAUncertainty0to100*TAAUncertainty0to100;
   }
   return sqrt(sys);
}

float systematicsForRAA(double pt,double centL=0,double centH=100, double HLT=0, int stage=0)
{
   if (!initialized && centL==0&&centH==100) initialization(centL,centH);
   if (!initialized && centL==0&&centH==10) initialization(centL,centH);

   double sys=0;

   if (pt<7) return 0;
   if (pt >= PtBins[1]) pt = PtBins[1]-0.1;
  
   if (stage==1) return sqrt(sys);
   
   //sys+= RAASignalExtraction->GetBinContent(RAASignalExtraction->FindBin(pt))*
   //      RAASignalExtraction->GetBinContent(RAASignalExtraction->FindBin(pt));
   sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))*
         PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));
   sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))*
         ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));

   if (stage==2) return sqrt(sys);

   sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))*
         ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
   sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))*
         PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

   sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
         ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
   sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
         PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

   sys+=fPPPtShape->Eval(pt)*fPPPtShape->Eval(pt);
   sys+=fPbPbPtShape->Eval(pt)*fPbPbPtShape->Eval(pt);

   sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
   sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
   sys+=ppAlignment*ppAlignment;
   sys+=ppLifetime*ppLifetime;
   sys+=PbPbAlignment*PbPbAlignment;
   sys+=PbPbLifetime*PbPbLifetime;
      
   if (stage==3) return sqrt(sys);

   sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
         ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));

   sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
         PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));
   
   return sqrt(sys);
}

// =============================================================================================================
// RCP systematics
// =============================================================================================================
float normalizationUncertaintyForRCP(double centL=0,double centH=100)
{
   return 0;
}

float systematicsForRCP(double pt, double HLT=0,double centL=0,double centH=100)
{
   if (!initialized && centL==0&&centH==100) initializationPbPbCent0100();
   if (!initialized && centL==0&&centH==10) initializationPbPbCent010();
   return 0.2;

}


// =============================================================================================================
// cross-section systematics for pp
// =============================================================================================================
float normalizationUncertaintyForPP()
{
   return sqrt((BtomumuKBRUncertainty*BtomumuKBRUncertainty)+(ppLumiUncertainty*ppLumiUncertainty));
}

float systematicsPP(double pt, double HLT=0,int stage=0)
{
   if (!initialized) initialization();
   double sys=0;

   if (pt >= PtBins[1]) pt = PtBins[1]-0.1;
   
   if (stage==1) return sqrt(sys);
   
   sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))* 
         ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));

   if (stage==2) return sqrt(sys);

   sys+=fPPPtShape->Eval(pt)*fPPPtShape->Eval(pt);
   sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
   sys+=ppAlignment*ppAlignment;
   sys+=ppLifetime*ppLifetime;
   sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))* 
         ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
   sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
         ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;

   if (stage==3) return sqrt(sys);

   sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
         ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));

   
   return sqrt(sys);
}

// =============================================================================================================
// cross-section systematics for PbPb
// =============================================================================================================
float normalizationUncertaintyForPbPb(double centL=0,double centH=100)
{
   double sys = ((BtomumuKBRUncertainty*BtomumuKBRUncertainty)+(PbPbNMBUncertainty*PbPbNMBUncertainty));
   if (centL==0&&centH==10) {
      // 0-10%
      sys+=TAAUncertainty0to10*TAAUncertainty0to10;
   } else {
      // 0-100%
      sys+=TAAUncertainty0to100*TAAUncertainty0to100;
   }   
   return sqrt(sys);
}


float systematicsPbPb(double pt, double centL=0,double centH=100, double HLT=0)
{
   if (!initialized && centL==0&&centH==100) initializationPbPbCent0100();
   if (!initialized && centL==0&&centH==10) initializationPbPbCent010();
   
   double sys=0;
   
   // pp tracking eff uncertainty used for the moment
   sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
   //sys+=PbPbNMBUncertainty*PbPbNMBUncertainty;
   sys+=PbPbAlignment*PbPbAlignment;
   sys+=PbPbLifetime*PbPbLifetime;
   
   sys+=TAAUncertainty0to100*TAAUncertainty0to100;
   sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))* 
         PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));
   sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
         PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;
   sys+=fPbPbPtShape->Eval(pt)*fPbPbPtShape->Eval(pt);
   sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))* 
         PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));
   sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
         PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

   return sqrt(sys);

}


// =============================================================================================================
// Drawer
// =============================================================================================================
void drawSys(double x1,double y1, double x2,double y2, int color = 1)
{
   TLine *l1 = new TLine(x1,y1/100.,x2,y2/100.);
   TLine *l2 = new TLine(x1,-y1/100.,x2,-y2/100.);
   l1->SetLineWidth(2);
   l2->SetLineWidth(2);
   l1->SetLineColor(color);
   l2->SetLineColor(color);
   l1->Draw();
   l2->Draw();
 
}

// =============================================================================================================
// Plot systematics for RAA
// =============================================================================================================
void plotSystematicsRAA(double centL=0,double centH=100)
{

  TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
  canvas->cd();
  canvas->SetFillColor(0);
  canvas->SetBorderMode(0);
  canvas->SetBorderSize(2);
  canvas->SetLeftMargin(0.185);//0.200
  canvas->SetRightMargin(0.045);
  canvas->SetTopMargin(0.080);
  canvas->SetBottomMargin(0.150);
  canvas->SetFrameBorderMode(0);
  canvas->SetLogx();

  TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-0.8,0.8);
  hempty->GetXaxis()->CenterTitle();
  hempty->GetYaxis()->CenterTitle();
  hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
  hempty->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
  hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
  hempty->GetYaxis()->SetTitleOffset(1.45);//1.
  hempty->GetXaxis()->SetTitleSize(0.05);//0.045
  hempty->GetYaxis()->SetTitleSize(0.05);//0.045
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.050);//0.035
  hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
  hempty->GetXaxis()->SetLabelOffset(0.01);
  hempty->Draw();

   drawSys(6,0, 6,normalizationUncertaintyForRAA(centL,centH),2);
   drawSys(6,normalizationUncertaintyForRAA(centL,centH), 6.5,normalizationUncertaintyForRAA(centL,centH),2);
   drawSys(6.5,0, 6.5,normalizationUncertaintyForRAA(centL,centH),2);


   drawSys(PtBins[0],0, PtBins[0],systematicsForRAA(PtBins[0],centL,centH,0,0),1);
   drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsForRAA(PtBins[nPtBins],centL,centH,0,0),1);


   for (double i=PtBins[0];i<=PtBins[nPtBins];i+=0.1)
   {      
      drawSys(i,systematicsForRAA(i,centL,centH,0,0), i+0.1,systematicsForRAA(i+0.1,centL,centH,0,0),1);
      drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,2)*systematicsForRAA(i,centL,centH,0,2))-(systematicsForRAA(i,centL,centH,0,1)*systematicsForRAA(i,centL,centH,0,1))),
              i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,2)*systematicsForRAA(i+0.1,centL,centH,0,2))-(systematicsForRAA(i+0.1,centL,centH,0,1)*systematicsForRAA(i+0.1,centL,centH,0,1))),4);
      drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,3)*systematicsForRAA(i,centL,centH,0,3))-(systematicsForRAA(i,centL,centH,0,2)*systematicsForRAA(i,centL,centH,0,2))),
              i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,3)*systematicsForRAA(i+0.1,centL,centH,0,3))-(systematicsForRAA(i+0.1,centL,centH,0,2)*systematicsForRAA(i+0.1,centL,centH,0,2))),kGreen+2);
      drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,0)*systematicsForRAA(i,centL,centH,0,0))-(systematicsForRAA(i,centL,centH,0,3)*systematicsForRAA(i,centL,centH,0,3))),
              i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,0)*systematicsForRAA(i+0.1,centL,centH,0,0))-(systematicsForRAA(i+0.1,centL,centH,0,3)*systematicsForRAA(i+0.1,centL,centH,0,3))),kMagenta);

   }

   TH1D *h1 = new TH1D("h1","",100,0,1);
   h1->SetLineWidth(2); h1->SetLineColor(1);
   TH1D *h2 = new TH1D("h2","",100,0,1);
   h2->SetLineWidth(2); h2->SetLineColor(2);
   TH1D *h4 = new TH1D("h4","",100,0,1);
   h4->SetLineWidth(2); h4->SetLineColor(4);
   TH1D *h5 = new TH1D("h5","",100,0,1);
   h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
   TH1D *h6 = new TH1D("h6","",100,0,1);
   h6->SetLineWidth(2); h6->SetLineColor(kMagenta);
   TH1D *h7 = new TH1D("h7","",100,0,1);
   h7->SetLineWidth(2); h7->SetLineColor(kYellow);
    
  TLatex* texlumi = new TLatex(0.19,0.936,"25.8 pb^{-1} (5.02 TeV pp) + 350.68 #mub^{-1} (5.02 TeV PbPb)");
  texlumi->SetNDC();
  //texlumi->SetTextAlign(31);
  texlumi->SetTextFont(42);
  texlumi->SetTextSize(0.036);
  texlumi->SetLineWidth(2);
  texlumi->Draw();
  TLatex* texcms = new TLatex(0.22,0.90,"CMS");
  texcms->SetNDC();
  texcms->SetTextAlign(13);
  texcms->SetTextFont(62);//61
  texcms->SetTextSize(0.06);
  texcms->SetLineWidth(2);
  texcms->Draw();
  TLatex* texpre = new TLatex(0.22,0.84,"Performance");
  texpre->SetNDC();
  texpre->SetTextAlign(13);
  texpre->SetTextFont(52);
  texpre->SetTextSize(0.04);
  texpre->SetLineWidth(2);
  texpre->Draw();

  TLatex * texY = new TLatex(0.5,0.8324607,"B^{+} R_{AA}, |y| < 2.4");//0.2612903,0.8425793
  texY->SetNDC();
  texY->SetTextColor(1);
  texY->SetTextFont(42);
  texY->SetTextSize(0.045);
  texY->SetLineWidth(2);
  texY->Draw();

  TString texper="%";
  TLatex * tlatexeff2 = new TLatex(0.5268456,0.7678883,Form("Centrality %.0f-%.0f%s",centL,centH,texper.Data()));//0.2612903,0.8425793
  tlatexeff2->SetNDC();
  tlatexeff2->SetTextColor(1);
  tlatexeff2->SetTextFont(42);
  tlatexeff2->SetTextSize(0.045);
  tlatexeff2->SetLineWidth(2);
  tlatexeff2->Draw();

   TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   leg->SetTextSize(0.04);
   leg->AddEntry(h2,"Overall Normalization (N_{MB}, Lumi)","l");
   leg->AddEntry(h1,"Total Systematics","l");
   leg->AddEntry(h4,"Signal Extraction","l");
   leg->AddEntry(h5,"B Meson Selection and Correction","l");
   leg->AddEntry(h6,"Tag and Probe","l");
   leg->Draw();
   canvas->SaveAs(Form("SystematicSummaryPbPb_Cent%d.pdf",(int)centH));
   canvas->SaveAs(Form("SystematicSummaryPbPb_Cent%d.png",(int)centH));


}

// =============================================================================================================
// Plot systematics for cross section
// =============================================================================================================
void plotSystematicsPP()
{
  TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
  canvas->cd();
  canvas->SetFillColor(0);
  canvas->SetBorderMode(0);
  canvas->SetBorderSize(2);
  canvas->SetLeftMargin(0.185);//0.200
  canvas->SetRightMargin(0.045);
  canvas->SetTopMargin(0.080);
  canvas->SetBottomMargin(0.150);
  canvas->SetFrameBorderMode(0);
  canvas->SetLogx();

  TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-0.8,0.8);
  hempty->GetXaxis()->CenterTitle();
  hempty->GetYaxis()->CenterTitle();
  hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
  hempty->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
  hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
  hempty->GetYaxis()->SetTitleOffset(1.45);//1.
  hempty->GetXaxis()->SetTitleSize(0.05);//0.045
  hempty->GetYaxis()->SetTitleSize(0.05);//0.045
  hempty->GetXaxis()->SetTitleFont(42);
  hempty->GetYaxis()->SetTitleFont(42);
  hempty->GetXaxis()->SetLabelFont(42);
  hempty->GetYaxis()->SetLabelFont(42);
  hempty->GetXaxis()->SetLabelSize(0.050);//0.035
  hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
  hempty->GetXaxis()->SetLabelOffset(0.01);
  hempty->Draw();

   drawSys(6,0, 6,normalizationUncertaintyForPP(),2);
   drawSys(6,normalizationUncertaintyForPP(), 6.5,normalizationUncertaintyForPP(),2);
   drawSys(6.5,0, 6.5,normalizationUncertaintyForPP(),2);


   drawSys(PtBins[0],0, PtBins[0],systematicsPP(PtBins[0]),1);
   drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsPP(PtBins[nPtBins]),1);

   for (double i=PtBins[0];i<PtBins[nPtBins];i+=0.1)
   {      
      drawSys(i,systematicsPP(i,0,0), i+0.1,systematicsPP(i+0.1,0,0),1);
      drawSys(i,sqrt((systematicsPP(i,0,2)*systematicsPP(i,0,2))-(systematicsPP(i,0,1)*systematicsPP(i,0,1))),
              i+0.1,sqrt((systematicsPP(i+0.1,0,2)*systematicsPP(i+0.1,0,2))-(systematicsPP(i+0.1,0,1)*systematicsPP(i+0.1,0,1))),4);
      drawSys(i,sqrt((systematicsPP(i,0,3)*systematicsPP(i,0,3))-(systematicsPP(i,0,2)*systematicsPP(i,0,2))),
              i+0.1,sqrt((systematicsPP(i+0.1,0,3)*systematicsPP(i+0.1,0,3))-(systematicsPP(i+0.1,0,2)*systematicsPP(i+0.1,0,2))),kGreen+2);
      drawSys(i,sqrt((systematicsPP(i,0,0)*systematicsPP(i,0,0))-(systematicsPP(i,0,3)*systematicsPP(i,0,3))),
              i+0.1,sqrt((systematicsPP(i+0.1,0,0)*systematicsPP(i+0.1,0,0))-(systematicsPP(i+0.1,0,3)*systematicsPP(i+0.1,0,3))),kMagenta);
   }

   TH1D *h1 = new TH1D("h1","",100,0,1);
   h1->SetLineWidth(2); h1->SetLineColor(1);
   TH1D *h2 = new TH1D("h2","",100,0,1);
   h2->SetLineWidth(2); h2->SetLineColor(2);
   TH1D *h4 = new TH1D("h4","",100,0,1);
   h4->SetLineWidth(2); h4->SetLineColor(4);
   TH1D *h5 = new TH1D("h5","",100,0,1);
   h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
   TH1D *h6 = new TH1D("h6","",100,0,1);
   h6->SetLineWidth(2); h6->SetLineColor(kMagenta);

  TLatex* texlumi = new TLatex(0.35,0.936,"25.8 pb^{-1} (5.02 TeV pp)");
  texlumi->SetNDC();
  //texlumi->SetTextAlign(31);
  texlumi->SetTextFont(42);
  texlumi->SetTextSize(0.045);
  texlumi->SetLineWidth(2);
  texlumi->Draw();
  TLatex* texcms = new TLatex(0.22,0.90,"CMS");
  texcms->SetNDC();
  texcms->SetTextAlign(13);
  texcms->SetTextFont(62);//61
  texcms->SetTextSize(0.06);
  texcms->SetLineWidth(2);
  texcms->Draw();
  TLatex* texpre = new TLatex(0.22,0.84,"Performance");
  texpre->SetNDC();
  texpre->SetTextAlign(13);
  texpre->SetTextFont(52);
  texpre->SetTextSize(0.04);
  texpre->SetLineWidth(2);
  texpre->Draw();

  TLatex * texY = new TLatex(0.5,0.8324607,"B^{+} d#sigma / dp_{T}, |y| < 2.4");//0.2612903,0.8425793
  texY->SetNDC();
  texY->SetTextColor(1);
  texY->SetTextFont(42);
  texY->SetTextSize(0.045);
  texY->SetLineWidth(2);
  texY->Draw();

   TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
   leg->SetTextSize(0.04);
   leg->AddEntry(h2,"Overall Normalization (Lumi + BR)","l");
   leg->AddEntry(h1,"Total Systematics","l");
   leg->AddEntry(h4,"Signal Extraction","l");
   leg->AddEntry(h5,"B Meson Selection and Correction","l");
   leg->AddEntry(h6,"Tag and Probe","l");
   leg->Draw();

  canvas->SaveAs("SystematicSummaryPP.pdf");
  canvas->SaveAs("SystematicSummaryPP.png");
  }


void plotNormalisationUnc(){

std::cout<<"normalisation uncertainty RAA 0-100="<<normalizationUncertaintyForRAA(0,100)<<std::endl;
std::cout<<"normalisation uncertainty RAA 0-10="<<normalizationUncertaintyForRAA(0,10)<<std::endl;
std::cout<<"normalisation uncertainty pp="<<normalizationUncertaintyForPP()<<std::endl;
std::cout<<"normalisation uncertainty PbPb 0-100="<<normalizationUncertaintyForPbPb(0,100)<<std::endl;
std::cout<<"normalisation uncertainty PbPb 0-10="<<normalizationUncertaintyForPbPb(0,10)<<std::endl;

}
