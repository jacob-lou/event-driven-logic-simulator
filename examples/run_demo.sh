#!/usr/bin/env bash
set -e

make

INPUT="exclusive_or.txt"
if [ ! -f "$INPUT" ]; then INPUT="single_not.txt"; fi
if [ ! -f "$INPUT" ]; then INPUT="test_small.txt"; fi

./logicsim-exe "$INPUT" > out.uml

echo "Generated out.uml"
echo "Tip: render with PlantUML if you want a diagram."
