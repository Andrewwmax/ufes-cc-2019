// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread EP1BSTSeq.cpp -o EP1BSTSeq

#include <iostream>
#include <vector>
#include <chrono>
#include <bits/stdc++.h> 

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()

#define DEBUG

mutex mux;
vector<string> sVazadas, sVerificar, sEncontradas;

vector<string> lerSenhas(FILE *arq){
	vector<string> senhas;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) 
		senhas.push_back(senha);

	return senhas;
}

bool BSTIterativa(int tamanho, string ver) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (!ver.compare(sVazadas[meio])) return true;
        else if (ver.compare(sVazadas[meio]) > 0) inicio = meio + 1;
        else fim = meio - 1;
	}
	return false;
}

bool BSTRecursiva(int inicio, int fim, string ver) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (!ver.compare(sVazadas[meio])) return true;
        else if (ver.compare(sVazadas[meio]) > 0) 
            return BSTRecursiva(meio + 1, fim, ver);
        else return BSTRecursiva(inicio, meio - 1, ver);
    }
    return false;
}

void buscaElemento() {
	for (int i = 0; i < sVerificar.size(); i++)
		// if(BSTIterativa(sVazadas.size(), sVerificar[i]))
		if(BSTRecursiva(0, sVazadas.size(), sVerificar[i]))
			sEncontradas.push_back(sVerificar[i]);
}

int main(int argc, char *argv[]){
	auto inicio = timeNow();

	if (argc != 4) {
		fprintf(stderr, "Use: ./EP1BSTSeq <threads> <Vazadas> <Verificar>\n");
		exit(1);
	}

	FILE *arqVerificar = fopen(argv[3], "r");
	if (arqVerificar == NULL){
		puts("Erro Arquivo de senhas VERIFICADAS");
		exit(0);
	}
	sVerificar = lerSenhas(arqVerificar);

	FILE *arqVazadas = fopen(argv[2], "r");
	if (arqVazadas == NULL){
		puts("Erro Arquivo de Senhas VAZADAS");
		exit(0);
	}
	sVazadas = lerSenhas(arqVazadas);

	////////////////////////////////////////////////////////////////
	
	sort(sVazadas.begin(), sVazadas.end());
	sort(sVerificar.begin(), sVerificar.end());

	buscaElemento();
	
	////////////////////////////////////////////////////////////////

	#ifdef DEBUG

		cout << "Encontramos " << sEncontradas.size() << " senhas, sendo elas: " << endl;
		for (int i = 0; i < sEncontradas.size(); i++) cout << "\t" << sEncontradas[i] << endl;

	#endif

	auto fim = timeNow();
	cout << duration(fim - inicio) / 1000.f << flush;
	// cout << "Tempo gasto: " << duration(fim - inicio) / 1000.f << " ms\n" << flush;

	return 0;
}

