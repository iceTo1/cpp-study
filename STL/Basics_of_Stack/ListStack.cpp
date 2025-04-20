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
class Stack;

template <typename T>
class Node
{
private:
    T           m_Data;
    Node<T>*    m_NextNode;

public:
    Node()
        : m_Data(T())
        , m_NextNode(nullptr)
    {}

    Node(const T& data)
        : m_Data(data)
        , m_NextNode(nullptr)
    { }

    // Allow access to private member by Stack class
    friend class Stack;
};

template <typename T>
class Stack
{
private:
    // `top` always stays at front.
    Node<T>* top = nullptr;
    int m_Count;
public:
    // insert at front
    void push (const T& data);
    // remove front
    void pop();
    T peek();
    bool isEmpty() const;
    int size() const;
public:
    Stack()
    : top(nullptr)
    , m_Count(0)
    { }

    ~Stack()
    { 
        while (!isEmpty())
        {
            pop();
        }
    }
};

template <typename T>
void Stack<T>::push(const T& data)
{
    Node<T>* newNode = new Node<T>(data);

    if (isEmpty())
    {
        top = newNode;
    }
    else
    {
        newNode->m_NextNode = top;
        top = newNode;
    }

    ++m_Count;
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack is already empty");
    }
    Node<T>* popNode = top;
    top = top->m_NextNode;

    delete popNode;
    popNode = nullptr;

    --m_Count;
}

template <typename T>
T Stack<T>::peek()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack has no data");
    }

    return top->m_Data;
}

template <typename T>
inline bool Stack<T>::isEmpty() const
{
    return nullptr == top;
}

template <typename T>
inline int Stack<T>::size() const
{
    return m_Count;
}