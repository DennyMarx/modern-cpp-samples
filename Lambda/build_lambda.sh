#!/bin/bash
echo "Building project via cmake"
cmake .
cmake --build ./ --clean-first
