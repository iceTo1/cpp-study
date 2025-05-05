#pragma once

/*
* Custom Binary Search Tree implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 23~24, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

/* This Binary Search Tree does not consider the duplicate value */
/* All operations, sorting is based on in-order */

#include <iostream>
#include <stdexcept>

// Declaration of Binary Search Tree class.
template <typename T>
class BinarySearchTree;

// Node for Binary Search Tree.
template <typename T>
class TreeNode
{
private:
	T				m_Data;			// Member variable to store data.
	TreeNode<T>*	m_pLeftNode;	// Member variable to store left child node.
	TreeNode<T>*	m_pRightNode;	// Member variable to store right child node.
public:
	// Default Constructor; Initialize the member variables with default values.
	TreeNode()
		: m_Data(T())
		, m_pLeftNode(nullptr)
		, m_pRightNode(nullptr)
	{ }
	// Parameterized Constructor; Initialize the member variables with given data.
	TreeNode(const T& data, TreeNode<T>* pLeft, TreeNode<T>* pRight)
		: m_Data(data)
		, m_pLeftNode(pLeft)
		, m_pRightNode(pRight)
	{ }
	// Destructor; No special operation.
	~TreeNode()
	{ }

	// Allow access to private member by Binary Search Tree class.
	friend class BinarySearchTree<T>; 
};

// Nickname the TreeNode to TNode (for convenience).
template <typename T>
using TNode = TreeNode<T>;

// Binary Search Tree class.
template <typename T>
class BinarySearchTree
{
private:
	TNode<T>*	m_pRoot;	// Member variable for root node.
	int			m_Count;	// Member variable to count nodes.
private:
	// Helper Functions (only available internally)
	// InsertNode Function; Insert the node with given data to the correct in-order position.
	TNode<T>* InsertNode(const T& data, TNode<T>* subtree_root);
	// EraseNode Function; Erase the node that has the given data.
	TNode<T>* EraseNode(TNode<T>* node, T data);
	// PrintInOrder Function; Print all data in-order.
	void PrintInOrder(TNode<T>* node) const;
	// MinimumNode Function; Return the minimum value in the tree.
	TNode<T>* MinimumNode(TNode<T>* node);
	// MaximumNode Function; Return the maximum value in the tree.
	TNode<T>* MaximumNode(TNode<T>* node);
	// ClearTree Function; Erase the all node from the tree.
	void ClearTree(TNode<T>* node);
	// SearchNode Function; Search the given data in the tree.
	bool SearchNode(const T& target, TNode<T>* node);

public:
	// Public Functions
	// insert Function; Insert the node with given data to the correct in-order position.
	void insert(const T& data);
	// erase Function; Erase the node that has the given data.
	void erase(const T& data);
	// clear Function; Erase all the nodes in the tree.
	void clear();
	// search Function; Search the given data in the tree.
	bool search(const T& data);
	// findMax Function; Return the right most child node's data.
	const T& findMax() const;
	// findMin Function; Return the left most child node's data.
	const T& findMin() const;
	// print Function; Print all data in-order.
	void print() const;

	
	class iterator; // Iterator declaration
	// Iterator Functions
	// begin Function; Return iterator that points to the first data.
	iterator begin();
	// end Function; Return iterator that points to the last data.
	iterator end();

public:
	// Iterator class
	class iterator
	{
	private:
		BinarySearchTree<T>*	m_pTree;	// Member variable to store the tree address.
		TNode<T>*				m_pNode;	// Member variable to store the node address.
		bool					m_isValid;	// Member variable to check if the iterator is valid.
	public:
		// ValidityTest Function; Test if the iterator is valid.
		void ValidityTest()
		{
			// If the member variables are not valid,
			if ((nullptr == m_pTree) && (nullptr == m_pNode) || !m_isValid)
			{
				// Throw an exception.
				throw std::runtime_error("Iterator Invalid");
			}
		}

		// Operator Overloading
		// Operator *; Access the data through the iterator.
		T& operator*()
		{
			// Check the iterator.
			ValidityTest();

			// Return the data of the node.
			return this->m_pNode->m_Data;
		}

