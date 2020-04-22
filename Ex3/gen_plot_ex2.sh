#!/bin/sh

export OMP_NUM_THREADS=1

for i in 1 2 3 4 5
do
	./a.out > temp.txt
	grep -w "Copy" temp.txt | cut -d " " -f13 >> results.txt
done

for j in 2 4 8 12 16 20 24 28 32
do
	export OMP_NUM_THREADS=$j

	for i in 1 2 3 4 5
	do
		./a.out > temp.txt
		grep -w "Copy" temp.txt | cut -d " " -f12 >> results.txt
	done
done

python3 calc.py < results.txt