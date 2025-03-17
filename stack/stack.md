# C++ STL: `std::stack`

## 📌 Overview
`std::stack` is a **Last-In-First-Out (LIFO)** container in C++ STL that allows **push and pop operations only at one end** (the top). It is implemented using **deque by default**, but can also be constructed using `list` or `vector`.

## 🛠️ Properties of `std::stack`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | `std::deque` (by default) |
| **Iterator Support** | ❌ No |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ✅ Yes |
| **Sorting Order** | ❌ No (Maintains insertion order) |
| **Size** | Dynamic (Can grow/shrink at one end) |

---

## 📝 Member Functions & Complexity
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `push(value)` | Inserts `value` at the top | **O(1)** |
| `pop()` | Removes the top element | **O(1)** |
| `top()` | Returns the top element | **O(1)** |
| `size()` | Returns the number of elements | **O(1)** |
| `empty()` | Checks if the stack is empty | **O(1)** |

---