		// Operator former ++; Advance the iterator in-order.
		iterator& operator++()
		{
			// Check the iterator.
			ValidityTest();

			// If there is a right subtree,
			if (nullptr != m_pNode->m_pRightNode)
			{
				// Minimum node of the right subtree is the next node.
				this->m_pNode = MinimumNode(m_pNode->m_pRightNode);
			}
			else
			{
				// Declare a node pointer to find the in-order successor node.
				TNode<T>* successorNode = nullptr;
				// Declare a node pointer to navigate through the node.
				TNode<T>* currentNode = this->m_pTree->m_pRoot;

				// <Finding in-order successor>
				// Iterate while navigating node pointer is not this node.
				while (currentNode != this->m_pNode)
				{
					// If the current node's data is bigger than this node's data,
					if (currentNode->m_Data > this->m_pNode->m_Data)
					{
						// Save the current node as successor node.
						successorNode = currentNode;
						// Continue traversing the current node to find successor.
						currentNode = currentNode->m_pLeftNode;
					}
					// If the current node's data is smaller than this node's data,
					else
					{
						// Continue traversing to current node to find minimum node that has greater value than this node.
						currentNode = currentNode->m_pRightNode;
					}
				}
				// Update the iterator to point to the successor node.
				this->m_pNode = successorNode;
			}
			// Return the updated iterator.
			return *this;
		}

