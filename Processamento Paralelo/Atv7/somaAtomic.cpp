// g++ -O3 -std=c++11 somaElementos.cpp -o somaElementos 
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <chrono>
#include <list>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <thread>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()

// #define DEBUG

long numElementos = 100000000;
int numThreads;
vector<int> valor;

//Implementar 3 versões:
// - Usando critical
// - Usando atomic
// - Usando reduction



long somaElementosAtomic() {
	long soma = 0;
	#pragma omp parallel for
		for (int i = 0; i < numElementos; i++) {
			#pragma omp atomic
				soma += valor[i];
		}
	return soma;
}

int main(int argc, char *argv[]) {

	valor.resize(numElementos);
	for(int i=0; i<numElementos; i++)
		valor[i] = random()%10;

	auto inicio = timeNow();
	long soma = somaElementosAtomic();
	auto fim = timeNow();

#ifdef DEBUG
	cout << "  Valor soma esperado: " << accumulate(valor.begin(), valor.end(), 0) << endl;
	cout << "Valor soma encontrado: " << soma << endl;
#endif

	cout << "Tempo gasto: " << duration(fim - inicio) / 1000.f << " ms\n" << flush;

	return 0;
}