# Leetcode 28 - Find the Index of the First Occurrence in a String

## Problem Description
This problem is about returning the index of the first occurrence of `needle` in `haystack`.

ex)
- haystack = "sadbutsad", needle = "sad"
    - Output: 0
- haystack = "leetcode", needle = "leeto"
    - Output: -1

Link to the problem: (https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150)

---

## Solutions Description

### solution.cpp (Solved by comparing elements' value with same index, adding same value into new string)
- If the `haystack` and `needle` is the same, return 0.
- If one of the strings are empty, return -1.
- Declare a loop to size of `needle` to minimize the loop (`loopCount`).
- Declare a string variable to store same characters, and compare at the last step (`compareStr`).
- Declare a integer variable to store index, to return (`index`).
- Iterate through the `haystack` for its size, `k`.
    - If the `compareStr` is identical with `needle`, return index.
    - If `k`th element in `haystack` is the same as first character of `needle`, and `k` + `loopCount` is within the `haystack` range, iterate `loopCount` times, using `i`.
        - Set index to `k`.
        - Add the `k`th character to the `compareStr`.
        - Incrase the `i`.
        - If the `compareStr` is the same as `needle`, return `index`.
- If `compareStr` is identical with `needle`, return `index`.
- Else, return `-1`.

- Time Complexity: O(N^3)
- Runtime: 0ms

---

## What I Learned
At first, I thought this problem was simple. However, it turned out to be quite tricky when it comes to handling the edge cases, such as 'mississipi'. 
The way I solved this problem was to copy the code into Visual Studio, set up breakpoint, and debug while following through the code. 
This felt like working, but after I passed every case, I found that my code is hard to read, difficult to understand and not clean.

Thus, I asked the AI to give me feedback and the clean code it gave me was obviously easy to understand.
The feedback of the AI also taught me that:
    - Manipulating loop variable inside another loop can cause a serious bug.
    - Using uninitialized variable can trigger Undefined Behavior.
    - Concatenating string is pricy (more than O(N^2)).
    - Same statement of condition check should be only one, not scattered in different places.
    - It is important to keep the implementation readable.

I was noticing my code is getting ugly, but I firstly wanted to solve the question. Now that I passed all cases, I will come back later, and try to solve it in a cleaner way.

## Files

- `solution.cpp`: Solution
- `Assigning extreme value.md`: Study note about assigning extreme value