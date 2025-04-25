#pragma once

/*
* Custom move function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 25, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

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