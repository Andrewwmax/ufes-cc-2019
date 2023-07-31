// Para compilar use o seguinte comando (no linux):
// g++ -O3 -fopenmp main.cpp -o removeRuido
// Para executar no cluster: qsub miniEP2.sh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <omp.h>

using namespace std;

typedef struct {
	int altura, largura, threshold;
	unsigned int ***pixel;
} Imagem;

unsigned int*** aloca(int n, int m);
Imagem *readPNM(const char *nomeArquivo);
void salvaPNM(Imagem *img, const char *nomeArquivo);
void removeRuidoMediana(const char *arquivoOrigem, const char *arquivoDestino);
int mediana(int v[], int n);

int main(int argc, char *argv[]) {

	if (argc != 4) {
        fprintf(stderr, "usage: prog <in.ppm> <out.ppm> <n>\n");
        exit(1);
    }

    int n = atoi(argv[3]);

    // double start_time = omp_get_wtime();
	removeRuidoMediana(argv[1], argv[2]);
	for(int i=2; i<=n; i++)
		removeRuidoMediana(argv[2], argv[2]);
	// double end_time = omp_get_wtime();
	// printf("%s\t%.5lf\n", argv[1], end_time - start_time);

	return 0;
}
// Aloca memoria para uma matriz de dimencoes (N x M x 3)
unsigned int*** aloca(int n, int m) {
    int i, j;
    unsigned int ***M;
    M = (unsigned int***) calloc(n, sizeof(unsigned int**));
    for(i = 0; i < n; i++){
        M[i] = (unsigned int**) calloc(m, sizeof(unsigned int*));
        for(j = 0; j < m; j++){
        	M[i][j] = (unsigned int*) calloc(3, sizeof(unsigned int)); 
        	// M[i][j][0] = 0; //Vermelho
        	// M[i][j][1] = 0; //Verde
        	// M[i][j][2] = 0; //Azul
        }
    }
    if (!M) {
		fprintf(stderr, "Erro na alocacao da memoria\n");
		exit(1);
	}

    return M;
}

