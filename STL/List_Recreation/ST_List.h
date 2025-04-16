#pragma once

/*
* Custom list implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 16~, 2025
*
* This code was written and maintained by Seungtack Lee for educational purposes.
* If you are using this for learning, please give proper credit.
* Unauthorized use for academic or job submissions is prohibited.
*/

// Declaration of list class
template <typename T>
class list;

// Node class
template <typename T>
class Node
{
	friend class list<T>;	// Allow access to private members to list class.
private:
	T		m_Data;			// Data stored in the node.
	Node*	m_pNextNode;	// Node pointer for next node.
	Node*	m_pPrevNode;	// Node pointer for previous node.
public:
	// Default Constructor: Initialize members to their default values.
	Node()
		: m_Data(T())
		, m_pNextNode(nullptr)
		, m_pPrevNode(nullptr)
	{ }
	// Parameterized Constructor: Initialize members by given data.
	Node(const T& data, Node* next, Node* prev)
		: m_Data(data)
		, m_pNextNode(next)
		, m_pPrevNode(prev)
	{ }
	// Destructor: no specific operation.
	~Node()
	{ }
};

// List class
template <typename T>
class list
{
private:
	Node<T>*	m_pHeadNode;	// Member pointer to store the first node.
	Node<T>*	m_pTailNode;	// Member pointer to store the last node.
	int			m_Count;		// Member variable to store data count.
public:
	// Default Constructor: Initialize members to their default values.
	list();
	// Destructor: Release all nodes, reinitialize members to their default values.
	~list();
public:

};

// Default Constructor: Initialize members to their default values.
template <typename T>
list<T>::list()
	: m_pHeadNode(nullptr)
	, m_pTailNode(nullptr)
	, m_Count(0)
{ }

// Destructor: Release all nodes, reinitialize members to their default values.
template <typename T>
list<T>::~list()
{
	// Declare a temporary node pointer to iterate through from head node.
	Node<T>* temp = m_pHeadNode;

	// While temp node is not null pointer,
	while (temp)
	{
		// Assign node to delete to temp node.
		Node<T>* deleteNode = temp;
		// Move temp node to the next node.
		temp = temp->m_pNextNode;
		// Release the memory of delete node.
		delete deleteNode;
	}

	// After deleting every node, reinitialize the list members to their default values.
	this->m_pHeadNode = nullptr;
	this->m_pTailNode = nullptr;
	this->m_Count = 0;
}