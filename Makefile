# Makefile CMPS 3350 Lab05

all: translate

translate.out: translate.cpp
	g++ translate.pp -o translate.out

clean:
	rm -f translate.out
