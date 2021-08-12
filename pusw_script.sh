#!/bin/sh
make
<<'COMMENTS'
FILE="file_test_opt1"

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]
then
	echo "./pusw_script <nb of numeros> <min> <max> [move ?]"
	exit 1
fi

ARG=`./a.out $1 $2 $3`;
echo $ARG

if [ -n "$4" ]
then
	./push_swap $ARG
fi

echo $ARG > chiffre.txt
./push_swap $ARG | ./checker_linux $ARG


echo -n "nb of moves : "
./push_swap $ARG | wc -l
COMMENTS
./push_swap "2 3 4 5 1"