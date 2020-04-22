#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <omp.h>
 
#define N 1000000

int main(int argc, char* argv [])
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

	int nb_threads = atoi(argv[1]);
	omp_set_num_threads(nb_threads);
	
	double t1 = omp_get_wtime();

	double maxval[nb_threads], mval;
	int maxloc[nb_threads], mloc;

	for(i=0; i < nb_threads; i++)
	{
		maxval[i] = 0.0;
	}
	#pragma omp parallel 
	{
		int thread_nb = omp_get_thread_num();
		#pragma omp for
		for (i=0; i < N; i++)
		{
			if (x[i] > maxval[thread_nb]) 
		    	maxval[thread_nb] = x[i]; maxloc[thread_nb] = i;
		}	
	}
	mval = 0;
	for(i=0; i<nb_threads; i++)
	{
		if (maxval[i] > mval)
		{
			mval = maxval[i];
			mloc = maxloc[i];
		}
	}


	double t = (omp_get_wtime() - t1);


	printf("Maximum value : %f, Maximum found value : %f\n", act_maxval, mval);
	printf("Time: %f\n", t);
}
