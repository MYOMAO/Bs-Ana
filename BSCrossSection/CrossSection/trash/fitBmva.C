using namespace std;
#include "uti.h"
#include "mva.h"

double minhisto=5.0;
double maxhisto=6.0;
double nbinsmasshisto=50;
double binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString collisionsystem;
TString infname;
float centmin,centmax;

bool isPbPb = true;

double yield=2;
double yieldErr=0;
double back=2;
double backErr=0;
double signif=0;
double signifErr=0;

float NPpar[2];

const int nbkg=1;
const int nsig=1;

TString bkgerf     = "[3]*(TMath::Erf((x-[4])/[5])+1)";
TString bkgerf_new = "[0]*(TMath::Erf((x-[1])/[2])+1)";

TString sig     = "[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))";		    
TString sig_new = "[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))";

TString bkg     = "[6]+[9]*(x-6)";
TString bkg_new = "[0]+[1]*(x-6)";

void clean0(TH1D* h)
{
    for (int i=1;i<=h->GetNbinsX();i++)
    {
	if(h->GetBinContent(i)==0) h->SetBinError(i,1);
    }
}

void getNPFnPar(TString npfname, float par[]){
	TFile* npf = new TFile(npfname.Data());
	TF1* f = (TF1*)npf->Get("f1");
	par[0] = f->GetParameter(1);
	par[1] = f->GetParameter(2);
}

