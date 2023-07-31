#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

int n[4];
//0 - n de entrada,
//1 - tam matA
//2 - tam matB
//3 - tam matC
double inicio;

typedef struct mult {
	double **A, **B;
	int n;
	char *nome;
} tMult;

typedef struct exp {
	double **A;
	int n, tam;
	const char *nome;
} tExp;

double **alocaMat(int n){
	double **mat = (double **) calloc(n, sizeof(double *));
	for(int i = 0; i < n; i++)
		mat[i] = (double *) calloc(n, sizeof(double));
	return mat;
}

double **lerMat(FILE *matriz, int n){
	double tmp;
	double **mat = alocaMat(n);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			tmp = (double) fscanf(matriz, "%lf", &mat[i][j]);
		}
	return mat;
}

void *criaMatMult(double **matrizA, double **matrizB, char *nome, int m){
	tMult *mat = (tMult*) calloc(1, sizeof(tMult*));
	// printf("TESTE CRIA MULT\n");
	mat->n = m;
	mat->A = alocaMat(m);
	mat->B = alocaMat(m);
	mat->A = matrizA;
	mat->B = matrizB;

	mat->nome = (char *) calloc(strlen(nome) - 1, sizeof(char));
	printf("%.0s", nome);
	mat->nome = (char *) nome;
	return mat;
}

void *criaMatExp(double **matrizA, const char *nome, int tam, int m){
	tExp *mat = (tExp *) calloc(1, sizeof(tExp *));
	// printf("TESTE CRIA EXP\n");
	mat->n = m;
	mat->tam = tam;
	mat->A = matrizA;
	mat->nome = nome;
	return mat;
}

double MyClock() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000) + tv.tv_usec;
}

void printMat(double **res, const char *nome, int n){
	// printf(" %s\n", nome);
	FILE *fp = fopen(nome, "w");
	if (fp == NULL){
		puts("Erro Arquivo");
		exit(0);
	} else {
		// printf("%d\n", n);
		fprintf(fp, "%d\n", n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) { 
				if(j == n - 1) fprintf(fp, "%.lf\t\n", res[i][j]);
				else fprintf(fp, "%.lf\t", res[i][j]);
			}
		}
		// fprintf(fp, "\n\n%lf\n", (MyClock() - clock) / CLOCKS_PER_SEC);
		fclose(fp);
		// printf("\n%s: %.6lf", nome, (MyClock() - inicio) / CLOCKS_PER_SEC);
	}
}

void *multMatrix(void *M){
	tMult *tmp = (tMult *) M;
	double **result = alocaMat(tmp->n);
	for(int i = 0; i < tmp->n; i++)
		for(int j = 0; j < tmp->n; j++)
			for (int k = 0; k < tmp->n; k++)
				result[i][j] += (tmp->A[i][k] * tmp->B[k][j]);

	printMat(result, tmp->nome, tmp->n);
	// printf("\n%.6lf", (MyClock() - inicio) / CLOCKS_PER_SEC);
}

double **retMultMatrix(double** mat1, double** mat2, int n){
	double **result = alocaMat(n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				result[i][j] += (mat1[i][k] * mat2[k][j]);

	return result;
}

void *expMatrix(void *M){
	tExp *tmp = (tExp *) M;
	double **res = alocaMat(tmp->tam);
	for (int i = 0; i < tmp->tam; i++)
		for (int j = 0; j < tmp->tam; j++)
			res[i][j] = tmp->A[i][j];
	
	for (int i = 0; i < tmp->n - 1; i++)
		res = retMultMatrix(tmp->A, res, tmp->tam);

	printMat(res, tmp->nome, tmp->tam);
	// printf("\n%.6lf", (MyClock() - inicio) / CLOCKS_PER_SEC);
}

FILE *carregaMat(char *nome){
	FILE *matriz = fopen(nome, "r");
	if (matriz == NULL) {
		fprintf(stderr, "Nao foi possivel abrir o arquivo da matriz %s\n", nome);
		exit(1);
	}
}

int main(int argc, char *argv[]) {
	
	inicio = MyClock();

	int tmp;
	if (argc != 4) {
		fprintf(stderr, "usage: prog <A> <B> n\n");
		exit(1);
	}

	n[0] = atoi(argv[3]);

	if(n[1] != n[2]){
		fprintf(stderr, "tam de A != tam de B");
		exit(1);
	}

	FILE *matrizA = carregaMat(argv[1]);
	tmp = fscanf(matrizA, "%d", &n[1]);
	double **A = lerMat(matrizA, n[1]);

	FILE *matrizB = carregaMat(argv[2]);
	tmp = fscanf(matrizB, "%d", &n[2]);
	double **B = lerMat(matrizB, n[2]);

	tMult *mult1 = (tMult *) criaMatMult(A, B, "AB.txt", n[1]);
	// printf("Deu\n");
	tMult *mult2 = (tMult *) criaMatMult(B, A, "BA.txt", n[2]);
	// printf("Merda\n");
	tMult *mult3 = (tMult *) criaMatExp(A, "An.txt", n[1], n[0]);
	// printf("Outra\n");
	tMult *mult4 = (tMult *) criaMatExp(B, "Bn.txt", n[2], n[0]);
	// printf("Vez\n");

	/* Calcule A*B */
	pthread_t thread_id1;
    pthread_create(&thread_id1, NULL, multMatrix, (void *) mult1);
	
	/* Calcule B*A */
	pthread_t thread_id2;
    pthread_create(&thread_id2, NULL, multMatrix, (void *) mult2);
	
	// /* Calcule A^n */
	pthread_t thread_id3;
    pthread_create(&thread_id3, NULL, expMatrix, (void *) mult3);

	// /* Calcule B^n */
	pthread_t thread_id4;
    pthread_create(&thread_id4, NULL, expMatrix, (void *) mult4);


    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
    pthread_join(thread_id4, NULL);

	printf("\nTotal: %.6lf", (MyClock() - inicio) / CLOCKS_PER_SEC);
	
	fclose(matrizA);
	fclose(matrizB);
	
	return 0;
}