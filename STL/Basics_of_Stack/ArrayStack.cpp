/*
* Stack simple implementation by Seungtack Lee
* Author: Lee, Seungtack
* GitHub: https://github.com/remydzn/cpp-study
* Date: Apr 20, 2025
*
* <Authorship Verification>
* This section exists to verify that this project was originally created by Seungtack Lee.
* Please leave a star when you are cloning this code.
* 
* Unauthorized use in academic or professional submissions without proper credit is prohibited.
* If you received this code from a source other than my GitHub repository, please let me know:
* https://github.com/remydzn
*/

#include <stdexcept>

template <typename T>
class Stack
{
private:
    T*   m_StackArr;
    int m_Top; 
    int m_Capacity;
public:
    void push(const T& data)
    {
        if (m_Top == m_Capacity)
        {
            throw std::overflow_error("Stack is already full");
        }
        m_StackArr[++m_Top] = data;
    }

    void pop()
    {
        if (-1 == m_Top)
        {
            throw std::underflow_error("Stack is already empty");
        }
        // Optional: re-initialize the logically erasing data to its default value
        m_StackArr[m_Top] = T();

        --m_Top;
    }

    bool isEmpty() const
    {
        return m_Top == -1;
    }

    T& top()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack has no data");
        }
        return m_StackArr[m_Top - 1];
    }
public:
    Stack(int size)
        : m_StackArr(nullptr)
        , m_Top(-1)
        , m_Capacity(size)
    {
        // Size can't be negative
        if (size < 1)
        {
            throw std::runtime_error("Invalid Stack Size");
        }
        // Declare a dynamic array with given size
        m_StackArr = new T[m_Capacity];
    }

    ~Stack()
    {
        delete[] m_StackArr;
    }

};