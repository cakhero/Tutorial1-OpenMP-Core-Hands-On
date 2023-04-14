// a simple serial pi program

#include <omp.h>
#include <stdio.h>

static long num_steps = 1000000000;
double step;

int main() {
	
	int i;
	double x, pi, tdata, sum = 0.0;

	tdata = omp_get_wtime();

	step = 1.0 / (double) num_steps;
	
	for (i = 0; i < num_steps; i++) {
		x = (i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}
	
	pi = step * sum;

	tdata = omp_get_wtime() - tdata;
	
	printf("pi = %f in %f seconds\n", pi, tdata);
}