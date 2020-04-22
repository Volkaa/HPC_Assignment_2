#!/bin/sh

gcc -fopenmp DFTW_1.c -lm

> results.txt

for i in 1 2 3 4 5
do
	./a.out > temp.txt
	grep -w "computation" temp.txt | cut -d " " -f4 >> results.txt
done


gcc -fopenmp DFTW_1_parallel.c -lm


for j in 1 2 4 6 8 10 12 16 20 24 28 32
do
	for i in 1 2 3 4 5
	do
		./a.out $j > temp.txt
		grep -w "computation" temp.txt | cut -d " " -f4 >> results.txt
	done
done


python3 calc_4.py < results.txt