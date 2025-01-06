# Define directories
$srcDir = "./src"
$buildDir = "./built"
$outputExe = "./built/main.exe"

# Create the build directory if it doesn't exist
if (!(Test-Path -Path $buildDir)) {
    New-Item -Path $buildDir -ItemType Directory
}

# # Check if the build directory exists
# if (Test-Path -Path $buildDir) {
#     # Remove all files and subdirectories in the folder
#     Get-ChildItem -Path $buildDir -Recurse | Remove-Item -Force -Recurse
# } else {
#     # Create the build directory if it doesn't exist
#     New-Item -Path $buildDir -ItemType Directory
# }

# Compile each .cpp file in the src directory to an object file
Get-ChildItem "$srcDir\*.cpp" | ForEach-Object {
    $fileName = $_.BaseName
    $cppFile = $_.FullName
    $objFile = "$buildDir\$fileName.o"
    
    # Compile the .cpp file into a .o file
    g++ -std=c++23 -g -Wall -Wextra -pedantic -c $cppFile -o $objFile

    # -g: Enables debugging features like source code, rows and etc.
    # -Wall: Enables most compiler warnings.
    # -Wextra: Enables extra warnings that are not included by -Wall.
    # -pedantic: Enforces strict compliance with the C++ standard and issues warnings for any non-standard extensions.
    # -std=c++23: Specifies the C++ standard version to use.
}

# # Link all the .o files into a single executable
g++ "$buildDir\*.o" -o $outputExe

Write-Host "Build complete! Executable is located at: $outputExe"

# # Run the executable after building
if (Test-Path -Path $outputExe) {
    Write-Host "========================================================================="
    & $outputExe
} else {
    Write-Host "Executable not found!"
}