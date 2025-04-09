#pragma once

/*
* Author: Lee, Seungtack
* Date: Apr 8~9, 2025
*/

#include <stdexcept>

template <typename T>
class vector
{
private:
	T*	m_pData;	// Use pointer for Dynamic Memory Allocation (HEAP)
	int m_Size;		// Element count
	int m_Capacity; // Max element count
public:
	// Functions
	void push_back(const T& data); // Add element to the end
	void pop_back(); // Remove the last element
	void resize(int resize_count); // Reallocate memory, increase capacity
	T& front(); // Return first element
	T& back(); // Return last element
	T& at(int idx); // Return 'idx'th element
	const T& at(int idx) const; // Const version of at()
	void clear(); // Erease all elements, capacity stays

	// Inline Functions
	int size() const { return m_Size; } // Return size
	int capacity() const { return m_Capacity; } // Return capacity
	bool empty() const { return (0 == m_Size); } // Check if empty
	T* data() { return m_pData; } // Return the starting address of vector
	const T* data() const { return m_pData; } // Const function of data()

	// Operator Overloadings
	T& operator[] (int idx); // Operator for random access with index
	vector& operator= (const vector& other); // Operator for assigning vector to vector
public:
	class iterator; // Iterator class declaration

	// Iterator Functions
	iterator begin();
	iterator end();
	iterator erase(iterator& other);
	iterator next(iterator& other);
	iterator next(iterator& other, int step);
	iterator prev(iterator& other);
	iterator prev(iterator& other, int step);
public:
	vector(); // Default Constructor
	vector(int size, const T& initial_value); // Initialize with size and value
	vector(int size); // Initialize with size only
	vector(const vector& other); // Copy Constructor
	~vector(); // Destructor

	class iterator
	{
	private:
		vector*	m_vectorPtr;	// Pointer to point vector
		T*		m_pData;		// Pointed value
		int		m_idx;			// Use -1 for end iterator
		bool	m_isValid;		// Check if the iterator is valid (not modified)
	
	public:
		// Testing functions
		void ValidityTest() // Check if pointed vector or iterator itself is valid
		{
			// if array is invalid, or array and iterator does not match, or iterator is invalid,
			if (nullptr == m_vectorPtr || m_pData != m_vectorPtr || !m_isValid)
			{
				// throw exception.
				throw std::invalid_argument("Iterator invalid.");
			}
		}
		void IndexTest() // Check if index is not negative or out of bound; I designed this in addition to STL iterators.
		{
			// if index is negative, or out of bound,
			if (m_idx < 0 || m_idx >= m_vectorPtr->m_Capacity)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}
		}
		
		// Operator overload
		T& operator* () // Access the value like pointer
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Return data of index.
			return m_pData[m_idx];
		}
		iterator& operator++ () // Former ++ to increase iterator
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if pointing to the last element,
			if (m_idx + 1 == m_vectorPtr->m_Size)
			{
				// end iterator.
				m_idx = -1;
			}
			// if vector is not empty,
			else if (0 < m_vectorPtr->m_Size)
			{

				++m_idx;
			}

			// Return modified iterator (if vector is empty, do not change)
			return *this;
		}
		iterator operator++ (int) // Latter ++ to increase iterator
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			iterator temp = *this;
			// Perform ++ to the iterator.
			++(*this);

			// Return the saved iterator.
			return temp;
		}
		iterator& operator-- () // Former -- to increase iterator
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if pointing to the first element,
			if (0 == m_idx)
			{
				// do nothing.
				return *this;
			}
			// if vector is not empty,
			else if (0 < m_vectorPtr->m_Size)
			{

				--m_idx;
			}

			// Return modified iterator (if vector is empty, do not change)
			return *this;
		}
		iterator operator-- (int) // Latter -- to increase iterator
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			iterator temp = *this;
			// Perform ++ to the iterator.
			--(*this);

			// Return the saved iterator.
			return temp;
		}
		iterator& operator+ (int step) // Operator to increase iterator by given step
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index + step is out of bound,
			if (m_idx + step < 0 || m_idx + step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			// Increase index by "step".
			m_idx += step;

			// Return modified iterator.
			return *this;
		}
		iterator& operator- (int step) // Operator to decrease iterator by given step
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index + step is out of bound,
			if (m_idx - step < 0 || m_idx - step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			// Increase index by "step".
			m_idx -= step;

			// Return modified iterator.
			return *this;
		}
		bool operator== (const iterator& other) // Check if two iterators are identical
		{
			// if iterator is pointing to same vector and, same element, return true.
			return (this->m_vectorPtr == other.m_vectorPtr && this->m_idx == other.m_idx);
		}
		bool operator!= (const iterator& other) // Check if two iterators are unidentical
		{
			// return opposite result of operator ==
			return !(*this == other);
		}

	public:
		iterator()
			: m_vectorPtr(nullptr)
			, m_pData(nullptr)
			, m_idx(-1)
			, m_isValid(false)
		{ }
		~iterator();

		// Declare friend to access private members of vector
		friend class vector; 
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
	// Check if size is negative.
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
	// Allocate memory.
	m_pData = new T[m_Capacity];

	// Perform Deep Copy.
	for (int i = 0; i < m_Size; ++i)
	{
		m_pData[i] = other.m_pData[i];
	}
}

