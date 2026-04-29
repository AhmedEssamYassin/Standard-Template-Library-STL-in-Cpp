#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    /* --- Basic Iteration --- */
    vector<int> vec = {10, 20, 30, 40, 50};
    cout << "Vector elements: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " "; /* Dereference iterator to get value */
    }
    cout << "\n";

    /* Much cleaner with C++11 auto: */
    /* for (auto it = vec.begin(); it != vec.end(); ++it) */

    /* --- Reverse Iterators --- */
    cout << "Vector in reverse: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n\n";

    /* --- Iterator Utilities --- */
    list<int> myList = {1, 2, 3, 4, 5};

    /* myList does NOT support random access (myList.begin() + 2 is an ERROR) */
    auto it = myList.begin();

    /* advance() moves the iterator efficiently based on its category */
    advance(it, 3); /* Moves iterator to point to '4' */
    cout << "After advance(it, 3), it points to: " << *it << "\n";

    /* distance() calculates elements between iterators */
    int dist = distance(myList.begin(), it);
    cout << "Distance from begin() to 'it' is: " << dist << "\n";

    /* next() and prev() return new iterators without modifying the original */
    auto nextIt = next(myList.begin(), 2);
    cout << "next(begin, 2) points to: " << *nextIt << "\n";

    /* --- Inserter Iterators --- */
    vector<int> dest;
    /* copy() normally requires dest to have enough space already. */
    /* back_inserter creates an output iterator that calls push_back() on dest. */
    copy(vec.begin(), vec.end(), back_inserter(dest));

    cout << "\ndest after copy + back_inserter: ";
    for (int x : dest)
        cout << x << " ";
    cout << "\n";

    return 0;
}
