#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#
 
# g++ EP1Original.cpp -o Ep1Original &&
# g++ EP1Sequencial.cpp -o EP1Sequencial && 
# g++ EP1Paralelo.cpp -o EP1Paralelo && 
# g++ EP1ParaleloList.cpp -o EP1ParaleloList
# [Finished in 2406.5s]

g++ -O3 -lrt EP1Original.cpp -o Ep1Original &&
g++ -O3 -lrt EP1Sequencial.cpp -o EP1Sequencial && 
g++ -O3 -lrt EP1Paralelo.cpp -o EP1Paralelo && 
g++ -O3 -lrt EP1ParaleloList.cpp -o EP1ParaleloList
# [Finished in 1690.6s]

numExec=2

tamLista="100 1000 10000 100000 1000000 10000000 50000000"
#7 testes

echo "EP1Original.cpp"
printf "\nEP1Original = [" >>Saida.txt
for N in $tamLista
do
	echo "N = "$N
	
	printf "\n["  >>Saida.txt
	for (( i=1; i<numExec; i++ ))
	do
		# printf "\n["  >>Saida.txt
		./EP1Original $N >>Saida.txt
		printf ", "  >>Saida.txt
		# printf "],"  >>Saida.txt
	done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt

echo "EP1Sequencial.cpp"
printf "\nEP1Sequencial = [" >>Saida.txt
for N in $tamLista
do
	echo "N = "$N
	
	printf "\n["  >>Saida.txt
	for (( i=1; i<numExec; i++ ))
	do
		# printf "\n["  >>Saida.txt
		./EP1Sequencial $N >>Saida.txt
		printf ", "  >>Saida.txt
		# printf "],"  >>Saida.txt
	done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt

echo "EP1Paralelo.cpp"
printf "\nEP1Paralelo = [" >>Saida.txt
for N in $tamLista
do
	echo "N = "$N
	
	printf "\n["  >>Saida.txt
	for (( i=1; i<numExec; i++ ))
	do
		# printf "\n["  >>Saida.txt
		./EP1Paralelo $N >>Saida.txt
		printf ", "  >>Saida.txt
		# printf "],"  >>Saida.txt
	done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt

echo "EP1ParaleloList.cpp"
printf "\nEP1ParaleloList = [" >>Saida.txt
for N in $tamLista
do
	echo "N = "$N
	
	printf "\n[" >>Saida.txt
	for (( i=1; i<numExec; i++ ))
	do
		# printf "\n["  >>Saida.txt
		./EP1ParaleloList $N >>Saida.txt
		printf ", " >>Saida.txt
		# printf "],"  >>Saida.txt
	done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt
