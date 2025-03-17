# C++ STL: `std::string` & C-Style Strings

## 📌 Overview
In C++, we have two main ways to handle strings:
- **C-Style Strings (`char[]`)**: Traditional character arrays with manual memory management.
- **C++ String Class (`std::string`)**: Modern, dynamic, and safer alternative.

---

# 📌 **Part 1: C-Style Strings (`char[]`)**
### ✅ **Overview**
C-style strings are **arrays of characters** ending with a **null terminator (`'\0'`)**.

## 🛠️ Properties of C-Style Strings
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Fixed-size `char[]` |
| **Requires Null Terminator** | ✅ Yes (`'\0'`) |
| **Random Access** | ✅ Yes (Supports indexing) |
| **Allows Duplicates** | ✅ Yes |
| **Sorting Order** | ❌ No (Requires manual sorting) |
| **Memory Management** | ❌ Manual (`new[]`, `delete[]`) |
| **Mutable** | ✅ Yes (Can modify characters) |
| **Size** | Fixed (constant/ known at compile-time) |
---

## 📝 C-Style String Functions (from `<cstring>`)
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `strlen(s)` | Returns the length (excluding null terminator) | **O(N)** |
| `strcpy(dest, src)` | Copies `src` into `dest` (must have enough space) | **O(N)** |
| `strncpy(dest, src, n)` | Copies first `n` characters | **O(N)** |
| `strcat(dest, src)` | Appends `src` to `dest` (must have enough space) | **O(N)** |
| `strcmp(s1, s2)` | Compares two strings lexicographically | **O(N)** |
| `strchr(s, ch)` | Finds first occurrence of `ch` in `s` | **O(N)** |
| `strtok(s, delim)` | Tokenizes string using delimiters | **O(N)** |

---
# 📌 **Part 2: STL: `std::string` &**

## 📌 Overview
`std::string` is a **dynamic character sequence container** in C++ STL that provides **built-in functions for manipulation** without worrying about memory management. Unlike **C-style strings (`char[]`)**, `std::string` is **safe, efficient, and flexible**.

## 🛠️ Properties of `std::string`
| Feature            | Details |
|-------------------|---------|
| **Underlying Data Structure** | Dynamic Character Array |
| **Iterator Support** | ✅ Yes (Random Access Iterator) |
| **Random Access** | ✅ Yes (Supports direct indexing) |
| **Allows Duplicates** | ✅ Yes |
| **Sorting Order** | ❌ No (Requires manual sorting) |
| **Size** | Dynamic (Can grow/shrink) |

---

## 📝 Member Functions & Complexity

### 📌 **Basic Operations**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `size()` / `length()` | Returns number of characters | **O(1)** |
| `empty()` | Checks if string is empty | **O(1)** |
| `clear()` | Deletes all characters | **O(1)** |
| `front()` | Returns first character | **O(1)** |
| `back()` | Returns last character | **O(1)** |
| `at(index)` | Returns character at `index` (Bounds checked) | **O(1)** |
| `operator[] (index)` | Returns character at `index` (No bounds check) | **O(1)** |

### 📌 **Modification Functions**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `push_back(char)` | Appends character to end | **O(1)** |
| `pop_back()` | Removes last character | **O(1)** |
| `append(str)` | Appends another string | **O(N)** |
| `assign(str)` | Assigns new string | **O(N)** |
| `insert(pos, str)` | Inserts `str` at position `pos` | **O(N)** |
| `replace(pos, len, str)` | Replaces substring with `str` | **O(N)** |
| `erase(pos, len)` | Removes substring from position `pos` | **O(N)** |
| `swap(str2)` | Swaps values with `str2` | **O(1)** |

### 📌 **Searching Functions**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `find(str, pos)` | Finds first occurrence of `str` from `pos` | **O(N)** |
| `rfind(str, pos)` | Finds last occurrence of `str` before `pos` | **O(N)** |
| `find_first_of(str, pos)` | Finds first character from `str` in `this` string | **O(N)** |
| `find_last_of(str, pos)` | Finds last character from `str` in `this` string | **O(N)** |
| `find_first_not_of(str, pos)` | Finds first character not in `str` | **O(N)** |
| `find_last_not_of(str, pos)` | Finds last character not in `str` | **O(N)** |

### 📌 **Substring & Tokenization**
| Function | Description | Time Complexity |
|----------|------------|----------------|
| `substr(pos, len)` | Extracts substring from `pos` of length `len` | **O(N)** |
| `getline(cin, str, delim)` | Reads line from input stream (handles spaces) | **O(N)** |
| `strtok(char*, delim)` | Splits `C-style` string by `delim` | **O(N)** |

---