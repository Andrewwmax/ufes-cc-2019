/*
 * Good Bless the Code
 *
 * Author: André Thiago Borghi Couto
 * Criado em 04 de Setembro de 2018, 22:05
*/

#include "questao6.h" 	

int **alocaMatrizAdj (int linhas, int colunas, int val){
		
	int **novo = (int **)malloc(linhas * sizeof(int *));
	if(!novo) printf("Erro Alocacao 1o\n");
	
	for (int i = 0; i < linhas; i++) 
		novo[i] = (int *) malloc (colunas * sizeof(int));
	
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++) novo[i][j] = val;
	}

	return novo;
}

Grafo *criaGrafo (int V){
	Grafo *novo = (Grafo *) malloc(sizeof(Grafo));
    	   novo->vertice = V;
		   novo->aresta = 0; 
		   novo->adj = alocaMatrizAdj(V, V, 0);
	return novo;
}

void insereAresta (Grafo *graph, int v, int w){
	if (v != w && graph->adj[v][w] == 0){
		graph->adj[v][w] = 1;
		graph->adj[w][v] = 1;
		graph->aresta++;
	}
}

void removeAresta (Grafo *graph, int v, int w){
	if (graph->adj[v][w] == 1){
		graph->aresta--;
		graph->adj[v][w] = 0;
		graph->adj[w][v] = 0;
	}
}

void imprimeGrafo (Grafo *graph){
	int v, w;
	for (v = 0; v < graph->vertice; v++){
		for (w = 0; w < graph->vertice; w++) {
			if(w <= v)
				if (graph->adj[v][w] > 0) 
					printf("[%d - %d] = %d\n", v, w, graph->adj[v][w]);
		}
	}
}

void imprimeVetorGrafo(Grafo *graph){
	for(int i = 0; i < graph->vertice; i++){
		for(int j = 0; j < graph->vertice; j++){
			printf("%2d ", graph->adj[i][j]);
		}
		printf("\n");
	}
}

int isVerticeAdjacente(Grafo *graph, int x, int y){
	if((graph->adj[x][y]) != 0 || (graph->adj[y][x]) != 0)
		return 1;
	else return 0;
}

void getVerticesAdjacentes(Grafo *graph, int pos){
	printf("Vertices Adjacentes a %d: \n", pos);
	for(int i = 0; i < graph->vertice; i++){
		if((graph->adj[i][pos]) != 0){
			printf("%d, ", i);
		}
	}
	printf("\n");
}

int grauVerticeGrafo(Grafo *graph, int pos){
	int grau = 0;
	
	for(int i = 0; i < graph->vertice; i++){
		if((graph->adj[pos][i]) != 0)
			grau++;
	}
	
	return grau;
}

void imprimeVetor(int *vetor, int tam){
	for(int i = 0; i < tam; i++) 
		if(i + 1 == tam) printf("%d.", vetor[i]);
		else printf("%d, ", vetor[i]);
	
	printf("\n");
}

void displayGrafo(int *vet, int tam){
	int cont = tam;
	int max = tam;
	
	printf("Grafo:\n");
	int tamvet = sizeof(vet) / sizeof(int*);

	for(int i = 0; i < max - 1; i++){ //Vertices
		printf("%d:", i);
		
		for(int j = cont - tam; j < (cont - 1); j++){
			if(vet[j - i] != 0) printf("%d ", max -(cont - j) + 1);
			
			if(j < cont - 2) printf("->");
		}
		printf("\n");
		tam--;
		cont += tam;
	}
}

int vizinho(int *vet, int u, int v, int tam, int tamVet){
	
	int Orig = tam - 1;
	int Aux = Orig;
	int Max = 0;
	int cont = 0;
	int tot = 0;
	int i = 0;
	while(i < tamVet){
		
		if(Aux <= 0){
			Orig--;
			Aux = Orig;
			Max = i - 1;
			cont++;
			tot++;
		}

		if(cont == u){
			if(u == 0) return vet[(Max + v - tot - 1)];
			else return vet[(Max + (v - u))];
		}
		
		Aux--;
		i++;
	}
	return 0;
}

