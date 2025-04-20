# log.md

Author: Seungtack Lee
Date: Apr 20, 2025

## Records while building the code

- List members, (data, next, prev) are private to the user (TOTALLY!). No getter, no setter, only accessible through iterators.

- To allow access to list of node private members, declare list class before the node class (to let it know about the presence of list class). And use `friend class list<T>;` before end of node class definition.

- Using `while` loop for deleting all nodes is more safe. `for` loop with using `m_Count` has possibility that it does not match with the actual node count.

- My `ValidityTest()` function is better when the return type is void, and when the function is `const`.

- Presence of `cbegin`, `crbegin`, `cend`, `crend`.

- Learned that `begin()`, `cbegin()` functions does not throw exception to use `range-based for loop`.
    Then why there is no `noexcept` keyword? Type `T`, or node can have exceptions. However, `size()` functions have `noexcept`.

- First, I tried to build `end()` function to return next node of the tail node. However, this only works when the list is not empty. Although I tried to use the statement for readability, I found that just returning `nullptr` is more safer, and have better performance.

- As I continued learning while writing code with trial and error, I learned that the STL data structures accepted the dangerous, but light and fast performance.

- Learned that `std::initializer_list<T>` is the only official way to use `{}` to initialize my recreated STL containers.
    Use them in constructor to pass and assign the list data.

“These notes are for personal reference and were gained through direct implementation.”