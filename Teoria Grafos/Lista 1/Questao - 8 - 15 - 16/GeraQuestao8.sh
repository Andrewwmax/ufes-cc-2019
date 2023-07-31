#!/bin/bash
reset
gcc questao8.c -o questao8

./questao8 $1
dot -Tpng -Kdot IN.DOT -oIN.png -Gdpi=150
dot -Tpng -Kdot OUT.DOT -oOUT.png -Gdpi=150

rm questao8