// Destructor; free memory, reinitialize pointer.
template <typename T>
inline vector<T>::~vector()
{
	// Free allocated memories.
	delete[] m_pData; 
	// Prevent dangling pointer.
	m_pData = nullptr; 

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

	// Add data.
	m_pData[m_Size++] = data;
}

// pop_back Function; remove last data.
template <typename T>
inline void vector<T>::pop_back()
{
	// if the vector is empty,
	if (this->empty())
	{
		// throw exception.
		throw std::out_of_range("Vector is empty");
	}

	// Re-initialize the last element with default value of the data type
	m_pData[m_Size - 1] = T(); // optional, but I tried to secure the data

	// Decrase the size.
	--m_Size;
}

// resize Function; resize the capacity of the vector, maintain the elements.
template <typename T>
inline void vector<T>::resize(int resize_count)
{
	// if resize_count is smaller than capacity,
	if (resize_count <= this->m_Capacity)
	{
		// do nothing.
		return; 
	}

	// Declare a temporary container with the resize count size.
	T* pTemp = new T[resize_count];

	// Copy existing data to temporary container.
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

// front Function; returns the first element. 
template <typename T>
inline T& vector<T>::front()
{
	// if the vector is empty,
	if (this->empty())
	{
		// Throw an exception.
		throw std::out_of_range("Vector is empty");
	}

	// Return first element.
	return m_pData[0];
}

// back Function; returns the last element.
template <typename T>
inline T& vector<T>::back()
{
	// if the vector is empty,
	if (this->empty())
	{
		throw std::out_of_range("Vector is empty");
	}

	// Return last element.
	return m_pData[m_Size - 1];
}

// at Function; returns data at "idx" index, checks bound.
template <typename T>
inline T& vector<T>::at(int idx)
{
	// if the vector is empty,
	if (this->empty())
	{
		// throw exception.
		throw std::out_of_range("Vector is empty");
	}

	// if the index is out of bound,
	if (idx >= m_Size || idx < 0)
	{
		// throw exception.
		throw std::out_of_range("The index is out of bound.");
	}

	// return "idx"th data.
	return m_pData[idx];
}

// at const Function; at Function for constant objects.
template<typename T>
inline const T& vector<T>::at(int idx) const
{
	// if the vector is empty,
	if (this->empty())
	{
		// throw exception.
		throw std::out_of_range("Vector is empty");
	}

	// if the index is out of bound,
	if (idx > m_Size || idx < 0)
	{
		// throw exception.
		throw std::out_of_range("The index is out of bound.");
	}

	return m_pData[idx];
}

// clear Function; erase all data by initializing to default value, capacity stays the same.
template <typename T>
inline void vector<T>::clear()
{
	// if the vector is empty,
	if (empty())
	{
		// do nothing.
		return;
	}

	// Iterate through the vector using for loop.
	// -> Direct index operation is lighter than using iterator operation.
	for (int i = 0; i < m_Size; ++i)
	{
		// Re-initialize the values by the default value of its data type
		m_pData[i] = T();
	}

	// Update the size to 0.
	m_Size = 0;
}

// Operator []; returns data at "idx" index.
template <typename T>
inline T& vector<T>::operator[](int idx)
{
	// operator[] omits bound check for faster performance with risk; undefined behavior.
	// return "idx"th data.
	return m_pData[idx];
}

// Operator =; assigns the other vector to this vector.
template <typename T>
inline vector<T>& vector<T>::operator=(const vector<T>& other)
{
	// if the other vector is the same as this vector,
	if (this == &other)
	{
		// return this vector.
		return *this;
	}

	// release the pre-allocated memory
	delete[] this->m_pData;

	// perform deep copy
	this->m_pData = new T[other.capacity()];
	this->m_Size = other.size();
	this->m_Capacity = other.capacity();

	for (int i = 0; i < m_Size; ++i)
	{
		this->m_pData[i] = other.at(i);
	}

	return *this;
}
