// Para compilar, você pode usar o seguinte comando (no linux):
// g++ pi.cpp -o pi
// Para executar no cluster: qsub pratica11.sh
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <mpi.h>
#include <sys/time.h>

using namespace std;

double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

int main(){
    double inicio = MyClock();
    long long num_steps = 10e9;
    long double step;
    long long i;
    long double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps;
    MPI_Init(NULL,NULL);
        int world_rank, world_size;
        MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);
        long double outsidesum,localsum = 0.0;
        long double bot,top,qtd;

        for (i = world_rank ;i < num_steps ; i+=world_size) 
        {
            x = (i+0.5)*step;
            localsum = localsum + 4.0/(1.0+x*x);
        }
        // if (world_size < 2) 
        // {
        //     fprintf(stderr, "World size must be greater than 1 for \n");
        //     MPI_Abort(MPI_COMM_WORLD, 1);
        // }
        if (world_rank == 0) {
            // If we are rank 0, set the number to -1 and send it to process 1
            //MPI_Recv(void *buf, int count, MPI_Datatype type, int source,int tag, MPI_Comm comm, , MPI_Status *status);
            for(i = 1; i < world_size ; i++)
            {
                MPI_Recv(&outsidesum, 1, MPI_LONG_DOUBLE, i, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                localsum += outsidesum;
            }
            //v.push_back(localsum);
        }else
        {
            //int MPI_Send(void *buf, int count, MPI_Datatype type, int dest, int tag, MPI_Comm comm);
            MPI_Send(&localsum, 1, MPI_LONG_DOUBLE, 0, 0, MPI_COMM_WORLD);
        }
    MPI_Finalize () ;
    sum = localsum;
    pi = step * sum;


    cout << fixed << setprecision(25);
    cout << "Valor encontrado: " << pi << endl;
    cout << "  Valor esperado: " << M_PI << endl;
    //3.141592653589793238462643383279502884197
    cout << "   Erro Relativo: " << fabs(pi - M_PI)/M_PI << endl;
    //3.141592653589793238462643383279502884197
    double tempoSeq = (MyClock()-inicio)/CLOCKS_PER_SEC;
    printf("     Tempo total: %.5lf\n\n\n", tempoSeq);
    return 0;
}
