// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread EP1Paralel.cpp -o EP1Paralel

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()

#define DEBUG

int N, numThreads, ind;

vector<string> sVazadas, sVerificar, sEncontradas;
mutex mux;


bool buscaElementoUnico(string ver){
	for (int i = 0; i < sVerificar.size(); i++)
		if(!ver.compare(sVerificar[i]))
			return true;
	return false;
}

void buscaElemento(int ini, int fim) {
	for (int i = ini; i < fim; i++){
		if(buscaElementoUnico(sVazadas[i])){
			mux.lock();
			sEncontradas.push_back(sVazadas[i]);
			mux.unlock();
		}
	}
}

vector<string> lerSenhas(FILE *arq){
	vector<string> senhas;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) 
		senhas.push_back(senha);

	return senhas;
}

void execThread(){

	thread th[numThreads];
	ind = 0;

	for (int i = 0; i < numThreads; i++){
		int ini, fim;
		if (i == numThreads - 1){
			ini = ind;
			fim = N;
		} else {
			ini = ind;
			fim = ind + N / numThreads;
			ind += N / numThreads;
		}
		// cout << "INI = " << ini << ", FIM = " << fim << endl;

		th[i] = thread(buscaElemento, ini, fim);
	}
	
	for (int i = 0; i < numThreads; ++i) th[i].join();
}

int main(int argc, char *argv[]){
	auto inicio = timeNow();
	
	if (argc != 4) {
		fprintf(stderr, "Use: ./EP1Paralel <threads> <sVazadas> <sVerificar>\n");
		exit(1);
	}

	// se o numero de threads for 0,
	// assume-se o valor de threads natural do cpu;
	atoi(argv[1]) ? numThreads = atoi(argv[1]) : numThreads = thread::hardware_concurrency();
	
	FILE *arqVazadas = fopen(argv[2], "r");
	if (arqVazadas == NULL){
		puts("Erro Arquivo de Senhas VAZADAS");
		exit(0);
	}
	sVazadas = lerSenhas(arqVazadas);

	N = sVazadas.size();

	FILE *arqVerificar = fopen(argv[3], "r");
	if (arqVerificar == NULL){
		puts("Erro Arquivo de senhas VERIFICADAS");
		exit(0);
	}
	sVerificar = lerSenhas(arqVerificar);

	////////////////////////////////////////////////////////////////

	execThread();

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

