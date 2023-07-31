// hash example
#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>


using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()

#define DEBUG

unordered_map<string, unsigned long long int> sVazadas;
vector<string> sVerificar, sEncontradas;
mutex mux;

unordered_map<string, unsigned long long int> lerSenhasVazadas(FILE *arq){

	unordered_map<string, unsigned long long int> senhas;
	hash<string> senhaHash;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) {
		string s(senha);
		senhas[s] = senhaHash(s);
	}

	return senhas;
}

vector<string> lerSenhasVerificar(FILE *arq){
	
	vector<string> senhas;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) 
		senhas.push_back(senha);

	return senhas;
}

void buscaElemento() {
	hash<string> senhaHash;
	for (int j = 0; j < sVerificar.size(); j++){
		string s(sVerificar[j]);
		if(!(sVazadas.find(s) == sVazadas.end()))
			sEncontradas.push_back(sVerificar[j]);
	}
}

int main(int argc, char *argv[]){
	auto inicio = timeNow();

	if (argc != 4) {
		fprintf(stderr, "Use: ./EP1Hash <threads> <Vazadas> <Verificar>\n");
		exit(1);
	}

	FILE *arqVerificar = fopen(argv[3], "r");
	if (arqVerificar == NULL){
		puts("Erro Arquivo de senhas VERIFICADAS");
		exit(0);
	}
	sVerificar = lerSenhasVerificar(arqVerificar);
	

	FILE *arqVazadas = fopen(argv[2], "r");
	if (arqVazadas == NULL){
		puts("Erro Arquivo de Senhas VAZADAS");
		exit(0);
	}
	sVazadas = lerSenhasVazadas(arqVazadas);
	
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

