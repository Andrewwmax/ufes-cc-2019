// Para compilar use o seguinte comando (no linux):
// g++ -fopenmp pi2.cpp -o pi2
// Para executar no cluster: qsub pratica9.sh
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <iomanip>

using namespace std;

static long num_passos = 1000000000;
long double passo;

int main (int argc, char *argv[]) {
	long double pi, somaTotal = 0.0;
	passo = 1.0/(long double) num_passos;

	int th;
	atoi(argv[1]) ? th = atoi(argv[1]) : th = omp_get_num_threads();

	omp_set_num_threads(th);
	somaTotal = 0.0;

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int numthreads = omp_get_num_threads();
		long double x;

		double somaLocal = 0;

		for (int i = id; i < num_passos; i+=numthreads){
			x = (i + 0.5) * passo;
			somaLocal += + 4.0 / (1.0 + x * x);
		}
		#pragma omp reduction
			somaTotal += somaLocal;
	}

	pi = passo * somaTotal;
	cout << fixed << setprecision(25);
	cout << "Thead: " << th << endl;
	cout << "Valor encontrado: " << pi << endl;
	cout << "  Valor esperado: " << M_PI << endl;
	//3.141592653589793238462643383279502884197
	return 0;
}