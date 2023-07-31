#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int help(int error){
	if(!error){
		printf ("Argumentos:\n\tSortation -f[funcao] -q[qtdnumeros] -o[arq] -r [rangeMin rangeMax]\n\tSortation --help");
		printf ("\n\t\tFuncao: radix,\n\t\t\t\tcounting,\n\t\t\t\tselection,\n\t\t\t\tbubble,\n\t\t\t\theap  obs. max -q[32729],\n\t\t\t\tinsertion,\n\t\t\t\tmerge,\n\t\t\t\tquick\n");
		printf ("\n\t\tQtdnumeros:\t(int*)+, default 100\tQuantidade de numeros a serem gerados\n\n");
		printf ("\n\t\tArq:\t\t[String]? default Null\tArquivo com os numeros a serem lidos, formato [(int*)+,(int*)*]\n\n");
		printf ("\n\t\tRangeMin & RangeMax: \t(int*)+ (int*)+ default 0\tIntervalo de geracao de numeros aleatorios\n\n");
		printf("\tEX: ./Sortation merge 1000\n\n");

	}
	else if(error == 1) printf ("\nFuncao: radix,\n\tcounting,\n\tselection,\n\tbubble,\n\theap  obs. max -q[32729],\n\tinsertion,\n\tmerge,\n\tquick\n");
	else if(error == 2) printf ("\nQtdnumeros:\t(int*)+, default 101\tQuantidade de numeros a serem gerados\n\n");
	else if(error == 3) printf ("\nArq:\t[String]? default Null\tArquivo com os numeros a serem lidos, formato [(int*)+,(int*)*]\n\n");
	else if(error == 4) printf ("\nRangeMin & RangeMax:\tIntervalo de geracao de numeros aleatorios, formato (int*)+ (int*)+\n\n");
	else help(0);

	exit(0);
}

typedef struct inArgs{
	int qtdnumeros = 101;
	int rangeMin = 0;
	int rangeMax = 0;
	char *sort;
	char *arq;
} tArgs;

int main(int argc, char** argv) {
	int qtdnumeros = 0, rangeMin = 0, rangeMax = 0, i = 1, achou = 0;
	char tam[10], arq[50];
	tArgs IN;
	if(argc == 1 || strcmp(argv[1], "--help") == 0) help(0);
	// if(strcmp(argv[1], "--help") == 0 || argc == 1) help(0); // Curto circuito, gera SegFault;
	else {
		if(argv[i][0] == '-' & argv[i][1] == 'f') {
			IN.sort = (char *) calloc(strlen(argv[i]) - 2, sizeof(char));
			strncpy(IN.sort, argv[i] + 2, strlen(argv[i]) - 2);
			printf("%s\n", IN.sort);
			i++;

			if(argv[i][0] == '-' & argv[i][1] == 'q' & argc > 1) {
				strncpy(tam, argv[i] + 2, strlen(argv[i]) - 2);
				IN.qtdnumeros = abs(atoi(tam));
				printf("%d\n", IN.qtdnumeros);
				if(argc >= i) i++;

				if(i < argc && argv[i][0] == '-' && argv[i][1] == 'r') {
					i++;
					if(i + 1 < argc && abs(atoi(argv[i])) > 0 && (abs(atoi(argv[i + 1])) > 0)) {
						IN.rangeMin = abs(atoi(argv[i]));
						printf("%d\n", IN.rangeMin);
						i++;
						IN.rangeMax = abs(atoi(argv[i]));
						printf("%d\n", IN.rangeMax);
					
					} else help(i);

				} else return 0;

			} else if(argv[i][0] == '-' & argv[i][1] == 'o' & i < argc) {
				IN.arq = (char *) calloc(strlen(argv[i]) - 2, sizeof(char));
				strncpy(IN.arq, argv[i] + 2, strlen(argv[i]) - 2);
				IN.arq[strlen(argv[i]) - 2] = '\0';
				printf("%s\n", IN.arq);

			} else help(i);
		} else help(i);
	}
	return true;
}

int mane(int argc, char** argv) {
	int qtdnumeros = 0, rangeMin = 0, rangeMax = 0;
	char sort[100], tam[100], arqentrada[100];
	// if(strcmp(argv[1], "--help") == 0){
	// } else
	if(strcmp(argv[1], "--help") == 0) return help(0);
	else {

		if(argv[1][0] == '-' && argv[1][1] == 'f') {
			strncpy(sort, argv[1]+2, strlen(argv[1]) - 2);
			printf("%s\n", sort);
		}
		
		if(argv[2][0] == '-' && argv[2][1] == 'q') {
			strncpy(tam, argv[2]+2, strlen(argv[2]) - 2);
			qtdnumeros = abs(atoi(tam));
			printf("%d\n", qtdnumeros);
		}
		
		if(argv[3][0] == '-' && argv[3][1] == 'o') {
			strncpy(arqentrada, argv[3]+2, strlen(argv[3]) - 2);
			arqentrada[strlen(argv[3]) - 2] = '\0';
			printf("%s\n", arqentrada);
		}

		if(argv[4][0] == '-' && argv[4][1] == 'r') {
			rangeMin = abs(atoi(argv[5]));
			printf("%d\n", rangeMin);
			rangeMax = abs(atoi(argv[6]));
			printf("%d\n", rangeMax);

		} 
	}
	return 0;
}