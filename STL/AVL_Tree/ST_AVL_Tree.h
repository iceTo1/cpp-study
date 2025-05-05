#pragma once

/*
* Custom AVL Tree implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 30 ~ May 5, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include <iostream>
#include "../include/utility/utility.h"

template <typename T>
class TNode
{
private:
	T m_Value;			// Member variable to store value.
	int m_Height;		// Member variable to store the node's height.
	TNode* m_LChild;	// Member variable to store left child node's address.
	TNode* m_RChild;	// Member variable to store right child node's address.
public:
	// Default constructor; Initialize the members with default values.
	TNode()
		: m_Value(T())
		, m_Height(0)
		, m_LChild(nullptr)
		, m_RChild(nullptr)
	{ }
	// Parameterized constructor; Initialize the members with given values. 
	TNode(const T& val)
		: m_Value(val)
		, m_Height(0)
		, m_LChild(nullptr)
		, m_RChild(nullptr)
	{ }
	// Destructor; No special operation.
	~TNode() {}

	friend class AVLTree<T>; // Grant access to private members by AVLTree.
};

template <typename T>
class AVLTree
{
private:
	TNode<T>* m_Root;	// Member variable to store the root node.
private:
	// Helper Functions
	// [Helper] updateHeight Function; Calculate the height of the tree (maximum height).
	void updateHeight(TNode<T>* node);

	// [Helper] height Function; Return the height of the tree.
	int height(TNode<T>* node);

	// [Helper] getBalanceFactor Function; Calculate the balance factor of the given node.
	int getBalanceFactor(TNode<T>* node) const;
	
	// [Helper] rightRotate Function; Rotate the nodes to the right for LL imbalance.
	TNode<T>* rightRotate(TNode<T>* node);
	
	// [Helper] leftRotate Function; Rotate the nodes to the left for RR imbalance.
	TNode<T>* leftRotate(TNode<T>* node);
	
	// [Helper] balance Function; Self-balance the tree based on the balance factor.
	TNode<T>* balance(TNode<T>* root);
	
	// [Helper] insert Function; Insert the given new node to the given subtree.
	TNode<T>* insert(TNode<T>* root, TNode<T>* new_node);
	
	// [Helper] minValueNode Function; Find the left most child node.
	TNode<T>* minValueNode(const TNode<T>* node) const;
	
	// [Helper] deleteNode Function; Delete the node with given value, starting from the given node.
	TNode<T>* deleteNode(TNode<T>* root, T value);
	
	// [Helper] PrintInOrder Function; Print the data in-order.
	void PrintInOrder(const TNode<T>* node) const;
public:
	// Default Constructor; Initialize the member with default value.
	AVLTree();
	// empty Function; Check if the tree is empty.
	bool empty() const { return nullptr == m_Root; }
	
	// insert Function; Insert the value to the tree.
	void insert(const T& value);
	
	// erase Function; Delete the value from the tree.
	void erase(const T& value);
	
	// search Function; Search the given value from the tree.
	bool search(const T& target) const;
	
	// print Function; Print the data in order.
	void print() const;
};

// Default Constructor; Initialize the member with default value.
template <typename T>
AVLTree<T>::AVLTree()
	: m_Root(nullptr)
{ }

// insert Function; Insert the value to the tree.
template<typename T>
void AVLTree<T>::insert(const T & value)
{
	// Create a new tree node with the given value.
	TNode<T>* new_node = new TNode<T>(value);
	// Call helper function to perform insertion.
	m_Root = insert(m_Root, new_node);
}

// erase Function; Delete the value from the tree.
template<typename T>
void AVLTree<T>::erase(const T& value)
{
	// If the tree is already empty,
	if (empty())
	{
		// Throw an exception.
		throw std::underflow_error("Tree is empty");
	}
	// Call the helper function for deletion.
	m_Root = deleteNode(m_Root, value);
}

// search Function; Search the given value from the tree.
template<typename T>
bool AVLTree<T>::search(const T& target) const
{
	// Declare a node to traverse the tree from the root.
	TNode<T>* curr = this->m_Root;

	// Iterate while the current node pointer is valid.
	while (curr)
	{
		// If the target is found,
		if (curr->m_Value == target)
		{
			// Return true.
			return true;
		}
		// If the target is less than the current node's data,
		else if (target < curr->m_Value)
		{
			// Update the current node pointer to its left child node.
			curr = curr->m_LChild;
		}
		// If the target is greater than the current node's data,
		else
		{
			// Update the current node pointer to its right child node.
			curr = curr->m_RChild;
		}
	}
	// If not found, return false.
	return false;
}

// print Function; Print the data in order.
template<typename T>
void AVLTree<T>::print() const
{
	// If the tree is empty,
	if (empty())
	{
		// Throw an exception.
		throw std::invalid_argument("tree is already empty");
	}

	// Call helper function to print in-order.
	PrintInOrder(m_Root);
}

// [Helper] updateHeight Function; Calculate the height of the tree (maximum height).
template<typename T>
void AVLTree<T>::updateHeight(TNode<T>* node)
{
	// If the given node is below the leaf, or if the tree is empty,
	if (nullptr == node)
	{
		// Return the height as -1.
		return;
	}
	// Otherwise, compute the height of each subtree.
	else
	{
		int lHeight = height(node->m_LChild);
		int rHeight = height(node->m_RChild);

		// Return the max height for subtree height
		node->m_Height = ST::max(lHeight, rHeight) + 1;
	}
}

// [Helper] height Function; Return the height of the tree.
template<typename T>
int AVLTree<T>::height(TNode<T>* node)
{
	return (nullptr == node) ? -1 : node->m_Height;
}

// [Helper] getBalanceFactor Function; Calculate the balance factor of the given node.
template<typename T>
int AVLTree<T>::getBalanceFactor(TNode<T>* node) const
{
	// If the given node is empty,
	if (nullptr == node)
	{
		// Return -1.
		return -1;
	}

	// Otherwise, calculate the balance factor.
	return height(node->m_LChild) - height(node->m_RChild);
}

// [Helper] rightRotate Function; Rotate the nodes to the right for LL imbalance.
template<typename T>
TNode<T>* AVLTree<T>::rightRotate(TNode<T>* node)
{
	// Declare variables to store the unbalanced nodes.
	TNode<T>* node_x = node->m_LChild;
	TNode<T>* node_c = node_x->m_RChild;

	// Rotate to the right.
	node_x->m_RChild = node;
	node->m_LChild = node_c;

	// Update the heights.
	updateHeight(node);
	updateHeight(node_x);

	// Return the new root node.
	return node_x;
}

// [Helper] leftRotate Function; Rotate the nodes to the left for RR imbalance.
template<typename T>
TNode<T>* AVLTree<T>::leftRotate(TNode<T>* node)
{
	// Declare variables to store the unbalanced nodes.
	TNode<T>* node_x = node->m_RChild;
	TNode<T>* node_c = node_x->m_LChild;

	// Rotate to the left.
	node_x->m_LChild = node;
	node->m_RChild = node_c;

	// Update the heights.
	updateHeight(node);
	updateHeight(node_x);

	// Return the new root node.
	return node_x;
}

// [Helper] balance Function; Self-balance the tree based on the balance factor.
template<typename T>
TNode<T>* AVLTree<T>::balance(TNode<T>* root)
{
	// If the given node is not valid,
	if (nullptr == root)
	{
		// Return null pointer.
		return nullptr;
	}

	// Calculate and update the node's height.
	updateHeight(root);

	// <Balancing the tree>
	// Declare a balance factor of the given node.
	int bf = getBalanceFactor(root);

	// If left-heavy,
	if (bf > 1)
	{
		// If LR Imbalance,
		if (getBalanceFactor(root->m_LChild) < 0)
		{
			// Perform Left Rotation for the child node.
			root->m_LChild = leftRotate(root->m_LChild);
		}
		// Perform Right Rotation for LL Imbalance, or LR after left rotation.
		return rightRotate(root);
	}

	// If right-heavy,
	if (bf < -1)
	{
		// If RL Imbalance,
		if (getBalanceFactor(root->m_RChild) > 0)
		{
			// Perform Right Rotation for the child node.
			root->m_RChild = rightRotate(root->m_RChild);
		}
		// Perform Left Rotation for RR Imbalance, or RL after right rotation.
		return leftRotate(root);
	}

	// If the given node is already balanced, return the node.
	return root;
}

// [Helper] insert Function; Insert the given new node to the given subtree.
template<typename T>
TNode<T>* AVLTree<T>::insert(TNode<T>* root, TNode<T>* new_node)
{
	// If inserting to an empty tree,
	if (nullptr == root)
	{
		// Assign the new node to the root.
		root = new_node;

		// Return the new root node.
		return root;
	}

	// If the inserting value is bigger than the subtree root's value,
	if (new_node->m_Value > root->m_Value)
	{
		root->m_RChild = insert(root->m_RChild, new_node);
	}

	// If the inserting value is smaller than the subtee root's value,
	else if (new_node->m_Value < root->m_Value)
	{
		root->m_LChild = insert(root->m_LChild, new_node);
	}

	// If the value is the same,
	else
	{
		std::cout << "Duplicate value found.\n";
		return root;
	}

	// Check the balance after insertion.
	return balance(root);
}

// [Helper] minValueNode Function; Find the left most child node.
template<typename T>
TNode<T>* AVLTree<T>::minValueNode(const TNode<T>* node) const
{
	// Declare a node pointer to store the given node.
	TNode<T>* leftmost = node;

	// Iterate while the current node has its left child.
	while (leftmost->m_LChild)
	{
		// Update the current node to its left child node.
		leftmost = leftmost->m_LChild;
	}

	// Return the left most node.
	return leftmost;
}

// [Helper] deleteNode Function; Delete the node with given value, starting from the given node.
template<typename T>
TNode<T>* AVLTree<T>::deleteNode(TNode<T>* root, T value)
{
	// <Traverse through the tree to find the deleting node>

	// If the deleting value is not found,
	if (nullptr == root)
	{
		// Throw an exception.
		throw std::invalid_argument("deleting value not found");
	}
	// If the value is smaller than the given node's value,
	else if (value < root->m_Value)
	{
		// Update the given node to its left child.
		root->m_LChild = deleteNode(root->m_LChild, value);
	}
	// If the value is bigger than the given node's value,
	else if (value > root->m_Value)
	{
		// Update the given node to its right child.
		root->m_RChild = deleteNode(root->m_RChild, value);
	}
	// If the node to delete is found,
	else
	{
		// <Deleting the node>
		// If the given node has no child, or only one child,
		// Delete the node and replace the node to its child.
		
		// If the given node does not have left child,
		if (nullptr == root->m_LChild)
		{
			// Store the right child's data.
			TNode<T>* temp = root->m_RChild;
			// Delete the given node.
			delete root;
			// Return the stored child's data.
			return temp;
		}
		// If the given node does not have right child,
		else if (nullptr == root->m_RChild)
		{
			// Store the left child's data.
			TNode<T>* temp = root->m_LChild;
			// Delete the given node.
			delete root;
			// Return the stored child's ddata.
			return temp;
		}
		// If the given node has both children,
		else
		{
			// Store the left most node from the right subtree.
			TNode<T>* rightmin = minValueNode(root->m_RChild);

			// Replace the given node's data with the right minimum node.
			root->m_Value = rightmin->m_Value;

			// Delete the right minimum node.
			root->m_RChild = deleteNode(root->m_RChild, rightmin->m_Value);
		}
	}
	
	return balance(root);

}

// [Helper] PrintInOrder Function; Print the data in-order.
template<typename T>
void AVLTree<T>::PrintInOrder(const TNode<T>* node) const
{
	// If the node has left child,
	if (node->m_LChild)
	{
		// Recursively call the printing function to the left child.
		PrintInOrder(node->m_LChild);
	}
	// Print the node's data.
	std::cout << node->m_Value << " ";
	// If the node has right child,
	if (node->m_RChild)
	{
		// Recursively call the printing function to the right child.
		PrintInOrder(node->m_RChild);
	}
}