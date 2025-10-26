#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <source_folder>"
    exit 1
fi

EXECUTABLE="exec"
SOURCE_FILE="$1/impl.cpp"

g++ -std=c++20 -o $EXECUTABLE $SOURCE_FILE

if [ $? -eq 0 ]; then
    ./$EXECUTABLE
    rm $EXECUTABLE
else
    echo "Compilation failed."
fi