omp: monte_carlo_omp.cpp
	g++ -fopenmp -o mc_omp monte_carlo_omp.cpp
run_omp:
	srun --cpus-per-task=4 ./mc_omp 1000000000 4
clean:
	rm -f mc_omp *~