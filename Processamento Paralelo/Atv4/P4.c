#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

int n[4];
//0 - n de entrada,
//1 - tam matA
//2 - tam matB
//3 - tam matC

double MyClock() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000) + tv.tv_usec;
}

double **alocaMat(int n){
	double **mat = (double **) calloc(n, sizeof(double *));
	for(int i = 0; i < n; i++)
		mat[i] = (double *) calloc(n, sizeof(double));
	return mat;
}

double** multMatrix(double** mat1, double** mat2, int N){
	double **result = alocaMat(N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				result[i][j] += (mat1[i][k] * mat2[k][j]);

	return result;
}

double **expMatrix(double **mat, int tam, int n){
	double **res = alocaMat(tam);
	for (int i = 0; i < tam; i++)
		for (int j = 0; j < tam; j++)
			res[i][j] = mat[i][j];
	
	for (int i = 0; i < n - 1; i++)
		res = multMatrix(mat, res, tam);

	return res;
}

void printMat(double **res, const char *nome, double clock, int n){
	FILE *fp = fopen(nome, "w");
	if (fp == NULL){
		puts("Erro Arquivo");
		exit(0);
	} else {
		fprintf(fp, "%d\n", n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) { 
				if(j == n - 1) fprintf(fp, "%.lf\t\n", res[i][j]);
				else fprintf(fp, "%.lf\t", res[i][j]);
			}
		}
		// fprintf(fp, "\n\n%lf\n", (MyClock() - clock) / CLOCKS_PER_SEC);
		// printf("%lf, ", (MyClock() - clock) / CLOCKS_PER_SEC);
		
		fclose(fp);
	}
}

FILE *carregaMat(char *nome){
	FILE *matriz = fopen(nome, "r");
	if (matriz == NULL) {
		fprintf(stderr, "Nao foi possivel abrir o arquivo da matriz %s\n", nome);
		exit(1);
	}
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

int main(int argc, char *argv[]) {
	

	double **A, **B;
	int tmp;
	if (argc != 4) {
		fprintf(stderr, "usage: prog <A> <B> n\n");
		exit(1);
	}

	FILE *matrizA = carregaMat(argv[1]);
	FILE *matrizB = carregaMat(argv[2]);
	
	n[0] = atoi(argv[3]);
	
	tmp = fscanf(matrizA, "%d", &n[1]);
	tmp = fscanf(matrizB, "%d", &n[2]);

	if(n[1] != n[2]){
		fprintf(stderr, "tam de A != tam de B");
		exit(1);
	}
	
	A = lerMat(matrizA, n[1]);
	B = lerMat(matrizB, n[2]);

	n[3] = n[1];

	double **C = alocaMat(n[3]);
	
	double inicio = MyClock();
	/* Calcule A*B */
	C = multMatrix(A, B, n[3]);
	printMat(C, "Res A*B", inicio, n[3]);

	for (int i = 0; i < n[3]; ++i)
		for (int j = 0; j < n[3]; ++j)
			C[i][j] = 0;

	/* Calcule B*A */
	C = multMatrix(B, A, n[3]);
	printMat(C, "Res B*A", inicio, n[3]);
	
	for (int i = 0; i < n[3]; ++i)
		for (int j = 0; j < n[3]; ++j)
			C[i][j] = 1;

	/* Calcule A^n */
	C = expMatrix(A, n[1], n[0]);
	printMat(C, "Res A^n", inicio, n[3]);
	
	for (int i = 0; i < n[3]; ++i)
		for (int j = 0; j < n[3]; ++j)
			C[i][j] = A[i][j];

	/* Calcule B^n */
	C = expMatrix(B, n[2], n[0]);
	printMat(C, "Res B^n", inicio, n[3]);
	 
	fclose(matrizA);
	fclose(matrizB); 

	printf("%.10lf\n\n", (MyClock() - inicio) / CLOCKS_PER_SEC);
	return 0;

}