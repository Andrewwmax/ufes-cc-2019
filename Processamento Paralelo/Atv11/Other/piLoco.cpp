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

int ind = 0;

double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

int main(int argc, char *argv[]) {
    double inicio = MyClock();

    long long num_steps = 100000000;
    long double step;
    long long i;
    long double x, pi, sum, sumlocal, sumTotal = 0.0;

    int np, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    MPI_Status status;

    step = 1.0 / (double) num_steps;
    
    if(rank == 0){
        for(int i = 1; i < np; i++){
            MPI_Send(&ini, 1, MPI_LONG_LONG_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&fim, 1, MPI_LONG_LONG_INT, i, 1, MPI_COMM_WORLD);
        }
    
    } else {
        // for(int i = 0; i < np; i++){
            long long int inicio, final;
            
            MPI_Recv(&inicio, 1, MPI_LONG_LONG_INT, 0, 0, MPI_COMM_WORLD, &status);
            MPI_Recv(&final, 1, MPI_LONG_LONG_INT, 0, 1, MPI_COMM_WORLD, &status);
            
            cout << inicio << final << endl;
            
            for (i = inicio; i < final; i++) {
                x = (i + 0.5) * step;
                sumlocal = sumlocal + 4.0 / (1.0 + x * x);

                MPI_Send(&sumlocal, 1, MPI_LONG_DOUBLE, i, 2, MPI_COMM_WORLD);
            }
        // }
    }


    if(rank == 0){
        for(int i = 0; i < np; i++){
            MPI_Recv(&sumTotal, 1, MPI_LONG_DOUBLE, i, 2, MPI_COMM_WORLD, &status);
            // MPI_Reduce(&sumlocal, &sum, np, MPI_LONG_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
            sum +=sumTotal;
        }
        pi = step * sum;
        cout << fixed << setprecision(25);
        cout << "Valor encontrado: " << pi << endl;
        cout << "  Valor esperado: " << M_PI << endl;
        cout << "   Erro Relativo: " << fabs(pi - M_PI)/M_PI << endl;
        //3.141592653589793238462643383279502884197
        double tempoSeq = (MyClock()-inicio)/CLOCKS_PER_SEC;
        printf("     Tempo total: %.5lf\n\n\n", tempoSeq);
    }

    MPI_Finalize();

    return 0;
}
