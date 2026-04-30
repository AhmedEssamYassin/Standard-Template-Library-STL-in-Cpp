# C++ STL: `std::list`

## Overview
`std::list` is a **doubly linked list** implementation in C++ STL that allows **fast insertions and deletions** at **any position**. Unlike `vector` and `deque`, it does **not support random access**.

## Properties of `std::list`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Doubly Linked List |
| **Iterator Support** | ✓ Yes (Bidirectional Iterator) |
| **Random Access** | ✗ No |
| **Allows Duplicates** | ✓ Yes |
| **Sorting Order** | ✗ No (Requires manual sorting) |
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
| `splice(pos, other_list)`| Transfers elements from `other_list` into this list | **O(1)** |

---

## When to Use `std::list`?
| Scenario | Use `list`? | Better Alternative |
|----------|-------------|-------------------|
| Frequent insert/delete in the **middle** | ✓ Yes | — |
| Need to transfer elements between containers fast | ✓ Yes | (Using `splice`) |
| Need random access by index (`list[i]`) | ✗ No | `vector` or `deque` |
| High performance / Cache friendliness required | ✗ No | `vector` |

---

## Common Pitfalls
1. **Cache unfriendliness**
 - Elements in a `std::list` are scattered across the heap (not contiguous). This causes a lot of cache misses, making `std::list` significantly slower than `std::vector` for iteration, even if Big-O time is theoretically the same.
2. **No random access**
 - You cannot do `myList[5]`. You must use iterators and advance them using `std::advance(it, 5)`, which takes **O(N)** time.
3. **Memory overhead**
 - Each element stores two extra pointers (next and prev), adding significant overhead for small data types like `int` or `char`.

---

## Tips & Tricks
1. **The power of `splice()`**
 - `splice` is the superpower of `std::list`. It transfers elements from one list to another by simply repointing the pointers, meaning it takes **O(1)** time without copying the data!
2. **Use `.remove_if()` with a lambda**
 - To remove elements based on a condition, use `myList.remove_if([](int x){ return x % 2 == 0; });` instead of writing a manual loop with `erase`.
3. **Use `.sort()` instead of `std::sort()`**
 - `std::sort` requires random-access iterators and will not compile with `std::list`. You must use the member function `myList.sort()`.