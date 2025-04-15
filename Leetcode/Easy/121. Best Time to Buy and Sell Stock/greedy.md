# Greedy Algorithm

---

## “Choosing what seems to be the best, at every pass”

## Key Ideas

### 1. Greedy Choice Property

→ Current best choice needs to be globally best .

### 2. Optimal Substructure

→ Even if the problem is divided into the smaller problems, their solutions are part of the big solution.

### Adapting to the LeetCode problem

- Buy the stock if the prices is the lowest
- Each step, calculate the profit [`sell` - `buy`]
- Keep track of the maximum profit
- Final maximum profit is the result