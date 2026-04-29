#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
STL Algorithms
--------------
The <algorithm> library is one of the most powerful parts of C++.
It works with any container that provides iterators (vector, array, string, deque, etc.).
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    vector<int> v = {4, 2, 5, 1, 3, 5, 2};

    cout << "Original vector: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    /* --- Sorting --- */
    sort(v.begin(), v.end());
    cout << "After sort(): ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    sort(v.rbegin(), v.rend()); /* Reverse sort */
    cout << "After sort(rbegin, rend): ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    sort(v.begin(), v.end()); /* sort ascending again for binary_search */

    /* --- Binary Search & Bounds (Requires SORTED range) --- */
    bool exists = binary_search(v.begin(), v.end(), 3);
    cout << "\nDoes 3 exist? " << (exists ? "Yes" : "No") << "\n";

    auto lb = lower_bound(v.begin(), v.end(), 4); /* First element >= 4 */
    auto ub = upper_bound(v.begin(), v.end(), 4); /* First element > 4 */
    cout << "lower_bound of 4 is at index: " << distance(v.begin(), lb) << "\n";
    cout << "upper_bound of 4 is at index: " << distance(v.begin(), ub) << "\n";

    /* --- Counting & Checking --- */
    int count5 = count(v.begin(), v.end(), 5);
    cout << "\nNumber of 5s: " << count5 << "\n";

    bool allPositive = all_of(v.begin(), v.end(), [](int x) { return x > 0; });
    cout << "Are all elements positive? " << (allPositive ? "Yes" : "No") << "\n";

    /* --- Mutations --- */
    reverse(v.begin(), v.end());
    cout << "\nAfter reverse(): ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    /* Rotate left by 2 positions */
    rotate(v.begin(), v.begin() + 2, v.end());
    cout << "After rotate(begin+2): ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    /* Unique (Erase-Unique idiom) */
    /* Must sort first for unique to group all duplicates together */
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "After sort + erase(unique): ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    /* --- Permutations --- */
    string s = "ABC";
    cout << "\nPermutations of " << s << ":" << "\n";
    do
    {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