int *transformV(Grafo *graph, int tam){
	int tamVet = 0;
	for(int i = tam - 1; i > 0; i--) tamVet += i;
	
	printf("Tamanho do Vetor: %d\n", tamVet);
	int *vet = (int*) calloc(tamVet, sizeof(int));
	
	int Orig = tam - 1;
	int Aux = Orig;
	int Max = -1;
	int tot = 0;
	for(int u = 0; u <= tam; u++){
		for(int v = u + 1; v < tam; v++){
			vet[tot] = graph->adj[u][v];
			Aux--;
			tot++;
		}    
	}
	//f(u, v) = pos(max(u − 1)) + v − u
	//displayGrafo(vet, tamVet);
	imprimeVetor(vet, tamVet);
	return vet;
}

void imprimeGrafoArquivo(Grafo *graph){
	FILE *fp = fopen("OUT.DOT", "w");
    if (fp == NULL){
    	puts("Erro Arquivo");
        exit(0);
    } else {

	    fprintf(fp, "/*%d %d*/\n", graph->vertice, graph->aresta);
		fprintf(fp, "graph G{\n");
		fprintf(fp, "size=\"7.5\";\n");
		fprintf(fp, "ratio=fill;\n");
		fprintf(fp, "node[shape=circle];\n");

		for (int v = 0; v < graph->vertice; v++){
			for (int w = 0; w < graph->vertice; w++) {
				if (w <= v && graph->adj[v][w] > 0) 
					fprintf(fp, "%d -- %d [label= \"%d\"];\n", v, w, graph->adj[v][w]);
			}
		}
		fprintf(fp, "}");
		fclose(fp);
	}
}

Grafo *lerGrafoArquivo(){
	int vertices, arestas, aOrigem, aDestino, aPeso;
	FILE *arq;
	Grafo *test;

	// printf("TG - UFES\n");
	// printf("## Leitura ##\n");

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
		insereArestaValorada(test, aOrigem, aDestino, aPeso);
	}
	//printf("## Fim Leitura ##\n\n");
	return test;	
}

void insereArestaValorada(Grafo *graph, int v, int w, int valor){
	if (v != w && graph->adj[v][w] == 0){
		//if()
		graph->adj[v][w] = valor;
		graph->adj[w][v] = valor;
		graph->aresta++;
	}
}

Grafo *preencheGrafoCompleto(int tam){
	srand(time(NULL));
	Grafo *graph = criaGrafo(tam);
	for (int i = 0; i < tam; i++){
		for (int j = 0; j < tam; j++){
			if(j < i) insereArestaValorada(graph, i, j, rand() % 10);
		}
	}
	return graph;
}

Grafo *preencheGrafoRand(int V, int tam) { 
	srand(time(NULL));
	double prob = (double) tam / V / (V - 1);
	Grafo *graph = criaGrafo(V);
	for (int v = 0; v < V; ++v)
		for (int w = 0; w < V; ++w)
			if (v != w)
				if (rand() < prob * (RAND_MAX + 1.0))
					insereArestaValorada(graph, v, w, rand() % 10);
	// printf("Preencheu\n");
	return graph;
}

Grafo *preencheGrafoBipartido(int tam){
	Grafo *graph = criaGrafo(tam);
	for (int v = 0; v < tam; v++)
		for (int w = 0; w < tam; w++)
			if(v % 2 == 0 && v != w)
				graph->adj[v][w] = 1;
	return graph;
}

///////////////////////////////////////////////////////////
///						AUXILIARES 						///
///////////////////////////////////////////////////////////
int *criaDfsVet(int tam_vet){
	int *vet = (int *) malloc(tam_vet * sizeof(int));
	for (int i = 0; i < tam_vet; ++i) vet[i] = i;
	return vet;
}

