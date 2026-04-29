#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Multimap Implementation (STL multimap)

- Stores key-value pairs (Associative container).
- Uses a **Balanced Binary Search Tree (Red-Black Tree)** internally.
- Allows **duplicate keys** (Unlike `map` which enforces unique keys).
- Keys are stored **in sorted order**.
- Provides **O(log N) complexity** for insertion, deletion, and search.

Methods:
--------
begin(): returns an iterator to the first element in the multimap - O(1)
end(): returns an iterator to the position past the last element - O(1)
size(): returns the number of key-value pairs in the multimap - O(1)
empty(): returns true if the multimap is empty, otherwise false - O(1)
insert({key, value}): inserts a key-value pair into the multimap (duplicates allowed) - O(log N)
erase(key): removes all elements with the given key - O(log N)
find(key): returns an iterator to the first occurrence of key, or end() if not found - O(log N)
count(key): returns the number of occurrences of a key - O(log N)
lower_bound(key): returns an iterator to the first element not less than key - O(log N)
upper_bound(key): returns an iterator to the first element greater than key - O(log N)
equal_range(key): returns a pair of iterators {lower_bound, upper_bound} - O(log N)
swap(other): swaps the contents with another multimap - O(N)
clear(): removes all elements from the multimap - O(N)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    /* Declaration and Initialization */
    multimap<string, int> mmap;

    /* Inserting elements (Duplicate keys allowed) */
    mmap.insert({"apple", 50});
    mmap.insert({"banana", 30});
    mmap.insert({"cherry", 20});
    mmap.insert({"banana", 40}); /* Duplicate key */
    mmap.insert({"apple", 60});  /* Duplicate key */

    /* Traversing multimap (Sorted by key, duplicates kept in insertion order) */
    cout << "Multimap Elements:\n";
    for (const auto &p : mmap)
        cout << p.first << ": " << p.second << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Finding elements */
    auto it = mmap.find("banana");
    if (it != mmap.end())
        cout << "First occurrence of banana: " << it->second << "\n";

    /* Counting occurrences of a key */
    cout << "Count of 'apple': " << mmap.count("apple") << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Getting range of elements with the same key */
    cout << "All values for 'banana': ";
    auto range = mmap.equal_range("banana");
    for (auto it = range.first; it != range.second; ++it)
        cout << it->second << " ";
    cout << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Erasing all occurrences of a key */
    mmap.erase("apple");
    cout << "After erasing 'apple':\n";
    for (const auto &p : mmap)
        cout << p.first << ": " << p.second << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Lower bound and Upper bound — always guard against end() before dereferencing */
    auto lb = mmap.lower_bound("banana");
    auto ub = mmap.upper_bound("banana");
    if (lb != mmap.end())
        cout << "Lower bound of 'banana': " << lb->second << "\n";
    if (ub != mmap.end())
        cout << "Upper bound of 'banana': " << ub->second << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Swapping with another multimap */
    multimap<string, int> newMmap = {{"grape", 70}, {"orange", 90}};
    mmap.swap(newMmap);

    cout << "Elements of mmap after swap: ";
    for (const auto &p : mmap)
        cout << p.first << ": " << p.second << " ";
    cout << "\n";

    cout << "Elements of newMmap after swap: ";
    for (const auto &p : newMmap)
        cout << p.first << ": " << p.second << " ";
    cout << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Size, Clear, Empty */
    cout << "Size of multimap: " << mmap.size() << "\n";
    mmap.clear();
    cout << "After clearing, is empty? " << (mmap.empty() ? "Yes" : "No") << "\n";
    cout << "--------------------------------------------------------" << "\n";

    return 0;
}
