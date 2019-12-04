#include <omp.h>

// Forward declaration of sqrt
double sqrt(double x);

double pi(int N) {

	double sum = 0.0;
	#pragma omp parallel default(none) shared(N, sum)
	{
    omp_set_num_threads(8);
	#pragma omp for reduction(+: sum) schedule(auto)
	for (int i = 0; i < N; i++) {
		double x = (i + 0.5) / N;
		sum += sqrt(1 - x * x);
	}
	} // end parallel
	return 4.0 / N * sum;
}
