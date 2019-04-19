# Helpers to run FlatTreeMEMproducer using the lxbatch Condor system

#1) Verify your input samples: Go to the directory test/Production. FileList.txt contains the name of the processes and root address of the samples on eos. Update FileList.txt. This list is used to check that the sample address exists, and how many events are contained in the samples via:

bash ./CheckEntriesInput.sh FileList.txt

#2) Edit PrepareCondorJobs.bash. The opt field is the suffix of the directory which will be created and will contain all the jobs to be launched. nEv is the number of event per job. With queue 1nd, the optimal number of jobs is between 10 (for ttH hypothesis) and 40 (for tZq hypothesis). The following command will create the directory, and use RunHTcondorMEM.bash as a template for creating all the jobs. If many jobs must be created it can take some time. PrepareCondorJobs.bash prepares the jobs but does not launch them. Redirecting its output is useful, because the output displays the command to launch the jobs. You just need to move launchJobs.sh in the directory containing the jobs and launch it via (it is better to do it with screen since it can take some time):

bash ./PrepareCondorJobs.bash FileList.txt 

#3) Launch the jobs. It might be a good idea to use the screen command (launching can also takes time). 

screen

#reload all the environment variables (LHAPDF, MEMEXECDIR) and enter in the Jobs directory created by PrepareCondorJobs.bash

source SendAllJobs.sh 

#4) Check if all the jobs are done via  https://monit-grafana.cern.ch/. Alternatively use:

condor_q

#When they are done, it is still possible that some of their outputs are either missing, corrupted or that the copy to afs went wrong. To detect such cases, it is useful to use the following command, to checks the outputs and create a new list of jobs remaining to be launched :

bash ./CheckRootFiles.sh FileList.txt

#Preparing the remaining jobs is done with:

bash ./PrepareCondorJobs_Resubmit.bash FileList.txt

#5) Merging the output. All the samples are splitted in many outputs. They are aded with:

bash ./HaddRootFiles.sh FileList.txt

# Alternatively, this command can be run on Condor batch system with the following command, once the condor submit file has been updated:

condor_submit sendHTcondorHaddRootfiles.sub

#6) Upload the merged outputs to eos. Modify the RenameAndUploadToEos.sh script with updating the eos repository and the prefix of the sample you want to rename into.

bash ./RenameAndUploadToEos.sh

#7) Merge rootfile with systematic variation: TO BE DESCRIBED.
