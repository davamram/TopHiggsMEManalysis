#!/bin/bash

opt=Prod3l

eosdir="/eos/cms/store/user/chanon/THQ/Ntuples_V4/3l_MEMoutput"

while read line
do

  echo $line > tmp
  proc=`awk '{print $1}' tmp`
  inputfile=`awk '{print $2}' tmp`
#  echo $proc $inputfile

  ls Jobs_${opt}/output_${proc}_${opt}_all.root
  eos cp Jobs_${opt}/output_${proc}_${opt}_all.root ${eosdir}/output_${proc}_${opt}_all.root
  echo ${eosdir}/output_${proc}_${opt}_all.root

done < $1 
