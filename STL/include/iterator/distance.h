#pragma once

/*
* Custom distance function implementation by Seungtack Lee
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

#include "../iterator/iterator_traits.h"
#include "../iterator/iterator.h"


namespace ST
{
	template <typename Iterator>
	typename ST::iterator_traits<Iterator>::difference_type
	distance(Iterator begin, Iterator end, ST::random_access_iterator_tag)
	{
		return end - begin;
	}

	template <typename Iterator>
	typename ST::iterator_traits<Iterator>::difference_type
	distance(Iterator begin, Iterator end, ST::input_iterator_tag)
	{
		typename iterator_traits<Iterator>::difference_type count = 0;

		while (begin != end)
		{
			++begin;
			++count;
		}

		return count;
	}

	template <typename Iterator>
	typename ST::iterator_traits<Iterator>::difference_type
	distance(Iterator begin, Iterator end)
	{
		using category = typename iterator_traits<Iterator>::iterator_category;

		return distance(begin, end, category());
	}
}