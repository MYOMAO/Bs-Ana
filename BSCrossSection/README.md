This repository contains code to perform the RAA calculation for bs analysis. The macro is run by going to the CrossSection directory and doing "source doAnalysis.sh".

doAnalysis.sh sets a bunch of parameters and runs 5 different macros. Each of the macros is outlined below.

# Bsdsigmadpt
Bsdsigmadpt.cc contains code to build the pp reference of the B meson measurements in pp collisions at 5.02 TeV starting from the FONLL calculations. The fonll input file (CrossSection/fonllInputs/fonllInput.dat) were produced using http://www.lpthe.jussieu.fr/~cacciari/fonll/fonllform.html using the following parameters for the calculations:

Collider: LHC(pp, 5.5), Heavy quark: botton ,PDFs: CTEQ6.6

Perturbative order: FONLL, Final state:  B hadron, Further decay: -

Cross section type: dsigma/dpt (or dsigma/dy) uncertainty range from scales and masses

Include PDFs uncertainties: (missing for the moment)

The file fonllInput.dat was produced with the kinematic ranges:

pt min = 10 GeV
pt max = 60 GeV
y min= -2.4
y max= 2.4
Use y:check
npoints=793

Bsdsigmapt.cc outputs a file that can be used for both pp and PbPb fiting calculations

# fitBs
applies cuts to the data and fits a gaussian and quadratic function to the data.

fitBs can be run for both pp and PbPb

# MCefficiency
calculates MCefficiency which is needed in to run CrossSectionRatio if the doDataCor parameter is set to 1. If in CrossSectionRatio the doDataCor parameter is set to 0, MCefficiency is not needed.

MCefficiency can be run for both pp and PbPb

# CrossSectionRatio
CrossSectionRatio plots the theoretical cross section (the output from Bsdsigmadpt) and the calculated cross section (the output from MCefficiency)

CrossSectionRatio can be run for both pp and PbPb

# NuclearModificationFactor
calculates the RAA
