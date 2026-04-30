# C++ STL: `std::map`

## Overview
`std::map` is an **ordered associative container** in C++ STL that stores **key-value pairs** in **sorted order** using a **Red-Black Tree (self-balancing BST)**. It provides **O(log N) complexity** for insertion, deletion, and lookup operations.

## Properties of `std::map`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Red-Black Tree (Self-Balancing BST) |
| **Iterator Support** | ✓ Yes (Bidirectional Iterator) |
| **Random Access** | ✗ No |
| **Allows Duplicates** | ✗ No (Unique Keys) |
| **Sorting Order** | ✓ Yes (Keys in sorted order) |
| **Average Time Complexity** | O(log N) for Insert, Delete, Search |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `insert({key, value})` | Inserts a key-value pair | **O(log N)** |
| `erase(key)` | Removes the element with the given key | **O(log N)** |
| `find(key)` | Returns an iterator to the element if found, else `end()` | **O(log N)** |
| `count(key)` | Returns 1 if key exists, otherwise 0 | **O(log N)** |
| `at(key)` | Returns reference to the mapped value | **O(log N)** |
| `operator[] (key)` | Inserts if key doesn't exist, else returns reference | **O(log N)** |
| `begin(), end()` | Iterators to traverse the map | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the map is empty | **O(1)** |
| `clear()` | Removes all elements | **O(N)** |
| `lower_bound(key)` | Returns iterator to first element not less than key | **O(log N)** |
| `upper_bound(key)` | Returns iterator to first element greater than key | **O(log N)** |
| `equal_range(key)` | Returns pair of iterators `{lower_bound, upper_bound}` | **O(log N)** |

---

## When to Use `std::map`?
| Scenario | Use `map`? | Better Alternative |
|----------|------------|-------------------|
| Need key-value pairs sorted by key | ✓ Yes | — |
| Need fast lookup but order doesn't matter | ✗ No | `unordered_map` (O(1) average) |
| Need duplicate keys | ✗ No | `multimap` |
| Only need to store unique values (no keys) | ✗ No | `set` |
| Frequent range queries (e.g. elements between X and Y) | ✓ Yes | — |

---

## Common Pitfalls
1. **`operator[]` inserts default values**
 - If you check `if (myMap["key"])`, it will **insert** `"key"` with a default value if it doesn't exist. Use `myMap.find("key")` or `myMap.count("key")` to check for existence instead.
2. **Strict Weak Ordering Requirement**
 - If you use a custom struct/class as a key, you MUST overload `operator<` or provide a custom comparator. The comparator must enforce strict weak ordering (if A < B is true, B < A must be false). If it doesn't, map behavior is **undefined** (elements might be lost or not found).
3. **Iterator Invalidation**
 - Erasing an element invalidates iterators pointing to that specific element, but *not* other iterators. Be careful when erasing elements while iterating through the map.

---

## Tips & Tricks
1. **Use `emplace` or `try_emplace` (C++17)**
 - `myMap.try_emplace(key, args...)` avoids constructing the value object if the key already exists, saving performance.
2. **Use Structured Bindings (C++17)**
 - `for (auto& [k, v] : myMap)` is much cleaner than `for (auto& p : myMap) { cout << p.first << p.second; }`.
3. **Use `.lower_bound()` instead of `std::lower_bound()`**
 - `myMap.lower_bound(key)` is O(log N). `std::lower_bound(myMap.begin(), myMap.end(), key)` is technically O(N) for non-random-access iterators!