#pragma once

/*
* Custom Red Black Tree implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: May 6~, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

/**
* @brief Characteristics of Red Black Tree
* @details
* 1. Root node has to be Black.
* 2. Red nodes cannot have red children.
* 3. Every path from radom node to all nil nodes have the same number of black nodes (Black Height).
* 4. ALL leaves (nils) are Black.
* 5. New inserted nodes are always Red.
*
* @author Seungtack Lee
* @date May 5, 2025
*/

#include "../utility/utility.h"
#include "rbtree_iterators.h"

namespace ST
{
	// enum Class for tree colors.
	enum class COLOR
	{
		RED,
		BLACK,
	};

	template <typename T>
	class RBTree; // Declaration of set.

	template <typename T>
	class RBNode
	{
	private:
		T			m_Data;		// Member variable to store data.
		COLOR		color;		// Member variable to store node color.
		RBNode<T>*	m_Parent;	// Member variable to store parent node.
		RBNode<T>*	m_LChild;	// Member variable to store left child.
		RBNode<T>*	m_RChild;	// Member variable to store right child.

	public:
		// Default Constructor; Initialize the node with default value for insertion.
		RBNode()
			: m_Data(T())
			, color(COLOR::RED)
			, m_Parent(nullptr)
			, m_LChild(nullptr)
			, m_RChild(nullptr)
		{ }
		// Constructor; Initialize the node with given data, set the node for insertion.
		RBNode(const T& data)
			: m_Data(data)
			, color(COLOR::RED)
			, m_Parent(nullptr)
			, m_LChild(nullptr)
			, m_RChild(nullptr)
		{
		}

		friend class RBTree<T>;	// Grant access to private member by set class. 
	};

	template <typename T>
	class RBTree
	{
	private:
		RBNode<T>* m_Root;		// Member variable to store the root node.
		RBNode<T>* const nil;	// Member variable for nil node.

	private:
		// Helper Functions
		// [Helper] Init_nil Function; Initialize the nil node to use, and mark leaf nodes.
		void Init_nil();
		// [Helper] CountNodes Function; Count the number of nodes in the subtree.
		size_t CountNodes(RBNode<T>* node) const;
		// [Helper] ClearSubtree Function; Erase data from the subtree.
		void ClearSubtree(RBNode<T>* node);
		// [Helper] MinimumNode Function; Find the minimum node from the given node as root.
		const RBNode<T>* MinimumNode(const RBNode<T>* node) const;
		// [Helper] Successor Function; Find the appropriate successsor node.
		const RBNode<T>* Successor(const RBNode<T>* node);
		// [Helper] MaximumNode Function; Find the maximum node from the given node as root.
		const RBNode<T>* MaximumNode(const RBNode<T>* node) const;
		// [Helper] Predecessor Function; Find the appropriate successsor node.
		const RBNode<T>* Predecessor(const RBNode<T>* node);
		// [Helper] InsertNode Function; Insert the node that has given value as its data.
		RBNode<T>* InsertNode(const T& value);
		// [Helper] FixInsert Function; Check the balance and fix the tree structure after insertion.
		void FixInsert(RBNode<T>* node);
		// [Helper] RotateLeft Function; Rotate left to solve imbalance.
		void RotateLeft(RBNode<T>* node);
		// [Helper] RotateRight Function; Rotate right to solve imbalance.
		void RotateRight(RBNode<T>* node);

	public:
		// Assigning traits for iterator functions.
		using value_type = T;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using size_type = int;
		using difference_type = int;

		// Using shorter name for iterators.
		using iterator = rbtree_iterator<T>;
		using const_iterator = rbtree_const_iterator<T>;
		using reverse_iterator = rbtree_reverse_iterator<T>;
		using const_reverse_iterator = rbtree_const_reverse_iterator<T>;

	public:
		// RBTree Functions
		// empty Function; Check if the tree is empty.
		bool empty() const;
		// size Function; Return the size of the tree.
		size_t size() const;
		// clear Function; Erase all the data from the tree.
		void clear();
		// insert Function; Insert the given value to the tree.
		ST::pair<iterator, bool> insert(const T& value);
		// erase Function; Erase the given value from the tree.
		size_t erase(const T& value);
		// find Function; Find the given value from the tree.
		iterator find(const T& value);
		// find Function; Constant version of find Function.
		const_iterator find(const T& value) const;
		// count Function; Count the number of value from the tree.
		size_t count(const T& value) const;

		// Iterator Functions
		// begin Function; Return the iterator that points to the left most node.
		iterator		begin()			{ return iterator(this, MinimumNode(m_Root)); }
		// begin Function; Constant version of begin function.
		const_iterator	begin() const	{ return const_iterator(this, MinimumNode(m_Root)); }
		// end Function; Return the iterator that points to nil node.
		iterator		end()			{ return iterator(this, nil); }
		// end Function; Constant version of end function.
		const_iterator	end() const		{ return const_iterator(this, nil); }
		// cbegin Function; Constant version of begin function that returns constant iterator explicitly.
		const_iterator	cbegin() const	{ return const_iterator(this, MinimumNode(m_Root)); }
		// cend Function; Constant version of end function that returns constant iterator explicitly.
		const_iterator	cend() const	{ return const_iterator(this, nil); }

		// rbegin Function; Return the reverse iterator that points to the right most node.
		reverse_iterator		rbegin()		{ return reverse_iterator(this, MaximumNode(m_Root)); }
		// rbegin Function; Constant version of rbegin function.
		const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(this, MaximumNode(m_Root)); }
		// rend Function; Return the reverse iterator that points to nil node.
		reverse_iterator		rend()			{ return reverse_iterator(this, nil); }
		// rend Function; Constant version of rend function.
		const_reverse_iterator	rend() const	{ return const_reverse_iterator(this, nil); }
		// crbegin Function; Constant version of rbegin function that returns constant reverse iterator explicitly.
		const_reverse_iterator	crbegin() const	{ return const_reverse_iterator(this, MaximumNode(m_Root)); }
		// crend Function; Constant version of rend function that returns constant reverse iterator explicitly.
		const_reverse_iterator	crend() const	{ return const_reverse_iterator(this, nil); }

	public:
		// Constructor; Initialize the root node to nothing, then set the root as 'nil'.
		RBTree()
			: m_Root(nullptr)
		{
			// Initialize nil node.
			Init_nil();
			m_Root = nil;
		}
		~RBTree()
		{
			// Delete all data.
			clear();
			delete nil;
		}

