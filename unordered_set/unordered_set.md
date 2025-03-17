# C++ STL: `std::unordered_set`

## 📌 Overview
`std::unordered_set` is an **unordered associative container** in C++ STL that stores **unique elements** in an **unordered manner** using a **hash table**. It provides **O(1) average-time complexity** for insertion, deletion, and lookup operations.

## 🛠️ Properties of `std::unordered_set`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Hash Table |
| **Iterator Support** | ✅ Yes (Forward Iterator) |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ❌ No (Only unique elements) |
| **Sorting Order** | ❌ No (Unordered) |
| **Average Time Complexity** | O(1) for Insert, Delete, Search |
| **Worst-case Time Complexity** | O(N) (Due to hash collisions) |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `insert(value)` | Inserts a value (Unique elements only) | **O(1) (Amortized)** |
| `erase(value)` | Removes the element with the given value | **O(1) (Amortized)** |
| `find(value)` | Returns an iterator to the value if found, else `end()` | **O(1) (Amortized)** |
| `count(value)` | Returns 1 if value exists, otherwise 0 | **O(1)** |
| `begin(), end()` | Iterators to traverse the set | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the set is empty | **O(1)** |
| `clear()` | Removes all elements | **O(N)** |
| `bucket_count()` | Returns number of buckets in hash table | **O(1)** |
| `load_factor()` | Returns the load factor (size / bucket_count) | **O(1)** |
| `rehash(n)` | Resizes hash table to have at least `n` buckets | **O(N)** |

---