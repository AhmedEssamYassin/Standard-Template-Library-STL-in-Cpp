# C++ STL: `std::queue`

## 📌 Overview
`std::queue` is a **FIFO (First-In-First-Out) container** in C++ STL that allows **insertion at the back** and **removal from the front**. It is implemented using **deque by default**, but can also be constructed using `list` or `vector`.

## 🛠️ Properties of `std::queue`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | `std::deque` (by default) |
| **Iterator Support** | ❌ No |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ✅ Yes |
| **Sorting Order** | ❌ No (Maintains insertion order) |
| **Size** | Dynamic (Can grow/shrink at both ends) |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `push(value)` | Inserts `value` at the back | **O(1)** |
| `pop()` | Removes the front element | **O(1)** |
| `front()` | Returns the front element | **O(1)** |
| `back()` | Returns the last element | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the queue is empty | **O(1)** |

---