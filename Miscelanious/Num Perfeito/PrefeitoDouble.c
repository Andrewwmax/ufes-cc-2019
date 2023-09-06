#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int ehPerfeito(double n) {
    double sum = 1; 
    for(int i = 2; i * i <= n; i++)
        if (/*n % i*/ fmod(n, i) == 0) sum = sum + i + (n / i);
    
    if(sum == n && n != 1)
        return 1;

    return 0; 
}

int main() {
    double sum;
    // Limite de 2^32, dos long long int, ja testei; cerca de 30 segs no meu pc;
    for (int n = 2; n < 20; n++) {
        
        // funcao geradora, por:
        // https://en.wikipedia.org/wiki/Euclid%E2%80%93Euler_theorem 
        // &&
        // https://en.wikipedia.org/wiki/Perfect_number
        sum = 1 + ((pow(2, n) - 2) * (pow(2, n) + 1) / 2);
    
        // printf("%.f\n", sum);
        // funcao que valida se o numero e perfeito
        if (ehPerfeito(sum)) printf("N = %d, Eh Perfeito: %.f\n", n, sum);
    }

    return 0; 
}

/*
Numero Perfect: 6
Numero Perfect: 28
Numero Perfect: 496
Numero Perfect: 8128
Numero Perfect: 33550336
Numero Perfect: 8589869056
Numero Perfect: 137438691328
Numero Perfect: 2305843008139952128
//Extrapola o LONG INT
Numero Perfect: 2658455991569831744654692615953842176
Numero Perfect: 191561942608236107294793378084303638130997321548169216
*/