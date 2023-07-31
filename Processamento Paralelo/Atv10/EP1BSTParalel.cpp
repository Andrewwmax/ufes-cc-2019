// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread EP1BST.cpp -o EP1BST

#include <iostream>
#include <vector>
#include <functional>
#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

// #define DEBUG

int N, numThreads, ind;

vector<long double> sVazadas, sVerificar, sEncontradas;
vector<string> sPrint;
// vector<unsigned long long int> sVazadas, sVerificar, sEncontradas;

vector<long double> lerSenhasINT(FILE *arq){
	vector<long double> senhas;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) {
		char *senhaConvert = (char *) calloc(50, sizeof(char));
		strcpy(senhaConvert, "0x");
		strcat(senhaConvert, senha);
		// printf("%s\n", senhaConvert);
		long double k = strtold(senhaConvert, NULL);
		// printf("%Lf\n", k);
		senhas.push_back(k);
	}
	return senhas;
}

vector<string> AdicionaSenhas(FILE *arq){
	vector<string> senhas;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) {
		char *senhaConvert = (char *) calloc(50, sizeof(char));
		strcpy(senhaConvert, "0x");
		strcat(senhaConvert, senha);
		// printf("%s\n", senhaConvert);
		long double k = strtold(senhaConvert, NULL);
		for (unsigned int i = 0; i < sEncontradas.size(); ++i){
			if(sEncontradas[i] == k){
				// printf("%.0Lf\n", sEncontradas[i]);
				senhas.push_back(senha);
			}
		}
	}

	return senhas;
}

bool BSTIterativaINT(/*unsigned long long int*/long double ver) {
    int inicio = 0;
    int final = sVazadas.size() - 1;
    int meio;

    while (inicio <= final) {
        meio = (inicio + final) / 2;
        if (ver == sVazadas[meio]) return true;
        else if (ver > sVazadas[meio]) inicio = meio + 1;
        else final = meio - 1;
	}
	return false;
}


int main(int argc, char *argv[]){

	if (argc != 4) {
		fprintf(stderr, "Use: ./EP1BST <threads> <Vazadas> <Verificar>\n");
		exit(1);
	}

	// se o numero de threads for 0,
	// assume-se o valor de threads natural do cpu;
	atoi(argv[1]) ? numThreads = atoi(argv[1]) : numThreads = omp_get_num_threads();

	FILE *arqVazadas = fopen(argv[2], "r");
	if (arqVazadas == NULL){
		puts("Erro Arquivo de Senhas VAZADAS");
		exit(0);
	}
	sVazadas = lerSenhasINT(arqVazadas);

	N = sVazadas.size();

	FILE *arqVerificar = fopen(argv[3], "r");
	if (arqVerificar == NULL){
		puts("Erro Arquivo de senhas VERIFICADAS");
		exit(0);
	}
	sVerificar = lerSenhasINT(arqVerificar);
	int K = sVerificar.size();

	fclose(arqVerificar);
	////////////////////////////////////////////////////////////////
	
	sort(sVazadas.begin(), sVazadas.end());
	sort(sVerificar.begin(), sVerificar.end());

	#pragma omp parallel for num_threads(numThreads)
	for (int i = 0; i < K; i++){
		if(binary_search(sVazadas.begin(), sVazadas.end(), sVerificar[i])) {
			#pragma omp critical
			sEncontradas.push_back(sVerificar[i]);
		}
	}

	////////////////////////////////////////////////////////////////

	#ifdef DEBUG
		
		arqVerificar = fopen(argv[3], "r");
		sPrint = AdicionaSenhas(arqVerificar);
		cout << "Encontramos " << sPrint.size() << " senhas, sendo elas: " << endl;
    	cout << fixed << setprecision(0);
		for (unsigned int i = 0; i < sPrint.size(); i++) cout << "\t" << sPrint[i] << endl;

	#endif

	return 0;
}