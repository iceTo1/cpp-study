#pragma once

/*
* Custom Maximum Heap Tree implementation by Seungtack Lee
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
class MaxHeap
{
private:
	vector<T>	m_MaxVec;	// Member variable for MaxHeap tree container.
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
	// pop Function; Delete the maximum value, and return the value.
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
	// Parameterized Constructor; Initialize the HeapTree with given value.
	MaxHeap(int capacity)
		: m_MaxVec()
	{
		if (capacity < 0)
		{
			throw std::invalid_argument("Invalid Size");
		}

		m_MaxVec.reserve(capacity);
	}
	// Destructor; No special operation.
	~MaxHeap()
	{
	}
};

// siftDown Function; Heapify after deletion.
template<typename T>
void MaxHeap<T>::siftDown(int index)
{
	// Declare variables to store children's index and maximum data's index.
	int leftIndex;
	int rightIndex;
	int maxIndex = index;

	// Iterate until finish heapifying.
	while (true)
	{
		// Store the left and right index of the given index.
		leftIndex = left(index);
		rightIndex = right(index);

		// If the left child exists, and the left child is bigger than the data,
		if (leftIndex < m_MaxVec.size() && m_MaxVec[leftIndex] > m_MaxVec[maxIndex])
		{
			// Update the maximum value index to the left child index.
			maxIndex = leftIndex;
		}
		// If the right child exists, and the right child is bigger than the data,
		if (rightIndex < m_MaxVec.size() && m_MaxVec[rightIndex] > m_MaxVec[maxIndex])
		{
			// Update the maximum value index to the right child index.
			maxIndex = rightIndex;
		}
		// If the maximum value index is already found,
		if (maxIndex == index)
		{
			// Espace from the loop.
			break;
		}

		// Swap the bigger value from children with the data with given index.
		T temp = m_MaxVec[index];
		m_MaxVec[index] = m_MaxVec[maxIndex];
		m_MaxVec[maxIndex] = temp;

		// Update the index to found maximum value index.
		index = maxIndex;
	}
}

// siftUp Function; Heapify after insertion.
template<typename T>
void MaxHeap<T>::siftUp(int index)
{
	// Declare a variable to store parent's index.
	int parentIndex;

	// Iterate until finish heapifying.
	while (index > 0)
	{
		// Update the parent index to parent's index.
		parentIndex = parent(index);

		// If the given value is bigger than the parent's value,
		if (m_MaxVec[index] > m_MaxVec[parentIndex])
		{
			// Swap the value
			T temp = m_MaxVec[index];
			m_MaxVec[index] = m_MaxVec[parentIndex];
			m_MaxVec[parentIndex] = temp;
			// Update the index to the parent's index.
			index = parentIndex;
		}
		// If the index is already the maximum value's index,
		else
		{
			// Escape from the loop.
			break;
		}
	}
}

// top Function; Return the top value.
template<typename T>
T& MaxHeap<T>::top()
{
	// If the tree is already empty,
	if (m_MaxVec.empty())
	{
		// Throw an exception.
		throw std::underflow_error("The HeapTree is empty");
	}
	// Otherwise, return the first data.
	return m_MaxVec[0];
}

// parent Function; Return the parent index based on given index.
template<typename T>
int MaxHeap<T>::parent(int index)
{
	// If the given index is invalid,
	if (index <= 0)
	{
		// Throw an exception.
		throw std::out_of_range("Invalid index");
	}
	// Return the index of parent.
	return (index - 1) / 2;
}

// left Function; Return the left child index based on given index.
template<typename T>
inline int MaxHeap<T>::left(int index)
{
	// Return the left child index.
	return index * 2 + 1;
}

// right Function; Return the right child index based on given index.
template<typename T>
inline int MaxHeap<T>::right(int index)
{
	// Return the right child index.
	return index * 2 + 2;
}

// push Function; Insert new value to the heap with data.
template<typename T>
void MaxHeap<T>::push(const T& data)
{
	// If the capacity is already full,
	if (m_MaxVec.capacity() == m_MaxVec.size())
	{
		// Reallocate memory to add data.
		m_MaxVec.reserve((0 == m_MaxVec.size()) ? 1 : m_MaxVec.size() * 2);
	}

	// Add data to the end of the container.
	m_MaxVec.push_back(data);

	// Heapify up.
	siftUp(m_MaxVec.size() - 1);
}

// pop Function; Delete the maximum value, and return the value.
template<typename T>
T MaxHeap<T>::pop()
{
	// If the container is already empty,
	if (m_MaxVec.empty())
	{
		// Throw an exception.
		throw std::underflow_error("The HeapTree is empty");
	}

	// Store the maximum value before deleting.
	T max = m_MaxVec[0];

	// Copy the last data and overwrite to the first data.
	m_MaxVec[0] = m_MaxVec[m_MaxVec.size() - 1];

	// Delete the last data.
	m_MaxVec.pop_back();

	// Heapify down.
	siftDown(0);

	// Return the value before deleting.
	return max;
}

// clear Function; Delete all data in the HeapTree.
template<typename T>
inline void MaxHeap<T>::clear()
{
	// Call the container's clear function.
	m_MaxVec.clear();
}

// empty Function; Check if the HeapTree is empty.
template<typename T>
inline bool MaxHeap<T>::empty() const
{
	// Call and return the container's empty function.
	return m_MaxVec.empty();
}

// size Function; Return the size of the HeapTree.
template<typename T>
inline int MaxHeap<T>::size() const
{
	// Call and return the container's size function.
	return m_MaxVec.size();
}

// DebugPrint Function; Print the data.
template<typename T>
inline void MaxHeap<T>::DebugPrint()
{
	for (const T& val : m_MaxVec)
	{
		std::cout << val << " ";
	}
	std::cout << "\n";
}
