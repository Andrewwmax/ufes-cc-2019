#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

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

int main(void) {
	int *aSelect = (int*) malloc((MAX) * sizeof (int));
	if (!aSelect) exit(EXIT_FAILURE);
	for (int i = MAX; i > 0; i--) {
		aSelect[i] = MAX - i;
	}

	////////////////////////////////////////////////////////////////////////////
	clock_t tInicio, tFim, tDecorrido;
	tInicio = clock();
	
	selection(aSelect, MAX);
	
	tFim = clock();
	////////////////////////////////////////////////////////////////////////////

	printf("\nDepois = [");
	for (int i = 0; i < MAX; i++) {
		printf(" %d,", aSelect[i]);
	}
	printf("]");
	
	tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
	printf("\n%ld milissegundos", tDecorrido);

	return 0;
}
