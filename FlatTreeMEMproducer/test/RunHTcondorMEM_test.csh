#!/bin/csh

setenv LOCALDIR `pwd`
setenv EXECDIR /afs/cern.ch/work/c/chanon/CMSSW_10_2_0/src/TopHiggsMEManalysis/FlatTreeMEMproducer/test/

setenv LC_ALL "en_US.UTF-8"

setenv LHAPDF /afs/cern.ch/work/c/chanon/LHAPDF-6.2.1-install
setenv LHAPATH /afs/cern.ch/work/c/chanon/LHAPDF-6.2.1-install/share/LHAPDF/
setenv LHAPDF_BIN /afs/cern.ch/work/c/chanon/LHAPDF-6.2.1-install/bin
setenv PATH ${PATH}:${LHAPDF_BIN}
setenv LD_LIBRARY_PATH /afs/cern.ch/work/c/chanon/LHAPDF-6.2.1-install/lib

rehash

setenv X509_USER_PROXY /afs/cern.ch/user/c/chanon/.globus/gridproxy.cert

cd ${EXECDIR}
eval `scram runtime -csh`

setenv INPUTFILE $1
setenv NEVPERJOB $2
setenv DIR_JOBS $3
setenv OPTION $4
setenv PROC $5
setenv NUM $6

set NMIN=`expr $NUM \* $NEVPERJOB`
set NMAX=`expr $NMIN + $NEVPERJOB`

echo Process: ${PROC}
echo Running on file: ${INPUTFILE}, events ${NMIN} to ${NMAX}
echo Output dir: ${DIR_JOBS}/Jobs_${OPTION} 


cd ${LOCALDIR}
#${EXECDIR}/./runMEM /afs/cern.ch/work/n/ntonon/public/ntuples/input_ntuples/tHq2017/3l/SR/tHq.root 0 1 --MEMRun ${EXECDIR}/Production/config.cfg 1 > log_tHq_test
${EXECDIR}/./runMEM ${INPUTFILE} ${NMIN} ${NMAX} --MEMRun ${DIR_JOBS}/Jobs_${OPTION}/config.cfg 1 ${DIR_JOBS}/Jobs_${OPTION}/listVar.txt > log_${PROC}_${OPTION}_${NUM}

ls 

cp log_${PROC}_${OPTION}_${NUM} ${DIR_JOBS}/Jobs_${OPTION}/log_${PROC}_${OPTION}_${NUM}
cp output.root ${DIR_JOBS}/Jobs_${OPTION}/output_${PROC}_${OPTION}_${NUM}.root
