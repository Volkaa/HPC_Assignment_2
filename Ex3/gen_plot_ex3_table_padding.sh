#!/bin/sh

gcc -fopenmp maxloc_parallel_table_padding.c

> results.txt

for j in 1 2 4 8 12 16 20 24 28 32
do
	for i in 1 2 3 4 5 6 7 8 9 10
	do
		./a.out $j > temp.txt
		grep -w "Time:" temp.txt | cut -d " " -f2 >> results.txt
	done
done


python3 calc_3_5.py < results.txt