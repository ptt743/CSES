#!/bin/bash
OUT_DIR="/tmp"
source /tmp/my_variable.sh
echo "file compile: $SOURCE_DIR"
g++ -std=c++17 "$SOURCE_DIR" -o "$OUT_DIR/a.out"
"$OUT_DIR/a.out"
