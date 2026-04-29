#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Demonstrating the difference between using find() or count() and operator[] for checking key existence in map.

- Using operator[]: If the key does not exist, it creates a new entry with default value (0 for int, empty string for string, etc.), leading to unwanted memory usage.
- Using find() or count(): These methods check for the key without inserting it, avoiding unnecessary overhead.

Time Complexity:
----------------
- find(key): O(log N)
- count(key): O(log N)
- operator[key]: O(log N) for search + O(log N) for insertion if key is absent (total O(log N))
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

    // Using subscript operator (Bad practice for checking existence)
    if (myMap["Alice"])
        cout << "Alice exists with value: " << myMap["Alice"] << endl;
    else
        cout << "Alice does not exist but was inserted with default value: " << myMap["Alice"] << endl;

    // Using find() (Better approach)
    if (myMap.find("Bob") != myMap.end())
        cout << "Bob exists with value: " << myMap["Bob"] << endl;
    else
        cout << "Bob does not exist, no insertion occurred." << endl;

    // Using count() (Another safe approach)
    if (myMap.count("Charlie"))
        cout << "Charlie exists with value: " << myMap["Charlie"] << endl;
    else
        cout << "Charlie does not exist, no insertion occurred." << endl;

    return 0;
}