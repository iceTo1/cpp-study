/*
* Custom list implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 16~, 2025
*
* This code was written and maintained by Seungtack Lee for educational purposes.
* If you are using this for learning, please give proper credit.
* Unauthorized use for academic or job submissions is prohibited.
*/

#include "ST_List.h"
#include <iostream>

int main()
{
	list<int> l;

	std::cout << l.size() << std::endl;

	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_front(1);

	l.pop_back();
	l.pop_front();

	l.clear();

	return 0;
}