void fitBmva(TString collsyst="PbPb", TString inputfile ="", TString npfile="ROOTfiles/NPFitPbPb.root", float centMin=0, float centMax=100, TString outputfile="outMVA")
{
  collisionsystem = collsyst;
  infname = outputfile;
  centmin = centMin;
  centmax = centMax;
  if(collsyst != "PbPb") isPbPb = false;

  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.02);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.09);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);

  TCanvas* c1 = new TCanvas("c1","",600,600);
  TCanvas* c2 = new TCanvas("c2","",600,600);

  TF1* fit (float ptmin, float ptmax, TString mvatype); // widVar=0,1

  TF1* bmass_s = new TF1("bmass_s","[0]",7,50);
  bmass_s->SetTitle(";B^{+} p_{T} (GeV/c);fraction of default significance");
  bmass_s->SetMinimum(0.0);
  bmass_s->SetMaximum(2.0);
  bmass_s->SetParameter(0,1);
  bmass_s->SetLineWidth(1);
  bmass_s->SetLineColor(kRed);
  bmass_s->SetLineStyle(2);
  bmass_s->GetXaxis()->SetTitleOffset(1.3);
  bmass_s->GetYaxis()->SetTitleOffset(1.8);
  bmass_s->GetXaxis()->SetLabelOffset(0.007);
  bmass_s->GetYaxis()->SetLabelOffset(0.007);
  bmass_s->GetXaxis()->SetTitleSize(0.045);
  bmass_s->GetYaxis()->SetTitleSize(0.045);
  bmass_s->GetXaxis()->SetTitleFont(42);
  bmass_s->GetYaxis()->SetTitleFont(42);
  bmass_s->GetXaxis()->SetLabelFont(42);
  bmass_s->GetYaxis()->SetLabelFont(42);
  bmass_s->GetXaxis()->SetLabelSize(0.04);
  bmass_s->GetYaxis()->SetLabelSize(0.04);

  c1->cd();
  bmass_s->Draw();

  TF1* bmass_y = new TF1("bmass_y","[0]",7,50);
  bmass_y->SetTitle(";B^{+} p_{T} (GeV/c);fraction of default yield");
  bmass_y->SetMinimum(0.0);
  bmass_y->SetMaximum(2.0);
  bmass_y->SetParameter(0,1);
  bmass_y->SetLineWidth(1);
  bmass_y->SetLineColor(kRed);
  bmass_y->SetLineStyle(2);
  bmass_y->GetXaxis()->SetTitleOffset(1.3);
  bmass_y->GetYaxis()->SetTitleOffset(1.8);
  bmass_y->GetXaxis()->SetLabelOffset(0.007);
  bmass_y->GetYaxis()->SetLabelOffset(0.007);
  bmass_y->GetXaxis()->SetTitleSize(0.045);
  bmass_y->GetYaxis()->SetTitleSize(0.045);
  bmass_y->GetXaxis()->SetTitleFont(42);
  bmass_y->GetYaxis()->SetTitleFont(42);
  bmass_y->GetXaxis()->SetLabelFont(42);
  bmass_y->GetYaxis()->SetLabelFont(42);
  bmass_y->GetXaxis()->SetLabelSize(0.04);
  bmass_y->GetYaxis()->SetLabelSize(0.04);

  c2->cd();
  bmass_y->Draw();

  TLatex* Title = new TLatex(0.1,0.94, Form("MVA Variation for %s",collisionsystem.Data()));
  Title->SetNDC();
  Title->SetTextAlign(12);
  Title->SetTextSize(0.04);
  Title->SetTextFont(42);

  c1->cd();
  Title->Draw("Same");
  c2->cd();
  Title->Draw("Same");

  TLegend* leg = new TLegend(0.7,0.53,0.90,0.90,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);
  leg->SetFillStyle(0);

    getNPFnPar(npfile, NPpar);
    std::cout<<"NP parameter 0: "<<NPpar[0]<<std::endl;
    std::cout<<"NP parameter 1: "<<NPpar[1]<<std::endl;

    TString inputf = Form("%s.root",inputfile.Data());
    TFile* data = new TFile(inputf.Data());
    TH1D* defYield = (TH1D*)data->Get("hPt");
    TH1D* defSignif = (TH1D*)data->Get("hSignif");
    
    for(int k=0;k<nMVA;k++)
    {
      TH1D* hSignif = new TH1D(Form("s_%s",mvatypes[k].Data()),"",nBins,ptBins);
      TH1D* hYield = new TH1D(Form("y_%s",mvatypes[k].Data()),"",nBins,ptBins);
      for(int i=0;i<nBins;i++)
	{
	 
	  TF1* f = fit(ptBins[i],ptBins[i+1],mvatypes[k]);
	  yield = yield/(ptBins[i+1]-ptBins[i]);
          yieldErr = yieldErr/(ptBins[i+1]-ptBins[i]);
	  back = back/(ptBins[i+1]-ptBins[i]);
	  backErr = backErr/(ptBins[i+1]-ptBins[i]);
	  signif = yield/sqrt(yield+back);
	  signifErr = sqrt(pow(yieldErr,2)*pow(2*back+yield,2)/(4*pow(back+yield,3))+pow(backErr,2)*pow(yield,2)/(4*pow(back+yield,3)));

	  double defsig = defSignif->GetBinContent(i+1);
	  double defsigerr = defSignif->GetBinError(i+1);
	  double defy = defYield->GetBinContent(i+1);
	  double defyerr = defYield->GetBinError(i+1);

	  cout << "YIELD: " << yield << endl;
	  cout << "DEF YIELD: " <<defy << endl;
	  cout << "BACK: " << back << endl;
	  cout << "SIGNIF: " << signif << endl;
	  cout << "DEF SIGNIF: " << defsig << endl;
	  cout << "SIG FRAC: " << signif/defsig <<endl;

	  if(signif/defsig == signif/defsig)
	  {
	    hSignif->SetBinContent(i+1,signif/defsig);
	    hSignif->SetBinError(i+1,signifErr/defsigerr);
	  }
	  else
	  {
	    hSignif->SetBinContent(i+1,1);
	    hSignif->SetBinError(i+1,1);
	  }

	  hYield->SetBinContent(i+1,yield/defy);
	  hYield->SetBinError(i+1,yieldErr/defyerr);
	}

	int colors[15]  = {2,3,4,5,6,7,8,9,30,40,41,46,38,49,29};
	hSignif->SetMarkerStyle(8);
	hSignif->SetMarkerColor(colors[k]);
	hYield->SetMarkerStyle(8);
	hYield->SetMarkerColor(colors[k]);

	leg->AddEntry(hSignif,mvatypes[k].Data(),"pl");

	c1->cd();
	hSignif->Draw("Same");
	//delete hSignif;
	
	c2->cd();
	hYield->Draw("Same");
	//delete hYield;
    }
    c1->cd();
    leg->Draw("Same");
    c2->cd();
    leg->Draw("Same");

    c1->SaveAs(Form("plotMVA/%s_signif.pdf",collisionsystem.Data()));
    c2->SaveAs(Form("plotMVA/%s_yield.pdf",collisionsystem.Data()));

}

