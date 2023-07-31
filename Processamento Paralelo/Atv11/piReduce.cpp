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
    long double step = 1.0 / num_steps;
    long long i;
    long double x, localPi = 0.0, sum = 0.0, pi = 0.0;

    int np, rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) MPI_Bcast(&num_steps, 1, MPI_LONG_LONG_INT, 0, MPI_COMM_WORLD);

    for (i = rank; i < num_steps; i += np) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    localPi = step * sum;

    MPI_Reduce(&localPi, &pi, 1, MPI_LONG_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

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
