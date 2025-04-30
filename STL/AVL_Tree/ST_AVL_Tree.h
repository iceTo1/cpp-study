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
* <Attribution>
* The structure of the test code was inspired by the educational content from the following source:
* Channel: withhoneyc
* URL: https://www.youtube.com/@withhoneyc
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include <iostream>

template <typename T>
class TreeNode
{
private:
	T m_Value;
	TreeNode* m_LChild;
	TreeNode* m_RChild;
public:
	TreeNode();
	TreeNode(const T& val);

	friend class AVLTree<T>;
};

template <typename T>
class AVLTree
{
private:
	TreeNode<T>* m_Root;
private:
	// Helper Functions
	int height(TreeNode<T>* root);
	int getBalanceFactor(TreeNode<T>* node);
	TreeNode<T>* rightRotate(TreeNode<T>* node);
	TreeNode<T>* leftRoatte(TreeNode<T>* node);
	TreeNode<T>* insert(TreeNode<T>* root, TreeNode<T>* new_node);
	TreeNode<T>* minValueNode(TreeNode<T>* node);
	TreeNode<T>* deleteNode(TreeNode<T>* root, T value);
	void PrintInOrder(TreeNode<T>* node) const;
public:
	AVLTree();
	bool isEmpty() const;
	void insert(const T& value);
	void deleteNode(const T& value);
	bool search(const T& target) const;
	void PrintInOrder() const;
};