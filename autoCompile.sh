#!/bin/bash

for file in $@ 
  do 
    nodemon --exec "gcc -x c++ ./src/${file} -lstdc++ -o ./out/${file/.cpp/.o} && ./out/${file/.cpp/.o}" -e .h,.cpp;
  done;