#pragma once

/*
* Custom list implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 16~20, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
* 
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#define STList_20250420
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
	// List Functions.
	void push_back(const T& data);	// push_back Function; Add data to the end.
	void push_front(const T& data);	// push_front Function; Add data to the front.
	void pop_back();				// pop_back Function; Remove the last data.
	void pop_front();				// pop_front Function; Remove the first data.
	void clear();					// clear Function; Remove all data.
	bool empty() const;				// empty Function; Check if the list is empty.
	int size() const noexcept;		// size Function; Return the size of the list.
	T& front();						// front Function; Return the first data.
	const T& front() const;			// const front Function; Return the first data as constant.
	T& back();						// back Function; Return the last data.
	const T& back() const;			// const front Function; Return the last data as constant.

public:
	class iterator;			// Iterator declaration.
	class const_iterator;	// Constant iterator declaration.

	// Iterator Functions.
	iterator begin();										// begin Function; Return iterator that points to the first data.
	const_iterator begin() const;							// begin const Function; Const version of begin() for range-based for loop.
	const_iterator cbegin() const;							// cbegin Function; Return constant iterator that points to the first data.
	iterator end();											// end Function; Return iterator that points to the right of the last data.
	const_iterator end() const;								// end const Function; Const version of end() for range-based for loop.
	const_iterator cend() const;							// cend Function; Return constant iterator that points to the right of the last data.
	iterator erase(const iterator& pos);					// erase Function; Erase the data that the given iterator is pointing.
	iterator insert(const T& data, const iterator& iter);	// insert Function; Insert data to the left of the iterator.
	
	class reverse_iterator;			// Reverse iterator declaration.
	class const_reverse_iterator;	// Constant reverse iterator declaration.

	// Reverse Iterator Functions.
	reverse_iterator rbegin();				// rbegin Function; Return reverse iterator that points to the last data.
	const_reverse_iterator crbegin() const;	// crbegin Function; Return constant reverse iterator that points to the last data.
	reverse_iterator rend();				// rend Function; Return reverse iterator that points to the left of the first data.
	const_reverse_iterator crend() const;	// crend Function; Return constant reverse iterator that points to the left of the first data.

public:
	class iterator
	{
	private:
		list*		m_pList;	// Member pointer to store address of list.
		Node<T>*	m_pNode;	// Member pointer to store address of node.
		bool		m_isValid;	// Member variable to test validity of iterator.
	public:
		// Testing functions
		// ValidityTest Function; Check if the iterator is valid.
		void ValidityTest() const
		{
			// If the list or node pointer points to nothing, or iterator is not valid,
			if (nullptr == m_pList || nullptr == m_pNode || !m_isValid)
			{
				throw std::runtime_error("Invalid Iterator");
			}
		}
		// Operator Overloading.
		// Operator Former *; Access the data that the iterator is pointing.
		T& operator *()
		{
			// Check iterator.
			ValidityTest();

			// Return the pointed value.
			return this->m_pNode->m_Data;
		}
		// Operator Former ++; Increase iterator by 1.
		iterator& operator ++()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the next node.
			m_pNode = m_pNode->m_NextNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter ++; Increase iterator by 1 after assign operator.
		iterator operator ++(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			iterator temp = *this;

			// Increase the iterator.
			++(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator Former --; Decrease iterator by 1.
		iterator& operator --()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the previous node.
			m_pNode = m_pNode->m_PrevNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter --; Decrease iterator by 1 after assign operator.
		iterator operator --(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			iterator temp = *this;

			// Decrease the iterator.
			--(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator ==; Check if two iterators are the same.
		bool operator ==(const iterator& iter) const
		{
			return (this->m_pNode == iter.m_pNode && this->m_pList == iter.m_pList);
		}
		// Operator !=; Check if two iterators are not the same.
		bool operator != (const iterator& iter) const
		{
			return !(*this == iter);
		}

	public:
		// Constructor; Initialize member variables with default values.
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_isValid(false)
		{ }
		// Parameterized constructor; Initialize the member variables with given data.
		iterator(list* list, Node<T>* node)
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
		~iterator()
		{ }

		friend class list<T>;	// Allow access to private members by list.
	};

	class const_iterator
	{
	private:
		const list*		m_pList;	// Member pointer to store address of list (constant).
		const Node<T>*	m_pNode;	// Member pointer to store address of node (constant).
		bool			m_isValid;	// Member variable to test validity of iterator.
	public:
		// Testing functions
		// ValidityTest Function; Check if the const_iterator is valid.
		bool ValidityTest() const
		{
			// If the list or node pointer points to nothing, or iterator is not valid,
			if (nullptr == m_pList || nullptr == m_pNode || !m_isValid)
			{
				throw std::runtime_error("Invalid Iterator");
			}

			// If the iterator is valid, return true.
			return true;
		}
		// Operator Overloading.
		// Operator Former *; Access the data that the const_iterator is pointing.
		const T& operator *() const
		{
			// Check iterator.
			ValidityTest();

			// Return the pointed value.
			return this->m_pNode->m_Data;
		}
		// Operator Former ++; Increase const_iterator by 1.
		const_iterator& operator ++()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the next node.
			m_pNode = m_pNode->m_NextNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter ++; Increase const_iterator by 1 after assign operator.
		const_iterator operator ++(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			const_iterator temp = *this;

			// Increase the iterator.
			++(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator Former --; Decrease const_iterator by 1.
		const_iterator& operator --()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the previous node.
			m_pNode = m_pNode->m_PrevNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter --; Decrease const_iterator by 1 after assign operator.
		const_iterator operator --(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			const_iterator temp = *this;

			// Decrease the iterator.
			--(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator ==; Check if two const_iterator are the same.
		bool operator ==(const const_iterator& iter) const
		{
			return (this->m_pNode == iter.m_pNode && this->m_pList == iter.m_pList);
		}
		// Operator !=; Check if two const_iterator are not the same.
		bool operator != (const const_iterator& iter) const
		{
			return !(*this == iter);
		}

	public:
		// Parameterized constructor; Initialize the member variables with given data.
		const_iterator(const list* list, const Node<T>* node)
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
		~const_iterator()
		{ }

		friend class list<T>;	// Allow access to private members by list.
	};

	class reverse_iterator
	{
	private:
		list*		m_pList;	// Member pointer to store address of list.
		Node<T>*	m_pNode;	// Member pointer to store address of node.
		bool		m_isValid;	// Member variable to test validity of iterator.
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
		reverse_iterator& operator ++()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the previous node.
			m_pNode = m_pNode->m_PrevNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter ++; Increase reverse_iterator by 1 after assign operator.
		reverse_iterator operator ++(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			reverse_iterator temp = *this;

			// Increase the iterator.
			++(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator Former --; Decrease reverse_iterator by 1.
		reverse_iterator& operator --()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the next node.
			m_pNode = m_pNode->m_NextNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter --; Decrease reverse_iterator by 1 after assign operator.
		reverse_iterator operator --(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			reverse_iterator temp = *this;

			// Decrease the iterator.
			--(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator ==; Check if two reverse_iterators are the same.
		bool operator ==(const reverse_iterator& iter) const
		{
			return (this->m_pNode == iter.m_pNode && this->m_pList == iter.m_pList);
		}
		// Operator !=; Check if two reverse_iterators are not the same.
		bool operator != (const reverse_iterator& iter) const
		{
			return !(*this == iter);
		}

		// Reverse iterator function
		// base Function; Return the forward iterator based on the reverse iterator.
		iterator base();

	public:
		// Constructor; Initialize member variables with default values.
		reverse_iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_isValid(false)
		{
		}
		// Parameterized constructor; Initialize the member variables with given data.
		reverse_iterator(list* list, Node<T>* node)
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
		~reverse_iterator()
		{ }

		friend class list<T>;	// Allow access to private members by list.
	};

	class const_reverse_iterator
	{
	private:
		const list*		m_pList;	// Member pointer to store address of list.
		const Node<T>*	m_pNode;	// Member pointer to store address of node.
		bool			m_isValid;	// Member variable to test validity of iterator.
	public:
		// Testing functions
		// ValidityTest Function; Check if the const_reverse_iterator is valid.
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
		// Operator Former *; Access the data that the const_reverse_iterator is pointing.
		const T& operator *() const
		{
			// Check iterator.
			ValidityTest();

			// Return the pointed value.
			return this->m_pNode->m_Data;
		}
		// Operator Former ++; Increase const_reverse_iterator by 1.
		const_reverse_iterator& operator ++()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the previous node.
			m_pNode = m_pNode->m_PrevNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter ++; Increase const_reverse_iterator by 1 after assign operator.
		const_reverse_iterator operator ++(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			const_reverse_iterator temp = *this;

			// Increase the iterator.
			++(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator Former --; Decrease const_reverse_iterator by 1.
		const_reverse_iterator& operator --()
		{
			// Check iterator.
			ValidityTest();

			// Move the iterator to the next node.
			m_pNode = m_pNode->m_NextNode;

			// Return the iterator.
			return *this;
		}
		// Operator Latter --; Decrease const_reverse_iterator by 1 after assign operator.
		const_reverse_iterator operator --(int)
		{
			// Check iterator.
			ValidityTest();

			// Store current iterator.
			const_reverse_iterator temp = *this;

			// Decrease the iterator.
			--(*this);

			// Return the stored iterator.
			return temp;
		}
		// Operator ==; Check if two const_reverse_iterators are the same.
		bool operator ==(const const_reverse_iterator& iter) const
		{
			return (this->m_pNode == iter.m_pNode && this->m_pList == iter.m_pList);
		}
		// Operator !=; Check if two const_reverse_iterators are not the same.
		bool operator != (const const_reverse_iterator& iter) const
		{
			return !(*this == iter);
		}

		// Reverse iterator function
		// base Function; Return the forward iterator based on the reverse iterator.
		const_iterator base();

	public:
		// Parameterized constructor; Initialize the member variables with given data.
		const_reverse_iterator(const list* list, const Node<T>* node)
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
		~const_reverse_iterator()
		{ }

		friend class list<T>;	// Allow access to private members by list.
	};

	// Default Constructor: Initialize members to their default values.
	list();
	// List initializing Constructor: Initialize members with a list.
	list(std::initializer_list<T> init);
	// Destructor: Release all nodes, reinitialize members to their default values.
	~list();

	static bool isAuthentic()
	{
	#ifdef STList_20250420
		return true;
	#else
		return false;
	#endif
	}
};

// Default Constructor: Initialize members to their default values.
template <typename T>
list<T>::list()
	: m_HeadNode(nullptr)
	, m_TailNode(nullptr)
	, m_Count(0)
{ }

template<typename T>
list<T>::list(std::initializer_list<T> init)
	: list()
{
	for (const T& val : init)
	{
		push_back(val);
	}
}

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
inline int list<T>::size() const noexcept
{
	return m_Count;
}

// front Function; Return the first data.
template<typename T>
T& list<T>::front()
{
	// If the list is empty,
	if (empty())
	{
		// Throw an exception.
		throw std::runtime_error("List is empty");
	}

	// Return the first data.
	return m_HeadNode->m_Data;
}

// constant front Function; Return the first data as constant.
template<typename T>
const T& list<T>::front() const
{
	// If the list is empty,
	if (empty())
	{
		// Throw an exception.
		throw std::runtime_error("List is empty");
	}

	// Return the first data.
	return m_HeadNode->m_Data;
}

// back Function; Return the last data. 
template <typename T>
T& list<T>::back()
{
	if (empty())
	{
		throw std::runtime_error("List is empty");
	}

	return m_TailNode->m_Data;
}

// constant back Function; Return the last data as constant. 
template <typename T>
const T& list<T>::back() const
{
	if (empty())
	{
		throw std::runtime_error("List is empty");
	}

	return m_TailNode->m_Data;
}

// begin Function; Return iterator that points to the first data.
template<typename T>
typename list<T>::iterator list<T>::begin()
{
	// If the list is empty,
	if (empty())
	{
		// Return iterator that points to nothing.
		return iterator(nullptr, nullptr);
	}
	// If the list is not empty, return iterator that points to the first node.
	return iterator(this, this->m_HeadNode);
}

// begin const Function; Const version of begin() for range-based for loop.
template<typename T>
typename list<T>::const_iterator list<T>::begin() const
{
	// If the list is empty,
	if (empty())
	{
		// Return iterator that points to nothing.
		return const_iterator(nullptr, nullptr);
	}
	// If the list is not empty, return iterator that points to the first node.
	return const_iterator(this, this->m_HeadNode);
}

// cbegin Function; Return constant iterator that points to the first data.
template<typename T>
typename list<T>::const_iterator list<T>::cbegin() const
{
	// Return the const_iterator that points to the first node (if empty, it will point to nothing).
	return const_iterator(this, this->m_HeadNode);
}

// end Function; Return iterator that points to the right of the last data.
template<typename T>
typename list<T>::iterator list<T>::end()
{
	// Return iterator that points to nothing.
	return iterator(this, nullptr);
}

// end const Function; Const version of end() for range-based for loop.
template<typename T>
typename list<T>::const_iterator list<T>::end() const
{
	return const_iterator(this, nullptr);
}

// cend Function; Return constant iterator that points to the right of the last data.
template<typename T>
typename list<T>::const_iterator list<T>::cend() const
{
	// Return const_iterator that points to nothing.
	return const_iterator(this, nullptr);
}

// erase Function; Erase the data that the given iterator is pointing.
template<typename T>
typename list<T>::iterator list<T>::erase(const iterator& pos)
{
	// If the list is already empty,
	if (empty())
	{
		// Throw an exception.
		throw std::runtime_error("List is empty");
	}

	// Test iterator.
	pos.ValidityTest();

	// Declare a node pointer to store the node the given iteator is pointing.
	Node<T>* deleteNode = pos.m_pNode;
	// Declare a node pointer to store the deleting node's next node.
	Node<T>* nextNode = pos.m_pNode->m_NextNode;
	// Declare a node pointer to store the deleting node's previous node.
	Node<T>* prevNode = pos.m_pNode->m_PrevNode;

	// If erasing the first node,
	if (!prevNode)
	{
		m_HeadNode = nextNode;
	}
	// If erasing the last node,
	else if (!nextNode)
	{
		m_TailNode = prevNode;
	}
	// If erasing the middle node,
	else
	{
		// Set the next node's previous node as the previous node.
		nextNode->m_PrevNode = prevNode;
		// Set the previous node's next node as the next node.
		prevNode->m_NextNode = nextNode;
	}

	// Release memory of the deleting node.
	delete deleteNode;
	// Prevent dangling pointer.
	deleteNode = nullptr;

	// Decrease the node count.
	--m_Count;

	return iterator(this, nextNode);
}

// insert Function; Insert data to the left of the iterator.
template<typename T>
typename list<T>::iterator list<T>::insert(const T& data, const iterator& iter)
{
	// Check iterator.
	if (this != iter.m_pList)
	{
		throw std::runtime_error("Invalid iterator");
	}

	// Declare a node pointer to store the pointed node.
	Node<T>* currNode;
	// Declare a node pointer to store the pointed node's previous node.
	Node<T>* prevNode;
	// If the iterator was end iterator,
	if (nullptr == iter.m_pNode)
	{
		// Set current node to nullptr.
		currNode = nullptr;
		// Set previous node to tail node.
		prevNode = m_TailNode;
	}
	// If the iterator was begin iterator,
	else if (nullptr == iter.m_pNode->m_PrevNode)
	{
		// Set current node to head node.
		currNode = m_HeadNode;
		// Set previous node to nullptr.
		prevNode = nullptr;
	}
	// If the iterator was pointing to the middle node,
	else
	{
		// Set current node to pointed node.
		currNode = iter.m_pNode;
		// Set previous node to previous node of pointed node.
		prevNode = iter.m_pNode->m_PrevNode;
	}

	// Declare a new node with the given data.
	Node<T>* newNode = new Node<T>(data, currNode, prevNode);

	// If the current node is pointing to nothing (end iterator),
	if (!currNode)
	{
		// Update the tail node as the new node.
		m_TailNode = newNode;
	}
	// If the current node is in the middle,
	else
	{
		// Reconnect the current node's previous node to the new node.
		currNode->m_PrevNode = newNode;
	}
	// If the previous node is pointing to nothing (begin iterator),
	if (!prevNode)
	{
		// Update the head node as the new node.
		m_HeadNode = newNode;
	}
	// If the previous node is in the middle,
	else
	{
		// Reconnect the previous node's next node to the new node.
		prevNode->m_NextNode = newNode;
	}

	// Increase the node count.
	++m_Count;

	return iterator(this, newNode);
}

// rbegin Function; Return reverse iterator that points to the last data.
template<typename T>
typename list<T>::reverse_iterator list<T>::rbegin()
{
	// Return reverse iterator that points to the last node.
	return reverse_iterator(this, this->m_TailNode);
}

// crbegin Function; Return constant reverse iterator that points to the last data.
template<typename T>
typename list<T>::const_reverse_iterator list<T>::crbegin() const
{
	// Return reverse iterator that points to the last node.
	return const_reverse_iterator(this, this->m_TailNode);
}

// rend Function; Return reverse iterator that points to the left of the first data.
template<typename T>
typename list<T>::reverse_iterator list<T>::rend()
{
	// Return reverse iterator that points to the left of the first node.
	return reverse_iterator(this, nullptr);
}

// crend Function; Return constant reverse iterator that points to the left of the first data.
template<typename T>
typename list<T>::const_reverse_iterator list<T>::crend() const
{
	// Return reverse iterator that points to the left of the first node.
	return const_reverse_iterator(this, nullptr);
}

// empty Function; Check if the list has no node inside.
template <typename T>
inline bool list<T>::empty() const
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
void list<T>::pop_back()
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
void list<T>::pop_front()
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

// base Function; Return the forward iterator based on the reverse iterator.
template <typename T>
typename list<T>::iterator list<T>::reverse_iterator::base()
{
	// Base points to the 'right' of the reverse iterator

	// If the reverse iterator is rbegin,
	if (this->m_pNode == this->m_pList->m_TailNode)
	{
		// Return end iterator for forward const iterator.
		return iterator(this->m_pList, nullptr);
	}
	else
	{
		return iterator(this->m_pList, this->m_pNode->m_NextNode);
	}
}

// base Function; Return the forward constant iterator based on the constant reverse iterator.
template <typename T>
typename list<T>::const_iterator list<T>::const_reverse_iterator::base()
{
	// Base points to the 'right' of the reverse iterator

	// If the reverse iterator is rbegin,
	if (this->m_pNode == this->m_pList->m_TailNode)
	{
		// Return end iterator for forward const iterator.
		return const_iterator(this->m_pList, nullptr);
	}
	else
	{
		return const_iterator(this->m_pList, this->m_pNode->m_NextNode);
	}
}