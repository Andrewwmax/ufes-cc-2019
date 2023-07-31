// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread -lrt pratica5.cpp -o pratica5
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

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()
#define FUNCAO(I) (sqrt(I)+pow(I, I)+log(I))

//Comente esse #define para não imprimir 
//o valor da soma dos elmentos do vetor
#define DEBUG

int N, numThreads;

int main(int argc, char *argv[]){
    auto start_time = timeNow();
    if (argc < 3) {
      fprintf(stderr, "usage: prog <n> <numThreads>\n");
      exit(1);
    }
    //Quantidade de elementos
    N = atoi(argv[1]);
    //Número de threads
    numThreads = atoi(argv[2]);

    //Semente fixa para gerar sempre os mesmos números
    srand(0); 

    // Gera uma lista, de tamanho N. Em cada posição, um número 
    // aleatório x (0.1 <= x <= 0.9) é sorteado e, a esse valor, 
    // é aplicado a função FUNCAO(x) 
    // vector<double> M(N, 1); 
    vector<double> M(N, 0.1 + (rand()%10000)/10000.0); 
    for(auto i = M.begin(); i != M.end(); i++)
        *i = FUNCAO(*i);

    
#ifdef DEBUG
    //Apenas para verificar se tudo foi feito como esperado
    //Seu código paralelo deve imprimir a mesma coisa do que é
    //impresso na versão sequencial
    //https://en.cppreference.com/w/cpp/algorithm/accumulate
    cout << accumulate(M.begin(), M.end(), 0.0) << "\t" ;
#endif

    auto end_time = timeNow();
    cout << fixed << setprecision(2);
    cout << duration(end_time - start_time) / 1000.f << " " <<flush;

    return 0;
}