Imagem *readPNM(const char *nomeArquivo) {
	char buff[16];
	Imagem *img;
	FILE *fp;
	int c;
    fp = fopen(nomeArquivo, "r");

    if (fp == NULL) {
        fprintf(stderr, "Nao foi possivel abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }
    if (!fgets(buff, sizeof(buff), fp)) {
		perror("stdin");
		exit(1);
	}

	if (buff[0] != 'P' || buff[1] != '3') {
		fprintf(stderr, "Formato da imagem invalido (deve ser 'P3')\n");
		exit(1);
	}

	img = (Imagem *) calloc(1, sizeof(Imagem));
	if (!img) {
		fprintf(stderr, "Erro na alocacao da memoria\n");
		exit(1);
	}

	c = getc(fp);
	while (c == '#') {
		while (getc(fp) != '\n')
			;
		c = getc(fp);
	}

	ungetc(c, fp);
	if (fscanf(fp, "%d %d", &img->largura, &img->altura) != 2) {
		fprintf(stderr, "Tamanho da imagem invalido\n");
		exit(1);
	}

	if (fscanf(fp, "%d", &img->threshold) != 1) {
		fprintf(stderr, "Componente rgb invalido\n");
		exit(1);
	}

	while (fgetc(fp) != '\n')
		;

	img->pixel = aloca(img->altura+2, img->largura+2);

	if (!img) {
		fprintf(stderr, "Erro na alocacao da memoria\n");
		exit(1);
	}
	int r, g, b;
	for(int i = 1; i <= img->altura; i++){
        for(int j = 1; j <= img->largura; j++){
            c = fscanf(fp, "%d %d %d", &r, &g, &b);
            img->pixel[i][j][0] = (unsigned int)r;
            img->pixel[i][j][1] = (unsigned int)g;
            img->pixel[i][j][2] = (unsigned int)b;
        }
    }
    fclose(fp);

	return img;
}

void salvaPNM(Imagem *img, const char *nomeArquivo){
	FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");
    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "#Processamento Paralelo\n");
    fprintf(arquivo, "%d %d %d\n", img->largura, img->altura, img->threshold);
    for(int i = 1; i <= img->altura; i++)
		for(int j = 1; j <= img->largura; j++) 
			for(int k = 0; k < 3; k++)
      			fprintf(arquivo, "%d\n", (int)img->pixel[i][j][k]);
    fclose(arquivo);
}

unsigned int calcMedia(unsigned int ***im, int imax, int jmax, int k, int mmax){
	int m[9], n = 0;
	// cout << imax << " : " << jmax << " : " << k << " : " << mmax;
	for (int i = imax - 1; i <= imax + 1; i++)
		for (int j = jmax - 1; j <= jmax + 1; j++){
			// for (int n = 0; n < mmax; n++){
				m[n++] = im[i][j][k];
				// cout <<  m[n];	
			}
	
	sort(m, m + mmax);
	return m[mmax / 2];
}

void removeRuidoMediana(const char *arquivoOrigem, const char *arquivoDestino){
	Imagem *img = readPNM(arquivoOrigem);
	int i, j, k;
	int m[9];

	unsigned int ***copia = aloca(img->altura + 2, img->largura + 2);
	for(i = 0; i <= img->altura; i++)
		for(j = 0; j <= img->largura; j++)
		    for (k = 0; k < 3; k++)
		    	copia[i][j][k] = img->pixel[i][j][k];

	/* Parte principal da imagem */
	for(i = 2; i <= img->altura - 1; i++){
		for(j = 2; j <= img->largura - 1; j++){
		    for (k = 0; k < 3; k++){
		    	// m[0] = copia[i-1][j-1][k];
		    	// m[1] = copia[i-1][j  ][k];
		    	// m[2] = copia[i-1][j+1][k];
		    	// m[3] = copia[i  ][j-1][k];
		    	// m[4] = copia[i  ][j  ][k];
		    	// m[5] = copia[i  ][j+1][k];
		    	// m[6] = copia[i+1][j-1][k];
		    	// m[7] = copia[i+1][j  ][k];
		    	// m[8] = copia[i+1][j+1][k];
		    	// img->pixel[i][j][k] = (unsigned int)mediana(m, 9);
	    // 		cout << "........." << m[0] << " " 
					// << m[1] << " "
					// << m[2] << " "
					// << m[3] << " "
					// << m[4] << " "
					// << m[5] << " "
					// << m[6] << " "
					// << m[7] << " "
					// << m[8] << " "
					// // << m[9] << " "
					// << ".........";  
				img->pixel[i][j][k] = calcMedia(copia, i, j, k, 9);
				// cout << " : " << img->pixel[i][j][k] << endl;
				// cout << i << " : " << j << " : " << k << " : " << 9 << " : " << img->pixel[i][j][k] << endl;
		    }
		}
	}

	/* Processa as quatro bordas */
	for(i=2;i<=img->altura-1;i++){
		j = 1;
		for (k=0; k<3; k++){
	    	// m[0] = copia[i-1][j  ][k];
	    	// m[1] = copia[i-1][j+1][k];
	    	// m[2] = copia[i  ][j  ][k];
	    	// m[3] = copia[i  ][j+1][k];
	    	// m[4] = copia[i+1][j  ][k];
	    	// m[5] = copia[i+1][j+1][k];
	    	// img->pixel[i][j][k] = (unsigned int)mediana(m, 6);
			img->pixel[i][j][k] = calcMedia(copia, i, j, k, 6);
	    }

		j = img->largura;
		for (k=0; k<3; k++){
	    	// m[0] = copia[i-1][j-1][k];
	    	// m[1] = copia[i-1][j  ][k];
	    	// m[2] = copia[i  ][j-1][k];
	    	// m[3] = copia[i  ][j  ][k];
	    	// m[4] = copia[i+1][j-1][k];
	    	// m[5] = copia[i+1][j  ][k];
	    	// img->pixel[i][j][k] = (unsigned int)mediana(m, 6);
			img->pixel[i][j][k] = calcMedia(copia, i, j, k, 6);
	    }
	}
	for(j=2;j<=img->largura-1;j++){
		i = 1;
		for (k=0; k<3; k++){
	    	// m[0] = copia[i  ][j-1][k];
	    	// m[1] = copia[i  ][j  ][k];
	    	// m[2] = copia[i  ][j+1][k];
	    	// m[3] = copia[i+1][j-1][k];
	    	// m[4] = copia[i+1][j  ][k];
	    	// m[5] = copia[i+1][j+1][k];
	    	// img->pixel[i][j][k] = (unsigned int)mediana(m, 6);
			img->pixel[i][j][k] = calcMedia(copia, i, j, k, 6);
	    }

		i = img->altura;
		for (k=0; k<3; k++){
	    	// m[0] = copia[i-1][j-1][k];
	    	// m[1] = copia[i-1][j  ][k];
	    	// m[2] = copia[i-1][j+1][k];
	    	// m[3] = copia[i  ][j-1][k];
	    	// m[4] = copia[i  ][j  ][k];
	    	// m[5] = copia[i  ][j+1][k];
	    	// img->pixel[i][j][k] = (unsigned int)mediana(m, 6);
			img->pixel[i][j][k] = calcMedia(copia, i, j, k, 6);
	    }
	}

	/* Processa os quatro cantos */
	for (k=0; k<3; k++){
		i = 0; j = 0;
		// m[0] = copia[i  ][j][k];
		// m[1] = copia[i  ][j+1][k];
		// m[2] = copia[i+1][j  ][k];
		// m[3] = copia[i+1][j+1][k];
		// img->pixel[i][j][k] = (unsigned int)mediana(m, 4);
		img->pixel[i][j][k] = calcMedia(copia, i + 1, j + 1, k, 4);

		i = 0; j = img->largura;
		// m[0] = copia[i  ][j][k];
		// m[1] = copia[i  ][j-1][k];
		// m[2] = copia[i+1][j-1][k];
		// m[3] = copia[i+1][j  ][k];
		// img->pixel[i][j][k] = (unsigned int)mediana(m, 4);
		img->pixel[i][j][k] = calcMedia(copia, i + 1, j, k, 4);

		i = img->altura; j = 0;
		// m[0] = copia[i  ][j][k];
		// m[1] = copia[i-1][j  ][k];
		// m[2] = copia[i-1][j+1][k];
		// m[3] = copia[i  ][j+1][k];
		// img->pixel[i][j][k] = (unsigned int)mediana(m, 4);
		img->pixel[i][j][k] = calcMedia(copia, i, j + 1, k, 4);

		i = img->altura; j = img->largura;
		// m[0] = copia[i  ][j][k];
		// m[1] = copia[i-1][j-1][k];
		// m[2] = copia[i-1][j  ][k];
		// m[3] = copia[i  ][j-1][k];
		// img->pixel[i][j][k] = (unsigned int)mediana(m, 4);
		img->pixel[i][j][k] = calcMedia(copia, i, j, k, 4);
	}
	salvaPNM(img, arquivoDestino);
}

int mediana(int v[], int n){
	sort(v, v+n);
	return v[n/2];
}
