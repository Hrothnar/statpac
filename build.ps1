# Define directories
$srcDir = "./src"
$buildDir = "./built"
$outputExe = "./built/main.exe"

# Create the build directory if it doesn't exist
if (!(Test-Path -Path $buildDir)) {
    New-Item -Path $buildDir -ItemType Directory
}

# Compile each .cpp file in the src directory to an object file
Get-ChildItem "$srcDir\*.cpp" | ForEach-Object {
    $fileName = $_.BaseName
    $cppFile = $_.FullName
    $objFile = "$buildDir\$fileName.o"
    
    # Compile the .cpp file into a .o file
    g++ -g -std=c++23 -c $cppFile -o $objFile
}

# Link all the .o files into a single executable
g++ -g -std=c++23 "$buildDir\*.o" -o $outputExe

Write-Host "Build complete! Executable is located at: $outputExe"

# Run the executable after building
if (Test-Path -Path $outputExe) {
    Write-Host "========================================================================="
    & $outputExe
} else {
    Write-Host "Executable not found!"
}