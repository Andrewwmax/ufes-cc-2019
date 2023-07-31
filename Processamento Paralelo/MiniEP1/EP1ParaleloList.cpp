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

double *somaGlobal;

double aplicaFuncaoESoma(list<double> M){
    double soma = 0.0;
    
    for(auto i: M) soma += FUNCAO(i);

    return soma;
}

int main(int argc, char *argv[]){
    
    if (argc != 2) {
        fprintf(stderr, "usage: ./EP1ParaleloList <N>\n");
        exit(1);
    }

    int N = atoi(argv[1]);

    //Semente fixa para gerar sempre os mesmos números
    srand(0);

    //Paralelo
    auto start_time_total = timeNow();
    
    somaGlobal = (double *) mmap(NULL, sizeof(*somaGlobal), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    pid_t parentPid;
    parentPid = fork();
    
    if(parentPid == 0) {

        list<double> M1(N / 4, 0.1 + (rand() % 10000) / 10000.0); 
        *somaGlobal += aplicaFuncaoESoma(M1);
        // cout << "\nTempo 1: " << duration(end_time - start_time_total) / 1000.f << " ms\n" << flush;
        
        pid_t childPid = fork();
        if(childPid == 0){
            list<double> M2(N / 4, 0.1 + (rand() % 10000) / 10000.0); 
            *somaGlobal += aplicaFuncaoESoma(M2);
            // munmap(somaGlobal, sizeof *somaGlobal);
            // cout << "\nTempo 2: " << duration(end_time - start_time_total) / 1000.f << " ms\n" << flush;
            return 0;
        
        } else if(childPid > 0){
            wait(NULL);
            list<double> M3(N / 4, 0.1 + (rand() % 10000) / 10000.0); 
            *somaGlobal += aplicaFuncaoESoma(M3);
            // cout << "\nTempo 3: " << duration(end_time - start_time_total) / 1000.f << " ms\n" << flush;

        } else perror("childPid");

    } else if (parentPid > 0){
        list<double> M4(N / 4, 0.1 + (rand() % 10000) / 10000.0); 
        *somaGlobal += aplicaFuncaoESoma(M4);
        wait(NULL);
        return 0;
        // cout << "\nTempo 4: " << duration(end_time - start_time_total) / 1000.f << " ms\n" << flush;

    } else perror("parentPid");


    // double soma = aplicaFuncaoESoma(M);
    cout << fixed << setprecision(4);
    auto end_time_total = timeNow();
    
    // cout << "Otimizado Paralelis com List<>";
    // cout << *somaGlobal;
    cout << duration(end_time_total - start_time_total) / 1000.f << flush;
    // cout << "\nSoma: " << *somaGlobal;
    // cout << "\nTempo Total: " << duration(end_time_total - start_time_total) / 1000.f << " ms\n" << flush;

    return 0;
}

