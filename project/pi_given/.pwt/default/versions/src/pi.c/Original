// Forward declaration of sqrt
double sqrt(double x);

double pi(int N) {

	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		double x = (i + 0.5) / N;
		sum += sqrt(1 - x * x);
	}
	return 4.0 / N * sum;
}
