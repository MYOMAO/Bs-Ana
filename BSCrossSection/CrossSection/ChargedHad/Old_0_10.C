#include <TColor.h>
#include <TBox.h>
#include <TH1D.h>

void RAA_0_10()
{
//=========Macro generated from canvas: RAA/RAA
//=========  (Fri May 13 15:19:14 2016) by ROOT version6.02/10
/*
   TCanvas *RAA = new TCanvas("RAA", "RAA",1,1,800,676);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   RAA->Range(-0.6654505,-0.2175,2.738206,1.595);
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
   Double_t xAxis99[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_1099 = new TH1D("RAA_0_1099","",37, xAxis99);
   RAA_0_1099->SetBinContent(1,0.2204812);
   RAA_0_1099->SetBinContent(2,0.2806058);
   RAA_0_1099->SetBinContent(3,0.3026289);
   RAA_0_1099->SetBinContent(4,0.3233787);
   RAA_0_1099->SetBinContent(5,0.3495531);
   RAA_0_1099->SetBinContent(6,0.3602403);
   RAA_0_1099->SetBinContent(7,0.3745525);
   RAA_0_1099->SetBinContent(8,0.396096);
   RAA_0_1099->SetBinContent(9,0.4138229);
   RAA_0_1099->SetBinContent(10,0.4223151);
   RAA_0_1099->SetBinContent(11,0.4267318);
   RAA_0_1099->SetBinContent(12,0.4312452);
   RAA_0_1099->SetBinContent(13,0.4239881);
   RAA_0_1099->SetBinContent(14,0.3854727);
   RAA_0_1099->SetBinContent(15,0.2904028);
   RAA_0_1099->SetBinContent(16,0.2170938);
   RAA_0_1099->SetBinContent(17,0.1662815);
   RAA_0_1099->SetBinContent(18,0.1512486);
   RAA_0_1099->SetBinContent(19,0.1433652);
   RAA_0_1099->SetBinContent(20,0.1492991);
   RAA_0_1099->SetBinContent(21,0.1888814);
   RAA_0_1099->SetBinContent(22,0.207381);
   RAA_0_1099->SetBinContent(23,0.2564237);
   RAA_0_1099->SetBinContent(24,0.3120261);
   RAA_0_1099->SetBinContent(25,0.3682366);
   RAA_0_1099->SetBinContent(26,0.3985422);
   RAA_0_1099->SetBinContent(27,0.4102227);
   RAA_0_1099->SetBinContent(28,0.4918687);
   RAA_0_1099->SetBinContent(29,0.5209187);
   RAA_0_1099->SetBinContent(30,0.5663249);
   RAA_0_1099->SetBinContent(31,0.6440206);
   RAA_0_1099->SetBinContent(32,0.7107389);
   RAA_0_1099->SetBinContent(33,0.7066618);
   RAA_0_1099->SetBinContent(34,0.6867508);
   RAA_0_1099->SetBinContent(35,0.8296027);
   RAA_0_1099->SetBinContent(36,0.7835506);
   RAA_0_1099->SetBinContent(37,0.7204885);
   RAA_0_1099->SetBinError(1,3.7562e-05);
   RAA_0_1099->SetBinError(2,4.314339e-05);
   RAA_0_1099->SetBinError(3,3.759465e-05);
   RAA_0_1099->SetBinError(4,4.061309e-05);
   RAA_0_1099->SetBinError(5,4.239273e-05);
   RAA_0_1099->SetBinError(6,4.336703e-05);
   RAA_0_1099->SetBinError(7,4.944136e-05);
   RAA_0_1099->SetBinError(8,4.22748e-05);
   RAA_0_1099->SetBinError(9,5.344719e-05);
   RAA_0_1099->SetBinError(10,6.529357e-05);
   RAA_0_1099->SetBinError(11,7.969909e-05);
   RAA_0_1099->SetBinError(12,9.697649e-05);
   RAA_0_1099->SetBinError(13,0.000114489);
   RAA_0_1099->SetBinError(14,7.855225e-05);
   RAA_0_1099->SetBinError(15,0.0001186627);
   RAA_0_1099->SetBinError(16,0.0001661496);
   RAA_0_1099->SetBinError(17,0.0002162367);
   RAA_0_1099->SetBinError(18,0.0003005481);
   RAA_0_1099->SetBinError(19,0.000398822);
   RAA_0_1099->SetBinError(20,0.000383844);
   RAA_0_1099->SetBinError(21,0.0008844264);
   RAA_0_1099->SetBinError(22,0.001512016);
   RAA_0_1099->SetBinError(23,0.00218423);
   RAA_0_1099->SetBinError(24,0.00464483);
   RAA_0_1099->SetBinError(25,0.008240413);
   RAA_0_1099->SetBinError(26,0.01121434);
   RAA_0_1099->SetBinError(27,0.01532412);
   RAA_0_1099->SetBinError(28,0.02141374);
   RAA_0_1099->SetBinError(29,0.01869548);
   RAA_0_1099->SetBinError(30,0.02361322);
   RAA_0_1099->SetBinError(31,0.01739123);
   RAA_0_1099->SetBinError(32,0.02282954);
   RAA_0_1099->SetBinError(33,0.03096699);
   RAA_0_1099->SetBinError(34,0.04381948);
   RAA_0_1099->SetBinError(35,0.06763312);
   RAA_0_1099->SetBinError(36,0.07961082);
   RAA_0_1099->SetBinError(37,0.2839015);
   RAA_0_1099->SetMinimum(0);
   RAA_0_1099->SetMaximum(1.45);
   RAA_0_1099->SetEntries(2175.736);
   RAA_0_1099->SetDirectory(0);
   RAA_0_1099->SetLineWidth(2);
   RAA_0_1099->SetMarkerStyle(20);
   RAA_0_1099->SetMarkerSize(0.8);
   RAA_0_1099->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_1099->GetXaxis()->SetRange(3,37);
   RAA_0_1099->GetXaxis()->CenterTitle(true);
   RAA_0_1099->GetXaxis()->SetLabelFont(42);
   RAA_0_1099->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_1099->GetXaxis()->SetLabelSize(0.05);
   RAA_0_1099->GetXaxis()->SetTitleSize(0.05);
   RAA_0_1099->GetXaxis()->SetTitleFont(42);
   RAA_0_1099->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_1099->GetYaxis()->CenterTitle(true);
   RAA_0_1099->GetYaxis()->SetLabelFont(42);
   RAA_0_1099->GetYaxis()->SetLabelSize(0.05);
   RAA_0_1099->GetYaxis()->SetTitleSize(0.05);
   RAA_0_1099->GetYaxis()->SetTitleOffset(1.4);
   RAA_0_1099->GetYaxis()->SetTitleFont(42);
   RAA_0_1099->GetZaxis()->SetLabelFont(42);
   RAA_0_1099->GetZaxis()->SetLabelSize(0.05);
   RAA_0_1099->GetZaxis()->SetTitleSize(0.05);
   RAA_0_1099->GetZaxis()->SetTitleFont(42);
   RAA_0_1099->Draw("");
*/
   TBox *box = new TBox(0.9,0.982,1.161895,1.018);

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

   TLatex *   tex = new TLatex(0.9,0.1,"0-10%");
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
   */

   /*
   box = new TBox(0.7,0.2710793,0.8,0.3341785);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(0.8,0.2889511,0.9,0.3578064);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   */

   box = new TBox(0.9,0.3123389,1,0.3867673);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1,0.3218883,1.1,0.3985923);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.1,0.3346768,1.2,0.4144282);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.2,0.3501236,1.4,0.4420684);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.4,0.3657931,1.6,0.4618527);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.6,0.3671423,1.8,0.4774879);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.8,0.370982,2,0.4824817);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2,0.3684058,2.2,0.4940846);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2.2,0.3622062,2.4,0.48577);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2.4,0.3236019,3.2,0.4473434);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(3.2,0.2408229,4,0.3399827);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(4,0.1819436,4.8,0.2522439);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(4.8,0.1430853,5.6,0.1894776);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(5.6,0.1321564,6.4,0.1703408);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(6.4,0.1272992,7.2,0.1594313);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(7.2,0.1337345,9.6,0.1648637);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(9.6,0.1691904,12,0.2085725);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(12,0.1857573,14.4,0.2290047);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(14.4,0.2296906,19.2,0.2831568);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(19.2,0.2794913,24,0.3445609);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(24,0.3298282,28.8,0.406645);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(28.8,0.35695,35.2,0.4401344);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(35.2,0.3673698,41.6,0.4530756);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(41.6,0.4404435,48,0.5432939);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(48,0.4664195,60.8,0.5754179);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(60.8,0.5070414,73.6,0.6256085);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(73.6,0.5765582,86.4,0.7114829);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(86.4,0.6362811,103.6,0.7851968);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(103.6,0.6326256,120.8,0.7806979);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(120.8,0.6148005,140,0.7587012);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(140,0.7426859,165,0.9165195);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(165,0.7014586,250,0.8656426);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   /*
   box = new TBox(250,0.6450035,400,0.7959735);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   Double_t xAxis100[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_10100 = new TH1D("RAA_0_10100","",37, xAxis100);
   RAA_0_10100->SetBinContent(1,0.2204812);
   RAA_0_10100->SetBinContent(2,0.2806058);
   RAA_0_10100->SetBinContent(3,0.3026289);
   RAA_0_10100->SetBinContent(4,0.3233787);
   RAA_0_10100->SetBinContent(5,0.3495531);
   RAA_0_10100->SetBinContent(6,0.3602403);
   RAA_0_10100->SetBinContent(7,0.3745525);
   RAA_0_10100->SetBinContent(8,0.396096);
   RAA_0_10100->SetBinContent(9,0.4138229);
   RAA_0_10100->SetBinContent(10,0.4223151);
   RAA_0_10100->SetBinContent(11,0.4267318);
   RAA_0_10100->SetBinContent(12,0.4312452);
   RAA_0_10100->SetBinContent(13,0.4239881);
   RAA_0_10100->SetBinContent(14,0.3854727);
   RAA_0_10100->SetBinContent(15,0.2904028);
   RAA_0_10100->SetBinContent(16,0.2170938);
   RAA_0_10100->SetBinContent(17,0.1662815);
   RAA_0_10100->SetBinContent(18,0.1512486);
   RAA_0_10100->SetBinContent(19,0.1433652);
   RAA_0_10100->SetBinContent(20,0.1492991);
   RAA_0_10100->SetBinContent(21,0.1888814);
   RAA_0_10100->SetBinContent(22,0.207381);
   RAA_0_10100->SetBinContent(23,0.2564237);
   RAA_0_10100->SetBinContent(24,0.3120261);
   RAA_0_10100->SetBinContent(25,0.3682366);
   RAA_0_10100->SetBinContent(26,0.3985422);
   RAA_0_10100->SetBinContent(27,0.4102227);
   RAA_0_10100->SetBinContent(28,0.4918687);
   RAA_0_10100->SetBinContent(29,0.5209187);
   RAA_0_10100->SetBinContent(30,0.5663249);
   RAA_0_10100->SetBinContent(31,0.6440206);
   RAA_0_10100->SetBinContent(32,0.7107389);
   RAA_0_10100->SetBinContent(33,0.7066618);
   RAA_0_10100->SetBinContent(34,0.6867508);
   RAA_0_10100->SetBinContent(35,0.8296027);
   RAA_0_10100->SetBinContent(36,0.7835506);
   RAA_0_10100->SetBinContent(37,0.7204885);
   RAA_0_10100->SetBinError(1,3.7562e-05);
   RAA_0_10100->SetBinError(2,4.314339e-05);
   RAA_0_10100->SetBinError(3,3.759465e-05);
   RAA_0_10100->SetBinError(4,4.061309e-05);
   RAA_0_10100->SetBinError(5,4.239273e-05);
   RAA_0_10100->SetBinError(6,4.336703e-05);
   RAA_0_10100->SetBinError(7,4.944136e-05);
   RAA_0_10100->SetBinError(8,4.22748e-05);
   RAA_0_10100->SetBinError(9,5.344719e-05);
   RAA_0_10100->SetBinError(10,6.529357e-05);
   RAA_0_10100->SetBinError(11,7.969909e-05);
   RAA_0_10100->SetBinError(12,9.697649e-05);
   RAA_0_10100->SetBinError(13,0.000114489);
   RAA_0_10100->SetBinError(14,7.855225e-05);
   RAA_0_10100->SetBinError(15,0.0001186627);
   RAA_0_10100->SetBinError(16,0.0001661496);
   RAA_0_10100->SetBinError(17,0.0002162367);
   RAA_0_10100->SetBinError(18,0.0003005481);
   RAA_0_10100->SetBinError(19,0.000398822);
   RAA_0_10100->SetBinError(20,0.000383844);
   RAA_0_10100->SetBinError(21,0.0008844264);
   RAA_0_10100->SetBinError(22,0.001512016);
   RAA_0_10100->SetBinError(23,0.00218423);
   RAA_0_10100->SetBinError(24,0.00464483);
   RAA_0_10100->SetBinError(25,0.008240413);
   RAA_0_10100->SetBinError(26,0.01121434);
   RAA_0_10100->SetBinError(27,0.01532412);
   RAA_0_10100->SetBinError(28,0.02141374);
   RAA_0_10100->SetBinError(29,0.01869548);
   RAA_0_10100->SetBinError(30,0.02361322);
   RAA_0_10100->SetBinError(31,0.01739123);
   RAA_0_10100->SetBinError(32,0.02282954);
   RAA_0_10100->SetBinError(33,0.03096699);
   RAA_0_10100->SetBinError(34,0.04381948);
   RAA_0_10100->SetBinError(35,0.06763312);
   RAA_0_10100->SetBinError(36,0.07961082);
   RAA_0_10100->SetBinError(37,0.2839015);
   RAA_0_10100->SetMinimum(0);
   RAA_0_10100->SetMaximum(1.45);
   RAA_0_10100->SetEntries(2175.736);
   RAA_0_10100->SetDirectory(0);
   RAA_0_10100->SetLineWidth(2);
   RAA_0_10100->SetMarkerStyle(20);
   RAA_0_10100->SetMarkerSize(0.8);
   RAA_0_10100->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_10100->GetXaxis()->SetRange(3,37);
   RAA_0_10100->GetXaxis()->CenterTitle(true);
   RAA_0_10100->GetXaxis()->SetLabelFont(42);
   RAA_0_10100->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_10100->GetXaxis()->SetLabelSize(0.05);
   RAA_0_10100->GetXaxis()->SetTitleSize(0.05);
   RAA_0_10100->GetXaxis()->SetTitleFont(42);
   RAA_0_10100->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_10100->GetYaxis()->CenterTitle(true);
   RAA_0_10100->GetYaxis()->SetLabelFont(42);
   RAA_0_10100->GetYaxis()->SetLabelSize(0.05);
   RAA_0_10100->GetYaxis()->SetTitleSize(0.05);
   RAA_0_10100->GetYaxis()->SetTitleOffset(1.4);
   RAA_0_10100->GetYaxis()->SetTitleFont(42);
   RAA_0_10100->GetZaxis()->SetLabelFont(42);
   RAA_0_10100->GetZaxis()->SetLabelSize(0.05);
   RAA_0_10100->GetZaxis()->SetTitleSize(0.05);
   RAA_0_10100->GetZaxis()->SetTitleFont(42);
   RAA_0_10100->Draw("same");
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
   Double_t xAxis101[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_10_copy101 = new TH1D("RAA_0_10_copy101","",37, xAxis101);
   RAA_0_10_copy101->SetBinContent(1,-1);
   RAA_0_10_copy101->SetBinContent(2,-1);
   RAA_0_10_copy101->SetBinContent(3,-1);
   RAA_0_10_copy101->SetBinContent(4,-1);
   /*
   RAA_0_10_copy101->SetBinContent(1,0.2204812);
   RAA_0_10_copy101->SetBinContent(2,0.2806058);
   RAA_0_10_copy101->SetBinContent(3,0.3026289);
   RAA_0_10_copy101->SetBinContent(4,0.3233787);
   */
   RAA_0_10_copy101->SetBinContent(5,0.3495531);
   RAA_0_10_copy101->SetBinContent(6,0.3602403);
   RAA_0_10_copy101->SetBinContent(7,0.3745525);
   RAA_0_10_copy101->SetBinContent(8,0.396096);
   RAA_0_10_copy101->SetBinContent(9,0.4138229);
   RAA_0_10_copy101->SetBinContent(10,0.4223151);
   RAA_0_10_copy101->SetBinContent(11,0.4267318);
   RAA_0_10_copy101->SetBinContent(12,0.4312452);
   RAA_0_10_copy101->SetBinContent(13,0.4239881);
   RAA_0_10_copy101->SetBinContent(14,0.3854727);
   RAA_0_10_copy101->SetBinContent(15,0.2904028);
   RAA_0_10_copy101->SetBinContent(16,0.2170938);
   RAA_0_10_copy101->SetBinContent(17,0.1662815);
   RAA_0_10_copy101->SetBinContent(18,0.1512486);
   RAA_0_10_copy101->SetBinContent(19,0.1433652);
   RAA_0_10_copy101->SetBinContent(20,0.1492991);
   RAA_0_10_copy101->SetBinContent(21,0.1888814);
   RAA_0_10_copy101->SetBinContent(22,0.207381);
   RAA_0_10_copy101->SetBinContent(23,0.2564237);
   RAA_0_10_copy101->SetBinContent(24,0.3120261);
   RAA_0_10_copy101->SetBinContent(25,0.3682366);
   RAA_0_10_copy101->SetBinContent(26,0.3985422);
   RAA_0_10_copy101->SetBinContent(27,0.4102227);
   RAA_0_10_copy101->SetBinContent(28,0.4918687);
   RAA_0_10_copy101->SetBinContent(29,0.5209187);
   RAA_0_10_copy101->SetBinContent(30,0.5663249);
   RAA_0_10_copy101->SetBinContent(31,0.6440206);
   RAA_0_10_copy101->SetBinContent(32,0.7107389);

   RAA_0_10_copy101->SetBinContent(33,0.7066618);
   RAA_0_10_copy101->SetBinContent(34,0.6867508);
   RAA_0_10_copy101->SetBinContent(35,0.8296027);
   RAA_0_10_copy101->SetBinContent(36,0.7835506);
   RAA_0_10_copy101->SetBinContent(37,0.7204885);

   RAA_0_10_copy101->SetBinError(1,3.7562e-05);
   RAA_0_10_copy101->SetBinError(2,4.314339e-05);
   RAA_0_10_copy101->SetBinError(3,3.759465e-05);
   RAA_0_10_copy101->SetBinError(4,4.061309e-05);
   RAA_0_10_copy101->SetBinError(5,4.239273e-05);
   RAA_0_10_copy101->SetBinError(6,4.336703e-05);
   RAA_0_10_copy101->SetBinError(7,4.944136e-05);
   RAA_0_10_copy101->SetBinError(8,4.22748e-05);
   RAA_0_10_copy101->SetBinError(9,5.344719e-05);
   RAA_0_10_copy101->SetBinError(10,6.529357e-05);
   RAA_0_10_copy101->SetBinError(11,7.969909e-05);
   RAA_0_10_copy101->SetBinError(12,9.697649e-05);
   RAA_0_10_copy101->SetBinError(13,0.000114489);
   RAA_0_10_copy101->SetBinError(14,7.855225e-05);
   RAA_0_10_copy101->SetBinError(15,0.0001186627);
   RAA_0_10_copy101->SetBinError(16,0.0001661496);
   RAA_0_10_copy101->SetBinError(17,0.0002162367);
   RAA_0_10_copy101->SetBinError(18,0.0003005481);
   RAA_0_10_copy101->SetBinError(19,0.000398822);
   RAA_0_10_copy101->SetBinError(20,0.000383844);
   RAA_0_10_copy101->SetBinError(21,0.0008844264);
   RAA_0_10_copy101->SetBinError(22,0.001512016);
   RAA_0_10_copy101->SetBinError(23,0.00218423);
   RAA_0_10_copy101->SetBinError(24,0.00464483);
   RAA_0_10_copy101->SetBinError(25,0.008240413);
   RAA_0_10_copy101->SetBinError(26,0.01121434);
   RAA_0_10_copy101->SetBinError(27,0.01532412);
   RAA_0_10_copy101->SetBinError(28,0.02141374);
   RAA_0_10_copy101->SetBinError(29,0.01869548);
   RAA_0_10_copy101->SetBinError(30,0.02361322);
   RAA_0_10_copy101->SetBinError(31,0.01739123);
   RAA_0_10_copy101->SetBinError(32,0.02282954);
   RAA_0_10_copy101->SetBinError(33,0.03096699);
   RAA_0_10_copy101->SetBinError(34,0.04381948);
   RAA_0_10_copy101->SetBinError(35,0.06763312);
   RAA_0_10_copy101->SetBinError(36,0.07961082);
   RAA_0_10_copy101->SetBinError(37,0.2839015);
   /*
   RAA_0_10_copy101->SetMinimum(0);
   RAA_0_10_copy101->SetMaximum(1.45);
   RAA_0_10_copy101->SetEntries(2175.736);
   RAA_0_10_copy101->SetDirectory(0);
   RAA_0_10_copy101->SetLineWidth(2);
   RAA_0_10_copy101->SetMarkerStyle(20);
   RAA_0_10_copy101->SetMarkerSize(0.8);
   RAA_0_10_copy101->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_10_copy101->GetXaxis()->SetRange(3,37);
   RAA_0_10_copy101->GetXaxis()->CenterTitle(true);
   RAA_0_10_copy101->GetXaxis()->SetLabelFont(42);
   RAA_0_10_copy101->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_10_copy101->GetXaxis()->SetLabelSize(0.05);
   RAA_0_10_copy101->GetXaxis()->SetTitleSize(0.05);
   RAA_0_10_copy101->GetXaxis()->SetTitleFont(42);
   RAA_0_10_copy101->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_10_copy101->GetYaxis()->CenterTitle(true);
   RAA_0_10_copy101->GetYaxis()->SetLabelFont(42);
   RAA_0_10_copy101->GetYaxis()->SetLabelSize(0.05);
   RAA_0_10_copy101->GetYaxis()->SetTitleSize(0.05);
   RAA_0_10_copy101->GetYaxis()->SetTitleOffset(1.4);
   RAA_0_10_copy101->GetYaxis()->SetTitleFont(42);
   RAA_0_10_copy101->GetZaxis()->SetLabelFont(42);
   RAA_0_10_copy101->GetZaxis()->SetLabelSize(0.05);
   RAA_0_10_copy101->GetZaxis()->SetTitleSize(0.05);
   RAA_0_10_copy101->GetZaxis()->SetTitleFont(42);
   RAA_0_10_copy101->Draw("sameaxis");
   RAA->Modified();
   RAA->cd();
   RAA->SetSelected(RAA);
   */
   RAA_0_10_copy101->SetLineWidth(2);
   RAA_0_10_copy101->SetLineColor(kRed);
   RAA_0_10_copy101->SetMarkerStyle(20);
   RAA_0_10_copy101->SetMarkerSize(0.8);
   RAA_0_10_copy101->SetMarkerColor(kRed);
   RAA_0_10_copy101->Draw("same");
}
