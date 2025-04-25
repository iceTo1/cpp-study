#pragma once

namespace ST
{
	// store type of <T>
	template <typename T>
	struct remove_reference
	{
		using type = T;
	};
	// store type of <T&>
	template <typename T>
	struct remove_reference<T&>
	{
		using type = T;
	};
	// store type of <T&&>
	template <typename T>
	struct remove_reference<T&&>
	{
		using type = T;
	};
}