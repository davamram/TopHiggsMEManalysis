# FlatTreeMEMproducer

#Input : Flat tree. Output : Flat tree including MEM weights

#Compile FlatTreeMEMproducer

cd src 

make

#Copy and modify config.cfg from MEMmultilepton

#run the FlatTreeMEMproducer interactively

cd ../test

./runMEM ROOTFILE.root EvInit EvEnd --MEMRun Production/config.cfg 1

#ROOTFILE.root is the input rootfile, EvInit EvEnd the events number, Production/config.cfg is the config file

#At the moment, if the last argument is 0 the jet selection must be done prior to the MEM; if it is 1, it is done within the MEM

#Running FlatTreeMEMproducer for production with the lxbatch system : see README in test/Production/

  
