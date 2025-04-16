# Assigning Extreme Value to Variable

## C-Style
Uses pre-defined constant values in `<climits>` or `<limits.h>`
    ex) `INT_MAX` is defined as `#define INT_MAX 2147483647`
Assigning these to variables will give them their maximum values.

```
#include <climits>

int maxValue = INT_MAX;
int minValue = INT_MIN;
```

## C++ Style
Uses `std::numeric_limits<T>` template class.
This template class provides more safety through type checking (C-style can assign `INT_MAX` to `float` or other data types).

```
#include <limits>

int maxValue = std::numeric_limits<int>::max();
int minValue = std::numeric_limits<int>::min();
```

## Bonus `std::max()`, `std::min()`
If two arguments are given, returns the maximum/minimum value.

```
int maximum = std::numeric_limits<int>::min();
int minimum = std::numeric_limits<int>::max();

for (int val : vec)
{
    maximum = std::max(maximum, val);
    minimum = std::min(minimum, val);
}
```