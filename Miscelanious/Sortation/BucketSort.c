#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000 //maximo

typedef struct {
    int topo;
    int balde[MAX];
} bucket;

void bubble(int v[], int tam) {
    int i, j, temp, flag;
    if (tam)
        for (j = 0; j < tam - 1; j++) {
            flag = 0;
            for (i = 0; i < tam - 1; i++) {
                if (v[i + 1] < v[i]) {
                    temp = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = temp;
                    flag = 1;
                }
            }
            if (!flag) break;
        }
}

void bucket_sort(int v[], int tam) {
    bucket b[MAX];
    int i, j, k;
    for (i = 0; i < MAX; i++) //inicializa todos os "topo"
        b[i].topo = 0;

    for (i = 0; i < tam; i++) { //verifica em que balde o elemento deve ficar
        j = (tam) - 1;
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

    for (i = 0; i < tam; i++)//ordena os baldes
        if (b[i].topo) 
            bubble(b[i].balde, b[i].topo);
    i = 0;
    for (j = 0; j < tam / 10; j++) { //põe os elementos dos baldes de volta no vetor
        for (k = 0; k < b[j].topo; k++) {
            v[i] = b[j].balde[k];
            //printf("%d, ", v[i]);
            i++;
        }
        //printf("\n");
    }
}

int main() {
    int *aBucket = (int*) malloc((MAX) * sizeof(int));
    if (!aBucket) exit(EXIT_FAILURE);
    for (int i = MAX -1; i > 0; i--) {
        aBucket[i] = MAX - i;
    }

    ////////////////////////////////////////////////////////////////////////////
    clock_t tInicio, tFim, tDecorrido;
    tInicio = clock();
    
    bucket_sort(aBucket, MAX);
    
    tFim = clock();
    ////////////////////////////////////////////////////////////////////////////

    printf("\nDepois = [");
    for (int i = 0; i < MAX; i++) {
        printf(" %d,", aBucket[i]);
    }
    printf("]");
    
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("\n%ld milissegundos", tDecorrido);

    return 0;
}