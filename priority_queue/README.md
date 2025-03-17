# C++ STL: `std::priority_queue`

## 📌 Overview
`std::priority_queue` is a **heap-based container** in C++ STL that provides **constant-time retrieval of the largest (or smallest) element**.  
- Implemented as a **Binary Heap** (Max Heap by default).  
- Elements are **sorted internally** based on priority.  
- Provides **O(log N) complexity** for insertions and deletions.  

---

## 🛠️ Properties of `std::priority_queue`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Binary Heap |
| **Iterator Support** | ❌ No (Only top access) |
| **Random Access** | ❌ No |
| **Allows Duplicates** | ✅ Yes |
| **Maintains Order** | ✅ Yes (Heap Order) |
| **Best for** | Dynamic sorting, fetching largest/smallest element |
| **Insertion (`push`)** | **O(log N)** |
| **Deletion (`pop`)** | **O(log N)** |
| **Top Element Access (`top`)** | **O(1)** |

---

## 📝 Member Functions & Complexity

### 📌 **Basic Operations**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `size()` | Returns number of elements | **O(1)** |
| `empty()` | Checks if priority queue is empty | **O(1)** |
| `top()` | Returns the highest priority element | **O(1)** |

### 📌 **Modification Functions**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `push(value)` | Inserts `value` into the priority queue | **O(log N)** |
| `pop()` | Removes the top element | **O(log N)** |
| `swap(pq2)` | Swaps contents with `pq2` | **O(1)** |

---

## 📌 **Max Heap (Default)**
A **Max Heap** stores elements in **descending order**, with the **largest** element at the top.

```cpp
priority_queue<int> maxHeap;
```
---
## 📌 **Min Heap**
A **Min Heap** stores elements in **ascending order**, with the **smallest** element at the top.

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```