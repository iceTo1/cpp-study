
/*
* Custom vector implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 8~12, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* This warning is now included because over 60 individuals have copied this code without visiting the original GitHub repository,
* which suggests the code has been redistributed without proper credit.
* If you are using this for learning, please give proper credit.
*
* <Attribution>
* The structure of the test code was inspired by the educational content from the following source:
* Channel: withhoneyc
* URL: https://www.youtube.com/@withhoneyc
* 
* Unauthorized use for academic or job submissions is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "ST_Vector.h"
#include <iostream>

void Vector_Test();

int main()
{
	Vector_Test();

	return 0;
}

template <typename T>
void PrintVector(const vector<T>& vec)
{
	std::cout << "{ ";
	for (const auto& val : vec)
	{
		std::cout << val << ", ";
	}
	std::cout << "\b\b }\n";
}

void Vector_Test()
{
	int option;
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);

	while (true)
	{
		system("cls"); // clear screen
		std::cout << "\n\n\t\t\t\t\t***** Vector Recreation Test *****\n\n";
		std::cout << "Current vector:\n";
		PrintVector(test);
		std::cout << "1. push_back    2. pop_back    3. front    4. back    5. at    6. print\n";
		std::cout << "Choose: ";
		std::cin >> option;

		while (getchar() != '\n');

		switch (option)
		{
		case 1:
			int val;
			std::cout << "Value to add at the back: ";
			std::cin >> val;
			test.push_back(val);
			break;
		case 2:
			test.pop_back();
			break;
		case 3:
			std::cout << test.front() << "\n";
			break;
		case 4:
			std::cout << test.back() << "\n";
			break;
		case 5:
			int idx;
			std::cout << "Index to access: ";
			std::cin >> idx;
			std::cout << test.at(idx) << "\n";
			break;
		case 6:
			std::cout << "Vector: ";
			PrintVector(test);
			break;
		default:
			std::cout << "Choose valid option (1~6)";
		}
		std::cout << "\n\n";
		system("pause");
	}
}