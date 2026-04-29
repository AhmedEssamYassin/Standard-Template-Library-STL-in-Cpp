# C++ STL: `<algorithm>`

## Overview
The `<algorithm>` header provides a vast collection of functions designed to be used on ranges of elements (defined by iterators). These functions perform operations like sorting, searching, counting, and modifying, and they are decoupled from the containers they operate on.

## Why Use STL Algorithms?
1. **Expressiveness**: `std::count_if` communicates intent much better than a manual `for` loop.
2. **Correctness**: They are thoroughly tested and handle edge cases (like empty ranges).
3. **Performance**: They are highly optimized. For instance, `std::sort` uses Introsort (O(N log N) worst-case) which is generally faster than handwritten quicksort.

---

## 📝 Common Algorithms

### Searching
- `find(begin, end, val)`: Finds first occurrence of `val` in O(N).
- `binary_search(begin, end, val)`: Returns true if `val` exists in a **sorted** range in O(log N).
- `lower_bound(begin, end, val)`: Returns iterator to first element `>= val` in a **sorted** range in O(log N).
- `upper_bound(begin, end, val)`: Returns iterator to first element `> val` in a **sorted** range in O(log N).

### Sorting
- `sort(begin, end)`: Sorts in ascending order. O(N log N).
- `stable_sort(begin, end)`: Sorts but maintains relative order of equal elements. O(N log N^2) or O(N log N) if extra memory is available.
- `partial_sort(begin, middle, end)`: Sorts the top K elements. O(N log K).

### Counting & Checking
- `count(begin, end, val)`: Counts occurrences of `val`. O(N).
- `all_of`, `any_of`, `none_of(begin, end, predicate)`: Checks condition across range. O(N).

### Modifying & Mutating
- `reverse(begin, end)`: Reverses the range. O(N).
- `rotate(begin, mid, end)`: Left-rotates such that `mid` becomes the new first element. O(N).
- `unique(begin, end)`: Moves consecutive duplicates to the end, returns iterator to new logical end. O(N). (Often paired with `erase`).
- `next_permutation(begin, end)`: Rearranges range into the next lexicographically greater permutation. Returns false if it was the last permutation. O(N).
