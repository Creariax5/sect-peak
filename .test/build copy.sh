#!/bin/bash

echo "Start build"

# Set the source file
SOURCE_FILE="src/main.cpp"
# Set the output binary
OUTPUT_FILE="build/main"

# Compile and link with SFML
g++ -std=c++17 -I/usr/include -L/usr/lib64 -o $OUTPUT_FILE $SOURCE_FILE -lsfml-graphics -lsfml-window -lsfml-system

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful"
else
    echo "Build failed"
fi

./$OUTPUT_FILE