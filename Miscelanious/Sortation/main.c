#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HeapSort.c"

#define MIN 1
#define MAX 50000

typedef struct {
    int topo;
    int balde[MAX];
} bucket;

int *criaVetor(int tam) { 
	int *numeros = (int *) malloc(tam * sizeof(int));
	if (!numeros) exit(EXIT_FAILURE);
	return numeros;
}

void shuffle(int *array) {
	for (int i = MAX - MIN - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
	}
}

void bubble(int piItem[], int iQtdElementos) {
	register int i, j;
	register int iAux;
	for (i = 1; i < iQtdElementos; i++) {
		for (j = iQtdElementos - 1; j >= i; j--) {
			if (piItem[j - 1] > piItem[j]) {
				iAux = piItem[j - 1];
				piItem[j - 1] = piItem[j];
				piItem[j] = iAux;
			}
		}
	}
	return;
}

void selection(int piItem[], int iQtdElementos) {
	register int iMinimo = 0, iAux = 0;
	for (int i = 0; i < iQtdElementos - 1; i++) {
		iMinimo = i;
		for (int j = i + 1; j < iQtdElementos; j++) {
			if (piItem[j] < piItem[iMinimo])
				iMinimo = j;
		}
		iAux = piItem[i];
		piItem[i] = piItem[iMinimo];
		piItem[iMinimo] = iAux;
	}
}

void radix(int vetor[], int tamanho) {
	int i;
	int *b;
	int maior = vetor[0];
	int exp = 1;

	b = (int *) calloc(tamanho, sizeof(int));

	for (i = 0; i < tamanho; i++) {
		if (vetor[i] > maior)
			maior = vetor[i];
	}

	while (maior/exp > 0) {
		int bucket[10] = { 0 };
		for (i = 0; i < tamanho; i++)
			bucket[(vetor[i] / exp) % 10]++; 
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = tamanho - 1; i >= 0; i--)
			b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
		for (i = 0; i < tamanho; i++)
			vetor[i] = b[i];
		exp *= 10;
	}
	free(b);
}

void insert(int piItem[], int iQtdElementos) {
    register int i, j, iAux;
    for (i = 1; i < iQtdElementos; i++) {
        iAux = piItem[i];
        for (j = i - 1; j >= 0 && iAux < piItem[j]; j--) {
            piItem[j + 1] = piItem[j];
        }
        piItem[j + 1] = iAux;
    }
    return;
}

void bucketS(int v[], int tam) {
    bucket b[tam];
    int i, j, k;
    for (i = 0; i < MAX; i++) //inicializa todos os "topo"
        b[i].topo = 0;

    for (i = 0; i < tam; i++) { //verifica em que balde o elemento deve ficar
        j = (MAX) - 1;
        while (1) {
            if (j < 0)
                break;
            if (v[i] >= j * 10) {
                b[j].balde[b[j].topo] = v[i];
                (b[j].topo)++;
                break;
            }
            j--;
        }
    }

    for (i = 0; i < MAX; i++)//ordena os baldes
        if (b[i].topo) 
            bubble(b[i].balde, b[i].topo);
    i = 0;
    for (j = 0; j < MAX / 10; j++) { //põe os elementos dos baldes de volta no vetor
        for (k = 0; k < b[j].topo; k++) {
            v[i] = b[j].balde[k];
            //printf("%d, ", v[i]);
            i++;
        }
        //printf("\n");
    }
}

void counting(int *A, int n){
    int i;
    int *B = (int *) calloc(n, sizeof (int));
    int *C = (int *) calloc(n, sizeof (int));

    for(i = 0; i < n; i++) C[A[i]-1]++;         //Passo 1
        
    for(i = 1; i < n; i++) C[i] += C[i - 1];    //Passo 2

    for(i = n - 1; i >= 0; i--) {               //Passo 3
        B[C[A[i] - 1] - 1] = A[i];
        C[A[i] - 1]--;
    }

    for(i = 0; i < n; i++) A[i] = B[i];			//Passo 4
}

void mergesort(int v[], int inicio, int fim) {
    int i, j, k, meio, *auxiliar;
    if (inicio == fim) {
        return;
    }

    /* ordenação recursiva das duas metades */
    meio = (inicio + fim) / 2;
    mergesort(v, inicio, meio);
    mergesort(v, meio + 1, fim);

    /* intercalação no vetor temporário auxiliar */
    i = inicio;
    j = meio + 1;
    k = 0;
    auxiliar = (int *) malloc(sizeof (int) * (fim - inicio + 1));
    while (i < meio + 1 || j < fim + 1) {
        if (i == meio + 1) /* i passou do inal da prfimeira metade, pegar v[j] */ {
            auxiliar[k] = v[j];
            j++;
            k++;
        } else if (j == fim + 1) /* j passou do inal da segunda metade, pegar v[i] */ {
            auxiliar[k] = v[i];
            i++;
            k++;
        } else if (v[i] < v[j]) /* v[i]<v[j], pegar v[i] */ {
            auxiliar[k] = v[i];
            i++;
            k++;
        } else /* v[j]<=v[i], pegar v[j] */ {
            auxiliar[k] = v[j];
            j++;
            k++;
        }
    }
    /* copia vetor intercalado para o vetor original */
    for (i = inicio; i <= fim; i++) {
        v[i] = auxiliar[i - inicio];
    }
    free(auxiliar);
    return;
}

