# Leetcode 392 - Is Subsequence

## Problem Description
This problem is about checking if the first given string is subsequence of the second string or not.

ex)
- Input = `s` = "abc", `t` = "ahbgdc"
    - Output: true
- Input = `s` = "axc", `t` = "ahbgdc"
    - Output: false
- Input = `s` = "aec", `t` = "abcde"
    - Output: false (`abcde` cannot be made after adding values betwen characters of `aec`)

Link to the problem: (https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150)

---

## Solutions Description

### solution.cpp (Solved by making additional string variable)
- If the `s` is empty, return true.
- Declare a string variable for final compare (`container`).
- Declare an integer variable to store index, initial value as -1 (`idx`).
- Declare an integer variable to iterate (`j`).
- Iterate for the size of `s` [integer `i` from 0 to `s.size() - 1`]
    - Set `j` to `idx` + 1.
    - Iterate for the size of `t` [integer `j` to `t.size()`]
        - If `j`th element of `t` is the same as `i`th element of `s`,
            Add the element to container.
            Set `idx` as `j`.
            `break` from the inner loop.
        - Else, move forward to keep on searching on `t`
- If the container is the same as `s`, return true.
- If the condition is not met, return false.

- Time Complexity: O(N^2)
- Runtime: 0ms

---

## What I Learned
This problem was also about using two pointers. Learning from `Roman to Integer` and `Valid Palindrome`, I did not use iterator and used index for direct accessing.
However, I still could not figure out how to solve the problem without additional container. The idea that I came up with was to compare elements with `s` until finding the same element from `t` by moving forward, but I could not think of how to decide the final condition to return `true` or `false`.

After solving, I asked the Gernerative AI for feedback, and this problem was also could be solved without an additional container, deciding the final condition with index only.
I believe this type of problems are my current weakness, I will try to practice more with same type until I get used to solve the problems in-place.
(https://leetcode.com/problem-list/two-pointers/)

Additionally, I learned that using `empty()` function rather than using the statement `"" == s` is more easy to read, and more modern.

## Files

- `solution.cpp`: First approach, using additinoal container.