#!/bin/sh

gcc -fopenmp maxloc_parallel_critical.c

> results.txt

for j in 1 2 4 8 12 16 20 24 28 32
do
	export OMP_NUM_THREADS=$j
	./a.out > temp.txt
	grep -w "Time:" temp.txt | cut -d " " -f2 >> results.txt
done

python3 calc_3.py < results.txt