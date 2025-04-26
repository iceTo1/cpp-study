# Leetcode 202 - Happy Number

## Problem Description
This problem is about checking if an integer is happy number.

ex)
- Input: n = 19
    - Output: true
    - Explanation:
        1^2 + 9^2 = 82
        8^2 + 2^2 = 68
        6^2 + 8^2 = 100
        1^2 + 0^2 + 0^2 = 1
- Input: n = 2
    - Output: false

Link to the problem: (https://leetcode.com/problems/happy-number/?envType=problem-list-v2&envId=two-pointers)

---

## Solutions Description

### solution.cpp (Solved by matching the length, and comparing while advancing)
- Declare an integer variable to store the result.
- Iterate infinitely
    - Iterate while the given integer is not 0
        - Add the squared value of the last digit of given integer.
        - Update the integer after removing the last digit.
    - If the calculated result is 1 (happy number), return true.
    - If the calculated result is less than 4, and not 0, escape from the loop.
    - Update the integer to the calculated result, and reset the result value to 0.
- Return false if the integer is not a happy number.

- Time Complexity: O(logN)
- Runtime: 0ms

---

## What I Learned
- At first, I tried to convert the given integer to string and calculate the result but after debugging, I found that adding after converting to string is inappropriate (calculating `char` type).
- So I shifted my way of approach to perform `%` to get each digit of input.
- Unlike the category, I did not use any pointer.
- The most difficult part of this problem was finding condition to escape the loop. To find it, I brute forced that 2, 3, 4 will never be happy number.

## Files

- `solution.cpp`: Solution.