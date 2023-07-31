#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

numeroExecucoes=30

tamanhoMatriz="100 200 300 500 700"

echo "P4"
printf "P4" >>Saida.txt
for N in $tamanhoMatriz
do
	echo "N = "$N
	
	printf "\n["  >>Saida.txt
	for (( i=1; i<numeroExecucoes; i++ ))
	do
	# printf "\n["  >>Saida.txt
		./P4 "Matrizes/A_"$N".txt" "Matrizes/B_"$N".txt" 3 >>Saida.txt
	# printf "],"  >>Saida.txt
	done
	printf "]"  >>Saida.txt

	echo ""
done

echo "P4Paralelo"
printf "P4Paralelo\n"  >>Saida.txt
for N in $tamanhoMatriz
do
	echo "N = "$N
	
	printf "\n["  >>Saida.txt
	for (( i=1; i<numeroExecucoes; i++ ))
	do
	# printf "\n["  >>Saida.txt
		./P4Paralel "Matrizes/A_"$N".txt" "Matrizes/B_"$N".txt" 3 >>Saida.txt
	# printf "],"  >>Saida.txt
	done
	printf "]"  >>Saida.txt

	echo ""
done

echo "P4Thread"
printf "P4Thread" >>Saida.txt
for N in $tamanhoMatriz
do
	echo "N = "$N
	
	printf "\n["  >>Saida.txt
	for (( i=1; i<numeroExecucoes; i++ ))
	do
	# printf "\n["  >>Saida.txt
		./P4Thread "Matrizes/A_"$N".txt" "Matrizes/B_"$N".txt" 3 >>Saida.txt
	# printf "],"  >>Saida.txt
	done
	printf "]"  >>Saida.txt

	echo ""
done
