#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int ehPerfeito(unsigned long long int n) {
    unsigned long long int sum = 1; 
	// #pragma omp parallel for num_threads(4)
    for(unsigned long long int i = 2; i * i <= n; i++)
        if (n % i == 0) sum = sum + i + (n / i);
	
	if(sum == n && n != 1)
		return 1;

	return 0; 
} 

int main() {
	unsigned long long int sum;
	// Limite de 2^32, dos long long int, ja testei; cerca de 30 segs no meu pc;
	#pragma omp parallel for num_threads(4)

	for (int n = 2; n < 32; n++) {
		// funcao geradora, por:
		// https://en.wikipedia.org/wiki/Euclid%E2%80%93Euler_theorem 
		// &&
		// https://en.wikipedia.org/wiki/Perfect_number
		sum = 1 + ((pow(2, n) - 2) * (pow(2, n) + 1) / 2);
	
		// printf("%lld\n", sum);
		// funcao que valida se o numero e perfeito
		if (ehPerfeito(sum)) printf("%d - Eh Perfeito: %lld\n", n, sum);
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
//Extrapola o UNSIGNED LONG LONG INT
Numero Perfect: 2658455991569831744654692615953842176
Numero Perfect: 191561942608236107294793378084303638130997321548169216

O 'N' que representa o numero
	2
	3
	5
	7
	13
	17
	19
	31

*/