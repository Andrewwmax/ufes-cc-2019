#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

# g++ -O3 -std=c++14 -pthread P6Thread.cpp -o P6Thread && ./P6Thread 1000000 4

numExec=30

tamLista="50000000"

numThreads=9

echo "P6Thread.cpp"
printf "\nP6Thread = [" >>Saida.txt
for (( t=1; t<numThreads; t++ ))
do
	echo "Thread = "$t
	
	printf "\n["  >>Saida.txt
		for (( i=1; i<numExec; i++ ))
		do
			./P6Thread $tamLista $t>>Saida.txt
			printf ", "  >>Saida.txt
		done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt