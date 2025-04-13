
/*
* Custom vector implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 8~12, 2025
* 
* This code was written and maintained by Seungtack Lee for educational purposes.
* If you are using this for learning, please give proper credit.
* Unauthorized use for academic or job submissions is prohibited.
*/

#include "ST_Vector.h"
#include <iostream>

template <typename T>
void PrintVector(vector<T>& vec);

template <typename T>
void PrintVector_Const(const vector<T>& vec);

int main()
{
	std::cout << "Welcome to ST_Vector Testing!\n";

	// Default Constructor Test
	vector<int> myVec;
	std::cout << "\n<Default Constructor Test>\n";
	std::cout << "Capacity of empty: " << myVec.capacity() << "\nSize of empty: " << myVec.size() << std::endl;
	PrintVector(myVec);

	// Parameterized Constructor Test
	vector<int> myVec2(3);
	std::cout << "\n<Parameterized Constructor Test>\n";
	std::cout << "Capacity: " << myVec2.capacity() << "\nSize: " << myVec2.size() << std::endl;
	PrintVector(myVec2);

	// Parameterized Constructor Test 2
	vector<int> myVec3(5, 2);
	std::cout << "\n<Parameterized Constructor Test 2>\n";
	std::cout << "Capacity: " << myVec3.capacity() << "\nSize: " << myVec3.size() << std::endl;
	PrintVector(myVec3);

	// Copy Constructor Test
	vector<int> myVec4 = myVec3;
	std::cout << "\n<Copy Constructor Test>\n";
	std::cout << "Capacity: " << myVec4.capacity() << "\nSize: " << myVec4.size() << std::endl;
	PrintVector(myVec4);

	// push_back Test
	std::cout << "\n<push_back Test>\n";
	std::cout << "Capacity of empty: " << myVec.capacity() << "\nSize of empty: " << myVec.size() << std::endl;
	myVec.push_back(3);
	myVec.push_back(7);
	std::cout << "Capacity after push_back: " << myVec.capacity() << "\nSize after push_back: " << myVec.size() << std::endl;
	PrintVector(myVec);

	// pop_back Test
	std::cout << "\n<pop_back Test>\n";
	std::cout << "Before pop_back:\n";
	PrintVector(myVec);
	myVec.pop_back();
	std::cout << "After pop_back:\n";
	PrintVector(myVec);

	// resize Test
	std::cout << "\n<resize Test>\n";
	std::cout << "Before resize:\n";
	std::cout << "Capacity: " << myVec4.capacity() << "\nSize: " << myVec4.size() << std::endl;
	PrintVector(myVec4);
	myVec4.resize(15);
	std::cout << "After resize:\n";
	std::cout << "Capacity: " << myVec4.capacity() << "\nSize: " << myVec4.size() << std::endl;
	PrintVector(myVec4);

	// front Test
	std::cout << "\n<front Test>\n";
	PrintVector(myVec4);
	std::cout << "Front: " << myVec4.front() << std::endl;

	// back Test
	std::cout << "\n<back Test>\n";
	myVec4.push_back(30);
	PrintVector(myVec4);
	std::cout << "Back: " << myVec4.back() << std::endl;

	// at Test
	std::cout << "\n<at Test>\n";
	myVec.push_back(2);
	myVec.push_back(10);
	PrintVector(myVec);
	int index;
	std::cout << "Enter Index: ";
	std::cin >> index;
	std::cout << "At: " << myVec.at(index) << std::endl;

	// clear Test
	std::cout << "\n<clear Test>\n";
	std::cout << "Before clear:\n";
	std::cout << "Capacity: " << myVec4.capacity() << "\nSize: " << myVec4.size() << std::endl;
	PrintVector(myVec4);
	myVec4.clear();
	std::cout << "After clear:\n";
	std::cout << "Capacity: " << myVec4.capacity() << "\nSize: " << myVec4.size() << std::endl;
	PrintVector(myVec4);

	// operator = Test
	std::cout << "\n<= Test>\n";
	std::cout << "Before assigning:\n";
	std::cout << "Capacity: " << myVec4.capacity() << "\nSize: " << myVec4.size() << std::endl;
	PrintVector(myVec4);
	myVec4 = myVec; 
	std::cout << "After assigning:\n";
	std::cout << "Capacity: " << myVec4.capacity() << "\nSize: " << myVec4.size() << std::endl;
	PrintVector(myVec4);

	// const vector test
	const vector<int> constVec(11, 5);

	// range-based loop test
	std::cout << "\n<Range-Based For Loop Test>\n";
	std::cout << "Constant Vector:\n";
	PrintVector_Const(constVec);

	return 0;
}

template <typename T>
void PrintVector(vector<T>& vec)
{
	std::cout << "Vector: { ";
	if (0 == vec.size())
	{
		std::cout << "}\n";
		return;
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ", ";
	}
	std::cout << "\b\b }\n";
}

template <typename T>
void PrintVector_Const(const vector<T>& vec)
{
	std::cout << "{ ";
	for (const auto& val : vec)
	{
		std::cout << val << ", ";
	}
	std::cout << "\b\b }\n";
}