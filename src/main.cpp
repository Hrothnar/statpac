#include <iostream>

int multiply() {
	int x {};
	std::cout << "Provide a number\n";
	std::cin >> x;
	std::cout << "Your number multiplied by 2 is: " << x * 2<< "\n";
	std::cout << "Your number multiplied by 3 is: " << x * 3<< std::endl;
	return 0;
}

int main() {
	// int x {};
	// int y;

	// std::cout << x;
	// std::cout << y;
	// std::cout << "Please, provide an input!" << std::endl;

	// std::cin >> x >> y;

	// std::cout << "Hello, world!" << std::endl << "And you too!" << std::endl;
	// std::cout << "Your input: " << x << " | " << y << "\n";
	multiply();

	return 0;
}

// void foo(int)
// {
// }

// int main()
// {
//     unsigned int x { 5 };
//     foo(x);

//     return 0;
// }

