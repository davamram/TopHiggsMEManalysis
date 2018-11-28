# SubGradientMinimizer

#Create SubGradient minimizer library

root -l -q createLibSubGradient.C

#Compile a test program for the SubGradient library

make clean

make

#The library SubGradient_h.so can be linked with MEMmultilepton and used in the MEM kinematic fits
