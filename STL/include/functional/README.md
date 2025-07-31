# 💽 Custom `functional` header (Minimal STL-style Comparing Algorithms)

This folder contains a minimal comparator utilities to construct `ST::sort`.
I built minimal replicas of `std::less` and `std::greater` as part of the STL clone project.

---

## 💾 Files
- `functional.h`: A header that combines the `greater.h` and `less.h` for deeper abstraction.
- `greater.h`: A generic algorithm to return greater value between the given two.
- `less.h`: A generic algorithm to return less value between the given two.

---

## 📋 Overview
Based on my learning from the Univ of Utah CS2420 course, 
I attempted to replicate the `std::less` and `std::greater` in a separate header file. 

### ⚒️ `functional.h`
- This file simply includes the `greater.h` and `less.h`.
- The users can utilize both algorithms just by including this header.

### ⚒️ `greater.h`
- This includes a generic functor named `greater`.
- The structure takes two arguments and compares them using the > operator.
- Return `true` if the first argument is **greater**.

### ⚒️ `less.h`
- This includes a generic functor named `less`.
- The structure takes two arguments and compares them using the > operator.
- Return `true` if the first argument is **less**.

---

## 💻 Example Use Case
You can use this header to sort items.
```
ST::vector<int> vec = { 4, 2, 6, 4, 8 };
ST::sort(vec.begin(), vec.end(), ST::greater<int>());
```

---

## 📚 Educational Attribution
> Created for educational purposes by Seungtack Lee
>
> The detailed file structure was constructed with help from GPT-4o,
> which provided the idea to abstract `less` and `greater` into a unified `functional.h`.

Unauthorized use in academic or professional submissions without proper credit is prohibited.

---

## 📖 Authorship Verification
This file is part of a self-built STL clone project.
If you found this code outside the original GitHub repository, please check or report:
[https://github.com/remydzn/cpp-study](https://github.com/remydzn/cpp-study)
