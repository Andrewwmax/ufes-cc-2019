// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -lrt miniEP1.cpp -o miniEP1
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
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<milliseconds>(a).count()
#define timeNow() high_resolution_clock::now()
#define FUNCAO(I) (sqrt(I) + pow(I, I) + log(I))

double aplicaFuncaoESoma(list<double> M){
    double soma = 0.0;
    
    for(auto i: M) soma += FUNCAO(i);

    return soma;
}

int main(int argc, char *argv[]){

    if (argc != 2) {
        fprintf(stderr, "usage: ./EP1Sequencial <N>\n");
        exit(1);
    }

    int N = atoi(argv[1]);

    double soma = 0.0;

    //Semente fixa para gerar sempre os mesmos números
    srand(0);

    list<double> M(N, 0.1 + (rand() % 10000) / 10000.0); 
    //Sequencial

    auto start_time_total = timeNow();
    soma = aplicaFuncaoESoma(M);
    auto end_time_total = timeNow();
    cout << fixed << setprecision(4);
    
    // cout << "Otimizado Sequencialis";
    // cout << soma << endl;
    cout << duration(end_time_total - start_time_total) / 1000.f << flush;
    // cout << "\nSoma: " << soma;
    // cout << "\nTempo Total: " << duration(end_time_total - start_time_total) / 1000.f << " ms\n" << flush;

    return 0;
}

