/******************************************************************************
							 heap.c
   Este programa implementa um heap MAXIMO em uma implementacao estatica de uma 
   arvore binaria. Nao usa a posicao 0 (zero) do arranjo.
 ******************************************************************************/
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define PARENT(i) ((i-1) / 2)
#define LINE_WIDTH 145
#define true 1
#define false 0

typedef struct {
	int *A;
	int tamanhoAtual;
	int tamanhoMaximo;
} HEAP;

void inicializarHeap(HEAP *h, int tamanhoMax) {
	h->A = (int*) malloc(sizeof (int)*(tamanhoMax + 1));
	h->tamanhoAtual = 0;
	h->tamanhoMaximo = tamanhoMax;
}

void destruirHeap(HEAP * h) {
	int tamanho = h->tamanhoMaximo;
	free(h->A);
	h->tamanhoMaximo = 0;
	h->tamanhoAtual = 0;
}

int pai(int i) { return i / 2; }

int filhoEsquerda(int i) { return 2 * i; }

int filhoDireita(int i) { return 2 * i + 1; }

/* metodo auxiliar que pressupoe que o heap para qualquer j>i estah ordenado
   porem o elemento i nao eh necessariamente maior que seus filhos           */
void maxHeapify(HEAP * h, int i) {
	int esq = filhoEsquerda(i);
	int dir = filhoDireita(i);
	int temp;
	int maior = i;
	if ((esq <= h->tamanhoAtual) && (h->A[esq] > h->A[i])) maior = esq;
	if ((dir <= h->tamanhoAtual) && (h->A[dir] > h->A[maior])) maior = dir;
	if (maior != i) {
		temp = h->A[i];
		h->A[i] = h->A[maior];
		h->A[maior] = temp;
		maxHeapify(h, maior);
	}
}

// Constroi heap a partir do arranjo usando o metodo maxHeapify
void construirHeapMaximo(HEAP * h) {
	int i;
	int metadeTamanho = h->tamanhoAtual / 2;
	for (i = metadeTamanho; i > 0; i--) maxHeapify(h, i);
}

// Insere no final do arranjo do heap
int inserirForaDeOrdem(HEAP * h, int valor) {
	if (h->tamanhoAtual < h->tamanhoMaximo) {
		(h->tamanhoAtual)++;
		h->A[h->tamanhoAtual] = valor;
		return true;
	}
	return false;
}

// Imprime o arranjo (na ordem que estiver)
void imprimirArranjo(HEAP h) {
	int tamanho = h.tamanhoAtual;
	int i;
	for (i = 1; i <= tamanho; i++) printf("%d ", h.A[i]);
	printf("\n");
}

// Imprime elementos em ordem decrescente e esvazia o heap
void heapSort(HEAP * h) {
	int tamanho = h->tamanhoAtual;
	int i, temp;
	construirHeapMaximo(h); // se o arranjo jah for um heap, nao precisa desta linha
	for (i = tamanho; i > 1; i--) {
		temp = h->A[1];
		h->A[1] = h->A[i];
		h->A[i] = temp;
		//printf("%d ",temp);
		(h->tamanhoAtual)--;
		maxHeapify(h, 1);
	}
	//printf("\n");
	h->tamanhoAtual = tamanho;
}

int inserirHeap(HEAP * h, int chave) {
	int i, temp;
	if (h->tamanhoAtual == h->tamanhoMaximo) return false;
	(h->tamanhoAtual)++;
	i = h->tamanhoAtual;
	h->A[i] = chave;
	while ((i > 1) && (h->A[pai(i)] < h->A[i])) {
		temp = h->A[i];
		h->A[i] = h->A[pai(i)];
		h->A[pai(i)] = temp;
		i = pai(i);
	}
	return true;
}

void percursoPreOrdem(HEAP* h, int atual) {
	if (atual <= h->tamanhoAtual) {
		printf("%i ", h->A[atual]);
		percursoPreOrdem(h, filhoEsquerda(atual));
		percursoPreOrdem(h, filhoDireita(atual));
	}
}

