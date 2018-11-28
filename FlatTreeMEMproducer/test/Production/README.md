# Helpers to run FlatTreeMEMproducer using the lxbatch system

# 1) Verify your input samples: Go to the directory test/Production. FileList.txt contains the name of the processes and root address of the samples on eos. Update FileList.txt. This list is used to check that the sample address exists, and how many events are contained in the samples via:

bash ./CheckEntriesInput.sh

# 2) Edit PrepareJobs.bash. The opt field is the suffix of the directory which will be created and will contain all the jobs to be launched. nEv is the number of event per job. With queue 1nd, the optimal number of jobs is between 10 (for ttH hypothesis) and 40 (for tZq hypothesis). The following command will create the directory, and use RunBatchMEM_template as a template for creating all the jobs. If many jobs must be created it can take some time. PrepareJobs.sh prepares the jobs but does not launch them. Redirecting its output is useful, because the output displays the command to launch the jobs. You just need to move launchJobs.sh in the directory containing the jobs and launch it via (it is better to do it with screen since it can take some time):

bash ./PrepareJobs.bash > launchJobs.sh

# 3) Launch the jobs. It might be a good idea to use the screen command (launching also takes time). 

screen

# reload all the environment variables (LHAPDF, MEMEXECDIR, LSB_JOB_REPORT_MAIL) 

source launchJobs.sh 

# 4) Check if all the jobs are done via  http://lsf-rrd.cern.ch/lrf-lsf/info.php?queue=1nd. Alternatively use:

bjobs

# When they are done, it is still possible that some of their outputs are either missing, corrupted or that the copy to afs went wrong. To detect such cases, it is useful to use the following command, to checks the outputs and create a new list of jobs remaining to be launched :

bash ./CheckRootFiles.sh > launchJobs_remains.sh 

# 5) Merging the output. All the samples are splitted in many outputs. They are aded with:

bash ./HaddRootFiles.sh

# 6) Upload the merged outputs to eos. Modify the RenameAndUploadToEos.sh script with updating the eos repository and the prefix of the sample you want to rename into.

bash ./RenameAndUploadToEos.sh

# 7) Merge rootfile with systematic variation: TO BE DESCRIBED.
