acc: monte_carlo_acc.cpp
	pgc++ -ta=tesla:nollvm -Minfo=all monte_carlo_acc.cpp
run_acc:
	srun -p cisc372 --gres=gpu:1 ./a.out 100000000000
clean:
	rm -f a.out *~