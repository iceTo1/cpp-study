#pragma once

/*
* Custom advance function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 28 ~ 29, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../iterator/iterator_traits.h"

namespace ST
{
	template <typename Iterator>
	void advance(Iterator& iter, typename ST::iterator_traits<Iterator>::difference_type n, ST::random_access_iterator_tag)
	{
		iter += n;
	}

	template <typename Iterator>
	void advance(Iterator& iter, typename ST::iterator_traits<Iterator>::difference_type n, ST::bidirectional_iterator_tag)
	{
		if (n > 0)
		{
			for (int i = 0; i < n; ++i)
				++iter;
		}
		else
		{
			for (int i = n; i < 0; ++i)
			{
				--iter;
			}
		}
	}

	template <typename Iterator>
	void advance(Iterator& iter, typename ST::iterator_traits<Iterator>::difference_type n, ST::forward_iterator_tag)
	{
		if (n < 0)
		{
			// UB
		}
		for (int i = 0; i < n; ++i)
		{
			++iter;
		}
	}

	template <typename Iterator>
	void advance(Iterator& iter, typename ST::iterator_traits<Iterator>::difference_type n, ST::input_iterator_tag)
	{
		if (n < 0)
		{
			// UB
		}
		for (int i = 0; i < n; ++i)
		{
			++iter;
		}
	}

	template <typename Iterator>
	void advance(Iterator& iter, typename ST::iterator_traits<Iterator>::difference_type n)
	{
		using category = typename ST::iterator_traits<Iterator>::iterator_category;

		advance(iter, n, category());
	}
}