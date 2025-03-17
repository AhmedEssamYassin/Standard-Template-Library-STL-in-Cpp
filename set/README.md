# C++ STL: `std::set`

## 📌 Overview
`std::set` is an **ordered associative container** in C++ STL that stores **unique elements in sorted order**. It is implemented using a **Red-Black Tree (self-balancing BST)** and provides **O(log N) complexity** for insertion, deletion, and lookup operations.

## 🛠️ Properties of `std::set`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Red-Black Tree (Self-Balancing BST) |
| **Iterator Support** | ✅ Yes (Bidirectional Iterator) |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ❌ No (Only unique elements) |
| **Sorting Order** | ✅ Yes (Elements in sorted order) |
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