CXX=g++
CXXFLAGS=-O3
LDFLAGS=-O3

OBJECTS=main.o sha1.o

sha1: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o sha1 $(OBJECTS)

all:	sha1

run:	all
	./sha1


clean:
	rm -f *.optrpt *.o sha1 *~ 

# g++ -O3 EP2.cpp sha1.cpp sha1.h -o EP2