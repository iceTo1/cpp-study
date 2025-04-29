#pragma once

/*
* Custom heap sort function implementation by Seungtack Lee
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

#include "../utility/utility.h"
#include "../functional/functional.h"

namespace ST
{
	template <typename RandomIter, typename Compare>
	void heapify(RandomIter begin, int index, int heap_size, Compare comp)
	{
		int largest = index;
		int left = 2 * index + 1;
		int right = left + 1;

		if (left < heap_size && comp(begin[largest], begin[left]))
		{
			largest = left;
		}
		if (right < heap_size && comp(begin[largest], begin[right]))
		{
			largest = right;
		}

		if (largest != index)
		{
			ST::swap(begin[index], begin[largest]);
			heapify(begin, largest, heap_size, comp);
		}
	}

	template <typename RandomIter, typename Compare>
	void heap_sort(RandomIter begin, RandomIter end, Compare comp)
	{
		int n = static_cast<int>(ST::distance(begin, end));

		// Max Heap
		for (int i = n / 2 - 1; i >= 0; --i)
		{
			heapify(begin, i, n, comp);
		}

		for (int i = n - 1; i > 0; --i)
		{
			ST::swap(begin[0], begin[i]);
			heapify(begin, 0, i, comp);
		}
	}
}