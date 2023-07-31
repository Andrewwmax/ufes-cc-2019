#include "questao8.h"

Grafo *criaGrafo(int tam){
	Grafo *novo = (Grafo*) malloc(tam * sizeof(Grafo));
	if(!novo) printf("Erro alocacao grafo.\n");

	novo->vertice = tam;
	novo->aresta = 0;
	novo->adj = (Vertice*) calloc(tam, sizeof(Vertice));
	if(!novo->adj) printf("Erro alocacao Vetor.\n");
	
	return novo;
}

Vertice *novoVertice(int x){
	Vertice *novo = (Vertice*) malloc(sizeof(Vertice));                                                    
	novo->no = x;
	novo->cst = 0;
	novo->peso = 0;
	novo->prox = NULL;
	return novo;
}

void insereArestaDigrafo(Grafo *graph, int vert1, int vert2, int deg){
	if(vert1 != vert2){
		Vertice *temp = &graph->adj[vert1];
		
		while(temp != NULL){
			if(temp->no == vert2) break;
			temp = temp->prox;
		}
		if(temp == NULL){ 
			Vertice *novo = novoVertice(vert2);
			novo->prox = graph->adj[vert1].prox;
			graph->adj[vert1].prox = novo;
			novo->peso = deg;
			novo->cst = deg;
			graph->aresta++;
		}
	}
}

void insereArestaGrafo(Grafo *graph, int vert1, int vert2, int deg){a
	if(vert1 != vert2){
		Vertice *temp = &graph->adj[vert1];
		
		while(temp != NULL){
			if(temp->no == vert2) break;
			
			temp = temp->prox;
		}
		if(temp == NULL){ 
			Vertice *novo = novoVertice(vert2);
			novo->prox = graph->adj[vert1].prox;
			graph->adj[vert1].prox = novo;
			novo->peso = deg;
			graph->aresta++;
		}
		temp = graph->adj[vert2].prox;
		
		while(temp != NULL){
			if(temp->no == vert1) break;

			temp = temp->prox;                                                                        
		}

		if(temp == NULL){
			Vertice *novo = novoVertice(vert1);
			novo->prox = graph->adj[vert2].prox;
			graph->adj[vert2].prox = novo;
			novo->peso = deg;
		}
	}
}

void remocaoArestaDigrafo(Grafo *graph, int v, int w){
	if(graph->adj[v].prox != NULL){
		Vertice *aux = graph->adj[v].prox;
		Vertice *preaux = &(graph->adj[v]);
		while(aux != NULL){
			if(aux->no == w) break;

			preaux = aux;
			aux = aux->prox;
		}
		if(!aux){
			graph->aresta--;
			preaux->prox = aux->prox;
			free(aux);
		}
	}
}

void remocaoArestaGrafo(Grafo *graph, int v, int w){
	if(graph->adj[v].prox != NULL){
		Vertice *aux = graph->adj[v].prox;
		Vertice *preaux = &(graph->adj[v]);
		while(aux != NULL){
			if(aux->no == w) break;

			preaux = aux;
			aux = aux->prox;
		}
		if(!aux){
			graph->aresta--;
			preaux->prox = aux->prox;
			free(aux);
		}
	}

	if(graph->adj[w].prox != NULL){
		Vertice *aux = graph->adj[w].prox;
		Vertice *preaux = &(graph->adj[w]);
		while(aux != NULL){
			if(aux->no == v) break;

			preaux = aux;
			aux = aux->prox;
		}
		if(aux != NULL){
			//printf("Removeu %d, %d\n", v, w);
			preaux->prox = aux->prox;
			free(aux);
		}
	}
}

void imprimeGrafo(Grafo *graph){
	Vertice *temp = &(graph->adj[0]);
	
	printf("Estrutura do Grafo:\n");
	for(int i = 0; i < graph->vertice; i++){
		temp = (graph->adj[i].prox);
		
		printf("%d: ", i);
		while(temp != NULL){
			printf("%d | %d ", temp->no, temp->peso);
			if(temp->prox != NULL) printf("\n-> ");

			temp = temp->prox;
		}
		printf("\n");
	}
}

