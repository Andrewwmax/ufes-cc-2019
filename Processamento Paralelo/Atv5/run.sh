#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

# g++ -O3 -std=c++14 -pthread P5.cpp -o P5 && ./P5 1000000 4 &&
# g++ -O3 -std=c++14 -pthread P5pThread.cpp -o P5pThread && ./P5pThread 1000000 4 &&
# g++ -O3 -std=c++14 -pthread P5thread.cpp -o P5thread && ./P5thread 1000000 4

numExec=30

tamLista="25000000"

numThreads=9

echo "P5.cpp"
printf "\nP5 = [" >>Saida.txt
for (( t=1; t<numThreads; t++ ))
do
	echo "Thread = "$t
	
	printf "\n["  >>Saida.txt
		for (( i=1; i<numExec; i++ ))
		do
			./P5 $tamLista $t>>Saida.txt
			printf ","  >>Saida.txt
		done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt

echo "P5pThread.cpp"
printf "\nP5pThread = [" >>Saida.txt
for (( t=1; t<numThreads; t++ ))
do
	echo "Thread = "$t
		printf "\n["  >>Saida.txt
		for (( i=1; i<numExec; i++ ))
		do
			./P5pThread $tamLista $t>>Saida.txt
			printf ","  >>Saida.txt
		done
		printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt

echo "P5thread.cpp"
printf "\nP5thread = [" >>Saida.txt
for (( t=1; t<numThreads; t++ ))
do
	echo "Thread = "$t
		printf "\n["  >>Saida.txt
		for (( i=1; i<numExec; i++ ))
		do
			./P5thread $tamLista $t>>Saida.txt
			printf ","  >>Saida.txt
		done
		printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt


