# C++ STL: `Iterators`

## Overview
Iterators are objects that point to elements inside an STL container, acting similarly to pointers. They act as the "bridge" between generic algorithms (like `std::sort` or `std::find`) and the containers (like `std::vector` or `std::map`).

## Iterator Categories
STL iterators fall into five categories, each supporting different operations. A container provides iterators of a specific category based on its underlying data structure.

| Category | Supported Operations | Containers |
|----------|----------------------|------------|
| **Input Iterator** | Read-only forward (`++`, `*it`) | `istream_iterator` |
| **Output Iterator** | Write-only forward (`++`, `*it = x`) | `ostream_iterator`, `inserter` |
| **Forward Iterator** | Read/Write forward (`++`, `*it`) | `forward_list`, `unordered_set/map` |
| **Bidirectional Iterator** | Forward and Backward (`++`, `--`) | `list`, `set`, `map` |
| **Random Access Iterator** | Jump arbitrarily (`it + n`, `it[n]`) | `vector`, `deque`, `array`, `string` |

---

## Important Iterator Functions
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `std::advance(it, n)` | Moves iterator forward by `n` | `O(1)` for Random Access, `O(N)` otherwise |
| `std::distance(start, end)` | Returns the number of elements between two iterators | `O(1)` for Random Access, `O(N)` otherwise |
| `std::next(it, n)` | Returns a new iterator `n` steps forward (doesn't modify `it`) | `O(1)` or `O(N)` |
| `std::prev(it, n)` | Returns a new iterator `n` steps backward | `O(1)` or `O(N)` |

---

## Iterator Invalidation (Common Pitfall)
When you modify a container, iterators pointing to its elements might become invalid (pointing to freed memory), leading to **Undefined Behavior**.

- **`std::vector` / `std::string`**:
 - `insert()` / `push_back()`: Invalidates ALL iterators if a reallocation occurs.
 - `erase()`: Invalidates iterators at or after the erased point.
- **`std::deque`**:
 - `insert()` / `erase()` in the middle: Invalidates ALL iterators.
- **`std::list` / `std::set` / `std::map`**:
 - `insert()`: NO iterators invalidated.
 - `erase()`: Only the iterator pointing to the erased element is invalidated.

---

## Iterator Adapters
STL provides special iterators that do work for you:
1. `std::back_inserter(container)`: Automatically calls `push_back()` when you write to it.
2. `std::front_inserter(container)`: Automatically calls `push_front()`.
3. `std::inserter(container, it)`: Automatically calls `insert()`.