void imprimeGrafoTela(Grafo *graph){
	Vertice *aux = graph->adj;
	
	printf("Grafo:\n");
	for(int i = 0; i < graph->vertice; i++){
		aux = (graph->adj[i].prox);
		
		//printf("%d: ", i);
		while(aux != NULL){
			//printf("%d -- %d", aux->no, aux->peso);
			printf("%d: %d -- %d\n", i, aux->no, aux->peso);
			// if(aux->prox != NULL){
			//     printf("\n%d: %d -- %d", i, aux->no, aux->peso);
			// }
			aux = aux->prox;
		}
		//printf("\n");
	}
}

//////////////////////////////////////////////////
///   IMPLEMENTACAO DE FUNCOES PARA PRIM      ////
//////////////////////////////////////////////////

int pesoAresta(Grafo *graph, int v1, int v2){
	Vertice *aux = graph->adj[v1].prox;
	int resp = (int) INFINITY;
	if(v1 == v2) return -1;
	while(aux != NULL){
		if(aux->no == v2){
			resp = aux->peso;
			break;
		} else aux = aux->prox;
	}
	return resp;
}

void printVet(int *vetor, int n){
	for(int i = 0; i < n; i++) printf("%d ,",vetor[i]);
	printf("\n");
}

Grafo *prim(Grafo* graph, int raiz){
	//Dado um grafo e um valor correspondente a um vertice gera e retorna um outro grafo que contem a Arvore Geradora Minima do grafo original

	//Obs:Previa de funcionamento
	//1.Trata Caso Inicial: Analisa e escreve nos dois vetores distancia de todos os vertices em referencia a raiz
	//      OBS:A distancia vai ser definida como infinito caso nao seja adjacente
	//2.Busca o vertice mais proximo a MST e faz a insercao na MST
	//3.Faz a insercao do Vertice mais proximo da MST a arvore(Esse vertice recebe nome de ATUAL)
	//4.Atualiza a distancia do vertice que acaba de ser inserido no vetor de distancia como -1 para evitar insercao dupla
	//5.Atualiza a distancia de todos os vertices adjacentes ao ATUAL caso a distancia seja menor ao que ja era e atualiza o vertMProx como o ATUAL
	//6.Caso a MST nao estaja completa ainda,volta para o passo 2
	//7.Caso a MST esteja completa, retorne ela.
	//Definicao de raiz
	Grafo *mst = criaGrafo(graph->vertice);                        //Local onde vou armazenar minha arvore geradora minima
	int *vertMProx = (int*) calloc((graph->vertice), sizeof(int)); //Armazena na posicao i o noh mais proximo ao vertice referente a i
	int *distancia = (int*) calloc((graph->vertice), sizeof(int)); //Vetor que mantem na posicao i a distancia do vertice mais proximo referente ao vertice i
	int atual;                                                  //Uso para armazenar o vertice mais proximo a mst que ainda nao esta incluido em mst
	int distAtual;                                              //Armazeno o peso do atual referente ao noh mais proximo de atual pertencente a mst
	Vertice *aux;                                               //Vertice Auxiliar para percorrer todos os vertices adjacentes a atual
	
	//Inicia os dois vetores todos referantes a distancia a raiz ja que a raiz eh o unico vertice em mst(teoricamente)
	for(int i = 0; i < graph->vertice; i++){
		distancia[i] = pesoAresta(graph, raiz, i);
		vertMProx[i] = raiz;
	}
		
	//Enquanto o numero de arestas na arvore for menor que o numero de vertices-1 no grafo original
	//Ou seja, enquanto nao completar a arvore
	while((graph->vertice - 1) > ((mst->aresta))){
		
		//Encontra o noh mais proximo a arvore mst e armazena ele em atual, e sua distancia em relacao a arvore mst no vetor distancia
		
		//Proceso de busca pelo vertice adjacente a arvore com menor distancia
		for(int i = 0; i < graph->vertice; i++){
			//Caso inicial em que nao utilizou nenhum noh
			distAtual = (int) INFINITY;
			
			//Para todo vertice pertencente ao grafo
			for(int j = 0; j < graph->vertice; j++){
				//Se a distancia do vertice dessa iteracao for menor que a do ultimo entao reescrever o menor vertice
				//O -1 serve para nao fazer comparacao com vertice que ja existem na mst
				if(distancia[j] < distAtual && distancia[j] != -1){
				   atual = j;                 //Armazena o vertice com menor peso adjacente a mst
				   distAtual = distancia[j];  //Armazena o peso do vertice
				}
			}
		}

		//Encontramos o noh mais proximo a mst, armazenamos o seu valor em atual, agora basta fazer a insercao
		insereArestaGrafo(mst, vertMProx[atual], atual, distancia[atual]);      //Faz a insercao do vertice mais proximo
		distancia[atual] = -1;                                            //Indica que ja esta na arvore

		//Agora atualizamos os valores do vetor distancia considerando o novo noh
		aux = graph->adj[atual].prox;         //Utilizado para percorrer todos os vertices adjacentes(VA) ao que acaba de ser inserido na mst
		while(aux != NULL){                   //Enquanto nao explorar todos os vertices adjacentes ao atual            
			//Caso a distancia do VA seja mais proximo do que acaba de ser inserido em comparacao ao que era
			//E caso ele o VA ja nao tenha sido inserido na mst(!=-1)
			if(distancia[aux->no] < INFINITY && pesoAresta(graph, atual, aux->no) < distancia[aux->no] && distancia[aux->no] != -1){
				//Atualiza o valor da distancia
				distancia[aux->no] = pesoAresta(graph,atual,aux->no);
				vertMProx[aux->no] = atual;
			}
			aux = aux->prox;
		}		
	}
	free(vertMProx);
	free(distancia);
	return mst;
}

