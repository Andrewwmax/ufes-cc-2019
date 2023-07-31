#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <sys/time.h>
#include <time.h>

double MyClock() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000) + tv.tv_usec;
}

int ehPerfeito(unsigned long long int n) {
    unsigned long long int sum = 1; 
    for(unsigned long long int i = 2; i * i <= n; i++)
        if (n % i == 0) sum = sum + i + (n / i);
	
	if(sum == n && n != 1)
		return 1;

	return 0; 
} 

int main(int argc, char *argv[]){
	if (argc != 2) {
		fprintf(stderr, "Use: NumPerfeito < N >\n");
		exit(1);
	}

	int N = atoi(argv[1]);
    unsigned long long int sum = 1 + ((pow(2, N) - 2) * (pow(2, N) + 1) / 2);

	double inicio = MyClock();

	if(ehPerfeito(sum))
		printf("%lld ehPerfeito, tempo de cálculo %.10lf segs\n", sum, (MyClock() - inicio) / CLOCKS_PER_SEC);
	else return 0;
}