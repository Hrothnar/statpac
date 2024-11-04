g++ -std=c++23 -g -Wall -Wextra -pedantic -c .\src\Main.cpp -o .\built\Main.o && 
g++ .\built\Main.o -o .\built\main.exe && 
.\built\main.exe
