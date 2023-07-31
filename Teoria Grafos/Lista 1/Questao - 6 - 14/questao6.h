#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include "Dijkstra.c"

// #include "quickedSort.c"

typedef struct grafo {
	int vertice;		// Vértice
	int aresta;			// Aresta
	int **adj; 			// Matriz Adjacente
} Grafo;

int **alocaMatrizAdj (int linhas, int colunas, int val);
/*
 *	Descricao:  Cria um vetor bi-dimensional, e cada linha 
 *				do vetor, entao recebe uma nova coluna, criando uma matriz 
 *				m[linhas][colunas] entao preenche-se a matriz com um valor 
 *				passado como paramentro.
 *	
 *	Estrutura:	Alocaca-se o vetor de linhas;
 *			 	Alocaca-se o vetor de colunas, dentro das posicoes do vetor de linhas;
 *				Preenche a matriz com o valor;
 *	
 *	Entrada: Inteiros com numero de Linhas, Colunas e valor para preencher a matriz.
 *	
 *	Saida: Uma matriz[linhas][colunas] alocada dinamicamente preenchida com o Valor de entrada.
*/

Grafo *criaGrafo (int V);
/*
 *	Descricao: 	Cria um grafo de grau V,
 *	Estrutura:	Alocaao do novo Grafo *;
 *				Preenchimento das informacoes do Grafo, com chamada da alocaMatrizAdj();
 *	Entrada: Inteiro com a quandidade de vertices.
 *	Saida: Um grafo com V vertices.
*/

void insereAresta (Grafo *graph, int v, int w);
/*
 *	Descricao: Insercao de aresta nao valorada, simples.
 *
 *	Estrutura: Condicao de nao existencia de aresta.
 *
 *	Entrada: Um Grafo *, Inteiro v e w, para vertices x,y da matriz de adjacencias.
 *
 *	Saida: Sem retorno.
*/

void removeAresta (Grafo *graph, int v, int w);
/*
 *	Descricao: Remocao de aresta valorada ou nao, simples.
 *
 *	Estrutura: Condicao de nao existencia de aresta.
 *
 *	Entrada: Um Grafo *, Inteiro v e w, para vertices x,y da matriz de adjacencias.
 *
 *	Saida: Sem Retorno
*/

void imprimeGrafo (Grafo *graph);
/*
 *	Descricao: Impressao de um Grafo simples, valorado ou nao.
 *
 *	Estrutura: 	Laco de repeticao para percorrer a matriz de adjacencias, 
 * 				imprimindo cada posicao existente.
 *				Impressao em tela da sequencia de arestas e seus valores.
 *
 *	Entrada: Um Grafo *.
 *
 *	Saida: Sem retorno
*/

void imprimeVetorGrafo(Grafo *graph);
/*
 *	Descricao: Impressao dos valores do Grafo como um Vetor
 *
 *	Estrutura: 	Laco de repeticao;
 *				Impressao em tela da sequencia de valores das arestas.
 *
 *	Entrada: Um Grafo *.
 *
 *	Saida: Sem Retorno.
*/

int isVerticeAdjacente(Grafo *graph, int x, int y);
/*
 *	Descricao: Verifica se 2 vertices sao adjacentes
 *
 *	Estrutura: Condicao de nao existencia da aresta.
 *
 *	Entrada: Um Grafo *, Inteiro x e y, para vertices da matriz de adjacencias.
 *
 *	Saida: Retorna 1 se forem adjacentes e 0 caso contrario.
*/

void getVerticesAdjacentes(Grafo *graph, int pos);
/*
 *	Descricao: Imprime todos os vertices adjacentes ao passado em 'pos'.
 *
 *	Estrutura: Laco de repeticao e condicional de existencia da aresta.
 *
 *	Entrada: Passado um Grafo * e Vertice pos.
 *
 *	Saida: Sem Retorno.
*/

int grauVerticeGrafo(Grafo *graph, int pos);
/*
 *	Descricao: Verificar o grau de um dado vertice.
 *
 *	Estrutura: Laco de repeticao e condicional de existencia de arestas adjacentes.
 *
 *	Entrada: Passado um Grafo * e Vertice pos.
 *
 *	Saida: Retorna o grau do vertice.
*/

void imprimeVetor(int *vetor, int tam);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void displayGrafo(int *vet, int tam);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

int vizinho(int *vet, int u, int v, int tam, int tamVet);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

int *transformV(Grafo *graph, int tam);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void imprimeGrafoArquivo(Grafo *graph);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

Grafo *lerGrafoArquivo();
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void insereArestaValorada(Grafo *graph, int v, int w, int valor);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

Grafo *preencheGrafoCompleto(int tam);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

Grafo *preencheGrafoRand(int V, int tam);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

int *criaDfsVet(int tam_vet);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void troca(int vet[], int pre[], int i, int j) ;
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

int particiona(int vet[], int vet2[], int inicio, int fim) ;
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

int particiona_random(int vet[], int vet2[], int inicio, int fim);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void quick_sort(int vet[], int vet2[], int inicio, int fim) ;
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void printVet(int vet[], int tam_vet, int tipo);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void fprintVet(int vet[], int tam_vet, int tipo) ;
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void SortDfs(int vet1[], int vet2[], int tam_vet);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void dfsR(Grafo *graph, int v, int pre[], int cnt0[], int pos[], int cnt1[], int pa[]) ;
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void dfs(Grafo *graph, int pre[], int cnt0[], int pos[], int cnt1[], int pa[]);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void controlDFS(Grafo *graph, int tam_vet);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

void dfsRcConexa(Grafo *graph, int *cc, int v, int id);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

int cConexa(Grafo *graph, int *cc);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

int dfsBipart(Grafo *graph, int v, int *color, int c);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/

int biparty(Grafo *graph, int *color);
/*
 *	Descricao: 
 *
 *	Estrutura:
 *
 *	Entrada:
 *
 *	Saida: 
*/