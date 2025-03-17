# Standard Template Library (STL) in C++
This repository provides a comprehensive explanation and examples for various **STL containers** in C++. Each container includes details on **iterators, random access support, underlying data structure, and sorting order**.

## 📌 STL Containers Overview

| Container | Data Structure | Supports Iterators | Random Access | Allows Duplicates | Sorted |
|-----------|---------------|--------------------|---------------|------------------|--------|
| `array` | Fixed-size array | ✅ Yes | ✅ Yes | ✅ Yes | ❌ No |
| `vector` | Dynamic array | ✅ Yes | ✅ Yes | ✅ Yes | ❌ No |
| `deque` | Doubly-ended queue | ✅ Yes | ✅ Yes | ✅ Yes | ❌ No |
| `list` | Doubly linked list | ✅ Yes (Bidirectional) | ❌ No | ✅ Yes | ❌ No |
| `stack` | LIFO structure (uses `deque` or `vector`) | ❌ No (only top) | ❌ No | ✅ Yes | ❌ No |
| `queue` | FIFO structure (uses `deque` or `list`) | ❌ No (only front & back) | ❌ No | ✅ Yes | ❌ No |
| `priority_queue` | Heap (binary heap by default) | ❌ No (only top) | ❌ No | ✅ Yes | ✅ Yes (Max Heap by default) |
| `set` | Balanced BST (Red-Black Tree) | ✅ Yes | ❌ No | ❌ No (unique values) | ✅ Yes |
| `multiset` | Balanced BST (Red-Black Tree) | ✅ Yes | ❌ No | ✅ Yes | ✅ Yes |
| `unordered_set` | Hash Table | ✅ Yes | ❌ No | ❌ No (unique values) | ❌ No |
| `map` | Balanced BST (Red-Black Tree) | ✅ Yes | ❌ No | ❌ No (unique keys) | ✅ Yes (by key) |
| `unordered_map` | Hash Table | ✅ Yes | ❌ No | ❌ No (unique keys) | ❌ No |
| `pair` | Simple data container | ✅ Yes | ❌ No | ✅ Yes | ❌ No |
| `tuple` | Fixed-size heterogeneous container | ✅ Yes | ❌ No | ✅ Yes | ❌ No |

---

## 📂 STL Topics Covered

### ✅ Sequential Containers
- `array`
- `vector`
- `deque`
- `list`

### ✅ Associative Containers
- `set`, `multiset`
- `map`, `unordered_map`
- `unordered_set`

### ✅ Container Adapters
- `stack`
- `queue`
- `priority_queue`

### ✅ Utility Components
- `pair`
- `tuple`

---

## 📖 What’s Inside?
Each STL container has its own file with:
- **Definition & Usage**
- **All Member Functions**
- **Time Complexity**
- **Examples & Edge Cases**
- **Sorting, Searching, & Modifications**

---

## How to Run?
Clone this repository and compile any STL example using:

```sh
g++ -O3 -o filename filename.cpp
```
Then,
```
./filename
```

