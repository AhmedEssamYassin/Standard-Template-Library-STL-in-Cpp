# C++ STL: `<bitset>`

## Overview
`std::bitset` is a highly optimized container for managing a fixed-size sequence of bits. It provides **O(N/64)** operations for bitwise math and boolean arrays, making it dramatically faster and more memory-efficient than `std::vector<bool>`.

## Properties of `std::bitset`
| Feature | Details |
|-------------------|---------|
| **Underlying Data Structure** | Fixed-size array of integers (typically 64-bit) |
| **Iterator Support** | [ ] No |
| **Random Access** | [x] Yes (`O(1)`) |
| **Dynamic Resizing**| [ ] No (Size must be known at compile time) |
| **Time Complexity** | Most bitwise operations are `O(N / 64)` |

---

## When to Use `std::bitset`?
| Scenario | Use `bitset`? | Better Alternative |
|----------|---------------|-------------------|
| Fixed-size array of booleans | [x] Yes | — |
| Need ultra-fast bitwise AND/OR/XOR | [x] Yes | — |
| Dynamic size known only at runtime | [ ] No | `vector<bool>` or `deque<bool>` |

---

## 📝 Member Functions
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `count()` | Returns the number of bits set to `1` | **O(N / 64)** |
| `size()` | Returns the total number of bits | **O(1)** |
| `test(pos)` | Returns `true` if bit at `pos` is `1` (bounds checked) | **O(1)** |
| `any()` | Returns `true` if at least one bit is `1` | **O(N / 64)** |
| `none()` | Returns `true` if all bits are `0` | **O(N / 64)** |
| `all()` | Returns `true` if all bits are `1` (C++11) | **O(N / 64)** |
| `set()` | Sets all bits to `1` | **O(N / 64)** |
| `reset()` | Sets all bits to `0` | **O(N / 64)** |
| `flip()` | Flips all bits (`0` -> `1`, `1` -> `0`) | **O(N / 64)** |
| `to_string()` | Converts to a `std::string` of '0's and '1's | **O(N)** |
| `to_ullong()` | Converts to `unsigned long long` | **O(1)** |
