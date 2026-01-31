#!/usr/bin/env bash
set -e

make
./logicsim-exe examples/xor.txt > out.uml

echo "Generated out.uml"
echo "Tip: render with PlantUML if you want a diagram."
