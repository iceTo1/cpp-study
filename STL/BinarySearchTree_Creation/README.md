# Custom Binary Search Tree (BST) Implementation (C++)

This repository contains a custom implementation of a **Binary Search Tree**, designed for in-order operations and learning purposes. The structure is implemented from scratch without using STL containers.

## Features
- Unbalanced BST with support for insertion, deletion, and search
- In-order traversal with `print()`, `findMin()`, and `findMax()` functions
- STL-compatible iterator:
  - `iterator` with `operator*`, `operator++`, `==`, `!=`
  - Supports range-based `for` loops
- Clear and well-documented recursive logic for tree manipulation

## Purpose
The purpose of this project is to gain a deep understanding of:
- Binary tree structures and pointer-based traversal
- Recursive insertion, deletion (including 3-case handling), and memory cleanup
- In-order iteration logic using custom STL-style iterators

## Author
**Seungtack Lee**  
GitHub: [remydzn](https://github.com/remydzn)

> Iterator logic mirrors `std::set` behavior and will evolve further.  
> Future plans include implementing `const_iterator`, `operator--`, and balanced BST logic (e.g., AVL or Red-Black Tree).
