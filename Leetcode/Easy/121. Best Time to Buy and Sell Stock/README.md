# Leetcode 169 - Majority Element

## Problem Description
This is about selecting the smallest value and biggest value that is right to the smallest, making the gap between the values as the maximum.
The problem simulates a stock-buying situation, maximizing the revenue.

ex)
- {7, 1, 4, 3, 6, 4} -> 5
- {7, 6, 4, 3, 1} -> 0

Link to the problem: (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150)

---

## Solutions Description

### main_index.cpp (Solved with "Greedy Algorithm")
- Initializes the buying price as the first element, selling profit to 0.
- While iterating through the list, buy when the price is the lowest, sell when the profit is the highest. 
- Declaring `profit` variable is one key point of this solution (can store current revenue, and maximum revenue to compare).
- Time Complexity: O(N)
- Runtime: 0ms

---

## What I Learned

- At first, I thought that this problem asks me to utilize the "Selection Sort" algorithm; store the minimum value's index, selecting the smallest value.
- However, I was stuck at test case 211 out of 212 and I could not figure out how to improve my code.
- After asking a feedback to the generative AI, I learned about the idea of "Greedy Algorithm".
- The problem turned out to be simple when I reconstructed my code.

---

## Files

- `solution.cpp`: Solution
- `greedy.md`: Study, notes about greedy algorithm (also added to notion)