#! /usr/bin/bash

echo "img,metodo,direto,k,erro" > data.csv
declare -a metodo=(" " "Bilinear" "Bicubico")
for i in `seq 1 3`; do
    fname_in="in_${i}.png";
    for j in 1 2; do
        for k in Direto Indireto; do
            for l in `seq 1 4`; do
                count=$(echo 2^$l - 1 | bc);
                fname="${i}_decompressed_${k}_${count}_${j}.png";
                echo -n "${fname_in},${metodo[$j]},${k},${count}," >> data.csv;
                octave --eval "calculateError('${fname_in}','${fname}')" \
                -p ../ep2 >> data.csv;
            done
        done
    done
done