//////////////////////////////////////////////////
///   IMPLEMENTACAO DE FUNCOES PARA KRUSKAL   ////
//////////////////////////////////////////////////

void printMat(int **matriz, int col){
	//Utilizado para imprimir a matriz
	for(int i = 0; i < 3; i++) {
		printf("\n");
		for(int j = 0; j < col; j++) 
			printf("%d ,", matriz[i][j]);
	}
	printf("\n");
}

void swapColMat(int **mat, int col1, int col2){
	//Troca o conteudo de duas colunas de posicao
	int aux;
	for(int i = 0; i < 3; i++){
		aux = mat[i][col1];
		mat[i][col1] = mat[i][col2];
		mat[i][col2] = aux;
	}
}

void bubbleSort(int **matriz, int colunas){
	//Faz ordenacao da matriz por ordem de peso entre as arestas
	//Ordenacao de Vetor
	for(int i = 0; i < colunas; i++){
		for(int j = 0; j < colunas - i - 1; j++){
			if(matriz[2][j] > matriz[2][j + 1]){
				swapColMat(matriz, j, j + 1);
			}
		}
	}
}

int buscaConjunto(int v, int *vetor){
	int i = v;
	while(vetor[i] >= 0){
		i = vetor[i];
	}
	return i;
}

void uniao(int v1, int v2, int *vetor){
	//Obs:Valores nulos na matriz sao defininidos como -2
	if(vetor[v2] == -2){        //Caso V2 nao foi iniciado ainda
		vetor[v2] = v1;
		if(vetor[v1] == -2) vetor[v1] = -1;
	} else if(vetor[v1] == -2){ //Caso V1 nao foi iniciado ainda 
		vetor[v1] = v2;
		if(vetor[v2] == -2) vetor[v2] = -1;
	} else {                    //Caso que os dois ja foram iniciados
		vetor[v2] = v1;
		if(vetor[v1] == -2) vetor[v1] = -1;
	}
}

