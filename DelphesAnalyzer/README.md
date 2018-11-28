# DelphesAnalyzer

#Set environment variables of Delphes and run the DelphesAnalyzer interactively

source setup_Delphes.csh

root -l run.C

#If willing to run on batch, use instead:

bsub -q 1nd RunDelphesAnalyzer

#Run FlatTreeMEMproducer on the output of RunDelphesAnalyzer

#Adapt Skim.C and run it on MEM output

root -l Skim.C

#After skimming, the output is ready for MVA/DNN training