int alturaHeap(HEAP* h) {
	int altura = -1;
	int i = 1;
	while (i <= h->tamanhoAtual) {
		i = filhoEsquerda(i);
		altura++;
	}
	return altura;
}

// void percursoVertical(HEAP* h, int space, int atual) {
// 	//if(!h->A[atual+1]) return;
// 	space += (MAX/4); 
// 	if (atual <= h->tamanhoAtual) {
// 		percursoVertical(h, space, filhoDireita(atual));
// 		for (int i = MAX/4; i < space; i++) printf("*");
// 		printf("%i\n", h->A[atual]);
// 		percursoVertical(h, space, filhoEsquerda(atual));
// 	}
// }
void percursoVertical(HEAP* h, int space, int atual) {
	space += (h->tamanhoMaximo / 6); 
	if (atual <= h->tamanhoAtual) {
		percursoVertical(h, space, filhoDireita(atual));
		for (int i = h->tamanhoMaximo / 4; i < space; i++) printf("*");
		printf("%i\n", h->A[atual]);
		percursoVertical(h, space, filhoEsquerda(atual));
	}
}

// void BFS(HEAP* h, int space, int atual) {
// 	//space /= 2; 
// 	if (atual <= h->tamanhoAtual) {
// 		//if()
// 		printf("\n");
// 		for (int i = 0; i < space; i++) printf("*");
// 		//for(int i = 0; i < 75; i++) printf("*");
// 		// printf("%i", h->A[atual]);
// 		//for(int i - 0; i < MAX; i++){
// 		while(atual < MAX) {
// 			printf("%i", h->A[atual++]);
// 			if(atual % 2 == 0) printf("\n");
// 			for (int i = 0; i < space; i++) printf("*");
// 			space /= 2;
// 			//getnivel();
// 		}
// 		//BFS(h, space/2, filhoDireita(atual));
// 		//printf("*");
// 		//BFS(h, space/2, filhoEsquerda(atual));
// 	}
// }

void printInTree(HEAP* h) {
	int print_pos[h->tamanhoAtual];
	
	int i, j, k, pos, x=1, level=0;

	print_pos[0] = 0;
	for(i = 0, j = 1; i < h->tamanhoAtual; i++, j++) {
		pos = print_pos[PARENT(i)]+ (i % 2 ? -1 : 1) * ((LINE_WIDTH) / (pow(2, (level+1)))+1);

		for (k = 0; k < pos - x; k++)
			printf("%c", i == 0 || i % 2 ? ' ' : '-');
		
		printf("%d", h->A[i+1]);
		//printf(")");

		print_pos[i] = x = pos + 1;
		if (j == pow(2, level)) {
			printf("\n");
			level++;
			x = 1;
			j = 0;
		}
	}
	printf("\n");
}

void preencheHEAPAleatorio(HEAP *h, int tam) {
	for (int i = h->tamanhoMaximo; i > 0; i--) {
		inserirForaDeOrdem(h, rand() %15);
	}
}
void vetToHeap(HEAP *h, int *vet, int opc){
	// void copy_array(void *dst, const void *src, size_t n, size_t size){
	// 0 = VET TO HEAP, 1 = HEAP TO VET
	if(!opc) memcpy(h->A, vet, sizeof(vet));
	else memcpy(vet, h->A, sizeof(vet));
// }
}

// void heap(int *vet, int tam) {
// 	HEAP meuHeap;
// 	inicializarHeap(&meuHeap, tam);
// 	meuHeap.A = vet;
// 	meuHeap.tamanhoAtual = tam;
// 	meuHeap.tamanhoMaximo = tam;
// 	printf("\n");
// 	heapSort(&meuHeap);
// 	percursoVertical(&meuHeap, 0, 1);
// 	vet = meuHeap.A;
// 	// printInTree(&meuHeap);
// 	destruirHeap(&meuHeap);
// }