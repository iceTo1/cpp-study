# Leetcode 58 - Length of Last Word

## Problem Description
This problem is about counting the length of the last word of given sentence.

ex)
- Input: "Hello World"
    - Output: 5
- Input: "   fly me   to   the moon  "
    - Output: 4

Link to the problem: (https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150)

---

## Solutions Description

### solution.cpp (Solved with "Reverse Iterator")
- Initializes the count to 0, and reverse iterator to the end of the given string.
- If the string ends with blanks spaces, shift the iterator left to skip them (bound check if the iterator reaches the left end of the string).
- If the iterator ignores all the blanks spaces, shift the iterator left until another blank appears while increasing the count by 1 (bound check if the iterator reaches the left end of the string).
- If there was no blank at the end, count the last word's length with the same algorithm above.

- Time Complexity: O(N)
- Runtime: 0ms

---

## What I Learned

- Rather than counting from the left, due to uncertainty of how many words could be in the string, I chose to read the last word only, using reverse iterator.
- I missed the edge case where the string is only one word. This caused the stack underflow, which I have never actually encountered before.
- After I added the bound check, the problem was solved.

---

## Files

- `solution.cpp`: Solution