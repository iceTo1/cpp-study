#pragma once

/*
* Custom quick sort function implementation by Seungtack Lee
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
	RandomIter partition(RandomIter begin, RandomIter end, Compare comp)
	{
		RandomIter pivot = begin + (ST::distance(begin, end) / 2);
		auto pivot_val = *pivot;

		RandomIter left = begin;
		RandomIter right = end - 1;

		while (true)
		{
			while (comp(*left, pivot_val))
			{
				++left;
			}
			while (comp(pivot_val, *right))
			{
				--right;
			}

			if (left >= right)
			{
				return right;
			}

			ST::swap(*left, *right);
			++left;
			--right;
		}
	}

	template <typename RandomIter, typename Compare>
	void quick_sort(RandomIter begin, RandomIter end, Compare comp)
	{
		if (ST::distance(begin, end) <= 1)
		{
			return;
		}
		RandomIter mid = ST::partition(begin, end, comp);

		quick_sort(begin, mid + 1, comp);
		quick_sort(mid + 1, end, comp);
	}
}