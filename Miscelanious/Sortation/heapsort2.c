// C implementation of Heap Sort
#include <stdio.h>
#include <stdlib.h>

// A heap has current size and array of elements
typedef struct {
    int tam;
    int* array;
} MaxHeap;

// A utility function to swap to integers
void troca(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

// The main function to heapify a Max Heap. The function
// assumes that everything under given root (element at
// index idx) is already heapified
void heapMaximo(MaxHeap* maxHeap, int index){
    int maior = index;  // Initialize largest as root
    int esquerdo = (index << 1) + 1;  // left = 2*idx + 1
    int direito = (index + 1) << 1; // right = 2*idx + 2

    // See if left child of root exists and is greater than
    // root
    if (esquerdo < maxHeap->tam &&
        maxHeap->array[esquerdo] > maxHeap->array[maior])
        maior = esquerdo;

    // See if right child of root exists and is greater than
    // the largest so far
    if (direito < maxHeap->tam &&
        maxHeap->array[direito] > maxHeap->array[maior])
        maior = direito;

    // Change root, if needed
    if (maior != index)
    {
        troca(&maxHeap->array[maior], &maxHeap->array[index]);
        heapMaximo(maxHeap, maior);
    }
}

// A utility function to create a max heap of given capacity
MaxHeap* heapConstrutor(int *array, int tam){
    int i;
    MaxHeap* maxHeap = (MaxHeap*) malloc(sizeof(MaxHeap));
    maxHeap->tam = tam;   // initialize size of heap
    maxHeap->array = array; // Assign address of first element of array

    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    for (i = (maxHeap->tam - 2) / 2; i >= 0; --i)
        heapMaximo(maxHeap, i);
    return maxHeap;
}

// The main function to sort an array of given size
void heapSort(int* array, int tam){
    // Build a heap from the input data.
    MaxHeap* maxHeap = heapConstrutor(array, tam);

    // Repeat following steps while heap size is greater than 1.
    // The last element in max heap will be the minimum element
    while (maxHeap->tam > 1){
        // The largest item in Heap is stored at the root. Replace
        // it with the last item of the heap followed by reducing the
        // size of heap by 1.
        troca(&maxHeap->array[0], &maxHeap->array[maxHeap->tam - 1]);
        --maxHeap->tam;  // Reduce heap size

        // Finally, heapify the root of tree.
        heapMaximo(maxHeap, 0);
    }
}

// A utility function to print a given array of given size
void printArray(int* arr, int tam){
    int i;
    for (i = 0; i < tam; ++i)
        printf("%d ", arr[i]);
}

/* Driver program to test above functions */
int main(){
    int arr[] = {25,40,55,20,44,35,38,99,10,65,50};
    int tam = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, tam);

    printf("\nSorted array is \n");
    printArray(arr, tam);
    return 0;
}