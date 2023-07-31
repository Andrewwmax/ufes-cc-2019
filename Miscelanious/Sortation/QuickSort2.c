#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define MIN 1
#define MAX 100000

void shuffle(int *array) {

    for (int i = MAX - MIN - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}

int separa(int v[], int p, int r) {
    int c = v[p], i = p + 1, j = r, t;
    while (/*A*/ i <= j) {
        if (v[i] <= c) ++i;
        else if (c < v[j]) --j;
        else {
            t = v[i];
            v[i] = v[j];
            v[j] = t;
            ++i;
            --j;
        }
    }
    // agora i == j+1                 
    t = v[p];
    v[p] = v[j];
    v[j] = t;
    return j;
}

void quicksort(int v[], int p, int r) {
    int j;
    if (p < r) {
        j = separa(v, p, r);
        quicksort(v, p, j - 1);
        quicksort(v, j + 1, r);
    }
}

int main() {
    
    srand(time(NULL));
    // int *numeros = (int*) malloc((MAX - MIN) * sizeof (int));
    // for (int i = 0; i < MAX - MIN; i++) {
    //     numeros[i] = i + MIN;
    // }
    // shuffle(numeros);
    
    // Pior caso ///////////////////
    int *numeros = (int*) malloc((MAX) * sizeof (int));
    if (!numeros) exit(EXIT_FAILURE);
    for (int i = MAX; i > 0; i--) {
        numeros[i] = MAX - i;
    }
    ////////////////////////////////

    // printf("\nAntes = [");
    // for (int i = 0; i < MAX; i++) {
    //     printf(" %d,", numeros[i]);
    // }
    // printf("]");

    clock_t tInicio, tFim, tDecorrido;
    ////////////////////////////////////////////////////////////////////////////
    tInicio = clock();
    quicksort(numeros, 0, MAX - MIN);
    tFim = clock();
    ////////////////////////////////////////////////////////////////////////////

    printf("\nDepois = [");
    for (int i = 0; i < MAX - MIN; i++) {
        printf(" %d,", numeros[i]);
    }
    printf("]");
    
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("\n%ld milissegundos", tDecorrido);

    return 0;
}