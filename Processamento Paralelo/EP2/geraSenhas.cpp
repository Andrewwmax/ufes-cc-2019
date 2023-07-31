#include <bits/stdc++.h> 
#include "sha1.h" 
using namespace std; 

int main(int argc, char *argv[]) {

    const char *SENHA = argv[1];
    cout << /*SENHA << " : " << */sha1(SENHA) << endl;
	
	// Retirar os 10 primeiros digitos

    // string s(sha1(SENHA));
    // s.

    return 0; 
} 
