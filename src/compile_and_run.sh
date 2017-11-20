#!/bin/sh

make all
MAKE_OUTPUT=$?

if [ $MAKE_OUTPUT = 0 ]; then
	echo 'Compiled successfully!'
else
	echo 'make failed'
	exit 1
fi

./codeit $@
