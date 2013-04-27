#!/bin/sh

# Create fair and square numbers before execute solver :-p

g++48 mp.cpp -o mp -O3
./mp | ruby2.0 check.rb > mp.out