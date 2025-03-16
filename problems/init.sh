#!/bin/bash
echo $1
SOURCE_DIR="$1"
echo "SOURCE_DIR=$SOURCE_DIR" > /tmp/my_variable.sh
cp ../template.cpp "$1" | nvim "$1"

