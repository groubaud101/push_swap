#!/bin/sh
make
#ARG=`./a.out 5 0 5`; ./push_swap $ARG | grep "nb de mv" | cut -d : -f2 >> file_test_opt

ARG=`./a.out 5 0 5`; ./push_swap -v $ARG