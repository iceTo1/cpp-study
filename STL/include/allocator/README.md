# Custom Allocator for STL Containers

This folder contains a minimal STL-compliant custom allocator implementation. 
The codes overall were based on/inspired by Code Blacksmith, he has amazing tutorials on C++ in his youtube.
[https://www.youtube.com/@CodeBlacksmith](https://www.youtube.com/@CodeBlacksmith)

---

## Files
- `ST_Allocator.h`: Custom allocator class that supports STL containers, or custom containers.
- `allocator_traits.h`: A minimal replica of `std::allocator_traits`, abstracting the allocator interface in a generic way.

---

## Overview
Based on my learning from the Univ of Utah CS2420 course, 
I attempted to replicate the STL project to behave more similarly to the STL. 

Instead of hardcoding `new`/`delete`, STL containers use an external `Allocator` class to manage memory.

### Custom Allocator
`ST_Allocator.h`
- Through `ST_Allocator.h`, `STAllocator<T>` class allocates and deallocates using `new` and `delete` inside.
### Traits Wrapper
`allocator_traits.h`
- Standardize allocator across types.
- Defines handy type aliases.

---

## Example Use Case
You can plug this allocator into any STL-style container, including STL.
```
ST::vector<int, STAllocator<int>> vec;
vec.push_back(10);
```

---

## Educational Attribution
" Inspired by Code Blacksmith
" Created for educational purposes by Seungtack Lee

Unauthorized use in academic or professional submissions without proper credit is prohibited.

---

## Authorship Verification
This file is part of a self-built STL clone project.
If you found this code outside the original GitHub repository, please check or report:
[https://github.com/remydzn/cpp-study](https://github.com/remydzn/cpp-study)
