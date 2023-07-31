#!/bin/bash
#
# Comandos básicos para o job
#$ -cwd
#$ -j y
#$ -S /bin/bash

# Nome do job
#$ -N Andre

#Número de cpus/núcleos usados (12)
#$ -pe orte 8

# Redirecting standard output error to files
# named "output" and "errors"
#$ -o output_par.txt
#$ -e errors_par.txt


#Comando que será executado (EP1 é o nome do programa)
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 86f7e437faa5a7fce15d1ddcb9eaeaea377667b8 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 6b0d31c0d563223024da45691584643ac78c96e8 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 395df8f7c51f007019cb30201c49e884b46b92fa >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 e0184adedf913b076626646d3f52c3b49c39ad6d >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 6dcd4ce23d88e2ee9568ba546c007c63d9131c1b >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 c63ae6dd4fc9f9dda66970e827d13f7c73fe841c >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 909f99a779adb66a76fc53ab56c7dd1caf35d0fd >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 b6589fc6ab0dc82cf12099d1c2d40ab994e8410c >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 0ade7c2cf97f75d009975f4d720d1fa6c19f4897 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 e0c9035898dd52fc65c41454cec9c4d2611bfb37 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 b8d09b4d8580aacbd9efc4540a9b88d2feb9d7e5 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 d7dacae2c968388960bf8970080a980ed5c5dcb7 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 1a8aea63b8211aafabd118db0572a13810d234ff >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 801c34269f74ed383fc97de33604b8a905adb635 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 4a3a8927b85daa16f0fe11b6bbb759eee3095858 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 d308e0b2d36c5d2420869c6bf112e31e8d5b0d52 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 fb96549631c835eb239cd614cc6b5cb7d295121a >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 9a79be611e0267e1d943da0737c6c51be67865a0 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 7e240de74fb1ed08fa08d38063f6a6a91462a815 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 91223fd10ce86fc852b449583aa2196c304bf6e0 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 40fa37ec00c761c7dbb6ebdee6d4a260b922f5f4 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 7c2fa47687b3791bc61bbe6933fabab1d786a9b4 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 606ec6e9bd8a8ff2ad14e5fade3f264471e82251 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 251f18d4e6b31f7e8ee5bbc62db713101e85a8c9 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 116ff222a3b49b63348d7782e4b43ffe2dcbb198 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 8aefb06c426e07a0a671a1e2488b4858d694a730 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 afc97ea131fd7e2695a98ef34013608f97f34e1d >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 6b942e2831f972c22e2b0292ea3a8176ab41cd3b >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 cc9db3a795571c7e71f45670a1da7ff49b5f1557 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 70c881d4a26984ddce795f6f71817c9cf4480e79 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 1efcfaab69361232b5e5e39265464be84f6e484f >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 cb990257247b592eaaed54b84b32d96b7904fd95 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 c49c34e2014a2da270eeae07d730726ffddd3196 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 e2512172abf8cc9f67fdd49eb6cacf2df71bbad3 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 2f5005d0e6ce2fb551cb5f2bdb9740a5ca7c28db >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 9865d483bc5a94f2e30056fc256ed3066af54d04 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 39dfa55283318d31afe5a3ff4a0e3253e2045e43 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 4170ac2a2782a1516fe9e13d7322ae482c1bd594 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 f56fe68c0a0ae4ee32e66f54df90db08ad4334eb >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 9f2feb0f1ef425b292f2f94bc8482494df430413 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 9d4e1e23bd5b727046a9e3b4b7db57bd8d6ee684 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 bf5afc18dfbca6ff28e36ac47bda8ab40d47c990 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 25ef54533baa49d7cc4e64d478ecd1d2fd55d761 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 df51e37c269aa94d38f93e537bf6e2020b21406c >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 24d3c6fe567c74749a2534b1ca2bd3d611528e27 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 a2b7caddbc353bd7d7ace2067b8c4e34db2097a3 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 c1fe3a7b487f66a6ac8c7e4794bc55c31b0ef403 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 af660090b01149c4cd9581bca5e30ceaacc675be >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 51e8087c726748d21d04753b342826154c269d69 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 f888fa8a61ba9a53a45f040a4bbb8b2fc1f64444 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 6934105ad50010b814c933314b1da6841431bc8b >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 a045b7efa463c6ed195c644163f4168952fbd34a >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 348162101fc6f7e624681b7400b085eeac6df7bd >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 8fe670fef2b8c74ef8987cdfccdb32e96ad4f9a2 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 43d4f12195d1badef1cc499d9b2756f69cccdc5b >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 d033e22ae348aeb5660fc2140aec35850c4da997 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 8d5004c9c74259ab775f63f7131da077814a7636 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 31039edaddb33cff8a061ed0a3a3ba4d8515b886 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 c95259de1fd719814daef8f1dc4bd64f9d885ff0 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 04a4fce796c2cf39c53220ec3b8e22e3b2f24615 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 7751a23fa55170a57e90374df13a3ab78efe0e99 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 bcd4262b2d08176dd257fe243388194b69517378 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 f024f8f5635ba8e56a175a884fa323d39ca01f04 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 f7a9e24777ec23212c54d7a350bc5bea5477fdbb >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 cecec3ec436bf58a4ecce3e179835e25ff691f3e >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 984ff6ee7c78078d4cb1ca08255303fb8741d986 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 2d2929e0f1bca99d9652924ce73b7969d33ff429 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 8a1d9b464a3fd8c9e5f06af5b43005029d7c16b1 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 3d486f74b9975ec5b707ad03897c3d8e1f998dd9 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 18f30f1ba4c62e2b460e693306b39a0de27d747c >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 c984aed014aec7623a54f0591da07a85fd4b762d >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 1f5523a8f535289b3401b29958d01b2966ed61d2 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 4b288f73587b1db7700c9661ce011e3b92b36443 >>SaidaTestes.txt
env time -f "%C\n\tTempo de Execução: %e\n\tMemória usada: %M\n\tCPU usada: %P\n" -o SaidaTestes.txt -a mpirun -np 8 -quiet EP2 db278aa2cc708f2163a08987ac289a979430611f >>SaidaTestes.txt
