#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
void radixsort(int vetor[], int tamanho) {
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

int main(){
	int *numeros = (int*) malloc((MAX) * sizeof (int));
    if (!numeros) exit(EXIT_FAILURE);
    for (int i = MAX; i > 0; i--) {
        numeros[i] = MAX - i;
    }

    ////////////////////////////////////////////////////////////////////////////
    clock_t tInicio, tFim, tDecorrido;
    tInicio = clock();
    
    radixsort(numeros, MAX);
    
    tFim = clock();
    ////////////////////////////////////////////////////////////////////////////

    printf("\nDepois = [");
    for (int i = 0; i < MAX; i++) {
        printf(" %d,", numeros[i]);
    }
    printf("]");
    
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("\n%ld milissegundos", tDecorrido);

    return 0;

}