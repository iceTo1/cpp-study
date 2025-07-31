# 💽 Custom `algorithm` header (Minimal STL-style Sorting Algorithms)

This folder contains a minimal sorting algorithm to imitate `std::sort`. 
Basic sorting algorithms were written based on the class CS2420 at the Univ of Utah.
intro_sort.h was designed with feedback and structural guidance from GPT-4o during self-study.

---

## 💾 Files
- `heap_sort.h`: Basic heap sort algorithm (guaranteed `O(NlogN)`).
- `insertion_sort.h`: Basic insertion sort algorithm (fastest with small size).
- `quick_sort.h`: Basic quick sort algorithm (fast for most cases).
- `intro_sort.h`: Advanced sorting algorithm which is used in `std::sort`.
- `sort.h`: A header that provides sort, with an abstracted intro sort algorithm.

---

## 📋 Overview
Based on my learning from the Univ of Utah CS2420 course, 
I attempted to replicate the `std::sort` in a separate header file. 

### ⚒️ Heap Sort
`heap_sort.h`
- Construct a Max-Heap
- Extract the root and move to the end
- Reconstruct a Max-Heap with the rest of the elements
- Repeat until only one element in the heap

### ⚒️ Insertion Sort
`insertion_sort.h`
- Consider the first element as a reference.
- Begin from the second element.
- For each element from the second to the last, insert it into its correct position among the elements to the reference's left.

### ⚒️ Quick Sort
`quick_sort.h`
- Select a pivot, typically the middle element.
- Traverse the container, comparing with the pivot, send smaller elements to the left and greater elements to the right.
- Recursively call the function twice, left partition of the pivot and right partition of the pivot.
- Repeat until one or less element left to sort.

### ⚒️ Intro Sort
`intro_sort.h`
- Begin with `quick sort`.
- If recursion goes too deep, switch to `heap sort`.
- The maximum recursion depth is usually set to `2 * (log2(num_of_elements))` to avoid worst-case Quick Sort behavior.
- When the partition size is smaller than the threshold, use `insertion sort`.

### ⚒️ Sort
`sort.h`
- Contains a generic function `floor_log2` for maximum depth, based on `log2` of element counts.
- Calculate the number of elements, maximum depth, and call the `intro_sort` function.

---

## 💻 Example Use Case
You can use this header to sort items.
```
ST::vector<int> vec = { 4, 2, 6, 4, 8 };
ST::sort(vec.begin(), vec.end());
```

---

## 📚 Educational Attribution
> Created for educational purposes by Seungtack Lee
>
> The advanced introsort logic was designed with help from GPT-4o,
> which provided structural guidance and critical feedback.

Unauthorized use in academic or professional submissions without proper credit is prohibited.

---

## 📖 Authorship Verification
This file is part of a self-built STL clone project.
If you found this code outside the original GitHub repository, please check or report:
[https://github.com/remydzn/cpp-study](https://github.com/remydzn/cpp-study)
