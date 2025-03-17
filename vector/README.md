# C++ STL: `std::vector`

## 📌 Overview
`std::vector` is a **dynamic array container** in C++ STL that provides **fast random access**, **automatic resizing**, and **efficient insertion/removal at the end**. It is implemented using **a dynamically allocated array**.

## 🛠️ Properties of `std::vector`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Dynamic Array |
| **Iterator Support** | ✅ Yes (Random Access Iterator) |
| **Random Access** | ✅ Yes (`O(1)`) |
| **Allows Duplicates** | ✅ Yes |
| **Sorting Order** | ❌ No (Requires manual sorting) |
| **Resizing** | ✅ Yes (Automatic growth) |
| **Amortized Insertion at End** | **O(1)** |

---

## 📝 Member Functions & Complexity

### 📌 **Basic Operations**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `size()` | Returns number of elements | **O(1)** |
| `capacity()` | Returns current allocated memory size | **O(1)** |
| `empty()` | Checks if vector is empty | **O(1)** |
| `clear()` | Deletes all elements | **O(N)** |
| `front()` | Returns first element | **O(1)** |
| `back()` | Returns last element | **O(1)** |
| `at(index)` | Returns element at `index` (Bounds checked) | **O(1)** |
| `operator[] (index)` | Returns element at `index` (No bounds check) | **O(1)** |

### 📌 **Modification Functions**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `push_back(value)` | Appends `value` at the end | **O(1) (Amortized)** |
| `pop_back()` | Removes last element | **O(1)** |
| `insert(pos, value)` | Inserts `value` at `pos` | **O(N)** |
| `erase(pos)` | Removes element at `pos` | **O(N)** |
| `erase(first, last)` | Removes range `[first, last)` | **O(N)** |
| `resize(n)` | Changes size to `n` (default initializes extra space) | **O(N)** |
| `swap(vec2)` | Swaps contents with `vec2` | **O(1)** |

---