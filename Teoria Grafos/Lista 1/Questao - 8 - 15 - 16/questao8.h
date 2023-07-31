#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//IMPLEMENTACAO DE ESTRUTURA DE GRAFOS

//Lista Encadeada que em que cada noh eh uma aresta
typedef struct vertice {        //Definicao vertice individual, como se fosse um noh
    int no;                     //Nome do vertice que a aresta liga
    int cst;					//Custo do arco
    int peso;                   //Peso da aresta
    struct vertice *prox;       //Ponteiro para proxima aresta
} Vertice;

//Estrutura para armazenar o vetor de listas encadeadas(grafo em si)
typedef struct grafo {
	int vertice;                //Numero de Vertices no Grafo
    int aresta;                 //Numero de Arestas no Grafo
    Vertice *adj;               //Vetor de Listas encadeadas
} Grafo;

Grafo *criaGrafo(int tam);
/*	
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

Vertice *novoVertice(int x);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void insereAresta(Grafo *graph, int vert1,int vert2,int deg);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void imprimeGrafo(Grafo *graph);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void imprimeGrafoTela(Grafo *graph);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

int pesoAresta(Grafo *graph,int v1,int v2);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void printVet(int *vetor,int n);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

Grafo *prim(Grafo* graph,int raiz);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void swapColMat(int **mat,int col1,int col2);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void printMat(int **matriz,int col);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void bubbleSort(int **matriz, int colunas);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

int buscaConjunto(int v,int *vetor);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void uniao(int v1,int v2,int *vetor);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

Grafo *kruskal(Grafo *graph);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

void imprimeGrafoArquivo(Grafo *graph);
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/

Grafo *lerGrafoArquivo();
/*
 *	Descricao:
 *	Entrada:
 *	Saida: 
*/