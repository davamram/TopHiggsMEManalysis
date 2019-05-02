#!/bin/bash

#Suffix of the subdirectory: jobs will be created in Jobs_${opt}, that should contain the config.cfg file 
opt=Prod3l

#nEv events are run per job. Recommended nEv=6. If running also TTWJJ hyp, use nEv=1 (very slow).
nEv=50

#LSF queue
queue=tomorrow

minimumsize=5000

while read line
do

  echo $line > tmp
  proc=`awk '{print $1}' tmp`
  inputfile=`awk '{print $2}' tmp`
#  echo $proc $inputfile

  root -l -q 'ReadEntries.C("'${inputfile}'")' | awk 'NR==3' > tmp
  nEntries=`cat tmp`

  #nJobs=2000
  nJobs=$(($nEntries / $nEv ))
  #((nJobs++))
#  echo nEntries=$nEntries nJobs=$nJobs

  rm Jobs_${opt}/JobsList_${proc}.txt

  for i in `seq 0 $nJobs` 
  do
    if [ -f Jobs_${opt}/output_${proc}_${opt}_${i}.root ]
    then
      actualsize=$(wc -c <"Jobs_${opt}/output_${proc}_${opt}_${i}.root")
      if [  $actualsize -le $minimumsize ]
      then 
        #rm Jobs_${opt}/output_${proc}_${opt}_${i}.root
        echo ${proc} Job ${i} returned corrupted output, added to Jobs_${opt}/JobsList_${proc}.txt
        echo ${i} >> Jobs_${opt}/JobsList_${proc}.txt
      fi
    else 
      echo ${proc} missing output for Job ${i}, added to Jobs_${opt}/JobsList_${proc}.txt
      echo ${i} >> Jobs_${opt}/JobsList_${proc}.txt
    fi
  done

done < $1



