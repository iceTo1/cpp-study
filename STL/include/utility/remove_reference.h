#pragma once

/*
* Custom remove_reference implementation by Seungtack Lee
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

namespace ST
{
	// store type of <T>
	template <typename T>
	struct remove_reference
	{
		using type = T;
	};
	// store type of <T&>
	template <typename T>
	struct remove_reference<T&>
	{
		using type = T;
	};
	// store type of <T&&>
	template <typename T>
	struct remove_reference<T&&>
	{
		using type = T;
	};

	// Alias for type
	template <typename T>
	using remove_reference_t = typename remove_reference<T>::type;
}