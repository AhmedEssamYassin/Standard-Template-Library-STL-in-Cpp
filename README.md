# Standard Template Library (STL) in C++

This repository serves as a comprehensive, technical reference for the C++ Standard Template Library (STL). It provides in-depth examples, architectural breakdowns, and performance analyses for STL containers, iterators, and algorithms. The objective is to bridge the gap between basic C++ syntax and high-performance competitive programming or production-level engineering.

Each module within the repository details the underlying data structures, strict time complexities (Big-O notation), iterator invalidation rules, and edge cases to prevent undefined behavior.

## Target Demographic

- **Competitive Programmers**: Optimized reference material for container operations, custom comparators, hash collision mitigation, and Order Statistics Trees (PBDS).
- **Software Engineers**: A structured refresher on C++ container selection, strict weak ordering, and memory management (e.g., `reserve` vs `resize`).
- **Students**: A stepping stone from basic C++ data structures to standard library mastery.

## Build and Execution

The repository includes a unified build system to compile and test all modules. It requires GCC and Make. It compiles using the `std=c++2b` standard and applies the `-DLOCAL` flag to support local file redirection without hanging.

```sh
# Compile all executable files
make -f Makefile all

# Execute all binaries and route stdout to local Output.txt files
make -f Makefile run

# Clean build artifacts
make -f Makefile clean
```

## Code Standards & Conventions

The codebase adheres strictly to a custom professional style guide:
- **Formatting**: 4-space indentation, Allman brace style, and block comments (`/* ... */`) exclusively.
- **Performance**: `\n` is used universally over `std::endl` to prevent expensive output buffer flushing.
- **Environment**: `#include <bits/stdc++.h>` and `freopen()` are utilized for brevity and rapid local testing. These are standard in competitive programming but should be refactored for production environments.

---

## STL Containers Overview

| Container        | Underlying Structure   | Supports Iterators        | Random Access | Allows Duplicates | Sorted               |
| :--------------- | :--------------------- | :------------------------ | :------------ | :---------------- | :------------------- |
| `array`          | Fixed-size array       | **✓ Yes**                 | **✓ Yes**     | **✓ Yes**         | ✗ No                 |
| `vector`         | Dynamic array          | **✓ Yes**                 | **✓ Yes**     | **✓ Yes**         | ✗ No                 |
| `deque`          | Doubly-ended queue     | **✓ Yes**                 | **✓ Yes**     | **✓ Yes**         | ✗ No                 |
| `list`           | Doubly linked list     | **✓ Yes** (Bidirectional) | ✗ No          | **✓ Yes**         | ✗ No                 |
| `stack`          | LIFO (deque/vector)    | ✗ No (Top only)           | ✗ No          | **✓ Yes**         | ✗ No                 |
| `queue`          | FIFO (deque/list)      | ✗ No (Front/Back)         | ✗ No          | **✓ Yes**         | ✗ No                 |
| `priority_queue` | Binary Heap            | ✗ No (Top only)           | ✗ No          | **✓ Yes**         | **✓ Yes** (Max Heap) |
| `set`            | Balanced BST (RB-Tree) | **✓ Yes**                 | ✗ No          | ✗ No (Unique)     | **✓ Yes**            |
| `multiset`       | Balanced BST (RB-Tree) | **✓ Yes**                 | ✗ No          | **✓ Yes**         | **✓ Yes**            |
| `unordered_set`  | Hash Table             | **✓ Yes**                 | ✗ No          | ✗ No (Unique)     | ✗ No                 |
| `map`            | Balanced BST (RB-Tree) | **✓ Yes**                 | ✗ No          | ✗ No (Unique)     | **✓ Yes** (By Key)   |
| `multimap`       | Balanced BST (RB-Tree) | **✓ Yes**                 | ✗ No          | **✓ Yes**         | **✓ Yes** (By Key)   |
| `unordered_map`  | Hash Table             | **✓ Yes**                 | ✗ No          | ✗ No (Unique)     | ✗ No                 |
| `pair`           | Structured Binding     | ✗ No                      | ✗ No          | **✓ Yes**         | ✗ No                 |
| `tuple`          | Heterogeneous Sequence | ✗ No                      | ✗ No          | **✓ Yes**         | ✗ No                 |
---

