CXX=g++
CXXFLAGS=-O3 -fopenmp
LDFLAGS=-fopenmp -O3

OBJECTS=EP2.o

removeRuido: $(OBJECTS)
	$(CXX) $(LDFLAGS) removeRuido -o $(OBJECTS)

all:	removeRuido

run:	all
	./removeRuido balloons.ppm 5


clean:
	rm -f *.optrpt *.o removeRuido *~ 
