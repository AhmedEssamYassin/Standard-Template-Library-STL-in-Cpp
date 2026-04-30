# C++ STL: `std::multimap`

## Overview
`std::multimap` is an **ordered associative container** in C++ STL that stores **key-value pairs** in **sorted order**, allowing **duplicate keys**. It is implemented using a **Red-Black Tree (self-balancing BST)** and provides **O(log N) complexity** for insertion, deletion, and lookup operations.

## Properties of `std::multimap`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Red-Black Tree (Self-Balancing BST) |
| **Iterator Support** | ✓ Yes (Bidirectional Iterator) |
| **Random Access** | ✗ No |
| **Allows Duplicates** | ✓ Yes (Multiple values per key) |
| **Sorting Order** | ✓ Yes (Keys in sorted order) |
| **Average Time Complexity** | O(log N) for Insert, Delete, Search |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `insert({key, value})` | Inserts a key-value pair (Allows duplicates) | **O(log N)** |
| `erase(key)` | Removes all elements with the given key | **O(log N)** |
| `find(key)` | Returns an iterator to the first occurrence of key | **O(log N)** |
| `count(key)` | Returns the number of occurrences of a key | **O(log N)** |
| `begin(), end()` | Iterators to traverse the map | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the map is empty | **O(1)** |
| `clear()` | Removes all elements | **O(N)** |
| `lower_bound(key)` | Returns iterator to first element not less than key | **O(log N)** |
| `upper_bound(key)` | Returns iterator to first element greater than key | **O(log N)** |
| `equal_range(key)` | Returns pair of iterators `{lower_bound, upper_bound}` | **O(log N)** |

---

## When to Use `std::multimap`?
| Scenario | Use `multimap`? | Better Alternative |
|----------|-----------------|-------------------|
| Need key-value pairs sorted by key AND duplicate keys | ✓ Yes | — |
| Need fast lookup but order doesn't matter | ✗ No | `unordered_multimap` |
| Need unique keys | ✗ No | `map` |
| Only need to store values (no keys) | ✗ No | `multiset` |

---

## Common Pitfalls
1. **No `operator[]` or `at()`**
 - Because `multimap` allows duplicate keys, `myMap["key"]` makes no sense (which value should it return?). You MUST use `insert()` to add elements and `equal_range()` or `find()` to retrieve them.
2. **`erase(key)` removes ALL matching keys**
 - If you have three elements with the key `"apple"` and you call `mmap.erase("apple")`, **all three** are deleted. If you only want to delete one, you must find it and erase by iterator: `mmap.erase(mmap.find("apple"));`
3. **Strict Weak Ordering Requirement**
 - Like `map` and `set`, the key type must have a valid `operator<` or a custom comparator that enforces strict weak ordering.

---

## Tips & Tricks
1. **Use `equal_range()` to iterate over a specific key**
 - Instead of manually finding `lower_bound` and `upper_bound`, use `equal_range` with structured bindings:
 ```cpp
 auto [it_start, it_end] = mmap.equal_range("key");
 for (auto it = it_start; it != it_end; ++it) { /* process it->second */ }
 ```
2. **Use `emplace` instead of `insert`**
 - `mmap.emplace("key", value);` is faster than `mmap.insert({"key", value});` as it avoids constructing a temporary `std::pair`.