# 💽 Custom `utility` header (Minimal STL-style Utility Functions)

This folder contains a minimal `utility` header for STL containers, and for general usage.
Not only from CS2420 class from Univ of Utah, I referenced `cppreference.com` and GPT4o for detailed guidance.
Link to `cppreference.com`: [https://cppreference.com/](https://cppreference.com/)

---

## 💾 Files
- `forward.h`: Enables perfect forwarding.
- `make_pair.h`: Establish pair with given values.
- `max.h`: Return the maximum among the given two arguments.
- `min.h`: Return the minimum among the given two arguments.
- `move.h`: Move data to another variable without a copying operation.
- `pair.h`: Data type that has two values in a pair.
- `remove_reference.h`: Removing `&` of any value type for perfect forwarding.
- `swap.h`: Efficient swapping using `move()`
- `utility.h`: A header that combines the utility headers for deeper abstraction.

---

## 📋 Overview
Based on my learning from the Univ of Utah CS2420 course, reading from `cppreference.com`, and feedback from GPT-4o,
I attempted to replicate the `utility.h` for my STL cloning project in a separate header file. 

### ⚒️ `forward.h`
- If the argument is lvalue, use forwarding reference to return as the lvalue.
- If the argument is rvalue, use rvalue reference to return as the rvalue.

*Perfect forwarding: Preserves the value type; Ensures no conversion in value type.

### ⚒️ `make_pair.h`
- Use `pair()` to establish a pair with two given values.

### ⚒️ `max.h`
- Return the maximum among the given two arguments, using the `>` operator.
- Return the maximum among the given two arguments, using a custom comparison function pointer/functor.

### ⚒️ `min.h`
- Return the minimum among the given two arguments, using the `<` operator.
- Return the minimum among the given two arguments, using a custom comparison function pointer/functor.

### ⚒️ `move.h`
- For `template`, casting to rvalue reference prevents from copying values when assigning them to another variables.
- Using this feature, `move()` converts the given argument as a forward reference and moves the data.

### ⚒️ `pair.h`
- `pair` is a structure data type that has two public members inside.
- This structure uses its constructors to have to values paired with eachother.

### ⚒️ `remove_reference.h`
- Since C++ cannot build a function that returns a type, use the `using` keyword to pass the type.
  - later can be used as `remove_reference<T>::type`
  - `remove_reference<T>::type` can also be used as `remove_reference_t`
- If the value type is lvalue reference, store the type without `&`.
- If the value type is rvalue reference, store the type without `&&`.
- If the value type is without reference, store the raw type.
- 

### ⚒️ `swap.h`
- This STL-style `swap()` uses `move()` to avoid copying values when swapping.
- Other logic is identical to the general swapping algorithm.

### ⚒️ `utility.h`
- This file simply includes the utility headers.
- The users can utilize both algorithms just by including this header.
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
