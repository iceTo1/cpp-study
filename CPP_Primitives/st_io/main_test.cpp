#include "stio.h"

int main()
{
	/*
	int i = 10;
	char msg[]  = "integer print test 1: ";

	ST::cout << msg << i << '\n';
	ST::cout << "integer print test 2: " << 15 << '\n';
	ST::cout << "float print test 1: " << 3.14f << '\n';
	ST::cout << "double print test 1: " << 3.14 << "\n";
	ST::cout << "long double print test 1: " << 3.14l << "\n";

	ST::cout << "Endline test" << ST::endl;
	ST::cout << "Hello, World!" << ST::endl;
	*/

	int i;
	ST::cout << "Enter integer: ";
	ST::cin >> i;

	ST::cout << "Entered integer: " << i << ST::endl;

	return 0;
}