# C++ STL: `std::multiset`

## 📌 Overview
`std::multiset` is an **ordered associative container** in C++ STL that stores **multiple occurrences** of elements in **sorted order**. It is implemented using a **Red-Black Tree (self-balancing BST)** and provides **O(log N) complexity** for insertion, deletion, and lookup operations.

## 🛠️ Properties of `std::multiset`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Red-Black Tree (Self-Balancing BST) |
| **Iterator Support** | ✅ Yes (Bidirectional Iterator) |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ✅ Yes (Stores multiple identical elements) |
| **Sorting Order** | ✅ Yes (Elements in sorted order) |
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