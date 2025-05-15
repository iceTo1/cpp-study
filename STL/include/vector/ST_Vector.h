#pragma once

/*
* Custom vector implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 8~12, 2025
* Edit: Apr 28~30, 2025
* Added Custom Allocator: May 14~15, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
*
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#define STVec_20250428
#include <stdexcept>
#include "../vector/vector_iterators.h"
#include "../utility/utility.h"
#include "../allocator/ST_Allocator.h"

namespace ST
{
	template <typename T, typename Alloc = STAllocator<T>>
	class vector
	{
	private:
		Alloc m_Allocator;	// Allocator instance
		T* m_pData;			// Use pointer for Dynamic Memory Allocation (HEAP)
		int m_Size;			// Element count
		int m_Capacity;		// Max element count

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
		using iterator = vector_iterator<T>;
		using const_iterator = vector_const_iterator<T>;
		using reverse_iterator = vector_reverse_iterator<T>;
		using const_reverse_iterator = vector_const_reverse_iterator<T>;
	public:
		// Functions
		void reserve(const int& size);	// Pre-allocate the given size of memory
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
		// Iterator Functions
		iterator begin() noexcept { return iterator(this, m_pData, 0); }						// Return iterator that points to the first element
		const_iterator begin() const noexcept { return const_iterator(this, m_pData, 0); }		// Constant version of begin function for range-based for loop
		const_iterator cbegin() const noexcept { return const_iterator(this, m_pData, 0); }		// Return constant iterator that points to the first element
		iterator end() noexcept { return iterator(this, m_pData, m_Size); }						// Return iterator that points to the right of the last element
		const_iterator end() const noexcept { return const_iterator(this, m_pData, m_Size); }	// Constant version of end function for range-based for loop
		const_iterator cend() const noexcept { return const_iterator(this, m_pData, m_Size); }	// Return constatn iterator that points to the right of the last element

		iterator erase(iterator& other);				// Erase the element pointed by other iterator and return the iterator pointing that position
		iterator insert(iterator pos, const T& val);	// Insert the value to the pointed position and return iterator that points to that position

		// Reverse Iterator Functions
		// Return iterator that goes backward, pointing to the last element
		reverse_iterator rbegin() noexcept
		{ return reverse_iterator(this, m_pData, (m_Size == 0) ? -1 : m_Size - 1); }

		// Const version of rbegin Function
		const_reverse_iterator rbegin() const noexcept
		{ return const_reverse_iterator(this, m_pData, (m_Size == 0) ? -1 : m_Size - 1); }
		
		// Return constant iterator that goes backward, pointing to the last element
		const_reverse_iterator crbegin() noexcept
		{ return const_reverse_iterator(this, m_pData, (m_Size == 0) ? -1 : m_Size - 1); }
		
		// Return iterator that goes backward, pointing to the left of the first element
		reverse_iterator rend() noexcept
		{ return reverse_iterator(this, m_pData, -1); }
		
		// Constant version of rend Function
		const_reverse_iterator rend() const noexcept
		{ return const_reverse_iterator(this, m_pData, -1);	}
		
		// Return constant iterator that goes backward, pointing to the last element
		const_reverse_iterator crend() const noexcept
		{ return const_reverse_iterator(this, m_pData, -1); }

	public:
		vector();									// Default Constructor
		vector(int size, const T& initial_value);	// Initialize with size and value
		vector(int size);							// Initialize with size only
		vector(std::initializer_list<T> init);		// Initialize with list
		vector(const vector& other);				// Copy Constructor
		~vector();									// Destructor

		// Granting access to private members to iterators.
		friend class vector_iterator<T>;
		friend class vector_const_iterator<T>;
		friend class vector_reverse_iterator<T>;
		friend class vector_const_reverse_iterator<T>;

		static bool isAuthentic()
		{
#ifdef STVec_20250428
			return true;
#else
			return false;
#endif
		}
	};

	// Default Constructor; capacity to 0.
	template <typename T, typename Alloc>
	vector<T, Alloc>::vector()
		: m_pData(nullptr)
		, m_Size(0)
		, m_Capacity(0)
	{ }

	// Parameterized Constructor; initialize with size, value.
	template <typename T, typename Alloc>
	vector<T, Alloc>::vector(int size, const T& initial_value)
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
		m_pData = m_Allocator.allocate(m_Capacity);

		for (int i = 0; i < m_Size; ++i)
		{
			m_Allocator.construct(m_pData + i, initial_value);
		}
	}

	// Parameterized Constructor; initialize size only, value to "default of T type".
	template <typename T, typename Alloc>
	vector<T, Alloc>::vector(int size)
		: vector(size, T())
	{ }

	// List initializing Constructor; Initialize with list
	template <typename T, typename Alloc>
	vector<T, Alloc>::vector(std::initializer_list<T> init)
		:vector()
	{
		for (const T& val : init)
		{
			push_back(val);
		}
	}

	// Copy Constructor; initialize with same values of other.
	template <typename T, typename Alloc>
	vector<T, Alloc>::vector(const vector& other)
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
	template <typename T, typename Alloc>
	vector<T, Alloc>::~vector()
	{
		for (int i = 0; i < m_Size; ++i)
		{
			m_Allocator.destroy(m_pData + i);
		}

		m_Allocator.deallocate(m_pData, m_Capacity);
	}

	template <typename T, typename Alloc>
	void vector<T, Alloc>::reserve(const int& size)
	{
		// if resize_count is smaller than capacity,
		if (size <= this->m_Capacity)
		{
			// do nothing.
			return;
		}

		// Declare a temporary container with the resize count size.
		T* pTemp = m_Allocator.allocate(size);

		// Copy existing data to temporary container.
		for (int i = 0; i < m_Size; ++i)
		{
			m_Allocator.construct(pTemp + i, ST::move(m_pData[i]));
			m_Allocator.destroy(m_pData + i);
		}

		// Free the memory of the old container, reassign the pointer to the new container.
		m_Allocator.deallocate(m_pData, m_Capacity);
		m_pData = pTemp;

		// Adjust the capacity.
		m_Capacity = size;
	}

	// push_back Funtion; add data to the end.
	template <typename T, typename Alloc>
	void vector<T, Alloc>::push_back(const T& data)
	{
		// if capacity is not enough,
		if (m_Size >= m_Capacity)
		{
			// re-allocate the capacity to double.
			reserve((m_Capacity > 0) ? m_Capacity * 2 : 1);
		}

		// Add data.
		m_Allocator.construct(m_pData + m_Size, data);
		++m_Size;
	}

	// pop_back Function; remove last data.
	template <typename T, typename Alloc>
	void vector<T, Alloc>::pop_back()
	{
		// if the vector is empty,
		if (this->empty())
		{
			// throw exception.
			throw std::out_of_range("Vector is empty");
		}

		// Re-initialize the last element with default value of the data type
		m_Allocator.destroy(m_pData + (m_Size - 1)); // optional, but I tried to secure the data

		// Decrase the size.
		--m_Size;
	}

	// resize Function; resize the capacity of the vector, initialize the remining data with default value.
	template <typename T, typename Alloc>
	void vector<T, Alloc>::resize(int newsize)
	{
		// If the new size is bigger than capacity,
		if (newsize > this->m_Capacity)
		{
			// Reallocate the memory for new size.
			reserve(newsize);
		}

		// If the new size is bigger than the previous size,
		if (newsize > m_Size)
		{
			// Set the remaining data as default value by type.
			for (int i = m_Size; i < newsize; ++i)
			{
				m_Allocator.construct(m_pData + i, T());
			}
		}
		// If the newsize is smaller than the previous size,
		else
		{
			// Release the exceeding elements.
			for (int i = newsize; i < m_Size; ++i)
			{
				m_Allocator.destroy(m_pData + i);
			}
		}

		// Adjust the size.
		m_Size = newsize;
	}

	// front Function; returns the first element. 
	template <typename T, typename Alloc>
	T& vector<T, Alloc>::front()
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
	template <typename T, typename Alloc>
	T& vector<T, Alloc>::back()
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
	template <typename T, typename Alloc>
	T& vector<T, Alloc>::at(int idx)
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
	template <typename T, typename Alloc>
	const T& vector<T, Alloc>::at(int idx) const
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
	template <typename T, typename Alloc>
	void vector<T, Alloc>::clear()
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
			m_Allocator.destroy(m_pData + i);
		}

		// Update the size to 0.
		m_Size = 0;
	}

	// Operator []; returns data at "idx" index.
	template <typename T, typename Alloc>
	T& vector<T, Alloc>::operator[](int idx)
	{
		// operator[] omits bound check for faster performance with risk; undefined behavior.
		// return "idx"th data.
		return m_pData[idx];
	}

	// constant Operator[]; Constant version of Operator[]
	template <typename T, typename Alloc>
	const T& vector<T, Alloc>::operator[] (int idx) const
	{
		// operator[] omits bound check for faster performance with risk; undefined behavior.
		// Return the data of given index.
		return m_pData[idx];
	}

	// Operator =; assigns the other vector to this vector.
	template <typename T, typename Alloc>
	vector<T, Alloc>& vector<T, Alloc>::operator= (const vector<T, Alloc>& other)
	{
		// if the other vector is the same as this vector,
		if (this == &other)
		{
			// return this vector.
			return *this;
		}

		// release the pre-allocated memory
		for (int i = 0; i < m_Size; ++i)
		{
			m_Allocator.destroy(m_pData + i);
		}
		m_Allocator.deallocate(m_pData, m_Capacity);

		// perform deep copy
		this->m_Capacity = other.m_Capacity;
		this->m_pData = m_Allocator.allocate(m_Capacity);
		this->m_Size = other.m_Size;

		for (int i = 0; i < m_Size; ++i)
		{
			m_Allocator.construct(m_pData + i, other.m_pData[i]);
		}

		return *this;
	}
	
	// erase Function; erase the pointed element.
	template <typename T, typename Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator& other)
	{
		// Test iterator.
		other.ValidityTest();
		other.IndexTest();

		// Release the memory the iterator is pointing to.
		m_Allocator.destroy(m_pData + other.m_idx);

		// Overlap the pointed element, shift elements after erased element to the left.
		for (int i = other.m_idx; i < m_Size - 1; ++i)
		{
			m_Allocator.construct(m_pData + i, ST::move(m_pData [i + 1]));
			m_Allocator.destroy(m_pData + i + 1);
		}

		// Decrease the size.
		--m_Size;
		// Re-initialize the last element to the default value by its type (optional).
		m_pData[m_Size] = T();

		return iterator(this, m_pData, other.m_idx);
	}

	// insert Function; insert the value to the left of the pointed position.
	template <typename T, typename Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, const T& val)
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
			m_Allocator.construct(m_pData + i, ST::move(m_pData[i - 1]));
			m_Allocator.destroy(m_pData + i - 1);
		}

		// Add the value to the desired position.
		m_Allocator.construct(m_pData + pos.m_idx, val);

		// Increase size.
		++m_Size;

		return iterator(this, m_pData, pos.m_idx);
	}
}