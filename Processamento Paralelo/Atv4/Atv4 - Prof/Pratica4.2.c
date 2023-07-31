#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

int nA, nB, n;

double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

int main(int argc, char *argv[]) {
	
	double inicio = MyClock();

	int **A, **B;
	int tmp;
	if (argc != 4) {
	  fprintf(stderr, "usage: prog <A> <B> n\n");
	  exit(1);
	}
	/* Abre os arquivos com os dados da matriz A*/
	FILE *matrizA = fopen(argv[1], "r");
	if (matrizA == NULL) {
	  fprintf(stderr, "Nao foi possivel abrir o arquivo da matriz A\n");
	  exit(1);
	}
	/* Abre os arquivos com os dados da matriz B */
	FILE *matrizB = fopen(argv[2], "r");
	if (matrizB == NULL) {
	  fprintf(stderr, "Nao foi possivel abrir o arquivo da matriz B\n");
	  exit(1);
	}

	n = atoi(argv[3]);

	/* Faz a leitura da matriz A */
	tmp = fscanf(matrizA, "%d", &nA);
	A = malloc (nA * sizeof (double *));
	for(int i=0; i<nA; i++)
	  A[i] = malloc(nA * sizeof(double));

	for(int i=0; i<nA; i++)
	  for(int j=0; j<nA; j++){
	      tmp = fscanf(matrizA, "%d", &A[i][j]);
	  }
	// printf("Matriz A\n");
	// for(int i=0; i<nA; i++){
	//     for(int j=0; j<nA; j++){
	//         printf("%d\t", A[i][j]);
	//     }
	//     printf("\n");
	// }
	  
	/* Faz a leitura da matriz A */
	tmp = fscanf(matrizB, "%d", &nB);
	if(nA != nB){
	  fprintf(stderr, "nA != nB");
	  exit(1);
	}
	B = malloc (nB * sizeof (double *));
	for(int i=0; i<nB; i++)
	  B[i] = malloc(nB * sizeof(double));

	for(int i=0; i<nB; i++)
	  for(int j=0; j<nB; j++){
	      tmp = fscanf(matrizB, "%d", &B[i][j]);
	  }

	/* Você deve calcular: A*B, B*A, A^n, B^n */
	/* Salve o resultado de cada operação em um arquivo */
	/* Faça cada operação em um processo */

	int pid = fork();

	if (pid < 0) { /* ocorreu erro na execução do Fork */
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (pid == 0) { /* processo filho */

	}
	else{ /* processo pai */

	}

	fclose(matrizA);
	fclose(matrizB); 

	printf("Tempo total: %.10lf\n", (MyClock()-inicio)/CLOCKS_PER_SEC);
	return 0;

	}