void quick(int vet[], int pre[], int esq, int dir) {
    int pivo = esq, i, ch, ch2, j;
    for (i = esq + 1; i <= dir; i++) {
        j = i;
        if (vet[j] < vet[pivo]) {
            ch = vet[j];
            ch2 = pre[j];
            while (j > pivo) {
                vet[j] = vet[j - 1];
                pre[j] = pre[j - 1];
                j--;
            }
            vet[j] = ch;
            pre[j] = ch2;
            pivo++;
        }
    }
    if (pivo - 1 >= esq) {
        quick(vet, pre, esq, pivo - 1);
    }
    if (pivo + 1 <= dir) {
        quick(vet, pre, pivo + 1, dir);
    }
}

void printVet(int vet[], int tam_vet, int tipo) {
	if(!tipo) printf("Pré-Ordem");
	else printf("Pós-Ordem");

	for(int i = 0; i < tam_vet; i++)
		if(i == 0) 					printf("[ %c, ", (char) (vet[i] + 65));
		else if(i == tam_vet - 1) 	printf("%c ]\n", (char) (vet[i] + 65));
		//else if(i % 10 == 0) 		printf("\n%d, ", (char) (vet[i] + 65);
		else 						printf("%c, ", (char) (vet[i] + 65));
}

void fprintVet(int vet[], int tam_vet, int tipo) {
	FILE *fp = fopen("OUT.DOT", "a");
    if (fp == NULL){
    	puts("Erro Arquivo");
        exit(0);
    } else {

		fprintf(fp, "\n//");
		if(!tipo) fprintf(fp, "Pré-Ordem");
		else fprintf(fp, "Pós-Ordem");

		for(int i = 0; i < tam_vet; i++)
			if(i == 0) 					fprintf(fp, "[ %c, ", (char) (vet[i] + 65));
			else if(i == tam_vet - 1) 	fprintf(fp, "%c ]", (char) (vet[i] + 65));
			//else if(i % 10 == 0) 		fprintf(fp, "//\n%c, ", (char) (vet[i] + 65));
			else 						fprintf(fp, "%c, ", (char) (vet[i] + 65));
	}
	// fprintf(fp, "*/");
	fclose(fp);
}
// ///////////////////////////////////////////////////////////
// ///						DFS      						///
// ///////////////////////////////////////////////////////////
// void SortDfs(int vet1[], int vet2[], int tam_vet) {
// 	srand(time(NULL));
// 	printf("DFS\n");
	
// 	int *pre = criaDfsVet(tam_vet);
// 	int *pos = criaDfsVet(tam_vet);
	
// 	quick(vet1, pre, 0, tam_vet - 1);
// 	quick(vet2, pos, 0, tam_vet - 1);
	
// 	printVet(pre, tam_vet, 0);
// 	printVet(pos, tam_vet, 1);
	
// 	fprintVet(pre, tam_vet, 0);
// 	fprintVet(pos, tam_vet, 1);
// }

// void dfsR(grafo *graph, int v, int pre[], int cnt0[], int pos[], int cnt1[], int pa[]) { 
// 	pre[v] = cnt0[0]++; 
// 	for (int w = 0; w < graph->vertice; ++w)
// 		if (graph->adj[v][w] != 0 && pre[w] == -1) 
// 			dfsR(graph, w, pre, cnt0, pos, cnt1, pa); 
// 	pos[v] = cnt1[0]++;
// }

// void dfs(grafo *graph, int pre[], int cnt0[], int pos[], int cnt1[], int pa[]) { 
// 	cnt0[0] = cnt1[0] = 0;
// 	for (int v = 0; v < graph->vertice; ++v) pre[v] = -1;
// 	for (int v = 0; v < graph->vertice; ++v) {
// 		if (pre[v] == -1) {
// 			pa[v] = v;
// 			dfsR(graph, v, pre, cnt0, pos, cnt1, pa);
// 		} // começa nova etapa
// 	}
// }

// void controlDFS(grafo *graph, int tam_vet){
// 	int *pre = criaDfsVet(tam_vet);
// 	int *pos = criaDfsVet(tam_vet);
// 	int *pa  = criaDfsVet(tam_vet);
// 	static int *cnt0 = criaDfsVet(1);
// 	static int *cnt1 = criaDfsVet(1);

