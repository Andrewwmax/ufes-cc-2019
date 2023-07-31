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

int NUMTHREADS = 4;

using namespace std;

typedef struct {
	int altura, largura, threshold;
	unsigned int ***pixel;
} Imagem;

unsigned int*** aloca(int n, int m);
Imagem *readPNM(const char *nomeArquivo);
void salvaPNM(Imagem *img, const char *nomeArquivo);
Imagem *removeRuidoMediana(Imagem *img);
void freeArray(unsigned int ***a, int h, int w);

int main(int argc, char *argv[]) {
	
	if (argc != 5) {
        fprintf(stderr, "usage: prog <in.ppm> <out.ppm> <n> <threads>\n");
        exit(1);
    }
	
	/*
	const char *in = "im/dead.ppm";
    const char *out = "out.ppm";
    const char *exec = "25";
    const char *th = "4";
    */
	  
	const char *in = argv[1];
    const char *out = argv[2];
    const char *exec = argv[3];
    const char *th = argv[4];
	
    
    int n = atoi(exec);
    NUMTHREADS = atoi(th);

	#ifdef _OPENMP
    omp_set_num_threads(NUMTHREADS);
    double start_time = omp_get_wtime();
	#endif

	Imagem *img = readPNM(in);

	for(int i = 0; i < n; i++)
		img = removeRuidoMediana(img);
    
	salvaPNM(img, out);

	#ifdef _OPENMP
	double end_time = omp_get_wtime();
	printf("%s\t%.5lf\n", in, end_time - start_time);
	#endif

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
	for (int i = imax - 1; i <= imax + 1; i++)
		for (int j = jmax - 1; j <= jmax + 1; j++)
				m[n++] = im[i][j][k];
	
	sort(m, m + mmax);
	return m[mmax / 2];
}

Imagem *removeRuidoMediana(Imagem *img){
	Imagem *imgDest = (Imagem *) calloc(1, sizeof(Imagem));
	imgDest->pixel = aloca(img->altura + 2, img->largura + 2);
	imgDest->altura = img->altura;
	imgDest->largura = img->largura;
	imgDest->threshold = img->threshold;


	#pragma omp parallel for num_threads(NUMTHREADS)
	for(int i = 2; i <= img->altura - 1; i++){
		for(int j = 2; j <= img->largura - 1; j++){
		    for(int k = 0; k < 3; k++){
		    	if(i > 1 && j > 1){
			    	imgDest->pixel[i][j][k] = calcMedia(img->pixel, i, j, k, 9);
		    	}
				if(i > 1){
			    	imgDest->pixel[i][1][k] = calcMedia(img->pixel, i, 1, k, 6);
			    	imgDest->pixel[i][img->largura][k] = calcMedia(img->pixel, i, img->largura, k, 6);
				} 
				if(j > 1){
			    	imgDest->pixel[1][j][k] = calcMedia(img->pixel, 1, j, k, 6);
			    	imgDest->pixel[img->altura][j][k] = calcMedia(img->pixel, img->altura, j, k, 6);
				}
				if(i == img->altura - 1 && j > img->largura - 1){
					imgDest->pixel[0][0][k] 					 = calcMedia(img->pixel, 1, 1, k, 4);	
					imgDest->pixel[0][img->largura][k] 			 = calcMedia(img->pixel, 1, img->largura, k, 4);
					imgDest->pixel[img->altura][0][k]			 = calcMedia(img->pixel, img->altura, 1, k, 4);
					imgDest->pixel[img->altura][img->largura][k] = calcMedia(img->pixel, img->altura, img->largura, k, 4);
				}
			}
		}
	}
	// Essa linha reduz o consumo de memoria, Muito interessante para PCs com pouca memoria, fica mais lento
	freeArray(img->pixel, img->altura, img->largura);
	return imgDest;
}

void freeArray(unsigned int ***a, int h, int w) {
    for (int i = 0; i < h; i++)
    	for (int j = 0; j < w; j++)
	        free(a[i][j]);

    for (int i = 0; i < h; i++)
	    free(a[i]);

	free(a);
}