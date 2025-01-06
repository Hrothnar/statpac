#!/bin/bash

# Define directories
srcDir="./src"
buildDir="./built"
outputExe="./built/main"

# Create the build directory if it doesn't exist
if [ ! -d "$buildDir" ]; then
    mkdir -p "$buildDir"
fi

# # Check if the build directory exists
# if [ -d "$buildDir" ]; then
#     # Remove all files and subdirectories in the folder
#     rm -rf "$buildDir"/*
# else
#     # Create the build directory if it doesn't exist
#     mkdir -p "$buildDir"
# fi

# Compile each .cpp file in the src directory to an object file
for cppFile in "$srcDir"/*.cpp; do
    fileName=$(basename "$cppFile" .cpp)
    objFile="$buildDir/$fileName.o"
    
    # Compile the .cpp file into a .o file
    g++ -std=c++23 -g -Wall -Wextra -pedantic -c $cppFile -o $objFile
    
    # -g: Enables debugging features like source code, rows and etc.
    # -Wall: Enables most compiler warnings.
    # -Wextra: Enables extra warnings that are not included by -Wall.
    # -pedantic: Enforces strict compliance with the C++ standard and issues warnings for any non-standard extensions.
    # -std=c++23: Specifies the C++ standard version to use.
done

# Link all the .o files into a single executable
g++ "$buildDir"/*.o -o "$outputExe"

echo "Build complete! Executable is located at: $outputExe"

# Run the executable after building
if [ -f "$outputExe" ]; then
    echo "========================================================================="
    "$outputExe"
else
    echo "Executable not found!"
fi
