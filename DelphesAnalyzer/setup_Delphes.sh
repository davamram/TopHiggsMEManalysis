#!/bin/sh
cd /group/cms/chanon
source setup.sh
cd /gridgroup/cms/amram/code/TopHiggsMEManalysis/DelphesAnalyzer
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/gridgroup/cms/amram/MG5_aMC_v3_3_2/Delphes/
export ROOT_INCLUDE_PATH=/gridgroup/cms/amram/MG5_aMC_v3_3_2/Delphes/external/
