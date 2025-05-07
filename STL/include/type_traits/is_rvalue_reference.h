#pragma once

namespace ST
{
	template <typename T>
	struct is_rvalue_reference
	{
		static constexpr bool value = false;
	};

	template <typename T>
	struct is_rvalue_reference<T&&>
	{
		static constexpr bool value = true;
	};
}