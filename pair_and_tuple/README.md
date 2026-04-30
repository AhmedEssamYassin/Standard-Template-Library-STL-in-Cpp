# C++ STL: `std::pair` & `std::tuple`

## Overview
`std::pair` and `std::tuple` are **utility classes** in C++ STL that allow storing multiple values in a **single object**.

- `std::pair` – Stores **two values**.
- `std::tuple` – Stores **multiple values** (more than two).

## Properties of `std::pair` & `std::tuple`
| Feature | `std::pair` | `std::tuple` |
|-------------------|------------|-------------|
| **Stores Multiple Values** | ✓ (Two values) | ✓ (Multiple values) |
| **Fixed Size** | ✓ Yes | ✓ Yes |
| **Supports Different Data Types** | ✓ Yes | ✓ Yes |
| **Sorting Support** | ✓ Yes (Lexicographical order) | ✗ No (Requires manual sorting) |
| **Random Access** | ✗ No | ✗ No |

---

## 📝 Member Functions & Complexity

### `std::pair` Functions:
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `pair<T1, T2> p(a, b)` | Creates a pair `(a, b)` | **O(1)** |
| `make_pair(a, b)` | Creates a pair `(a, b)` | **O(1)** |
| `p.first` | Accesses the first element | **O(1)** |
| `p.second` | Accesses the second element | **O(1)** |
| `tie(a, b) = p` | Unpacks a pair into variables | **O(1)** |
| `swap(p1, p2)` | Swaps contents of two pairs | **O(1)** |

### `std::tuple` Functions:
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `tuple<T1, T2, T3> t(a, b, c)` | Creates a tuple `(a, b, c)` | **O(1)** |
| `make_tuple(a, b, c)` | Creates a tuple `(a, b, c)` | **O(1)** |
| `get<i>(t)` | Accesses the `i-th` element of tuple `t` | **O(1)** |
| `tie(a, b, c) = t` | Unpacks a tuple into variables | **O(1)** |
| `swap(t1, t2)` | Swaps contents of two tuples | **O(1)** |

---