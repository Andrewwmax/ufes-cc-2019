// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread minSeq.cpp -o minSeq 
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

#define DEBUG

int valorMin;
long numElementos = 500000000;
int numThreads;
vector<int> valor;

void calculaMenorElemento() {
	for (int i = 0; i < numElementos; i++) {
		if(valor[i] < valorMin)
			valorMin = valor[i];
	}
}

int main(int argc, char *argv[]) {
	srand(time(0));
	if (argc != 2) {
		fprintf(stderr, "usage: ./a.out <threads>\n");
		exit(1);
	}

	numThreads = atoi(argv[1]);
	
	valor.resize(numElementos);
	for(int i=0; i<numElementos; i++)
		valor[i] = random();

	auto inicio = timeNow();
	valorMin = valor[0];
	calculaMenorElemento();
	auto fim = timeNow();

#ifdef DEBUG
	cout << "Valor minimo esperado: " << *min_element(valor.begin(), valor.end()) << endl;
	cout << "Valor minimo encontrado: " << valorMin << endl;
#endif

	cout << "Tempo gasto: " << duration(fim - inicio) / 1000.f << " ms\n" << flush;

	return 0;
}