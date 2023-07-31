#!/bin/bash
#
#$ -cwd
#$ -j y
#$ -S /bin/bash
#$ -N SeuNome
#$ -pe mpich 16

# Redirecting standard output error to files
# named "output" and "errors"
#$ -o output_par.txt
#$ -e errors_par.txt

mpirun -np 16 ./pi >out.txt
