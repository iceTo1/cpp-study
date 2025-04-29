#pragma once

/*
* Custom Heap Tree implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 27, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../Vector_Recreation/ST_oldVector.h"
#include "../include/utility/utility.h"
#include "../include/functional/functional.h"
#include <stdexcept>
#include <iostream>

template <typename T, typename Compare = ST::less<T>>
class Heap
{
private:
	vector<T>	m_Vec;	// Member variable for MaxHeap tree container.
	Compare		m_Compare;	// Member variable for Comparator functor.
private:
	// Helper Functions.
	// siftDown Function; Heapify after deletion.
	void siftDown(int index);
	// siftUp Function; Heapify after insertion.
	void siftUp(int index);
public:
	// heapify Function; Heapify the data.
	void heapify();
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
	// DebugPrint Function; Print the data in formatted way.
	void DebugPrint();
	// DataPrint Function; Print the data.
	void DataPrint();
public:
	// Parameterized Constructor; Initialize the HeapTree with given value.
	Heap(int capacity);
	// List initializing Constructor; Initialize with list
	Heap(std::initializer_list<T> init);
	// Destructor; No special operation.
	~Heap()
	{ }
};

// Parameterized Constructor; Initialize the HeapTree with given value.
template<typename T, typename Compare>
Heap<T, Compare>::Heap(int capacity)
	: m_Vec()
	, m_Compare(Compare())
{
	if (capacity < 0)
	{
		throw std::invalid_argument("Invalid Size");
	}

	m_Vec.reserve(capacity);
}

// List initializing Constructor; Initialize with list
template<typename T, typename Compare>
Heap<T, Compare>::Heap(std::initializer_list<T> init)
	: m_Vec()
	, m_Compare(Compare())
{
	m_Vec.reserve(init.size());
	// Add element of list to the container.
	for (const T& val : init)
	{
		m_Vec.push_back(val);
	}
	// Heapify.
	heapify();
}

// siftDown Function; Heapify after deletion.
template <typename T, typename Compare>
void Heap<T, Compare>::siftDown(int index)
{
	// Declare variables to store children's index and maximum data's index.
	int leftIndex;
	int rightIndex;
	int targetIndex = index;

	// Iterate until finish heapifying.
	while (true)
	{
		// Store the left and right index of the given index.
		leftIndex = left(index);
		rightIndex = right(index);

		// If the left child exists, and the left child is bigger than the data,
		if (leftIndex < m_Vec.size() && m_Compare(m_Vec[targetIndex], m_Vec[leftIndex]))
		{
			// Update the maximum value index to the left child index.
			targetIndex = leftIndex;
		}
		// If the right child exists, and the right child is bigger than the data,
		if (rightIndex < m_Vec.size() && m_Compare(m_Vec[targetIndex], m_Vec[rightIndex]))
		{
			// Update the maximum value index to the right child index.
			targetIndex = rightIndex;
		}
		// If the maximum value index is already found,
		if (targetIndex == index)
		{
			// Espace from the loop.
			break;
		}

		// Swap the bigger value from children with the data with given index.
		ST::swap(m_Vec[index], m_Vec[targetIndex]);

		// Update the index to found maximum value index.
		index = targetIndex;
	}
}

// siftUp Function; Heapify after insertion.
template <typename T, typename Compare>
void Heap<T, Compare>::siftUp(int index)
{
	// Declare a variable to store parent's index.
	int parentIndex;

	// Iterate until finish heapifying.
	while (index > 0)
	{
		// Update the parent index to parent's index.
		parentIndex = parent(index);

		// If the given value is bigger than the parent's value,
		if (m_Compare(m_Vec[parentIndex], m_Vec[index]))
		{
			// Swap the value
			ST::swap(m_Vec[index], m_Vec[parentIndex]);

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

// heapify Function; Heapify the data.
template<typename T, typename Compare>
void Heap<T, Compare>::heapify()
{
	// First half data has child, iterate for (size / 2)
	for (int i = (m_Vec.size() / 2 - 1); i >= 0; --i)
	{
		// Heapify down from the parent node.
		siftDown(i);
	}
}

// top Function; Return the top value.
template <typename T, typename Compare>
T& Heap<T, Compare>::top()
{
	// If the tree is already empty,
	if (m_Vec.empty())
	{
		// Throw an exception.
		throw std::underflow_error("The HeapTree is empty");
	}
	// Otherwise, return the first data.
	return m_Vec[0];
}

// parent Function; Return the parent index based on given index.
template <typename T, typename Compare>
int Heap<T, Compare>::parent(int index)
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
template <typename T, typename Compare>
inline int Heap<T, Compare>::left(int index)
{
	// Return the left child index.
	return index * 2 + 1;
}

// right Function; Return the right child index based on given index.
template <typename T, typename Compare>
inline int Heap<T, Compare>::right(int index)
{
	// Return the right child index.
	return index * 2 + 2;
}

// push Function; Insert new value to the heap with data.
template <typename T, typename Compare>
void Heap<T, Compare>::push(const T& data)
{
	// If the capacity is already full,
	if (m_Vec.capacity() == m_Vec.size())
	{
		// Reallocate memory to add data.
		m_Vec.reserve((0 == m_Vec.size()) ? 1 : m_Vec.size() * 2);
	}

	// Add data to the end of the container.
	m_Vec.push_back(data);

	// Heapify up.
	siftUp(m_Vec.size() - 1);
}

// pop Function; Delete the maximum value, and return the value.
template <typename T, typename Compare>
T Heap<T, Compare>::pop()
{
	// If the container is already empty,
	if (m_Vec.empty())
	{
		// Throw an exception.
		throw std::underflow_error("The HeapTree is empty");
	}

	// Store the maximum value before deleting.
	T max = m_Vec[0];

	// Copy the last data and overwrite to the first data.
	m_Vec[0] = m_Vec[m_Vec.size() - 1];

	// Delete the last data.
	m_Vec.pop_back();

	// Heapify down.
	siftDown(0);

	// Return the value before deleting.
	return max;
}

// clear Function; Delete all data in the HeapTree.
template <typename T, typename Compare>
inline void Heap<T, Compare>::clear()
{
	// Call the container's clear function.
	m_Vec.clear();
}

// empty Function; Check if the HeapTree is empty.
template <typename T, typename Compare>
inline bool Heap<T, Compare>::empty() const
{
	// Call and return the container's empty function.
	return m_Vec.empty();
}

// size Function; Return the size of the HeapTree.
template <typename T, typename Compare>
inline int Heap<T, Compare>::size() const
{
	// Call and return the container's size function.
	return m_Vec.size();
}

// DebugPrint Function; Print the data in formatted way.
template <typename T, typename Compare>
void Heap<T, Compare>::DebugPrint()
{
	// If the vector is empty,
	if (m_Vec.empty())
	{
		// Print empty line and exit the function.
		std::cout << "\n";
		return;
	}

	// Declare variables for level, max data count per level, and print count.
	int level = 0;
	int data_at_level = 1;
	int count = 0;

	// Iterate the container.
	for (int i = 0; i < m_Vec.size(); ++i)
	{
		// Print the current data and white space.
		std::cout << m_Vec[i] << " ";
		// Increase print count after printing.
		++count;

		// If printed for max data count at current level,
		if (count == data_at_level)
		{
			// Print new line.
			std::cout << "\n";
			// Increase the level.
			++level;
			// Update the max data count at level.
			data_at_level *= 2;
			// Reset the print count.
			count = 0;
		}
	}
	// If printing is done without printing for max data count,
	if (count != 0)
	{
		// Print new line, and escape the loop.
		std::cout << "\n";
	}
}

// DataPrint Function; Print the data.
template<typename T, typename Compare>
void Heap<T, Compare>::DataPrint()
{
	for (T& val : m_Vec)
	{
		std::cout << val << " ";
	}
}