		// Operator latter ++; Latter version of ++.
		iterator operator++(int)
		{
			// Declare an iterator to store current iterator.
			iterator temp(this->m_pTree, this->m_pNode);
			
			// Advance this iterator.
			++(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator former --; Retreat the iterator in-order.
		iterator& operator--()
		{
			// Check the iterator.
			ValidityTest();

			// Declare a node pointer to store predecessor.
			TNode<T>* predecessor = nullptr;
			// Declare a node pointer to store current traversing node.
			TNode<T>* current = m_pTree->m_pRoot;
			
			// If this node has its left child,
			if (this->m_pNode->m_pLeftNode)
			{
				// Set the predecessor to the maximum node of the left subtree.
				predecessor = MaximumNode(m_pNode->m_pLeftNode);
			}
			// If this node does not have left child, 
			else
			{
				// Iterate while the traversing node is not this node.
				while (current != m_pNode)
				{
					// If the traversing node has bigger data than this node,
					if (current->m_Data > m_pNode->m_Data)
					{
						// Continue traversing to its left child subtree.
						current = current->m_pLeftNode;
					}
					// If the traversing node has smaller data than this node,
					else
					{
						// Store the traversing node as predecessor.
						predecessor = current;
						// Continue traversing to the right subtree to find maximum node that has smaller data than this node.
						current = current->m_pRightNode;
					}
				}
				m_pNode = predecessor;
			}
			return *this;
		}

		// Operator latter --; Latter version of --.
		iterator operator--(int)
		{
			// Store this iterator's data.
			iterator temp = *this;
			// Retreat this iterator.
			--this;

			// Return the stored iterator.
			return temp;
		}

		// Operator =; Assign the given iterator to this iterator.
		iterator& operator=(const iterator& other)
		{
			// Check the given iterator.
			other.ValidityTest();

			// Assign the member variables.
			this->m_pTree = other.m_pTree;
			this->m_pNode = other.m_pNode;
			this->m_isValid = true;

			return *this;
		}

		// Operator ==; Check if the two iterators are identical.
		bool operator==(const iterator& other)
		{
			// Check both iterators.
			ValidityTest();
			other.ValidityTest();

			// If both are pointing to the same,
			if (this->m_pTree == other.m_pTree && this->m_pNode == other.m_pNode)
			{
				// Return true.
				return true;
			}
			// Otherwise, return false.
			return false;
		}

		// Operator !=; Check if the two iterators are not identical.
		bool operator!=(const iterator& other)
		{
			// Return the opposite of ==.
			return !(*this == other);
		}

	public:
		// Default Constructor; Initialize the iterator with default values.
		iterator()
			: m_pTree(nullptr)
			, m_pNode(nullptr)
			, m_isValid(false)
		{ }
		// Parameterized Constructor; Initialize the iterator with given values.
		iterator(BinarySearchTree<T>* tree, TNode<T>* node)
			: m_pTree(tree)
			, m_pNode(node)
			, m_isValid(false)
		{
			// If the iterator points to the correct item,
			if (nullptr != m_pTree && nullptr != m_pNode)
			{
				// Update the iterator as valid.
				m_isValid = true;
			}
		}
		// Destructor; No specific operation.
		~iterator()
		{ }

		friend class BinarySearchTree<T>;	// Allow access to private member by Binary Search Tree class.
	};

	// Default Constructor; Initialize the member variables with default values.
	BinarySearchTree()
		: m_pRoot(nullptr)
		, m_Count(0)
	{ }

	// Destructor; Release the memory of all nodes.
	~BinarySearchTree()
	{
		// Delete all the nodes.
		clear();
		// Root node pointer to point nothing.
		m_pRoot = nullptr;
		// Reset the node count.
		m_Count = 0;
	}
};

// [Helper] InsertNode Function; Insert the node with given data to the correct in-order position.
template<typename T>
TNode<T>* BinarySearchTree<T>::InsertNode(const T& data, TNode<T>* subtree_root)
{
	// Base case: If the position to insert is found (result of comparison with leaf node),
	if (nullptr == subtree_root)
	{
		// Set the node pointer to a new node with data and no child.
		subtree_root = new TNode<T>(data, nullptr, nullptr);
	}
	else
	{
		// If the data is bigger than the given node,
		if (data > subtree_root->m_Data)
		{
			// Call the function recursively to find position to insert in the right side of the tree.
			subtree_root->m_pRightNode = InsertNode(data, subtree_root->m_pRightNode);
		}
		// If the data is smaller than the given node,
		else
		{
			// Call the function recursively to find position to insert in the left side of the tree.
			subtree_root->m_pLeftNode = InsertNode(data, subtree_root->m_pLeftNode);
		}
	}

	// Return the new node.
	return subtree_root;
}

// [Helper] EraseNode Function; Erase the node that has the given data.
template<typename T>
TNode<T>* BinarySearchTree<T>::EraseNode(TNode<T>* node, T data)
{
	// Base case: If there is no node with the given data,
	if (nullptr == node)
	{
		// Escape from the recursion.
		return nullptr;
	}

	// If the data is bigger than the data in the node,
	if (data > node->m_Data)
	{
		// Call the function recursively for the left child node.
		node = EraseNode(node->m_pLeftNode, data);
	}
	// If the data is less than the data in the node,
	else if (data < node->m_Data)
	{
		// Call the function recursively for the right child node.
		node = EraseNode(node->m_pRightNode, data);
	}
	else
	{
		// If the node is a leaf node,
		if (nullptr == node->m_pLeftNode && nullptr == node->m_pRightNode)
		{
			// Delete the node.
			delete node;
			// Return null pointer for complete deletion.
			return nullptr;
		}
		// If the node has one child,
		else if (nullptr == node->m_pLeftNode || nullptr == node->m_pRightNode)
		{
			// Save the child node's address to return.
			TNode<T>* child = ((node->m_pLeftNode) ? (node->m_pLeftNode) : (node->m_pRightNode));
			// Delete the node.
			delete node;
			// Return the child node to connect with the parent node.
			return child;
		}
		// If the node has two children,
		else
		{
			// Save the node that has the minimum value of the right side.
			TNode<T>* rightMin = MinimumNode(node->m_pRightNode);
			// Overwrite the deleting node's value with the right minimum node's value.
			node->m_Data = rightMin->m_Data;
			// Delete the right minimum node (Recursively erase to prevent dangling pointer of right minimum node's parent).
			node->m_pRightNode = EraseNode(node->m_pRightNode, rightMin->m_Data);
			rightMin = nullptr;
			// Return the node to connect with the parent node.
			return node;
		}
	}

	// Return the node to connect with the parent node.
	return node;
}

// [Helper] PrintInOrder Function; Print all data in-order.
template<typename T>
void BinarySearchTree<T>::PrintInOrder(TNode<T>* node) const
{
	// Base case: If the node is empty,
	if (nullptr == node)
	{
		// Escape from the recursion.
		return;
	}

	// Print the left child node.
	PrintInOrder(node->m_pLeftNode);
	// Print the current node.
	std::cout << node->m_Data;
	// Print the right child node.
	PrintInOrder(node->m_pRightNode);
}

// [Helper] MinimumNode Function; Return the minimum value in the tree.
template<typename T>
TNode<T>* BinarySearchTree<T>::MinimumNode(TNode<T>* node)
{
	// Store the value of the given node.
	TNode<T>* min = node;
	// Iterate while there is left child node.
	while (min->m_pLeftNode)
	{
		// Update the minimum node to its left child node.
		min = min->m_pLeftNode;
	}
	// Return the left most child node.
	return min;
}

// [Helper] MaximumNode Function; Return the maximum value in the tree.
template<typename T>
TNode<T>* BinarySearchTree<T>::MaximumNode(TNode<T>* node)
{
	// Store the value of the given node.
	TNode<T>* max = node;
	// Iterate while there is right child node.
	while (max->m_pRightNode)
	{
		// Update the maximum node to its right child node.
		max = max->m_pRightNode;
	}
	// Return the right most child node.
	return max;
}

// [Helper] ClearTree Function; Erase the all node from the tree.
template<typename T>
void BinarySearchTree<T>::ClearTree(TNode<T>* node)
{
	// If the node is a leaf node,
	if (nullptr == node->m_pLeftNode && nullptr == node->m_pRightNode)
	{
		// Delete the node.
		delete node;
		node = nullptr;
		// Escape the recursion function.
		return;
	}
	// Delete the left subtree recursively.
	ClearTree(node->m_pLeftNode);
	// Delete the right subtree recursively.
	ClearTree(node->m_pRightNode);

	// Delete the node.
	delete node;
}

// [Helper] SearchNode Function; Search the given data in the tree.
template<typename T>
bool BinarySearchTree<T>::SearchNode(const T& target, TNode<T>* node)
{
	// If the data was not found,
	if (nullptr == node)
	{
		// Return false.
		return false;
	}

	// If the target is bigger than the node's data,
	if (target > node->m_Data)
	{
		// Recursively call the function with right child node.
		return SearchNode(target, node->m_pRightNode);
	}
	// If the target is smaller than the node's data,
	else if (target < node->m_Data)
	{
		// Recursively call the function with left child node.
		return SearchNode(target, node->m_pLeftNode);

	}
	// If the target is found,
	else if (target == node->m_Data)
	{
		// Return true.
		return true;
	}

	// If not found, return false.
	return false;
}

// insert Function; Insert the node with given data to the correct in-order position.
template<typename T>
void BinarySearchTree<T>::insert(const T& data)
{
	// Prompt the recusrive call from the root node, with the data.
	this->m_pRoot = InsertNode(data, this->m_pRoot);
	// Increase the node count.
	++m_Count;
}

// erase Function; Erase the node that has the given data.
template<typename T>
void BinarySearchTree<T>::erase(const T& data)
{
	// Prompt the recursive call from the root node, with the data.
	this->m_pRoot = EraseNode(this->m_pRoot, data);
	// Decrease the node cound.
	--m_Count;
}

// clear Function; Erase all the nodes in the tree.
template<typename T>
void BinarySearchTree<T>::clear()
{
	// If the tree is already empty,
	if (0 == m_Count && nullptr == m_pRoot)
	{
		// Do nothing.
		return;
	}

	// Prompt the recursive call from the root node.
	ClearTree(this->m_pRoot);

	// Reset the root node pointer to nothing.
	m_pRoot = nullptr;

	// Reset the node count to 0;
	m_Count = 0;
}

// search Function; Search the given data in the tree.
template<typename T>
inline bool BinarySearchTree<T>::search(const T& target)
{
	// Prompt the recursive call from the root node, with the data.
	return SearchNode(target, this->m_pRoot);
}

// findMax Function; Return the right most child node's data.
template<typename T>
inline const T& BinarySearchTree<T>::findMax() const
{
	// Return the maximum node's data.
	return (MaximumNode(this->m_pRoot))->m_Data;
}

// findMin Function; Return the left most child node's data.
template<typename T>
inline const T& BinarySearchTree<T>::findMin() const
{
	// Return the minimum node's data.
	return (MinimumNode(this->m_pRoot))->m_Data;
}

// print Function; Print all data in-order.
template<typename T>
inline void BinarySearchTree<T>::print() const
{
	// Prompt the recursive call from the root node, with the data.
	PrintInOrder(this->m_pRoot);
}

// begin Function; Return iterator that points to the first data.
template<typename T>
typename BinarySearchTree<T>::iterator BinarySearchTree<T>::begin()
{
	// Return iterator with the minimum node.
	return iterator(this, MinimumNode(this->m_pRoot));
}

// end Function; Return iterator that points to the last data.
template<typename T>
typename BinarySearchTree<T>::iterator BinarySearchTree<T>::end()
{
	// Return iterator with the next to the maximum node.
	return iterator(this, nullptr);
}