#pragma once

/*
* Custom Priority Queue implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 27~, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include "../HeapTree/ST_Heap.h"

template <typename T, typename Compare = ST::less<T>>
class priority_queue
{
private:
	Heap<T, Compare> m_Heap;	// Member Container
public:
	// push Function; Add data to the queue.
	void push(const T& data);
	// pop Function; Remove the highest priority value.
	void pop();
	// top Function; Return the highest priority value.
	T& top();
	// empty Function; Check if the queue is empty.
	bool empty() const;
	// size Function; Return the number of data in the queue.
	int size();
	// DebugPrint Function; Print the data for debug.
	void DebugPrint();
public:
	// Default Constructor; Initialize the container with default value.
	priority_queue();
	// Default Constructor; Initialize the container with list.
	priority_queue(std::initializer_list<T> init);
	// Destructor; No special operation.
	~priority_queue()
	{ }
};

// Default Constructor; Initialize the container with default value.
template<typename T, typename Compare>
priority_queue<T, Compare>::priority_queue()
	: m_Heap()
{ }

// Default Constructor; Initialize the container with list.
template<typename T, typename Compare>
priority_queue<T, Compare>::priority_queue(std::initializer_list<T> init)
	: m_Heap(init)
{ }

// push Function; Add data to the queue.
template<typename T, typename Compare>
void priority_queue<T, Compare>::push(const T& data)
{
	m_Heap.push(data);
}

// pop Function; Remove the highest priority value.
template<typename T, typename Compare>
void priority_queue<T, Compare>::pop()
{
	m_Heap.pop();
	// m_Heap.heapify();
}

template<typename T, typename Compare>
T& priority_queue<T, Compare>::top()
{
	return m_Heap.top();
}

// empty Function; Check if the queue is empty.
template<typename T, typename Compare>
bool priority_queue<T, Compare>::empty() const
{
	return m_Heap.empty();
}

// size Function; Return the number of data in the queue.
template<typename T, typename Compare>
int priority_queue<T, Compare>::size()
{
	return m_Heap.size();
}

// DebugPrint Function; Print the data for debug.
template<typename T, typename Compare>
void priority_queue<T, Compare>::DebugPrint()
{
	std::cout << "[ ";
	m_Heap.DataPrint();
	std::cout << "]\n";
}


