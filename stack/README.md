# C++ STL: `std::stack`

## Overview
`std::stack` is a **Last-In-First-Out (LIFO)** container in C++ STL that allows **push and pop operations only at one end** (the top). It is implemented using **deque by default**, but can also be constructed using `list` or `vector`.

## Properties of `std::stack`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | `std::deque` (by default) |
| **Iterator Support** | [ ] No |
| **Random Access** | [ ] No |
| **Allows Duplicates** | [x] Yes |
| **Sorting Order** | [ ] No (Maintains insertion order) |
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

## When to Use `std::stack`?
| Scenario | Use `stack`? | Better Alternative |
|----------|--------------|-------------------|
| Need Last-In, First-Out (LIFO) behavior | [x] Yes | — |
| Depth-First Search (DFS) | [x] Yes | (or use recursion) |
| Undo/Redo functionality | [x] Yes | — |
| Need to iterate through the elements | [ ] No | `vector` or `deque` |

---

## Common Pitfalls
1. **Calling `pop()` or `top()` on an empty stack**
 - This is **Undefined Behavior** and will likely crash your program. Always check `if (!myStack.empty())` before accessing or removing the top element.
2. **No iteration**
 - You cannot use a `for` loop to iterate through a stack. If you need iteration, use the underlying container (like `vector` or `deque`) directly instead of the `stack` adapter.

---

## Tips & Tricks
1. **Changing the underlying container**
 - By default, `std::stack` uses a `std::deque`. You can make it use a `vector` instead if you want strictly contiguous memory and slightly faster operations:
 `std::stack<int, std::vector<int>> myStack;`
2. **Use `emplace()`**
 - Like other containers, `myStack.emplace(args...)` constructs the element directly in place, which is faster than `push()` for complex objects.