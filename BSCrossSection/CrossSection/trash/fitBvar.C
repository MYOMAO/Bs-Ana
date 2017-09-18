using namespace std;
#include "uti.h"
#include "parameters.h"

double minhisto=5.0;
double maxhisto=6.0;
double nbinsmasshisto=50;
double binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString collisionsystem;
TString infname;
float centmin,centmax;

bool isPbPb = true;

float yield=0;
float yieldErr=0;
float NPpar[2];

const int nbkg=4;
const int nsig=2;

TString bkgerf = "[3]*(TMath::Erf((x-[4])/[5])+1)";
TString bkgerf_new = "[0]*(TMath::Erf((x-[1])/[2])+1)";

TString sig[nsig] =     {"[0]*([7]*Gaus(x,[1],[2]*(1+[6]))/(sqrt(2*3.14159)*[2]*(1+[6]))+(1-[7])*Gaus(x,[1],[8]*(1+[6]))/(sqrt(2*3.14159)*[8]*(1+[6])))",
		         "[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8])+[6]*Gaus(x,[1],[9])/(sqrt(2*3.14159)*[9]))",
		         //"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+[6]*ROOT::Math::crystalball_cdf(x,[9],[10],[8],[1]))",
		         //"[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+[6]*TMath::BreitWigner(x,[1],[8]))"
			 };
		    
TString sig_new[nsig] = {"[0]*([3]*Gaus(x,[1],[2]*(1+[5]))/(sqrt(2*3.14159)*[2]*(1+[5]))+(1-[3])*Gaus(x,[1],[4]*(1+[5]))/(sqrt(2*3.14159)*[4]*(1+[5])))",
		         "[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4])+[5]*Gaus(x,[1],[6])/(sqrt(2*3.14159)*[6]))",
		         //"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+[5]*ROOT::Math::crystalball_cdf(x,[6],[7],[4],[1]))",
		         //"[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+[5]*TMath::BreitWigner(x,[1],[4]))"
			 };

TString sig_bkg[nsig] = {"[9]+[10]*(x-6)",
		         "[10]+[11]*(x-6)",
		         //"[11]+[12]*(x-5)",
		         //"[9]+[10]*(x-6)"
			 };

int sigmax[nsig] = {8,9};

TString bkg[nbkg] = {"",
		    "[9]+[10]*x+[11]*x*x",
		    "[9]+[10]*x+[11]*x*x+[12]*x*x*x",
		    "[9]*exp([10]*(x-5))"};

TString bkg_new[nbkg] = {"[0]+[1]*(x-6)",
		    "[0]+[1]*x+[2]*x*x",
		    "[0]+[1]*x+[2]*x*x+[3]*x*x*x",
		    "[0]*exp([1]*(x-5))"};

int bkgmax[nbkg] = {0,11,12,10};

TString signame[nsig] = {"DoubleGaussian","TripleGaussian"};
TString bkgname[nbkg] = {"Linear","Quadratic","Cubic","Exponential"};

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

