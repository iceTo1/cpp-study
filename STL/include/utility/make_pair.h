#pragma once

#include "pair.h"

namespace ST
{
	template <typename T1, typename T2>
	constexpr pair<T1, T2> make_pair(const T1& a, const T2& b)
	{
		return pair<T1, T2>(a, b);
	}
}