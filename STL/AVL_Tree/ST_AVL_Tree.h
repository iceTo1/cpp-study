#pragma once

/*
* Custom AVL Tree implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 30~, 2025
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
	TNode* m_LChild;	// Member variable to store left child node's address.
	TNode* m_RChild;	// Member variable to store right child node's address.
public:
	// Default constructor; Initialize the members with default values.
	TNode()
		: m_Value(T())
		, m_LChild(nullptr)
		, m_RChild(nullptr)
	{ }
	// Parameterized constructor; Initialize the members with given values. 
	TNode(const T& val)
		: m_Value(val)
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
	// [Helper] height Function; Return the height of the tree (maximum height).
	int height(TNode<T>* node);
	// [Helper] getBalanceFactor Function; Calculate the balance factor of the given node.
	int getBalanceFactor(TNode<T>* node) const;
	// [Helper] rightRotate Function; Rotate the nodes to the right for LL imbalance.
	TNode<T>* rightRotate(TNode<T>* node);
	// [Helper] leftRotate Function; Rotate the nodes to the left for RR imbalance.
	TNode<T>* leftRoatate(TNode<T>* node);
	// [Helper] insert Function; Insert the given new node to the given subtree.
	TNode<T>* insert(TNode<T>* root, TNode<T>* new_node);
	// [Helper] minValueNode Function; 
	TNode<T>* minValueNode(TNode<T>* node) const;
	// [Helper] deleteNode Function; 
	TNode<T>* deleteNode(TNode<T>* root, T value);
	// [Helper] PrintInOrder Function; 
	void PrintInOrder(TNode<T>* node) const;
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

// [Helper] height Function; Return the height of the tree (maximum height).
template<typename T>
int AVLTree<T>::height(TNode<T>* node)
{
	// If the given node is below the leaf, or if the tree is empty,
	if (nullptr == node)
	{
		// Return the height as -1.
		return -1;
	}
	// Otherwise, compute the height of each subtree.
	else
	{
		int lHeight = height(node->m_LChild);
		int rHeight = height(node->m_RChild);

		// Return the max height for subtree height
		return ST::max(lHeight, rHeight) + 1;
	}
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
	TNode<T>* node_1 = node->m_LChild;
	TNode<T>* node_2 = node_1->m_LChild;

	// Rotate to the right.
	node_1->m_LChild = node_2;
	node_1->m_RChild = node;

	// Return the new root node.
	return node_1;
}

// [Helper] leftRotate Function; Rotate the nodes to the left for RR imbalance.
template<typename T>
TNode<T>* AVLTree<T>::leftRoatate(TNode<T>* node)
{
	// Declare variables to store the unbalanced nodes.
	TNode<T>* node_1 = node->m_RChild;
	TNode<T>* node_2 = node_1->m_RChild;

	// Rotate to the left.
	node_1->m_LChild = node;
	node_1->m_RChild = node_2;

	// Return the new root node.
	return node_1;
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

	// After insertion, check for imbalance, and make the AVL Tree balanced by proper rotation.



	return nullptr;
}
