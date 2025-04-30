#pragma once

/*
* Custom reverse iterator for list implementation by Seungtack Lee
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
#include "../list/list_iterator.h"

namespace ST
{
	template <typename T>
	class Node;

	template <typename T>
	class list;

	template <typename T>
	class list_reverse_iterator
	{
	private:
		list<T>*	m_pList;	// Member pointer to store address of list.
		Node<T>*	m_pNode;	// Member pointer to store address of node.
		bool		m_isValid;	// Member variable to test validity of iterator.

	public:
		// List traits for iterator functions.
		using iterator_category = ST::random_access_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T*;
		using reference = T&;
	public:
		// Testing functions
		// ValidityTest Function; Check if the reverse_iterator is valid.
		bool ValidityTest() const
		{
			// If the list or node pointer points to nothing, or iterator is not valid,
			if (nullptr == m_pList || nullptr == m_pNode || !m_isValid)
			{
				throw std::runtime_error("Invalid Iterator");
			}

			// If the reverse_iterator is valid, return true.
			return true;
		}
		// Operator Overloading.
		// Operator Former *; Access the data that the reverse_iterator is pointing.
		T& operator *()
		{
			// Check iterator.
			ValidityTest();

			// Return the pointed value.
			return this->m_pNode->m_Data;
		}
		// Operator Former ++; Increase reverse_iterator by 1.
		list_reverse_iterator& operator ++()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the previous node.
			m_pNode = m_pNode->m_PrevNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter ++; Increase reverse_iterator by 1 after assign operator.
		list_reverse_iterator operator ++(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			list_reverse_iterator temp = *this;

			// Increase the iterator.
			++(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator Former --; Decrease reverse_iterator by 1.
		list_reverse_iterator& operator --()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the next node.
			m_pNode = m_pNode->m_NextNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter --; Decrease reverse_iterator by 1 after assign operator.
		list_reverse_iterator operator --(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			list_reverse_iterator temp = *this;

			// Decrease the iterator.
			--(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator ==; Check if two reverse_iterators are the same.
		bool operator ==(const list_reverse_iterator& iter) const
		{
			return (this->m_pNode == iter.m_pNode && this->m_pList == iter.m_pList);
		}
		// Operator !=; Check if two reverse_iterators are not the same.
		bool operator != (const list_reverse_iterator& iter) const
		{
			return !(*this == iter);
		}

		// Reverse iterator function
		// base Function; Return the forward iterator based on the reverse iterator.
		list_iterator<T> base()
		{
			// Base points to the 'right' of the reverse iterator

			// If the reverse iterator is rbegin,
			if (this->m_pNode == this->m_pList->m_TailNode)
			{
				// Return end iterator for forward const iterator.
				return list_iterator<T>(this->m_pList, nullptr);
			}
			else
			{
				return list_iterator<T>(this->m_pList, this->m_pNode->m_NextNode);
			}
		}

	public:
		// Constructor; Initialize member variables with default values.
		list_reverse_iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_isValid(false)
		{
		}
		// Parameterized constructor; Initialize the member variables with given data.
		list_reverse_iterator(list<T>* list, Node<T>* node)
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
		~list_reverse_iterator()
		{
		}

		friend class list<T>;	// Allow access to private members by list.
	};
}