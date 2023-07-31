#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define RANGE 10// p/ String
#define MAX 1000000

void countSortSTR(char arr[]) {
    // The output character array that will have sorted arr
    char output[strlen(arr)];

    // Create a count array to store count of inidividul
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof (count));

    // Store count of each character
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    // Build the output character array
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
    // Driver program to test above function
}

/*
int maximum(int *array, int size){
  int aux = 0;
  int max = 0;

  for(aux = 0; aux < size; aux++)
    if(array[aux] > max) 
        max = array[aux];
  return max;
}
*/

// Um vetor A indexado a partir da posição 1 e que possui tamanho N 
// N = número de elementos a serem ordenados;
// Um vetor B que é usado para guardar a sequência ordenada;
// Um vetor C, de tamanho K 
// K = tamanho do intervalo de valores do vetor A, que é usado como memória temporária;

void counting(int *A, int n/*, int *B, int *C, int k*/){
    int i, B[n], C[n];

    for(i = 0; i < n; i++) C[A[i]-1]++;         //Passo 1
        
    for(i = 1; i < n; i++) C[i] += C[i - 1];    //Passo 2

    for(i = n - 1; i >= 0; i--) {               //Passo 3
        B[C[A[i] - 1] - 1] = A[i];
        C[A[i] - 1]--;
    }

    for(i = 0; i < n; i++) {                    //Passo 4
        A[i] = B[i];
    }
}

int main() {
    // char arr[] = "geeksforgeekshghfdfsdryyghhgchfdxyuhiugychfgdxygukjhjdtfyp";
    int *aCounting = (int*) malloc(MAX * sizeof (int));
    // int *bCounting = (int*) malloc(MAX * sizeof (int));
    // int *cCounting = (int*) malloc(MAX * sizeof (int));
    if (!aCounting) exit(EXIT_FAILURE);
    // if (!bCounting) exit(EXIT_FAILURE);
    // if (!cCounting) exit(EXIT_FAILURE);
    for (int i = MAX; i >= 0; i--) {
        aCounting[i] = MAX - i;
    }
    ////////////////////////////////////////////////////////////////////////////
    clock_t tInicio, tFim, tDecorrido;
    tInicio = clock();
    
    counting(aCounting, MAX/*, bCounting, cCounting, MAX*/);
    
    tFim = clock();
    ////////////////////////////////////////////////////////////////////////////

    printf("\nDepois = [");
    for (int i = 0; i < MAX; i++) {
        printf(" %d,", aCounting[i]);
    }
    printf("]");
    
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("\n%ld milissegundos", tDecorrido);

    //countSort(arr);
    // printf("Sorted character array is %d n", aCounting[0]);
    return 0;
}