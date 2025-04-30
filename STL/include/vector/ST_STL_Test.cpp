
/*
* Custom vector implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 28, 2025
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

#include "../vector/ST_Vector.h"
#include "../list/ST_List.h"
#include "../algorithm/sort.h"
#include <iostream>

void Vector_Test();
void List_Test();

int main()
{
	while (true)
	{
		system("cls");
		std::cout << "\n\n\t\t\t\t\tST's STL Recreation Project\n\n";
		std::cout << "Which Container would you like to test?\n(1: Vector, 2: List)\n";
		std::cout << "[";
		std::cout << " ]\b\b";
		int op;
		std::cin >> op;

		switch (op)
		{
		case 1:
			Vector_Test();
			break;
		case 2:
			List_Test();
			break;
		default:
			std::cout << "Choose valid option (1 or 2)";
		}
	}
	

	return 0;
}

template <typename T>
void PrintVector(const ST::vector<T>& vec)
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
	ST::vector<int> test = { 1, 6, 3, 4, 2, 7 };

	while (true)
	{
		system("cls"); // clear screen
		std::cout << "\n\n\t\t\t\t\t***** Vector Recreation Test *****\n\n";
		std::cout << "Current vector:\n";
		PrintVector(test);
		std::cout << "1. push_back    2. pop_back    3. front    4. back    5. at    6. sort    7. print    0. exit\n";
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
			std::cout << "Sorted Vector: ";
			ST::sort(test.begin(), test.end());
			PrintVector(test);
			break;
		case 7:
			std::cout << "Vector: ";
			PrintVector(test);
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

template <typename T>
void PrintList(const ST::list<T>& lst)
{
	std::cout << "[ ";

	bool first = true;
	for (const auto& val : lst)
	{
		if (!first)
		{
			std::cout << " <--> ";
		}
		std::cout << val;
		first = false;

	}
	std::cout << " ]\n";
}

void List_Test()
{
	// Setup
	int option;
	ST::list<int> test = { 5, 3, 8, 1, 2, 4 };

	// Test
	while (true)
	{
		system("cls"); // clear screen
		std::cout << "\n\n\t\t\t\t***** List Recreation Test *****\n\n";
		std::cout << "Current list:\n";
		PrintList(test);
		std::cout << "1. push_back    2. push_front    3.pop_back    4. pop_front    5. back    6. front    7. print    8. insert    9. sort    0. exit\n";
		std::cout << "Choose: ";
		std::cin >> option;

		while (getchar() != '\n');

		switch (option)
		{
		case 1:
			int val1;
			std::cout << "Value to add at the back: ";
			std::cin >> val1;
			test.push_back(val1);
			break;
		case 2:
			int val2;
			std::cout << "Value to add at front: ";
			std::cin >> val2;
			test.push_front(val2);
			break;
		case 3:
			test.pop_back();
			break;
		case 4:
			test.pop_front();
			break;
		case 5:
			std::cout << test.back() << "\n";
			break;
		case 6:
			std::cout << test.front() << "\n";
			break;
		case 7:
			PrintList(test);
			break;
		case 8:
		{
			int val3, idx;
			std::cout << "Value to insert: ";
			std::cin >> val3;
			std::cout << "Index to insert (will insert left to the index): ";
			std::cin >> idx;

			ST::list<int>::iterator iter = test.begin();
			for (int i = 0; i < idx; ++i)
			{
				++iter;
			}

			test.insert(val3, iter);

			break;
		}
		case 9:
			std::cout << "Sorted List: ";
			test.sort();
			PrintList(test);
			break;
		case 0:
			return;
		default:
			std::cout << "Choose valid option (1~8)";
		}
		std::cout << "\n\n";
		system("pause");
	}
}