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

#include <cstddef>
#include <memory>
#include <limits>
#include <iostream>
#include "../utility/utility.h"

template <typename T>
struct STAllocator
{
	// Types
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using void_pointer = void*;
	using const_void_pointer = const void*;
	using size_type = size_t;
	using difference_type = std::ptrdiff_t;

	// Rebind
	template <typename U>
	struct rebind
	{
		// Converting allocator into another type of allocator.
		using other = STAllocator<U>;
	};

	STAllocator() = default;

	template <typename U>
	STAllocator(const STAllocator<U>& other)
	{

	}

	~STAllocator() = default;

	pointer allocate(size_type numObjects)
	{
		return static_cast<pointer>(operator new(sizeof(T) * numObjects));
	}

	// To improve locality, use the nearest allocated memory.
	pointer allocate(size_type numObjects, const_void_pointer hint)
	{
		return allocate(numObjects);
	}

	void deallocate(pointer p, size_type numObjects)
	{
		operator delete(p);
	}

	size_type max_size() const
	{
		return std::numeric_limits<size_type>::max();
	}

	// Construction Function - should take any number of arguments.
	template <typename U, typename... Args>
	void construct(U* p, Args&& ...args)
	{
		// new(p) U(): p is preallocated address. Constructs U type of object. [placement new]
		new(p) U(ST::forward<Args>(args)...);
	}

	// Destroy Function
	template <typename U>
	void destroy(U* p)
	{
		// Calls destructor
		p->~U();
	}
};