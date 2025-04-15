# Leetcode 14 - Longest Common Prefix

## Problem Description
This problem is about find the longest common prefix among a given array of strings.

ex)
- Input: [ "flower", "flow", "flight" ]
    - Output: "fl"
- Input: [ "dog","racecar","car" ]
    - Output: ""

Link to the problem: (https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150)

---

## Solutions Description

### main_index.cpp (Solved by comparing elements' value with same index)
- If the array has only one string, return the only element.
- Iterate through the string elements to find minimum length among them (to minimize the comparison).
- Declare variables to temporarily storing a character value, and to store the final output string.
- Iterate through the string elements, temporarily store the first element's 'i'th character, compare with the same index of other strings.
- If the characters are identical, concatenate the character to the string variable.
- As soon as the characters do not match, return the string variable.

- Time Complexity: O(N)
- Runtime: 0ms

---

## What I Learned

- I initialized the variable to check the minimum size of the string element by using the restriction of the problem (0 <= strs[i].length <= 200). 
- However, I reaslized that if I learn how to assign the biggest value of the type right away, the solution could cover more general cases.

---

## Files

- `solution.cpp`: Solution