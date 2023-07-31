#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

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

void merge(int *vet, int tam){
    mergesort(aMerge, 0, MAX);
}

int main(void) {
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