#include <TColor.h>
#include <TBox.h>
#include <TH1D.h>

void RAA_0_10()
{
//=========Macro generated from canvas: RAA/RAA
//=========  (Fri May 20 18:48:22 2016) by ROOT version6.02/10
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
   Double_t xAxis392[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_10648 = new TH1D("RAA_0_10648","",37, xAxis392);
   RAA_0_10648->SetBinContent(1,0.329664);
   RAA_0_10648->SetBinContent(2,0.3222867);
   RAA_0_10648->SetBinContent(3,0.301588);
   RAA_0_10648->SetBinContent(4,0.3233953);
   RAA_0_10648->SetBinContent(5,0.3504778);
   RAA_0_10648->SetBinContent(6,0.364188);
   RAA_0_10648->SetBinContent(7,0.3750847);
   RAA_0_10648->SetBinContent(8,0.3969639);
   RAA_0_10648->SetBinContent(9,0.4119907);
   RAA_0_10648->SetBinContent(10,0.4240788);
   RAA_0_10648->SetBinContent(11,0.4259811);
   RAA_0_10648->SetBinContent(12,0.4296807);
   RAA_0_10648->SetBinContent(13,0.4207418);
   RAA_0_10648->SetBinContent(14,0.3876461);
   RAA_0_10648->SetBinContent(15,0.2967605);
   RAA_0_10648->SetBinContent(16,0.2225874);
   RAA_0_10648->SetBinContent(17,0.1704491);
   RAA_0_10648->SetBinContent(18,0.1567843);
   RAA_0_10648->SetBinContent(19,0.1418605);
   RAA_0_10648->SetBinContent(20,0.1473989);
   RAA_0_10648->SetBinContent(21,0.189161);
   RAA_0_10648->SetBinContent(22,0.2234717);
   RAA_0_10648->SetBinContent(23,0.2725377);
   RAA_0_10648->SetBinContent(24,0.3147641);
   RAA_0_10648->SetBinContent(25,0.3659665);
   RAA_0_10648->SetBinContent(26,0.4102998);
   RAA_0_10648->SetBinContent(27,0.4057602);
   RAA_0_10648->SetBinContent(28,0.5148934);
   RAA_0_10648->SetBinContent(29,0.5395297);
   RAA_0_10648->SetBinContent(30,0.5980593);
   RAA_0_10648->SetBinContent(31,0.6846947);
   RAA_0_10648->SetBinContent(32,0.7005613);
   RAA_0_10648->SetBinContent(33,0.6930027);
   RAA_0_10648->SetBinContent(34,0.6483107);
   RAA_0_10648->SetBinContent(35,0.8585297);
   RAA_0_10648->SetBinContent(36,0.7691633);
   RAA_0_10648->SetBinContent(37,0.5914436);
   RAA_0_10648->SetBinError(1,0.0001184389);
   RAA_0_10648->SetBinError(2,6.846512e-05);
   RAA_0_10648->SetBinError(3,3.733913e-05);
   RAA_0_10648->SetBinError(4,4.058976e-05);
   RAA_0_10648->SetBinError(5,4.252102e-05);
   RAA_0_10648->SetBinError(6,4.377422e-05);
   RAA_0_10648->SetBinError(7,4.941479e-05);
   RAA_0_10648->SetBinError(8,4.223718e-05);
   RAA_0_10648->SetBinError(9,5.297191e-05);
   RAA_0_10648->SetBinError(10,6.518282e-05);
   RAA_0_10648->SetBinError(11,7.903593e-05);
   RAA_0_10648->SetBinError(12,9.591532e-05);
   RAA_0_10648->SetBinError(13,0.000112673);
   RAA_0_10648->SetBinError(14,7.814679e-05);
   RAA_0_10648->SetBinError(15,0.0001194238);
   RAA_0_10648->SetBinError(16,0.0001674997);
   RAA_0_10648->SetBinError(17,0.0002170065);
   RAA_0_10648->SetBinError(18,0.0003041568);
   RAA_0_10648->SetBinError(19,0.0003855818);
   RAA_0_10648->SetBinError(20,0.0003700719);
   RAA_0_10648->SetBinError(21,0.0008733662);
   RAA_0_10648->SetBinError(22,0.001607174);
   RAA_0_10648->SetBinError(23,0.002303064);
   RAA_0_10648->SetBinError(24,0.004635329);
   RAA_0_10648->SetBinError(25,0.008256834);
   RAA_0_10648->SetBinError(26,0.01180725);
   RAA_0_10648->SetBinError(27,0.01550079);
   RAA_0_10648->SetBinError(28,0.02271527);
   RAA_0_10648->SetBinError(29,0.01950407);
   RAA_0_10648->SetBinError(30,0.03237383);
   RAA_0_10648->SetBinError(31,0.05592587);
   RAA_0_10648->SetBinError(32,0.02231718);
   RAA_0_10648->SetBinError(33,0.02976742);
   RAA_0_10648->SetBinError(34,0.04073585);
   RAA_0_10648->SetBinError(35,0.06854561);
   RAA_0_10648->SetBinError(36,0.07702628);
   RAA_0_10648->SetBinError(37,0.2307548);
   RAA_0_10648->SetMinimum(0);
   RAA_0_10648->SetMaximum(1.6);
   RAA_0_10648->SetEntries(2912.194);
   RAA_0_10648->SetDirectory(0);
   RAA_0_10648->SetLineWidth(2);
   RAA_0_10648->SetMarkerStyle(20);
   RAA_0_10648->SetMarkerSize(1.3);
   RAA_0_10648->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_10648->GetXaxis()->SetRange(3,37);
   RAA_0_10648->GetXaxis()->CenterTitle(true);
   RAA_0_10648->GetXaxis()->SetLabelFont(42);
   RAA_0_10648->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_10648->GetXaxis()->SetTitleSize(0.05);
   RAA_0_10648->GetXaxis()->SetTitleFont(42);
   RAA_0_10648->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_10648->GetYaxis()->CenterTitle(true);
   RAA_0_10648->GetYaxis()->SetLabelFont(42);
   RAA_0_10648->GetYaxis()->SetTitleOffset(1.6);
   RAA_0_10648->GetYaxis()->SetTitleFont(42);
   RAA_0_10648->GetZaxis()->SetLabelFont(42);
   RAA_0_10648->GetZaxis()->SetLabelSize(0.05);
   RAA_0_10648->GetZaxis()->SetTitleSize(0.05);
   RAA_0_10648->GetZaxis()->SetTitleFont(42);
   RAA_0_10648->Draw("");
   */
   TBox *box = new TBox(0.9,0.983,1.161895,1.017);

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
   box = new TBox(0.7,0.2701468,0.8,0.3330291);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(0.8,0.2891212,0.9,0.3576695);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(0.9,0.3133335,1,0.3876222);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
*/
   box = new TBox(1,0.3255906,1.1,0.4027854);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.1,0.3353324,1.2,0.414837);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.2,0.3511598,1.4,0.4427681);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.4,0.3644527,1.6,0.4595287);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.6,0.3691054,1.8,0.4790522);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(1.8,0.3707611,2,0.4812011);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2,0.3676907,2.2,0.4916707);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2.2,0.3600414,2.4,0.4814422);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(2.4,0.324703,3.2,0.4505893);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(3.2,0.2421617,4,0.3513593);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(4,0.1820723,4.8,0.2631026);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(4.8,0.1434589,5.6,0.1974393);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(5.6,0.1353602,6.4,0.1782084);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(6.4,0.1265667,7.2,0.1571544);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(7.2,0.1320324,9.6,0.1627655);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(9.6,0.1694409,12,0.2088812);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(12,0.2001703,14.4,0.246773);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(14.4,0.2441249,19.2,0.3009504);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(19.2,0.2819447,24,0.3475834);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(24,0.3277959,28.8,0.4041371);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(28.8,0.3674862,35.2,0.4531135);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(35.2,0.3633765,41.6,0.4481438);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(41.6,0.4610675,48,0.5687192);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(48,0.4830849,60.8,0.5959744);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(60.8,0.5354735,73.6,0.6606451);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(73.6,0.6130315,86.4,0.756358);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(86.4,0.6271697,103.6,0.7739528);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(103.6,0.6203975,120.8,0.7656078);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(120.8,0.5803877,140,0.7162337);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(140,0.7685822,165,0.9484771);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(165,0.6885787,250,0.8497479);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(250,0.5294786,400,0.6534087);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   
   /*
   Double_t xAxis393[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_10649 = new TH1D("RAA_0_10649","",37, xAxis393);
   RAA_0_10649->SetBinContent(1,0.329664);
   RAA_0_10649->SetBinContent(2,0.3222867);
   RAA_0_10649->SetBinContent(3,0.301588);
   RAA_0_10649->SetBinContent(4,0.3233953);
   RAA_0_10649->SetBinContent(5,0.3504778);
   RAA_0_10649->SetBinContent(6,0.364188);
   RAA_0_10649->SetBinContent(7,0.3750847);
   RAA_0_10649->SetBinContent(8,0.3969639);
   RAA_0_10649->SetBinContent(9,0.4119907);
   RAA_0_10649->SetBinContent(10,0.4240788);
   RAA_0_10649->SetBinContent(11,0.4259811);
   RAA_0_10649->SetBinContent(12,0.4296807);
   RAA_0_10649->SetBinContent(13,0.4207418);
   RAA_0_10649->SetBinContent(14,0.3876461);
   RAA_0_10649->SetBinContent(15,0.2967605);
   RAA_0_10649->SetBinContent(16,0.2225874);
   RAA_0_10649->SetBinContent(17,0.1704491);
   RAA_0_10649->SetBinContent(18,0.1567843);
   RAA_0_10649->SetBinContent(19,0.1418605);
   RAA_0_10649->SetBinContent(20,0.1473989);
   RAA_0_10649->SetBinContent(21,0.189161);
   RAA_0_10649->SetBinContent(22,0.2234717);
   RAA_0_10649->SetBinContent(23,0.2725377);
   RAA_0_10649->SetBinContent(24,0.3147641);
   RAA_0_10649->SetBinContent(25,0.3659665);
   RAA_0_10649->SetBinContent(26,0.4102998);
   RAA_0_10649->SetBinContent(27,0.4057602);
   RAA_0_10649->SetBinContent(28,0.5148934);
   RAA_0_10649->SetBinContent(29,0.5395297);
   RAA_0_10649->SetBinContent(30,0.5980593);
   RAA_0_10649->SetBinContent(31,0.6846947);
   RAA_0_10649->SetBinContent(32,0.7005613);
   RAA_0_10649->SetBinContent(33,0.6930027);
   RAA_0_10649->SetBinContent(34,0.6483107);
   RAA_0_10649->SetBinContent(35,0.8585297);
   RAA_0_10649->SetBinContent(36,0.7691633);
   RAA_0_10649->SetBinContent(37,0.5914436);
   RAA_0_10649->SetBinError(1,0.0001184389);
   RAA_0_10649->SetBinError(2,6.846512e-05);
   RAA_0_10649->SetBinError(3,3.733913e-05);
   RAA_0_10649->SetBinError(4,4.058976e-05);
   RAA_0_10649->SetBinError(5,4.252102e-05);
   RAA_0_10649->SetBinError(6,4.377422e-05);
   RAA_0_10649->SetBinError(7,4.941479e-05);
   RAA_0_10649->SetBinError(8,4.223718e-05);
   RAA_0_10649->SetBinError(9,5.297191e-05);
   RAA_0_10649->SetBinError(10,6.518282e-05);
   RAA_0_10649->SetBinError(11,7.903593e-05);
   RAA_0_10649->SetBinError(12,9.591532e-05);
   RAA_0_10649->SetBinError(13,0.000112673);
   RAA_0_10649->SetBinError(14,7.814679e-05);
   RAA_0_10649->SetBinError(15,0.0001194238);
   RAA_0_10649->SetBinError(16,0.0001674997);
   RAA_0_10649->SetBinError(17,0.0002170065);
   RAA_0_10649->SetBinError(18,0.0003041568);
   RAA_0_10649->SetBinError(19,0.0003855818);
   RAA_0_10649->SetBinError(20,0.0003700719);
   RAA_0_10649->SetBinError(21,0.0008733662);
   RAA_0_10649->SetBinError(22,0.001607174);
   RAA_0_10649->SetBinError(23,0.002303064);
   RAA_0_10649->SetBinError(24,0.004635329);
   RAA_0_10649->SetBinError(25,0.008256834);
   RAA_0_10649->SetBinError(26,0.01180725);
   RAA_0_10649->SetBinError(27,0.01550079);
   RAA_0_10649->SetBinError(28,0.02271527);
   RAA_0_10649->SetBinError(29,0.01950407);
   RAA_0_10649->SetBinError(30,0.03237383);
   RAA_0_10649->SetBinError(31,0.05592587);
   RAA_0_10649->SetBinError(32,0.02231718);
   RAA_0_10649->SetBinError(33,0.02976742);
   RAA_0_10649->SetBinError(34,0.04073585);
   RAA_0_10649->SetBinError(35,0.06854561);
   RAA_0_10649->SetBinError(36,0.07702628);
   RAA_0_10649->SetBinError(37,0.2307548);
   RAA_0_10649->SetMinimum(0);
   RAA_0_10649->SetMaximum(1.6);
   RAA_0_10649->SetEntries(2912.194);
   RAA_0_10649->SetDirectory(0);
   RAA_0_10649->SetLineWidth(2);
   RAA_0_10649->SetMarkerStyle(20);
   RAA_0_10649->SetMarkerSize(1.3);
   RAA_0_10649->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_10649->GetXaxis()->SetRange(3,37);
   RAA_0_10649->GetXaxis()->CenterTitle(true);
   RAA_0_10649->GetXaxis()->SetLabelFont(42);
   RAA_0_10649->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_10649->GetXaxis()->SetTitleSize(0.05);
   RAA_0_10649->GetXaxis()->SetTitleFont(42);
   RAA_0_10649->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_10649->GetYaxis()->CenterTitle(true);
   RAA_0_10649->GetYaxis()->SetLabelFont(42);
   RAA_0_10649->GetYaxis()->SetTitleOffset(1.6);
   RAA_0_10649->GetYaxis()->SetTitleFont(42);
   RAA_0_10649->GetZaxis()->SetLabelFont(42);
   RAA_0_10649->GetZaxis()->SetLabelSize(0.05);
   RAA_0_10649->GetZaxis()->SetTitleSize(0.05);
   RAA_0_10649->GetZaxis()->SetTitleFont(42);
   RAA_0_10649->Draw("same");
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
   Double_t xAxis394[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_10_copy650 = new TH1D("RAA_0_10_copy650","",37, xAxis394);
   
   RAA_0_10_copy650->SetBinContent(1,-1);
   RAA_0_10_copy650->SetBinContent(2,-1);
   RAA_0_10_copy650->SetBinContent(3,-1);
   RAA_0_10_copy650->SetBinContent(4,-1);
   RAA_0_10_copy650->SetBinContent(5,-1);
   RAA_0_10_copy650->SetBinContent(6,0.364188);
   RAA_0_10_copy650->SetBinContent(7,0.3750847);
   RAA_0_10_copy650->SetBinContent(8,0.3969639);
   RAA_0_10_copy650->SetBinContent(9,0.4119907);
   RAA_0_10_copy650->SetBinContent(10,0.4240788);
   RAA_0_10_copy650->SetBinContent(11,0.4259811);
   RAA_0_10_copy650->SetBinContent(12,0.4296807);
   RAA_0_10_copy650->SetBinContent(13,0.4207418);
   RAA_0_10_copy650->SetBinContent(14,0.3876461);
   RAA_0_10_copy650->SetBinContent(15,0.2967605);
   RAA_0_10_copy650->SetBinContent(16,0.2225874);
   RAA_0_10_copy650->SetBinContent(17,0.1704491);
   RAA_0_10_copy650->SetBinContent(18,0.1567843);
   RAA_0_10_copy650->SetBinContent(19,0.1418605);
   RAA_0_10_copy650->SetBinContent(20,0.1473989);
   RAA_0_10_copy650->SetBinContent(21,0.189161);
   RAA_0_10_copy650->SetBinContent(22,0.2234717);
   RAA_0_10_copy650->SetBinContent(23,0.2725377);
   RAA_0_10_copy650->SetBinContent(24,0.3147641);
   RAA_0_10_copy650->SetBinContent(25,0.3659665);
   RAA_0_10_copy650->SetBinContent(26,0.4102998);
   RAA_0_10_copy650->SetBinContent(27,0.4057602);
   RAA_0_10_copy650->SetBinContent(28,0.5148934);
   RAA_0_10_copy650->SetBinContent(29,0.5395297);
   RAA_0_10_copy650->SetBinContent(30,0.5980593);
   RAA_0_10_copy650->SetBinContent(31,0.6846947);
   RAA_0_10_copy650->SetBinContent(32,0.7005613);
   RAA_0_10_copy650->SetBinContent(33,0.6930027);
   RAA_0_10_copy650->SetBinContent(34,0.6483107);
   RAA_0_10_copy650->SetBinContent(35,0.8585297);
   RAA_0_10_copy650->SetBinContent(36,0.7691633);
   RAA_0_10_copy650->SetBinContent(37,0.5914436);
   RAA_0_10_copy650->SetBinError(1,0.0001184389);
   RAA_0_10_copy650->SetBinError(2,6.846512e-05);
   RAA_0_10_copy650->SetBinError(3,3.733913e-05);
   RAA_0_10_copy650->SetBinError(4,4.058976e-05);
   RAA_0_10_copy650->SetBinError(5,4.252102e-05);
   RAA_0_10_copy650->SetBinError(6,4.377422e-05);
   RAA_0_10_copy650->SetBinError(7,4.941479e-05);
   RAA_0_10_copy650->SetBinError(8,4.223718e-05);
   RAA_0_10_copy650->SetBinError(9,5.297191e-05);
   RAA_0_10_copy650->SetBinError(10,6.518282e-05);
   RAA_0_10_copy650->SetBinError(11,7.903593e-05);
   RAA_0_10_copy650->SetBinError(12,9.591532e-05);
   RAA_0_10_copy650->SetBinError(13,0.000112673);
   RAA_0_10_copy650->SetBinError(14,7.814679e-05);
   RAA_0_10_copy650->SetBinError(15,0.0001194238);
   RAA_0_10_copy650->SetBinError(16,0.0001674997);
   RAA_0_10_copy650->SetBinError(17,0.0002170065);
   RAA_0_10_copy650->SetBinError(18,0.0003041568);
   RAA_0_10_copy650->SetBinError(19,0.0003855818);
   RAA_0_10_copy650->SetBinError(20,0.0003700719);
   RAA_0_10_copy650->SetBinError(21,0.0008733662);
   RAA_0_10_copy650->SetBinError(22,0.001607174);
   RAA_0_10_copy650->SetBinError(23,0.002303064);
   RAA_0_10_copy650->SetBinError(24,0.004635329);
   RAA_0_10_copy650->SetBinError(25,0.008256834);
   RAA_0_10_copy650->SetBinError(26,0.01180725);
   RAA_0_10_copy650->SetBinError(27,0.01550079);
   RAA_0_10_copy650->SetBinError(28,0.02271527);
   RAA_0_10_copy650->SetBinError(29,0.01950407);
   RAA_0_10_copy650->SetBinError(30,0.03237383);
   RAA_0_10_copy650->SetBinError(31,0.05592587);
   RAA_0_10_copy650->SetBinError(32,0.02231718);
   RAA_0_10_copy650->SetBinError(33,0.02976742);
   RAA_0_10_copy650->SetBinError(34,0.04073585);
   RAA_0_10_copy650->SetBinError(35,0.06854561);
   RAA_0_10_copy650->SetBinError(36,0.07702628);
   RAA_0_10_copy650->SetBinError(37,0.2307548);
   
   
   RAA_0_10_copy650->SetLineWidth(2);
   RAA_0_10_copy650->SetLineColor(kRed);
   RAA_0_10_copy650->SetMarkerStyle(20);
   RAA_0_10_copy650->SetMarkerSize(0.8);
   RAA_0_10_copy650->SetMarkerColor(kRed);
   RAA_0_10_copy650->Draw("same");

   /*
   RAA_0_10_copy650->SetMinimum(0);
   RAA_0_10_copy650->SetMaximum(1.6);
   RAA_0_10_copy650->SetEntries(2912.194);
   RAA_0_10_copy650->SetDirectory(0);
   RAA_0_10_copy650->SetLineWidth(2);
   RAA_0_10_copy650->SetMarkerStyle(20);
   RAA_0_10_copy650->SetMarkerSize(1.3);
   RAA_0_10_copy650->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_10_copy650->GetXaxis()->SetRange(3,37);
   RAA_0_10_copy650->GetXaxis()->CenterTitle(true);
   RAA_0_10_copy650->GetXaxis()->SetLabelFont(42);
   RAA_0_10_copy650->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_10_copy650->GetXaxis()->SetTitleSize(0.05);
   RAA_0_10_copy650->GetXaxis()->SetTitleFont(42);
   RAA_0_10_copy650->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_10_copy650->GetYaxis()->CenterTitle(true);
   RAA_0_10_copy650->GetYaxis()->SetLabelFont(42);
   RAA_0_10_copy650->GetYaxis()->SetTitleOffset(1.6);
   RAA_0_10_copy650->GetYaxis()->SetTitleFont(42);
   RAA_0_10_copy650->GetZaxis()->SetLabelFont(42);
   RAA_0_10_copy650->GetZaxis()->SetLabelSize(0.05);
   RAA_0_10_copy650->GetZaxis()->SetTitleSize(0.05);
   RAA_0_10_copy650->GetZaxis()->SetTitleFont(42);
   RAA_0_10_copy650->Draw("sameaxis");
   RAA->Modified();
   RAA->cd();
   RAA->SetSelected(RAA);
   */
}
