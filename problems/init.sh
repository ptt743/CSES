#!/bin/bash
echo $*
raw="$*"
SOURCE_DIR="${raw// /_}"
SOURCE_DIR="${SOURCE_DIR}.cpp"
echo "SOURCE_DIR=$SOURCE_DIR" > /tmp/my_variable.sh
cp ../template.cpp "$SOURCE_DIR" | nvim "$SOURCE_DIR"

