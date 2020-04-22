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

	omp_set_num_threads(10);

	double t1 = omp_get_wtime();

	double maxval = 0.0; int maxloc = 0;
		
	#pragma omp parallel for shared(maxval, maxloc)
	for (i=0; i < N; i++)
	{
		//#pragma omp critical
		//{
		double current_maxval = maxval;
		if(omp_get_thread_num() == 0)
			sleep(0.01);
			if (x[i] > current_maxval) 
		    	maxval = x[i]; maxloc = i;
		// }
	}	

	double t = (omp_get_wtime() - t1);

	

	printf("Maximum value : %f, Maximum found value : %f\n", act_maxval, maxval);
	printf("Time : %f\n", t);
}
