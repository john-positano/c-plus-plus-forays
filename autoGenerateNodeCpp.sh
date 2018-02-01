#!/bin/bash

nl=$'\n'

for folder in $@
  do
    binding_gyp="{
      \"targets\": [
        {
          \"target_name\": \"${folder}\",
          \"sources\": [ \"${folder}.cpp\" ]
        }
      ]
    }";
    if [ -d "./node-src/${folder}" ]; then
        echo "'./node-src/${folder}' already exists. Deleting...";
        rm -rf "./node-src/${folder}" 
    fi
    echo "Creating Folder './node-src/${folder}' ...";
    mkdir "./node-src/${folder}" &&
    touch "./node-src/${folder}/${folder}.cpp" &&
    echo $binding_gyp > "./node-src/${folder}/binding.gyp";
  done;