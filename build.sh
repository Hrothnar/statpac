#!/bin/bash

# Define directories
srcDir="./src"
buildDir="./built"
outputExe="./built/main"

# Create the build directory if it doesn't exist
if [ ! -d "$buildDir" ]; then
    mkdir -p "$buildDir"
fi

# Compile each .cpp file in the src directory to an object file
for cppFile in "$srcDir"/*.cpp; do
    fileName=$(basename "$cppFile" .cpp)
    objFile="$buildDir/$fileName.o"
    
    # Compile the .cpp file into a .o file
    g++ -g -std=c++23 -c "$cppFile" -o "$objFile"
done

# Link all the .o files into a single executable
g++ -g -std=c++23 "$buildDir"/*.o -o "$outputExe"

echo "Build complete! Executable is located at: $outputExe"

# Run the executable after building
if [ -f "$outputExe" ]; then
    echo "========================================================================="
    "$outputExe"
else
    echo "Executable not found!"
fi
