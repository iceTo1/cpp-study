# 💽 Custom `iterator` header (Minimal STL-style Iterators System)

This folder contains a minimal `iterator` header to construct STL containers.
Not only from CS2420 class from Univ of Utah, I referenced `cppreference.com` and GPT4o for detailed guidance.
Link to `cppreference.com`: [https://cppreference.com/](https://cppreference.com/)

---

## 💾 Files
- `advance.h`: Move the iterator forward (or backward) by `n` steps.
- `distance.h`: Calculate the number of steps between two given iterators.
- `iterator.h`: A header that combines the iterator-related headers for deeper abstraction.
- `iterator_category.h`: Defines iterator category tags (e.g., input, output, random access) for different iterator behaviors.
- `iterator_traits.h`: Provides a structure to extract iterator traits (e.g., value_type, difference_type) for generic programming.
- `next.h`: Return an iterator pointing to the next element.
- `prev.h`: Return an iterator pointing to the previous element.

---

## 📋 Overview
Based on my learning from the Univ of Utah CS2420 course, reading from `cppreference.com`, and feedback from GPT-4o,
I attempted to replicate the `iterator.h` for my STL cloning project in a separate header file. 

### ⚒️ `advance.h`
- If the iterator type is `random_access`, return the iterator after moving it for `n`, directly.
- If the iterator type is `bidirectional`, return the iterator after moving it `n` times, using `++` or `--` operator.
- If the iterator type is `forward`, return the iterator after moving it `n` times, using `++`.
- If the iterator type is `input`, return the iterator after moving it `n` times, using `++` operator.
- Dispatch is handled using `iterator_category` tags.

*Dispatch: Selecting and calling the appropriate function based on the iterator category

### ⚒️ `distance.h`
- If the iterator type is `random_access`, return the distance calculated with `-` operator.
- If the iterator type is `input`, return the distance counted by incrementing the `begin` until it reaches `end`.
- Dispatch is handled using `iterator_category` tags.

### ⚒️ `iterator.h`
- This file simply includes all of the iterator-related header files in the folder.
- The users can utilize the iterators just by including this header.

### ⚒️ `iterator_category.h`
- This file contains the standard iterator category tags as empty `struct`s.
- These tags are used for tag dispatching to enable type-specific behavior in generic algorithms.
- Since empty `struct`s occupy no storage at runtime, they provide zero-overhead type information.
- The category tags are organized hierarchically using inheritance to represent iterator capabilities (C++ `struct`).

### ⚒️ `iterator_traits.h`
- This file stores the iterator traits based on the type of iterators.
- Stores `value_type`, `difference_type`, `pointer`, `reference`, and `iterator_category` of various iterators and primitive type pointers.

### ⚒️ `next.h`
- This function calls `advance` function copies the iterator to return one that moved `n` steps.

### ⚒️ `prev.h`
- This function calls `advance` function copies the iterator to return one that moved `-n` steps.


---

## 📚 Educational Attribution
> Created for educational purposes by Seungtack Lee
>
> The detailed file structure was constructed with help from GPT-4o,
> which provided the feedback for the code to fix errors and points to improve.

Unauthorized use in academic or professional submissions without proper credit is prohibited.

---

## 📖 Authorship Verification
This file is part of a self-built STL clone project.
If you found this code outside the original GitHub repository, please check or report:
[https://github.com/remydzn/cpp-study](https://github.com/remydzn/cpp-study)
