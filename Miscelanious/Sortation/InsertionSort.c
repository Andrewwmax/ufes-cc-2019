#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

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

int main(void) {
    int *aInsert = (int*) malloc((MAX) * sizeof (int));
    if (!aInsert) exit(EXIT_FAILURE);
    for (int i = MAX; i > 0; i--) {
        aInsert[i] = MAX - i;
    }

    ////////////////////////////////////////////////////////////////////////////
    clock_t tInicio, tFim, tDecorrido;
    tInicio = clock();
    
    insert(aInsert, MAX);
    
    tFim = clock();
    ////////////////////////////////////////////////////////////////////////////

    printf("\nDepois = [");
    for (int i = 0; i < MAX; i++) {
        printf(" %d,", aInsert[i]);
    }
    printf("]");
    
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("\n%ld milissegundos", tDecorrido);

    return 0;
}