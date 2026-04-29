# C++ STL: `std::array`

## Overview
`std::array` is a **fixed-size container** in C++ STL that represents an array with **static storage duration**. Unlike `vector`, the size of `std::array` must be **known at compile-time**.

## Properties of `std::array`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Fixed-size array |
| **Iterator Support** | [x] Yes (Random Access Iterator) |
| **Random Access** | [x] Yes (Supports direct indexing) |
| **Allows Duplicates** | [x] Yes |
| **Sorting Order** | [ ] No (Requires manual sorting) |
| **Size** | Fixed at compile-time |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `begin()` | Returns an iterator to the first element | **O(1)** |
| `end()` | Returns an iterator past the last element | **O(1)** |
| `rbegin()` | Returns a reverse iterator to the last element | **O(1)** |
| `rend()` | Returns a reverse iterator before the first element | **O(1)** |
| `front()` | Returns the first element | **O(1)** |
| `back()` | Returns the last element | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the array is empty | **O(1)** |
| `at(index)` | Returns the element at `index` with bounds checking | **O(1)** |
| `operator[] (index)` | Returns the element at `index` (No bounds checking) | **O(1)** |
| `swap(other)` | Swaps contents with another array | **O(N)** |
| `fill(value)` | Fills the array with a specific value | **O(N)** |

---