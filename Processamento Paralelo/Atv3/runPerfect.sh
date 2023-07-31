#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

# limite="9223372034707292160" max
# limite="2305843008139952128"
limite="32"
# limite="8129"

for (( i=2; i<limite; i++ ))
do
	# echo "N = "$N
	# printf "\n" >>NumPerfeito.txt
	./NumPerfeito $i >>NumPerfeito.txt

	# printf " eh Perfeito"  >>NumPerfeito.txt
done




























# for N in $tamanhoMatriz
# do
# 	echo "N = "$N
# 	for (( i=1; i<=numeroExecucoes; i++ ))
# 	do
# 		./programaICCSemO3 $N >>icc/semO3/saida$N.txt
# 	done
# 	echo ""
# 	echo ""
# done

# for N in $tamanhoMatriz
# do
# 	echo "N = "$N
# 	for (( i=1; i<=numeroExecucoes; i++ ))
# 	do
# 		./programaICCComO3 $N >>icc/comO3/saida$N.txt
# 	done
# 	echo ""
# 	echo ""
# done

# for N in $tamanhoMatriz
# do
# 	echo "N = "$N
# 	for (( i=1; i<=numeroExecucoes; i++ ))
# 	do
# 		./programaGCCSemO3 $N >>gcc/semO3/saida$N.txt
# 	done
# 	echo ""
# 	echo ""
# done

# for N in $tamanhoMatriz
# do
# 	echo "N = "$N
# 	for (( i=1; i<=numeroExecucoes; i++ ))
# 	do
# 		./programaGCCComO3 $N >>gcc/comO3/saida$N.txt
# 	done
# 	echo ""
# 	echo ""
# done
