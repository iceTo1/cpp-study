#pragma once

/*
* Custom list implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 16~20, 2025
* Edit: Apr 28~ , 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
* 
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#define STList_20250430
#include <stdexcept>
#include "../list/list_iterators.h"


namespace ST
{
	// Declaration of list class
	template <typename T>
	class list;

	// Node class
	template <typename T>
	class Node
	{
		friend class list<T>;	// Allow access to private members to list class.
		friend class ST::list_iterator<T>;
		friend class ST::list_const_iterator<T>;
		friend class ST::list_reverse_iterator<T>;
		friend class ST::list_const_reverse_iterator<T>;
	private:
		T		m_Data;			// Data stored in the node.
		Node* m_NextNode;		// Node pointer for next node.
		Node* m_PrevNode;		// Node pointer for previous node.

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
		using iterator = ST::list_iterator<T>;
		using const_iterator = ST::list_const_iterator<T>;
		using reverse_iterator = ST::list_reverse_iterator<T>;
		using const_reverse_iterator = ST::list_const_reverse_iterator<T>;

	public:
		// Default Constructor: Initialize members to their default values.
		Node()
			: m_Data(T())
			, m_NextNode(nullptr)
			, m_PrevNode(nullptr)
		{
		}
		// Parameterized Constructor: Initialize members by given data.
		Node(const T& data, Node* next, Node* prev)
			: m_Data(data)
			, m_NextNode(next)
			, m_PrevNode(prev)
		{
		}
		// Destructor: no specific operation.
		~Node()
		{
		}


	};

	// List class
	template <typename T>
	class list
	{
	private:
		Node<T>* m_HeadNode;		// Member pointer to store the first node.
		Node<T>* m_TailNode;		// Member pointer to store the last node.
		int			m_Count;		// Member variable to store node count.

	private:
		Node<T>* merge_sort(Node<T>* head);			// Helper function for sort Function.
		Node<T>* merge(Node<T>* l1, Node<T>* l2);	// Helper function for merge_sort Function.

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
		using iterator = ST::list_iterator<T>;
		using const_iterator = ST::list_const_iterator<T>;
		using reverse_iterator = ST::list_reverse_iterator<T>;
		using const_reverse_iterator = ST::list_const_reverse_iterator<T>;

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
		void sort();					// sort Function; Sort the data inside the list.

	public:
		// Iterator Functions.
		// begin Function; Return iterator that points to the first data.
		iterator begin() noexcept { return iterator(this, this->m_HeadNode); }
		// begin const Function; Const version of begin() for range-based for loop.
		const_iterator begin() const noexcept { return const_iterator(this, this->m_HeadNode); }
		// cbegin Function; Return constant iterator that points to the first data.
		const_iterator cbegin() const noexcept { return const_iterator(this, this->m_HeadNode); }
		// end Function; Return iterator that points to the right of the last data.
		iterator end() noexcept { return iterator(this, nullptr); }
		// end const Function; Const version of end() for range-based for loop.
		const_iterator end() const noexcept { return const_iterator(this, nullptr); }
		// cend Function; Return constant iterator that points to the right of the last data.
		const_iterator cend() const noexcept { return const_iterator(this, nullptr); }

		// erase Function; Erase the data that the given iterator is pointing.
		iterator erase(const iterator& pos);
		// insert Function; Insert data to the left of the iterator.
		iterator insert(const T& data, const iterator& iter);

		// Reverse Iterator Functions.
		// rbegin Function; Return reverse iterator that points to the last data.
		reverse_iterator rbegin() noexcept { return reverse_iterator(this, this->m_TailNode); }
		// crbegin Function; Return constant reverse iterator that points to the last data.
		const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(this, this->m_TailNode); }
		// rend Function; Return reverse iterator that points to the left of the first data.
		reverse_iterator rend() noexcept { return reverse_iterator(this, nullptr); }
		// crend Function; Return constant reverse iterator that points to the left of the first data.
		const_reverse_iterator crend() const noexcept { return const_reverse_iterator(this, nullptr); }

	public:
		// Default Constructor: Initialize members to their default values.
		list();
		// List initializing Constructor: Initialize members with a list.
		list(std::initializer_list<T> init);
		// Destructor: Release all nodes, reinitialize members to their default values.
		~list();

		static bool isAuthentic()
		{
#ifdef STList_20250430
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
	{
	}

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

	// sort Function; Sort the data inside the list.
	template<typename T>
	void list<T>::sort()
	{
		if (this->m_Count <= 1)
		{
			return;
		}

		m_HeadNode = merge_sort(m_HeadNode);

		Node<T>* tail = m_HeadNode;
		while (tail && tail->m_NextNode)
		{
			tail = tail->m_NextNode;
		}

		m_TailNode = tail;
	}

	// Helper function for sort Function.
	template<typename T>
	Node<T>* list<T>::merge_sort(Node<T>* head)
	{
		if (!head || !head->m_NextNode)
		{
			return head;
		}

		Node<T>* slow = head;
		Node<T>* fast = head->m_NextNode;

		while (fast && fast->m_NextNode)
		{
			slow = slow->m_NextNode;
			fast = fast->m_NextNode->m_NextNode;
		}

		Node<T>* mid = slow->m_NextNode;
		slow->m_NextNode = nullptr;
		if (mid)
		{
			mid->m_PrevNode = nullptr;
		}

		Node<T>* left = merge_sort(head);
		Node<T>* right = merge_sort(mid);

		return merge(left, right);
	}

	template <typename T>
	Node<T>* list<T>::merge(Node<T>* l1, Node<T>* l2)
	{
		Node<T> temp;
		Node<T>* tail = &temp;

		while (l1 && l2)
		{
			if (l1->m_Data <= l2->m_Data)
			{
				tail->m_NextNode = l1;
				l1->m_PrevNode = tail;
				l1 = l1->m_NextNode;
			}
			else
			{
				tail->m_NextNode = l2;
				l2->m_PrevNode = tail;
				l2 = l2->m_NextNode;
			}
			tail = tail->m_NextNode;
		}

		tail->m_NextNode = l1 ? l1 : l2;
		if (tail->m_NextNode)
		{
			tail->m_NextNode->m_PrevNode = tail;
		}

		Node<T>* newHead = temp.m_NextNode;
		if (newHead)
		{
			newHead->m_PrevNode = nullptr;
		}

		return newHead;
	}

	// erase Function; Erase the data that the given iterator is pointing.
	template<typename T>
	typename list<T>::iterator list<T>::erase(const typename list<T>::iterator& pos)
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
	typename list<T>::iterator list<T>::insert(const T& data, const typename list<T>::iterator& iter)
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
}
