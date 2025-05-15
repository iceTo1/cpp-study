#pragma once

/*
* Custom allocator implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: May 14~15, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* <Attribution>
* The structure of the code was based on the educational content from the following source:
* Channel: Code Blacksmith
* URL: https://www.youtube.com/@CodeBlacksmith
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../utility/utility.h"

namespace ST
{
	template <typename Alloc>
	struct allocator_traits
	{
		using allocator_type = Alloc;

		using value_type = typename Alloc::value_type;
		using pointer = typename Alloc::pointer;
		using const_pointer = typename Alloc::const_pointer;
		using void_pointer = typename Alloc::void_pointer;
		using const_void_pointer = typename Alloc::const_void_pointer;

		using size_type = typename Alloc::size_type;
		using difference_type = typename Alloc::difference_type;

		template <typename T>
		using rebind_alloc = typename Alloc::template rebind<T>::other;

		static pointer allocate(Alloc& a, size_type n)
		{
			return a.allocate(n);
		}
		static void deallocate(Alloc& a, pointer p, size_type n)
		{
			a.deallocate(p, n);
		}

		template <typename T, typename... Args>
		static void construct(Alloc& a, T* p, Args&&... args)
		{
			a.construct(p, ST::forward<Args>(args)...);
		}

		template <typename T>
		static void destroy(Alloc& a, T* p)
		{
			a.destroy(p);
		}
	};
}