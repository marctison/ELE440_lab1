## This is the default target, which will be built when 
## you invoke make
##
##g++ -Wall -g *.cpp -o test
#.PHONY: all
#all:
#	mkdir -p ../bin
#	mv binary ../bin
#
## This rule tells make to delete hello and hello.o
#.PHONY: clean 
#clean:
#	rm -f ../bin/*
# Define required macros here
SHELL = /bin/sh

OBJS =  main.o algo.o resources.o
SOURCES = main.cpp algo.cpp resources.cpp
CFLAGS = -Wall -g
CC = g++
INCLUDE =
LIBS = -lm

lab1bin:${OBJ}
	mkdir -p ../bin
	${CC} ${CFLAGS} ${INCLUDES} ${SOURCES} -o ../bin/$@

clean:
	rm -f ../bin/*

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
