#pragma once

#include "move.h"

namespace ST
{
	template <typename T>
	void swap(T& a, T& b)
	{
		T temp = ST::move(a);
		a = ST::move(b);
		b = ST::move(temp);
	}
}