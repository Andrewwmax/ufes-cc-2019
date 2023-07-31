#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

# mpic++ -O3 NEWEP2.cpp sha1.h sha1.cpp -o EP2

echo -n "Digite a String para Criptografar: "
read senha

echo -n "Digite o NP: "
read np

np=`expr $np + 1`

cript=$(./geraSenhas $senha)
echo $cript

time mpirun -np $np -quiet EP2 $cript

# env time -v mpirun -np 4 -quiet EP2 8cb2237d0679ca88db6464eac60da96345513964
# env time -v mpirun -np 4 -quiet EP2 7b151de317f2547df39e1a1ff2850a6abfa6128f
# env time -v mpirun -np 4 -quiet EP2 230cdfcdb6f2aa33b7acf19edaae5a216a14155f
# env time -v mpirun -np 4 -quiet EP2 b2cdbf0601d8ae90d3cda1c978566ace86c4eac0
# env time -v mpirun -np 4 -quiet EP2 a045b7efa463c6ed195c644163f4168952fbd34a	
# env time -v mpirun -np 4 -quiet EP2 d27e086d60a993d203717509c46a6752daccc967

# 12345 = 8cb2237d0679ca88db6464eac60da96345513964
# A1B2C = 7b151de317f2547df39e1a1ff2850a6abfa6128f
# 123ZZ = 230cdfcdb6f2aa33b7acf19edaae5a216a14155f
# DCEL  = b2cdbf0601d8ae90d3cda1c978566ace86c4eac0 
# 99999 = a045b7efa463c6ed195c644163f4168952fbd34a

