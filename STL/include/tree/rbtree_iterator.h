#pragma once

/*
* Custom iterator for RBTree implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: May 6, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../tree/ST_RBTree.h"
#include "../iterator/iterator_category.h"

namespace ST
{
	template <typename T>
	class rbtree_iterator
	{
	private:
		RBTree<T>* m_Tree;
		RBNode<T>* m_Node;
	public:
		// Vector traits for iterator functions.
		using iterator_category = ST::bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = int;
		using pointer = T*;
		using reference = T&;
	
	public:
		// Operator Overloading
		reference operator*() const { return m_Node->m_Data; }
		pointer operator->() const { return &(m_Node->m_Data); }
		bool operator== (const rbtree_iterator& other) const { return (m_Node == other.m_Node) && (m_Tree == other.m_Tree); }
		bool operator!= (const rbtree_iterator& other) const { return !(*this == other); }

		rbtree_iterator& operator++ ()
		{
			m_Node = m_Tree->Sucessor(m_Node);

			return *this;
		}
		
		rbtree_iterator operator++ (int)
		{
			rbtree_iterator temp = *this;
			++(*this);

			return temp;
		}

		rbtree_iterator& operator-- ()
		{
			m_Node = m_Tree->Predecessor(m_Node);

			return *this;
		}

		rbtree_iterator operator-- (int)
		{
			rbtree_iterator temp = *this;
			--(*this);

			return temp;
		}

	public:
		rbtree_iterator()
			: m_Tree(nullptr)
			, m_Node(nullptr)
		{ }
		rbtree_iterator(RBTree<T>* tree, RBNode<T>* node)
			: m_Tree(tree)
			, m_Node(node)
		{ }
	};
}