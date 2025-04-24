# Custom Vector Implementation (C++)

This project contains a fully custom implementation of a dynamic array in C++, similar in behavior and interface to `std::vector`.

## Features
- Dynamic resizing with automatic capacity doubling
- STL-style interface and method names
- Forward iterators (`iterator`, `const_iterator`)
- Reverse iterators (`reverse_iterator`, `const_reverse_iterator`)
- Full support for range-based for loops
- Deep copy constructor and assignment
- Boundary checking for element access
- Read-only `cbegin()`, `crbegin()` for safe traversal

## Purpose
This implementation was written for educational purposes to fully understand how `std::vector` works under the hood and to practice memory management, iterators, and object-oriented design.

## Author
**Seungtack Lee**  
GitHub: [remydzn](https://github.com/remydzn)

> This project is planned to integrate custom allocators later.  
> Unauthorized use in academic or professional contexts without proper credit is prohibited.
