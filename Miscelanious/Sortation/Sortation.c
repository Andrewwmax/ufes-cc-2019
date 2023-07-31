#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// #include "HeapSort.c"

typedef struct {
    int topo;
    int *balde;
} bucket;

typedef struct {
    int tam;
    int* array;
} MaxHeap;

typedef struct inArgs{
	int qtdnumeros;
	int rangeMin;
	int rangeMax;
	char *sort;
	char *arq;
} tArgs;

int *criaVetor(int tam) { 
	int *numeros = (int *) calloc(tam, sizeof(int));
	if (!numeros) exit(EXIT_FAILURE);
	return numeros;
}

void troca(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void shuffle(int *array, int tam/*, int rangeMin, int rangeMax*/) {
	for (int i = tam - 1; i > 0; i--) {
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

void insertion(int piItem[], int iQtdElementos) {
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

void bucketS(int vet[], int n) {
	bucket balde[n];
	int i, j;

	for(i=0; i < n; i++){
		balde[i].topo = 0;
		balde[i].balde = (int *) malloc(n * sizeof(int));
	}

	for(i = 0; i < n; i++){
		int j = n -1;// = n * vet[i];
		while (1) {
            if (j < 0)
                break;
            if (vet[i] >= j * 10) {
				balde[j].balde[balde[j].topo] = vet[i];
				balde[j].topo++;
                break;
            }
            j--;
        }
	}

	for(i = 0; i < n; i++){
		bubble(balde[i].balde, balde[i].topo);
	}
	//for (int i = 0; i < n; i++) printf("%d, ", vet[i]);

	i = j = 0;
	while(i != n){
		if(balde[j].topo){
			balde[j].topo--;
			vet[i] = balde[j].balde[balde[j].topo];
			i++;
		} else {
			j++;
		}
	}
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
//					HEAPSORT importado;	 Bugadão		//
// void heap(int *vet, int tam) {
// 	HEAP H;
// 	inicializarHeap(&H, tam);
// 	//for (int i = 0; i < tam; ++i) H.A[i] = vet[i];
// 	//memcpy(H.A, vet, sizeof(H.A));
// 	//vetToHeap(&H, vet, 0);
// 	// please C, I tried to do it right, do not complain later;
// 	H.A = vet; 

// 	H.tamanhoAtual = tam;
// 	H.tamanhoMaximo = tam;
// 	printf("\n");
// 	heapSort(&H);
// 	// percursoVertical(&H, 0, 1);
// 	vet = H.A;
// 	// printInTree(&H);
// 	destruirHeap(&H);						 
// }
//////////////////////////////////////////////////////////

// void heapMaximo(MaxHeap* maxHeap, int index){
//     int maior = index;
//     int esquerdo = (index << 1) + 1;
//     int direito = (index + 1) << 1;

//     if (esquerdo < maxHeap->tam &&
//         maxHeap->array[esquerdo] > maxHeap->array[maior])
//         maior = esquerdo;

//     if (direito < maxHeap->tam &&
//         maxHeap->array[direito] > maxHeap->array[maior])
//         maior = direito;
//     if (maior != index)
//     {
//         troca(&maxHeap->array[maior], &maxHeap->array[index]);
//         heapMaximo(maxHeap, maior);
//     }
// }

// // A utility function to create a max heap of given capacity
// MaxHeap* heapConstrutor(int *array, int tam){
//     int i;
//     MaxHeap* maxHeap = (MaxHeap*) malloc(sizeof(MaxHeap));
//     maxHeap->tam = tam;   // initialize size of heap
//     maxHeap->array = array; // Assign address of first element of array

//     // Start from bottommost and rightmost internal mode and heapify all
//     // internal modes in bottom up way
//     for (i = (maxHeap->tam - 2) / 2; i >= 0; --i)
//         heapMaximo(maxHeap, i);
//     return maxHeap;
// }

// // The main function to sort an array of given size
// void heapSort(int* array, int tam){
//     // Build a heap from the input data.
//     MaxHeap* maxHeap = heapConstrutor(array, tam);

//     // Repeat following steps while heap size is greater than 1.
//     // The last element in max heap will be the minimum element
//     while (maxHeap->tam > 1){
//         // The largest item in Heap is stored at the root. Replace
//         // it with the last item of the heap followed by reducing the
//         // size of heap by 1.
//         troca(&maxHeap->array[0], &maxHeap->array[maxHeap->tam - 1]);
//         --maxHeap->tam;  // Reduce heap size

//         // Finally, heapify the root of tree.
//         heapMaximo(maxHeap, 0);
//     }
// }

void Sortation(void (*Sort)(int *vet, int qtd), int *vet, int tam) {
	clock_t tInicio, tFim, tDecorrido;

	tInicio = clock();
	Sort(vet, tam);
	tFim = clock();

	for (int i = 0; i < tam; i++) printf("%d, ", vet[i]);

	printf("\n%ld ms\n", ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000)));
}

int *lerArquivo(char *fill){
	FILE *arq;
	int *vet, num = 0, i = 0, j = 0;
	arq = fopen(fill, "rt");
	fscanf(arq, "%d%*c", &num);
	
	printf("[%d] Numeros de entrada\n", num);
	
	vet = criaVetor(num);

	for(i = 0; i < num; i++){
		fscanf(arq, "%d, ", &j);
		printf("%d, ", j);
		vet[i] = j;
	}
	return vet;
}

int help(int error){
	if(!error){
		printf ("Argumentos:\t  -f[funcao] -q[qtdnumeros] -o[arq] -r [rangeMin rangeMax]");
		printf ("\n\tSortation -f -q -r");
		printf ("\n\tSortation -f -o\n\tSortation --help\n");
		printf ("\n\t|Funcao:\n\t|\t+--- radix,\n\t|\t+--- counting,\n\t|\t+--- selection,\n\t|\t+--- bubble,\n\t|\t+--- heap  obs. max -q[32729],\n\t|\t+--- insertion,\n\t|\t+--- merge,\n\t|\t+--- quick\n");
		printf ("\t|Qtdnumeros:\n\t|\t+--- (int+), default 101\n\t\t\tQuantidade de numeros a serem gerados\n");
		printf ("\t|Arquivo:\n\t|\t+--- [String]? default NULL\n\t\t\tArquivo com os numeros a serem lidos, formato {(int+),(int+)}\n");
		printf ("\t|Range Min & Max:\n\t|\t+--- [(int+) (int+)] default [qtdnumeros] obs: [Opcional]\n\t\t\tIntervalo de geracao de numeros aleatorios\n");
		printf ("\n\t|EX: ./Sortation -fmerge -q100 -r 1500 2000\n\n");
	}
	else if(error == 1) printf ("\nFuncao: radix,\n\tcounting,\n\tselection,\n\tbubble,\n\tinsertion,\n\tmerge,\n\tquick\n");
	else if(error == 2) printf ("\nQtdnumeros:\t(int*)+, default 100\tQuantidade de numeros a serem gerados\n");
	else if(error == 3) printf ("\nArq:\t[String]? default Null\tArquivo com os numeros a serem lidos, formato [(int*)+,(int*)*]");
	else if(error == 4) printf ("\nRangeMin & Max:\tIntervalo de geracao de numeros aleatorios, formato (int*)+ (int*)+\n");

	exit(0);
}

tArgs inArg(int argc, char** argv) {
	int qtdnumeros = 0, i = 1;
	char tam[10], arq[50];
	tArgs IN;
	if(argc == 1 || strcmp(argv[1], "--help") == 0) help(0);
	// if(strcmp(argv[1], "--help") == 0 || argc == 1) help(0); // Curto circuito, gera SegFault;
	else {
		if(argv[i][0] == '-' & argv[i][1] == 'f') {
			IN.sort = (char *) calloc(strlen(argv[i]) - 2, sizeof(char));
			strncpy(IN.sort, argv[i] + 2, strlen(argv[i]) - 2);
			printf("-f[%s]\t", IN.sort);
			i++;

			if(argv[i][0] == '-' & argv[i][1] == 'q' & argc > 1) {
				strncpy(tam, argv[i] + 2, strlen(argv[i]) - 2);
				IN.qtdnumeros = abs(atoi(tam));
				printf("-q[%d]\t", IN.qtdnumeros);
				IN.rangeMin = 1;
				IN.rangeMax = IN.qtdnumeros;
				if(argc >= i) i++;

				if(i < argc && argv[i][0] == '-' && argv[i][1] == 'r') {
					i++;
					if(i + 1 < argc && abs(atoi(argv[i])) >= 0 && (abs(atoi(argv[i + 1])) > 0)) {
						IN.rangeMin = abs(atoi(argv[i]));
						printf("-r [%d]", IN.rangeMin);
						i++;
						IN.rangeMax = abs(atoi(argv[i]));
						printf(" [%d]\t", IN.rangeMax);
					
					} else help(i);

				} else return IN;

			} else if(argv[i][0] == '-' & argv[i][1] == 'o' & i < argc) {
				IN.arq = (char *) calloc(strlen(argv[i]) - 2, sizeof(char));
				strncpy(IN.arq, argv[i] + 2, strlen(argv[i]) - 2);
				IN.arq[strlen(argv[i]) - 2] = '\0';
				printf("-o[%s]\t", IN.arq);

			} else help(i);
		} else help(i);
	}
	return IN;
}

void range(int *numeros, int qtdnumeros, int rangeMin, int rangeMax) {
	// time_t u = time(NULL);// / CLOCKS_PER_SEC;
	// time_t *hr = &u;
	// char *c = ctime(hr);
	// printf("\nA funcao escolhida, %s, com %d numeros\n ctime = %s", sort, qtdnumeros, c);

	clock_t tInicio, tFim, tDecorrido;

	//numeros = criaVetor(qtdnumeros); //argv[2];
	// for (int i = 0; i < qtdnumeros; i++) numeros[i] = i + MIN;
	
	printf("\nNumeros a serem ordenados = %d\n", qtdnumeros);
	for (int i = 0; i < qtdnumeros; i++) {	
		numeros[i] = rand() % rangeMax;
		(numeros[i] < rangeMin) ? (((numeros[i] + rangeMin) > rangeMax) ? (numeros[i] = numeros[i]) : (numeros[i] = numeros[i] + rangeMin)) : (numeros[i] = numeros[i]);
	//  numeros[i] < rangeMin ? numeros[i] : numeros[i] + rangeMin;
	}
	
	////////////////////////////////////////////////////////////////////////////
	tInicio = clock();
	shuffle(numeros, qtdnumeros);
	tFim = clock();    
	////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < qtdnumeros; i++) printf("%d, ", numeros[i]);
	tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
	printf("\n%ld ms\n", tDecorrido);
}

int main(int argc, char** argv) {
	srand(time(NULL));
	
	tArgs ARGS;
	int *numeros;

	if(argc == 1 || argc == 2) help(0);
	else ARGS = inArg(argc, argv);

	if (ARGS.arq != NULL){
		numeros = lerArquivo(ARGS.arq);
	} else {
		numeros = criaVetor(ARGS.qtdnumeros);
		range(numeros, ARGS.qtdnumeros, ARGS.rangeMin, ARGS.rangeMax); //argv[2];
	}


	//int qtdnumeros = ARGS.qtdnumeros, rangeMin = ARGS.rangeMin, rangeMax = ARGS.rangeMax;
	//char sort[100], tam[15], arq[100];
	//strcpy(sort, ARGS.sort);
	//strcpy(arq, ARGS.arq);
		
	// printf ("Argumentos -- Syntaxe: ./Sortation -f[funcao] -q[qtdnumeros] -o[arq] -r [rangeMin rangeMax] \n");
	

	// if (argc != 3 || strcmp(argv[1], "--help") == 0){
	// printf ("Argumentos:\n\tSortation [funcao] [qtdnumeros]\n\tSortation --help\n\t\tFuncao: radix,\n\t\t\tcounting,\n\t\t\tselection,\n\t\t\tbubble,\n\t\t\theap [32729],\n\t\t\tinsertion,\n\t\t\tmerge,\n\t\t\tquick\n\n");
	// printf("\tEX: ./Sortation merge 1000\n\n");
	// return 0;
	// //exit(-1);
	// }

	// strcpy(sort, argv[1]);
	// //if(argv[2][1] == 'o') {
	// //strcpy(arq, argv[3]);
	// //lerArquivo(numeros, arq);
	// //} else 
	// qtdnumeros = abs(atoi(argv[2]));
	
	
	// primeiro test
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// int *aBubble = numeros;
	// void (*bub)(int *vet, int qtd);
	// bub = &bubble;
	// bub(aBubble, qtdnumeros);
	// for (int i = 0; i < qtdnumeros; i++) printf("%d\n", aBubble[i]);
	// Sortation(bubble,aBubble,qtdnumeros);
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	if(strcmp(ARGS.sort, "bubble") == 0) {// || 'Bubble':
		printf("\n##########\naBubble\n");
		int *aBubble = numeros;
		Sortation(bubble,aBubble,ARGS.qtdnumeros);
	
	} else if(strcmp(ARGS.sort, "selection") == 0) {// || 'Selection':
		printf("\n##########\naSelection\n");
		int *aSelection = numeros;
		Sortation(selection,aSelection,ARGS.qtdnumeros);
	
	} else if(strcmp(ARGS.sort, "radix") == 0) {// || 'Radix':
		printf("\n##########\naRadix\n");
		int *aRadix = numeros;
		Sortation(radix,aRadix,ARGS.qtdnumeros);
	
	} else if(strcmp(ARGS.sort, "insertion") == 0) {// || 'Insert':
		printf("\n##########\naInsertion\n");
		int *aInsertion = numeros;
		Sortation(insertion,aInsertion,ARGS.qtdnumeros);
	
	} else if(strcmp(ARGS.sort, "bucket") == 0) {// || 'Bucket':
		printf("\n##########\naBucketS\n");
		int *aBucketS = numeros;
		Sortation(bucketS,aBucketS,ARGS.qtdnumeros);
	
	} else if(strcmp(ARGS.sort, "counting") == 0) {// || 'Counting':
		printf("\n##########\naCounting\n");
		int *aCounting = numeros;
		Sortation(counting,aCounting,ARGS.qtdnumeros);
	
	} else if(strcmp(ARGS.sort, "merge") == 0) {// || 'Merge':
		printf("\n##########\naMerge\n");
		int *aMerge = numeros;
		Sortation(merge,aMerge,ARGS.qtdnumeros);
	
	} else if(strcmp(ARGS.sort, "quick") == 0) {// || 'Quick':
		printf("\n##########\naQuick\n");
		int *aQuick = numeros;
		Sortation(quick,aQuick,ARGS.qtdnumeros);
	
	// } else if(strcmp(ARGS.sort, "heap") == 0) {// || 'Heap':
	// 	printf("\n##########\naHeap\n");
	// 	int *aHeap = numeros;
	// 	Sortation(heap,aHeap,ARGS.qtdnumeros);
	
	} else return 0;
}