// 	dfs(graph, pre, cnt0, pos, cnt1, pa);
	
// 	SortDfs(pre, pos, graph->vertice);
// }
// ///////////////////////////////////////////////////////////
// ///					COMPONENTE CONEXA 		  			///
// ///////////////////////////////////////////////////////////
// void dfsRcConexa(grafo *graph, int *cc, int v, int id){ 
// 	cc[v] = id;
// 	for (int w = 0; w < graph->vertice; ++w){
// 		if (graph->adj[v][w] != 0 && cc[w] == -1){
// 			dfsRcConexa(graph, cc, w, id);
// 			//printf("Analize Componente Conexa = %d\n", id); 
// 		} 
// 	}

// 	// for (ver a = G->adj[v]; a != NULL; a = a->next)
// 	// 	if (cc[a->w] == -1) 
// }

// int cConexa(grafo *graph, int *cc){
// 	int id = 0;
// 	for (int v = 0; v < graph->vertice; ++v)
// 		cc[v] = -1;
// 	for (int v = 0; v < graph->vertice; ++v){
// 		if (cc[v] == -1) dfsRcConexa(graph, cc, v, id++);
// 			//printf("%d\n", id); 
// 	}

// 	return id;
// }

// void testaVetor(Grafo *graph, int u, int v){
// 	imprimeVetorGrafo(graph); 		//matriz
// 	int tamvet = 0;
// 	int *resultVetor = transformV(graph, graph->vertice);
// 	for(int i = graph->vertice - 1; i > 0; i--) tamvet += i;
	
// 	imprimeVetor(resultVetor, tamvet); 	//vetor
// 	int rVizinho = vizinho(resultVetor, u, v, graph->vertice, tamvet);

// 	printf("Busca de [%d,%d] = %d, vetor de [%d]\n\n", u, v, rVizinho, tamvet);
// }

// void posOrder(int *pred, int inicio, int j){
// 	if(j != inicio){
// 		j = pred[j];
// 		posOrder(pred, inicio, j);
// 		printf("%d - ", j);
// 	}
// }

// void dijkstra(int **G, int n, int inicio) {
 
//     int **custo = alocaMatrizAdj(n, n, 0);
//     int *predecessor = 	(int *) calloc (n, sizeof(int));
//     int *distancia = 	(int *) calloc (n, sizeof(int));
//     int *visitado = 	(int *) calloc (n, sizeof(int));
//     int contador, minDistancia, proximoVertice, i, j;
    
// 	// predecessor[] armazena o predecessorecessor de cada contagem de nos 
// 	// que fornece o numero de nos vistos ate agora para criar 
// 	// a matriz de custo
//     for(i = 0; i < n; i++){
//         for(j = 0; j < n; j++){
//             if(G[i][j] == 0) custo[i][j] = 9999999;
//             else custo[i][j] = G[i][j];
//         }
//     }
    
//     //inicializa predecessor[], distancia[] e visitado[]
//     for(i = 0; i < n; i++) {
//         distancia[i] = custo[inicio][i];
//         predecessor[i] = inicio;
//         visitado[i] = 0;
//     }
    
//     distancia[inicio] = 0;
//     visitado[inicio] = 1;
//     contador = 1;
    
//     while(contador < n - 1) {
//         minDistancia = 9999999;
        
//         //proximoVertice fornece o no a uma distancia minima
//         for(i = 0; i < n; i++){
//             if(distancia[i] < minDistancia && !visitado[i]) {
//                 minDistancia = distancia[i];
//                 proximoVertice = i;
//             }
//         }
            
// 	// verifica se existe um caminho melhor através do proximoVertice
//         visitado[proximoVertice] = 1;
//         for(i = 0; i < n; i++){
// 	        if(!visitado[i])
// 	            if(minDistancia + custo[proximoVertice][i] < distancia[i]) {
// 	                distancia[i] = minDistancia + custo[proximoVertice][i];
// 	                predecessor[i] = proximoVertice;
// 	            }
// 	        }
//         contador++;
//     }
 
