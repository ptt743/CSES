#!/bin/bash

raw="$*"
name="${raw// /_}"
file="${name%.cpp}.cpp"
echo $1
SOURCE_DIR="$1"
echo "SOURCE_DIR=$file" > /tmp/my_variable.sh
cp ../template.cpp "$file" | nvim "$file"

