#!/bin/bash
reset
gcc questao6.c -o questao6

./questao6 $1
dot -Tpng -Kfdp IN.DOT -oIN.png -Gdpi=150
dot -Tpng -Kcirco OUT.DOT -oOUT.png -Gdpi=150

rm questao6