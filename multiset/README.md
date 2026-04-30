# C++ STL: `std::multiset`

## Overview
`std::multiset` is an **ordered associative container** in C++ STL that stores **multiple occurrences** of elements in **sorted order**. It is implemented using a **Red-Black Tree (self-balancing BST)** and provides **O(log N) complexity** for insertion, deletion, and lookup operations.

## Properties of `std::multiset`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Red-Black Tree (Self-Balancing BST) |
| **Iterator Support** | ✓ Yes (Bidirectional Iterator) |
| **Random Access** | ✗ No |
| **Allows Duplicates** | ✓ Yes (Stores multiple identical elements) |
| **Sorting Order** | ✓ Yes (Elements in sorted order) |
| **Average Time Complexity** | O(log N) for Insert, Delete, Search |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `insert(value)` | Inserts a value (Duplicates allowed) | **O(log N)** |
| `erase(value)` | Removes all occurrences of the value | **O(log N)** |
| `find(value)` | Returns an iterator to the first occurrence of value | **O(log N)** |
| `count(value)` | Returns the number of occurrences of a value | **O(log N)** |
| `begin(), end()` | Iterators to traverse the set | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the set is empty | **O(1)** |
| `clear()` | Removes all elements | **O(N)** |
| `lower_bound(value)` | Returns iterator to first element not less than value | **O(log N)** |
| `upper_bound(value)` | Returns iterator to first element greater than value | **O(log N)** |
| `equal_range(value)` | Returns pair of iterators `{lower_bound, upper_bound}` | **O(log N)** |

---

## When to Use `std::multiset`?
| Scenario | Use `multiset`? | Better Alternative |
|----------|-----------------|-------------------|
| Need to store elements sorted automatically AND allow duplicates | ✓ Yes | — |
| Need fast lookup but order doesn't matter | ✗ No | `unordered_multiset` |
| Need unique elements only | ✗ No | `set` |
| Need key-value mapping | ✗ No | `multimap` |

---

## Common Pitfalls
1. **`erase(value)` removes ALL occurrences**
 - If you have three `10`s in your multiset and call `mset.erase(10)`, **all three** are deleted.
 - If you only want to delete **one** occurrence, you must find it and erase by iterator: 
 `mset.erase(mset.find(10));` (Note: `find()` returns an iterator to the first occurrence).
2. **Modifying elements breaks the multiset**
 - You cannot modify the value of an element directly because it would break the internal BST ordering. You must `erase()` and `insert()`.

---

## Tips & Tricks
1. **Use `.count(val)` carefully**
 - While `mset.count(val)` is often thought of as O(log N), it is actually **O(log N + K)** where K is the number of occurrences. If K is very large, this can be slow.
2. **Use `equal_range()` to process all duplicates**
 - `auto [start, end] = mset.equal_range(val);` is the most efficient way to get bounds for all occurrences of `val`.
3. **Use `.lower_bound()` instead of `std::lower_bound()`**
 - `mset.lower_bound(val)` is O(log N). `std::lower_bound(mset.begin(), mset.end(), val)` is technically O(N) for non-random-access iterators!