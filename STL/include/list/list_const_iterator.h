#pragma once

/*
* Custom const iterator for list implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 30, 2025
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
	class Node;

	template <typename T, typename Alloc>
	class list;

	template <typename T, typename Alloc>
	class list_const_iterator
	{
	private:
		const list<T, Alloc>*	m_pList;	// Member pointer to store address of list (constant).
		const Node<T, Alloc>*	m_pNode;	// Member pointer to store address of node (constant).
		bool					m_isValid;	// Member variable to test validity of iterator.
	public:
		// List traits for iterator functions.
		using iterator_category = ST::bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = const T*;
		using reference = const T&;
	public:
		// Testing functions
		// ValidityTest Function; Check if the const_iterator is valid.
		bool ValidityTest() const
		{
			// If the list or node pointer points to nothing, or iterator is not valid,
			if (nullptr == m_pList || nullptr == m_pNode || !m_isValid)
			{
				throw std::runtime_error("Invalid Iterator");
			}

			// If the iterator is valid, return true.
			return true;
		}
		// Operator Overloading.
		// Operator Former *; Access the data that the const_iterator is pointing.
		reference operator *() const
		{
			// Check iterator.
			ValidityTest();

			// Return the pointed value.
			return this->m_pNode->m_Data;
		}
		// Operator Former ++; Increase const_iterator by 1.
		list_const_iterator& operator ++()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the next node.
			m_pNode = m_pNode->m_NextNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter ++; Increase const_iterator by 1 after assign operator.
		list_const_iterator operator ++(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			list_const_iterator temp = *this;

			// Increase the iterator.
			++(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator Former --; Decrease const_iterator by 1.
		list_const_iterator& operator --()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the previous node.
			m_pNode = m_pNode->m_PrevNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter --; Decrease const_iterator by 1 after assign operator.
		list_const_iterator operator --(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			list_const_iterator temp = *this;

			// Decrease the iterator.
			--(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator ==; Check if two const_iterator are the same.
		bool operator ==(const list_const_iterator& iter) const
		{
			return (this->m_pNode == iter.m_pNode && this->m_pList == iter.m_pList);
		}
		// Operator !=; Check if two const_iterator are not the same.
		bool operator != (const list_const_iterator& iter) const
		{
			return !(*this == iter);
		}

	public:
		// Default Constructor; Initialize the member variables with default data.
		list_const_iterator()
		: m_pList(nullptr)
			, m_pNode(nullptr)
		{}

		// Parameterized constructor; Initialize the member variables with given data.
		list_const_iterator(const list<T, Alloc>* list, const Node<T, Alloc>* node)
			: m_pList(list)
			, m_pNode(node)
			, m_isValid(false)
		{
			if (nullptr != m_pList && nullptr != m_pNode)
			{
				m_isValid = true;
			}
		}

		// Destructor; No specific operation.
		~list_const_iterator()
		{}

		friend class list<T, Alloc>; // Allow access to private members by list.
	};
}