#!/bin/sh
make

FILE="file_test_opt1"

ARG=`./a.out 5 0 5`;
echo $ARG
echo $ARG > chiffre.txt
./push_swap -v $ARG

#ARG=`./a.out 5 0 5`; ./push_swap $ARG | grep "nb de mv" | cut -d : -f2 >> file_test_opt1

#awk '{ sum += $FILE; n++ } END { if (n > 0) print sum / n; }'
