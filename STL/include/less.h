#pragma once

namespace ST
{
	// less comparator Functor
	template <typename T>
	struct less
	{
		bool operator ()(const T& first, const T& second) const
		{
			return first < second;
		}
	};
}