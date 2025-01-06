#ifndef PRINT_H
#define PRINT_H

void printPassedInt(int);
void printPassedInt(int); // forward could be duplicated as they only declare the existence of a function
void performStuff();
void showSize();
void doSomething();
void printFloatDetails(float);
void workWithCppString();

#endif

// #pragma once - an alternative way to guard headers from duplication. 
// There is one known case where #pragma once will typically fail. If a header file is copied so that it exists in multiple places on the file system,
// if somehow both copies of the header get included, header guards will successfully de-dupe the identical headers, 
// but #pragma once won’t (because the compiler won’t realize they are actually identical content).