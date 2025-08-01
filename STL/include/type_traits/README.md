# 💽 Custom `type_traits` header (Minimal STL-style Value Type Header)

This folder contains a minimal value type traits for `utility` header.
I built minimal replicas of `std::type_traits` as part of the STL clone project.

---

## 💾 Files
- `is_lvalue_reference.h`: A structure that has information if the value type is lvalue reference.
- `is_rvalue_reference.h`: A structure that has information if the value type is rvalue reference.
- `type_traits.h`: A header that combines the type traits headers for deeper abstraction.

---

## 📋 Overview
Based on my learning from the Univ of Utah CS2420 course, 
I attempted to replicate the `is_lvalue_reference` and `is_rvalue_reference` in a separate header file. 

### ⚒️ `is_lvalue_reference.h`
- If the type is lvalue reference, store `true`.
- If not, store `false` to the `value`.

### ⚒️ `is_rvalue_reference.h`
- If the type is rvalue reference, store `true`.
- If not, store `false` to the `value`.

### ⚒️ `type_traits.h`
- This file simply includes the type traits headers.
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
