# C++ STL: `std::multimap`

## 📌 Overview
`std::multimap` is an **ordered associative container** in C++ STL that stores **key-value pairs** in **sorted order**, allowing **duplicate keys**. It is implemented using a **Red-Black Tree (self-balancing BST)** and provides **O(log N) complexity** for insertion, deletion, and lookup operations.

## 🛠️ Properties of `std::multimap`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Red-Black Tree (Self-Balancing BST) |
| **Iterator Support** | ✅ Yes (Bidirectional Iterator) |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ✅ Yes (Multiple values per key) |
| **Sorting Order** | ✅ Yes (Keys in sorted order) |
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