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

#include "../utility/utility.h"
#include "../functional/functional.h"
#include "../iterator/iterator.h"

namespace ST
{
	template <typename RandomIter, typename Compare = ST::less<typename ST::iterator_traits<RandomIter>::value_type>> 
	void sort(RandomIter begin, RandomIter end, Compare comp)
	{
		// If the container is small, perform Insertion Sort.
		

		// If the container is large, perform Intro Sort (Quick Sort + Heap Sort).
	}
}