Grafo *kruskal(Grafo *graph){
	//Criacao de um Vetor[3][2*Arestas] que vai armazenar todos conjuntos de arestas e o peso
	//Notamos que todas arestas vao ser repitida devido ao jeito que lemos o Grafo
	//Vetor[0][A]: Vertice X da Aresta A
	//Vetor[1][A]: Vertice Y da Aresta A
	//Vetor[2][A]: Peso da Aresta que liga X e Y
	
	//Alocacao de Matriz
	int **matrizOrdenada = (int**) malloc(3 * sizeof(int));
	for(int i = 0; i < 3; i++)
		matrizOrdenada[i] = (int *) malloc (2 * (graph->aresta) * sizeof(int));
	//Leitura do Grafo e escrevendo os conjuntos de Arestas na matriz
	Vertice *aux = graph->adj[0].prox;
	int contV = 0; 
	int contA = 0;
	
	while(contA < 2 * (graph->aresta)){
		if(aux != NULL){
			matrizOrdenada[0][contA] = contV;
			matrizOrdenada[1][contA] = aux->no;
			matrizOrdenada[2][contA] = aux->peso;
			aux = aux->prox;
			contA++;
		} else {
			contV++;
			aux = graph->adj[contV].prox;
		}
	}
	//Ordenando a matriz por peso de aresta usando bubbleSort
	bubbleSort(matrizOrdenada, 2 * (graph->aresta));
	
	//Trabalhando com O Conjunt de Arestas(Vetor de "Arvore")
	int *vetorUniao = (int*) malloc((graph->vertice) * sizeof(int));   //Vetor utilizado para representar Uniao
	Grafo *mst = criaGrafo(graph->vertice);                              //Grafo onde sera armazenado a Arvore Minima Geradora do Grafo
	
	//Iniciando vetor com -2 pois vou ter que enderacar o Vertice 0
	for(int i = 0; i < graph->vertice; i++) vetorUniao[i] = -2;
	
	//Contador usado para armazenar quantas arestas existem na arvore
	int contador = 0;
	
	//Proce de Insercao
	for(int i = 0; i < 2 * (graph->aresta); i++){
		//Analisando agora v1 e v2
		if(contador == graph->vertice) break;    //Se o contador igualar o numero de Vertices para
		
		//Se o V1 nao pertencer ao mesmo conjunto que V2 ou entao se a busca for igual o conjunto nulo(-2) para os dois
		if((buscaConjunto(matrizOrdenada[0][i], vetorUniao)) != (buscaConjunto(matrizOrdenada[1][i], vetorUniao)) || (buscaConjunto(matrizOrdenada[1][i], vetorUniao) == -2 && buscaConjunto(matrizOrdenada[0][i], vetorUniao) == -2)){
			//Ocorre a insercao
			insereArestaGrafo(mst, matrizOrdenada[0][i], matrizOrdenada[1][i], matrizOrdenada[2][i]); 
			uniao(matrizOrdenada[0][i], matrizOrdenada[1][i], vetorUniao);
			contador++;
		}
	}
	free(matrizOrdenada);
	free(vetorUniao);
	return mst;
}

///////////////////////////////////////////////////////////
///						AUXILIARES 						///
///////////////////////////////////////////////////////////
void imprimeGrafoArquivo(Grafo *graph){
	Vertice *aux = &(graph->adj[0]);
	FILE *fp = fopen("OUT.DOT", "w");
	if (fp == NULL){
		puts("Erro Arquivo");
		exit(0);
	} else {

		fprintf(fp, "/*%d %d*/\n", graph->vertice, graph->aresta*2);
		fprintf(fp, "graph G{\n");
		fprintf(fp, "size=\"7.5\";\n");
		fprintf(fp, "ratio=fill;\n");
		fprintf(fp, "node[shape=circle];\n");

		for(int i = 0; i < graph->vertice; i++){
			aux = (graph->adj[i].prox);
	  
			while(aux != NULL){
				fprintf(fp, "%d -- %d [label= \"%d\"];\n", i, aux->no, aux->peso);
				remocaoArestaGrafo(graph, i, aux->no);
				// if(aux->prox != NULL){
				//     aux = aux->prox;
				//     fprintf(fp, "%d -- %d [label= \"%d\"];\n", i, aux->no, aux->peso);
				//     remocaoArestaGrafo(graph, i, aux->no);
				// }
				aux = aux->prox;
			}
		}
		fprintf(fp, "}");
	}
	fclose(fp);
}

