# Leetcode 125 - Valid Palindrome

## Problem Description
This problem is about checking if the given string is palindrome or not, after ignoring all the space and special characters.

ex)
- haystack = "A man, a plan, a canal: Panama"
    - Output: true (`amanaplanacanalpanama` is palindrome)
- haystack = "race a car"
    - Output: false (`raceacar` is not palindrome)

Link to the problem: (https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150)

---

## Solutions Description

### solution.cpp (Solved by making additional string variable)
- Declare a variable to store the converted string (`compare`).
- Iterate through to convert the elements.
    - If the element is alphabet, add to the `compare` after converting it to lowercase character.
    - If the element is number, add to the `compare`.

- Declare two iterators that points to the first and the last element.
- Iterate while the left iterator points to the element that is on the left side of what the right iterator is pointing.
    - If the values of iterators are differernt, return false immediately.
    - Move the first iterator to the right, second iterator to the left.
- If the values were symmetrical, return true.

- Time Complexity: O(N)
- Runtime: 0ms

---

## What I Learned
Last time, I learned that concatenating `std::string` is pricy because of memory allocation.
However, I believed that this problem requires additional space to store correctly converted string to check.

After passing all the tests, I asked a Generative AI for feedback, and it gave me a suggestion to use `reserve()` function so that it could process the memory allocation step in advance.