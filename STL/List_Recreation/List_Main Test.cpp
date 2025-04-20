
/*
* Custom list implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 16~20, 2025
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

#include "ST_List.h"
#include <iostream>

void List_Test();

int main()
{
	List_Test();

	return 0;
}

template <typename T>
void PrintList(const list<T>& lst)
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
	list<int> test = { 1, 2, 3, 4, 5 };

	// Test
	while (true)
	{
		system("cls"); // clear screen
		std::cout << "\n\n\t\t\t\t***** List Recreation Test *****\n\n";
		std::cout << "Current list:\n";
		PrintList(test);
		std::cout << "1. push_back    2. push_front    3.pop_back    4. pop_front    5. back    6. front    7. print    8. insert    0. exit\n";
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

			list<int>::iterator iter = test.begin();
			for (int i = 0; i < idx; ++i)
			{
				++iter;
			}

			test.insert(val3, iter);

			break;
		}
		case 0:
			return;
		default:
			std::cout << "Choose valid option (1~8)";
		}
		std::cout << "\n\n";
		system("pause");
	}
}