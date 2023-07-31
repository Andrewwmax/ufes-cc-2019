#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

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

int main(void) {
    int *aBubble = (int*) malloc(MAX * sizeof (int));
    if (!aBubble) exit(EXIT_FAILURE);
    for (int i = MAX; i > 0; i--) {
        aBubble[i] = MAX - i;
    }

//////////////////////////////////////////////////////////
    clock_t tInicio, tFim, tDecorrido;
    tInicio = clock();

    bubble(aBubble, MAX);

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