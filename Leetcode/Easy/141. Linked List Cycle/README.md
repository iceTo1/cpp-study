# Leetcode 141 - Linked List Cycle

## Problem Description
This problem is about checking if the linked list is cycling or not

ex)
- Input: head = [3, 2, 0, -4], pos = 1
    - Output: true
- Input: head = [1, 2], pos = 0
    - Output: true
- Input: head = [1], pos = -1
    - Output: false

Link to the problem: (https://leetcode.com/problems/linked-list-cycle/submissions/1614427363/?envType=problem-list-v2&envId=two-pointers)

---

## What I learned & Solution Description

### Floyd’s Cycle Detection Algorithm

- The key idea of this algorithm is that if there is any cycle, no matter where they repeat, if two pointers advance with different gaps (one with one, the other with two), they will eventually meet. If there is no cycle, they will not meet and one of them reaches the end of the list.
    [Let pointer with bigger gap as `fast`, smaller gap as `slow`]
    
- The important part of this problem was checking the equality of nodes itself, not the values that they contain. At first after I read about this type of algorithm, I was comparing the value, not the nodes, so I was not able to check if the cycle exists correctly when it comes to the list with all same data.

- `slow` and `fast` both starts from the first node.

- The last important part is the condition to keep on iterate. Just like the exception case, the loop only checks if the `fast` has not reached the end or it can advance once. Checking the `slow` is not necessary because the `fast` automatically checks the node it will point later.
    Why check `fast` and `fast->next`?

    This is to prevent the operation to do `nullptr->next`, which is a critical action called `segment fault` that results in immediate crash.
    - If the `fast` is `nullptr`, this means the `fast` has reached the end.
    - If the `fast->next` is `nullptr`, this means the `fast->next->next` will reach the end.
    ⇒ Checking only these two condition will prevent the program referencing `nullptr`.

## Files
- `solution.cpp`: Solution after learning about Floyd's algorithm.