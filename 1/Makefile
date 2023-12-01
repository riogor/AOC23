CXX=g++
CFLAGS=-Wall -O2 -std=c++20 -DLOCAL

all: format 1 2

1: 1.cpp
	$(CXX) $(CFLAGS) -o $@ $^

2: 2.cpp
	$(CXX) $(CFLAGS) -o $@ $^

format :
	clang-format -i *.cpp

clean:
	rm -f *.o 1 2 output.txt
