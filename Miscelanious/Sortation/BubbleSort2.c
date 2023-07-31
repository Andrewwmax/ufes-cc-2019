#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void bubble2(int piItem[], int iQtdElementos) {
	register int i, j;
	register int iAux;
	bool bTroca;
	for (i = 1; i < iQtdElementos; i++) {
		bTroca = 0; /* falso */
		for (j = iQtdElementos - 1; j >= i; j--) {
			if (piItem[j - 1] > piItem[j]) {
				iAux = piItem[j - 1];
				piItem[j - 1] = piItem[j];
				piItem[j] = iAux;
				bTroca = 1; /* verdadeiro */
			}
		}
		if (!bTroca) return;
	} return;
}

int main(void) {

	int *aBubble = (int*) malloc(MAX * sizeof (int));
	if (!aBubble) exit(EXIT_FAILURE);
	for (int i = MAX; i > 0; i--) {
		aBubble[i] = MAX - i;
	}


	printf("Antes da Ordenação:[");
	for (int i = 0; i < MAX; i++) {
		printf(" %d,", aBubble[i]);
	}
	printf("]\n");

	//////////////////////////////////////////////////////////
    clock_t tInicio, tFim, tDecorrido;
    tInicio = clock();

	bubble2(aBubble, MAX);

    tFim = clock();
	///////////////////////////////////////////////////////////	
	
	printf("\n\nDepois da Ordenação:\n[");
	for (int i = 0; i < MAX; i++) {
		printf(" %d, ", aBubble[i]);
	}
	printf("]\n");

    printf("\n%ld milissegundos", ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000)));
	return 0;
}