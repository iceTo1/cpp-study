#pragma once

/*
* Custom min function implementation by Seungtack Lee
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

namespace ST
{
	template <typename T>
	constexpr const T& min(const T& first, const T& second) noexcept
	{
		return (first < second) ? first : second;
	}

	template <typename T, typename Compare>
	constexpr const T& min(const T& first, const T& second, Compare comp) noexcept
	{
		return comp(second, first) ? first : second;
	}

}