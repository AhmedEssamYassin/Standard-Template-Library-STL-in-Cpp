# C++ STL: `std::set`

## Overview
`std::set` is an **ordered associative container** in C++ STL that stores **unique elements in sorted order**. It is implemented using a **Red-Black Tree (self-balancing BST)** and provides **O(log N) complexity** for insertion, deletion, and lookup operations.

## Properties of `std::set`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Red-Black Tree (Self-Balancing BST) |
| **Iterator Support** | ✓ Yes (Bidirectional Iterator) |
| **Random Access** | ✗ No |
| **Allows Duplicates** | ✗ No (Only unique elements) |
| **Sorting Order** | ✓ Yes (Elements in sorted order) |
| **Average Time Complexity** | O(log N) for Insert, Delete, Search |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `insert(value)` | Inserts a value (Duplicates not allowed) | **O(log N)** |
| `erase(value)` | Removes the value from the set | **O(log N)** |
| `find(value)` | Returns an iterator to the value if found | **O(log N)** |
| `count(value)` | Returns 1 if value exists, otherwise 0 | **O(log N)** |
| `begin(), end()` | Iterators to traverse the set | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the set is empty | **O(1)** |
| `clear()` | Removes all elements | **O(N)** |
| `lower_bound(value)` | Returns iterator to first element not less than value | **O(log N)** |
| `upper_bound(value)` | Returns iterator to first element greater than value | **O(log N)** |
| `equal_range(value)` | Returns pair of iterators `{lower_bound, upper_bound}` | **O(log N)** |

---

## When to Use `std::set`?
| Scenario | Use `set`? | Better Alternative |
|----------|------------|-------------------|
| Need to store unique elements sorted automatically | ✓ Yes | — |
| Need fast lookup but order doesn't matter | ✗ No | `unordered_set` (O(1) average) |
| Need to store duplicate elements | ✗ No | `multiset` |
| Need key-value mapping | ✗ No | `map` |
| Frequent range queries (e.g. elements between X and Y) | ✓ Yes | — |

---

## Common Pitfalls
1. **Modifying elements breaks the set**
 - You cannot modify the value of an element directly because it would break the internal BST ordering. To change a value, you must `erase()` the old one and `insert()` the new one.
2. **Strict Weak Ordering Requirement**
 - If you use a custom struct/class, you MUST overload `operator<` or provide a custom comparator. The comparator must enforce strict weak ordering. If `A < B` is false and `B < A` is false, `set` considers `A` and `B` equal and will not insert the duplicate.
3. **Performance overhead**
 - `std::set` allocates a new tree node for every element. For small elements, the overhead of pointers (left, right, parent, color) can exceed the size of the data itself.

---

## Tips & Tricks
1. **Use `emplace` (C++11)**
 - `mySet.emplace(args...)` constructs the object directly in place, avoiding temporary copies compared to `insert()`.
2. **Use `.contains()` (C++20)**
 - `if (mySet.contains(val))` is cleaner than `if (mySet.find(val) != mySet.end())`.
3. **Use `.lower_bound()` instead of `std::lower_bound()`**
 - `mySet.lower_bound(val)` is O(log N). `std::lower_bound(mySet.begin(), mySet.end(), val)` is technically O(N) for non-random-access iterators!