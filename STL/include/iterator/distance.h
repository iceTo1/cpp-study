#pragma once

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