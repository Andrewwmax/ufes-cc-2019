#include<bits/stdc++.h> 
#include "sha1.h"
#include <sys/time.h>
#include "mpi.h"


#define POS1(I) ((I%63))
#define POS2(I) ((I/63)%63)
#define POS3(I) (((I/63)/63)%63)
#define POS4(I) ((((I/63)/63)/63)%63)
#define POS5(I) (((((I/63)/63)/63)/63)%63)

#define MAX 63*63*63*63*63
#define TAM(S) (MAX/S)

using namespace std; 

long int i;

double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

int main(int argc, char *argv[]) { 
	if (argc < 2) {
      fprintf(stderr, "usage: prog <sha1> \n");
      exit(1);b2cdbf0601d8ae90d3cda1c978566ace86c4eac0
    }
	double inicio = MyClock();
	double tempoTotal;

	char caracteres[] = {"\0ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz"}; //63	//"\00123..." =ruim

	int rank,size;
	MPI_Init (& argc , & argv );
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);  //pid
    MPI_Comm_size (MPI_COMM_WORLD, &size);      //process number

	char s[6];
	s[0] = '\0';
	s[1] = '\0';
	s[2] = '\0';
	s[3] = '\0';
	s[4] = '\0';
	s[5] = '\0';
	
	int ini, fim;
	ini = (TAM (size) * rank) - 1;
	fim = TAM (size) * (rank + 1);
	if(rank == size - 1)
		fim = MAX;
	
	for (i = ini; i < fim; i++) {	
		s[0] = caracteres[POS1(i)];
		s[1] = caracteres[POS2(i)];
		s[2] = caracteres[POS3(i)];
		s[3] = caracteres[POS4(i)];
		s[4] = caracteres[POS5(i)];
		
		if(argv[1] == sha1(s)){
			cout << " > " << rank << " i = "<< i << ", \t" << s << " =\t" << sha1(s) << endl;
			
			cout << fixed << setprecision(5);

			cout << "Tempo total: " << (MyClock() - inicio) / CLOCKS_PER_SEC << endl;
			
			MPI_Abort(MPI_COMM_WORLD, 1);	
			cout << rank << " abortou \n"<<endl;
			break;
		}
	}
	cout << rank << " nao achou" << endl;
	MPI_Finalize() ;
	cout << fixed << setprecision(5);
	cout << "Tempo total: " << (MyClock() - inicio) / CLOCKS_PER_SEC << endl;

    return 0;
}
