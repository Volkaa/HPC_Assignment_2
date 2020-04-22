#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <omp.h>
 
#define N 1000000

int main(int agrc, char* agrv [])
{

	ssize_t i;
	
	double x[N];
	srand(time(0)); // seed
	for(i=0; i < N;i++){
		// Generate random number between 0 and 1
		x[i] = ((double)(rand()) / RAND_MAX)*((double)(rand()) / RAND_MAX)*((double)(rand()) / RAND_MAX)*1000;
	}

	// Get the real max
	double act_maxval = 0.0; int act_maxloc = 0;
	for (i=0; i < N; i++)
	{
		if (x[i] > act_maxval) 
		    act_maxval = x[i]; act_maxloc = i;
	}	

	double t1 = omp_get_wtime();

	for(int j = 0; j < 20; j++)
	{
		double maxval = 0.0; int maxloc = 0;

		#pragma omp parallel for shared(maxval, maxloc)
		for (i=0; i < N; i++)
		{
			#pragma omp critical
			{
				if (x[i] > maxval) 
			    	maxval = x[i]; maxloc = i;
			}
		}	
	}
	double maxval = 0.0; int maxloc = 0;

	double t = (omp_get_wtime() - t1)/20.0;

	

	printf("Maximum value : %f, Maximum found value : %f\n", act_maxval, maxval);
	printf("Time: %f\n", t);
}
