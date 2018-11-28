#------------------------------------------------------------------------------
# ROOT definitions
ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs) -lMathMore  -lMinuit2

#------------------------------------------------------------------------------
# g++ options

CXX = g++
CXXFLAGS = -g -O -fPIC -Wall -Wno-deprecated  
LD = g++

SOFLAGS = -shared #-dynamiclib #-single_module #-undefined dynamic_lookup

CXXFLAGS     += $(ROOTCFLAGS) 

LIBS         = ${ROOTGLIBS} ${ROOTLIBS} -LSubGradient_h.so
#------------------------------------------------------------------------------
# Compilation

all : testMinimizer

clean:
	rm *.o
	rm test*

objects= TestMinimizer.o

testMinimizer: $(objects) 
	$(CXX) -o testMinimizer TestMinimizer.o ${LIBS}  $(CXXFLAGS) #${SOFLAGS}

TestMinimizer.o: TestMinimizer.cpp Functions.h SubGradient.h
	$(CXX) ${LIBS} ${CXXFLAGS} -c TestMinimizer.cpp 

