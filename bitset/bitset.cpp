#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
std::bitset

A bitset is an array of bools but each boolean value is not stored separately.
Instead, bitset optimizes the space such that each bool takes exactly 1 bit.
The size of bitset is fixed at compile-time.

Because bitset uses bit-level operations on underlying integers (usually 64-bit),
operations like &, |, ^, and counting bits are extremely fast — effectively O(N/64).
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    /* Declaration */
    bitset<8> b1;           /* 00000000 */
    bitset<8> b2(29);       /* 00011101 (29 in binary) */
    bitset<8> b3("101101"); /* 00101101 (from string) */

    cout << "b1: " << b1 << "\n";
    cout << "b2: " << b2 << "\n";
    cout << "b3: " << b3 << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Bitwise Operations */
    cout << "b2 & b3: " << (b2 & b3) << "\n"; /* AND */
    cout << "b2 | b3: " << (b2 | b3) << "\n"; /* OR */
    cout << "b2 ^ b3: " << (b2 ^ b3) << "\n"; /* XOR */
    cout << "~b2 : " << (~b2) << "\n";        /* NOT */
    cout << "b2 << 1: " << (b2 << 1) << "\n"; /* Left Shift */
    cout << "b2 >> 1: " << (b2 >> 1) << "\n"; /* Right Shift */
    cout << "--------------------------------------------------------" << "\n";

    /* Modifying Bits */
    bitset<4> b4; /* 0000 */
    b4.set();     /* sets all bits to 1 (1111) */
    b4.reset(1);  /* sets bit at index 1 to 0 (1101) - Note: 0-indexed from the right */
    b4.flip(2);   /* flips bit at index 2 (1001) */

    cout << "b4 after modifications: " << b4 << "\n";
    cout << "--------------------------------------------------------" << "\n";

    /* Accessing and Information */
    cout << "Number of 1s in b4: " << b4.count() << "\n";
    cout << "Total size of b4: " << b4.size() << "\n";
    cout << "Is bit 0 set? " << (b4.test(0) ? "Yes" : "No") << "\n";
    cout << "Are any bits set? " << (b4.any() ? "Yes" : "No") << "\n";
    cout << "Are all bits set? " << (b4.all() ? "Yes" : "No") << "\n";
    cout << "Are no bits set? " << (b4.none() ? "Yes" : "No") << "\n";

    return 0;
}
