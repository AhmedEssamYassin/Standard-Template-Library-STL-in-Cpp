# C++ STL: `std::queue`

## Overview
`std::queue` is a **FIFO (First-In-First-Out) container** in C++ STL that allows **insertion at the back** and **removal from the front**. It is implemented using **deque by default**, but can also be constructed using `list` or `vector`.

## Properties of `std::queue`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | `std::deque` (by default) |
| **Iterator Support** | [ ] No |
| **Random Access** | [ ] No |
| **Allows Duplicates** | [x] Yes |
| **Sorting Order** | [ ] No (Maintains insertion order) |
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

## When to Use `std::queue`?
| Scenario | Use `queue`? | Better Alternative |
|----------|--------------|-------------------|
| Need First-In, First-Out (FIFO) behavior | [x] Yes | — |
| Breadth-First Search (BFS) | [x] Yes | — |
| Scheduling tasks in order of arrival | [x] Yes | — |
| Need to iterate through the elements | [ ] No | `deque` or `list` |
| Need priority-based processing | [ ] No | `priority_queue` |

---

## Common Pitfalls
1. **Calling `pop()`, `front()`, or `back()` on an empty queue**
 - This is **Undefined Behavior** and will likely crash your program. Always check `if (!myQueue.empty())` before accessing or removing elements.
2. **No iteration**
 - You cannot use a `for` loop to iterate through a queue. If you need iteration, use `deque` directly.

---

## Tips & Tricks
1. **Changing the underlying container**
 - By default, `std::queue` uses a `std::deque`. You can make it use a `std::list` instead:
 `std::queue<int, std::list<int>> myQueue;`
 - *Note: You cannot use `std::vector` because it lacks a fast `pop_front()`.*
2. **Use `emplace()`**
 - Like other containers, `myQueue.emplace(args...)` constructs the element directly in place, which is faster than `push()` for complex objects.