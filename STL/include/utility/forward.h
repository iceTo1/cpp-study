#pragma once

#include "../utility/remove_reference.h"

namespace ST
{
	template <typename T>
	constexpr T&& forward(remove_reference<T>& param) noexcept
	{
		return static_cast<T&&>(param);
	}

	template <typename T>
	constexpr T&& forward(remove_reference<T>&& param) noexcept
	{
		static_assert(!std::is_lvalue_reference<T>::value, "T is lvalue reference but given as rvalue.");
		return static_cast<T&&>(param);
	}
}