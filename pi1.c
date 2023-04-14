// a simple parallel pi program version 1 (1st SPMD)

#include <omp.h>
#include <stdio.h>

static long num_steps = 1000000000;
double step;

#define NUM_THREADS 2

void main() {

	int i, nthreads;
	double pi, tdata, sum[NUM_THREADS];

	tdata = omp_get_wtime();

	step = 1.0 / (double) num_steps;
	omp_set_num_threads(NUM_THREADS);

	#pragma omp parallel
	{
		int i, id, nthrds;
		double x;

		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		
		if (id == 0) nthreads = nthrds;

		for (i = id, sum[id] = 0.0; i < num_steps; i = i + nthrds) {
			x = (i + 0.5) * step;
			sum[id] += 4.0 / (1.0 + x * x);
		}
	}
	
	for (i = 0, pi = 0.0; i < nthreads; i++) pi += sum[i] * step;

	tdata = omp_get_wtime() - tdata;

	printf("pi = %f in %f seconds\n", pi, tdata);
}