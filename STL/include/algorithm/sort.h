#pragma once

/*
* Custom sort function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 28~, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include <cmath>
#include "../utility/utility.h"
#include "../functional/functional.h"
#include "../iterator/iterator.h"
#include "../algorithm/intro_sort.h"
#include <iostream>

namespace ST
{
	template <typename SizeType>
	SizeType floor_log2(SizeType n)
	{
		SizeType result = 0;
		
		while (n >>= 1)
		{
			++result;
		}
		
		return result;
	}

	template <typename RandomIter, typename Compare = ST::less<typename ST::iterator_traits<RandomIter>::value_type>> 
	void sort(RandomIter begin, RandomIter end, Compare comp = Compare())
	{
		using DiffType = typename ST::iterator_traits<RandomIter>::difference_type;

		DiffType size = ST::distance(begin, end);
		int maxDepth = 2 * ST::floor_log2(size);

		ST::intro_sort(begin, end, comp, maxDepth);
	}
}