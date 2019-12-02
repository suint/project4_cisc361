#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double pi(int N);

// --- Basic timer function ---------------------------------------------------

#ifdef _OPENMP
	#include <omp.h>
	#define getClock() omp_get_wtime()
#else
	#include <time.h>
	#define getClock() ((double)clock() / CLOCKS_PER_SEC)
#endif


// --- Launcher function ------------------------------------------------------

int main(int argc, char* argv[]) {
	
	// Reads the test parameters from the command line
	double arg_n = 0.0;
	int param_iters = 1;
	if(argc >= 2) sscanf(argv[1], "%lf", &arg_n);
	if(argc >= 3) param_iters = atoi(argv[2]);
	
	if(arg_n < 1 || arg_n >= INT_MAX || param_iters < 1) {
		printf("This test uses the numerical integration method to obtain 'pi':\n");
		printf("  The parameter <steps> controls the precision of the approximation.\n");
		printf("  The optional parameter [iters] is used to repeat the test several times.\n");
		printf("Usage: %s <steps> [iters]\n", argv[0]);
		exit(0);
	}
	
	// Allocates input/output resources
	// Initializes data
	int param_steps = (int)arg_n;
	double out_result;
	
	// Calls the function that performs the actual computation
	printf("- Executing test...\n");
	double time_start = getClock();
	// ================================================

		for(int iters = 0; iters < param_iters; iters++) {
			out_result = pi(param_steps);
		}
		
	// ================================================
	double time_finish = getClock();

	// Prints an execution report
	printf("time (s)= %.6f\n", time_finish - time_start);
	printf("size\t= %i\n", param_steps);
	printf("chksum\t= %.8f\n", out_result);
	const double realPiValue = 3.141592653589793238;
	printf("error\t= %.1e\n", fabs(out_result - realPiValue));
	if(param_iters > 1) printf("iters\t= %i\n", param_iters);
	
	return 0;
}
