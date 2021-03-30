#!/bin/bash

echo "Compile Script ...";

#Compile
g++ -c main.cpp;
g++ -c test.cpp;
g++ -Wall -O2 -o main main.o test.o;

#Clean
rm -f main.o test.o

echo "Script Complete ...";