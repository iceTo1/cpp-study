#pragma once

/*
* Author: Lee, Seungtack
* Date: Apr 8, 2025
*/

#include <stdexcept>

template <typename T>
class vector
{
private:
	T* m_pData; // Use pointer for Dynamic Memory Allocation (HEAP)
	int m_Size; // Element count
	int m_Capacity; // Max element count
public:
	void push_back(const T& data); // Add element to the end
	void resize(int resize_count); // Reallocate memory, increase capacity
	int size() const { return m_Size; } // Return size
	int capacity() const { return m_Capacity; } // Return capacity
	bool empty() const { return (0 == m_Size); } // Check if empty
	T* data() { return m_pData; } // Return the starting address of vector
	const T* data() const { return m_pData; } // Const function of data()

	T& front();
	T& back();

	T& operator[] (int idx); // Operator for random access with index
	vector& operator= (const vector& other); // Operator for assigning vector to vector
public:
	class iterator; // Iterator
	iterator begin();
	iterator end();
	iterator erase(iterator& other);
public:
	vector(); // Default Constructor
	vector(int size, const T& initial_value); // Initialize with size and value
	vector(int size); // Initialize with size only
	vector(const vector& other); // Copy Constructor
	~vector(); // Destructor

	class iterator
	{
	private:
		vector* m_vectorPtr; // Pointer to point vector
		T* m_pData; // Pointed value
		int m_idx; // Use -1 for end iterator
		bool m_isValid; // Check if the iterator is valid (not modified)
	
	public:
		// Testing functions
		void ValidityTest(); // Check if pointed vector or iterator itself is valid
		void IndexTest(); // Check if index is not negative or out of bound
		
		// Operator overload
		T& operator* (); // Access the value like pointer
		iterator& operator++ (); // Former ++ to increase iterator
		iterator operator++ (int); // Latter ++ to increase iterator
		iterator& operator-- (); // Former -- to increase iterator
		iterator operator-- (int); // Latter -- to increase iterator
		iterator& operator+ (int step); // Operator to increase iterator by given step
		iterator& operator- (int step); // Operator to decrease iterator by given step
		bool operator== (const iterator& other); // Check if two iterators are identical
		bool operator!= (const iterator& other); // Check if two iterators are unidentical

	public:
		iterator();
		~iterator();

		friend class vector; // Declare friend to access private members of vector
	};
};
// Default Constructor; capacity to 2.
template <typename T>
inline vector<T>::vector()
	: m_pData(nullptr)
	, m_Size(0)
	, m_Capacity(2)
{
	// Initialize with capacity 2.
	m_pData = new T[m_Capacity];
}

// Parameterized Constructor; initialize with size, value.
template <typename T>
inline vector<T>::vector(int size, const T& initial_value)
	: m_pData(nullptr)
	, m_Size(size)
	, m_Capacity(size * 2)
{
	// Check if size is negative
	if (m_Size < 0)
	{
		throw std::invalid_argument("Size cannot be negative.");
	}
	// Initialize the size of vector by given value, capacity by 2 * value.
	m_pData = new T[m_Capacity];

	for (int i = 0; i < m_Size; ++i)
	{
		m_pData[i] = initial_value;
	}
}

// Parameterized Constructor; initialize size only, value to "default of T type".
template <typename T>
inline vector<T>::vector(int size)
	: vector(size, T())
{ }

// Copy Constructor; initialize with same values of other.
template <typename T>
inline vector<T>::vector(const vector & other)
	: m_pData(nullptr)
	, m_Size(other.m_Size)
	, m_Capacity(other.m_Capacity)
{
	// Allocate memory
	m_pData = new T[m_Capacity];

	// Perform Deep Copy
	for (int i = 0; i < m_Size; ++i)
	{
		m_pData[i] = other.m_pData[i];
	}
}

// Destructor; free memory, reinitialize pointer.
template <typename T>
inline vector<T>::~vector()
{
	delete[] m_pData; // Free allocated memories
	m_pData = nullptr; // Prevent dangling pointer

	m_Size = 0;
	m_Capacity = 0;
}

// push_back Funtion; add data to the end.
template <typename T>
inline void vector<T>::push_back(const T& data)
{
	// if capacity is not enough,
	if (m_Size >= m_Capacity)
	{
		// re-allocate the capacity to double.
		resize(m_Capacity * 2);
	}

	// add data
	m_pData[m_Size++] = data;
}

// resize Function; resize the capacity of the vector, maintain the elements
template <typename T>
inline void vector<T>::resize(int resize_count)
{
	// if resize_count is smaller than capacity,
	if (resize_count <= this->m_Capacity)
	{
		return; // do nothing.
	}

	// Declare a temporary container with the resize count size
	T* pTemp = new T[resize_count];

	// Copy existing data to temporary container
	for (int i = 0; i < this->m_Size; ++i)
	{
		pTemp[i] = this->m_pData[i];
	}

	// Free the memory of the old container, reassign the pointer to the new container.
	delete[] this->m_pData;
	m_pData = pTemp;

	// Adjust the capacity.
	m_Capacity = resize_count;
}

