#! /usr/bin/bash

for arq in *.png; do
    for i in `seq 1 4`; do
        count=$(echo 2^$i - 1 | bc);
        imgnum=${arq#in_};
        imgnum=${imgnum%.png};
        octave --eval "compress('$arq',$count)" -p ../ep2 && \
        cp ./compressed.png ./com.png && \
        for method in 1 2; do 
            fname=${imgnum}_decompressed_indirect_${count}_${method}.png;
            for j in `seq 1 $i`; do
                octave --eval "decompress('compressed.png', $method, 1, 3)" -p ../ep2 && \
                mv ./decompressed.png ./compressed.png;
            done && \
            mv ./compressed.png $fname;
            fname=${imgnum}_decompressed_direct_${count}_${method}.png;
            h=`expr $count + 2`;
            octave --eval "decompress('com.png', $method, $count, $h)" -p ../ep2 && \
            mv ./decompressed.png $fname;
            cp ./com.png ./compressed.png;
        done;
    done;
done