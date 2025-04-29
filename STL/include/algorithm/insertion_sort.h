#pragma once

/*
* Custom insertion sort function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 29, 2025
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
	template <typename RandomIter, typename Compare>
	void insertion_sort(RandomIter begin, RandomIter end, Compare comp)
	{
		for (RandomIter iter = begin + 1; iter != end; ++iter)
		{
			auto val = *iter;
			RandomIter iter2 = iter - 1;
			while (iter2 != begin && comp(val, *(iter2 - 1)))
			{
				*iter2 = *(iter2 - 1);
				--iter2;
			}
			*iter2 = val;
		}
	}
}