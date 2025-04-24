# Simple Stack Implementation in C++

This is a basic stack implementation created for **learning and educational purposes**.
This folder contains **two simple ways to implement stack**:
    1. Dynamic Array Implementation
    2. Node Implementation

---

## Features
### 1. Dynamic Array Implementation
- Array-based storage
- `push`, `pop`, `top`, `isEmpty` functions
- Exception handling for `overflow` and `underflow`
- Template support

### 2. Node-based Implementation (Singly-Linked List)
- Node-based storage
- `push`, `pop`, `peek`, `isEmpty`, `size` functions
- Exception handling for `overflow` and `underflow`
- Template support

- Key point: Always insert/remove at the front, while moving `top`.

---

## Limitations
- No resizing (for 1)
- Not circularly-linked
- Not STL-compatible (this is only for introducing the idea of stack)

---

## Author & License

This project was written by **Seungtack Lee** as a part of personal C++ study practice.  
Feel free to use it for **learning, practice, or reference** — just remember to give proper credit.

> 🔗 GitHub: [remydzn](https://github.com/remydzn)