#pragma once

/*
* Custom intro sort function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 29~30, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../algorithm/insertion_sort.h"
#include "../algorithm/quick_sort.h"
#include "../algorithm/heap_sort.h"
#include "../iterator/iterator.h"

namespace ST
{
	template <typename RandomIter, typename Compare>
	void intro_sort(RandomIter begin, RandomIter end, Compare comp, int depth)
	{
		using DiffType = typename ST::iterator_traits<RandomIter>::difference_type;
		static const int threshold = 16;

		DiffType size = ST::distance(begin, end);

		if (size <= threshold)
		{
			ST::insertion_sort(begin, end, comp);
			return;
		}

		if (depth == 0)
		{
			ST::heap_sort(begin, end, comp);
			return;
		}

		RandomIter pivot = ST::partition(begin, end, comp);

		ST::intro_sort(begin, pivot, comp, depth - 1);
		ST::intro_sort(pivot, end, comp, depth - 1);
	}
}