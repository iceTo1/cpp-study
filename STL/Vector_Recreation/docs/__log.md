# log.md

Author: Seungtack Lee
Date: Apr 20, 2025

## Records while building the code

- Using existing constructor is more efficient.
    - using `T()` to initialize the value by the type `T`'s default value.

- Deep copy vs Shallow copy
    - Used Deep copy for copy constructor

- Comparing pointer and object by using address, if they are the same
    ```
    if (this == &other)
    {
        return *this;
    }
    ```

- Vectors do not release memory when performing `pop_back()`. 
    - the memory can not be modified because it was allocated as a whole.

- Object/class that does not possess `heap` memory does not require any operation on `destructor`

- `typename` keyword is needed to define functions that return iterator outside of the class.

- begin() `const`, end() `const` is needed to use range based for loop.

- operator[] `const` is needed to pass the vector as constant reference.

+ Updated the parameterized constructor to have capacity the same size of `m_Size` -> similar to STL vector.


“These notes are for personal reference and were gained through direct implementation.”