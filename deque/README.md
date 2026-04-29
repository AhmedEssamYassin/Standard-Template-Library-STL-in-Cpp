# C++ STL: `std::deque`

## Overview
`std::deque` (Double-Ended Queue) is a **dynamic container** in C++ STL that allows **fast insertions and deletions** from both ends. Unlike `vector`, it is **not stored in contiguous memory**, making mid-insertions/deletions less efficient.

## Properties of `std::deque`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Segmented Dynamic Array |
| **Iterator Support** | [x] Yes (Random Access Iterator) |
| **Random Access** | [x] Yes (Supports direct indexing) |
| **Allows Duplicates** | [x] Yes |
| **Sorting Order** | [ ] No (Requires manual sorting) |
| **Size** | Dynamic (Can grow/shrink at both ends) |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `push_front(value)` | Inserts `value` at the front | **O(1)** |
| `push_back(value)` | Inserts `value` at the back | **O(1)** |
| `pop_front()` | Removes the front element | **O(1)** |
| `pop_back()` | Removes the last element | **O(1)** |
| `front()` | Returns the first element | **O(1)** |
| `back()` | Returns the last element | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the deque is empty | **O(1)** |
| `at(index)` | Returns the element at `index` with bounds checking | **O(1)** |
| `operator[] (index)` | Returns the element at `index` (No bounds checking) | **O(1)** |
| `insert(pos, value)` | Inserts `value` at iterator `pos` | **O(N)** |
| `erase(pos)` | Removes the element at iterator `pos` | **O(N)** |
| `clear()` | Removes all elements | **O(N)** |

---

## When to Use `std::deque`?
| Scenario | Use `deque`? | Better Alternative |
|----------|--------------|-------------------|
| Frequent insert/delete at **front AND back** | [x] Yes | — |
| Need random access by index | [x] Yes | `vector` (if front operations aren't needed) |
| Elements must be contiguous in memory | [ ] No | `vector` |
| Frequent insert/delete in the middle | [ ] No | `list` |

---

## Common Pitfalls
1. **Iterator Invalidation on `insert()` / `erase()`**
 - Inserting or erasing in the middle of a `deque` **invalidates all iterators** and references.
 - Inserting at either end (via `push_front` or `push_back`) invalidates iterators, but **references/pointers remain valid**.
2. **Not entirely contiguous memory**
 - Unlike `std::vector`, `std::deque` allocates memory in chunks. Therefore, passing `&myDeque[0]` to a C-style API expecting a contiguous array will result in **Undefined Behavior**.
3. **Slightly slower than `vector`**
 - Because it uses a table of pointers to manage memory chunks, random access (`myDeque[i]`) requires two pointer dereferences, making it marginally slower than `vector`.

---

## Tips & Tricks
1. **Default container for `std::queue` and `std::stack`**
 - `deque` is the underlying container used when you create a `queue` or `stack`.
2. **Use it for sliding window algorithms**
 - `deque` is extremely useful for maintaining minimum/maximum values in a sliding window because you can pop from both ends efficiently.