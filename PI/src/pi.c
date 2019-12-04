#include <stdlib.h>

// Forward declaration of sqrt
double sqrt(double x);
int rand();
double pow(double a, double b);
double tgamma(double a);
//calculus approach serial
double pi_v1_s(int N) {
	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		double x = (i + 0.5) / N;
		sum += sqrt(1 - x * x);
	}
	return 4.0 / N * sum;
}

double pi_v1_p(int N) {

	double sum = 0.0;
	#pragma omp parallel default(none) shared(N, sum)
	{
	#pragma omp for reduction(+: sum) schedule(auto)
	for (int i = 0; i < N; i++) {
		double x = (i + 0.5) / N;
		sum += sqrt(1 - x * x);
	}
	} // end parallel
	return 4.0 / N * sum;
}

//Gregory-Leibniz Series
double pi_v2_s(int N){
	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		double denominator = 1 + 2* i;
		double x = (double) 1 / denominator;
		if( i % 2 == 1){
			x = x * -1;
		}
		sum += x;
	}
	return sum * 4;
}

double pi_v2_p(int N){
	double sum = 0.0;
	#pragma omp parallel default(none) shared(N, sum)
	{
	#pragma omp for reduction(+: sum) schedule(auto)
	for (int i = 0; i < N; i++) {
		double denominator = 1 + 2* i;
		double x = (double) 1 / denominator;
		if( i % 2 == 1){
			x = x * -1;
		}
		sum += x;
	}
	} // end parallel
	return sum * 4;
}

//Nilakantha Series
double pi_v3_s(int N){
	double sum = 3.0;
	for (int i = 0; i < N; i++) {
		double denominator = (i+2) * (i+3) * (i+4);
		double x = (double) 4 / denominator;
		if( i % 2 == 1){
			x = x * -1;
		}
		sum += x;
	}
	return sum;
}

double pi_v3_p(int N){
	double sum = 3.0;
	#pragma omp parallel default(none) shared(N, sum)
	{
	#pragma omp for reduction(+: sum) schedule(auto)
	for (int i = 0; i < N; i++) {
		double denominator = (i+2) * (i+3) * (i+4);
		double x = (double) 4 / denominator;
		if( i % 2 == 1){
			x = x * -1;
		}
		sum += x;
	}
	} // end parallel
	return sum;
}

double pi_v4_s(int N){
		srand((unsigned)time(NULL));
		double count = 0;
        for (int i = 0; i < N; i++)
		 {
		    double a, b;
            a = (double) ((rand() % 1000) / 1000.0);
			b = (double) ((rand() % 1000) / 1000.0);
			if( a*a + b*b <= 1){
				count++;
			}
        	}
        return (double) count / N  * 4;
}

double pi_v4_p(int N) {
	srand((unsigned)time(NULL));
	double sum = 0.0;
	#pragma omp parallel default(none) shared(N, sum)
	{
	unsigned int myseed = omp_get_thread_num();
	#pragma omp for reduction(+: sum) schedule(auto)
	for (int i = 0; i < N; i++) {
		double a, b;
        a = (double) ((rand_r(&myseed) % 1000) / 1000.0);
		b = (double) ((rand_r(&myseed) % 1000) / 1000.0);
		if( a*a + b*b <= 1){
				sum++;
		}
	}
	} // end parallel
	return (double) sum / N  * 4;
}

double pi_v5_s(int N){
	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		double a, b, c, d, e, temp;
		a = tgamma((i)*6 + 1);
		b = 545140134 * i;
		
		c = tgamma(i+1);
		c = (double) pow(c, 3);
		
		
		d = (double) tgamma((i)*3 + 1);
		e = (double) pow(-640320, (i)*3);
		double numerator, denominator;
		numerator = a * (b + 13591409.0);
		denominator = c * d * e;
		temp = numerator / denominator;
		sum += temp;
	}
	double sqr = sqrt(10005);
	return 426880.0 * sqr /sum;
}

double pi_v5_p(int N) {

	double sum = 0.0;

	#pragma omp parallel default(none) shared(N, sum)
	{
	#pragma omp for reduction(+: sum) schedule(auto)
	for (int i = 0; i < N; i++) {
		double a, b, c, d, e, temp;
		a = tgamma((i)*6 + 1);
		b = 545140134 * i;
		
		c = tgamma(i+1);
		c = (double) pow(c, 3);
		
		
		d = (double) tgamma((i)*3 + 1);
		e = (double) pow(-640320, (i)*3);
		double numerator, denominator;
		numerator = a * (b + 13591409.0);
		denominator = c * d * e;
		temp = numerator / denominator;
		sum += temp;
	}
	} // end parallel
	double sqr = sqrt(10005);
	return 426880.0 * sqr /sum;
}


