INCLUDE = $(CURDIR)/matrix_hal/
all:
	g++ -g -I $INCLUDE -Wall -std=c++0x matrix_hal/*.cpp prog.cpp -o socket
