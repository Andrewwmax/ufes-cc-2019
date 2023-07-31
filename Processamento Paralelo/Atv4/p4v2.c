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

void printMatS(double **res, int n){
	printf("%d\n", n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) { 
			if(j == n - 1) printf("%.lf\t\n", res[i][j]);
			else printf("%.lf\t", res[i][j]);
		}
	}
	printf("\n\n");
}

void printMatF(double **res, const char *nome, int n){
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

void marechalRandom(int tam){
	srand(time(NULL));
	printf("%d\n", tam);
	for (int v = 0; v < tam; ++v)
		for (int w = 0; w < tam; ++w)
			if(w == tam - 1) printf("%d\n", rand() % 10);
			else printf("%d ", rand() % 10);
}

int main(int argc, char *argv[]) {
	
	double **A, **B;
	int tmp;
	
	FILE *matrizA = carregaMat((char *) "A.txt");
	FILE *matrizB = carregaMat((char *) "B.txt");
	
	// n[0] = atoi((char *) "3");
	
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
	
	/* Calcule A*B */
	C = multMatrix(A, B, n[3]);
	printMatF(C, "A*B", n[3]);

	for (int i = 0; i < n[3]; ++i)
		for (int j = 0; j < n[3]; ++j)
			C[i][j] = 0;

	/* Calcule B*A */
	C = multMatrix(B, A, n[3]);
	printMatF(C, "B*A", n[3]);

	for (int i = 0; i < n[3]; ++i)
		for (int j = 0; j < n[3]; ++j)
			C[i][j] = 0;

	// C = multMatrix(A, A, n[3]);
	// C = multMatrix(C, A, n[3]);
	C = expMatrix(A, n[3], 2);
	printMatF(C, "A^n", n[3]);

	for (int i = 0; i < n[3]; ++i)
		for (int j = 0; j < n[3]; ++j)
			C[i][j] = 0;
	
	C = expMatrix(B, n[3], 2);
	printMatF(C, "B^n", n[3]);

	// marechalRandom(100);

		 
	fclose(matrizA);
	fclose(matrizB);

}