## Modules Covered

### Sequential Containers
- `array`, `vector`, `deque`, `list`

### Associative Containers
- **Ordered**: `set`, `multiset`, `map`, `multimap`
- **Unordered**: `unordered_set`, `unordered_map`

### Container Adapters
- `stack`, `queue`, `priority_queue`

### Utility & Core Concepts
- `algorithms` (Sorting, Searching, Modifying)
- `iterators` (Categories, Adapters, Invalidation rules)
- `predicate_functions` (Custom Comparators, Strict Weak Ordering)
- `custom_hash_function` (SplitMix64 implementation for collision defense)
- `pair_and_tuple`, `bitset`

### GCC Extensions
- `policy_based_data_structures` (Order Statistics Tree for O(log N) indexing and k-th element lookups)

---

## Container Selection Matrix

```mermaid
flowchart TD
    Start([Start: Choose C++ Container]) --> Type{Key-Value pairs?}

    %% Associative Containers (Maps)
    Type -->|Yes| MapOrdered{Need sorted keys?}
    MapOrdered -->|Yes| MapDups{Allow duplicates?}
    MapDups -->|Yes| multimap[`std::multimap`]
    MapDups -->|No| map[`std::map`]
    
    MapOrdered -->|No| UMapDups{Allow duplicates?}
    UMapDups -->|Yes| umultimap[`std::unordered_multimap`]
    UMapDups -->|No| umap[`std::unordered_map`]

    %% Sequence & Set Containers
    Type -->|No| Search{Fast search by value <br/>or uniqueness?}

    %% Sets
    Search -->|Yes| SetOrdered{Need elements sorted?}
    SetOrdered -->|Yes| SetDups{Allow duplicates?}
    SetDups -->|Yes| multiset[`std::multiset`]
    SetDups -->|No| set[`std::set`]
    
    SetOrdered -->|No| USetDups{Allow duplicates?}
    USetDups -->|Yes| umultiset[`std::unordered_multiset`]
    USetDups -->|No| uset[`std::unordered_set`]

    %% Sequences
    Search -->|No| Fixed{Fixed size known <br/>at compile time?}
    Fixed -->|Yes| array[`std::array`]
    Fixed -->|No| MidInsert{Frequent inserts/erases<br/>in the middle?}

    MidInsert -->|Yes| list[`std::list` / `std::forward_list`]
    MidInsert -->|No| Ends{Insert/erase at<br/>BOTH front and back?}

    Ends -->|Yes| deque[`std::deque`]
    Ends -->|No| vector[`std::vector` <br/>⭐ Default Choice]

    %% Styling (Works natively on GitHub)
    classDef decision fill:#e1f5fe,stroke:#0288d1,stroke-width:2px,color:#000;
    classDef result fill:#e8f5e9,stroke:#388e3c,stroke-width:2px,color:#000;
    classDef highlight fill:#fff9c4,stroke:#fbc02d,stroke-width:3px,color:#000;

    class Type,MapOrdered,MapDups,UMapDups,Search,SetOrdered,SetDups,USetDups,Fixed,MidInsert,Ends decision;
    class multimap,map,umultimap,umap,multiset,set,umultiset,uset,array,list,deque result;
    class vector highlight;
```

---

## Asymptotic Complexity Matrix

| Operation        | `vector`       | `deque` | `list` | `set`/`map`    | `unordered_set/map` |
| ---------------- | -------------- | ------- | ------ | -------------- | ------------------- |
| **Access `[i]`** | O(1)           | O(1)    | O(N)   | O(log N) (Map) | O(1) avg (Map)      |
| **Insert front** | O(N)           | O(1)    | O(1)   | —              | —                   |
| **Insert back**  | O(1) Amortized | O(1)    | O(1)   | —              | —                   |
| **Insert mid**   | O(N)           | O(N)    | O(1)*  | O(log N)       | O(1) avg            |
| **Erase mid**    | O(N)           | O(N)    | O(1)*  | O(log N)       | O(1) avg            |
| **Find**         | O(N)           | O(N)    | O(N)   | O(log N)       | O(1) avg            |

*\* Note: O(1) insertion/erasure in `list` assumes the iterator is already pointing to the target position. Finding that position still requires O(N) traversal.*
