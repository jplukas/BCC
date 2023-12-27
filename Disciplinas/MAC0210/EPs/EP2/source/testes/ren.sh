#! /usr/bin/bash

for arq in *_direct_*.png; do
    mv $arq ${arq/_direct/_Direto}
done


for arq in *_indirect_*.png; do
    mv $arq ${arq/_indirect/_Indireto};
done