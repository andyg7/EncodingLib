#!/bin/sh

make all
MAKE_OUTPUT=$?

if [ $MAKE_OUTPUT = 0 ]; then
	echo 'Compiled successfully!'
else
	echo 'make failed'
	exit 1
fi

ARG1=$1
shift
ARG2=$1

./a.out $ARG1 $ARG2
