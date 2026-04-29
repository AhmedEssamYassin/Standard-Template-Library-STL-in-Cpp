#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Ordered Map Implementation (STL map)

Associative container that stores key-value pairs in sorted order (by key)
Implemented as a balanced binary search tree (typically Red-Black Tree)
Keys are unique, and lookup, insertion, and deletion are logarithmic time O(log N)
Supports bidirectional iterators

Strict Weak Ordering Requirement:
---------------------------------
When using custom objects as keys, the comparator MUST obey strict weak ordering:
1. Irreflexivity: comp(a, a) is false.
2. Antisymmetry: If comp(a, b) is true, then comp(b, a) must be false.
3. Transitivity: If comp(a, b) is true and comp(b, c) is true, comp(a, c) must be true.
If the comparator fails this (e.g. using <= instead of <), the map behavior is UNDEFINED.

Methods:
--------
begin(): returns an iterator to the first element in the map - O(1)
end(): returns an iterator to the position past the last element - O(1)
rbegin(): returns a reverse iterator to the last element - O(1)
rend(): returns a reverse iterator to the position before the first element - O(1)
size(): returns the number of key-value pairs in the map - O(1)
empty(): returns true if the map is empty, otherwise false - O(1)
[key]: accesses the value corresponding to a key (inserts a new key if not found) - O(log N)
insert({key, value}): inserts a key-value pair if the key does not exist - O(log N)
erase(iterator/key): removes an element by iterator or key - O(log N)
find(key): returns an iterator to the key if found, otherwise map.end() - O(log N)
count(key): returns 1 if the key exists, otherwise 0 - O(log N)
lower_bound(key): returns an iterator to the first element not less than key - O(log N)
upper_bound(key): returns an iterator to the first element greater than key - O(log N)
clear(): removes all elements from the map - O(N)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    map<string, int> myMap;
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap.insert({"Charlie", 35});

    cout << "Size: " << myMap.size() << "\n";                    /* Prints 3 */
    cout << "Empty: " << (myMap.empty() ? "Yes" : "No") << "\n"; /* Prints No */

    /* Traversing the map */
    cout << "Elements: " << "\n";
    for (const auto &[key, value] : myMap)
        cout << key << " -> " << value << "\n";

    /* Finding an element */
    string searchKey = "Bob";
    /* Important */
    if (myMap.find(searchKey) != myMap.end())
        cout << searchKey << " found with value " << myMap[searchKey] << "\n";
    else
        cout << searchKey << " not found" << "\n";

    /* Erasing an element */
    myMap.erase("Alice");
    cout << "After erase(Alice): " << "\n";
    for (const auto &[key, value] : myMap)
        cout << key << " -> " << value << "\n";

    /* Checking lower_bound and upper_bound */
    auto lb = myMap.lower_bound("Bob");
    auto ub = myMap.upper_bound("Bob");
    if (lb != myMap.end())
        cout << "Lower bound of Bob: " << lb->first << " -> " << lb->second << "\n";
    if (ub != myMap.end())
        cout << "Upper bound of Bob: " << ub->first << " -> " << ub->second << "\n";

    myMap.clear();
    cout << "After clear(): " << (myMap.empty() ? "Map is empty" : "Map is not empty") << "\n";

    return 0;
}
