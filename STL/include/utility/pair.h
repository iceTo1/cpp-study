#pragma once

/*
* Custom pair function implementation by Seungtack Lee
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
	template <typename T1, typename T2>
	struct pair
	{
		T1 first;
		T2 second;

		// Default Constructor
		pair()
			: first()
			, second()
		{
		}

		// Parameterized Constructor
		pair(const T1& a, const T2& b)
			: first(a)
			, second(b)
		{
		}

		// Copy Constructor
		template <typename t1, typename t2>
		pair(const pair<t1, t2>& other)
			: first(other.first)
			, second(other.second)
		{
		}

		// Operator Overloading
		bool operator== (const pair& other) const
		{
			return (first == other.first && second == other.second);
		}
		bool operator!= (const pair& other) const
		{
			return !(*this == other);
		}
		bool operator< (const pair& other) const
		{
			if (first < other.first)
			{
				return true;
			}
			if (first > other.first)
			{
				return false;
			}

			return second < other.second;
		}

	};
}