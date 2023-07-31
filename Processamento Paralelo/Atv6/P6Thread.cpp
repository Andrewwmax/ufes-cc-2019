// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread P6.cpp -o P6
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
#include <mutex>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()
// #define FUNCAO(I) (sqrt(I)+pow(I, I)+log(I))

// #define DEBUG

int N, numThreads, ind;
double minimo = INFINITY;
vector<double> M;
mutex mux;

void aplicaFuncao(int ini, int fim){
    int min = M[ini];
    // printf("Thread");
    for(int i = ini; i != fim; i++){
        if(min > M[i]){
            min = M[i];
        }
    }
    mux.lock();
    if(minimo > min){
        minimo = min;
        // printf("%4.0f\n", minimo);
    }
    mux.unlock();
    //criar vetor de tamanho das threads, salvar ao final,
    //e buscar no vetor resultado o minimo
}

int main(int argc, char *argv[]){
    
    if (argc < 3) {
        fprintf(stderr, "usage: prog <n> <numThreads>\n");
        exit(1);
    }
    
    N = atoi(argv[1]);

    numThreads = atoi(argv[2]);

    //cout << thread::hardware_concurrency() << endl;
    //numThreads = thread::hardware_concurrency();

    srand(time(0)); 

    M.resize(N);
    for (int i = 0; i < N; ++i) M[i] = random();
    // for (int i = 0; i < N; ++i) M[i] = (rand() % N) + N / 3;
    // M.resize(N, 0.1 + (rand() % 10000) / 10000.0);
    
    auto start_time = timeNow();
    thread th[numThreads];
    ind = 0;

    for (int i = 0; i < numThreads; i++){
        int ini, fim;
        if (i == numThreads - 1){
            ini = ind;
            fim = N;
            // cout << N << endl;
        } else {
            ini = ind;
            fim = ind + N / numThreads;
            ind += N / numThreads;
            // cout << ind << endl;
        }
        th[i] = thread(aplicaFuncao, ini, fim);
    }
    
    for (int i = 0; i < numThreads; ++i) th[i].join();

    // for (int i = 0; i < N; i++) printf("%4.0f, ", M[i]);
    // printf("\n\nMINIMO: %.0f\n", minimo);

    auto end_time = timeNow();
    cout << fixed << setprecision(2);
    cout << duration(end_time - start_time) / 1000.f << flush;

    return 0;
}

