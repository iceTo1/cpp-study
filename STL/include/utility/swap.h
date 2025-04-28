#pragma once

/*
* Custom swap function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 25, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "move.h"

namespace ST
{
	template <typename T>
	void swap(T& a, T& b)
	{
		T temp = ST::move(a);
		a = ST::move(b);
		b = ST::move(temp);
	}
}