TF1* fit(float ptmin, float ptmax, TString mvatype="")
{

    static int count=0;
    count++;

  TCanvas* c = new TCanvas(Form("c_%.0f_%.0f",ptmin,ptmax),"",400,400);
  TFile* infile = new TFile(Form("%s/%s_%s_%.0f_%.0f.root",infname.Data(),mvatype.Data(),collisionsystem.Data(),ptmin,ptmax));
  TH1D* h = (TH1D*)infile->Get("h");                    h->SetName(Form("h_%s_%.0f_%.0f",mvatype.Data(),ptmin,ptmax));
  TH1D* hMCSignal = (TH1D*)infile->Get("hMCSignal");    hMCSignal->SetName(Form("hMCSignal_%s_%.0f_%.0f",mvatype.Data(),ptmin,ptmax));
    
  TF1* f;  
  TF1* background;
  TF1* bkpi;
  TF1* mass;

  f = new TF1(Form("f%d",count),Form("%s+%s+%s",sig.Data(),bkg.Data(),bkgerf.Data()), 5.0, 6.0);

    clean0(h);
    h->Draw();

    double hmin = h->GetBinContent(h->GetMinimumBin());
    double hmax = h->GetBinContent(h->GetMaximumBin());
    double havg = h->Integral();

    double mcmin = hMCSignal->GetBinContent(h->GetMinimumBin());
    double mcmax = hMCSignal->GetBinContent(h->GetMaximumBin());
    double mcavg = hMCSignal->Integral();

    //f->SetParLimits(0,0,1000);
    f->SetParLimits(1,5.27,5.29);
    f->SetParLimits(2,0.01,0.05);
    f->SetParLimits(8,0.01,0.05);
    /*if(!isPbPb)
    {
	f->SetParLimits(2,0.01,0.03);
	f->SetParLimits(8,0.01,0.03);
    }*/
    f->SetParLimits(7,0,1);
    //f->SetParLimits(6,0,1000);
    f->SetParLimits(9,-1000,0);
    
    f->SetParLimits(3,0,1000);
    f->FixParameter(4,NPpar[0]);
    f->FixParameter(5,NPpar[1]);

    f->SetParameter(0,100);
    f->SetParameter(1,5.28);
    f->SetParameter(2,0.05);
    f->SetParameter(8,0.03);

    f->FixParameter(1,5.279);
    f->FixParameter(3,0);
    f->FixParameter(6,0);
    f->SetParLimits(6,-hmin,hmin);
    //f->FixParameter(9,0);
 
    h->GetEntries();
    hMCSignal->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
    hMCSignal->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
    f->ReleaseParameter(1);
    f->SetParLimits(1,5.27,5.29);
    hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    hMCSignal->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    hMCSignal->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);

    f->FixParameter(1,f->GetParameter(1));
    f->FixParameter(2,f->GetParameter(2));  
    f->FixParameter(7,f->GetParameter(7)); 
    f->FixParameter(8,f->GetParameter(8));
 
    f->ReleaseParameter(3);
    f->SetParLimits(3,0,1000);
    f->ReleaseParameter(6);
    //f->ReleaseParameter(9);
 
    h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
    h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
    f->ReleaseParameter(1);
    f->SetParLimits(1,5.27,5.29);
    h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    h->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);
    
    background = new TF1(Form("background%d",count),bkg_new.Data(),minhisto,maxhisto);
    background->SetParameter(0,f->GetParameter(6));
    background->SetParameter(1,f->GetParameter(9));
    background->SetParError(0,f->GetParError(6));


    bkpi = new TF1(Form("bpki%d",count),bkgerf_new.Data(),minhisto,maxhisto);
    bkpi->SetParameter(0,f->GetParameter(3));
    bkpi->SetParameter(1,NPpar[0]);
    bkpi->SetParameter(2,NPpar[1]);

    mass = new TF1(Form("fmass%d",count),sig_new.Data(),minhisto,maxhisto);
    mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8));
    mass->SetParError(0,f->GetParError(0));
    mass->SetParError(1,f->GetParError(1));
    mass->SetParError(2,f->GetParError(2));
    mass->SetParError(3,f->GetParError(7));
    mass->SetParError(4,f->GetParError(8));

      f->SetLineColor(kRed);
      f->SetLineWidth(2);

   background->SetLineColor(4);
   background->SetLineStyle(2);
   background->SetLineWidth(3);
   background->SetRange(minhisto,maxhisto);
   
   bkpi->SetFillColor(kGreen+4);
   bkpi->SetFillStyle(3005);
   bkpi->SetLineColor(kGreen+4);
   bkpi->SetLineWidth(3);

   mass->SetLineColor(kOrange-3);
   mass->SetLineStyle(2);
   mass->SetLineWidth(3);
   mass->SetFillColor(kOrange-3);
   mass->SetFillStyle(3002);

  h->SetXTitle("m_{#mu#muK} (GeV/c^{2})");
  h->SetYTitle("Entries / (5 MeV/c^{2})");
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
  h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
  h->GetXaxis()->SetTitleOffset(1.0);
  h->GetYaxis()->SetTitleOffset(1.5);
  h->GetXaxis()->SetLabelOffset(0.008);
  h->GetYaxis()->SetLabelOffset(0.008);
  h->GetXaxis()->SetTitleSize(0.060);
  h->GetYaxis()->SetTitleSize(0.060);
  h->GetXaxis()->SetTitleFont(42);
  h->GetYaxis()->SetTitleFont(42);
  h->GetXaxis()->SetLabelFont(42);
  h->GetYaxis()->SetLabelFont(42);
  h->GetXaxis()->SetLabelSize(0.06);
  h->GetYaxis()->SetLabelSize(0.06);
  h->Draw("e");
  
  double axisymin = -0.05;
  h->SetAxisRange(axisymin,h->GetMaximum()*1.2,"Y");
  h->GetXaxis()->SetNdivisions(-50205);
  int ci = TColor::GetColor("#000099");
  h->SetLineColor(ci);
  h->SetStats(0);
  
      h->SetMarkerStyle(20); // 24?
      h->SetMarkerSize(0.8);

   h->Draw("e");
   bkpi->Draw("same");
   background->Draw("same");   
   mass->SetRange(minhisto,maxhisto);
   mass->Draw("same");
   f->Draw("same");

   yield = mass->Integral(minhisto,maxhisto)/binwidthmass;
   yieldErr = mass->Integral(minhisto,maxhisto)/binwidthmass*mass->GetParError(0)/mass->GetParameter(0);
   back = background->Integral(5.179,5.379)/binwidthmass;
   backErr = background->Integral(5.179,5.379)/binwidthmass*background->GetParError(0)/background->GetParameter(0);

  TLegend* leg = new TLegend(0.55,0.45,0.875,0.76,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetTextFont(42);
  leg->SetFillStyle(0);
  leg->AddEntry(h,"Data","pl");
  leg->AddEntry(f,"Fit","l");
  leg->AddEntry(mass,"B^{+} Signal","f");
  leg->AddEntry(background,"Combinatorial","l");
  leg->AddEntry(bkpi,"B #rightarrow J/#psi X","f");
  leg->Draw("same");

  TLatex* texCms = new TLatex(0.225,0.87, "#scale[1.25]{CMS} Preliminary");
  texCms->SetNDC();
  texCms->SetTextAlign(12);
  texCms->SetTextSize(0.04);
  texCms->SetTextFont(42);
  texCms->Draw();

  TLatex* texCol;
  if(collisionsystem=="pp"||collisionsystem=="PP") texCol= new TLatex(0.39,0.94, Form("25.8 pb^{-1} (%s #sqrt{s_{NN}} = 5.02 TeV)","pp"));
  else texCol= new TLatex(0.35,0.94, Form("345 #mub^{-1} (%s #sqrt{s_{NN}} = 5.02 TeV)","PbPb"));
  texCol->SetNDC();
  texCol->SetTextSize(0.05);
  texCol->SetLineWidth(2);
  texCol->SetTextFont(42);
  texCol->Draw();

  TLatex* tex;
  
  tex = new TLatex(0.53,0.85,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(0.35,0.69,mvatype.Data());
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetLineWidth(2);
  tex->Draw();
  
  if(isPbPb){
  TString texper="%";
  tex = new TLatex(0.225,0.78,Form("Centrality %.0f-%.0f%s",0.0,100.0,texper.Data()));//0.2612903,0.8425793
  tex->SetNDC();
  tex->SetTextColor(1);
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetLineWidth(2);
  tex->Draw();
  }

  tex = new TLatex(0.77,0.78,"|y_{lab}| < 2.4");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.05);
  tex->SetLineWidth(2);
  tex->Draw();

  tex = new TLatex(0.30,0.54,"B^{+}");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextSize(0.06);
  tex->SetLineWidth(2);
  tex->Draw();

  c->SaveAs(Form("plotMVA/%s_%s_%.0f_%.0f.pdf",mvatype.Data(),collisionsystem.Data(),ptmin,ptmax));

    return mass;
}


int main(int argc, char *argv[])
{
  if(argc==6)
    {
      fitBmva(argv[1],argv[2],argv[3],atof(argv[3]),atof(argv[4]));
      return 0;
    }
  else if(argc==4)
    {
      fitBmva(argv[1],argv[2],argv[3]);
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}

