# C++ STL: `std::priority_queue`

## Overview
`std::priority_queue` is a **heap-based container** in C++ STL that provides **constant-time retrieval of the largest (or smallest) element**. 
- Implemented as a **Binary Heap** (Max Heap by default). 
- Elements are **sorted internally** based on priority. 
- Provides **O(log N) complexity** for insertions and deletions. 

---

## Properties of `std::priority_queue`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Binary Heap |
| **Iterator Support** | [ ] No (Only top access) |
| **Random Access** | [ ] No |
| **Allows Duplicates** | [x] Yes |
| **Maintains Order** | [x] Yes (Heap Order) |
| **Best for** | Dynamic sorting, fetching largest/smallest element |
| **Insertion (`push`)** | **O(log N)** |
| **Deletion (`pop`)** | **O(log N)** |
| **Top Element Access (`top`)** | **O(1)** |

---

## 📝 Member Functions & Complexity

### **Basic Operations**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `size()` | Returns number of elements | **O(1)** |
| `empty()` | Checks if priority queue is empty | **O(1)** |
| `top()` | Returns the highest priority element | **O(1)** |

### **Modification Functions**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `push(value)` | Inserts `value` into the priority queue | **O(log N)** |
| `pop()` | Removes the top element | **O(log N)** |
| `swap(pq2)` | Swaps contents with `pq2` | **O(1)** |

---

## **Max Heap (Default)**
A **Max Heap** stores elements in **descending order**, with the **largest** element at the top.

```cpp
priority_queue<int> maxHeap;
```
---
## **Min Heap**
A **Min Heap** stores elements in **ascending order**, with the **smallest** element at the top.

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

---

## When to Use `std::priority_queue`?
| Scenario | Use `priority_queue`? | Better Alternative |
|----------|-----------------------|-------------------|
| Need constant access to the largest/smallest element | [x] Yes | — |
| Need to find K-th largest/smallest quickly | [x] Yes | `std::nth_element` (if offline) |
| Need to iterate through all sorted elements | [ ] No | `set` or `vector` + `sort()` |
| Need to search or delete arbitrary elements | [ ] No | `set` |
| Processing events/tasks by priority | [x] Yes | — |

---

## Common Pitfalls
1. **No iteration allowed**
 - You **cannot** loop through a priority queue. You can only view the `top()` and `pop()` it. If you need to iterate, use `std::set` or a sorted `std::vector`.
2. **Comparator Logic is REVERSED**
 - This is the biggest pitfall in STL. Passing `std::less<T>` (which means A < B) creates a **MAX-HEAP** (largest on top). Passing `std::greater<T>` creates a **MIN-HEAP**. This feels backwards compared to `sort()` or `set`.
3. **Strict Weak Ordering Requirement**
 - Custom comparators must obey strict weak ordering (just like `set` and `map`).

---

## Tips & Tricks
1. **Use `std::make_heap` for O(N) construction**
 - If you already have a `std::vector` of elements, pushing them one by one takes O(N log N). Instead, use `std::make_heap(vec.begin(), vec.end())` to build the heap in **O(N)** time, and then wrap it in a `priority_queue` (or just use heap algorithms).
2. **Use Lambda Comparators (C++11+)**
 - Instead of writing a struct, use a lambda:
 ```cpp
 auto comp = [](int a, int b) { return a > b; };
 priority_queue<int, vector<int>, decltype(comp)> pq(comp);
 ```
3. **Store pairs/tuples**
 - By default, `priority_queue<pair<int, int>>` sorts by `.first` then `.second`. This is extremely useful for algorithms like Dijkstra's.