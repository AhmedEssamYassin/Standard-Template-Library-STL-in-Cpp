#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Pairs and Vector of Pairs in C++ STL

A pair is a container that stores two values mapped to each other as (a, b).
A vector containing multiple such pairs is called a "vector of pairs".
*/

/* Predicate function to sort vector elements by the second element of pairs */
bool sortbysec(const pair<int, int> &P1, const pair<int, int> &P2) { return (P1.second < P2.second); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    /* Declaring a vector of pairs */
    vector<pair<int, int>> vc;

    /* Adding pairs to the vector using different methods */
    vc.push_back({2, 5});
    vc.push_back({3, 12});
    vc.push_back(make_pair(1, 7));

    /* Printing the vector of pairs */
    cout << "Original Vector of Pairs:" << "\n";
    for (const auto &p : vc)
        cout << p.first << " " << p.second << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Sorting based on the first element (default behavior) */
    sort(vc.begin(), vc.end());
    cout << "Sorted by first element (Ascending Order):" << "\n";
    for (const auto &p : vc)
        cout << p.first << " " << p.second << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Sorting based on the second element (Ascending Order) */
    sort(vc.begin(), vc.end(), sortbysec);
    cout << "Sorted by second element (Ascending Order):" << "\n";
    for (const auto &p : vc)
        cout << p.first << " " << p.second << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Sorting based on the first element (Descending Order) */
    sort(vc.rbegin(), vc.rend());
    cout << "Sorted by first element (Descending Order):" << "\n";
    for (const auto &p : vc)
        cout << p.first << " " << p.second << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Sorting based on the second element (Descending Order) */
    sort(vc.rbegin(), vc.rend(), sortbysec);
    cout << "Sorted by second element (Descending Order):" << "\n";
    for (const auto &p : vc)
        cout << p.first << " " << p.second << "\n";
    cout << "--------------------------------------------------------" << "\n";

    return 0;
}
