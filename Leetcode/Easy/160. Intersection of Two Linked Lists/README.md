# Leetcode 160 - Intersection of Two Linked Lists

## Problem Description
This problem is about checking if the two singly linked lists join another singly linked list.

ex)
- Input: listA = [4, 1, 8, 4, 5], listB = [5, 6, 1, 8, 4, 5]
    - Output: Intersected at '8'
- Input: listA = [1, 9, 1, 2, 4], listB = [3, 2, 4]
    - Output: Intersected at '2'
- Input: listA = [2, 6, 4], listB = [1, 5]
    - Output: null

Link to the problem: (https://leetcode.com/problems/intersection-of-two-linked-lists/description/?envType=problem-list-v2&envId=two-pointers)

---

## Solutions Description

### solution.cpp (Solved by matching the length, and comparing while advancing)
- If the two nodes are already the same, immediately return one.
- If the two nodes are both pointing to nothing, immediately return `nullptr`
- Declare two variables to store the first node of first list, and first node of second list (`listA`, `listB`).
- Declare another two variables to store the data of the two variables above (`tempA`, `tempB`).
- Declare two variables to store the length of the two lists (`lenA`, `lenB`).
- Iterate through the first list with `tempA` while increasing `lenA`.
- Iterate through the second list with `tempB` while increasing `lenB`.
- Advance the list pointers of the longer list.
- While both of the pointers `listA` and `listB` are valid, advance them and check if the nodes they are pointing to is identical.
    - If the identical node is found, return the node.
- If the above loop is finished without returning any node, consider there is no intersection, and return `nullptr`.

- Time Complexity: O(N+M)
- Runtime: 29ms

---

## What I Learned
- At first, I was re-using the `listA` and `listB` after checking the length of the lists. This caused unintended behavior to compare only the last nodes. I learned that it is important to declare another variable or reinitialize them once they are used.
- Also, after solving the problem, I found that my two `if-else` statements were having same statement at the bottom, so I refined my code to only contain the common section only once, after checking the conditions.
- Lastly, I was not iterating through the list correctly because I was comparing the `difference` to be greater or equal to `0`. This caused another iteration, which was incorrect.

## Files

- `solution.cpp`: Solution.