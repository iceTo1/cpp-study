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
	vector<T>	m_MaxVec;	// Member variable for MinHeap tree container.
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
	// Parameterized Constructor; Initialize the HeapTree with given values.
	MinHeap(int capacity)
		: m_MaxVec()
	{
		if (capacity < 0)
		{
			throw std::invalid_argument("Invalid Size");
		}

		m_MaxVec.reserve(capacity);
	}
	// Destructor; No special operation.
	~MinHeap()
	{
	}
};

