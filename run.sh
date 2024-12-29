#!/bin/bash

# Script to compile and run the Coding Quiz App

echo "Compiling the quiz program..."
gcc quiz.c -o quiz -lm

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the quiz..."
    ./quiz
else
    echo "Compilation failed. Please check for errors in the code."
fi
