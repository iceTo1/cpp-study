#pragma once

/*
* Custom Binary Search Tree implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 23~, 2025
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

	friend class BinarySearchTree<T>; // Allow access to private member by Binary Search Tree class.
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
	TNode<T>* InsertNode(const T& data, TNode<T>* node);
	TNode<T>* EraseNode(TNode<T>* node, T data);
	void PrintInOrder(TNode<T>* node) const;
	TNode<T>* MinimumNode(TNode<T>* node);
	void ClearTree(TNode<T>* node);

public:
	// Public Functions
	void insert(const T& data);
	void erase(const T& data);
	void clear();
	bool search(const T& data);
	const T& findMax() const;
	const T& findMin() const;
	void printInOrder() const;

	// Iterator Functions
	class iterator; // Iterator declaration
	iterator begin();
	iterator end();

public:
	// Iterator class
	class iterator
	{
	private:
		TNode<T>*				m_pNode;	// Member variable to store the node address.
		BinarySearchTree<T>*	m_pTree;	// Member variable to store the tree address.
	public:
		// Operator Overloading
		// Operator *; Access the data through the iterator.
		T& operator*();
		// Operator former ++; Advance the iterator in-orderly.
		iterator& operator++();
		// Operator latter ++; Latter version of ++.
		iterator operator++(int);
		// Operator =; Assign the given iterator to this iterator.
		iterator& operator=(const iterator& other);
		// Operator ==; Check if the two iterators are identical.
		bool operator==(const iterator& other);
		// Operator !=; Check if the two iterators are not identical.
		bool operator!=(const iterator& other);
	public:
		// Default Constructor; Initialize the iterator with default values.
		iterator()
			: m_pNode(nullptr)
			, m_pTree(nullptr)
		{ }
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
TNode<T>* BinarySearchTree<T>::InsertNode(const T& data, TNode<T>* node)
{
	// Base case: If the position to insert is found,
	if (nullptr == node)
	{
		// Set the node pointer to a new node with data and no child.
		node = new TNode<T>(data, nullptr, nullptr);
	}
	else
	{
		// If the data is bigger than the given node.
		if (data > node->m_Data)
		{
			// Call the function recursively to find position to insert in the right side of the tree.
			node->m_pRightNode = InsertNode(data, node->m_pRightNode);
		}
		else
		{
			// Call the function recursively to find position to insert in the left side of the tree.
			node->m_pLeftNode = InsertNode(data, node->m_pLeftNode);
		}
	}

	// Return the new node.
	return node;
}

// [Helper] EraseNode Function; Erase the node that has the given data.
template<typename T>
TNode<T>* BinarySearchTree<T>::EraseNode(TNode<T>* node, T data)
{
	// Base case: If there is no node with the given data,
	if (nullptr == node)
	{
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
	// Return the most left child node.
	return min;
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

