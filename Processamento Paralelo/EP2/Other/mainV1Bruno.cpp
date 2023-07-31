#include<bits/stdc++.h> 
#include "sha1.h"
#include <sys/time.h>
#include "mpi.h"


#define POS1(I) ((I%62)+1)
#define POS2(I) ((I/63)%63)
#define POS3(I) (((I/63)/63)%63)
#define POS4(I) ((((I/63)/63)/63)%63)
#define POS5(I) (((((I/63)/63)/63)/63)%63)



using namespace std; 

double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

/*
63^5=992.436.543‬
63^4=15.752.961‬	//700mb
63^3=250.047‬	//10mb
63^2=3969
63	=63


*/

long int i;
long int MAX=63*63*63*63*63;	




int main(int argc, char *argv[]) { 
	if (argc < 2) {
      fprintf(stderr, "usage: prog <sha1> \n");
      exit(1);
    }
	double inicio = MyClock();
	

	char caracteres[] = "\00123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //63

	int rank,size;
	MPI_Init (& argc , & argv );
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);  //pid
    MPI_Comm_size (MPI_COMM_WORLD, &size);      //process number

	char s[6];
	s[5] = '\0';
	
	if (rank == 0)
		MPI_Bcast(&MAX, 1, MPI_LONG_INT, 0, MPI_COMM_WORLD);
	
	
	for (i=rank; i<MAX; i+=size) {	
		s[0] = caracteres[POS1(i)];
		s[1] = caracteres[POS2(i)];
		s[2] = caracteres[POS3(i)];
		s[3] = caracteres[POS4(i)];
		s[4] = caracteres[POS5(i)];
		
		if(argv[1]==sha1(s)){
			cout << s << "\t" << sha1(s) << endl;
			break;
		}
		
		//cout << s << "\t" << sha1(s) << endl;
	}
	
	
	MPI_Finalize () ;
	double tempoTotal = (MyClock()-inicio)/CLOCKS_PER_SEC;
	cout << fixed << setprecision(5);
	cout << "     Tempo total: " << tempoTotal << endl;

    return 0;
}
