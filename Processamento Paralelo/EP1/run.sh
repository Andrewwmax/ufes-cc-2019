#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

# [Finished in 10714.8s]

g++ -O3 EP1Seq.cpp -o EP1Seq && env time -f "%C\n\tTempo de Execução: %E\n\tMemória usada: %M\n" -o memory.txt -a ./EP1Seq 0 txt/SenhasVazadas.txt txt/1000.txt
g++ -O3 -pthread EP1Paralel.cpp -o EP1Paralel  && env time -f "%C\n\tTempo de Execução: %E\n\tMemória usada: %M\n" -o memory.txt -a ./EP1Paralel 0 txt/SenhasVazadas.txt txt/1000.txt
g++ -O3 EP1BSTSeq.cpp -o EP1BSTSeq  && env time -f "%C\n\tTempo de Execução: %E\n\tMemória usada: %M\n" -o memory.txt -a ./EP1BSTSeq 0 txt/SenhasVazadas.txt txt/1000.txt
g++ -O3 -pthread EP1BSTParalel.cpp -o EP1BSTParalel  && env time -f "%C\n\tTempo de Execução: %E\n\tMemória usada: %M\n" -o memory.txt -a ./EP1BSTParalel 0 txt/SenhasVazadas.txt txt/1000.txt
g++ -O3 EP1Hash.cpp -o EP1Hash && env time -f "%C\n\tTempo de Execução: %E\n\tMemória usada: %M\n" -o memory.txt -a ./EP1Hash 0 txt/SenhasVazadas.txt txt/1000.txt

numExec=15

numThreads="1 2 3 4 8"

tamLista="1 2 75 100 200 500 1000 5000"

echo "EP1Seq.cpp"
printf "\nEP1Seq = [" >>Saida.txt
for t in $tamLista
do
	echo "Verificar = "$t
	
	printf "\n["  >>Saida.txt
		for (( i=1; i<numExec; i++ ))
		do
			./EP1Seq 0 txt/SenhasVazadas.txt txt/$t.txt>>Saida.txt
			printf ", "  >>Saida.txt
		done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt


echo "EP1BSTSeq.cpp"
printf "\nEP1BSTSeq = [" >>Saida.txt
for t in $tamLista
do
	echo "Verificar = "$t
	
	printf "\n["  >>Saida.txt
		for (( i=1; i<numExec; i++ ))
		do
			./EP1BSTSeq 0 txt/SenhasVazadas.txt txt/$t.txt>>Saida.txt
			printf ", "  >>Saida.txt
		done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt


echo "EP1Paralel.cpp"
for t in $numThreads
do
	echo "Thread = "$t
	printf "\nEP1Paralel$t = [" >>Saida.txt
	for l in $tamLista
	do
		echo "Verificar = "$l
		
		printf "\n[" >>Saida.txt
			for (( i=1; i<numExec; i++ ))
			do
				./EP1Paralel $t txt/SenhasVazadas.txt txt/$l.txt>>Saida.txt
				printf ", " >>Saida.txt
			done
		printf "]," >>Saida.txt

	done
	echo ""
	printf "]\n" >>Saida.txt
done


echo "EP1BSTParalel.cpp"
for t in $numThreads
do
	echo "Thread = "$t
	printf "\nEP1BSTParalel$t = [" >>Saida.txt
	for l in $tamLista
	do
		echo "Verificar = "$l
		
		printf "\n[" >>Saida.txt
			for (( i=1; i<numExec; i++ ))
			do
				./EP1BSTParalel $t txt/SenhasVazadas.txt txt/$l.txt>>Saida.txt
				printf ", " >>Saida.txt
			done
		printf "]," >>Saida.txt

	done
	echo ""
	printf "]\n" >>Saida.txt
done


echo "EP1Hash.cpp"
printf "\nEP1Hash = [" >>Saida.txt
for t in $tamLista
do
	echo "Verificar = "$t
	
	printf "\n["  >>Saida.txt
		for (( i=1; i<numExec; i++ ))
		do
			./EP1Hash 0 txt/SenhasVazadas.txt txt/$t.txt>>Saida.txt
			printf ", "  >>Saida.txt
		done
	printf "],"  >>Saida.txt

	echo ""
done
printf "]\n" >>Saida.txt
