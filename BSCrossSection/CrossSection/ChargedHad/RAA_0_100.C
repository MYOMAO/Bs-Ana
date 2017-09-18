#include <TColor.h>
#include <TBox.h>
#include <TH1D.h>

void RAA_0_100()
{
//=========Macro generated from canvas: RAA/RAA
//=========  (Fri May 20 18:48:21 2016) by ROOT version6.02/10
/*
   TCanvas *RAA = new TCanvas("RAA", "RAA",1,1,800,676);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   RAA->Range(-0.6654505,-0.24,2.738206,1.76);
   RAA->SetFillColor(0);
   RAA->SetBorderMode(0);
   RAA->SetBorderSize(2);
   RAA->SetLogx();
   RAA->SetLeftMargin(0.15);
   RAA->SetRightMargin(0.04);
   RAA->SetTopMargin(0.08);
   RAA->SetBottomMargin(0.12);
   RAA->SetFrameFillStyle(0);
   RAA->SetFrameBorderMode(0);
   RAA->SetFrameFillStyle(0);
   RAA->SetFrameBorderMode(0);
   Double_t xAxis359[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_100615 = new TH1D("RAA_0_100615","",37, xAxis359);
   RAA_0_100615->SetBinContent(1,0.3314644);
   RAA_0_100615->SetBinContent(2,0.3462147);
   RAA_0_100615->SetBinContent(3,0.3421076);
   RAA_0_100615->SetBinContent(4,0.3658316);
   RAA_0_100615->SetBinContent(5,0.3966155);
   RAA_0_100615->SetBinContent(6,0.4148868);
   RAA_0_100615->SetBinContent(7,0.4303691);
   RAA_0_100615->SetBinContent(8,0.4518389);
   RAA_0_100615->SetBinContent(9,0.4696205);
   RAA_0_100615->SetBinContent(10,0.484041);
   RAA_0_100615->SetBinContent(11,0.4870421);
   RAA_0_100615->SetBinContent(12,0.4867814);
   RAA_0_100615->SetBinContent(13,0.4789017);
   RAA_0_100615->SetBinContent(14,0.4456695);
   RAA_0_100615->SetBinContent(15,0.3588006);
   RAA_0_100615->SetBinContent(16,0.2849955);
   RAA_0_100615->SetBinContent(17,0.2419699);
   RAA_0_100615->SetBinContent(18,0.2243542);
   RAA_0_100615->SetBinContent(19,0.2180826);
   RAA_0_100615->SetBinContent(20,0.2247647);
   RAA_0_100615->SetBinContent(21,0.270725);
   RAA_0_100615->SetBinContent(22,0.3015448);
   RAA_0_100615->SetBinContent(23,0.3391684);
   RAA_0_100615->SetBinContent(24,0.4025604);
   RAA_0_100615->SetBinContent(25,0.4453615);
   RAA_0_100615->SetBinContent(26,0.5048213);
   RAA_0_100615->SetBinContent(27,0.5191112);
   RAA_0_100615->SetBinContent(28,0.5835764);
   RAA_0_100615->SetBinContent(29,0.6316778);
   RAA_0_100615->SetBinContent(30,0.6641992);
   RAA_0_100615->SetBinContent(31,0.7348689);
   RAA_0_100615->SetBinContent(32,0.7565952);
   RAA_0_100615->SetBinContent(33,0.7582413);
   RAA_0_100615->SetBinContent(34,0.7690597);
   RAA_0_100615->SetBinContent(35,0.8465348);
   RAA_0_100615->SetBinContent(36,0.838195);
   RAA_0_100615->SetBinContent(37,0.7198431);
   RAA_0_100615->SetBinError(1,5.45556e-05);
   RAA_0_100615->SetBinError(2,3.613189e-05);
   RAA_0_100615->SetBinError(3,2.607049e-05);
   RAA_0_100615->SetBinError(4,2.885564e-05);
   RAA_0_100615->SetBinError(5,3.159594e-05);
   RAA_0_100615->SetBinError(6,3.38567e-05);
   RAA_0_100615->SetBinError(7,3.869295e-05);
   RAA_0_100615->SetBinError(8,3.305379e-05);
   RAA_0_100615->SetBinError(9,4.18263e-05);
   RAA_0_100615->SetBinError(10,5.177436e-05);
   RAA_0_100615->SetBinError(11,6.300253e-05);
   RAA_0_100615->SetBinError(12,7.546549e-05);
   RAA_0_100615->SetBinError(13,8.87769e-05);
   RAA_0_100615->SetBinError(14,6.1286e-05);
   RAA_0_100615->SetBinError(15,9.414707e-05);
   RAA_0_100615->SetBinError(16,0.0001322857);
   RAA_0_100615->SetBinError(17,0.0001814982);
   RAA_0_100615->SetBinError(18,0.0002505459);
   RAA_0_100615->SetBinError(19,0.0003376182);
   RAA_0_100615->SetBinError(20,0.0003242908);
   RAA_0_100615->SetBinError(21,0.0007237008);
   RAA_0_100615->SetBinError(22,0.001286194);
   RAA_0_100615->SetBinError(23,0.001729729);
   RAA_0_100615->SetBinError(24,0.003645816);
   RAA_0_100615->SetBinError(25,0.006132279);
   RAA_0_100615->SetBinError(26,0.009164018);
   RAA_0_100615->SetBinError(27,0.01215199);
   RAA_0_100615->SetBinError(28,0.01470765);
   RAA_0_100615->SetBinError(29,0.0127274);
   RAA_0_100615->SetBinError(30,0.01638585);
   RAA_0_100615->SetBinError(31,0.02569265);
   RAA_0_100615->SetBinError(32,0.01410461);
   RAA_0_100615->SetBinError(33,0.02175455);
   RAA_0_100615->SetBinError(34,0.03042374);
   RAA_0_100615->SetBinError(35,0.04570938);
   RAA_0_100615->SetBinError(36,0.05478526);
   RAA_0_100615->SetBinError(37,0.1718071);
   RAA_0_100615->SetMinimum(0);
   RAA_0_100615->SetMaximum(1.6);
   RAA_0_100615->SetEntries(7549.091);
   RAA_0_100615->SetDirectory(0);
   RAA_0_100615->SetLineWidth(2);
   RAA_0_100615->SetMarkerStyle(20);
   RAA_0_100615->SetMarkerSize(1.3);
   RAA_0_100615->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_100615->GetXaxis()->SetRange(3,37);
   RAA_0_100615->GetXaxis()->CenterTitle(true);
   RAA_0_100615->GetXaxis()->SetLabelFont(42);
   RAA_0_100615->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_100615->GetXaxis()->SetTitleSize(0.05);
   RAA_0_100615->GetXaxis()->SetTitleFont(42);
   RAA_0_100615->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_100615->GetYaxis()->CenterTitle(true);
   RAA_0_100615->GetYaxis()->SetLabelFont(42);
   RAA_0_100615->GetYaxis()->SetTitleOffset(1.6);
   RAA_0_100615->GetYaxis()->SetTitleFont(42);
   RAA_0_100615->GetZaxis()->SetLabelFont(42);
   RAA_0_100615->GetZaxis()->SetLabelSize(0.05);
   RAA_0_100615->GetZaxis()->SetTitleSize(0.05);
   RAA_0_100615->GetZaxis()->SetTitleFont(42);
   RAA_0_100615->Draw("");
   */
   TBox *box = new TBox(0.9,0.911,1.161895,1.089);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   /*
   ci = TColor::GetColor("#9999ff");
   box->SetFillColor(ci);
   box->SetLineWidth(0);
   box->Draw();
   box = new TBox(1.161895,0.88,1.5,1.12);

   ci = TColor::GetColor("#cccccc");
   box->SetFillColor(ci);
   box->SetLineWidth(0);
   box->Draw();
   TLine *line = new TLine(0.7,1,400,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(0.9,0.1,"0-100%");
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1.8,1.03,"T_{AA} and lumi. uncertainty");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1.8,0.93,"|#eta|<1");
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   box = new TBox(0.7,0.3064424,0.8,0.3777729);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(0.8,0.3268842,0.9,0.4047789);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(0.9,0.3543908,1,0.4388403);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
 */
   box = new TBox(1,0.3707168,1.1,0.4590567);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.1,0.3845509,1.2,0.4761873);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.2,0.3993961,1.4,0.5042817);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.4,0.4151139,1.6,0.5241271);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.6,0.4208021,1.8,0.5472799);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.8,0.4234111,2,0.5506731);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2,0.4158465,2.2,0.5577162);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2.2,0.409115,2.4,0.5486883);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2.4,0.3741336,3.2,0.5172055);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(3.2,0.2975345,4,0.4200667);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(4,0.2388493,4.8,0.3311417);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(4.8,0.2082126,5.6,0.2757271);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(5.6,0.1960407,6.4,0.2526677);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(6.4,0.1936436,7.2,0.2425217);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(7.2,0.2013329,9.6,0.2481966);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(9.6,0.242502,12,0.2989481);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(12,0.2701029,14.4,0.3329867);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(14.4,0.3038092,19.2,0.3745277);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(19.2,0.3605853,24,0.4445355);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(24,0.3989047,28.8,0.4918184);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(28.8,0.4521378,35.2,0.5575047);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(35.2,0.4648761,41.6,0.5733463);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(41.6,0.522536,48,0.6446169);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(48,0.5655579,60.8,0.6977977);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(60.8,0.5946288,73.6,0.7337696);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(73.6,0.6578823,86.4,0.8118555);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(86.4,0.6772966,103.6,0.8358938);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(103.6,0.6787656,120.8,0.837717);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(120.8,0.6884472,140,0.8496722);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(140,0.7578003,165,0.9352693);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(165,0.7503507,250,0.9260392);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(250,0.6443967,400,0.7952896);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
     /*
   Double_t xAxis360[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_100616 = new TH1D("RAA_0_100616","",37, xAxis360);
   RAA_0_100616->SetBinContent(1,0.3314644);
   RAA_0_100616->SetBinContent(2,0.3462147);
   RAA_0_100616->SetBinContent(3,0.3421076);
   RAA_0_100616->SetBinContent(4,0.3658316);
   RAA_0_100616->SetBinContent(5,0.3966155);
   RAA_0_100616->SetBinContent(6,0.4148868);
   RAA_0_100616->SetBinContent(7,0.4303691);
   RAA_0_100616->SetBinContent(8,0.4518389);
   RAA_0_100616->SetBinContent(9,0.4696205);
   RAA_0_100616->SetBinContent(10,0.484041);
   RAA_0_100616->SetBinContent(11,0.4870421);
   RAA_0_100616->SetBinContent(12,0.4867814);
   RAA_0_100616->SetBinContent(13,0.4789017);
   RAA_0_100616->SetBinContent(14,0.4456695);
   RAA_0_100616->SetBinContent(15,0.3588006);
   RAA_0_100616->SetBinContent(16,0.2849955);
   RAA_0_100616->SetBinContent(17,0.2419699);
   RAA_0_100616->SetBinContent(18,0.2243542);
   RAA_0_100616->SetBinContent(19,0.2180826);
   RAA_0_100616->SetBinContent(20,0.2247647);
   RAA_0_100616->SetBinContent(21,0.270725);
   RAA_0_100616->SetBinContent(22,0.3015448);
   RAA_0_100616->SetBinContent(23,0.3391684);
   RAA_0_100616->SetBinContent(24,0.4025604);
   RAA_0_100616->SetBinContent(25,0.4453615);
   RAA_0_100616->SetBinContent(26,0.5048213);
   RAA_0_100616->SetBinContent(27,0.5191112);
   RAA_0_100616->SetBinContent(28,0.5835764);
   RAA_0_100616->SetBinContent(29,0.6316778);
   RAA_0_100616->SetBinContent(30,0.6641992);
   RAA_0_100616->SetBinContent(31,0.7348689);
   RAA_0_100616->SetBinContent(32,0.7565952);
   RAA_0_100616->SetBinContent(33,0.7582413);
   RAA_0_100616->SetBinContent(34,0.7690597);
   RAA_0_100616->SetBinContent(35,0.8465348);
   RAA_0_100616->SetBinContent(36,0.838195);
   RAA_0_100616->SetBinContent(37,0.7198431);
   RAA_0_100616->SetBinError(1,5.45556e-05);
   RAA_0_100616->SetBinError(2,3.613189e-05);
   RAA_0_100616->SetBinError(3,2.607049e-05);
   RAA_0_100616->SetBinError(4,2.885564e-05);
   RAA_0_100616->SetBinError(5,3.159594e-05);
   RAA_0_100616->SetBinError(6,3.38567e-05);
   RAA_0_100616->SetBinError(7,3.869295e-05);
   RAA_0_100616->SetBinError(8,3.305379e-05);
   RAA_0_100616->SetBinError(9,4.18263e-05);
   RAA_0_100616->SetBinError(10,5.177436e-05);
   RAA_0_100616->SetBinError(11,6.300253e-05);
   RAA_0_100616->SetBinError(12,7.546549e-05);
   RAA_0_100616->SetBinError(13,8.87769e-05);
   RAA_0_100616->SetBinError(14,6.1286e-05);
   RAA_0_100616->SetBinError(15,9.414707e-05);
   RAA_0_100616->SetBinError(16,0.0001322857);
   RAA_0_100616->SetBinError(17,0.0001814982);
   RAA_0_100616->SetBinError(18,0.0002505459);
   RAA_0_100616->SetBinError(19,0.0003376182);
   RAA_0_100616->SetBinError(20,0.0003242908);
   RAA_0_100616->SetBinError(21,0.0007237008);
   RAA_0_100616->SetBinError(22,0.001286194);
   RAA_0_100616->SetBinError(23,0.001729729);
   RAA_0_100616->SetBinError(24,0.003645816);
   RAA_0_100616->SetBinError(25,0.006132279);
   RAA_0_100616->SetBinError(26,0.009164018);
   RAA_0_100616->SetBinError(27,0.01215199);
   RAA_0_100616->SetBinError(28,0.01470765);
   RAA_0_100616->SetBinError(29,0.0127274);
   RAA_0_100616->SetBinError(30,0.01638585);
   RAA_0_100616->SetBinError(31,0.02569265);
   RAA_0_100616->SetBinError(32,0.01410461);
   RAA_0_100616->SetBinError(33,0.02175455);
   RAA_0_100616->SetBinError(34,0.03042374);
   RAA_0_100616->SetBinError(35,0.04570938);
   RAA_0_100616->SetBinError(36,0.05478526);
   RAA_0_100616->SetBinError(37,0.1718071);
   RAA_0_100616->SetMinimum(0);
   RAA_0_100616->SetMaximum(1.6);
   RAA_0_100616->SetEntries(7549.091);
   RAA_0_100616->SetDirectory(0);
   RAA_0_100616->SetLineWidth(2);
   RAA_0_100616->SetMarkerStyle(20);
   RAA_0_100616->SetMarkerSize(1.3);
   RAA_0_100616->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_100616->GetXaxis()->SetRange(3,37);
   RAA_0_100616->GetXaxis()->CenterTitle(true);
   RAA_0_100616->GetXaxis()->SetLabelFont(42);
   RAA_0_100616->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_100616->GetXaxis()->SetTitleSize(0.05);
   RAA_0_100616->GetXaxis()->SetTitleFont(42);
   RAA_0_100616->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_100616->GetYaxis()->CenterTitle(true);
   RAA_0_100616->GetYaxis()->SetLabelFont(42);
   RAA_0_100616->GetYaxis()->SetTitleOffset(1.6);
   RAA_0_100616->GetYaxis()->SetTitleFont(42);
   RAA_0_100616->GetZaxis()->SetLabelFont(42);
   RAA_0_100616->GetZaxis()->SetLabelSize(0.05);
   RAA_0_100616->GetZaxis()->SetTitleSize(0.05);
   RAA_0_100616->GetZaxis()->SetTitleFont(42);
   RAA_0_100616->Draw("same");
      tex = new TLatex(0.96,0.936,"25.8 pb^{-1} (5.02 TeV pp) + 404 #mub^{-1} (5.02 TeV PbPb)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.18645,0.892,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(61);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.18645,0.82,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0456);
   tex->SetLineWidth(2);
   tex->Draw();
   */
   Double_t xAxis361[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_100_copy617 = new TH1D("RAA_0_100_copy617","",37, xAxis361);
   RAA_0_100_copy617->SetBinContent(1,-1);
   RAA_0_100_copy617->SetBinContent(2,-1);
   RAA_0_100_copy617->SetBinContent(3,-1);
   RAA_0_100_copy617->SetBinContent(4,-1);
   RAA_0_100_copy617->SetBinContent(5,-1);
   RAA_0_100_copy617->SetBinContent(6,0.4148868);
   RAA_0_100_copy617->SetBinContent(7,0.4303691);
   RAA_0_100_copy617->SetBinContent(8,0.4518389);
   RAA_0_100_copy617->SetBinContent(9,0.4696205);
   RAA_0_100_copy617->SetBinContent(10,0.484041);
   RAA_0_100_copy617->SetBinContent(11,0.4870421);
   RAA_0_100_copy617->SetBinContent(12,0.4867814);
   RAA_0_100_copy617->SetBinContent(13,0.4789017);
   RAA_0_100_copy617->SetBinContent(14,0.4456695);
   RAA_0_100_copy617->SetBinContent(15,0.3588006);
   RAA_0_100_copy617->SetBinContent(16,0.2849955);
   RAA_0_100_copy617->SetBinContent(17,0.2419699);
   RAA_0_100_copy617->SetBinContent(18,0.2243542);
   RAA_0_100_copy617->SetBinContent(19,0.2180826);
   RAA_0_100_copy617->SetBinContent(20,0.2247647);
   RAA_0_100_copy617->SetBinContent(21,0.270725);
   RAA_0_100_copy617->SetBinContent(22,0.3015448);
   RAA_0_100_copy617->SetBinContent(23,0.3391684);
   RAA_0_100_copy617->SetBinContent(24,0.4025604);
   RAA_0_100_copy617->SetBinContent(25,0.4453615);
   RAA_0_100_copy617->SetBinContent(26,0.5048213);
   RAA_0_100_copy617->SetBinContent(27,0.5191112);
   RAA_0_100_copy617->SetBinContent(28,0.5835764);
   RAA_0_100_copy617->SetBinContent(29,0.6316778);
   RAA_0_100_copy617->SetBinContent(30,0.6641992);
   RAA_0_100_copy617->SetBinContent(31,0.7348689);
   RAA_0_100_copy617->SetBinContent(32,0.7565952);
   RAA_0_100_copy617->SetBinContent(33,0.7582413);
   RAA_0_100_copy617->SetBinContent(34,0.7690597);
   RAA_0_100_copy617->SetBinContent(35,0.8465348);
   RAA_0_100_copy617->SetBinContent(36,0.838195);
   RAA_0_100_copy617->SetBinContent(37,0.7198431);
   RAA_0_100_copy617->SetBinError(1,5.45556e-05);
   RAA_0_100_copy617->SetBinError(2,3.613189e-05);
   RAA_0_100_copy617->SetBinError(3,2.607049e-05);
   RAA_0_100_copy617->SetBinError(4,2.885564e-05);
   RAA_0_100_copy617->SetBinError(5,3.159594e-05);
   RAA_0_100_copy617->SetBinError(6,3.38567e-05);
   RAA_0_100_copy617->SetBinError(7,3.869295e-05);
   RAA_0_100_copy617->SetBinError(8,3.305379e-05);
   RAA_0_100_copy617->SetBinError(9,4.18263e-05);
   RAA_0_100_copy617->SetBinError(10,5.177436e-05);
   RAA_0_100_copy617->SetBinError(11,6.300253e-05);
   RAA_0_100_copy617->SetBinError(12,7.546549e-05);
   RAA_0_100_copy617->SetBinError(13,8.87769e-05);
   RAA_0_100_copy617->SetBinError(14,6.1286e-05);
   RAA_0_100_copy617->SetBinError(15,9.414707e-05);
   RAA_0_100_copy617->SetBinError(16,0.0001322857);
   RAA_0_100_copy617->SetBinError(17,0.0001814982);
   RAA_0_100_copy617->SetBinError(18,0.0002505459);
   RAA_0_100_copy617->SetBinError(19,0.0003376182);
   RAA_0_100_copy617->SetBinError(20,0.0003242908);
   RAA_0_100_copy617->SetBinError(21,0.0007237008);
   RAA_0_100_copy617->SetBinError(22,0.001286194);
   RAA_0_100_copy617->SetBinError(23,0.001729729);
   RAA_0_100_copy617->SetBinError(24,0.003645816);
   RAA_0_100_copy617->SetBinError(25,0.006132279);
   RAA_0_100_copy617->SetBinError(26,0.009164018);
   RAA_0_100_copy617->SetBinError(27,0.01215199);
   RAA_0_100_copy617->SetBinError(28,0.01470765);
   RAA_0_100_copy617->SetBinError(29,0.0127274);
   RAA_0_100_copy617->SetBinError(30,0.01638585);
   RAA_0_100_copy617->SetBinError(31,0.02569265);
   RAA_0_100_copy617->SetBinError(32,0.01410461);
   RAA_0_100_copy617->SetBinError(33,0.02175455);
   RAA_0_100_copy617->SetBinError(34,0.03042374);
   RAA_0_100_copy617->SetBinError(35,0.04570938);
   RAA_0_100_copy617->SetBinError(36,0.05478526);
   RAA_0_100_copy617->SetBinError(37,0.1718071);
   
   RAA_0_100_copy617->SetLineWidth(2);
   RAA_0_100_copy617->SetLineColor(kRed);
   RAA_0_100_copy617->SetMarkerStyle(20);
   RAA_0_100_copy617->SetMarkerSize(0.8);
   RAA_0_100_copy617->SetMarkerColor(kRed);
   RAA_0_100_copy617->Draw("same");

   /*
   RAA_0_100_copy617->SetMinimum(0);
   RAA_0_100_copy617->SetMaximum(1.6);
   RAA_0_100_copy617->SetEntries(7549.091);
   RAA_0_100_copy617->SetDirectory(0);
   RAA_0_100_copy617->SetLineWidth(2);
   RAA_0_100_copy617->SetMarkerStyle(20);
   RAA_0_100_copy617->SetMarkerSize(1.3);
   RAA_0_100_copy617->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_100_copy617->GetXaxis()->SetRange(3,37);
   RAA_0_100_copy617->GetXaxis()->CenterTitle(true);
   RAA_0_100_copy617->GetXaxis()->SetLabelFont(42);
   RAA_0_100_copy617->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_100_copy617->GetXaxis()->SetTitleSize(0.05);
   RAA_0_100_copy617->GetXaxis()->SetTitleFont(42);
   RAA_0_100_copy617->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_100_copy617->GetYaxis()->CenterTitle(true);
   RAA_0_100_copy617->GetYaxis()->SetLabelFont(42);
   RAA_0_100_copy617->GetYaxis()->SetTitleOffset(1.6);
   RAA_0_100_copy617->GetYaxis()->SetTitleFont(42);
   RAA_0_100_copy617->GetZaxis()->SetLabelFont(42);
   RAA_0_100_copy617->GetZaxis()->SetLabelSize(0.05);
   RAA_0_100_copy617->GetZaxis()->SetTitleSize(0.05);
   RAA_0_100_copy617->GetZaxis()->SetTitleFont(42);
   RAA_0_100_copy617->Draw("sameaxis");
   RAA->Modified();
   RAA->cd();
   RAA->SetSelected(RAA);
   
   
   */
}
