#include "mpi.h"
#include <math.h>

int main(int argc, char *argv[]){
   
    int done = 0, /*n,*/ rank, np, i;
    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;
    long double n = 10e8;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    while (!done) {
		// if (rank == 0) {
		// 	n = 10e8;
		//     // printf("Enter the number of intervals: (0 quits) ");
		//     // scanf("%d",&n);
		// }
		
		MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
		if (n == 0) break;
	  
		h   = 1.0 / (double) n;
		sum = 0.0;
		for (i = rank + 1; i <= n; i += np) {
		    x = h * ((double)i - 0.5);
		    sum += 4.0 / (1.0 + x*x);
		}

		mypi = h * sum;
    
		MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    
		if (rank == 0)
	    	printf("pi is approximately %.16f, Error is %.16f\n", pi, fabs(pi - PI25DT));
    	done = 1;
    }

    MPI_Finalize();
    
    return 0;
}