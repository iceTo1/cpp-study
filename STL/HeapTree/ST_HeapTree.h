#pragma once

#include "../Vector_Recreation/ST_Vector.h"
#include <stdexcept>

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
