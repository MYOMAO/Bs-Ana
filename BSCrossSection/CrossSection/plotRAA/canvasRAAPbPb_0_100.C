void canvasRAAPbPb_0_100()
{
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Sat Sep  2 20:49:05 2017) by ROOT version6.08/02
   TCanvas *canvasRAA = new TCanvas("canvasRAA", "canvasRAA",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvasRAA->SetHighLightColor(2);
   canvasRAA->Range(0.7746443,-0.2310559,1.845025,1.69441);
   canvasRAA->SetFillColor(0);
   canvasRAA->SetBorderMode(0);
   canvasRAA->SetBorderSize(2);
   canvasRAA->SetLogx();
   canvasRAA->SetLeftMargin(0.12);
   canvasRAA->SetRightMargin(0.03);
   canvasRAA->SetTopMargin(0.075);
   canvasRAA->SetBottomMargin(0.12);
   canvasRAA->SetFrameBorderMode(0);
   canvasRAA->SetFrameBorderMode(0);
   
   TH2F *hemptyEff__1 = new TH2F("hemptyEff__1","",50,8,65,10,0,1.55);
   hemptyEff__1->SetMinimum(0);
   hemptyEff__1->SetMaximum(2);
   hemptyEff__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptyEff__1->SetLineColor(ci);
   hemptyEff__1->SetMarkerStyle(20);
   hemptyEff__1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff__1->GetXaxis()->CenterTitle(true);
   hemptyEff__1->GetXaxis()->SetLabelFont(42);
   hemptyEff__1->GetXaxis()->SetTitleSize(0.05);
   hemptyEff__1->GetXaxis()->SetTitleFont(42);
   hemptyEff__1->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff__1->GetYaxis()->CenterTitle(true);
   hemptyEff__1->GetYaxis()->SetLabelFont(42);
   hemptyEff__1->GetYaxis()->SetTitleSize(0.05);
   hemptyEff__1->GetYaxis()->SetTitleOffset(1.1);
   hemptyEff__1->GetYaxis()->SetTitleFont(42);
   hemptyEff__1->GetZaxis()->SetLabelFont(42);
   hemptyEff__1->GetZaxis()->SetLabelSize(0.035);
   hemptyEff__1->GetZaxis()->SetTitleSize(0.035);
   hemptyEff__1->GetZaxis()->SetTitleFont(42);
   hemptyEff__1->Draw("");
   TLine *line = new TLine(8,1,65,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TBox *box = new TBox(8,0.8492652,8.35,1.150735);
   box->SetFillColor(16);
   box->SetLineColor(16);
   box->Draw();
   TLatex *   tex = new TLatex(0.38,0.595,"Centrality 0-100%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.13,0.936,"27.4 pb^{-1} (5.02 TeV pp) + 350.68 #mub^{-1} (5.02 TeV PbPb)");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.9,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.84,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.23,0.7,"T_{AA} and lumi.");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.23,0.65,"uncertainty");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t gNuclearModification_fx3001[1] = {
   35};
   Double_t gNuclearModification_fy3001[1] = {
   0};
   Double_t gNuclearModification_felx3001[1] = {
   25};
   Double_t gNuclearModification_fely3001[1] = {
   -nan};
   Double_t gNuclearModification_fehx3001[1] = {
   25};
   Double_t gNuclearModification_fehy3001[1] = {
   -nan};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(1,gNuclearModification_fx3001,gNuclearModification_fy3001,gNuclearModification_felx3001,gNuclearModification_fehx3001,gNuclearModification_fely3001,gNuclearModification_fehy3001);
   grae->SetName("gNuclearModification");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#0099ff");
   grae->SetFillColor(ci);
   grae->SetFillStyle(3001);

   ci = TColor::GetColor("#0099ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#330066");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_gNuclearModification3001 = new TH1F("Graph_gNuclearModification3001","Graph",100,5,65);
   Graph_gNuclearModification3001->SetMinimum(0);
   Graph_gNuclearModification3001->SetMaximum(1.1);
   Graph_gNuclearModification3001->SetDirectory(0);
   Graph_gNuclearModification3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gNuclearModification3001->SetLineColor(ci);
   Graph_gNuclearModification3001->SetMarkerStyle(20);
   Graph_gNuclearModification3001->GetXaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetXaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetXaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetXaxis()->SetTitleFont(42);
   Graph_gNuclearModification3001->GetYaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetYaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleFont(42);
   Graph_gNuclearModification3001->GetZaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetZaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetZaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gNuclearModification3001);
   
   grae->Draw("5");
   Double_t xAxis1[2] = {10, 60}; 
   
   TH1D *hNuclearModification__2 = new TH1D("hNuclearModification__2","",1, xAxis1);

   ci = TColor::GetColor("#330066");
   hNuclearModification__2->SetLineColor(ci);
   hNuclearModification__2->SetLineWidth(3);

   ci = TColor::GetColor("#330066");
   hNuclearModification__2->SetMarkerColor(ci);
   hNuclearModification__2->SetMarkerStyle(21);
   hNuclearModification__2->SetMarkerSize(1.2);
   hNuclearModification__2->GetXaxis()->SetTitle("B_{s} p_{T} (GeV/c)");
   hNuclearModification__2->GetXaxis()->SetLabelFont(42);
   hNuclearModification__2->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification__2->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification__2->GetXaxis()->SetTitleFont(42);
   hNuclearModification__2->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification__2->GetYaxis()->SetLabelFont(42);
   hNuclearModification__2->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification__2->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification__2->GetYaxis()->SetTitleFont(42);
   hNuclearModification__2->GetZaxis()->SetLabelFont(42);
   hNuclearModification__2->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification__2->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification__2->GetZaxis()->SetTitleFont(42);
   hNuclearModification__2->Draw("same");
   
   TLegend *leg = new TLegend(0.6036242,0.7474695,0.942953,0.8457592,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gNuclearModification","B^{+} |y| < 2.4","pf");

   ci = TColor::GetColor("#0099ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3001);

   ci = TColor::GetColor("#0099ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#330066");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.038);
   leg->Draw();
   
   TH2F *hemptyEff_copy__3 = new TH2F("hemptyEff_copy__3","",50,8,65,10,0,1.55);
   hemptyEff_copy__3->SetMinimum(0);
   hemptyEff_copy__3->SetMaximum(2);
   hemptyEff_copy__3->SetDirectory(0);
   hemptyEff_copy__3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hemptyEff_copy__3->SetLineColor(ci);
   hemptyEff_copy__3->SetMarkerStyle(20);
   hemptyEff_copy__3->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff_copy__3->GetXaxis()->CenterTitle(true);
   hemptyEff_copy__3->GetXaxis()->SetLabelFont(42);
   hemptyEff_copy__3->GetXaxis()->SetTitleSize(0.05);
   hemptyEff_copy__3->GetXaxis()->SetTitleFont(42);
   hemptyEff_copy__3->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff_copy__3->GetYaxis()->CenterTitle(true);
   hemptyEff_copy__3->GetYaxis()->SetLabelFont(42);
   hemptyEff_copy__3->GetYaxis()->SetTitleSize(0.05);
   hemptyEff_copy__3->GetYaxis()->SetTitleOffset(1.1);
   hemptyEff_copy__3->GetYaxis()->SetTitleFont(42);
   hemptyEff_copy__3->GetZaxis()->SetLabelFont(42);
   hemptyEff_copy__3->GetZaxis()->SetLabelSize(0.035);
   hemptyEff_copy__3->GetZaxis()->SetTitleSize(0.035);
   hemptyEff_copy__3->GetZaxis()->SetTitleFont(42);
   hemptyEff_copy__3->Draw("sameaxis");
   canvasRAA->Modified();
   canvasRAA->cd();
   canvasRAA->SetSelected(canvasRAA);
}
