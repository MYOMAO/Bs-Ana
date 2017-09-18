# should I use EFFCOR in CrossSectionRation? Not using it 

#!/bin/bash
#source clean.sh
CENTPbPbMIN=0
CENTPbPbMAX=100
#Central point of the analysis

# these settings control which macros are run
DOANALYSISPP_FONLL=0
DOANALYSISPP_FIT=1
DOANALYSISPP_MCSTUDY=1
DOANALYSISPP_CROSS=1

DOANALYSISPbPb_FIT=1
DOANALYSISPbPb_MCSTUDY=1
DOANALYSISPbPb_CROSS=1
DORAA=1

## PP MONTE CARLO
INPUTMCPP="../../bsTMVACDozen/merged-files/MLP_and_BDT_MC.root"

## PP DATA 
INPUTDATAPP="../../bsTMVACDozen/merged-files/MLP_and_BDT_DATA.root"

## PbPb MONTE CARLO
INPUTMCPbPb="/data/leure/forLuke/loop_Bs0_PbPb_MC_25072017_pthat10.root"

## PbPb DATA 
INPUTDATAPbPb="/data/wangj/Data2015/Bntuple/PbPb/Bntuple_BfinderData_PbPb_20160406_bPt5jpsiPt0tkPt0p8_BpB0BsX_skimhlt.root"

## ANALYSIS PP TRIGGERED
FONLLDATINPUT="fonllInputs/fonllInput.dat"
FONLLOUTPUTFILE="outputBs.root"
OUTPUTFILERAA="ROOTfiles/outputRAA.root"

LABELPP="pp"
LUMIPP=27.4
ISMCPP=0
ISDOWEIGHTPP=0
SELGENPP="TMath::Abs(Gy)<2.4&&abs(GpdgId)==521&&GisSignal==1"

# Candan's unoptimized cuts (used in Julia's slides)
CUTPP="TMath::Abs(By)<2.4&&TMath::Abs(Bmumumass-3.096916)<0.15&&Bmass>5&&Bmass<6&&Btrk1Pt>1.5&&Btrk2Pt>1.5&&Bchi2cl>.0132&&BsvpvDistance/BsvpvDisErr>3.05&&Bd0/Bd0Err>2&&cos(Bdtheta)>.26&&Bmu1pt>1.5&&Bmu2pt>1.5&&Bpt>5.75&&abs(Btktkmass-1.019455)<.0155&&Blxy>.025"
RECOONLYPP=$CUTPP

TRGPP="(HLT_HIL1DoubleMu0_v1)"
OUTPUTFILEPP="ROOTfiles/hPtSpectrumBsPP.root"
OUTPUTFILEMCSTUDYPP="ROOTfiles/MCstudiesPP.root"
OUTPUTFILEPlotPP="ROOTfiles/CrossSectionPP.root"

OUTPUTFILEPbPb="ROOTfiles/hPtSpectrumBsPbPb.root"

#SETTING for NP fit
# this setting for the fit was causing problems. The fit is assumed to be a linear plus a gaussian in the code  as of 9/1/2017
#NPFIT_PP="3.12764e1*TMath::Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*TMath::Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2) + 2.11124e2"
NPFIT_PP="0"

# iNP from https://github.com/boundino/Bntuple/blob/master/CrossSection/Analysis/fitBs.C
#NPFIT_PP="TMath::Gaus(x,5.36800e+00,5.77122e-02)/(sqrt(2*3.14159)*TMath::Abs(5.77122e-02))"

if [ $DOANALYSISPP_FONLL -eq 1 ]; then      
root -l -b -q Bsdsigmadpt.cc
fi 

echo "-------------------------------------------------------------------------"

if [ $DOANALYSISPP_FIT -eq 1 ]; then      
g++ fitBs.C $(root-config --cflags --libs) -g -o fitBs.exe 
./fitBs.exe 0 "$INPUTDATAPP"  "$INPUTMCPP"  "$TRGPP" "$CUTPP"   "$SELGENPP"   "$ISMCPP"   1   "$ISDOWEIGHTPP"   "$LABELPP"  "$OUTPUTFILEPP" "$NPFIT_PP" 0
rm fitBs.exe
fi 

echo "-------------------------------------------------------------------------"

