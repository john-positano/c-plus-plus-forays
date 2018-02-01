#!/bin/bash

for folder in $@
  do
    nodemon --exec "
      cd ./node-src/${folder} && 
      node-gyp clean && 
      node-gyp configure &&
      node-gyp build
    " -e .h,.cpp
  done;