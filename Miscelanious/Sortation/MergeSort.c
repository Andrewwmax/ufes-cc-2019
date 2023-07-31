#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void intercala(int v[], int inicio, int meio, int fim) {
    /* intercalação no vetor temporário auxiliar */
    int i, j, k, *auxiliar;
    auxiliar = (int *) calloc(sizeof (int), fim - inicio + 1);
    i = inicio;
    j = meio + 1;
    k = 0;
    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            auxiliar[k] = v[i];
            i++;
        } else {
            auxiliar[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= meio) {
        auxiliar[k] = v[i];
        i++;
        k++;
    }
    while (j <= fim) {
        auxiliar[k] = v[j];
        j++;
        k++;
    }
    /* copia vetor intercalado para o vetor original */
    for (i = 0; i < (fim - inicio) + 1; i++) {
        v[inicio + i] = auxiliar[i];
    }
    free(auxiliar);
    return;
}
void mergesort(int v[], int inicio, int fim) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergesort(v, inicio, meio);
        mergesort(v, meio + 1, fim);
        intercala(v, inicio, meio, fim);
    }
    return;
}

int main() {
    int *aMerge = (int*) malloc((MAX) * sizeof (int));
    if (!aMerge) exit(EXIT_FAILURE);
    for (int i = MAX; i > 0; i--) {
        aMerge[i] = MAX - i;
    }

    ////////////////////////////////////////////////////////////////////////////
    clock_t tInicio, tFim, tDecorrido;
    tInicio = clock();
    
    mergesort(aMerge, 0, MAX);
    
    tFim = clock();
    ////////////////////////////////////////////////////////////////////////////

    printf("\nDepois = [");
    for (int i = 0; i < MAX; i++) {
        printf(" %d,", aMerge[i]);
    }
    printf("]");
    
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("\n%ld milissegundos", tDecorrido);

    return 0;
}