#!/bin/bash

eosdir="/store/user/chanon/THQ/Ntuples_V3/2l"

eos ls ${eosdir} > l

for i in `cat l`
do

echo root://eoscms//eos/cms${eosdir}/$i

done

