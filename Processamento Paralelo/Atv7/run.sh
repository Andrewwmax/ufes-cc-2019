#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

# g++ somaCritical.cpp -fopenmp -o somaCritical && ./somaCritical &&
# g++ somaAtomic.cpp -fopenmp -o somaAtomic && ./somaAtomic &&
# g++ somaReduction.cpp -fopenmp -o somaReduction && ./somaReduction &&
# g++ somaSequencial.cpp -fopenmp -o somaSequencial && ./somaSequencial

numExec=30

tamLista="100000000"

echo "somaCritical.cpp"
printf "\nsomaCritical = [" >>Saida.txt
# printf "\n["  >>Saida.txt
	for (( i=1; i<numExec; i++ ))
	do
		./somaCritical >>Saida.txt
		printf ", " >>Saida.txt
	done
# printf "]," >>Saida.txt

echo ""
printf "]\n" >>Saida.txt


echo "somaAtomic.cpp"
printf "\nsomaAtomic = [" >>Saida.txt
# printf "\n["  >>Saida.txt
	for (( i=1; i<numExec; i++ ))
	do
		./somaAtomic >>Saida.txt
		printf ", " >>Saida.txt
	done
# printf "]," >>Saida.txt

echo ""
printf "]\n" >>Saida.txt


echo "somaReduction.cpp"
printf "\nsomaReduction = [" >>Saida.txt
# printf "\n["  >>Saida.txt
	for (( i=1; i<numExec; i++ ))
	do
		./somaReduction >>Saida.txt
		printf ", " >>Saida.txt
	done
# printf "]," >>Saida.txt

echo ""
printf "]\n" >>Saida.txt


echo "somaSequencial.cpp"
printf "\nsomaSequencial = [" >>Saida.txt
# printf "\n["  >>Saida.txt
	for (( i=1; i<numExec; i++ ))
	do
		./somaSequencial >>Saida.txt
		printf ", " >>Saida.txt
	done
# printf "]," >>Saida.txt

echo ""
printf "]\n" >>Saida.txt