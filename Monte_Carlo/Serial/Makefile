serial: monte_carlo_serial.cpp
	g++ -fopenmp -o mc_serial monte_carlo_serial.cpp
run_serial:
	srun --cpus-per-task=1 ./mc_serial 100000000
clean:
	rm -f mc_serial *~