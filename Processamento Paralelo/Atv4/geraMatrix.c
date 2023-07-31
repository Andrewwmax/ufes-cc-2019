#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void marechalRandom(int tam, int lim){
	srand(time(NULL));
	printf("%d\n", tam);
	for (int v = 0; v < tam; ++v)
		for (int w = 0; w < tam; ++w)
			if(w == tam - 1) printf("%d\n", rand() % lim);
			else printf("%d ", rand() % lim);
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	int l = atoi(argv[2]);
	marechalRandom(n, l);
	return 0;
}