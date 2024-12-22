#include <iostream>
#include "Print.h"

// void printPassedInt(int);
int macrosUse();

int main() {
	printPassedInt(7);
	macrosUse();
	performStuff();
	showSize();
	doSomething();

    float numbers[] = { -12.375f, 0.1f, -0.0f, INFINITY, NAN };
	for (float num : numbers) {
        printFloatDetails(num);
    }

	return 0;
}