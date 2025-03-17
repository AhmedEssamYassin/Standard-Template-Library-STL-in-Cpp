# C++ STL: `std::deque`

## 📌 Overview
`std::deque` (Double-Ended Queue) is a **dynamic container** in C++ STL that allows **fast insertions and deletions** from both ends. Unlike `vector`, it is **not stored in contiguous memory**, making mid-insertions/deletions less efficient.

## 🛠️ Properties of `std::deque`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Segmented Dynamic Array |
| **Iterator Support** | ✅ Yes (Random Access Iterator) |
| **Random Access** | ✅ Yes (Supports direct indexing) |
| **Allows Duplicates** | ✅ Yes |
| **Sorting Order** | ❌ No (Requires manual sorting) |
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