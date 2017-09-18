#include "uti.h"
//#include "parameters.h"
#include "TF1.h"

const int nBins=1;
double ptBins[nBins+1] = {10.,1000};

Double_t minhisto=5.0;
Double_t maxhisto=6.0;
Double_t nbinsmasshisto=50;
Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weight;
TString weightgen;
TString seldata;
TString selmc;
TString selmceff;
TString selmcgen;
TString collisionsystem;
Float_t hiBinMin,hiBinMax,centMin,centMax;

void fitNP(int usePbPb=0, TString inputdata="/data/HeavyFlavourRun2/MC2015/Bntuple/pp/Bntuple20160618_BJpsiMM_5p02TeV_TuneCUETP8M1.root" , TString inputmc="/data/HeavyFlavourRun2/MC2015/Bntuple/pp/Bntuple20160618_BJpsiMM_5p02TeV_TuneCUETP8M1.root", TString trgselection="1",  TString cut="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&Btrk1Pt>0.9&&Bchi2cl>1.32e-02&&(Bd0/Bd0Err)>3.41&&cos(Bdtheta)>-3.46e-01&&Bmu1pt>1.5&&Bmu2pt>1.5&&Blxy>0.025", TString cutmcgen="TMath::Abs(Gy)<2.4&&abs(GpdgId)==521&&GisSignal==1", int isMC=0, Double_t luminosity=1., int doweight=0, TString collsyst="PP", TString outputfile="ROOTfiles/mytest.root", Float_t centmin=0., Float_t centmax=0.)
{
	collisionsystem=collsyst;
	hiBinMin = centmin*2;
	hiBinMax = centmax*2;
	centMin = centmin;
	centMax = centmax;

	double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing);

	if (!(usePbPb==1||usePbPb==0)) std::cout<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!, you are using a non valid isPbPb option"<<std::endl;
	bool isPbPb=(bool)(usePbPb);

	if(!isPbPb)
	{
		seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
		selmceff = Form("%s",cut.Data());
		selmcgen = Form("%s",cutmcgen.Data());
	}
	else
	{
		seldata = Form("%s&&%s&&hiBin>%f&&hiBin<%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
		selmceff = Form("%s&&hiBin>%f&&hiBin<%f",cut.Data(),hiBinMin,hiBinMax);
		selmcgen = Form("%s&&hiBin>%f&&hiBin<%f",cutmcgen.Data(),hiBinMin,hiBinMax);
	}

	selmc = Form("%s",cut.Data());

	gStyle->SetTextSize(0.05);
	gStyle->SetTextFont(42);
	gStyle->SetPadRightMargin(0.043);
	gStyle->SetPadLeftMargin(0.18);
	gStyle->SetPadTopMargin(0.1);
	gStyle->SetPadBottomMargin(0.145);
	gStyle->SetTitleX(.0f);

	void clean0 (TH1D* h);
	TF1* fit (TTree* nt, TTree* ntMC, double ptmin, double ptmax, int isMC,bool, TF1* &total,Float_t centmin, Float_t centmax);

	if(doweight==0) {
		weightgen="1";
		weight="1";
	}
	if(doweight<0 || doweight>=1) std::cout<<"ERROR, this weighting option is not defined"<<std::endl;

	std::cout<<"we are using weight="<<weight<<std::endl;

	TFile* inf = new TFile(inputdata.Data());

	TTree* nt = (TTree*)inf->Get("ntKp");
	nt->AddFriend("ntHlt");
	nt->AddFriend("ntHi");
	nt->AddFriend("ntSkim");

	TF1 *totalmass;

	TFile* outf = new TFile(outputfile.Data(),"recreate");
	for(int i=0;i<nBins;i++)
	{
		TF1* f = fit(nt,nt,ptBins[i],ptBins[i+1],isMC,isPbPb, totalmass,centmin, centmax);
		double yield = f->Integral(minhisto,maxhisto)/binwidthmass;
		double yieldErr = f->Integral(minhisto,maxhisto)/binwidthmass*f->GetParError(0)/f->GetParameter(0);
	}  
}

void clean0(TH1D* h)
{
	for (int i=1;i<=h->GetNbinsX();i++)
	{
		if(h->GetBinContent(i)==0) h->SetBinError(i,1);
	}
}

