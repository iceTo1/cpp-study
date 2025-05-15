#pragma once

/*
* Custom forward function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: May 1, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../utility/remove_reference.h"
#include "../type_traits/is_lvalue_reference.h"

namespace ST
{
	template <typename T>
	constexpr T&& forward(ST::remove_reference_t<T>& param) noexcept
	{
		return static_cast<T&&>(param);
	}

	template <typename T>
	constexpr T&& forward(ST::remove_reference_t<T>&& param) noexcept
	{
		static_assert(!ST::is_lvalue_reference<T>::value, "T is lvalue reference but given as rvalue.");
		return static_cast<T&&>(param);
	}
}