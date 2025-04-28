#pragma once

namespace ST
{
	// greater comparator Functor
	template <typename T>
	struct greater
	{
		bool operator ()(const T& first, const T& second) const
		{
			return first > second;
		}
	};
}