TF1 *fit(TTree *nt, TTree *ntMC, Double_t ptmin, Double_t ptmax, int isMC,bool isPbPb,TF1* &total,Float_t centmin, Float_t centmax)
{
	//cout<<cut.Data()<<endl;
	static Int_t count=0;
	count++;
	TCanvas* c= new TCanvas(Form("c%d",count),"",600,600);
	TH1D* h = new TH1D(Form("h%d",count),"",nbinsmasshisto,minhisto,maxhisto);

	//   TF1* f = new TF1(Form("f%d",count),"[0]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2]) + [3]*Gaus(x,[4],[5])/(sqrt(2*3.14159)*[5]) + [6]*Gaus(x,[7],[8])/(sqrt(2*3.14159)*[8]) + [9]+[10]*x ");
	//   TF1* f = new TF1(Form("f%d",count),"[0]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2]) + [3]*Gaus(x,[4],[5])/(sqrt(2*3.14159)*[5]) + [9]+[10]*x ");
	TF1* f = new TF1(Form("f%d",count),"[0]*TMath::Erf((x-[1])/[2]) + [0] + [9]+[10]*x ");

	if(isMC==1) nt->Project(Form("h%d",count),"Bmass",Form("%s*(%s&&Bpt>%f&&Bpt<%f)","1",seldata.Data(),ptmin,ptmax));   
	else nt->Project(Form("h%d",count),"Bmass",Form("(%s&&Bpt>%f&&Bpt<%f)",seldata.Data(),ptmin,ptmax));   

	clean0(h);

	h->Draw();
	f->SetParLimits(0, 1e-2, 1e4);
	f->SetParLimits(1, 5.02, 5.06);
	f->SetParLimits(2, 0.001, 0.1);

	f->SetParLimits(3, 1e-2, 1e4);
	f->SetParLimits(4, 5.06, 5.10);
	f->SetParLimits(5, 0.001, 0.1);

	f->SetParLimits(6, 0, 1e4);
	f->SetParLimits(7, 5.3, 5.4);
	f->SetParLimits(8, 0.001, 0.5);

	f->SetParLimits(9, 0, 1e5);
	f->SetParLimits(10, -500,  100);

	f->SetParameter(0,1e2);
	f->SetParameter(1,5.03);
	f->SetParameter(2,0.05);

	f->SetParameter(0,1e2);
	f->SetParameter(1,5.03);
	f->SetParameter(2,0.05);

	f->SetParameter(3,1e2);
	f->SetParameter(4,5.07);
	f->SetParameter(5,0.05);

	f->SetParameter(6,1e2);
	f->SetParameter(7,5.35);
	f->SetParameter(8,0.05);

	f->SetParameter(9,1e3);
	f->SetParameter(10,-1);

	//error fn
	f->SetParLimits(0, 1e1, 1e3);
	f->SetParLimits(1, 5., 5.3);
	f->SetParLimits(2, -10, 0);
	f->SetParameter(0,100);
	f->SetParameter(1,5.1);
	f->SetParameter(2,0);

	h->GetEntries();

	h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L q","",minhisto,maxhisto);
	h->Fit(Form("f%d",count),"L m","",minhisto,maxhisto);
	h->SetMarkerSize(0.8);
	h->SetMarkerStyle(20);

	TF1 *background = new TF1(Form("background%d",count),"[0]+[1]*x");
	background->SetParameter(0,f->GetParameter(9));
	background->SetParameter(1,f->GetParameter(10));
	background->SetLineColor(4);
	background->SetRange(minhisto,maxhisto);
	background->SetLineStyle(2);

	//   TF1 *mass = new TF1(Form("fmass%d",count),"[0]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2]) + [3]*Gaus(x,[4],[5])/(sqrt(2*3.14159)*[5]) + [6]*Gaus(x,[7],[8])/(sqrt(2*3.14159)*[8])");
	//   mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(3),f->GetParameter(4),f->GetParameter(5),f->GetParameter(6),f->GetParameter(7),f->GetParameter(8));
	//TF1 *mass = new TF1(Form("fmass%d",count),"[0]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2]) + [3]*Gaus(x,[4],[5])/(sqrt(2*3.14159)*[5])");
	//mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2),f->GetParameter(3),f->GetParameter(4),f->GetParameter(5));
	TF1 *mass = new TF1(Form("fmass%d",count),"[0]*TMath::Erf((x-[1])/[2]) + [0]");
	mass->SetParameters(f->GetParameter(0),f->GetParameter(1),f->GetParameter(2));
	//mass->SetParError(0,f->GetParError(0));
	//mass->SetParError(1,f->GetParError(1));
	//mass->SetParError(2,f->GetParError(2));
	mass->SetLineColor(2);

	h->SetXTitle("m_{#mu#muK} (GeV/c^{2})");
	h->SetYTitle("Entries / (5 MeV/c^{2})");
	h->GetXaxis()->CenterTitle();
	h->GetYaxis()->CenterTitle();
	h->SetAxisRange(0,h->GetMaximum()*1.4*1.2,"Y");
	h->GetXaxis()->SetTitleOffset(1.3);
	h->GetYaxis()->SetTitleOffset(1.8);
	h->GetXaxis()->SetLabelOffset(0.007);
	h->GetYaxis()->SetLabelOffset(0.007);
	h->GetXaxis()->SetTitleSize(0.045);
	h->GetYaxis()->SetTitleSize(0.045);
	h->GetXaxis()->SetTitleFont(42);
	h->GetYaxis()->SetTitleFont(42);
	h->GetXaxis()->SetLabelFont(42);
	h->GetYaxis()->SetLabelFont(42);
	h->GetXaxis()->SetLabelSize(0.04);
	h->GetYaxis()->SetLabelSize(0.04);
	h->SetMarkerSize(0.8);
	h->SetMarkerStyle(20);
	h->SetStats(0);
	h->Draw("e");
	background->Draw("same");   
	mass->SetRange(minhisto,maxhisto);
	mass->Draw("same");
	mass->SetLineStyle(2);
	mass->SetFillStyle(3004);
	mass->SetFillColor(2);
	f->Draw("same");

	Double_t yield = mass->Integral(minhisto,maxhisto)/binwidthmass;
	Double_t yieldErr = mass->Integral(minhisto,maxhisto)/binwidthmass*mass->GetParError(0)/mass->GetParameter(0);

	TLegend* leg = new TLegend(0.65,0.58,0.82,0.88,NULL,"brNDC");
	leg->SetBorderSize(0);
	leg->SetTextSize(0.04);
	leg->SetTextFont(42);
	leg->SetFillStyle(0);
	leg->AddEntry(h,"Data","pl");
	leg->AddEntry(f,"Fit","l");
	leg->AddEntry(mass,"Peaking BG","f");
	leg->AddEntry(background,"Combinatorial","l");
	leg->Draw("same");

	TLatex* texCms = new TLatex(0.18,0.93, "#scale[1.25]{CMS} Preliminary");
	texCms->SetNDC();
	texCms->SetTextAlign(12);
	texCms->SetTextSize(0.04);
	texCms->SetTextFont(42);
	texCms->Draw();

	TLatex* texCol;
	if(collisionsystem=="pp"||collisionsystem=="PP") texCol= new TLatex(0.96,0.93, Form("%s #sqrt{s_{NN}} = 5.02 TeV","pp"));
	else texCol= new TLatex(0.96,0.93, Form("%s #sqrt{s_{NN}} = 5.02 TeV","PbPb"));
	texCol->SetNDC();
	texCol->SetTextAlign(32);
	texCol->SetTextSize(0.04);
	texCol->SetTextFont(42);
	texCol->Draw();

	TLatex* tex;

	tex = new TLatex(0.22,0.78,Form("%.1f < p_{T} < %.1f GeV/c",ptmin,ptmax));
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	if(centMax>0){
		TString texper="%";
		tex = new TLatex(0.22,0.71,Form("Centrality %.0f-%.0f%s",centMin,centMax,texper.Data()));//0.2612903,0.8425793
		tex->SetNDC();
		tex->SetTextColor(1);
		tex->SetTextFont(42);
		tex->SetTextSize(0.045);
		tex->SetLineWidth(2);
		tex->Draw();
	}

	tex = new TLatex(0.22,0.83,"|y| < 2.4");
	tex->SetNDC();
	tex->SetTextFont(42);
	tex->SetTextSize(0.04);
	tex->SetLineWidth(2);
	tex->Draw();

	total=f;

	h->Write();
	f->Write();
	if(!isPbPb) c->SaveAs(Form("plotNP/BMass%s_%d.pdf",collisionsystem.Data(),count));
	else c->SaveAs(Form("plotNP/BMass%s_%.0f_%.0f_%d.pdf",collisionsystem.Data(),centMin,centMax,count));
	return mass;
}


int main(int argc, char *argv[])
{
	if(argc==14)
	{
		fitNP(atoi(argv[1]),argv[2], argv[3], argv[4], argv[5], argv[6], atoi(argv[7]), atof(argv[8]), atoi(argv[9]),argv[10],argv[11],atof(argv[12]),atof(argv[13]));
		return 0;
	}
	else if(argc==12)
	{
		fitNP(atoi(argv[1]), argv[2], argv[3], argv[4], argv[5], argv[6], atoi(argv[7]), atof(argv[8]), atoi(argv[9]),argv[10],argv[11]);
		return 0;
	}
	else
	{
		std::cout << "Wrong number of inputs" << std::endl;
		return 1;
	}
}



double ErrorOnSigma(double width, double errwidth, double smear, double errsmearing){
	double squarederroronsigma=(1+smear)*(1+smear)*errwidth*errwidth+width*width*errsmearing*errsmearing;
	double erroronsigma=TMath::Sqrt(squarederroronsigma);
	return erroronsigma;

}

