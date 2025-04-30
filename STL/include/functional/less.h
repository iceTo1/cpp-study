#pragma once

/*
* Custom less function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 28, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

namespace ST
{
	// less comparator Functor
	template <typename T>
	struct less
	{
		bool operator ()(const T& first, const T& second) const
		{
			return first < second;
		}
	};
}