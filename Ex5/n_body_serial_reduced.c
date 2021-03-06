#include "stdio.h" // printf
#include "stdlib.h" // malloc and rand for instance. Rand not thread safe!
#include "time.h"   // time(0) to get random seed
#include "math.h"  // sine and cosine
#include "omp.h"   // openmp library like timing
#include <string.h> /* For memset */ 

#define DIM 2
#define X 0
#define Y 1
#define G 0.000000000006673

typedef double vect_t[DIM];


void initialization(vect_t*pos, vect_t* vel, double* mass, int n)
{
	for (int q = 0; q < n; q++) 
	{
		pos[q][X] = (rand() / (double)(RAND_MAX)) * 2 - 1;
		pos[q][Y] = (rand() / (double)(RAND_MAX)) * 2 - 1;

		vel[q][X] = (rand() / (double)(RAND_MAX)) * 2 - 1;
		vel[q][Y] = (rand() / (double)(RAND_MAX)) * 2 - 1;

		mass[q] = fabs((rand() / (double)(RAND_MAX)) * 2 - 1);
	}
}


void compute_forces(vect_t* forces, vect_t*pos, double* mass, int n)
{
	forces = memset(forces, 0, n*sizeof(vect_t)); 
	for (int q = 0; q < n; q++)
	{ 
       	for (int k = n-1; k > q; k--)
       	{
            double x_diff = pos[q][X] - pos[k][X]; 
            double y_diff = pos[q][Y] - pos[k][Y]; 
            double dist = sqrt(x_diff*x_diff + y_diff*y_diff); 
            double dist_cubed = dist*dist*dist; 
            double force_qk_X = G*mass[q]*mass[k]/dist_cubed * x_diff; 
            double force_qk_Y = G*mass[q]*mass[k]/dist_cubed * y_diff; 
            forces[q][X] += force_qk_X; 
            forces[q][Y] += force_qk_Y; 
            forces[k][X] -= force_qk_X; 
            forces[k][Y] -= force_qk_Y; 
       } 
	}
}

void move_particles(vect_t* forces, vect_t* vel, vect_t* pos, 
					double* mass, int n, double delta_t)
{
	for (int q = 0; q < n; q++)
	{
		pos[q][X] += delta_t*vel[q][X]; 
		pos[q][Y] += delta_t*vel[q][Y];

		vel[q][X] += delta_t/mass[q]*forces[q][X]; 
		vel[q][Y] += delta_t/mass[q]*forces[q][Y];
	}
}


void print_pos_vel (vect_t* vel, vect_t* pos, int n)
{
	for (int q = 0; q < n; q++)
	{
		printf("Particle %d, pos : [%f,%f], vel : [%f,%f]\n", q, pos[q][X], pos[q][Y], vel[q][X], vel[q][Y]);
	}
}


void print_calc (vect_t* vel, vect_t* pos, int n)
{
	for (int q = 0; q < n; q++)
	{
		printf("%f\n%f\n", pos[q][X], pos[q][Y]);
	}
}


int main (int argc, char* argv[]) 
{
	int n = 500;
	int cycles = 100;
	double delta_t = 0.05;

	srand(time(0)); // seed

	vect_t* forces = malloc(n*sizeof(vect_t));
	vect_t* vel = malloc(n*sizeof(vect_t));
	vect_t* pos = malloc(n*sizeof(vect_t));
	double* mass = malloc(n*sizeof(double));

	initialization(vel, pos, mass, n);

	double start_time = omp_get_wtime();

	for(int c = 0; c < cycles; c++)
	{
		compute_forces(forces, pos, mass, n);
		move_particles(forces, vel, pos, mass, n, delta_t);
		//print_calc(vel, pos, n);
	}
	
	double time = omp_get_wtime() - start_time;
	printf("Execution time : %f\n", time);

	//print_pos_vel(vel, pos, n);

}