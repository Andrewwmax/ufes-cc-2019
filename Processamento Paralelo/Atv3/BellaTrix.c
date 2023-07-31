#include <stdio.h>

int max = 3;

int main() {
    
    int mat1[max][max], mat2[max][max], result[max][max], i, j;
    
    for(i = 0; i < max; i++){
        for(j = 0; j < max; j++){
            mat1[i][j] = 2;
            mat2[i][j] = 4;
            result[i][j] = 0;
        }
    }

    printf("\nMatrix Resultado:\n");
    for(i = 0; i < max; i++) {
        for(j = 0; j < max; j++) {
            for (int k = 0; k < max; k++) {
                result[i][j] = result[i][j] + (mat1[i][k] * mat2[k][j]);
            }
            printf("%4d, ", result[i][j]);
        }
        printf("\n");
    }
} 