CXX = c++
CXXFLAGS = -std=c++11
OBJS = bin/dual.o

all: bin/dual.o bin/main clean

bin/dual.o: src/dual.hpp src/dual.cpp
	$(CXX) $(CXXFLAGS) -c src/dual.cpp -o bin/dual.o

bin/main: $(OBJS) src/main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) src/main.cpp -o bin/main

clean:
	rm -rf bin/*.o 
