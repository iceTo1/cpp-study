#pragma once

#include <cstddef>
#include "iterator.h"
#include "iterator_category.h"

namespace ST
{
	// Assume that iterator type will be given, by default.
	template <typename Iterator>
	struct iterator_traits
	{
		using value_type = typename Iterator::value_type;
		using difference_type = typename Iterator::difference_type;
		using pointer = typename Iterator::pointer;
		using reference = typename Iterator::reference;
		using iterator_category = typename Iterator::iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T*;
		using reference = T&;
		using iterator_category = ST::random_access_iterator_tag;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = const T*;
		using reference = const T&;
		using iterator_category = ST::random_access_iterator_tag;
	};
}
