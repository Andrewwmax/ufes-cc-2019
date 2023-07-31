#include "mpi.h"
#include <stdio.h>
 
int main( int argc, char *argv[] ){
    int errs = 0;
    int provided, flag, claimed;
 
    MPI_Init_thread( 0, 0, MPI_THREAD_MULTIPLE, &provided );
    printf("TESTE\n");   
    MPI_Is_thread_main( &flag );
    if (!flag) {
        errs++;
        printf( "This thread called init_thread but Is_thread_main gave false\n" );//fflush(stdout);
    }
    MPI_Query_thread( &claimed );
    if (claimed != provided) {
        errs++;
        printf( "Query thread gave thread level %d but Init_thread gave %d\n", claimed, provided );//fflush(stdout);
    }
 
    MPI_Finalize();
    return errs;
}