void imprimeDigrafoArquivo(Grafo *graph){
	Vertice *aux = &(graph->adj[0]);
	FILE *fp = fopen("OUT.DOT", "w");
	if (fp == NULL){
		puts("Erro Arquivo");
		exit(0);
	} else {

		fprintf(fp, "/*%d %d*/\n", graph->vertice, graph->aresta);
		fprintf(fp, "digraph G{\n");
		fprintf(fp, "size=\"7.5\";\n");
		fprintf(fp, "ratio=fill;\n");
		fprintf(fp, "node[shape=circle];\n");

		for(int i = 0; i < graph->vertice; i++){
			aux = (graph->adj[i].prox);
	  
			while(aux != NULL){
				fprintf(fp, "%d -> %d [label= \"%d\"];\n", i, aux->no, aux->peso);
				//remocaoArestaGrafo(graph, i, aux->no);
				// if(aux->prox != NULL){
				//     aux = aux->prox;
				//     fprintf(fp, "%d -- %d [label= \"%d\"];\n", i, aux->no, aux->peso);
				//     remocaoArestaGrafo(graph, i, aux->no);
				// }
				aux = aux->prox;
			}
		}
		fprintf(fp, "}");
	}
	fclose(fp);
}

Grafo *lerGrafoArquivo(int type){
	// type == true leh grafo, type == 0 leh digrafo;
	int vertices, arestas, aOrigem, aDestino, aPeso;
	FILE *arq;
	Grafo *test;
	if(type){

		//printf("TG - UFES\n");
		//printf("## Leitura ##\n");

		arq = fopen("IN.DOT", "rt");
		fscanf(arq, "%*c%*c%d%*c%d", &vertices, &arestas);
		//qtdLinhas - 4
		//printf("%d\t%d\n", vertices, arestas);

		test = criaGrafo(vertices);
		if(!test) printf("Erro alocacao.\n");

		fscanf(arq, "%*s %*s");
		fscanf(arq, "%*s %*s");
		fscanf(arq, "%*s %*s");
		fscanf(arq, "%*c%*c");

		for(int i = 0; i < arestas; i++){
			fscanf(arq, "%d %*c%*c %d %*s %*c%d%*s", &aOrigem, &aDestino, &aPeso);
			//printf("%d\t%d\t%d\n", aOrigem, aDestino, aPeso);
			insereArestaGrafo(test, aOrigem, aDestino, aPeso);
		}
	} else {

		arq = fopen("IN.DOT", "rt");
		fscanf(arq, "%*c%*c%d%*c%d", &vertices, &arestas);
		
		test = criaGrafo(vertices);
		if(!test) printf("Erro alocacao.\n");

		fscanf(arq, "%*s %*s");
		fscanf(arq, "%*s %*s");
		fscanf(arq, "%*s %*s");
		fscanf(arq, "%*c%*c");

		for(int i = 0; i < arestas; i++){
			fscanf(arq, "%d %*c%*c %d %*s %*c%d%*s", &aOrigem, &aDestino, &aPeso);
			insereArestaDigrafo(test, aOrigem, aDestino, aPeso);
		}
	}
	return test;    
}


///////////////////////////////////////////////////////////
///						BIPARTIDO 						///
///////////////////////////////////////////////////////////
bool dfsRBipart(Grafo *graph, int v, int *color, int c){ 
	// printf("dfsBipart\n");
	color[v] = c;
	Vertice *aux = &(graph->adj[v]);
	while(aux->prox != NULL){
	// for (Vertice *a = &(graph->adj[v]); a != NULL; a = a->prox) {
		int w = aux->prox->no;
		// printf("for 1 - %d\n", aux->prox->no);
		if (color[w] == -1) {
			// printf("if 1\n");
			if (dfsRBipart(graph, w, color, 1 - c) == 0) {
				// printf("if 2\n");
				return 0;
			}
		} else { //v-w é arco de retorno
			// printf("else 1\n");
			if (color[w] == c){ 
				// printf("if 3\n");
				return 0;	//base da recursão
			}
		}
	// }
	aux = aux->prox;
	}
	return true;
}

