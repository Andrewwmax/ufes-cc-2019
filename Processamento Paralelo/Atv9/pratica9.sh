#!/bin/bash
#
#$ -cwd
#$ -j y
#$ -S /bin/bash
#$ -N <SeuNome>
#$ -pe orte 12

# Redirecting standard output error to files
# named "output" and "errors"
#$ -o output_par.txt
#$ -e errors_par.txt

time ./pi >outPar.txt
