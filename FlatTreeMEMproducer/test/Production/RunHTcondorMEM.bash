#!/bin/bash

LOCALDIR=`pwd`
EXECDIR=/afs/cern.ch/work/c/chanon/CMSSW_10_2_0/src/TopHiggsMEManalysis/FlatTreeMEMproducer/test/

export SCRAM_ARCH=slc6_amd64_gcc700
export LC_ALL="en_US.UTF-8"

export LHAPDF=/afs/cern.ch/work/c/chanon/LHAPDF-6.2.1-install
export LHAPATH=/afs/cern.ch/work/c/chanon/LHAPDF-6.2.1-install/share/LHAPDF/
export LHAPDF_BIN=/afs/cern.ch/work/c/chanon/LHAPDF-6.2.1-install/bin
export PATH=${PATH}:${LHAPDF_BIN}
export LD_LIBRARY_PATH=/afs/cern.ch/work/c/chanon/LHAPDF-6.2.1-install/lib

#rehash

export X509_USER_PROXY=/afs/cern.ch/user/c/chanon/.globus/gridproxy.cert

cd ${EXECDIR}
eval `scram runtime -sh`

INPUTFILE=$1
NEVPERJOB=$2
DIR_JOBS=$3
OPTION=$4
PROC=$5
NUMTMP=$6

ii=0
for i in `cat ${DIR_JOBS}/Jobs_${OPTION}/JobsList_${PROC}.txt`
do
  #echo $i
  if [[ "${ii}" -eq "${NUMTMP}" ]]
  then
    NUM=${i}
  fi
  ((ii++))
done

NMIN=$((${NUM} * ${NEVPERJOB}))
NMAX=$((${NMIN} + ${NEVPERJOB}))

echo Process: ${PROC}
echo Running on file: ${INPUTFILE}, events ${NMIN} to ${NMAX}
echo Output dir: ${DIR_JOBS}/Jobs_${OPTION} 


cd ${LOCALDIR}

${EXECDIR}/./runMEM ${INPUTFILE} ${NMIN} ${NMAX} --MEMRun ${DIR_JOBS}/Jobs_${OPTION}/config.cfg 1 ${DIR_JOBS}/Jobs_${OPTION}/listVar.txt > log_${PROC}_${OPTION}_${NUM}

ls 

cp log_${PROC}_${OPTION}_${NUM} ${DIR_JOBS}/Jobs_${OPTION}/log_${PROC}_${OPTION}_${NUM}
cp output.root ${DIR_JOBS}/Jobs_${OPTION}/output_${PROC}_${OPTION}_${NUM}.root
