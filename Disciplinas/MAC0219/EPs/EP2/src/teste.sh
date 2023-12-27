#! /usr/bin/bash

echo "n_processos,array_size,custom,iteration,time" > testes.csv;

for CUSTOM in true false; do
  ARR_S=1024;
  for j in `seq 1 8`; do
    NPS=1;
    for k in `seq 1 6`; do
      for i in `seq 1 30`; do
        echo -n "$NPS,$ARR_S,$CUSTOM,$i," >> testes.csv;
        if "$CUSTOM"; then
            mpirun -np $NPS --use-hwthread-cpus --oversubscribe \
            ./broadcast --custom --array_size $ARR_S >> testes.csv;
        else
            mpirun -np $NPS --use-hwthread-cpus --oversubscribe \
            ./broadcast --array_size $ARR_S >> testes.csv;
        fi;
      done;
      NPS=`expr $NPS \* 2`;
    done;
    ARR_S=`expr $ARR_S \* 2`;
  done;
done;