bool biparty(Grafo *graph, int *color){
	//printf("biparty\n");
	for (int v = 0; v < graph->vertice; ++v) {
		// printf("for -1\n");
		color[v] = -1; //incolor
	}
	for (int v = 0; v < graph->vertice; ++v){ 
		//printf("for 2\n");
		if (color[v] == -1){ // começa nova etapa
			// printf("if -1\n");
			if (dfsRBipart(graph, v, color, 0) == 0){
				// printf("if 0 -- %d\n", v);
				return 0;
			}
		}
	}
	return true;
}


///////////////////////////////////////////////////////////
///						PONTE   						///
///////////////////////////////////////////////////////////
int *pre, *low;
int *stack, *pa;
int N, k, cnt;

void rPonte(Grafo *graph, int v, int *sc){ 
	pre[v] = cnt++;
	int min = pre[v]; 
	stack[N++] = v;

	Vertice *aux = &(graph->adj[v]);
	while(aux != NULL){
		int w = aux->no;
		if (pre[w] == -1) {
			rPonte(graph, w, sc);
			if (low[w] < min){ 
			min = low[w];
			} 							//A
		} else if (pre[w] < pre[v] && sc[w] == -1) {
			if (pre[w] < min) {
				min = pre[w];
			} 							//B
		}
		aux = aux->prox;
	}

	low[v] = min;
	if (low[v] == pre[v]) {             //C
		int u;
		do {
			u = stack[--N];
			sc[u] = k;
		} while (u != v);
		k++;
	}
}

int isPonte(Grafo *graph, int *sc){

	pre = (int *) malloc(graph->vertice * sizeof (int));
	low = (int *) malloc(graph->vertice * sizeof (int));
	stack = (int *) malloc(graph->vertice * sizeof (int));
	
	for (int v = 1; v < graph->vertice; ++v) 
		pre[v] = sc[v] = -1;

	k = N = cnt = 0;

	for (int v = 0; v < graph->vertice; ++v){ 
		if (pre[v] == -1){
			rPonte(graph, v, sc);
		}
	}
	free( pre); free( low); free( stack);
	return k;
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
void MST(Grafo *test, int e){
	
	if(e == 1){ 
		printf("PRIM\n");
		Grafo *mst = prim(test, 0);
		imprimeGrafoTela(mst);
		imprimeGrafoArquivo(mst);
	} else {
		printf("KRUSKAL\n");
		Grafo *mst2 = kruskal(test);
		imprimeGrafoTela(mst2);
		imprimeGrafoArquivo(mst2);
	}
}

int main() {
	Grafo *tst = lerGrafoArquivo(1);
	// imprimeGrafoTela(tst);

	//PARA TESTAR KRUSKAL
	// printf("KRUSKAL\n");
	// tst = kruskal(tst);
	// imprimeGrafoTela(tst);

	//PARA TESTAR PRIM
	printf("PRIM\n");
	tst = prim(tst, 0);
	imprimeGrafoTela(tst);

	//PARA TESTAR PONTES
	// int *vet = (int *) calloc(tst->vertice, sizeof(int));
	// int p = isPonte(tst, vet);
	// printf("O Grafo contem %d Ponte(s)\n\n", p/2);

	// //PARA TESTAR BIPARTIDO
	// int *color = (int *) calloc(tst->vertice, sizeof(int));
	// for (int i = 0; i < tst->vertice; i++) printf("%d\t", color[i]);
	// tst = lerGrafoArquivo(1);
	// bool bip = biparty(tst, color);
	// if(bip) printf("\nO Grafo eh bipartido\n");
	// else printf("\nO Grafo nao eh bipartido\n");

	imprimeGrafoArquivo(tst);

	// test(tst, 1);
	return 0;
}
