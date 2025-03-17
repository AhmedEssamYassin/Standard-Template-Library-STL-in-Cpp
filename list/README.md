# C++ STL: `std::list`

## 📌 Overview
`std::list` is a **doubly linked list** implementation in C++ STL that allows **fast insertions and deletions** at **any position**. Unlike `vector` and `deque`, it does **not support random access**.

## 🛠️ Properties of `std::list`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Doubly Linked List |
| **Iterator Support** | ✅ Yes (Bidirectional Iterator) |
| **Random Access** | ❌ No |
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
| `empty()` | Checks if the list is empty | **O(1)** |
| `insert(pos, value)` | Inserts `value` at iterator `pos` | **O(N)**|
| `erase(pos)` | Removes the element at iterator `pos` | **O(N)**|
| `remove(value)` | Removes all occurrences of `value` | **O(N)** |
| `clear()` | Removes all elements | **O(N)** |
| `sort()` | Sorts the list in ascending order | **O(N log N)** |
| `reverse()` | Reverses the order of elements | **O(N)** |
| `merge(other_list)` | Merges two sorted lists | **O(N)** |
| `unique()` | Removes consecutive duplicate elements | **O(N)** |

---