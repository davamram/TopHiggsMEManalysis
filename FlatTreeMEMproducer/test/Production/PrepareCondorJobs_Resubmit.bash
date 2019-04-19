#!/bin/bash

#Automatically creates jobs, given the processes and files listed in the first argument (typically FileList.txt)
#Environment variables LHAPDF and MEMEXECDIR (containing the executable) must be set

#Suffix of the subdirectory: jobs will be created in Jobs_${opt}, that should contain the config.cfg file and listVar.txt 
opt=Training2land3l

#nEv events are run per job. Recommended nEv=6. If running also TTWJJ hyp, use nEv=1 (very slow). Depends on process
nEv=50

#HTcondor queue
queue=tomorrow

#mkdir Jobs_${opt}
#cp config_Production.cfg Jobs_${opt}/config.cfg
#cp listVar_Production.txt Jobs_${opt}/listVar.txt
cp RunHTcondorMEM.bash Jobs_${opt}/RunHTcondorMEM.bash

#outputDir=`echo ${PWD}/Jobs_${opt}`
#echo OUTPUTDIR: ${outputDir}

minimumsize=5000

rm Jobs_${opt}/SendAllJobs_resubmit.sh

while read line
do

  echo $line > tmp
  proc=`awk '{print $1}' tmp`
  inputfile=`awk '{print $2}' tmp`
  echo $proc $inputfile

  root -l -q 'ReadEntries.C("'${inputfile}'")' | awk 'NR==3' > tmp
  nEntries=`cat tmp`

  nJobs=$(($nEntries / $nEv ))
  echo nEntries=$nEntries nJobs=$nJobs

  #nJobsMax=$((20000/$nEv))
  #echo nJobsMax=$nJobsMax

  cp sendHTcondor.sub Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub
  sed -i s,INPUTFILE,${inputfile},g Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub
  sed -i s/NEV/${nEv}/g Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub
  sed -i s,OUTPUTDIR,${PWD},g Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub
  sed -i s/PROC/${proc}/g Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub
  sed -i s/OPTION/${opt}/g Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub
  sed -i s/QUEUE/${queue}/g Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub
#  sed -i s/NJOBS/${nJobs}/g Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub

  #rm Jobs_${opt}/SendAllJobs_resubmit.sh
  echo condor_submit sendHTcondor_${proc}_resubmit.sub >> Jobs_${opt}/SendAllJobs_resubmit.sh

  rm Jobs_${opt}/JobsList_${proc}.txt

  nJobsRedo=0
  for i in `seq 0 $nJobs`
  do
    if [ -f Jobs_${opt}/output_${proc}_${opt}_${i}.root ]
    then
      actualsize=$(wc -c <"Jobs_${opt}/output_${proc}_${opt}_${i}.root")
      if [ $actualsize -le $minimumsize ]
      then
        rm Jobs_${opt}/output_${proc}_${opt}_${i}.root
        echo ${proc} Job ${i} returned corrupted output, added to Jobs_${opt}/JobsList_${proc}.txt
        echo ${i} >> Jobs_${opt}/JobsList_${proc}.txt
	((nJobsRedo++))
      fi
    else
      echo ${proc} missing output for Job ${i}, added to Jobs_${opt}/JobsList_${proc}.txt
      echo ${i} >> Jobs_${opt}/JobsList_${proc}.txt
      ((nJobsRedo++))
    fi
  done

  sed -i s/NJOBS/${nJobsRedo}/g Jobs_${opt}/sendHTcondor_${proc}_resubmit.sub

done < $1

chmod +x Jobs_${opt}/SendAllJobs.sh
