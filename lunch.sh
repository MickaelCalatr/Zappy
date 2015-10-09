#!/bin/bash

if [ $1 > 0 ]; then
    cmpt=0
    while [ "$cmpt" != $1 ]
    do
	nb=$RANDOM
	./zappy_ai $2 $3 $4 $5 $6 $7 $8 &
	cmpt=$(($cmpt+1))
    done
    rm 0
else
    echo "Error syntax : ./launcher IA_nbr flags"
fi
exit 0

