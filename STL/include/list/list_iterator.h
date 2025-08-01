#pragma once

/*
* Custom iterator for list implementation by Seungtack Lee
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
#include "../list/ST_List.h"

namespace ST
{
	template <typename T, typename Alloc>
	class Node;

	template <typename T, typename Alloc>
	class list;

	template <typename T, typename Alloc>
	class list_iterator
	{
	private:
		list<T, Alloc>*	m_pList;	// Member pointer to store address of list.
		Node<T, Alloc>*	m_pNode;	// Member pointer to store address of node.
		bool			m_isValid;	// Member variable to test validity of iterator.

	public:
		// List traits for iterator functions.
		using iterator_category = bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T*;
		using reference = T&;

	public:
		// Testing functions
		// ValidityTest Function; Check if the iterator is valid.
		void ValidityTest() const
		{
			// If the list or node pointer points to nothing, or iterator is not valid,
			if (nullptr == m_pList || nullptr == m_pNode || !m_isValid)
			{
				throw std::runtime_error("Invalid Iterator");
			}
		}
		// Operator Overloading.
		// Operator Former *; Access the data that the iterator is pointing.
		reference operator *()
		{
			// Check iterator.
			ValidityTest();

			// Return the pointed value.
			return this->m_pNode->m_Data;
		}
		// Operator Former ++; Increase iterator by 1.
		list_iterator& operator ++()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the next node.
			m_pNode = m_pNode->m_NextNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter ++; Increase iterator by 1 after assign operator.
		list_iterator operator ++(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			list_iterator temp = *this;

			// Increase the iterator.
			++(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator Former --; Decrease iterator by 1.
		list_iterator& operator --()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the previous node.
			m_pNode = m_pNode->m_PrevNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter --; Decrease iterator by 1 after assign operator.
		list_iterator operator --(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			list_iterator temp = *this;

			// Decrease the iterator.
			--(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator ==; Check if two iterators are the same.
		bool operator ==(const list_iterator& iter) const
		{
			return (this->m_pNode == iter.m_pNode && this->m_pList == iter.m_pList);
		}
		// Operator !=; Check if two iterators are not the same.
		bool operator != (const list_iterator& iter) const
		{
			return !(*this == iter);
		}

	public:
		// Constructor; Initialize member variables with default values.
		list_iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_isValid(false)
		{
		}
		// Parameterized constructor; Initialize the member variables with given data.
		list_iterator(list<T, Alloc>* list, Node<T, Alloc>* node)
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
		~list_iterator()
		{
		}

		friend class list<T, Alloc>;	// Allow access to private members by list.
	};
}