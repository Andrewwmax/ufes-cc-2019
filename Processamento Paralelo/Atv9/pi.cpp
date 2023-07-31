// Para compilar use o seguinte comando (no linux):
// g++ -fopenmp pi.cpp -o pi
// Para executar no cluster: qsub pratica9.sh
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){
	long long num_steps = 1000000000;
	long double step;
	long long i;
	long double x, pi, sum = 0.0;
	step = 1.0 / (double) num_steps;

	int th;
	atoi(argv[1]) ? th = atoi(argv[1]) : th = omp_get_num_threads();

	#pragma omp parallel num_threads(th)
	{
		#pragma omp for reduction(+:sum)
			for (i = 0; i < num_steps; i++) {
				x = (i + 0.5) * step;
				sum = sum + 4.0 / (1.0 + x * x);
			}
	}
	pi = step * sum;

	cout << fixed << setprecision(25);
	cout << "Thead: " << th << endl;
	cout << "Valor encontrado: " << pi << endl;
	cout << "  Valor esperado: " << M_PI << endl;
	//3.141592653589793238462643383279502884197
	return 0;
}
