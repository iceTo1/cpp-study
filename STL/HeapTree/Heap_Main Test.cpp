
/*
* Custom heap implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 27, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* <Attribution>
* The structure of the test code was inspired by the educational content from the following source:
* Channel: withhoneyc
* URL: https://www.youtube.com/@withhoneyc
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "ST_Heap.h"
#include <iostream>

void Heap_Test();

int main()
{
	Heap_Test();

	return 0;
}

void Heap_Test()
{
	int option;
	Heap<int> test = { 1, 2, 3, 4, 5 };

	std::cout << "Current heap:\n";
	test.DebugPrint();

	while (true)
	{
		system("cls"); // clear screen
		std::cout << "\n\n\t\t\t\t\t***** Heap Recreation Test *****\n\n";
		std::cout << "Current heap:\n";
		test.DebugPrint();
		std::cout << "1. push    2. pop    3. top    4. clear    5. heapify    6. print    0. exit\n";
		std::cout << "Choose: ";
		std::cin >> option;

		while (getchar() != '\n');

		switch (option)
		{
		case 1:
			int val;
			std::cout << "Value to add at the back: ";
			std::cin >> val;
			test.push(val);
			break;
		case 2:
			test.pop();
			break;
		case 3:
			std::cout << test.top() << "\n";
			break;
		case 4:
			test.clear();
			break;
		case 5:
			test.heapify();
			break;
		case 6:
			std::cout << "Heap:\n";
			test.DebugPrint();
			break;
		case 0:
			return;
		default:
			std::cout << "Choose valid option (0~6)";
		}
		std::cout << "\n\n";
		system("pause");
	}
}