void canvas1DhEff_pp()
{
//=========Macro generated from canvas: canvas1D/
//=========  (Sat Sep  2 20:46:02 2017) by ROOT version6.08/02
   TCanvas *canvas1D = new TCanvas("canvas1D", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvas1D->SetHighLightColor(2);
   canvas1D->Range(-2.500001,-0.07500001,72.5,0.675);
   canvas1D->SetFillColor(0);
   canvas1D->SetBorderMode(0);
   canvas1D->SetBorderSize(2);
   canvas1D->SetFrameBorderMode(0);
   canvas1D->SetFrameBorderMode(0);
   
   TH2F *hemptyEff__1 = new TH2F("hemptyEff__1","",50,5,65,10,0,0.6);
   hemptyEff__1->SetMinimum(0);
   hemptyEff__1->SetMaximum(0.6);
   hemptyEff__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptyEff__1->SetLineColor(ci);
   hemptyEff__1->SetMarkerStyle(20);
   hemptyEff__1->GetXaxis()->SetTitle("p_{T} GeV^{-1}c)");
   hemptyEff__1->GetXaxis()->CenterTitle(true);
   hemptyEff__1->GetXaxis()->SetLabelFont(42);
   hemptyEff__1->GetXaxis()->SetLabelSize(0.035);
   hemptyEff__1->GetXaxis()->SetTitleSize(0.05);
   hemptyEff__1->GetXaxis()->SetTitleOffset(0.9);
   hemptyEff__1->GetXaxis()->SetTitleFont(42);
   hemptyEff__1->GetYaxis()->SetTitle("#alpha x #epsilon");
   hemptyEff__1->GetYaxis()->CenterTitle(true);
   hemptyEff__1->GetYaxis()->SetLabelFont(42);
   hemptyEff__1->GetYaxis()->SetLabelSize(0.035);
   hemptyEff__1->GetYaxis()->SetTitleSize(0.05);
   hemptyEff__1->GetYaxis()->SetTitleOffset(0.95);
   hemptyEff__1->GetYaxis()->SetTitleFont(42);
   hemptyEff__1->GetZaxis()->SetLabelFont(42);
   hemptyEff__1->GetZaxis()->SetLabelSize(0.035);
   hemptyEff__1->GetZaxis()->SetTitleSize(0.035);
   hemptyEff__1->GetZaxis()->SetTitleFont(42);
   hemptyEff__1->Draw("");
   Double_t xAxis1[2] = {10, 60}; 
   
   TH1D *hEff__2 = new TH1D("hEff__2","",1, xAxis1);
   hEff__2->SetStats(0);
   hEff__2->SetLineColor(2);
   hEff__2->SetMarkerColor(2);
   hEff__2->SetMarkerStyle(20);
   hEff__2->GetXaxis()->CenterTitle(true);
   hEff__2->GetXaxis()->SetLabelFont(42);
   hEff__2->GetXaxis()->SetLabelSize(0.035);
   hEff__2->GetXaxis()->SetTitleSize(0.035);
   hEff__2->GetXaxis()->SetTitleFont(42);
   hEff__2->GetYaxis()->CenterTitle(true);
   hEff__2->GetYaxis()->SetLabelFont(42);
   hEff__2->GetYaxis()->SetLabelSize(0.035);
   hEff__2->GetYaxis()->SetTitleSize(0.035);
   hEff__2->GetYaxis()->SetTitleFont(42);
   hEff__2->GetZaxis()->SetLabelFont(42);
   hEff__2->GetZaxis()->SetLabelSize(0.035);
   hEff__2->GetZaxis()->SetTitleSize(0.035);
   hEff__2->GetZaxis()->SetTitleFont(42);
   hEff__2->Draw("same");
   TLatex *   tex = new TLatex(0.5,0.75,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.08,0.95,"CMS Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.9,0.92,"25.8 pb^{-1} (5.02 TeV pp)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
   canvas1D->Modified();
   canvas1D->cd();
   canvas1D->SetSelected(canvas1D);
}