void fitBvar(TString collsyst="PbPb", TString inputfile ="", TString npfile="ROOTfiles/NPFitPbPb.root", float centMin=0, float centMax=100, TString outputfile="outHisto")
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

  TF1* fit (float ptmin, float ptmax, int s, int b, int widVar); // widVar=0,1

  TCanvas* c = new TCanvas("c","",600,600);

  TF1* bmass = new TF1("bmass","[0]",7,50);
  bmass->SetTitle(";B^{+} p_{T} (GeV/c);fraction of default yield");
  bmass->SetMinimum(0.9);
  bmass->SetMaximum(1.1);
  if(isPbPb)
    {
    bmass->SetMinimum(0.9);
    bmass->SetMaximum(1.1);
    }
  bmass->SetParameter(0,1);
  bmass->SetLineWidth(1);
  bmass->SetLineColor(kRed);
  bmass->SetLineStyle(2);
  bmass->GetXaxis()->SetTitleOffset(1.3);
  bmass->GetYaxis()->SetTitleOffset(1.8);
  bmass->GetXaxis()->SetLabelOffset(0.007);
  bmass->GetYaxis()->SetLabelOffset(0.007);
  bmass->GetXaxis()->SetTitleSize(0.045);
  bmass->GetYaxis()->SetTitleSize(0.045);
  bmass->GetXaxis()->SetTitleFont(42);
  bmass->GetYaxis()->SetTitleFont(42);
  bmass->GetXaxis()->SetLabelFont(42);
  bmass->GetYaxis()->SetLabelFont(42);
  bmass->GetXaxis()->SetLabelSize(0.04);
  bmass->GetYaxis()->SetLabelSize(0.04);
  bmass->Draw();

  TLatex* Title = new TLatex(0.1,0.94, Form("Fit Variation for %s",collisionsystem.Data()));
  Title->SetNDC();
  Title->SetTextAlign(12);
  Title->SetTextSize(0.04);
  Title->SetTextFont(42);
  Title->Draw("Same");

  TLegend* leg = new TLegend(0.2,0.67,0.4,0.87,NULL,"brNDC");
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);
  leg->SetFillStyle(0);

    getNPFnPar(npfile, NPpar);
    std::cout<<"NP parameter 0: "<<NPpar[0]<<std::endl;
    std::cout<<"NP parameter 1: "<<NPpar[1]<<std::endl;

    TString inputf;
    if(nBins == 1) inputf = Form("%s_integrated.root",inputfile.Data());
    else inputf = Form("%s.root",inputfile.Data());

    TFile* data = new TFile(inputf.Data());  
    TH1D* h_def = (TH1D*)data->Get("hPt"); 
    TH1D* hwidvar;
    int cnt =0;

    for(int s=0;s<nsig;s++)
    {
	bkgmax[0]=sigmax[s]+2;

	for(int b=0;b<nbkg;b++)
	{

	  if(s==0 || b==0)
	  {
	      TH1D* hvar = new TH1D(Form("h_%s",bkgname[b].Data()),"",nBins,ptBins);
	      if(s==0 && b==0) hwidvar = new TH1D("h_widvar","",nBins,ptBins);

	      for(int i=0;i<nBins;i++)
		{

		  double def_y = h_def->GetBinContent(i+1);
		  double def_err = h_def->GetBinError(i+1);
		 
		  TF1* f = fit(ptBins[i],ptBins[i+1],s,b,0);
		  cout<<"YIELD / YIELDERR:  "<< yield <<" "<< yieldErr << endl;
		  cout << "DEF YIELD:  "<< def_y*(ptBins[i+1]-ptBins[i]) <<endl;
		  double y = yield/(ptBins[i+1]-ptBins[i]);
		  double err = yieldErr/(ptBins[i+1]-ptBins[i]);

		  double y_fr = y/def_y;
		  cout << "YIELD FRACTION: " << y_fr << endl;
		  double err_fr = sqrt(pow(err/def_y,2)+pow(def_err*y/(def_y*def_y),2));

		  hvar->SetBinContent(i+1,y_fr);
		  hvar->SetBinError(i+1,err_fr);
		  hvar->SetMarkerStyle(8);
		  hvar->SetMarkerColor(4+cnt);
		  cnt++;

		  if(s==0 && b==0)
		  {    		     
		      f = fit(ptBins[i],ptBins[i+1],0,0,1);
		      cout<<"YIELD / YIELDERR:  "<< yield <<" "<< yieldErr << endl;
		      cout << "DEF YIELD:  "<< def_y*(ptBins[i+1]-ptBins[i]) <<endl;
		      y = yield/(ptBins[i+1]-ptBins[i]);
		      err = yieldErr/(ptBins[i+1]-ptBins[i]);

		      y_fr = y/def_y;
		      cout << "YIELD FRACTION: " << y_fr << endl;
		      err_fr = sqrt(pow(err/def_y,2)+pow(def_err*y/(def_y*def_y),2));

		      hwidvar->SetBinContent(i+1,y_fr);
		      hwidvar->SetBinError(i+1,err_fr);
		      hwidvar->SetMarkerStyle(8);
		      hwidvar->SetMarkerColor(3);
		  }

		}

		c->cd();
		hvar->Draw("Same");
		if(s==0 && b==0) hwidvar->Draw("Same");

		leg->AddEntry(hvar,Form("%s and %s",signame[s].Data(),bkgname[b].Data()),"pl");
		if(s==0 && b==0) leg->AddEntry(hwidvar, "Width Variation", "pl");
	    }
	}
    }

  c->cd();
  leg->Draw("Same");

  if(nBins == 1) c->SaveAs(Form("SystPDF/total_var_%s.pdf",collisionsystem.Data()));  
  else c->SaveAs(Form("SystPDF/var_%s.pdf",collisionsystem.Data()));  
}

