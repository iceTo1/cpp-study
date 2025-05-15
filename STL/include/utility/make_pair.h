#pragma once

/*
* Custom make_pair function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: May 1, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "pair.h"

namespace ST
{
	template <typename T1, typename T2>
	constexpr pair<T1, T2> make_pair(const T1& a, const T2& b)
	{
		return pair<T1, T2>(a, b);
	}
}