# C++ STL: `unordered_map`

## Overview
`unordered_map` is an **associative container** in C++ STL that stores **key-value pairs** in an **unordered** manner using a **hash table**. It provides **average O(1) complexity** for insertion, deletion, and lookup operations.

## Properties of `unordered_map`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Hash Table |
| **Iterator Support** | ✓ Yes (Forward Iterator) |
| **Random Access** | ✗ No |
| **Allows Duplicates** | ✗ No (Unique Keys) |
| **Sorting Order** | ✗ No (Unordered) |
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

## When to Use `std::unordered_map`?
| Scenario | Use `unordered_map`? | Better Alternative |
|----------|----------------------|-------------------|
| Need key-value mapping with fast lookup | ✓ Yes | — |
| Order of elements doesn't matter | ✓ Yes | — |
| Need elements sorted by key | ✗ No | `map` |
| Frequent range queries | ✗ No | `map` |
| Security against Hash Collision attacks | ✗ No | `map` or use custom hash |

---

## Common Pitfalls
1. **Hash Collision Attacks (Codeforces / CP)**
 - The default `std::hash` is predictable. Malicious test cases can trigger O(N) lookup time, causing Time Limit Exceeded (TLE). Always use a **custom splitmix64 hash** for competitive programming.
2. **Iterators are not ordered**
 - Iterating over an `unordered_map` yields elements in a seemingly random order. Don't rely on insertion order.
3. **`operator[]` inserts default values**
 - Checking `if (myMap["key"])` inserts `"key"`. Use `find()` or `count()`.
4. **No `std::hash` for `std::pair` or `std::vector`**
 - You cannot use `unordered_map<pair<int,int>, int>` out of the box. You must provide a custom hash struct.

---

## Tips & Tricks
1. **Use `reserve()` to prevent rehashing**
 - If you know you will insert 10,000 elements, call `umap.reserve(10000)` first. This avoids expensive O(N) table rehashing as the map grows.
2. **Use `.contains()` (C++20)**
 - `if (umap.contains(key))` is cleaner than `if (umap.find(key) != umap.end())`.
3. **`max_load_factor`**
 - You can tweak the performance vs memory trade-off using `umap.max_load_factor(0.25)` to force rehashing sooner, keeping collision chains very short.