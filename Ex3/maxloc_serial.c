#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
# include <unistd.h>
# include <math.h>
# include <float.h>
# include <limits.h>

#define N 1000000

double mysecond(){
  struct timeval tp;
  struct timezone tzp;
  int i;

  i = gettimeofday(&tp,&tzp);
  return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6 );
}

int main(int agrc, char* agrv [])
{

	double x[N];
	srand(time(0)); // seed
	for(int i=0; i < N;i++){
		// Generate random number between 0 and 1
		x[i] = ((double)(rand()) / RAND_MAX)*((double)(rand()) / RAND_MAX)*((double)(rand()) / RAND_MAX)*1000;
	}

	double t1 = mysecond();

	double maxval = 0.0; int maxloc = 0;
	for (int j = 0; j < 100; j++) 
	{
		maxval = 0.0; maxloc = 0;
		for (int i=0; i < N; i++)
		{
			if (x[i] > maxval) 
			    maxval = x[i]; maxloc = i;
		}	
	}

	double t = (mysecond() - t1)/100.0;

	printf("Max val : %f\n", maxval);
	printf("Time : %f\n", t);
}
