// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread EP1BST.cpp -o EP1BST

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <bits/stdc++.h> 

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()

#define DEBUG

int N, numThreads, ind;
mutex mux;
vector<string> sVazadas, sVerificar, sEncontradas;

////////////////////////////////////////////////////////////////////
// Com estrutura de arvore

/*
node *sVazadas = nullptr;

struct node {
   string val;
   node* left;
   node* right;
};

node* createNewNode(string x) {
	node* nn = new node;
	nn->val = x;
	nn->left  = nullptr;
	nn->right = nullptr;

	return nn;
}

void bstInsert(node* &root, string x) {
	if(root == nullptr) {
		root = createNewNode(x);
		return;
	}

	if(x.compare(root->val) < 0) {
		if(root->left == nullptr) {
			root->left = createNewNode(x);
			return;
		} else bstInsert(root->left, x);
	}

	if(x.compare(root->val) > 0) {
		if(root->right == nullptr) {
			root->right = createNewNode(x);
			return;
		} else bstInsert(root->right, x);
	}
}

bool busca(node *root, string x){
    if(root == NULL) return false;
    else if(x.compare(root->val) < 0) return busca(root->left, x);
    else if(x.compare(root->val) == 0) return true;
    else if(x.compare(root->val) > 0) return busca(root->right, x);
    else return false;
}

vector<string> lerSenhasVerificar(FILE *arq){
	vector<string> senhas;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) 
		senhas.push_back(senha);

	return senhas;
}

node *lerSenhasVazadas(FILE *arq){
	node *senhas = nullptr;
	char *senha = (char *) calloc(50, sizeof(char));
	
	while(EOF != fscanf(arq, "%s", senha)){
		//cout << senha << endl;
		bstInsert(senhas, senha);
	}

	return senhas;
}

void buscarSenha(){
	for (unsigned int i = 0; i < sVerificar.size(); i++){
		//cout << sVerificar[i] << endl;
		if(busca(sVazadas, sVerificar[i])) {
			sEncontradas.push_back(sVerificar[i]);
		}
	}
}
*/

////////////////////////////////////////////////////////////////////
// Com Vetor

vector<string> lerSenhas(FILE *arq){
	vector<string> senhas;
	char *senha = (char *) calloc(50, sizeof(char));

	while(EOF != fscanf(arq, "%s", senha)) 
		senhas.push_back(senha);

	return senhas;
}

bool BSTIterativa(int ini, int fim, string ver) {
    int inicio = ini;
    int final = fim - 1;
    int meio;

    while (inicio <= final) {
        meio = (inicio + final) / 2;
        if (!ver.compare(sVazadas[meio])) return true;
        else if (ver.compare(sVazadas[meio]) > 0) inicio = meio + 1;
        else final = meio - 1;
	}
	return false;
}

bool BSTRecursiva(int ini, int fim, string ver) {
    if (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (!ver.compare(sVazadas[meio])) return true;
        else if (ver.compare(sVazadas[meio]) > 0) 
            return BSTRecursiva(meio + 1, fim, ver);
        else return BSTRecursiva(ini, meio - 1, ver);
    }
    return false;
}

void buscaElemento(int ini, int fim) {
	// printf("TID: %ld\n", this_thread::get_id());
	for (int i = 0; i < sVerificar.size(); i++){
		if(BSTIterativa(ini, fim, sVerificar[i])){
		// if(BSTRecursiva(ini, fim, sVerificar[i])){
			mux.lock();
			sEncontradas.push_back(sVerificar[i]);
			mux.unlock();
		}
	}
}

void execThread(){

	thread th[numThreads];
	ind = 0;

	sort(sVazadas.begin(), sVazadas.end());
	// sort(sVerificar.begin(), sVerificar.end());
	
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
		fprintf(stderr, "Use: ./EP1BST <threads> <Vazadas> <Verificar>\n");
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
	
	// sort(sVazadas.begin(), sVazadas.end());
	// sort(sVerificar.begin(), sVerificar.end());

	// execThread();
	thread th[numThreads];
	ind = 0;

	sort(sVazadas.begin(), sVazadas.end());
	sort(sVerificar.begin(), sVerificar.end());
	
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

