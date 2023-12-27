#!/bin/bash

n_tests=30
ifs=2
threads=12
v_size_start=10000
v_size_end=20000000
iterations=10
v_step=$((($v_size_end - $v_size_start)/$iterations))
fname=out.csv

if test -f "$fname"; then
    rm -f "$fname"
fi
echo ifs,threads,v_size,iter,time >> $fname
for i in `seq 0 $ifs`;
do
    make IF=$i &> /dev/null
    for j in `seq 1 $threads`;
    do
        for k in `seq $v_size_start $v_step $v_size_end`;
        do
            for n in `seq 1 $n_tests`;
            do
                echo -n "$i,$j,$k,$n," >> $fname
                ./contention $j $k >> $fname
            done
        done
    done
done