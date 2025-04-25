#pragma once
#include "remove_reference.h"

namespace ST
{
	template <typename T>
	constexpr typename ST::remove_reference<T>::type&& move(T&& t) noexcept
	{
		// Return the given type with &&, after removing all & and add && to it.
		return static_cast<ST::remove_reference<T>::type&&>(t);
	}
}