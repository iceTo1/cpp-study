# Leetcode 169 - Majority Element

## Problem Description
This is about the element that appears more than "size / 2" times in the array. Element that satisfies the condition always exists.
ex)
- {3, 2, 3} -> 3
- {2, 2, 1, 1, 1, 2, 2} -> 2

Link to the problem: https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

---

## Solutions Description

### main_index.cpp (Solved with std::sort())
- Uses std::sort() function.
- Returns the middle element of the sorted array.
- Time Complexity: O(NlogN)
- Runtime: 3ms

---

## What I Learned

- At first, I tried my best to figure out how to solve this with O(N) time complexity. This led me to manipulate the sum of the elements. -> I thought I found a pattern that the output is always the rounded number of average value, but it was wrong.
- In the end, I decided to just sort first and think after for simplicity.
- After that, luckily, I found out that when I return the middle element after sorting, it always returns the majority value.

---

## Files

- `solution.cpp`: Solution