#!/bin/sh

gcc -fopenmp n_body_serial_simple.c -lm

./a.out > temp.txt

gcc -fopenmp n_body_parallel_simple.c -lm

./a.out 10 > temp2.txt

diff temp.txt temp2.txt > results_simple.txt



gcc -fopenmp n_body_serial_reduced.c -lm

./a.out > temp.txt

gcc -fopenmp n_body_parallel_reduced.c -lm

./a.out 10 > temp2.txt

diff temp.txt temp2.txt > results_reduced.txt