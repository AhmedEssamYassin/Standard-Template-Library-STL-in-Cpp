#include <bits/stdc++.h>

/* 1. Include the PBDS headers */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

/* 2. Use the PBDS namespace */
using namespace __gnu_pbds;

#define ll long long int
#define endl "\n"

/*
Ordered Set (Order Statistics Tree)

This acts exactly like a std::set but supports two extra O(log N) operations:
1. find_by_order(k)
2. order_of_key(k)
*/

/* 3. Define the ordered_set type */
typedef tree<int,                              /* Key type */
             null_type,                        /* Value type (null_type makes it act like a set, not a map) */
             less<int>,                        /* Comparator (less = ascending order) */
             rb_tree_tag,                      /* Underlying data structure (Red-Black tree) */
             tree_order_statistics_node_update /* The policy that adds order statistics */
             >
    ordered_set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    ordered_set o_set;

    /* Insert elements */
    o_set.insert(10);
    o_set.insert(50);
    o_set.insert(30);
    o_set.insert(20);
    o_set.insert(40);

    /* The set internally sorts them: {10, 20, 30, 40, 50} */

    /* --- find_by_order(k) --- */
    /* Returns an iterator to the k-th smallest element (0-indexed) */
    /* If k is out of bounds, it returns o_set.end() */
    cout << "0-th smallest element: " << *o_set.find_by_order(0) << "\n"; /* 10 */
    cout << "2-nd smallest element: " << *o_set.find_by_order(2) << "\n"; /* 30 */
    cout << "4-th smallest element: " << *o_set.find_by_order(4) << "\n"; /* 50 */

    cout << "--------------------------------------------------------" << "\n";

    /* --- order_of_key(val) --- */
    /* Returns the number of elements STRICTLY LESS than val */
    cout << "Elements strictly less than 30: " << o_set.order_of_key(30) << "\n";   /* 2 (10, 20) */
    cout << "Elements strictly less than 25: " << o_set.order_of_key(25) << "\n";   /* 2 (10, 20) */
    cout << "Elements strictly less than 100: " << o_set.order_of_key(100) << "\n"; /* 5 (all of them) */

    return 0;
}
