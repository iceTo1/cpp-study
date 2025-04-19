#pragma once

/*
* Custom vector implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 8~12, 2025
* 
* This code was written and maintained by Seungtack Lee for educational purposes.  
* If you are using this for learning, please give proper credit.  
* Unauthorized use for academic or job submissions is prohibited.
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
	void push_back(const T& data);	// Add element to the end
	void pop_back();				// Remove the last element
	void resize(int resize_count);	// Reallocate memory, increase capacity
	T& front();						// Return first element
	T& back();						// Return last element
	T& at(int idx);					// Return 'idx'th element
	const T& at(int idx) const;		// Const version of at()
	void clear();					// Erease all elements, capacity stays

	// Inline Functions
	int size() const { return m_Size; }				// Return size
	int capacity() const { return m_Capacity; }		// Return capacity
	bool empty() const { return (0 == m_Size); }	// Check if empty
	T* data() { return m_pData; }					// Return the starting address of vector
	const T* data() const { return m_pData; }		// Const function of data()

	// Operator Overloadings
	T& operator[] (int idx);					// Operator for random access with index
	const T& operator[] (int idx) const;		// Operator[]; Constant version of Operator[]
	vector& operator= (const vector& other);	// Operator for assigning vector to vector

public:
	class iterator;					// Iterator class declaration
	class const_iterator;			// Constant Iterator class declaration
	class reverse_iterator;			// Reverse Iterator class declaration
	class const_reverse_iterator;	// Constant Reverse Iterator class declaration
	
	// Iterator Functions
	iterator begin();								// Return iterator that points to the first element
	const_iterator cbegin() const;					// Return constant iterator that points to the first element
	iterator end();									// Return iterator that points to the right of the last element
	const_iterator cend() const;					// Return constatn iterator that points to the right of the last element
	iterator erase(iterator& other);				// Erase the element pointed by other iterator and return the iterator pointing that position
	iterator insert(iterator pos, const T& val);	// Insert the value to the pointed position and return iterator that points to that position

	// Reverse Iterator Functions
	reverse_iterator rbegin();			// Return iterator that goes backward, pointing to the last element
	const_reverse_iterator crbegin();	// Return constant iterator that goes backward, pointing to the last element
	reverse_iterator rend();			// Return iterator that goes backward, pointing to the left of the first element
	const_reverse_iterator crend();		// Return constant iterator that goes backward, pointing to the last element
	
public:
	vector();									// Default Constructor
	vector(int size, const T& initial_value);	// Initialize with size and value
	vector(int size);							// Initialize with size only
	vector(const vector& other);				// Copy Constructor
	~vector();									// Destructor

	class iterator
	{
	private:
		vector*	m_vectorPtr;	// Pointer to point vector
		T*		m_pData;		// Pointed value
		int		m_idx;			// Use -1 for end iterator
		bool	m_isValid;		// Check if the iterator is valid (not modified)
	
	public:
		// Testing functions
		// ValidityTest Function; Check if pointed vector or iterator itself is valid.
		void ValidityTest()
		{
			// if array is invalid, or array and iterator does not match, or iterator is invalid,
			if (nullptr == m_vectorPtr || m_pData != m_vectorPtr->m_pData || !m_isValid)
			{
				// throw exception.
				throw std::invalid_argument("Iterator invalid.");
			}
		}
		// IndexTest Function; Check if index is not negative or out of bound; I designed this in addition to STL iterators.
		void IndexTest()
		{
			// if index is negative, or out of bound,
			if (m_idx < 0 || m_idx > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}
		}
		
		// Operator overload
		// Operator *; Access the value like pointer.
		T& operator* ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Return data of index.
			return m_pData[m_idx];
		}

		// Operator Former ++; Increase iterator by 1.
		iterator& operator++ ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Increase index.
			++m_idx;

			// Return modified iterator.
			return *this;
		}

		// Operator Latter ++; Increase iterator by 1 after assign operator.
		iterator operator++ (int)
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

		// Operator Former --; Decrease iterator by 1.
		iterator& operator-- ()
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
				// decrease index.
				--m_idx;
			}

			// Return modified iterator (if vector is empty, do not change).
			return *this;
		}

		// Operator Latter --; Decrease iterator by 1 after assign operator.
		iterator operator-- (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			iterator temp = *this;
			// Perform -- to the iterator.
			--(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator +; Increase the iterator by given step.
		iterator& operator+ (int step)
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

		// Operator -; Decrease the iterator by given step.
		iterator& operator- (int step)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index - step is out of bound,
			if (m_idx - step < 0 || m_idx - step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			// Decrease index by "step".
			m_idx -= step;

			// Return modified iterator.
			return *this;
		}

		// Operator =; Assign/copy iterator.
		iterator& operator= (const iterator& other)
		{
			// if other iterator and this iterator are different,
			if (this != &other)
			{
				// copy data.
				this->m_vectorPtr = other.m_vectorPtr;
				this->m_pData = other.m_pData;
				this->m_idx = other.m_idx;
				this->m_isValid = other.m_isValid;
			}
			return *this;
		}

		// Operator ==; Check if two iterators are identical.
		bool operator== (const iterator& other) 
		{
			// if iterator is pointing to same vector and, same element, return true.
			return (this->m_vectorPtr == other.m_vectorPtr && this->m_idx == other.m_idx);
		}

		// Operator !=; Check if two iterators are unidentical.
		bool operator!= (const iterator& other) 
		{
			// return opposite result of operator ==.
			return !(*this == other);
		}

	public:
		// iterator Constructor; Initialize the members by nullpointers, index by 0.
		iterator()
			: m_vectorPtr(nullptr)
			, m_pData(nullptr)
			, m_idx(0)
			, m_isValid(false)
		{ }

		// iterator parameterized Constructor; Initialized the members by given values.
		iterator(vector<T>* vector, T* data, int idx)
			: m_vectorPtr(vector)
			, m_pData(data)
			, m_idx(idx)
			, m_isValid(false)
		{
			// if vector is valid,
			if (nullptr != vector && vector->m_pData == data)
			{
				m_isValid = true;
			}
		}

		// iterator Destructor; No particular operation needed without memory allocation.
		~iterator()
		{ }

		// Declare friend to access private members of vector.
		friend class vector; 
	};

	class const_iterator
	{
	private:
		const T* m_pData;			// Constant type data pointer
		const vector* m_vectorPtr;	// Constant type vector pointer
		int m_idx;					// Index variable (cannot be constant; need to point different elements)
		bool m_isValid;				// Validity variable (cannot be constant; need to check validity)
	public:
		// Testing functions
		// ValidityTest Function; Check if pointed vector or iterator itself is valid.
		void ValidityTest()
		{
			// if array is invalid, or array and iterator does not match, or iterator is invalid,
			if (nullptr == m_vectorPtr || m_pData != m_vectorPtr->m_pData || !m_isValid)
			{
				// throw exception.
				throw std::invalid_argument("Iterator invalid.");
			}
		}
		// IndexTest Function; Check if index is not negative or out of bound; I designed this in addition to STL iterators.
		void IndexTest()
		{
			// if index is negative, or out of bound,
			if (m_idx < 0 || m_idx > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}
		}

		// Operator overload
		// constant Operator *; Access the value like pointer; Cannot overwrite the constant data type.
		const T& operator* () const
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Return data of index.
			return m_pData[m_idx];
		}

		// Operator Former ++; Increase iterator by 1.
		const_iterator& operator++ ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Increase index.
			++m_idx;

			// Return modified iterator.
			return *this;
		}

		// Operator Latter ++; Increase iterator by 1 after assign operator.
		const_iterator operator++ (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			const_iterator temp = *this;

			// Perform ++ to the iterator.
			++(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator Former --; Decrease iterator by 1.
		const_iterator& operator-- ()
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
				// decrease index.
				--m_idx;
			}

			// Return modified iterator (if vector is empty, do not change).
			return *this;
		}

		// Operator Latter --; Decrease iterator by 1 after assign operator.
		const_iterator operator-- (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			const_iterator temp = *this;
			// Perform -- to the iterator.
			--(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator +; Increase the iterator by given step.
		const_iterator& operator+ (int step)
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

		// Operator -; Decrease the iterator by given step.
		const_iterator& operator- (int step)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index - step is out of bound,
			if (m_idx - step < 0 || m_idx - step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			// Decrease index by "step".
			m_idx -= step;

			// Return modified iterator.
			return *this;
		}

		// Operator =; Assign/copy iterator.
		const_iterator& operator= (const const_iterator& other)
		{
			// if other iterator and this iterator are different,
			if (this != &other)
			{
				// copy data.
				this->m_vectorPtr = other.m_vectorPtr;
				this->m_pData = other.m_pData;
				this->m_idx = other.m_idx;
				this->m_isValid = other.m_isValid;
			}
			return *this;
		}

		// Operator ==; Check if two iterators are identical.
		bool operator== (const const_iterator& other)
		{
			// if iterator is pointing to same vector and, same element, return true.
			return (this->m_vectorPtr == other.m_vectorPtr && this->m_idx == other.m_idx);
		}

		// Operator !=; Check if two iterators are unidentical.
		bool operator!= (const const_iterator& other)
		{
			// return opposite result of operator ==.
			return !(*this == other);
		}
	public:
		// iterator parameterized Constructor; Initialized the members by given values.
		const_iterator(const vector<T>* vector, const T* data, int idx)
			: m_vectorPtr(vector)
			, m_pData(data)
			, m_idx(idx)
			, m_isValid(false)
		{
			// if vector is valid,
			if (nullptr != vector && vector->m_pData == data)
			{
				m_isValid = true;
			}
		}
		// constant iterator Destructor; No specific operation due to no memory allocation.
		~const_iterator()
		{ }
	};

	class reverse_iterator
	{
	private:
		vector* m_vectorPtr;
		T*		m_pData;
		int		m_idx;
		bool	m_isValid;
	public:
		// Testing functions
		// ValidityTest Function; Check if pointed vector or iterator itself is valid.
		void ValidityTest()
		{
			// if array is invalid, or array and iterator does not match, or iterator is invalid,
			if (nullptr == m_vectorPtr || m_pData != m_vectorPtr->m_pData || !m_isValid)
			{
				// throw exception.
				throw std::invalid_argument("Iterator invalid.");
			}
		}
		// IndexTest Function; Check if index is not negative or out of bound; I designed this in addition to STL iterators.
		void IndexTest()
		{
			// if index is negative, or out of bound,
			if (m_idx < 0 || m_idx > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}
		}

		// base Function; convert the reverse iterator to iterator.
		iterator base();

		// Operator overload
		// Operator *; Access the value like pointer.
		T& operator* ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Return data of index.
			return m_pData[m_idx];
		}

		// Operator Former ++; Increase iterator by 1 (reverse way).
		reverse_iterator& operator++ ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Increase index in reverse way.
			--m_idx;

			// Return modified iterator (if vector is empty, do not change).
			return *this;
		}

		// Operator Latter ++; Increase iterator by 1 after assign operator (reverse way).
		reverse_iterator operator++ (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			reverse_iterator temp = *this;

			// Perform ++ in reverse way to the iterator.
			--(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator Former --; Decrease iterator by 1 (reverse way).
		reverse_iterator& operator-- ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if pointing to the last element,
			if (m_idx >= m_vectorPtr->m_Size - 1)
			{
				// do nothing.
				return *this;
			}
			// if vector is not empty,
			else if (0 < m_vectorPtr->m_Size)
			{
				// decrease index in reverse way.
				++m_idx;
			}

			// Return modified iterator (if vector is empty, do not change).
			return *this;
		}

		// Operator Latter --; Decrease iterator by 1 after assign operator (reverse way).
		reverse_iterator operator-- (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			reverse_iterator temp = *this;
			// Perform -- in reverse way to the iterator.
			++(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator +; Increase the iterator by given step (reverse way).
		reverse_iterator operator+ (int step)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index + step in reverse way is out of bound,
			if (m_idx - step < 0 || m_idx - step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			// Create temporary iterator that stores this iterator's information.
			reverse_iterator temp = *this;

			// Increase index of the temporary iterator in reverse way by "step".
			temp.m_idx -= step;

			// Return modified iterator.
			return temp;
		}

		// Operator -; Decrease the iterator by given step (reverse way).
		reverse_iterator operator- (int step)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index - step in reverse way is out of bound,
			if (m_idx + step < 0 || m_idx + step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			// Create temporary iterator that stores this iterator's information.
			reverse_iterator temp = *this;

			// Increase index of the temporary iterator in reverse way by "step".
			temp.m_idx += step;

			// Return modified iterator.
			return *this;
		}

		// Operator =; Assign/copy iterator.
		reverse_iterator& operator= (const reverse_iterator& other)
		{
			// if other iterator and this iterator are different,
			if (this != &other)
			{
				// copy data.
				this->m_vectorPtr = other.m_vectorPtr;
				this->m_pData = other.m_pData;
				this->m_idx = other.m_idx;
				this->m_isValid = other.m_isValid;
			}
			return *this;
		}

		// Operator ==; Check if two iterators are identical.
		bool operator== (const reverse_iterator& other)
		{
			// if iterator is pointing to same vector and, same element, return true.
			return (this->m_vectorPtr == other.m_vectorPtr && this->m_idx == other.m_idx);
		}

		// Operator !=; Check if two iterators are unidentical.
		bool operator!= (const reverse_iterator& other)
		{
			// return opposite result of operator ==.
			return !(*this == other);
		}

	public:
		// reverse_iterator Constructor; Initialize the members by nullpointers, index by end + 1 (end).
		reverse_iterator()
			: m_vectorPtr(nullptr)
			, m_pData(nullptr)
			, m_idx(0)
			, m_isValid(false)
		{ }

		// reverse_iterator parameterized Constructor; Initialized the members by given values.
		reverse_iterator(vector<T>* vector, T* data, int idx)
			: m_vectorPtr(vector)
			, m_pData(data)
			, m_idx(idx)
			, m_isValid(false)
		{
			// if the vector is valid,
			if (nullptr != vector && this->m_pData == data)
			{
				m_isValid = true;
			}
		}

		// reverse_iterator Destructor; No particular operation needed without memory allocation.
		~reverse_iterator()
		{ }

		// Declare friend to access private members of vector.
		friend class vector;
	};

	class const_reverse_iterator
	{
	private:
		const vector*	m_vectorPtr;
		const T*		m_pData;
		int				m_idx;
		bool			m_isValid;
	public:
		// Testing functions
		// ValidityTest Function; Check if pointed vector or iterator itself is valid.
		void ValidityTest()
		{
			// if array is invalid, or array and iterator does not match, or iterator is invalid,
			if (nullptr == m_vectorPtr || m_pData != m_vectorPtr->m_pData || !m_isValid)
			{
				// throw exception.
				throw std::invalid_argument("Iterator invalid.");
			}
		}
		// IndexTest Function; Check if index is not negative or out of bound; I designed this in addition to STL iterators.
		void IndexTest()
		{
			// if index is negative, or out of bound,
			if (m_idx < 0 || m_idx > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}
		}

		// base Function; convert the reverse iterator to iterator.
		const_iterator base();

		// Operator overload
		// Operator *; Access the value like pointer.
		const T& operator* () const
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Return data of index.
			return m_pData[m_idx];
		}

		// Operator Former ++; Increase iterator by 1 (reverse way).
		const_reverse_iterator& operator++ ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Increase index in reverse way.
			--m_idx;

			// Return modified iterator (if vector is empty, do not change).
			return *this;
		}

		// Operator Latter ++; Increase iterator by 1 after assign operator (reverse way).
		const_reverse_iterator operator++ (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			const_reverse_iterator temp = *this;

			// Perform ++ in reverse way to the iterator.
			--(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator Former --; Decrease iterator by 1 (reverse way).
		const_reverse_iterator& operator-- ()
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if pointing to the last element,
			if (m_idx >= m_vectorPtr->m_Size - 1)
			{
				// do nothing.
				return *this;
			}
			// if vector is not empty,
			else if (0 < m_vectorPtr->m_Size)
			{
				// decrease index in reverse way.
				++m_idx;
			}

			// Return modified iterator (if vector is empty, do not change).
			return *this;
		}

		// Operator Latter --; Decrease iterator by 1 after assign operator (reverse way).
		const_reverse_iterator operator-- (int)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// Save current iterator.
			const_reverse_iterator temp = *this;
			// Perform -- in reverse way to the iterator.
			++(*this);

			// Return the saved iterator.
			return temp;
		}

		// Operator +; Increase the iterator by given step (reverse way).
		const_reverse_iterator operator+ (int step)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index + step in reverse way is out of bound,
			if (m_idx - step < 0 || m_idx - step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			// Create temporary iterator that stores this iterator's information.
			const_reverse_iterator temp = *this;

			// Increase index of the temporary iterator in reverse way by "step".
			temp.m_idx -= step;

			// Return modified iterator.
			return temp;
		}

		// Operator -; Decrease the iterator by given step (reverse way).
		const_reverse_iterator operator- (int step)
		{
			// Test iterator.
			ValidityTest();
			IndexTest();

			// if index - step in reverse way is out of bound,
			if (m_idx + step < 0 || m_idx + step > m_vectorPtr->m_Size)
			{
				// throw exception.
				throw std::out_of_range("Index out of bound");
			}

			// Create temporary iterator that stores this iterator's information.
			const_reverse_iterator temp = *this;

			// Increase index of the temporary iterator in reverse way by "step".
			temp.m_idx += step;

			// Return modified iterator.
			return *this;
		}

		// Operator =; Assign/copy iterator.
		const_reverse_iterator& operator= (const const_reverse_iterator& other)
		{
			// if other iterator and this iterator are different,
			if (this != &other)
			{
				// copy data.
				this->m_vectorPtr = other.m_vectorPtr;
				this->m_pData = other.m_pData;
				this->m_idx = other.m_idx;
				this->m_isValid = other.m_isValid;
			}
			return *this;
		}

		// Operator ==; Check if two iterators are identical.
		bool operator== (const const_reverse_iterator& other)
		{
			// if iterator is pointing to same vector and, same element, return true.
			return (this->m_vectorPtr == other.m_vectorPtr && this->m_idx == other.m_idx);
		}

		// Operator !=; Check if two iterators are unidentical.
		bool operator!= (const const_reverse_iterator& other)
		{
			// return opposite result of operator ==.
			return !(*this == other);
		}

	public:
		// reverse_iterator parameterized Constructor; Initialized the members by given values.
		const_reverse_iterator(const vector<T>* vector, const T* data, int idx)
			: m_vectorPtr(vector)
			, m_pData(data)
			, m_idx(idx)
			, m_isValid(false)
		{
			// if the vector is valid,
			if (nullptr != vector && this->m_pData == data)
			{
				m_isValid = true;
			}
		}

		// reverse_iterator Destructor; No particular operation needed without memory allocation.
		~const_reverse_iterator()
		{ }

		// Declare friend to access private members of vector.
		friend class vector;
	};
};

// Default Constructor; capacity to 0.
template <typename T>
vector<T>::vector()
	: m_pData(nullptr)
	, m_Size(0)
	, m_Capacity(0)
{
	// Initialize with capacity 0.
	m_pData = new T[m_Capacity];
}

// Parameterized Constructor; initialize with size, value.
template <typename T>
vector<T>::vector(int size, const T& initial_value)
	: m_pData(nullptr)
	, m_Size(size)
	, m_Capacity(size)
{
	// Check if size is negative.
	if (m_Size < 0)
	{
		throw std::invalid_argument("Size cannot be negative.");
	}

	// Initialize the size of vector by given value, capacity by size.
	m_pData = new T[m_Capacity];

	for (int i = 0; i < m_Size; ++i)
	{
		m_pData[i] = initial_value;
	}
}

// Parameterized Constructor; initialize size only, value to "default of T type".
template <typename T>
vector<T>::vector(int size)
	: vector(size, T())
{ }

// Copy Constructor; initialize with same values of other.
template <typename T>
vector<T>::vector(const vector & other)
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
vector<T>::~vector()
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
void vector<T>::push_back(const T& data)
{
	// if vector size is 0,
	if (0 == this->m_Capacity)
	{
		// re-allocate the capacity to 1.
		resize(1);
	}

	// if capacity is not enough,
	else if (m_Size >= m_Capacity)
	{
		// re-allocate the capacity to double.
		resize(m_Capacity * 2);
	}

	// Add data.
	m_pData[m_Size++] = data;
}

// pop_back Function; remove last data.
template <typename T>
void vector<T>::pop_back()
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
void vector<T>::resize(int resize_count)
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
T& vector<T>::front()
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
T& vector<T>::back()
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
T& vector<T>::at(int idx)
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
template <typename T>
const T& vector<T>::at(int idx) const
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

	return m_pData[idx];
}

// clear Function; erase all data by initializing to default value, capacity stays the same.
template <typename T>
void vector<T>::clear()
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
T& vector<T>::operator[](int idx)
{
	// operator[] omits bound check for faster performance with risk; undefined behavior.
	// return "idx"th data.
	return m_pData[idx];
}

// constant Operator[]; Constant version of Operator[]
template <typename T>
const T& vector<T>::operator[] (int idx) const
{
	// operator[] omits bound check for faster performance with risk; undefined behavior.
	// Return the data of given index.
	return m_pData[idx];
}

// Operator =; assigns the other vector to this vector.
template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other)
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

// begin Function; return iterator that points to the first element.
template <typename T>
typename vector<T>::iterator vector<T>::begin()
{
	// return begin iterator.
	return iterator(this, m_pData, 0);
}

// cbegin Function; constant version of begin Function.
template<typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const
{
	return const_iterator(this, m_pData, 0);
}

// end Function; return iterator that points next to the last element.
template <typename T>
typename vector<T>::iterator vector<T>::end()
{
	// return next to the last element.
	return iterator(this, m_pData, m_Size);
}

// cend Function; constant version of end Function.
template<typename T>
typename vector<T>::const_iterator vector<T>::cend() const
{
	return const_iterator(this, m_pData, m_Size);
}

// erase Function; erase the pointed element.
template <typename T>
typename vector<T>::iterator vector<T>::erase(iterator& other)
{
	// Test iterator.
	other.ValidityTest();
	other.IndexTest();

	// Overlap the pointed element, shift elements after erased element to the left.
	for (int i = other.m_idx; i < m_Size - 1; ++i)
	{
		m_pData[i] = m_pData[i + 1];
	}

	// Decrease the size.
	--m_Size;
	// Re-initialize the last element to the default value by its type (optional).
	m_pData[m_Size] = T();
	
	return iterator(this, m_pData, other.m_idx);
}

// insert Function; insert the value to the left of the pointed position.
template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos, const T& val)
{
	// If the capacity is not enough to insert,
	if (m_Size + 1 > m_Capacity)
	{
		// resize the capacity.
		resize(m_Capacity * 2);
	}

	// If the index of the iterator is out of bound,
	if (pos.m_idx < 0 || pos.m_idx > m_Size)
	{
		// Throw an exception.
		throw std::out_of_range("Invalid index");
	}

	// Shift elements from the pointed element,
	for (int i = m_Size; i > pos.m_idx; --i)
	{
		// Shift from right to keep the data.
		m_pData[i] = m_pData[i - 1];
	}

	// Add the value to the desired position.
	m_pData[pos.m_idx] = val;

	// Increase size.
	++m_Size;

	return iterator(this, m_pData, pos.m_idx);
}

// rbegin Function; return reverse iterator that points to the last element.
template <typename T>
typename vector<T>::reverse_iterator vector<T>::rbegin()
{
	// Return the iterator that points to the last element.
	return reverse_iterator(this, m_pData, (m_Size == 0) ? -1 : m_Size - 1);
}

// crbegin Function; return constant reverse iterator that points to the last element.
template<typename T>
typename vector<T>::const_reverse_iterator vector<T>::crbegin()
{
	// Return the const_iterator that points to the last element.
	return const_reverse_iterator(this, m_pData, (m_Size==0) ? -1 : m_Size - 1);
}

// rend Function; return reverse iterator that points to the next to the first element.
template <typename T>
typename vector<T>::reverse_iterator vector<T>::rend()
{
	// Return reverse iterator that points to next to the first element. 
	return reverse_iterator(this, m_pData, -1);
}

// crend Function; return constant reverse iterator that points to the next to the first element.
template<typename T>
typename vector<T>::const_reverse_iterator vector<T>::crend()
{
	// Return constant reverse iterator that points to next to the first element. 
	return const_reverse_iterator(this, m_pData, -1);
}

// base Function; return forward iterator from reverse iterator.
template<typename T>
typename vector<T>::iterator vector<T>::reverse_iterator::base()
{
	// Test iterator.
	ValidityTest();
	IndexTest();

	// Return converted iterator.
	// Shift the indexto the right for proper begin(), and end() iterators.
	return iterator(m_vectorPtr, m_pData, m_idx + 1);
}

// base Function; return constant forward iterator from constant reverse iterator.
template<typename T>
typename vector<T>::const_iterator vector<T>::const_reverse_iterator::base()
{
	// Test iterator.
	ValidityTest();
	IndexTest();

	// Return converted iterator.
	// Shift the index to the right for proper begin(), and end() iterators.
	return const_iterator(m_vectorPtr, m_pData, m_idx + 1);
}
