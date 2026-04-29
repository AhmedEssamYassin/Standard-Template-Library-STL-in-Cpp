# C++ STL: Custom Hash Function for `unordered_map` & `unordered_set`

## Overview
The default hash function in `std::unordered_map` and `std::unordered_set` can be **vulnerable to attacks** (such as hash collision attacks in competitive programming). To **enhance performance and security**, we use a **custom hash function**.

---

## Why Use a Custom Hash?
| Issue | Explanation |
|-------|------------|
| **Weak Default Hash** | The default hashing function is **predictable**, making it easy for attackers to force collisions. |
| **Performance Degradation** | If too many elements map to the same bucket, operations degrade from **O(1) to O(N)**. |
| **Custom Randomization** | We can introduce **random seed values** to prevent predictable collisions. |

---

## **Custom Hash Implementation**
We use **[SplitMix64](https://xoshiro.di.unimi.it/splitmix64.c) hashing** for a **robust and fast** hashing function.

```cpp
struct CustomHash 
{
 static uint64_t splitmix64(uint64_t x) 
 {
 x += 0x9e3779b97f4a7c15;
 x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
 x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
 return x ^ (x >> 31);
 }

 size_t operator()(uint64_t x) const 
 {
 static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
 return splitmix64(x + FIXED_RANDOM);
 }
};
```