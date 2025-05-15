#pragma once

/*
* Custom is_lvalue_reference implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: May 7, 2025
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
	struct is_lvalue_reference
	{
		static constexpr bool value = false;
	};

	template <typename T>
	struct is_lvalue_reference<T&>
	{
		static constexpr bool value = true;
	};
}