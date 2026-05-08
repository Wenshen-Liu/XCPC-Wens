#!/bin/bash
# compile and run — output to output/<mirror-path>, no extra files
set -e

if [ $# -lt 1 ]; then
    echo "usage: ./run.sh <path/to/file.cpp>"
    exit 1
fi

SRC="$1"
OUT="output/${SRC%.cpp}"

mkdir -p "$(dirname "$OUT")"
g++-15 -std=c++20 -O2 -Wall "$SRC" -o "$OUT"
echo "[ok] $OUT"
echo "---"
"./$OUT"
