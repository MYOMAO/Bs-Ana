root -l -q -b ratio_histograms.C
sed -i 's/bool PbPb=false/bool PbPb=true/' ratio_histograms.C
root -l -q -b ratio_histograms.C
sed -i 's/bool PbPb=true/bool PbPb=false/' ratio_histograms.C
