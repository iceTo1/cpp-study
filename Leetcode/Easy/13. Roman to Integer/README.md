# Leetcode 13 - Roman to Integer

## Problem Description
This is about returning integer value after reading roman numerical value as input
ex) "III" -> 3, "IX" -> 9, "LVIII" -> 58

Link to the problem: https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150

---

## Solutions Description

### main_index.cpp (Solved with Index)
- Uses one `for` loop and `s[i]` indexing.
- Each special case described in the problem (e.g., "IV", "IX", etc.) is checked first.
- Bound check is done  with `i + 1 < s.size()` before accessing `s[i + 1]`.
- Time Complexity: O(N)
- Runtime: 0ms

### main_iterator.cpp (Solved with Iterator)
- Uses one `while` loop and `std::string::iterator`.
- Each special case described in the problem is checked first.
- Bound check is done with `std::next(iter)`, but to reduce calling the `std::next()` frequently, the value is stored in `auto next`.
- Although having the same format, this solution turned out to be slower than Index solution, and I reasoned that calling `std::next()` could be the reason, slower than index operation.
- Time Complexity: O(N)
- Runtime: 4ms

---

## What I Learned

- At first, I thought using iterator would be faster because the iterators are designed specially for STL containers, thus I reasoned that they would be the fastest, with the best efficiency. However, the result was the opposite. I assume that calling `std::next()` multiple times can slow the result of the code than directly accessing with index by performing integer operation.
- Learned why `*(iter + 1)` is unsafe, and how `std::next(iter)` can cover index checking.

---

## Files

- `main_index.cpp`: Solution using indexing
- `main_iterator.cpp`: Solution using STL iterator