TF1* fit(float ptmin, float ptmax, int s, int b, int widVar)
{

    static int count=0;
    count++;

  TCanvas* c = new TCanvas(Form("c_%.0f_%.0f",ptmin,ptmax),"",400,400);
  TFile* infile = new TFile(Form("%s/%s_%.0f_%.0f.root",infname.Data(),collisionsystem.Data(),ptmin,ptmax));
  TH1D* h = (TH1D*)infile->Get("h");                    h->SetName(Form("h_%.0f_%.0f",ptmin,ptmax));
  TH1D* hMCSignal = (TH1D*)infile->Get("hMCSignal");    hMCSignal->SetName(Form("hMCSignal_%.0f_%.0f",ptmin,ptmax));
    
  TF1* f;  
  TF1* background;
  TF1* bkpi;
  TF1* mass;

  if(b==0) f = new TF1(Form("f%d",count),Form("%s+%s+%s",sig[s].Data(),sig_bkg[s].Data(),bkgerf.Data()), 5.0, 6.0);
  else f = new TF1(Form("f%d",count),Form("%s+%s+%s",sig[s].Data(),bkg[b].Data(),bkgerf.Data()), 5.0, 6.0);

    clean0(h);
    h->Draw();

    double hmin = h->GetBinContent(h->GetMinimumBin());
    double hmax = h->GetBinContent(h->GetMaximumBin());
    double havg = h->Integral();

    double mcmin = hMCSignal->GetBinContent(h->GetMinimumBin());
    double mcmax = hMCSignal->GetBinContent(h->GetMaximumBin());
    double mcavg = hMCSignal->Integral();

    f->SetParLimits(0,0,2*hmax);
    f->SetParLimits(1,5.27,5.29);
    f->SetParLimits(2,0.01,0.05);
    f->SetParLimits(8,0.01,0.05);
    f->SetParLimits(7,0,1);
    f->SetParLimits(6,0,1);
    if(s==1) f->SetParLimits(9,0,1);
    //if(s==2) f->SetParLimits(10,1,10);
    if(b==0 && sigmax[s]==8)
    {
	//f->SetParLimits(9,0.5*hmin,1.5*hmax);
	f->SetParLimits(10,-1000,0);
    }
    if(b==0 && sigmax[s]==10)
    {
	//f->SetParLimits(11,0.5*hmin,1.5*hmax);
	f->SetParLimits(12,-1000,0);
    }
    if(b==3)
    {
	//f->SetParLimits(9,0,1.5*hmax);
	f->SetParLimits(10,-100,0);
    }

    f->SetParLimits(3,0,1000);
    f->FixParameter(4,NPpar[0]);
    f->FixParameter(5,NPpar[1]);

    f->SetParameter(0,100);
    f->SetParameter(1,5.28);
    f->SetParameter(2,0.05);
    f->SetParameter(8,0.03);

    f->FixParameter(1,5.279);
    f->FixParameter(3,0);
    if(s==2) f->FixParameter(7,0);

    if(s>0 && bkgmax[b]>=11) f->FixParameter(11,0);
    if(s>0 && bkgmax[b]>=12) f->FixParameter(12,0); 
 
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
    f->FixParameter(6,f->GetParameter(6));
    if(sigmax[s]>=9) f->FixParameter(9,f->GetParameter(9));
    if(sigmax[s]>=10) f->FixParameter(10,f->GetParameter(10));

    if(s==2) 
    {
	f->ReleaseParameter(7);
	f->SetParLimits(7,0,1);
    }
 
    if(s>0 && bkgmax[b]>=11) f->ReleaseParameter(11);
    if(s>0 && bkgmax[b]>=12) f->ReleaseParameter(12); 
    f->ReleaseParameter(3);
    f->SetParLimits(3,0,1000);
 
    h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
    h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
    f->ReleaseParameter(1);
    f->SetParLimits(1,5.27,5.29);
    h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
    h->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);
    
    if(b==0)
    {
	background = new TF1(Form("background%d",count),bkg_new[b].Data(),minhisto,maxhisto);
	background->SetParameter(0,f->GetParameter(sigmax[s]+1));
	background->SetParameter(1,f->GetParameter(sigmax[s]+2));
    }
    else
    {
	background = new TF1(Form("background%d",count),bkg_new[b].Data(),minhisto,maxhisto);
	background->SetParameter(0,f->GetParameter(9));
	background->SetParameter(1,f->GetParameter(10));
	if(bkgmax[b]>=11) background->SetParameter(2,f->GetParameter(11));
	if(bkgmax[b]>=12) background->SetParameter(3,f->GetParameter(12));
    }

    bkpi = new TF1(Form("bpki%d",count),bkgerf_new.Data(),minhisto,maxhisto);
    bkpi->SetParameter(0,f->GetParameter(3));
    bkpi->SetParameter(1,NPpar[0]);
    bkpi->SetParameter(2,NPpar[1]);

    mass = new TF1(Form("fmass%d",count),sig_new[s].Data(),minhisto,maxhisto);
    if(s==0 || s==3) mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8),f->GetParameter(6));
    if(s==1) mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8),f->GetParameter(6),f->GetParameter(9));
    if(s==2) mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(7),f->GetParameter(8),f->GetParameter(6),f->GetParameter(9),f->GetParameter(10));

    mass->SetParError(0,f->GetParError(0));
    mass->SetParError(1,f->GetParError(1));
    mass->SetParError(2,f->GetParError(2));
    mass->SetParError(3,f->GetParError(7));
    mass->SetParError(4,f->GetParError(8));
    mass->SetParError(5,f->GetParError(6));
    if(sigmax[s]>=9) mass->SetParError(6,f->GetParError(9));
    if(sigmax[s]>=10) mass->SetParError(7,f->GetParError(10));

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
  
  if(centmax>0){
  TString texper="%";
  tex = new TLatex(0.225,0.78,Form("Centrality %.0f-%.0f%s",centmin,centmax,texper.Data()));//0.2612903,0.8425793
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

    if(widVar==0) 
      c->SaveAs(Form("SystPDF/%s_%s_%s_%.0f_%.0f.pdf",collisionsystem.Data(),signame[s].Data(),bkgname[b].Data(),ptmin,ptmax));
    else
      c->SaveAs(Form("SystPDF/%s_%s_%.0f_%.0f.pdf",collisionsystem.Data(),"widvar",ptmin,ptmax));

    return mass;
}


int main(int argc, char *argv[])
{
  if(argc==6)
    {
      fitBvar(argv[1],argv[2],argv[3],atof(argv[3]),atof(argv[4]));
      return 0;
    }
  else if(argc==4)
    {
      fitBvar(argv[1],argv[2],argv[3]);
      return 0;
    }
  else
    {
      std::cout << "Wrong number of inputs" << std::endl;
      return 1;
    }
}

