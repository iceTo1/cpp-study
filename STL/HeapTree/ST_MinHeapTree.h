#pragma once

/*
* Custom Mininum Heap Tree implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 24~25, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../Vector_Recreation/ST_Vector.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class MinHeap
{
private:
	vector<T>	m_MinVec;	// Member variable for MinHeap tree container.
private:
	// Helper Functions.
	// siftDown Function; Heapify after deletion.
	void siftDown(int index);
	// siftUp Function; Heapify after insertion.
	void siftUp(int index);
public:
	// top Function; Return the top value.
	T& top();
	// parent Function; Return the parent index based on given index.
	int parent(int index);
	// left Function; Return the left child index based on given index.
	int left(int index);
	// right Function; Return the right child index based on given index.
	int right(int index);
	// push Function; Insert new value to the heap with data.
	void push(const T& data);
	// pop Function; Delete the minimum value, and return the value.
	T pop();
	// clear Function; Delete all data in the HeapTree.
	void clear();
	// empty Function; Check if the HeapTree is empty.
	bool empty() const;
	// size Function; Return the size of the HeapTree.
	int size() const;
	// DebugPrint Function; Print the data.
	void DebugPrint();
public:
	// Parameterized Constructor; Initialize the HeapTree with given values.
	MinHeap(int capacity)
		: m_MinVec()
	{
		if (capacity < 0)
		{
			throw std::invalid_argument("Invalid Size");
		}

		m_MinVec.reserve(capacity);
	}
	// Destructor; No special operation.
	~MinHeap()
	{ }
};

// siftUp Function; Heapify after insertion.
template<typename T>
void MinHeap<T>::siftDown(int index)
{
	// Iterate to find the correct place for the heapifying value.
	while (true)
	{
		// Declare a variable to store the smaller child's index.
		int smallerIdx = index;

		// If the left child is the only child,
		if (m_MinVec.size() <= right(index) && left(index) < m_MinVec.size())
		{
			// Update the smaller index to left child index, and escape the loop.
			smallerIdx = left(index);
		}
		// If the right child is the only child,
		else if (m_MinVec.size() <= left(index) && right(index) < m_MinVec.size())
		{
			// Update the smaller index to right child index, and escape the loop.
			smallerIdx = right(index);
		}
		// If both children exist,
		else
		{
			// Find the smaller value's index
			if (m_MinVec[left(index)] < m_MinVec[right(index)])
			{
				smallerIdx = left(index);
			}
			else
			{
				smallerIdx = right(index);
			}
		}

		// If the smaller index is already the index,
		if (smallerIdx == index)
		{
			// Escape from the loop.
			break;
		}

		// Swap the heapifying value with the smaller child.
		T temp = m_MinVec[smallerIdx];
		m_MinVec[smallerIdx] = m_MinVec[index];
		m_MinVec[index] = temp;

		index = smallerIdx;
	}
}

// siftUp Function; Heapify after insertion.
template<typename T>
void MinHeap<T>::siftUp(int index)
{
	// Declare a variable to store parent index.
	int tempIdx;
	// Declare a variable for swapping.
	T temp;

	// While index is valid, and heapifying value is smaller than parent, move up by swapping.
	while (index > 0 && m_MinVec[index] < m_MinVec[parent(index)])
	{
		// Store the parent index.
		tempIdx = parent(index);

		// Swap the heapifying value and its parnet.
		temp = m_MinVec[index];
		m_MinVec[index] = m_MinVec[tempIdx];
		m_MinVec[tempIdx] = temp;

		// Update the heapifying value's index.
		index = tempIdx;
	}
}

// top Function; Return the top value.
template<typename T>
T& MinHeap<T>::top()
{
	// If the heaptree is empty,
	if (0 == m_MinVec.size())
	{
		// Throw an exception.
		throw std::underflow_error("HeapTree is empty");
	}
	// Return the first value.
	return m_MinVec[0];
}

// parent Function; Return the parent index based on given index.
template<typename T>
int MinHeap<T>::parent(int index)
{
	// If the index represents the root node,
	if (0 >= index)
	{
		// Throw an exception.
		throw std::out_of_range("Invalid Index");
	}

	// Otherwise, return the parent data's index.
	return (index - 1) / 2;
}

// left Function; Return the left child index based on given index.
template<typename T>
inline int MinHeap<T>::left(int index)
{
	// Return the left child's index.
	return (2 * index + 1);
}

// right Function; Return the right child index based on given index.
template<typename T>
inline int MinHeap<T>::right(int index)
{
	return (2 * index + 2);
}

// push Function; Add the data in the correct place.
template<typename T>
void MinHeap<T>::push(const T& data)
{
	// If the container is full,
	int cap = m_MinVec.capacity();
	if (m_MinVec.size() == cap)
	{
		// Allocate more memory.
		m_MinVec.reserve((cap == 0) ? 1 : 2 * cap);
	}

	// Add the data at the end.
	m_MinVec.push_back(data);

	// Store the added data's index.
	int idx = m_MinVec.size() - 1;

	// Heapify up the data.
	siftUp(idx);
}

// pop Function; Remove the minimum data, and return the value.
template<typename T>
T MinHeap<T>::pop()
{
	// If the container is empty,
	if (m_MinVec.empty())
	{
		// Throw an exception.
		throw std::underflow_error("The HeapTree is empty");
	}

	// Declare a variable to store the minimum value.
	T min = m_MinVec[0];

	// Overwrite the last value to the root.
	m_MinVec[0] = m_MinVec[m_MinVec.size() - 1];

	// Heapify down the new root value.
	siftDown(0);

	// Delete the last element.
	m_MinVec.pop_back();

	return min;
}

// clear Function; Delete all data in the HeapTree.
template<typename T>
inline void MinHeap<T>::clear()
{
	// Call the container's clear function.
	this->m_MinVec.clear();
}

// empty Function; Check if the HeapTree is empty.
template<typename T>
inline bool MinHeap<T>::empty() const
{
	// Call the container's empty function.
	return this->m_MinVec.empty();
}

// size Function; Return the size of the HeapTree.
template<typename T>
inline int MinHeap<T>::size() const
{
	return this->m_MinVec.size();
}

// DebugPrint Function; Print the elements.
template<typename T>
inline void MinHeap<T>::DebugPrint()
{
	for (const T& val : this->m_MinVec)
	{
		std::cout << val << " ";
	}
}
