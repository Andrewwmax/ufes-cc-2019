// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread EP1Seq.cpp -o EP1Seq

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()

#define DEBUG

vector<string> sVazadas, sVerificar, sEncontradas;

bool buscaElementoUnico(string ver){
	for (int j = 0; j < sVerificar.size(); j++)
		if(!ver.compare(sVerificar[j]))
			return true;
	return false;
}

void buscaElemento() {
	for (int i = 0; i < sVazadas.size(); i++)
		if(buscaElementoUnico(sVazadas[i]))
			sEncontradas.push_back(sVazadas[i]);
}

vector<string> lerSenhas(FILE *arq){
	vector<string> senhas;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) 
		senhas.push_back(senha);

	return senhas;
}

int main(int argc, char *argv[]) {
	auto inicio = timeNow();
	
	if (argc != 4) {
		fprintf(stderr, "Use: ./EP1Seq <threads> <sVazadas> <sVerificar>\n");
		exit(1);
	}
	
	FILE *arqVazadas = fopen(argv[2], "r");
	if (arqVazadas == NULL){
		puts("Erro Arquivo de Senhas VAZADAS");
		exit(0);
	}
	sVazadas = lerSenhas(arqVazadas);

	FILE *arqVerificar = fopen(argv[3], "r");
	if (arqVerificar == NULL){
		puts("Erro Arquivo de senhas VERIFICADAS");
		exit(0);
	}
	sVerificar = lerSenhas(arqVerificar);

	////////////////////////////////////////////////////////////////

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