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

#include <stdexcept>

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
	Node*	m_NextNode;		// Node pointer for next node.
	Node*	m_PrevNode;		// Node pointer for previous node.
public:
	// Default Constructor: Initialize members to their default values.
	Node()
		: m_Data(T())
		, m_NextNode(nullptr)
		, m_PrevNode(nullptr)
	{ }
	// Parameterized Constructor: Initialize members by given data.
	Node(const T& data, Node* next, Node* prev)
		: m_Data(data)
		, m_NextNode(next)
		, m_PrevNode(prev)
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
	Node<T>*	m_HeadNode;		// Member pointer to store the first node.
	Node<T>*	m_TailNode;		// Member pointer to store the last node.
	int			m_Count;		// Member variable to store node count.
public:
	void push_back(const T& data);
	void push_front(const T& data);
	void popback();
	void popfront();
	void clear();
	bool empty();
	int size() const;
public:
	// Default Constructor: Initialize members to their default values.
	list();
	// Destructor: Release all nodes, reinitialize members to their default values.
	~list();
};

// Default Constructor: Initialize members to their default values.
template <typename T>
list<T>::list()
	: m_HeadNode(nullptr)
	, m_TailNode(nullptr)
	, m_Count(0)
{ }

// Destructor: Release all nodes, reinitialize members to their default values.
template <typename T>
list<T>::~list()
{
	// Declare a temporary node pointer to iterate through from head node.
	Node<T>* temp = m_HeadNode;

	// While temp node is not null pointer,
	while (temp)
	{
		// Assign node to delete to temp node.
		Node<T>* deleteNode = temp;
		// Move temp node to the next node.
		temp = temp->m_NextNode;
		// Release the memory of delete node.
		delete deleteNode;
	}

	// After deleting every node, reinitialize the list members to their default values.
	this->m_HeadNode = nullptr;
	this->m_TailNode = nullptr;
	this->m_Count = 0;
}

// size Function; Return the node count.
template <typename T>
inline int list<T>::size() const
{
	return m_Count;
}

// empty Function; Check if the list has no node inside.
template <typename T>
inline bool list<T>::empty()
{
	// If the list is empty, return true.
	return (m_Count == 0);
}

// push_back Function; Add data to the end of the list.
template<typename T>
void list<T>::push_back(const T& data)
{
	// Create a new node that has data, pointing to nothing for next node, and tail node for previous node.
	Node<T>* newNode = new Node<T>(data, nullptr, m_TailNode);
	// If the list was empty,
	if (empty())
	{
		// Update head node as the new node.
		m_HeadNode = newNode;
		// Update tail node as the new node.
		m_TailNode = newNode;
	}
	// If the list was not empty,
	else
	{
		// Set previous tail node's next node as the new node.
		m_TailNode->m_NextNode = newNode;
		// Update tail node as the new node.
		m_TailNode = newNode;
	}
	// Increase the node count.
	++m_Count;
}

// push_front Function; Add data to the front of the list.
template <typename T>
void list<T>::push_front(const T& data)
{
	// Create a new node that has data, pointing to head node for next node, and nothing for previous node.
	Node<T>* newNode = new Node<T>(data, m_HeadNode, nullptr);

	// If the list was empty,
	if (empty())
	{
		// Update the head node and tail node.
		m_HeadNode = newNode;
		m_TailNode = newNode;
	}
	// If the list was not empty,
	else
	{
		// Set the previous head node's previous node as the new node.
		m_HeadNode->m_PrevNode = newNode;
		// Update the head node as the new node.
		m_HeadNode = newNode;
	}
	// Increase node count.
	++m_Count;
}

// popback Function; Remove the last node of the list.
template <typename T>
void list<T>::popback()
{
	// If the list was empty,
	if (empty())
	{
		// Throw an exception.
		throw std::runtime_error("List is empty");
	}
	
	// Declare a node pointer for deletion.
	Node<T>* deleteNode = m_TailNode;

	// If there was only one node,
	if (1 == m_Count)
	{
		// Update the head node and tail node to point nothing.
		m_HeadNode = nullptr;
		m_TailNode = nullptr;
	}
	else
	{
		// Move the tail node to the left.
		m_TailNode = m_TailNode->m_PrevNode;
		// Update the new tail node to have nothing for next node.
		m_TailNode->m_NextNode = nullptr;
	}
	
	// Release memory of the previous tail node.
	delete deleteNode;
	// Prevent dangling pointer.
	deleteNode = nullptr;

	// Decrease the node count.
	--m_Count;
}

// popfront Function; Remove the first node of the list.
template <typename T>
void list<T>::popfront()
{
	// If the list was empty,
	if (empty())
	{
		// Throw an exception.
		throw std::runtime_error("List is empty");
	}

	// Declare a node pointer for deletion.
	Node<T>* deleteNode = m_HeadNode;

	// If there was only one node,
	if (1 == m_Count)
	{
		// Update the head node and tail node to point nothing.
		m_HeadNode = nullptr;
		m_TailNode = nullptr;
	}
	else
	{
		// Move the head node to the right.
		m_HeadNode = m_HeadNode->m_NextNode;
		// Update the previous node of the new head node as nothing.
		m_HeadNode->m_PrevNode = nullptr;

	}

	// Release the memory of the previous head node.
	delete deleteNode;
	// Prevent dangling pointer.
	deleteNode = nullptr;

	// Decrease the node count.
	--m_Count;
}

// clear Function; Remove all the nodes from the list.
template <typename T>
void list<T>::clear()
{
	// If the list is already empty,
	if (empty())
	{
		// Do nothing
		return;
	}
	// If the list is not empty,
	else
	{
		// Create a node pointer for pointing before deleting.
		Node<T>* pointNode = m_HeadNode;
		// Iterate through the list.
		while (nullptr != pointNode)
		{
			// Create a node for deletion.
			Node<T>* deleteNode = pointNode;
			// Advance the pointing node.
			pointNode = pointNode->m_NextNode;
			// Release memory of the delete node.
			delete deleteNode;
		}

		// Update the head and tail nodes to point nothing.
		m_HeadNode = nullptr;
		m_TailNode = nullptr;

		// Update the point node to point nothing.
		pointNode = nullptr;

		// Reinitialize the count as 0.
		m_Count = 0;
	}
}