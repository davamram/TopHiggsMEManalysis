#!/bin/bash

LOCALDIR=`pwd`
EXECDIR=/afs/cern.ch/work/c/chanon/CMSSW_10_2_0/src/TopHiggsMEManalysis/FlatTreeMEMproducer/test/

export SCRAM_ARCH=slc6_amd64_gcc700
export LC_ALL="en_US.UTF-8"

export X509_USER_PROXY=/afs/cern.ch/user/c/chanon/.globus/gridproxy.cert

cd ${EXECDIR}
eval `scram runtime -sh`

#cd ${LOCALDIR}
cd Production

opt=$1
inputlist=$2
procnum=$3

ii=0
while read line
do

  echo $line > tmp
  proc=`awk '{print $1}' tmp`

  if [[ "${ii}" -eq "${procnum}" ]]
  then
    hadd Jobs_${opt}/output_${proc}_${opt}_all.root Jobs_${opt}/output_${proc}_${opt}_*.root
  fi

  ((ii++))

done < ${inputlist}

ls 