// 	// imprime o caminho e a distância de cada nó
//     for(i = 0; i < n; i++){
//         if(i != inicio) {
//             printf("\t\t\n\nCaminho de %d = [", i);
//             j = i;
//             posOrder(predecessor, inicio, j);
//             printf("%d]", i);
//             printf("\nDistancia \t = %d", distancia[i]);
//             // printf("\nCaminho: [%d", i);
            
//             // do {
//             //     j = predecessor[j];
//             //     printf(" - %d", j);
//             // } while(j != inicio);
//     	}
//     }
//     printf("\n");
// }

// // A DFS based recursive function that returns true if a matching for vertex u is possible 
// int bpm(int **bpGraph, int tam, int u, int seen[], int matchR[]) {
// 	// Try every job one by one 
// 	for (int v = 0; v < tam; v++) { 
// 		// If applicant u is interested in job v and v is not visited 
// 		if (bpGraph[u][v] && !seen[v]) {
// 			// Mark v as visited
// 			seen[v] = 1;

// 			// If job 'v' is not assigned to an applicant OR previously assigned  
// 			// applicant for job v (which is matchR[v]) has an alternate job available.  
// 			// Since v is marked as visited in the above line, matchR[v] in the following  
// 			// recursive call will not get job 'v' again 
// 			if (matchR[v] < 0 || bpm(bpGraph, tam, matchR[v], seen, matchR)) {
// 				// printf("Match [%d - %d]\n", u, matchR[v]);
// 				matchR[v] = u;
// 				return 1;
// 			}
// 		}
// 	}
// 	return 0;
// }

// // Returns maximum number of matching from M to N 
// int maxBPM(int **bpGraph, int tam) { 
// 	// An array to keep track of the applicants assigned to jobs.  
// 	// The value of matchR[i] is the applicant number assigned to job i, 
// 	// the value -1 indicates nobody is assigned. 
// 	int matchR[tam];

// 	// Initially all jobs are available 
// 	// memset(matchR, -1, sizeof(matchR));
// 	for (int i = 0; i < tam; ++i)
// 		matchR[i] = -1;

// 	// Count of jobs assigned to applicants 
// 	int result = 0;
// 	for (int u = 0; u < tam; u++) {
// 		// Mark all jobs as not seen for next applicant.
// 		int seen[tam];
// 		// memset(seen, 0, sizeof(seen));
// 		for (int i = 0; i < tam; ++i)
// 			seen[i] = 0;  
// 		// Find if the applicant 'u' can get a job 
// 		if (bpm(bpGraph, tam, u, seen, matchR)){
// 			result++;
// 		}
// 	}
// 	return result;
// }

int main(){

	// ENTRADAS OPCIONAIS
	// Grafo *test = preencheGrafoCompleto(4);
	Grafo *test = preencheGrafoRand(499, 40000);
	// Grafo *test = preencheGrafoBipartido(4);
	// Grafo *test = lerGrafoArquivo();
	// imprimeGrafo(test);

	// DIJKSTRA
	// dijkstra(test->adj, test->vertice, 0);

	// MATCHING MAXIMO
	// printf("\nProblema exemplo\nMatching maximo de candidatos que conseguem emprego eh %d\n", maxBPM(test->adj, test->vertice));
	// imprimeGrafo(test);

	// TESTE COMPONENTE CONEXA EXERCICIO 14
	// int *vet = (int *) calloc(test->vertice, sizeof(int));
	// int compC = cConexa(test, vet);
	// printf("%d Componente Conexa\n", compC);
	
	// TESTE DE DFS
	imprimeGrafoArquivo(test);
	// controlDFS(test, test->vertice);
	
	// TESTE DO EXERCICIO 6.C E 6.D
	// imprimeVetorGrafo(test); 		//matriz
	// testaVetor(test, 1, 5);
	// imprimeGrafo(test);
	// imprimeGrafoArquivo(test);
	
	return 0;
}
