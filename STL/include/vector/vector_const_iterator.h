#pragma once

/*
* Custom const iterator for vector implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 28~30, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include <cstddef>
#include "../iterator/iterator_category.h"

namespace ST
{
	template <typename T, typename Alloc>
	class vector;

	template <typename T, typename Alloc = STAllocator<T>>
	class vector_const_iterator
	{
	private:
		const T*					m_pData;		// Constant type data pointer
		const ST::vector<T, Alloc>*	m_vectorPtr;	// Constant type vector pointer
		int							m_idx;			// Index variable (cannot be constant; need to point different elements)
		bool						m_isValid;		// Validity variable (cannot be constant; need to check validity)

	public:
		// Vector traits for iterator functions.
		using iterator_category = random_access_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = const T*;
		using reference = const T&;

	public:
		// Testing functions
		// ValidityTest Function; Check if pointed vector or iterator itself is valid.
		void ValidityTest() const
		{
			// if array is invalid, or array and iterator does not match, or iterator is invalid,
			if (nullptr == m_vectorPtr || nullptr == m_pData || m_pData != m_vectorPtr->m_pData || !m_isValid)
			{
				// throw exception.
				throw std::invalid_argument("Iterator invalid.");
			}
		}
		// IndexTest Function; Check if index is not negative or out of bound; I designed this in addition to STL iterators.
		void IndexTest() const
		{
			// if index is negative, or out of bound,
			if (m_idx < 0 || m_idx > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}
		}

		// Operator overload
		// constant Operator *; Access the value like pointer; Cannot overwrite the constant data type.
		reference operator* () const
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Return data of index.
			return m_pData[m_idx];
		}

		// Operator Former ++; Increase iterator by 1.
		vector_const_iterator& operator++ ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Increase index.
			++m_idx;

			// Return modified iterator.
			return *this;
		}

		// Operator Latter ++; Increase iterator by 1 after assign operator.
		vector_const_iterator operator++ (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			vector_const_iterator temp = *this;

			// Perform ++ to the iterator.
			++(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator Former --; Decrease iterator by 1.
		vector_const_iterator& operator-- ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if pointing to the first element,
			if (0 == m_idx)
			{
				// do nothing.
				return *this;
			}
			// if vector is not empty,
			else if (0 < m_vectorPtr->m_Size)
			{
				// decrease index.
				--m_idx;
			}

			// Return modified iterator (if vector is empty, do not change).
			return *this;
		}

		// Operator Latter --; Decrease iterator by 1 after assign operator.
		vector_const_iterator operator-- (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			vector_const_iterator temp = *this;
			// Perform -- to the iterator.
			--(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator +; Increase the iterator by given step.
		vector_const_iterator& operator+ (int step)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index + step is out of bound,
			if (m_idx + step < 0 || m_idx + step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			vector_const_iterator temp = *this;

			// Increase index by "step".
			temp.m_idx += step;

			// Return modified iterator.
			return temp;
		}

		// Operator -; Decrease the iterator by given step.
		vector_const_iterator& operator- (int step)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index - step is out of bound,
			if (m_idx - step < 0 || m_idx - step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			vector_const_iterator temp = *this;

			// Decrease index by "step".
			temp.m_idx -= step;

			// Return modified iterator.
			return temp;
		}

		// Operator =; Assign/copy iterator.
		vector_const_iterator& operator= (const vector_const_iterator& other)
		{
			// if other iterator and this iterator are different,
			if (this != &other)
			{
				// copy data.
				this->m_vectorPtr = other.m_vectorPtr;
				this->m_pData = other.m_pData;
				this->m_idx = other.m_idx;
				this->m_isValid = other.m_isValid;
			}
			return *this;
		}

		// Operator ==; Check if two iterators are identical.
		bool operator== (const vector_const_iterator& other)
		{
			// if iterator is pointing to same vector and, same element, return true.
			return (this->m_vectorPtr == other.m_vectorPtr && this->m_idx == other.m_idx);
		}

		// Operator !=; Check if two iterators are unidentical.
		bool operator!= (const vector_const_iterator& other)
		{
			// return opposite result of operator ==.
			return !(*this == other);
		}

		// Operator +; Calculate index between iterators.
		int operator+ (const vector_const_iterator& other) const
		{
			return this->m_idx + other.m_idx;
		}

		// Operator -; Calculate index between iterators.
		int operator- (const vector_const_iterator& other) const
		{
			return this->m_idx - other.m_idx;
		}

	public:
		// iterator parameterized Constructor; Initialized the members by given values.
		vector_const_iterator(const vector<T, Alloc>* vector, const T* data, int idx)
			: m_vectorPtr(vector)
			, m_pData(data)
			, m_idx(idx)
			, m_isValid(false)
		{
			// if vector is valid,
			if (nullptr != vector && vector->m_pData == data)
			{
				m_isValid = true;
			}
		}
		// constant iterator Destructor; No specific operation due to no memory allocation.
		~vector_const_iterator()
		{
		}
		friend class ST::vector<T, Alloc>;
	};
}
