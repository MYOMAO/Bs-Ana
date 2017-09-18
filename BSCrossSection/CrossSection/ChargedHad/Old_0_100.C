#include <TColor.h>
#include <TBox.h>
#include <TH1D.h>

void RAA_0_100()
{
//=========Macro generated from canvas: RAA/RAA
//=========  (Fri May 13 15:19:12 2016) by ROOT version6.02/10
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
   Double_t xAxis66[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_10066 = new TH1D("RAA_0_10066","",37, xAxis66);
   RAA_0_10066->SetBinContent(1,0.2879894);
   RAA_0_10066->SetBinContent(2,0.3313456);
   RAA_0_10066->SetBinContent(3,0.3462058);
   RAA_0_10066->SetBinContent(4,0.3693359);
   RAA_0_10066->SetBinContent(5,0.3992552);
   RAA_0_10066->SetBinContent(6,0.4154228);
   RAA_0_10066->SetBinContent(7,0.4330702);
   RAA_0_10066->SetBinContent(8,0.4549119);
   RAA_0_10066->SetBinContent(9,0.4744453);
   RAA_0_10066->SetBinContent(10,0.4881788);
   RAA_0_10066->SetBinContent(11,0.4939881);
   RAA_0_10066->SetBinContent(12,0.4926561);
   RAA_0_10066->SetBinContent(13,0.4841838);
   RAA_0_10066->SetBinContent(14,0.4488303);
   RAA_0_10066->SetBinContent(15,0.3615875);
   RAA_0_10066->SetBinContent(16,0.2881784);
   RAA_0_10066->SetBinContent(17,0.2431273);
   RAA_0_10066->SetBinContent(18,0.2222835);
   RAA_0_10066->SetBinContent(19,0.2175955);
   RAA_0_10066->SetBinContent(20,0.2270155);
   RAA_0_10066->SetBinContent(21,0.2731642);
   RAA_0_10066->SetBinContent(22,0.2970666);
   RAA_0_10066->SetBinContent(23,0.3489187);
   RAA_0_10066->SetBinContent(24,0.4170735);
   RAA_0_10066->SetBinContent(25,0.4594024);
   RAA_0_10066->SetBinContent(26,0.495269);
   RAA_0_10066->SetBinContent(27,0.5240523);
   RAA_0_10066->SetBinContent(28,0.5719975);
   RAA_0_10066->SetBinContent(29,0.6299889);
   RAA_0_10066->SetBinContent(30,0.6623098);
   RAA_0_10066->SetBinContent(31,0.729187);
   RAA_0_10066->SetBinContent(32,0.7704618);
   RAA_0_10066->SetBinContent(33,0.7735723);
   RAA_0_10066->SetBinContent(34,0.7931861);
   RAA_0_10066->SetBinContent(35,0.8344583);
   RAA_0_10066->SetBinContent(36,0.8295234);
   RAA_0_10066->SetBinContent(37,0.8477847);
   RAA_0_10066->SetBinError(1,2.568238e-05);
   RAA_0_10066->SetBinError(2,2.824522e-05);
   RAA_0_10066->SetBinError(3,2.647242e-05);
   RAA_0_10066->SetBinError(4,2.919912e-05);
   RAA_0_10066->SetBinError(5,3.185709e-05);
   RAA_0_10066->SetBinError(6,3.397847e-05);
   RAA_0_10066->SetBinError(7,3.903175e-05);
   RAA_0_10066->SetBinError(8,3.338616e-05);
   RAA_0_10066->SetBinError(9,4.243359e-05);
   RAA_0_10066->SetBinError(10,5.248198e-05);
   RAA_0_10066->SetBinError(11,6.426495e-05);
   RAA_0_10066->SetBinError(12,7.687639e-05);
   RAA_0_10066->SetBinError(13,9.041817e-05);
   RAA_0_10066->SetBinError(14,6.230362e-05);
   RAA_0_10066->SetBinError(15,9.615697e-05);
   RAA_0_10066->SetBinError(16,0.0001358903);
   RAA_0_10066->SetBinError(17,0.0001858436);
   RAA_0_10066->SetBinError(18,0.0002533064);
   RAA_0_10066->SetBinError(19,0.0003439127);
   RAA_0_10066->SetBinError(20,0.0003348324);
   RAA_0_10066->SetBinError(21,0.0007429927);
   RAA_0_10066->SetBinError(22,0.001289215);
   RAA_0_10066->SetBinError(23,0.001808078);
   RAA_0_10066->SetBinError(24,0.003848377);
   RAA_0_10066->SetBinError(25,0.006418932);
   RAA_0_10066->SetBinError(26,0.008694532);
   RAA_0_10066->SetBinError(27,0.01199701);
   RAA_0_10066->SetBinError(28,0.01452741);
   RAA_0_10066->SetBinError(29,0.01275717);
   RAA_0_10066->SetBinError(30,0.01353808);
   RAA_0_10066->SetBinError(31,0.0120752);
   RAA_0_10066->SetBinError(32,0.01456282);
   RAA_0_10066->SetBinError(33,0.022584);
   RAA_0_10066->SetBinError(34,0.03197727);
   RAA_0_10066->SetBinError(35,0.04633265);
   RAA_0_10066->SetBinError(36,0.05613232);
   RAA_0_10066->SetBinError(37,0.2032989);
   RAA_0_10066->SetMinimum(0);
   RAA_0_10066->SetMaximum(1.45);
   RAA_0_10066->SetEntries(5936.658);
   RAA_0_10066->SetDirectory(0);
   RAA_0_10066->SetLineWidth(2);
   RAA_0_10066->SetMarkerStyle(20);
   RAA_0_10066->SetMarkerSize(0.8);
   RAA_0_10066->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_10066->GetXaxis()->SetRange(3,37);
   RAA_0_10066->GetXaxis()->CenterTitle(true);
   RAA_0_10066->GetXaxis()->SetLabelFont(42);
   RAA_0_10066->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_10066->GetXaxis()->SetLabelSize(0.05);
   RAA_0_10066->GetXaxis()->SetTitleSize(0.05);
   RAA_0_10066->GetXaxis()->SetTitleFont(42);
   RAA_0_10066->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_10066->GetYaxis()->CenterTitle(true);
   RAA_0_10066->GetYaxis()->SetLabelFont(42);
   RAA_0_10066->GetYaxis()->SetLabelSize(0.05);
   RAA_0_10066->GetYaxis()->SetTitleSize(0.05);
   RAA_0_10066->GetYaxis()->SetTitleOffset(1.4);
   RAA_0_10066->GetYaxis()->SetTitleFont(42);
   RAA_0_10066->GetZaxis()->SetLabelFont(42);
   RAA_0_10066->GetZaxis()->SetLabelSize(0.05);
   RAA_0_10066->GetZaxis()->SetTitleSize(0.05);
   RAA_0_10066->GetZaxis()->SetTitleFont(42);
   RAA_0_10066->Draw("");
*/
   TBox *box = new TBox(0.9,0.975,1.161895,1.025);

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
   */

   /*
   box = new TBox(0.7,0.3101133,0.8,0.3822983);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(0.8,0.3300157,0.9,0.4086562);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   */
   box = new TBox(0.9,0.3567497,1,0.4417608);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(1,0.371196,1.1,0.4596496);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(1.1,0.3869646,1.2,0.4791757);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(1.2,0.4021133,1.4,0.5077106);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(1.4,0.4193796,1.6,0.5295111);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(1.6,0.4244014,1.8,0.5519563);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(1.8,0.4294517,2,0.5585244);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(2,0.4208683,2.2,0.564444);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(2.2,0.4136305,2.4,0.5547371);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(2.4,0.3767903,3.2,0.5208703);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(3.2,0.2998545,4,0.4233205);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(4,0.2415189,4.8,0.334838);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(4.8,0.2092113,5.6,0.2770433);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(5.6,0.1942246,6.4,0.2503424);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(6.4,0.1932111,7.2,0.24198);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(7.2,0.203349,9.6,0.250682);
   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(9.6,0.2446869,12,0.3016414);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(12,0.2660917,14.4,0.3280414);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(14.4,0.3125432,19.2,0.3852942);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(19.2,0.3735856,24,0.4605614);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(24,0.4114821,28.8,0.5073227);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(28.8,0.4435744,35.2,0.5469636);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(35.2,0.4692951,41.6,0.5788096);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(41.6,0.5121643,48,0.6318307);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(48,0.5640441,60.8,0.6959336);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(60.8,0.5929262,73.6,0.7316935);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(73.6,0.6527665,86.4,0.8056074);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(86.4,0.6897085,103.6,0.8512151);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   box = new TBox(103.6,0.6924902,120.8,0.8546544);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(120.8,0.7100454,140,0.8763268);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(140,0.7469904,165,0.9219263);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   box = new TBox(165,0.7425858,250,0.9164609);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();

   /*
   box = new TBox(250,0.7589266,400,0.9366427);

   ci = TColor::GetColor("#ffcc00");
   box->SetFillColor(ci);
   box->Draw();
   */
   /*
   Double_t xAxis67[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_10067 = new TH1D("RAA_0_10067","",37, xAxis67);
   RAA_0_10067->SetBinContent(1,0.2879894);
   RAA_0_10067->SetBinContent(2,0.3313456);
   RAA_0_10067->SetBinContent(3,0.3462058);
   RAA_0_10067->SetBinContent(4,0.3693359);
   RAA_0_10067->SetBinContent(5,0.3992552);
   RAA_0_10067->SetBinContent(6,0.4154228);
   RAA_0_10067->SetBinContent(7,0.4330702);
   RAA_0_10067->SetBinContent(8,0.4549119);
   RAA_0_10067->SetBinContent(9,0.4744453);
   RAA_0_10067->SetBinContent(10,0.4881788);
   RAA_0_10067->SetBinContent(11,0.4939881);
   RAA_0_10067->SetBinContent(12,0.4926561);
   RAA_0_10067->SetBinContent(13,0.4841838);
   RAA_0_10067->SetBinContent(14,0.4488303);
   RAA_0_10067->SetBinContent(15,0.3615875);
   RAA_0_10067->SetBinContent(16,0.2881784);
   RAA_0_10067->SetBinContent(17,0.2431273);
   RAA_0_10067->SetBinContent(18,0.2222835);
   RAA_0_10067->SetBinContent(19,0.2175955);
   RAA_0_10067->SetBinContent(20,0.2270155);
   RAA_0_10067->SetBinContent(21,0.2731642);
   RAA_0_10067->SetBinContent(22,0.2970666);
   RAA_0_10067->SetBinContent(23,0.3489187);
   RAA_0_10067->SetBinContent(24,0.4170735);
   RAA_0_10067->SetBinContent(25,0.4594024);
   RAA_0_10067->SetBinContent(26,0.495269);
   RAA_0_10067->SetBinContent(27,0.5240523);
   RAA_0_10067->SetBinContent(28,0.5719975);
   RAA_0_10067->SetBinContent(29,0.6299889);
   RAA_0_10067->SetBinContent(30,0.6623098);
   RAA_0_10067->SetBinContent(31,0.729187);
   RAA_0_10067->SetBinContent(32,0.7704618);
   RAA_0_10067->SetBinContent(33,0.7735723);
   RAA_0_10067->SetBinContent(34,0.7931861);
   RAA_0_10067->SetBinContent(35,0.8344583);
   RAA_0_10067->SetBinContent(36,0.8295234);
   RAA_0_10067->SetBinContent(37,0.8477847);
   RAA_0_10067->SetBinError(1,2.568238e-05);
   RAA_0_10067->SetBinError(2,2.824522e-05);
   RAA_0_10067->SetBinError(3,2.647242e-05);
   RAA_0_10067->SetBinError(4,2.919912e-05);
   RAA_0_10067->SetBinError(5,3.185709e-05);
   RAA_0_10067->SetBinError(6,3.397847e-05);
   RAA_0_10067->SetBinError(7,3.903175e-05);
   RAA_0_10067->SetBinError(8,3.338616e-05);
   RAA_0_10067->SetBinError(9,4.243359e-05);
   RAA_0_10067->SetBinError(10,5.248198e-05);
   RAA_0_10067->SetBinError(11,6.426495e-05);
   RAA_0_10067->SetBinError(12,7.687639e-05);
   RAA_0_10067->SetBinError(13,9.041817e-05);
   RAA_0_10067->SetBinError(14,6.230362e-05);
   RAA_0_10067->SetBinError(15,9.615697e-05);
   RAA_0_10067->SetBinError(16,0.0001358903);
   RAA_0_10067->SetBinError(17,0.0001858436);
   RAA_0_10067->SetBinError(18,0.0002533064);
   RAA_0_10067->SetBinError(19,0.0003439127);
   RAA_0_10067->SetBinError(20,0.0003348324);
   RAA_0_10067->SetBinError(21,0.0007429927);
   RAA_0_10067->SetBinError(22,0.001289215);
   RAA_0_10067->SetBinError(23,0.001808078);
   RAA_0_10067->SetBinError(24,0.003848377);
   RAA_0_10067->SetBinError(25,0.006418932);
   RAA_0_10067->SetBinError(26,0.008694532);
   RAA_0_10067->SetBinError(27,0.01199701);
   RAA_0_10067->SetBinError(28,0.01452741);
   RAA_0_10067->SetBinError(29,0.01275717);
   RAA_0_10067->SetBinError(30,0.01353808);
   RAA_0_10067->SetBinError(31,0.0120752);
   RAA_0_10067->SetBinError(32,0.01456282);
   RAA_0_10067->SetBinError(33,0.022584);
   RAA_0_10067->SetBinError(34,0.03197727);
   RAA_0_10067->SetBinError(35,0.04633265);
   RAA_0_10067->SetBinError(36,0.05613232);
   RAA_0_10067->SetBinError(37,0.2032989);
   RAA_0_10067->SetMinimum(0);
   RAA_0_10067->SetMaximum(1.45);
   RAA_0_10067->SetEntries(5936.658);
   RAA_0_10067->SetDirectory(0);
   RAA_0_10067->SetLineWidth(2);
   RAA_0_10067->SetMarkerStyle(20);
   RAA_0_10067->SetMarkerSize(0.8);
   RAA_0_10067->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_10067->GetXaxis()->SetRange(3,37);
   RAA_0_10067->GetXaxis()->CenterTitle(true);
   RAA_0_10067->GetXaxis()->SetLabelFont(42);
   RAA_0_10067->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_10067->GetXaxis()->SetLabelSize(0.05);
   RAA_0_10067->GetXaxis()->SetTitleSize(0.05);
   RAA_0_10067->GetXaxis()->SetTitleFont(42);
   RAA_0_10067->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_10067->GetYaxis()->CenterTitle(true);
   RAA_0_10067->GetYaxis()->SetLabelFont(42);
   RAA_0_10067->GetYaxis()->SetLabelSize(0.05);
   RAA_0_10067->GetYaxis()->SetTitleSize(0.05);
   RAA_0_10067->GetYaxis()->SetTitleOffset(1.4);
   RAA_0_10067->GetYaxis()->SetTitleFont(42);
   RAA_0_10067->GetZaxis()->SetLabelFont(42);
   RAA_0_10067->GetZaxis()->SetLabelSize(0.05);
   RAA_0_10067->GetZaxis()->SetTitleSize(0.05);
   RAA_0_10067->GetZaxis()->SetTitleFont(42);
   RAA_0_10067->Draw("same");
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
   Double_t xAxis68[38] = {0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 3.2, 4, 4.8, 5.6, 6.4, 7.2, 9.6, 12, 14.4, 19.2, 24, 28.8, 35.2, 41.6, 48, 60.8, 73.6, 86.4, 103.6, 120.8, 140, 165, 250, 400}; 
   
   TH1D *RAA_0_100_copy68 = new TH1D("RAA_0_100_copy68","",37, xAxis68);
   RAA_0_100_copy68->SetBinContent(1,-1);
   RAA_0_100_copy68->SetBinContent(2,-1);
   RAA_0_100_copy68->SetBinContent(3,-1);
   RAA_0_100_copy68->SetBinContent(4,-1);
   /*
   RAA_0_100_copy68->SetBinContent(1,0.2879894);
   RAA_0_100_copy68->SetBinContent(2,0.3313456);
   RAA_0_100_copy68->SetBinContent(3,0.3462058);
   RAA_0_100_copy68->SetBinContent(4,0.3693359);
   */
   RAA_0_100_copy68->SetBinContent(5,0.3992552);
   RAA_0_100_copy68->SetBinContent(6,0.4154228);
   RAA_0_100_copy68->SetBinContent(7,0.4330702);
   RAA_0_100_copy68->SetBinContent(8,0.4549119);
   RAA_0_100_copy68->SetBinContent(9,0.4744453);
   RAA_0_100_copy68->SetBinContent(10,0.4881788);
   RAA_0_100_copy68->SetBinContent(11,0.4939881);
   RAA_0_100_copy68->SetBinContent(12,0.4926561);
   RAA_0_100_copy68->SetBinContent(13,0.4841838);
   RAA_0_100_copy68->SetBinContent(14,0.4488303);
   RAA_0_100_copy68->SetBinContent(15,0.3615875);
   RAA_0_100_copy68->SetBinContent(16,0.2881784);
   RAA_0_100_copy68->SetBinContent(17,0.2431273);
   RAA_0_100_copy68->SetBinContent(18,0.2222835);
   RAA_0_100_copy68->SetBinContent(19,0.2175955);
   RAA_0_100_copy68->SetBinContent(20,0.2270155);
   RAA_0_100_copy68->SetBinContent(21,0.2731642);
   RAA_0_100_copy68->SetBinContent(22,0.2970666);
   RAA_0_100_copy68->SetBinContent(23,0.3489187);
   RAA_0_100_copy68->SetBinContent(24,0.4170735);
   RAA_0_100_copy68->SetBinContent(25,0.4594024);
   RAA_0_100_copy68->SetBinContent(26,0.495269);
   RAA_0_100_copy68->SetBinContent(27,0.5240523);
   RAA_0_100_copy68->SetBinContent(28,0.5719975);
   RAA_0_100_copy68->SetBinContent(29,0.6299889);
   RAA_0_100_copy68->SetBinContent(30,0.6623098);
   RAA_0_100_copy68->SetBinContent(31,0.729187);
   RAA_0_100_copy68->SetBinContent(32,0.7704618);
   RAA_0_100_copy68->SetBinContent(33,0.7735723);
   RAA_0_100_copy68->SetBinContent(34,0.7931861);
   RAA_0_100_copy68->SetBinContent(35,0.8344583);
   RAA_0_100_copy68->SetBinContent(36,0.8295234);
   RAA_0_100_copy68->SetBinContent(37,0.8477847);

   RAA_0_100_copy68->SetBinError(1,2.568238e-05);
   RAA_0_100_copy68->SetBinError(2,2.824522e-05);
   RAA_0_100_copy68->SetBinError(3,2.647242e-05);
   RAA_0_100_copy68->SetBinError(4,2.919912e-05);
   RAA_0_100_copy68->SetBinError(5,3.185709e-05);
   RAA_0_100_copy68->SetBinError(6,3.397847e-05);
   RAA_0_100_copy68->SetBinError(7,3.903175e-05);
   RAA_0_100_copy68->SetBinError(8,3.338616e-05);
   RAA_0_100_copy68->SetBinError(9,4.243359e-05);
   RAA_0_100_copy68->SetBinError(10,5.248198e-05);
   RAA_0_100_copy68->SetBinError(11,6.426495e-05);
   RAA_0_100_copy68->SetBinError(12,7.687639e-05);
   RAA_0_100_copy68->SetBinError(13,9.041817e-05);
   RAA_0_100_copy68->SetBinError(14,6.230362e-05);
   RAA_0_100_copy68->SetBinError(15,9.615697e-05);
   RAA_0_100_copy68->SetBinError(16,0.0001358903);
   RAA_0_100_copy68->SetBinError(17,0.0001858436);
   RAA_0_100_copy68->SetBinError(18,0.0002533064);
   RAA_0_100_copy68->SetBinError(19,0.0003439127);
   RAA_0_100_copy68->SetBinError(20,0.0003348324);
   RAA_0_100_copy68->SetBinError(21,0.0007429927);
   RAA_0_100_copy68->SetBinError(22,0.001289215);
   RAA_0_100_copy68->SetBinError(23,0.001808078);
   RAA_0_100_copy68->SetBinError(24,0.003848377);
   RAA_0_100_copy68->SetBinError(25,0.006418932);
   RAA_0_100_copy68->SetBinError(26,0.008694532);
   RAA_0_100_copy68->SetBinError(27,0.01199701);
   RAA_0_100_copy68->SetBinError(28,0.01452741);
   RAA_0_100_copy68->SetBinError(29,0.01275717);
   RAA_0_100_copy68->SetBinError(30,0.01353808);
   RAA_0_100_copy68->SetBinError(31,0.0120752);
   RAA_0_100_copy68->SetBinError(32,0.01456282);
   RAA_0_100_copy68->SetBinError(33,0.022584);
   RAA_0_100_copy68->SetBinError(34,0.03197727);
   RAA_0_100_copy68->SetBinError(35,0.04633265);
   RAA_0_100_copy68->SetBinError(36,0.05613232);
   RAA_0_100_copy68->SetBinError(37,0.2032989);

   /*
   RAA_0_100_copy68->SetMinimum(0);
   RAA_0_100_copy68->SetMaximum(1.45);
   RAA_0_100_copy68->SetEntries(5936.658);
   RAA_0_100_copy68->SetDirectory(0);
   RAA_0_100_copy68->SetLineWidth(2);
   RAA_0_100_copy68->SetMarkerStyle(20);
   RAA_0_100_copy68->SetMarkerSize(0.8);
   RAA_0_100_copy68->GetXaxis()->SetTitle("p_{T} (GeV)");
   RAA_0_100_copy68->GetXaxis()->SetRange(3,37);
   RAA_0_100_copy68->GetXaxis()->CenterTitle(true);
   RAA_0_100_copy68->GetXaxis()->SetLabelFont(42);
   RAA_0_100_copy68->GetXaxis()->SetLabelOffset(-0.005);
   RAA_0_100_copy68->GetXaxis()->SetLabelSize(0.05);
   RAA_0_100_copy68->GetXaxis()->SetTitleSize(0.05);
   RAA_0_100_copy68->GetXaxis()->SetTitleFont(42);
   RAA_0_100_copy68->GetYaxis()->SetTitle("R_{AA}");
   RAA_0_100_copy68->GetYaxis()->CenterTitle(true);
   RAA_0_100_copy68->GetYaxis()->SetLabelFont(42);
   RAA_0_100_copy68->GetYaxis()->SetLabelSize(0.05);
   RAA_0_100_copy68->GetYaxis()->SetTitleSize(0.05);
   RAA_0_100_copy68->GetYaxis()->SetTitleOffset(1.4);
   RAA_0_100_copy68->GetYaxis()->SetTitleFont(42);
   RAA_0_100_copy68->GetZaxis()->SetLabelFont(42);
   RAA_0_100_copy68->GetZaxis()->SetLabelSize(0.05);
   RAA_0_100_copy68->GetZaxis()->SetTitleSize(0.05);
   RAA_0_100_copy68->GetZaxis()->SetTitleFont(42);
   RAA_0_100_copy68->Draw("sameaxis");
   RAA->Modified();
   RAA->cd();
   RAA->SetSelected(RAA);
   */
   RAA_0_100_copy68->SetLineWidth(2);
   RAA_0_100_copy68->SetLineColor(kRed);
   RAA_0_100_copy68->SetMarkerStyle(20);
   RAA_0_100_copy68->SetMarkerSize(0.8);
   RAA_0_100_copy68->SetMarkerColor(kRed);
   RAA_0_100_copy68->Draw("same");
}
