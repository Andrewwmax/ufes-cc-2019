//////////////////////////////////////////////////////
// 12345 = 8cb2237d0679ca88db6464eac60da96345513964 //
// A1B2C = 7b151de317f2547df39e1a1ff2850a6abfa6128f //
// 123ZZ = 230cdfcdb6f2aa33b7acf19edaae5a216a14155f //
// DCEL = b2cdbf0601d8ae90d3cda1c978566ace86c4eac0  //
// 99999 = a045b7efa463c6ed195c644163f4168952fbd34a //
/*	Command being timed: "./EP2 a045b7efa463c6ed195c644163f4168952fbd34a"
	User time (seconds): 1336.94
	System time (seconds): 0.16
	Percent of CPU this job got: 99%
	Elapsed (wall clock) time (h:mm:ss or m:ss): 22:17.69
	Average shared text size (kbytes): 0
	Average unshared data size (kbytes): 0
	Average stack size (kbytes): 0
	Average total size (kbytes): 0
	Maximum resident set size (kbytes): 3328
	Average resident set size (kbytes): 0
	Major (requiring I/O) page faults: 0
	Minor (reclaiming a frame) page faults: 123
	Voluntary context switches: 8
	Involuntary context switches: 13591
	Swaps: 0
	File system inputs: 0
	File system outputs: 0
	Socket messages sent: 0
	Socket messages received: 0
	Signals delivered: 0
	Page size (bytes): 4096
	Exit status: 0
*/
//////////////////////////////////////////////////////
// d27e086d60a993d203717509c46a6752daccc967 //
//////////////////////////////////////////////

#include <bits/stdc++.h> 
#include "sha1.h"
// #include "mpi.h"

using namespace std; 

int main(int argc, char *argv[]) {

	if (argc != 2) {
        fprintf(stderr, "usage: prog <SHA1>\n");
        exit(1);
    }
	
	const char *SENHA = argv[1];
	// char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%*";
	char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	char s1[2];
	s1[1] = '\0';
	#pragma omp parallel for
	for(int i = 0; i < strlen(caracteres); i++){
		s1[0] = caracteres[i];
		string CRIPT(sha1(s1));
		if(!CRIPT.compare(SENHA)){
			cout << s1 << " : " << CRIPT << endl;
			exit(0);
		}
	}
	printf("Não é de 1 caracter\n");

	char s2[3];
	s2[2] = '\0';
	#pragma omp parallel for
	for(int i = 0; i < strlen(caracteres); i++)
		for(int j = 0; j < strlen(caracteres); j++){
			s2[0] = caracteres[i];
			s2[1] = caracteres[j];
			string CRIPT(sha1(s2));
			if(!CRIPT.compare(SENHA)){
				cout << s2 << " : " << CRIPT << endl;
				exit(0);
			}
		}
	printf("Não é de 2 caracter\n");

	char s3[4];
	s3[3] = '\0';
	#pragma omp parallel for
	for(int i = 0; i < strlen(caracteres); i++)
		for(int j = 0; j < strlen(caracteres); j++)
			for(int k = 0; k < strlen(caracteres); k++){
				s3[0] = caracteres[i];
				s3[1] = caracteres[j];
				s3[2] = caracteres[k];
				string CRIPT(sha1(s3));
				if(!CRIPT.compare(SENHA)){
					cout << s3 << " : " << CRIPT << endl;
					exit(0);
				}
			}
	printf("Não é de 3 caracter\n");

	char s4[5];
	s4[4] = '\0';
	#pragma omp parallel for
	for(int i = 0; i < strlen(caracteres); i++)
		for(int j = 0; j < strlen(caracteres); j++)
			for(int k = 0; k < strlen(caracteres); k++)
				for(int l = 0; l < strlen(caracteres); l++){
					s4[0] = caracteres[i];
					s4[1] = caracteres[j];
					s4[2] = caracteres[k];
					s4[3] = caracteres[l];
					string CRIPT(sha1(s4));
					if(!CRIPT.compare(SENHA)){
						cout << s4 << " : " << CRIPT << endl;
						exit(0);
					}
				}
	printf("Não é de 4 caracter\n");

	char s5[6];
	s5[5] = '\0';
	#pragma omp parallel for
	for(int i = 0; i < strlen(caracteres); i++)
		for(int j = 0; j < strlen(caracteres); j++)
			for(int k = 0; k < strlen(caracteres); k++)
				for(int l = 0; l < strlen(caracteres); l++)
					for(int m = 0; m < strlen(caracteres); m++){
						s5[0] = caracteres[i];
						s5[1] = caracteres[j];
						s5[2] = caracteres[k];
						s5[3] = caracteres[l];
						s5[4] = caracteres[m];
						string CRIPT(sha1(s5));
						if(!CRIPT.compare(SENHA)){
							cout << s5 << " : " << CRIPT << endl;
							exit(0);
						}
					}
	printf("Não é de 5 caracter\n");

/*
	char ssPlus[7];
	ssPlus[6] = '\0';
	#pragma omp parallel for
	for(int i = 0; i < strlen(caracteres); i++)
		for(int j = 0; j < strlen(caracteres); j++)
			for(int k = 0; k < strlen(caracteres); k++)
				for(int l = 0; l < strlen(caracteres); l++)
					for(int m = 0; m < strlen(caracteres); m++)
						for(int n = 0; n < strlen(caracteres); n++){
							ssPlus[0] = caracteres[i];
							ssPlus[1] = caracteres[j];
							ssPlus[2] = caracteres[k];
							ssPlus[3] = caracteres[l];
							ssPlus[4] = caracteres[m];
							ssPlus[5] = caracteres[n];
							string CRIPT(sha1(ssPlus));
							if(!CRIPT.compare(SENHA)){
								cout << ssPlus << " : " << CRIPT << endl;
								exit(0);
							}
						}
	printf("Não é de 6 caracter\n");
*/	
   return 0;

}