		friend class rbtree_iterator<T>;
		friend class rbtree_const_iterator<T>;
		friend class rbtree_reverse_iterator<T>;
		friend class rbtree_const_reverse_iterator<T>;
	};

	// [Helper] Init_nil Function; Initialize the nil node to use, and mark leaf nodes.
	template <typename T>
	void RBTree<T>::Init_nil()
	{
		// Create a new node and assign it to 'nil'.
		nil = new RBNode<T>();
		// Initialize the 'nil' node to its own properties.
		nil->color = COLOR::BLACK;
		nil->m_Parent = nullptr;
		nil->m_LChild = nullptr;
		nil->m_RChild = nullptr;
	}

	// [Helper] CountNodes Function; Count the number of nodes in the subtree.
	template<typename T>
	size_t RBTree<T>::CountNodes(RBNode<T>* node) const
	{
		// If the node is empty,
		if (nil == node)
		{
			// Return 0.
			return 0;
		}
		// Return the result of CountNodes function for both children + 1.
		return 1 + CountNodes(node->m_LChild) + CountNodes(node->m_RChild);
	}

	// [Helper] ClearSubtree Function; Erase data from the subtree.
	template<typename T>
	void RBTree<T>::ClearSubtree(RBNode<T>* node)
	{
		// If the node is empty (base case),
		if (nil == node)
		{
			// Escape the recursion.
			return;
		}

		// Delete node in post-order.
		ClearSubtree(node->m_LChild);
		ClearSubtree(node->m_RChild);
		delete node;
		node = nullptr;
	}

	// [Helper] MinimumNode Function; Find the minimum node from the given node as root.
	template<typename T>
	const RBNode<T>* RBTree<T>::MinimumNode(const RBNode<T>* node) const
	{
		// Iterate while the node has left child.
		while (nil != node->m_LChild)
		{
			// Update the node to its left child.
			node = node->m_LChild;
		}
		// Return the left most node.
		return node;
	}

	// [Helper] Successor Function; Find the appropriate successsor node.
	template<typename T>
	const RBNode<T>* RBTree<T>::Successor(const RBNode<T>* node)
	{
		// If the given node has right child,
		if (nil != node->m_RChild)
		{
			// Find the minimum node from the right tree.
			return MinimumNode(node->m_RChild);
		}
		// If the given node does not have right child,
		else
		{
			RBNode<T>* parent = node->m_Parent;
			// Iterate while the parent's left child is the node,
			// or the parent does not exist.
			while (nullptr != parent && parent->m_LChild == node)
			{
				// Update the node to its parent.
				node = parent;
				// Update the parent node to its parent.
				parent = parent->m_Parent;
			}
			return parent;
		}
	}

	// [Helper] MaximumNode Function; Find the maximum node from the given node as root.
	template<typename T>
	const RBNode<T>* RBTree<T>::MaximumNode(const RBNode<T>* node) const
	{
		// Iterate while the node has right child.
		while (nil != node->m_RChild)
		{
			// Update the node to its right child.
			node = node->m_RChild;
		}
		// Return the right most node.
		return node;
	}

	// [Helper] Predeccessor Function; Find the appropriate successsor node.
	template<typename T>
	const RBNode<T>* RBTree<T>::Predecessor(const RBNode<T>* node)
	{
		// If the node has its left child,
		if (nil != node->m_LChild)
		{
			// Return the maximum node from its left subtree.
			return MaximumNode(node->m_LChild);
		}
		// If the node does not have its left child,
		else
		{
			// Return the biggest parent node.
			RBNode<T>* parent = node->m_Parent;
			// Iterate while the parent node is not null
			// or the node is right child of the parent node.
			while (nullptr != parent && parent->m_RChild == node)
			{
				// Update the node to its parent.
				node = parent;
				// Update the parent node to its parent.
				parent = parent->m_Parent;
			}
			return parent;
		}
	}

	// [Helper] InsertNode Function; Insert the node that has given value as its data.
	template<typename T>
	RBNode<T>* RBTree<T>::InsertNode(const T& value)
	{
		// Create a new node with given value.
		RBNode<T>* newNode = new RBNode<T>(value);
		newNode->m_LChild = nil;
		newNode->m_RChild = nil;

		// Declare variables for traversal.
		RBNode<T>* parent = nullptr;
		RBNode<T>* current = m_Root;

		// Search for place to insert the node (find parent and insert to its child).
		// Iterate while the current node is not the nil node.
		while (current != nil)
		{
			// Update the parent to the current node.
			parent = current;
			// Update the current node.
			if (value < current->m_Data)
			{
				current = current->m_LChild;
			}
			else
			{
				current = current->m_RChild;
			}
		}

		// Set the parent node of the new node.
		newNode->m_Parent = parent;

		// If the node is being inserted as root node,
		if (nil == m_Root)
		{
			m_Root = newNode;
		}
		// Otherwise, insert the new node to the appropriate child of its parent node.
		else if (value < parent->m_Data)
		{
			parent->m_LChild = newNode;
		}
		else
		{
			parent->m_RChild = newNode;
		}

		// Call function to balance the tree after insertion.
		FixInsert(newNode);

		return newNode;
	}

	// [Helper] FixInsert Function; Check the balance and fix the tree structure after insertion.
	template<typename T>
	void RBTree<T>::FixInsert(RBNode<T>* node)
	{
		/**
		* 1. Check if parent is red.
		* 2. If uncle is red, recolor.
		* 3. If uncle is black, rotate and recolor based on triangle or line case.
		* 4. Repeat until root is black.
		*/

		// Iterate while the parent node is red.
		while (node != m_Root && node->m_Parent->color == COLOR::RED)
		{
			// If the parent is left child of grandparent node,
			if (node->m_Parent == node->m_Parent->m_Parent->m_LChild)
			{
				// Declare a node pointer for uncle node.
				RBNode<T>* uncle = node->m_Parent->m_Parent->m_RChild;

				// Case 1: When uncle is red,
				if (uncle->color == COLOR::RED)
				{
					// Recolor.
					// When both parent and uncle are red, make grandparent as red,
					// and recolor the parent and uncle.
					node->m_Parent->color = COLOR::BLACK;
					uncle->color = COLOR::BLACK;
					node->m_Parent->m_Parent->color = COLOR::RED;
					node = node->m_Parent->m_Parent;
				}
				else
				{
					// Case 2: When uncle is black, node is LR Imbalance,
					if (node == node->m_Parent->m_RChild)
					{
						// Rotate to the left to make it Case 3.
						node = node->m_Parent;
						RotateLeft(node);
					}

					// Case 3: When uncle is black, node is LL Imbalance,
					// Recolor the parent node and grandparent node.
					node->m_Parent->color = COLOR::BLACK;
					node->m_Parent->m_Parent->color = COLOR::RED;
					// Rotate to the right.
					RotateRight(node->m_Parent->m_Parent);
				}
			}
			// If the parent is right child of grandparent node,
			else
			{
				// Declare a node pointer for uncle node.
				RBNode<T>* uncle = node->m_Parent->m_Parent->m_LChild;

				// Case 1: When uncle is red,
				if (uncle->color == COLOR::RED)
				{
					// Recolor.
					// When both parent and uncle are red, make grandparent as red,
					// and recolor the parent and uncle.
					node->m_Parent->color = COLOR::BLACK;
					uncle->color = COLOR::BLACK;
					node->m_Parent->m_Parent->color = COLOR::RED;
					node = node->m_Parent->m_Parent;
				}
				else
				{
					// Case 2: When uncle is black, node is RL Imbalance,
					if (node == node->m_Parent->m_LChild)
					{
						// Rotate to the right to make it Case 3.
						node = node->m_Parent;
						RotateRight(node);
					}

					// Case 3: When uncle is black, node is RR Imbalance,
					// Recolor the parent node and grandparent node.
					node->m_Parent->color = COLOR::BLACK;
					node->m_Parent->m_Parent->color = COLOR::RED;
					// Rotate to the right.
					RotateLeft(node->m_Parent->m_Parent);
				}
			}
		}
		// Adjust the root node's color to be black.
		m_Root->color = COLOR::BLACK;
	}

	// [Helper] RotateLeft Function; Rotate left to solve imbalance.
	template<typename T>
	void RBTree<T>::RotateLeft(RBNode<T>* node)
	{
		// Declare node pointers for left rotation.
		RBNode<T>* node_x = node->m_RChild;
		RBNode<T>* node_c = node_x->m_LChild;

		// node_x takes the given node's position.
		node_x->m_Parent = node->m_Parent;

		// <Linking the node_x with its new parent node>
		// If the node_x becomes a root,
		if (nullptr == node->m_Parent)
		{
			// Update the root to the node_x.
			m_Root = node_x;
		}
		// If the given node is left child,
		else if (node == node->m_Parent->m_LChild)
		{
			node->m_Parent->m_LChild = node_x;
		}
		// If the given node is right child,
		else
		{
			node->m_Parent->m_RChild = node_x;
		}

		// <Rotate>
		// Set the node_x's left child to the given node.
		node_x->m_LChild = node;
		node->m_Parent = node_x;
		// Set the node_x's left child to the given node's right child.
		node->m_RChild = node_c;
		if (node_c != nil)
			node_c->m_Parent = node; // nil node's parent has to be nullptr.
	}

	// [Helper] RotateRight Function; Rotate right to solve imbalance.
	template<typename T>
	void RBTree<T>::RotateRight(RBNode<T>* node)
	{
		// Declare node pointers for left rotation.
		RBNode<T>* node_x = node->m_LChild;
		RBNode<T>* node_c = node_x->m_RChild;

		// node_x takes the given node's position.
		node_x->m_Parent = node->m_Parent;

		// <Linking the node_x with its new parent node>
		// If the node_x becomes a root,
		if (nullptr == node->m_Parent)
		{
			// Update the root to the node_x.
			m_Root = node_x;
		}
		// If the given node is left child,
		else if (node == node->m_Parent->m_LChild)
		{
			node->m_Parent->m_LChild = node_x;
		}
		// If the given node is right child,
		else
		{
			node->m_Parent->m_RChild = node_x;
		}

		// <Rotate>
		// Set the node_x's right child to the given node.
		node_x->m_RChild = node;
		node->m_Parent = node_x;
		// Set the node_x's right child to the given node's left child.
		node->m_LChild = node_c;
		if (node_c != nil)
			node_c->m_Parent = node; // nil node's parent has to be nullptr.
	}

	// empty Function; Check if the tree is empty.
	template<typename T>
	inline bool RBTree<T>::empty() const
	{
		// Check if the root node is nil node.
		return (m_Root == nil);
	}

	// size Function; Return the size of the tree.
	template<typename T>
	size_t RBTree<T>::size() const
	{
		// Call CountNodes function for total node count.
		return CountNodes(m_Root);
	}

	// clear Function; Erase all the data from the tree.
	template<typename T>
	void RBTree<T>::clear()
	{
		// If the tree is already empty,
		if (empty())
		{
			// Do nothing.
			return;
		}
		// Call ClearSubtree function from the root.
		ClearSubtree(m_Root);
		// Reset the root to nil node.
		m_Root = nil;
	}

	// insert Function; Insert the given value to the tree.
	template<typename T>
	ST::pair<typename RBTree<T>::iterator, bool> RBTree<T>::insert(const T& value)
	{
		// If duplicate is found,
		if (find(value) != end())
		{
			// Set the result to false, with the duplicate value.
			return ST::make_pair(find(value), false);
		}
		
		// Otherwise, insert the node.
		RBNode<T>* newNode = InsertNode(value);

		// Return the pair with iterator and boolean value.
		return ST::make_pair(iterator(this, newNode), true);
	}

	// find Function; Find the given value from the tree.
	template<typename T>
	typename RBTree<T>::iterator RBTree<T>::find(const T& value)
	{
		// Declrae a node pointer to traverse from the root.
		RBNode<T>* current = m_Root;

		// Iterate while the current node is not nil node.
		while (current != nil)
		{
			// If the value is found,
			if (value == current->m_Data)
			{
				// Return the iterator that points to the current node.
				return iterator(this, current);
			}
			// If the value is smaller than the curren node's data,
			else if (value < current->m_Data)
			{
				// Update the current node to its left child.
				current = current->m_LChild;
			}
			// If the value is bigger than the curren node's data,
			else
			{
				// Update the current node to its right child.
				current = current->m_RChild;
			}
		}

		// If not found, return end iterator.
		return end();
	}

	// find Function; Constant version of the find Function.
	template<typename T>
	typename RBTree<T>::const_iterator RBTree<T>::find(const T& value) const
	{
		// Declrae a node pointer to traverse from the root.
		RBNode<T>* current = m_Root;

		// Iterate while the current node is not nil node.
		while (current != nil)
		{
			// If the value is found,
			if (value == current->m_Data)
			{
				// Return the iterator that points to the current node.
				return const_iterator(this, current);
			}
			// If the value is smaller than the curren node's data,
			else if (value < current->m_Data)
			{
				// Update the current node to its left child.
				current = current->m_LChild;
			}
			// If the value is bigger than the curren node's data,
			else
			{
				// Update the current node to its right child.
				current = current->m_RChild;
			}
		}

		// If not found, return end iterator.
		return const_iterator(this, nil);
	}
	
	// count Function; Count the number of value from the tree.
	template<typename T>
	size_t RBTree<T>::count(const T& value) const
	{
		// If the value is found, return 1.
		// Otherwise, return 0.
		return (find(value) != end()) ? 1 : 0;
	}
}