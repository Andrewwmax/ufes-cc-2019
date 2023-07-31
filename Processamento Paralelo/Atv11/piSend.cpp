// Para compilar, você pode usar o seguinte comando (no linux):
// g++ pi.cpp -o pi
// Para executar no cluster: qsub pratica11.sh
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <sys/time.h>
#include "mpi.h"

using namespace std;

double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

int main(int argc, char *argv[]){
    double inicio = MyClock();

    long long int num_steps = 10e9;
    long double step;
    step = 1.0 / num_steps;
    long long int i;
    long double x, localSum = 0.0, procSum = 0.0, sum = 0.0, pi;

    int np, rank;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    if (rank == 0) {
        for (i = rank; i < num_steps ; i += 4) {
            x = (i + 0.5) * step;
            localSum = localSum + 4.0 / (1.0 + x * x);
        }
        for(i = 1; i < np ; i++){
            MPI_Recv(&procSum, 1, MPI_LONG_DOUBLE, i, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            localSum += procSum;
        }
    } else {
        for (i = rank; i < num_steps ; i += np) {
            x = (i + 0.5) * step;
            localSum = localSum + 4.0 / (1.0 + x * x);
        }
        MPI_Send(&localSum, 1, MPI_LONG_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    // sum = localSum;
    pi = step * localSum;
    MPI_Finalize();

    if (rank == 0){

        cout << fixed << setprecision(25);
        cout << "Valor encontrado: " << pi << endl;
        cout << "  Valor esperado: " << M_PI << endl;
        //3.141592653589793238462643383279502884197
        cout << "   Erro Relativo: " << fabs(pi - M_PI) / M_PI << endl;
        cout << "     Tempo total: " << (MyClock()-inicio) / CLOCKS_PER_SEC << endl;
        // printf("     Tempo total: %.5lf\n\n\n", tempoSeq);
    }


    return 0;
}
