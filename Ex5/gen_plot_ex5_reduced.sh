#!/bin/sh

gcc -fopenmp n_body_serial_reduced.c -lm

> results.txt

for i in 1 2 3 4 5
do
	./a.out > temp.txt
	grep -w "Execution time :" temp.txt | cut -d " " -f4 >> results.txt
done


gcc -fopenmp n_body_parallel_reduced.c -lm


for j in 1 2 4 6 8 10 12 16 20 24 28 32
do
	for i in 1 2 3 4 5
	do
		./a.out $j > temp.txt
		grep -w "Execution time :" temp.txt | cut -d " " -f4 >> results.txt
	done
done


python3 calc_5_reduced.py < results.txt