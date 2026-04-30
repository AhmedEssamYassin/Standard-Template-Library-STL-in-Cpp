# C++ STL: `std::vector`

## Overview
`std::vector` is a **dynamic array container** in C++ STL that provides **fast random access**, **automatic resizing**, and **efficient insertion/removal at the end**. It is implemented using **a dynamically allocated array**.

## Properties of `std::vector`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Dynamic Array |
| **Iterator Support** | ✓ Yes (Random Access Iterator) |
| **Random Access** | ✓ Yes (`O(1)`) |
| **Allows Duplicates** | ✓ Yes |
| **Sorting Order** | ✗ No (Requires manual sorting) |
| **Resizing** | ✓ Yes (Automatic growth) |
| **Amortized Insertion at End** | **O(1)** |

---

## 📝 Member Functions & Complexity

### **Basic Operations**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `size()` | Returns number of elements | **O(1)** |
| `capacity()` | Returns current allocated memory size | **O(1)** |
| `empty()` | Checks if vector is empty | **O(1)** |
| `clear()` | Deletes all elements | **O(N)** |
| `front()` | Returns first element | **O(1)** |
| `back()` | Returns last element | **O(1)** |
| `at(index)` | Returns element at `index` (Bounds checked) | **O(1)** |
| `operator[] (index)` | Returns element at `index` (No bounds check) | **O(1)** |

### **Modification Functions**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `push_back(value)` | Appends `value` at the end | **O(1) (Amortized)** |
| `pop_back()` | Removes last element | **O(1)** |
| `insert(pos, value)` | Inserts `value` at `pos` | **O(N)** |
| `erase(pos)` | Removes element at `pos` | **O(N)** |
| `erase(first, last)` | Removes range `[first, last)` | **O(N)** |
| `resize(n)` | Changes size to `n` (default initializes extra space) | **O(N)** |
| `reserve(n)` | Allocates memory for at least `n` elements without changing size | **O(N)** |
| `swap(vec2)` | Swaps contents with `vec2` | **O(1)** |

---

## When to Use `std::vector`?
| Scenario | Use `vector`? | Better Alternative |
|----------|---------------|-------------------|
| Need random access by index | ✓ Yes | — |
| Frequent insert/delete at front | ✗ No | `deque` or `list` |
| Frequent insert/delete in middle | ✗ No | `list` |
| Need sorted unique elements | ✗ No | `set` |
| Need contiguous memory (C API interop) | ✓ Yes | — |
| Size known at compile time | Maybe | `array` (zero overhead) |

---

## Common Pitfalls
1. **`reserve()` vs `resize()` Confusion**
 - `reserve(n)` allocates memory (capacity changes) but doesn't create elements (size is still 0).
 - `resize(n)` actually creates `n` elements (size changes). Accessing `vec[0]` after `reserve` without `push_back` is **Undefined Behavior**.
2. **`vector<bool>` is NOT a true vector**
 - It is specially optimized to use 1 bit per element, meaning you **cannot** take a reference to a boolean element (`bool& b = vec[0]` will fail). If you need a normal boolean array, use `vector<char>` or `deque<bool>`.
3. **Iterator Invalidation**
 - Whenever `vector` resizes internally (exceeds capacity), **all iterators and pointers** to its elements become invalid.

---

## Tips & Tricks
1. **Pre-allocate memory**
 - If you know you will push 10,000 elements, call `vec.reserve(10000)` beforehand. This avoids expensive reallocations and copies as the vector grows.
2. **Use `emplace_back()` instead of `push_back()`**
 - For complex objects (like pairs or structs), `emplace_back` constructs the object directly in place, avoiding temporary copies.
3. **The Erase-Remove Idiom**
 - To remove all occurrences of a value, use `vec.erase(remove(vec.begin(), vec.end(), value), vec.end());`. This is the standard O(N) way to filter a vector.
4. **Clear Memory Completely**
 - `vec.clear()` changes size to 0 but does **not** free memory (capacity remains). To actually free the memory, use the swap trick: `vector<int>().swap(vec);` (or `vec.shrink_to_fit()` in C++11).