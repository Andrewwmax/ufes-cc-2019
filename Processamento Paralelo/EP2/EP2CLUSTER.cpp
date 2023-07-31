//////////////////////////////////////////////////////
// 12345 = 8cb2237d0679ca88db6464eac60da96345513964	//
// A1B2C = 7b151de317f2547df39e1a1ff2850a6abfa6128f //
// 123ZZ = 230cdfcdb6f2aa33b7acf19edaae5a216a14155f //
// DCEL = b2cdbf0601d8ae90d3cda1c978566ace86c4eac0  //
// 99999 = a045b7efa463c6ed195c644163f4168952fbd34a //
//////////////////////////////////////////////////////
// CEUNES = d27e086d60a993d203717509c46a6752daccc967//
//////////////////////////////////////////////////////
// mpirun -np 2 -quiet a.out b2cdbf0601d8ae90d3cda1c978566ace86c4eac0
// mpirun -np 2 EP2 b2cdbf0601d8ae90d3cda1c978566ace86c4eac0


#include <bits/stdc++.h> 
#include "sha1.h"
#include "mpi.h"
#include "omp.h"

using namespace std;


void realtime(){	
	time_t initial = time(0);
	while(1){
		time_t current = time(0);
        // string s = ctime(&current);
        // s.resize( s.length() - 1 );
        cout << "\r" << difftime(current, initial) << flush;
	}
}

int ind;
int **distribui(int **limites, char *c, int np){
	for (int /*i = 0*/ i = 1; i < np; i++){
		int ini, fim;
		if (i == np - 1){
			ini = ind;
			fim = strlen(c);
		} else {
			ini = ind;
			fim = ind + strlen(c) / (np - 1);
			ind += strlen(c) / (np - 1);
		}

		limites[i][0] = ini;
		limites[i][1] = fim;
	}
}

