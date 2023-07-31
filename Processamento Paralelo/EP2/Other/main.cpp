#include<bits/stdc++.h> 
#include "sha1.h"

using namespace std; 

int main() { 
	char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 

	char s[3];
	s[2] = '\0';
	for(int i = 0; i < strlen(caracteres); i++)
		for(int j = 0; j < strlen(caracteres); j++){
			s[0] = caracteres[i];
			s[1] = caracteres[j];
			cout << s << "\t" << sha1(s) << endl;
	   }

   return 0;
   }
