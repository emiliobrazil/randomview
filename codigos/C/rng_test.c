#include <stdio.h>
#include <time.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main(void)
{
	// ----------------------------------------------------------------------
	// init with default algorithm (gsl_rng_default = gsl_rng_mt19937)
	// ----------------------------------------------------------------------
	const gsl_rng_type * T = gsl_rng_default;
	gsl_rng * r = gsl_rng_alloc(T);
	
	// ----------------------------------------------------------------------
	// seed
	// ----------------------------------------------------------------------
	unsigned long int s = time(0);
	gsl_rng_set(r, s);
	
	// ----------------------------------------------------------------------
	// random sequencies generation
	// ----------------------------------------------------------------------
	
	int i, n = 10;
	
	// generate random numbers from distribution U(0,1)
	printf("Random numbers from distribution U(0,1)\n");
	for (i = 0; i < n; i++) {
		double u = gsl_rng_uniform_pos(r);
		printf("%.5f\n", u);
	}
	
	// generate random numbers from distribution Exponential(lambda)
	double lambda = 10.0;
	printf("Random numbers from distribution Exponential(%f)\n", lambda);
	for (i = 0; i < n; i++) {
		double u = gsl_ran_exponential(r, lambda);
		printf("%.5f\n", u);
	}
	
	// generate random numbers from distribution Bernoulli(p)
	double p = 0.3;
	printf("Random numbers from distribution Bernoulli(%f)\n", p);
	for (i = 0; i < n; i++) {
		unsigned int u = gsl_ran_bernoulli(r, p);
		printf("%u\n", u);
	}
	
	// ----------------------------------------------------------------------
	// cleanup
	// ----------------------------------------------------------------------
	gsl_rng_free(r);
	
	return 0;
}

// Compilation:
// gcc rng_test.c /usr/local/lib/libgsl.a -o rng_test