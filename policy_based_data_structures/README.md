> [!WARNING]
> Policy-Based Data Structures (PBDS) are **NOT** part of the C++ Standard Library (ISO C++).
> They are a **GCC extension** available via `<ext/pb_ds/assoc_container.hpp>`.
> They will **NOT** compile on MSVC (Visual Studio) or Clang without `libstdc++`.

# GCC Extension: Policy-Based Data Structures

## Overview
Policy-Based Data Structures provide specialized containers that are not available in the standard STL. The most famous and commonly used one in Competitive Programming is the **Order Statistics Tree**.

An Order Statistics Tree acts exactly like a `std::set`, but adds two incredibly powerful `O(log N)` operations:
1. Find the **k-th smallest element**.
2. Find the **index** (number of elements strictly less than) a given element.

## Setup
You need specific headers and namespaces:
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
```

Then you define the type (usually hidden behind a `typedef` or `using`):
```cpp
typedef tree<
    int,                               /* Key type */
    null_type,                         /* Mapped-policy (null_type makes it a set) */
    less<int>,                         /* Comparator (use less_equal for multiset behavior) */
    rb_tree_tag,                       /* Red-Black tree */
    tree_order_statistics_node_update  /* Enables order statistics */
> ordered_set;
```

---

## 📝 Member Functions
An `ordered_set` has all the normal functions of `std::set` (`insert`, `erase`, `find`, `lower_bound`), **plus**:

| Function | Description | Time Complexity |
|----------|------------|----------------|
| `find_by_order(k)` | Returns an iterator to the **k-th** smallest element (0-indexed) | **O(log N)** |
| `order_of_key(value)` | Returns the number of elements **strictly less than** `value` | **O(log N)** |

## When to Use PBDS?
- When you need to answer "What is the median element right now?" dynamically as elements are inserted/removed.
- When you need to answer "How many numbers are smaller than X?" dynamically.
- (Standard STL requires a `vector` + `sort` + `binary_search` for this, which is `O(N log N)` for insertions. PBDS does it in `O(log N)`).