void processNP(int rank, int *limite, char *caracteres, char *SENHA) {
	int tam = strlen(caracteres);
	
	// if(rank == 0){
	    char s1[2];
		s1[1] = '\0';
		for(int i = limite[0]; i < limite[1]; i++){
			s1[0] = caracteres[i];
			string CRIPT(sha1(s1));
			if(!CRIPT.compare(SENHA)){
				// if(rank == 0){
				// 	cout << "O Processador rank " << rank << " achou a RESPOSTA" << endl << s1 << " : " << SENHA << endl;
				// 	MPI_Abort(MPI_COMM_WORLD, 0);
				// } else 
					MPI_Send(s1, 2, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
			}
		}

	    char s2[3];
		s2[2] = '\0';
		for(int i = limite[0]; i < limite[1]; i++)
			for(int j = 0; j < tam; j++){
				s2[0] = caracteres[i];
				s2[1] = caracteres[j];
				string CRIPT(sha1(s2));
				if(!CRIPT.compare(SENHA)){
					// if(rank == 0){
					// 	cout << "O Processador rank " << rank << " achou a RESPOSTA" << endl << s2 << " : " << SENHA << endl;
					// 	MPI_Abort(MPI_COMM_WORLD, 0);
					// } else
						MPI_Send(s2, 3, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
				}
			}

	    char s3[4];
		s3[3] = '\0';
		for(int i = limite[0]; i < limite[1]; i++)
			for(int j = 0; j < tam; j++)
				for(int k = 0; k < tam; k++){
					s3[0] = caracteres[i];
					s3[1] = caracteres[j];
					s3[2] = caracteres[k];
					string CRIPT(sha1(s3));
					if(!CRIPT.compare(SENHA)){
						// if(rank == 0){
						// 	cout << "O Processador rank " << rank << " achou a RESPOSTA" << endl << s3 << " : " << SENHA << endl;
						// 	MPI_Abort(MPI_COMM_WORLD, 0);
						// } else 
							MPI_Send(s3, 4, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
					}
				}
	
	// } else {
	    
		char s4[5];
		s4[4] = '\0';
		for(int i = limite[0]; i < limite[1]; i++)
			for(int j = 0; j < tam; j++)
				for(int k = 0; k < tam; k++)
					for(int l = 0; l < tam; l++){
						s4[0] = caracteres[i];
						s4[1] = caracteres[j];
						s4[2] = caracteres[k];
						s4[3] = caracteres[l];
						string CRIPT(sha1(s4));
						if(!CRIPT.compare(SENHA)){
							// if(rank == 0){
							// 	cout << "O Processador rank " << rank << " achou a RESPOSTA" << endl << s4 << " : " << SENHA << endl;
							// 	MPI_Abort(MPI_COMM_WORLD, 0);
							// } else 
								MPI_Send(s4, 5, MPI_CHAR, 0, 1, MPI_COMM_WORLD);	
						}
					}

		char s5[6];
		s5[5] = '\0';
		for(int i = limite[0]; i < limite[1]; i++)
			for(int j = 0; j < tam; j++)
				for(int k = 0; k < tam; k++)
					for(int l = 0; l < tam; l++)
						for(int m = 0; m < tam; m++){
							s5[0] = caracteres[i];
							s5[1] = caracteres[j];
							s5[2] = caracteres[k];
							s5[3] = caracteres[l];
							s5[4] = caracteres[m];
							string CRIPT(sha1(s5));
							if(!CRIPT.compare(SENHA)){
							// 	if(rank == 0){
							// 		cout << "O Processador rank " << rank << " achou a RESPOSTA" << endl << s5 << " : " << SENHA << endl;
							// 		MPI_Abort(MPI_COMM_WORLD, 0);
							// 	} else
									MPI_Send(s5, 6, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
							}
						}
		char s6[7];
		s6[6] = '\0';
		for(int i = limite[0]; i < limite[1]; i++)
			for(int j = 0; j < tam; j++)
				for(int k = 0; k < tam; k++)
					for(int l = 0; l < tam; l++)
						for(int m = 0; m < tam; m++)
							for(int n = 0; n < tam; n++){
								s6[0] = caracteres[i];
								s6[1] = caracteres[j];
								s6[2] = caracteres[k];
								s6[3] = caracteres[l];
								s6[4] = caracteres[m];
								s6[5] = caracteres[n];
								string CRIPT(sha1(s6));
								if(!CRIPT.compare(SENHA)){
								// 	if(rank == 0){
								// 		cout << "O Processador rank " << rank << " achou a RESPOSTA" << endl << s5 << " : " << SENHA << endl;
								// 		MPI_Abort(MPI_COMM_WORLD, 0);
								// 	} else
										MPI_Send(s6, 7, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
								}
							}
	// }

}

int main(int argc, char *argv[]) {

	if (argc != 2) {
        fprintf(stderr, "usage: prog <SHA1>\n");
        exit(1);
    }
	
	char *SENHA = argv[1];
    char *RESPOSTA = (char *) calloc(6, sizeof(char));
	char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	int np, rank;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Status status;

	if(rank == 0) {
		int **limites = (int **) calloc(np, sizeof(int *));
		for (int i = 0; i < np; i++)
			limites[i] = (int *) calloc(np, sizeof(int));

		distribui(limites, caracteres, np);

        for(int i = 1; i < np; i++){
        	int limite[2];
        	limite[0] = limites[i][0];
        	limite[1] = limites[i][1];
            MPI_Send(limite, 2, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
/*	    #pragma omp parallel sections num_threads(3)
		{
	   		#pragma omp section
	 	  	{
	        	realtime();
	    	}
	   		#pragma omp section
	 	  	{
			    processNP(rank, limites[0], caracteres, SENHA);
	    	}
	   		#pragma omp section
	 	  	{
*/

        	// cout << "thread non main" << endl;
        	int numCache;
 	   		MPI_Probe(MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
   		    MPI_Get_count(&status, MPI_CHAR, &numCache);
		    char *RESPOSTA = (char *) calloc(numCache, sizeof(char));
		    // cout << "STATUS: " << status.MPI_SOURCE << endl;
            MPI_Recv(RESPOSTA, numCache, MPI_CHAR, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
			cout << endl <<"O Processador " << status.MPI_SOURCE << " achou a RESPOSTA" << endl << RESPOSTA << " : " << SENHA << endl;
			MPI_Abort(MPI_COMM_WORLD, 1);
	 	  	// }
		// }

    } else {
    	int *limite = (int *) calloc(2, sizeof(int));
        MPI_Recv(limite, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        processNP(rank, limite, caracteres, SENHA);
    }

   MPI_Finalize();
   return 0;
}