if [ $DOANALYSISPP_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe  0 "$INPUTMCPP"  "$SELGENPP" "$SELGENPPACCPP"  "$RECOONLYPP" "$CUTPP&&$TRGPP"  "$LABELPP" "$OUTPUTFILEMCSTUDYPP" "$ISDOWEIGHTPP" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

echo "-------------------------------------------------------------------------"

if [ $DOANALYSISPP_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE"  "$OUTPUTFILEPP" "$OUTPUTFILEMCSTUDYPP" "$OUTPUTFILEPlotPP" 0 "$LABELPP" 1 "$LUMIPP"
rm CrossSectionRatio.exe
fi

echo "-------------------------------------------------------------------------"

LABELPbPb="PbPb"

LUMIPbPb=13.14

ISMCPbPb=0
ISDOWEIGHTPbPb=0
SELGENPbPbACCPbPb="TMath::Abs(Gy)<2.4&&abs(GpdgId)==521&&GisSignal==1&&TMath::Abs(Gy)<2.4&& ((TMath::Abs(Gmu1eta)<1.2 && Gmu1pt>3.5) || (TMath::Abs(Gmu1eta)>1.2 && TMath::Abs(Gmu1eta)<2.1 && Gmu1pt>(5.77-1.8*TMath::Abs(Gmu1eta))) || (TMath::Abs(Gmu1eta)>2.1 && TMath::Abs(Gmu1eta)<2.4 && Gmu1pt>1.8)) && ((TMath::Abs(Gmu2eta)<1.2 && Gmu2pt>3.5) || (TMath::Abs(Gmu2eta)>1.2 && TMath::Abs(Gmu2eta)<2.1 && Gmu2pt>(5.77-1.8*TMath::Abs(Gmu2eta))) || (TMath::Abs(Gmu2eta)>2.1 && TMath::Abs(Gmu2eta)<2.4 && Gmu2pt>1.8)) && Gtk1pt>0.5 && TMath::Abs(Gtk1eta)<2.4"

SELGENPbPb="TMath::Abs(Gy)<2.4&&abs(GpdgId)==521&&GisSignal==1"

#GA
CUTPbPb="TMath::Abs(By)<2.4&&abs(Bmumumass-3.096916)<0.15&&Bmass>5.&&Bmass<6.&&Btrk1Pt>1.5&&Btrk2Pt>1.5&&Bchi2cl>0.1&&(Bd0/Bd0Err)>5.&&cos(Bdtheta)>0.8&&Bmu1pt>1.5&&Bmu2pt>1.5&&Bpt>15.0&&TMath::Abs(Btktkmass-1.019455)<0.05&&Blxy>0.1"
RECOONLYPbPb="1"

TRGPbPb="(HLT_HIL1DoubleMu0_v1 || HLT_HIL1DoubleMu0_part1_v1 || HLT_HIL1DoubleMu0_part2_v1 || HLT_HIL1DoubleMu0_part3_v1)"

OUTPUTFILEMCSTUDYPbPb="ROOTfiles/MCstudiesPbPb.root"
OUTPUTFILEPlotPbPb="ROOTfiles/CrossSectionPbPb.root"

#SETTING for NP fit
#NPFIT_PbPb="3.39711e1*TMath::Gaus(x,5.35002e0,3.87952e-2)*(x<5.35002e0)+(x>=5.35002e0)*3.39711e1*TMath::Gaus(x,5.35002e0,1.14232e-1)+2.16376e2*TMath::Erf(-(x-5.14189)/8.66243e-2) + 2.16376e2"
NPFIT_PbPb="0"

if [ $DOANALYSISPbPb_FIT -eq 1 ]; then      
g++ fitBs.C $(root-config --cflags --libs) -g -o fitBs.exe 
./fitBs.exe 1 "$INPUTDATAPbPb"  "$INPUTMCPbPb"  "$TRGPbPb" "$CUTPbPb"   "$SELGENPbPb"   "$ISMCPbPb"   1   "$ISDOWEIGHTPbPb"   "$LABELPbPb"  "$OUTPUTFILEPbPb" "$NPFIT_PbPb" 0 "$CENTPbPbMIN" "$CENTPbPbMAX"
rm fitBs.exe
fi 

echo "-------------------------------------------------------------------------"

if [ $DOANALYSISPbPb_MCSTUDY -eq 1 ]; then      
g++ MCefficiency.C $(root-config --cflags --libs) -g -o MCefficiency.exe 
./MCefficiency.exe 1 "$INPUTMCPbPb"  "$SELGENPbPb" "$SELGENPbPbACCPbPb"  "$RECOONLYPbPb" "$CUTPbPb&&$TRGPbPb"  "$LABELPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$ISDOWEIGHTPbPb" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm MCefficiency.exe
fi

echo "-------------------------------------------------------------------------"

if [ $DOANALYSISPbPb_CROSS -eq 1 ]; then      
g++ CrossSectionRatio.C $(root-config --cflags --libs) -g -o CrossSectionRatio.exe 
./CrossSectionRatio.exe "$FONLLOUTPUTFILE"  "$OUTPUTFILEPbPb" "$OUTPUTFILEMCSTUDYPbPb" "$OUTPUTFILEPlotPbPb" 0 "$LABELPbPb" 0 "$LUMIPbPb"
rm CrossSectionRatio.exe
fi

echo "-------------------------------------------------------------------------"

if [ $DORAA -eq 1 ]; then
g++ NuclearModificationFactor.C $(root-config --cflags --libs) -g -o NuclearModificationFactor.exe
./NuclearModificationFactor.exe "$OUTPUTFILEPlotPP" "$OUTPUTFILEPlotPbPb"  "$LABELPbPb" "$OUTPUTFILERAA" "$CENTPbPbMIN" "$CENTPbPbMAX"
rm NuclearModificationFactor.exe
fi
echo "-------------------------------------------------------------------------"
