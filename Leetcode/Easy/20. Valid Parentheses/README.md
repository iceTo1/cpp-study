# Leetcode 20 - Valid Parentheses

## Problem Description
This problem is about checking if given string has valid parentheses syntax.

ex)
- Input: s = "()"
    - Output: true
- Input: s = "()[]{}"
    - Output: true
- Input: s = "(]"
    - Output: false
- Input: s = "([])"
    - Output: true

Link to the problem: (https://leetcode.com/problems/valid-parentheses/description/?envType=problem-list-v2&envId=2yaiuobm)

---

## Solutions Description

### solution.cpp (Solved by iterating through the string while checking the parentheses)
- Declare a stack to store the string element.
- Iterate through the given string.
    - If the string element is one of the opening bracket, ( '(', '{', '[' )
        -  Push to the stack.
    - If the string element is one of the closing bracket, ( ')', '}', ']' )
        - Check if the stack is empty, and if the stack's top element matches with the  braket.
            - If either one of the condition is true, return false.
            - Otherwise, remove the top element from the stack.
- Finally, return true if the stack is empty.

- Time Complexity: O(N)
- Runtime: 0ms

---

## What I Learned
- This problem had more edge cases than I expected. I passed after attempting for 5 times.
- After solving the problem, I realized I was checking similar conditions repeatedly while handling edge cases I did not thought of at first. -> After grouping and re-writing the similar if-else blocks, my code became more cleaner and easier to understand.

## Files

- `solution.cpp`: Solution.