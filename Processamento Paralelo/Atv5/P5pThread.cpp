// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread -lrt P5.cpp -o P5
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
#include <pthread.h>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()
#define FUNCAO(I) (sqrt(I)+pow(I, I)+log(I))

#define DEBUG

int N, numThreads, ind/*, *ini, *fim*/;
vector<double> M;

typedef struct tamThread{
    int ini, fim, th;
} sThread;

void *aplicaFuncao(void *th){
    sThread *t = (sThread *) th;
    for(int i = t->ini; i < t->fim; i++) {
        // printf("%.3f, ", M[i]);
        M[i] = FUNCAO(M[i]);
    }
}

int main(int argc, char *argv[]){
    auto start_time = timeNow();
    if (argc < 3) {
      fprintf(stderr, "usage: prog <n> <numThreads>\n");
      exit(1);
    }

    // N = 10000000;
    N = atoi(argv[1]);
    
    // numThreads = 4;
    numThreads = atoi(argv[2]);
    //numThreads = thread::hardware_concurrency();

    srand(0); 

    M.resize(N, 0.1 + (rand() % 10000) / 10000.0);
    // M.resize(N, 1);

    ind = 0;
    int pth;
    pthread_t threads[numThreads];
    // ini = (int *) calloc(numThreads, sizeof(int));
    // fim = (int *) calloc(numThreads, sizeof(int));

    sThread *th = (sThread *) calloc(numThreads, sizeof(sThread));

    for (int i = 0; i < numThreads; i++){
        if (i == numThreads - 1){
            th[i].ini = ind;
            th[i].fim = N;
            // cout << N << endl;
        } else {
            th[i].ini = ind;
            th[i].fim = ind + N / numThreads;
            ind += N / numThreads;
            // cout << ind << endl;
        }
    }
    
    for (int i = 0; i < numThreads; i++){
        sThread *s =  &th[i];
        pth = pthread_create(&threads[i], NULL, aplicaFuncao, (void *)  &th[i]);
        if (pth){
            printf("ERRO; pthread_create() devolveu o erro %d\n", pth);
            exit(-1);
        }
    }

    for (int i = 0; i < numThreads; i++) pthread_join(threads[i], NULL);

    
#ifdef DEBUG
    cout << accumulate(M.begin(), M.end(), 0.0) << "\t" ;
#endif


    auto end_time = timeNow();
    cout << fixed << setprecision(2);
    cout << duration(end_time - start_time) / 1000.f << " " << flush;

    return 0;
}

