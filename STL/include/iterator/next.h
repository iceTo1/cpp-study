#pragma once

/*
* Custom next function implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 29, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../iterator/advance.h"
#include "../iterator/iterator_traits.h"

namespace ST
{
	template <typename Iterator>
	Iterator next(Iterator iter, typename ST::iterator_traits<Iterator>::difference_type n = 1)
	{
		advance(iter, n);
		return iter;
	}
}