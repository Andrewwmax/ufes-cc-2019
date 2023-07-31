#!/bin/bash
#reset

./Sortation -fbubble -q100 -r 1500 2000
./Sortation -fcounting -q100 -r 1500 2000
./Sortation -fheap -q100 -r 1500 2000
./Sortation -finsertion -q100 -r 1500 2000
./Sortation -fmerge -q100 -r 1500 2000
./Sortation -fquick -q100 -r 1500 2000
./Sortation -fradix -q100 -r 1500 2000
./Sortation -fselection -q100 -r 1500 2000

#./Sortation -fbubble -otest.txt
#./Sortation -fcounting -otest.txt
#./Sortation -fheap -otest.txt
#./Sortation -finsertion -otest.txt
#./Sortation -fmerge -otest.txt
#./Sortation -fquick -otest.txt
#./Sortation -fradix -otest.txt
#./Sortation -fselection -otest.txt