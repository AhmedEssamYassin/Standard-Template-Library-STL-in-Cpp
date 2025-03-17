# C++ STL: `unordered_map`

## 📌 Overview
`unordered_map` is an **associative container** in C++ STL that stores **key-value pairs** in an **unordered** manner using a **hash table**. It provides **average O(1) complexity** for insertion, deletion, and lookup operations.

## 🛠️ Properties of `unordered_map`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Hash Table |
| **Iterator Support** | ✅ Yes (Forward Iterator) |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ❌ No (Unique Keys) |
| **Sorting Order** | ❌ No (Unordered) |
| **Average Time Complexity** | O(1) for Insert, Delete, Search |
| **Worst-case Time Complexity** | O(N) (Due to hash collisions) |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `insert({key, value})` | Inserts a key-value pair | **O(1)** (amortized) |
| `erase(key)` | Removes the element with the given key | **O(1)** (amortized) |
| `find(key)` | Returns an iterator to the element if found, else `end()` | **O(1)** (amortized) |
| `count(key)` | Returns 1 if key exists, otherwise 0 | **O(1)** |
| `at(key)` | Returns reference to the mapped value | **O(1)** |
| `operator[] (key)` | Inserts if key doesn't exist, else returns reference | **O(1)** |
| `begin(), end()` | Iterators to traverse the map | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the map is empty | **O(1)** |
| `clear()` | Removes all elements | **O(N)** |
| `bucket_count()` | Returns number of buckets in hash table | **O(1)** |
| `load_factor()` | Returns the load factor (size / bucket_count) | **O(1)** |
| `rehash(n)` | Resizes hash table to have at least `n` buckets | **O(N)** |
---