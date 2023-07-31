#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double MyClock() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000) + tv.tv_usec;
}

int somaElementos(int** mat, int N){
	int soma;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			soma += mat[j][i];

	return soma;
}

int somaElementos2(int** mat, int N){
	int soma;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			soma += mat[j][i];

	return soma;
}

int** multMatrix(int** mat1, int** mat2, int** result, int N){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				result[i][j] += (mat1[i][k] * mat2[k][j]);
}

int** multMatrixIJK(int** mat1, int** mat2, int** result, int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			register int soma = 0;
			for (int k = 0; k < N; k++){
				soma += (mat1[i][k] * mat2[k][j]);
			}
			result[i][j] = soma;
		}
	}
}

int** multMatrixJIK(int** mat1, int** mat2, int** result, int N){
	for(int j = 0; j < N; j++){
		for(int i = 0; i < N; i++){
			register int soma = 0;
			for (int k = 0; k < N; k++){
				soma += (mat1[i][k] * mat2[k][j]);
			}
			result[i][j] = soma;
		}
	}
}

int** multMatrixKIJ(int** mat1, int** mat2, int** result, int N){
	for (int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			register int a = mat1[i][k];
			for(int j = 0; j < N; j++){
				result[k][i] += (a * mat2[k][j]);
			}
		}
	}
}

int** multMatrixIKJ(int** mat1, int** mat2, int** result, int N){
	for(int i = 0; i < N; i++){
		for (int k = 0; k < N; k++){
			register int a = mat1[i][k];
			for(int j = 0; j < N; j++){
				result[k][i] += (a * mat2[k][j]);
			}
		}
	}
}

int** multMatrixJKI(int** mat1, int** mat2, int** result, int N){
	for(int j = 0; j < N; j++){
		for (int k = 0; k < N; k++){
			register int b = mat2[j][k];
			for(int i = 0; i < N; i++){
				result[k][i] += (mat1[k][j] * b);
			}
		}
	}
}

int** multMatrixKJI(int** mat1, int** mat2, int** result, int N){
	for (int k = 0; k < N; k++){
		for(int j = 0; j < N; j++){
			register int b = mat2[j][k];
			for(int i = 0; i < N; i++){
				result[k][i] += (mat1[k][j] * b);
			}
		}
	}
}

int** multMatrixTransIJK(int** mat1, int** mat2, int** matTrans, int** result, int N){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			matTrans[j][i] = mat2[i][j];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			register int soma = 0;
			for (int k = 0; k < N; k++){
				soma += (mat1[i][k] * matTrans[k][j]);
			}
			result[i][j] = soma;
		}
	}
}

void printSaida(int N, int iter){

	int** mat = (int **) calloc(N, sizeof(int *));
	int** mat2 = (int **) calloc(N, sizeof(int *));
	int** result = (int **) calloc(N, sizeof(int *));

	for (int i = 0; i < N; ++i){
		mat[i] = (int *) calloc(N, sizeof(int));
		mat2[i] = (int *) calloc(N, sizeof(int));
		result[i] = (int *) calloc(N, sizeof(int));
	}
	
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			mat[i][j] = i;
			mat2[j][i] = i;
			result[i][j] = 1;
		}
	}

	printf("[");
	for (int i = 0; i < iter; i++) {
		double inicio = MyClock();
		multMatrix(mat, mat2, result, N);
		if(i < iter - 1) printf("%.10lf, ", (MyClock() - inicio) / CLOCKS_PER_SEC);    
		else printf("%.10lf]\n\n", (MyClock() - inicio) / CLOCKS_PER_SEC);    
	}
}

int main(int argc, char *argv[]){
	if (argc != 2) {
		fprintf(stderr, "usage: prog <N>\n");
		exit(1);
	}

	int N = atoi(argv[1]);
	
	// int N = 10;

    int** mat = (int **) calloc(N, sizeof(int *));
    int** mat2 = (int **) calloc(N, sizeof(int *));
    int** matTrans = (int **) calloc(N, sizeof(int *));
    int** result = (int **) calloc(N, sizeof(int *));

    for (int i = 0; i < N; ++i){
        mat[i] = (int *) calloc(N, sizeof(int));
        mat2[i] = (int *) calloc(N, sizeof(int));
        matTrans[i] = (int *) calloc(N, sizeof(int));
        result[i] = (int *) calloc(N, sizeof(int));
    }
	
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            mat[i][j] = i;
            mat2[j][i] = i;
            result[i][j] = 1;
        }
    }

    double inicio = MyClock();
	// int soma = somaElementos(mat,N);
    // multMatrix(mat, mat2, result, N);

    // multMatrixIJK(mat, mat2, result, N);
    // multMatrixJIK(mat, mat2, result, N);
    
    // multMatrixKIJ(mat, mat2, result, N);
    // multMatrixIKJ(mat, mat2, result, N);
    
    // multMatrixJKI(mat, mat2, result, N);
    // multMatrixKJI(mat, mat2, result, N);

	multMatrixTransIJK(mat, mat2, matTrans, result, N);
	
	printf("%.10lf", (MyClock() - inicio) / CLOCKS_PER_SEC);
    
//    	multMatrix2(mat, mat2, result, N);
// 		for (int i = 0; i < N; ++i){
//      	for (int j = 0; j < N; ++j){

//        		printf("%d, ", result[i][j]);
//        	}
//        	printf("\n");
// 		}
// 		for (int i = 0; i < 5; i++) printSaida(10, 10);

	return 0;
}