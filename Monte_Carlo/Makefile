serial: monte_carlo_serial.cpp
	g++ -fopenmp -o mc_serial monte_carlo_serial.cpp
omp: monte_carlo_omp.cpp
	g++ -fopenmp -o mc_omp monte_carlo_omp.cpp
acc: monte_carlo_acc.cpp
	pgc++ -ta=tesla:nollvm -Minfo=all monte_carlo_acc.cpp
run_acc:
	srun -p cisc372 --gres=gpu:1 ./a.out 100000000000
clean:
	rm -f mc_serial mc_omp a.out *~