void merge(int *vet, int tam) {
	//Auxiliar de merge
	mergesort(vet, 0, tam);
}

void quicksort(int vet[], int esq, int dir) {
    int pivo = esq, i, ch, j;
    for (i = esq + 1; i <= dir; i++) {
        j = i;
        if (vet[j] < vet[pivo]) {
            ch = vet[j];
            while (j > pivo) {
                vet[j] = vet[j - 1];
                j--;
            }
            vet[j] = ch;
            pivo++;
        }
    }
    if (pivo - 1 >= esq) {
        quicksort(vet, esq, pivo - 1);
    }
    if (pivo + 1 <= dir) {
        quicksort(vet, pivo + 1, dir);
    }
}

void quick(int *vet, int tam) {
	//Auxiliar de Quick
	quicksort(vet, 0, tam);
}

//////////////////////////////////////////////////////////
//					HEAPSORT importado;					//
void heap(int *vet, int tam) {
	HEAP H;
	inicializarHeap(&H, tam);
	//for (int i = 0; i < tam; ++i) H.A[i] = vet[i];
	//memcpy(H.A, vet, sizeof(H.A));
	//vetToHeap(&H, vet, 0);
	// please C, I tried to do it right, do not complain later;
	H.A = vet;

	H.tamanhoAtual = tam;
	H.tamanhoMaximo = tam;
	printf("\n");
	heapSort(&H);
	// percursoVertical(&H, 0, 1);
	vet = H.A;
	// printInTree(&H);
	destruirHeap(&H);						 //
}														//
//////////////////////////////////////////////////////////

void Sortation(void (*Sort)(int *vet, int qtd), int *vet, int tam){
	clock_t tInicio, tFim, tDecorrido;

	tInicio = clock();
	Sort(vet, tam);
	tFim = clock();

	for (int i = 0; i < MAX; i++) printf("%d, ", vet[i]);

	printf("\n%ld ms\n", ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000)));
}

int main(int argc, char** argv) {
	int tam;
	char sort[100];
		//printf ("Argumentos -- Syntaxe: ./Sort 'funcao' 'qtdnumeros'\n");
	
	if (argc != 3){
		printf ("Argumentos inválidos -- Syntaxe: ./Sort 'funcao' 'qtdnumeros'\n");
		exit(-1);
	}
	
	if (argv[2] < 0){
		perror(argv[2]);
		exit(-1);
	}
	
	strcpy(sort, argv[1]);
	tam = atoi(argv[2]);
	printf("\nA funcao escolhida, %s, com %d numeros\n", sort, tam);

	srand(time(NULL));
	clock_t tInicio, tFim, tDecorrido;
	int *numeros = criaVetor(MAX); //argv[2];
	// for (int i = 0; i < MAX; i++) numeros[i] = i + MIN;
	
	printf("\nNumeros a serem ordenados = %d\n", MAX);
	for (int i = MAX; i >= 0; i--) numeros[i] = MAX - i;
	
	////////////////////////////////////////////////////////////////////////////
	tInicio = clock();
	shuffle(numeros);
	tFim = clock();    
	////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < MAX; i++) printf("%d, ", numeros[i]);
	tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
	printf("\n%ld ms\n", tDecorrido);

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// int *aBubble = numeros;
	// void (*bub)(int *vet, int qtd);
	// bub = &bubble;
	// bub(aBubble, MAX);
	// for (int i = 0; i < MAX; i++) printf("%d\n", aBubble[i]);
	// Sortation(bubble,aBubble,MAX);
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "bubble") == 0) {// || 'Bubble':
			printf("\n##########\naBubble\n");
			int *aBubble = numeros;
			Sortation(bubble,aBubble,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "selection") == 0) {// || 'Selection':
			printf("\n##########\naSelection\n");
			int *aSelection = numeros;
			Sortation(selection,aSelection,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "radix") == 0) {// || 'Radix':
			printf("\n##########\naRadix\n");
			int *aRadix = numeros;
			Sortation(radix,aRadix,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "insert") == 0) {// || 'Insert':
			printf("\n##########\naInsert\n");
			int *aInsert = numeros;
			Sortation(insert,aInsert,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "bucket") == 0) {// || 'Bucket':
			printf("\n##########\naBucketS\n");
			int *aBucketS = numeros;
			Sortation(bucketS,aBucketS,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "counting") == 0) {// || 'Counting':
			printf("\n##########\naCounting\n");
			int *aCounting = numeros;
			Sortation(counting,aCounting,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "merge") == 0) {// || 'Merge':
			printf("\n##########\naMerge\n");
			int *aMerge = numeros;
			Sortation(merge,aMerge,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "quick") == 0) {// || 'Quick':
			printf("\n##########\naQuick\n");
			int *aQuick = numeros;
			Sortation(quick,aQuick,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		if(strcmp(sort, "heap") == 0) {// || 'Heap':
			printf("\n##########\naHeap\n");
			int *aHeap = numeros;
			Sortation(heap,aHeap,MAX);
		}
			// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	return 0;
}
	