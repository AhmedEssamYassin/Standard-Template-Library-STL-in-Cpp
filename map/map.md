# C++ STL: `std::map`

## 📌 Overview
`std::map` is an **ordered associative container** in C++ STL that stores **key-value pairs** in **sorted order** using a **Red-Black Tree (self-balancing BST)**. It provides **O(log N) complexity** for insertion, deletion, and lookup operations.

## 🛠️ Properties of `std::map`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Red-Black Tree (Self-Balancing BST) |
| **Iterator Support** | ✅ Yes (Bidirectional Iterator) |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ❌ No (Unique Keys) |
| **Sorting Order** | ✅ Yes (Keys in sorted order) |
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