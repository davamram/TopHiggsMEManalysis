#------------------------------------------------------------------------------
#Madgraph definitions
MADDIR=../../../MEMmultilepton/src/Madgraph
TTH_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_4/src
THAD_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_DECAY_tbwjj/src
ATHAD_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_DECAY_antitbwjj/src
TLEP_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_DECAY_tbwlnu/src
H2L2NU_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_DECAY_hw2l2nu/src
TTLL_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_DECAY_ggttll/src
TTWP_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_ckm_DECAY_qqttlpvl/src
TTWM_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_ckm_DECAY_qqttlmvl/src
TTWPJJ_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_ckm_DECAY_ppttlpvljj/src
TTWMJJ_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_ckm_DECAY_ppttlmvljj/src
TTbar_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_DECAY_ggtt/src
TLLQ_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_no_b_mass_DECAY_pptllq/src
WZJJ_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_DECAY_gqlnullgq/src
THQ_MADINCDIR=${MADDIR}/PROC_SA_CPP_sm_no_b_mass_DECAY_ppthq/src
TTLL_EFT_MADINCDIR=${MADDIR}/PROC_SA_CPP_dim6top_LO_UFO_all_DECAY_ggttll/src
TTLL_EFT_MADLIBDIR=${MADDIR}/PROC_SA_CPP_dim6top_LO_UFO_all_DECAY_ggttll/lib
TTLL_EFT_MADMODELLIB=model_dim6top_LO_UFO_all_ggttll
MADINCDIR = -I$(TTH_MADINCDIR) -I$(THAD_MADINCDIR) -I$(ATHAD_MADINCDIR) -I$(TLEP_MADINCDIR) -I$(H2L2NU_MADINCDIR) -I$(TTLL_MADINCDIR) -I$(TTWP_MADINCDIR) -I$(TTWM_MADINCDIR) -I${TTWPJJ_MADINCDIR} -I${TTWMJJ_MADINCDIR} -I${TTbar_MADINCDIR} -I${TLLQ_MADINCDIR} -I${WZJJ_MADINCDIR} -I${THQ_MADINCDIR} -I${TTLL_EFT_MADINCDIR}
#------------------------------------------------------------------------------
# ROOT definitions
ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs) -lMathMore -lMinuit2
#------------------------------------------------------------------------------
#LHAPDF definitions
LHAPDFINCDIR=-I${LHAPDF}/include
LHAPDFLIB=-L${LHAPDF}/lib -lLHAPDF
#------------------------------------------------------------------------------
# g++ options
CXX = g++
CXXFLAGS = -g -O3 -fPIC -Wall -Wno-deprecated
CXXFLAGS     += $(ROOTCFLAGS) ${LHAPDFINCDIR} ${MADINCDIR}
LIBS         = ${ROOTGLIBS} ${ROOTLIBS} ${LHAPDFLIB} -L../../../MEMmultilepton -lMEMmultilepton -L${TTLL_EFT_MADLIBDIR} -l${TTLL_EFT_MADMODELLIB}
#------------------------------------------------------------------------------
# Compilation

all : ../test/runMEM

clean:
	rm *.o
	rm ../test/runMEM

objects= runMEM.o ReadFlatTree.o

../test/runMEM: $(objects)
	$(CXX) -o ../test/runMEM $(objects) ${LIBS}  $(CXXFLAGS)

runMEM.o: runMEM.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c runMEM.cpp

ReadFlatTree.o: ReadFlatTree.cpp
	$(CXX) ${LIBS} ${CXXFLAGS} -c ReadFlatTree.cpp
#ConfigParser.o: src/ConfigParser.cpp
#        $(CXX) ${LIBS} ${CXXFLAGS} -c src/ConfigParser.cpp
