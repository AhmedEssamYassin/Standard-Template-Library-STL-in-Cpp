#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Demonstrating pair and tuple in STL

Pair:
-----
A container to hold two heterogeneous values.
Stored as first and second.
Useful for key-value pairs, coordinates, etc.

Tuple:
------
A generalization of pair that can hold multiple heterogeneous values.
Supports structured binding and element access via get<>.

Methods and Features:
---------------------
make_pair(a, b): Creates a pair of two values - O(1)
tie(a, b): Unpacks values from a pair - O(1)
get<i>(tuple): Accesses the ith element of a tuple - O(1)
tuple_size<tuple<Types...>>::value: Returns number of elements - O(1)
tuple_element<i, tuple<Types...>>::type: Type of ith element - O(1)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    /* Pair Example */
    pair<int, string> p1 = make_pair(1, "Alice");
    pair<int, string> p2 = {2, "Bob"};
    cout << "Pair 1: (" << p1.first << ", " << p1.second << ")" << "\n";
    cout << "Pair 2: (" << p2.first << ", " << p2.second << ")" << "\n";

    /* Swapping pairs */
    p1.swap(p2);
    cout << "After swap - Pair 1: (" << p1.first << ", " << p1.second << ")" << "\n";

    /* Using tie to unpack a pair */
    int num;
    string name;
    tie(num, name) = p1;
    cout << "Unpacked from p1: " << num << " - " << name << "\n";

    /* Tuple Example */
    tuple<int, string, double> t1 = make_tuple(1, "Charlie", 75.5);
    cout << "Tuple: (" << get<0>(t1) << ", " << get<1>(t1) << ", " << get<2>(t1) << ")" << "\n";

    /* Modifying a tuple element */
    get<1>(t1) = "David";
    cout << "After modification: " << get<1>(t1) << "\n";

    /* Using tie to unpack a tuple */
    int id;
    string person;
    double weight;
    tie(id, person, weight) = t1;
    cout << "Unpacked from tuple: " << id << " - " << person << " - " << weight << "\n";

    return 0;
}
