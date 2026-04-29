#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Deque (Double-Ended Queue) Implementation (STL deque)

A dynamic array-like container that allows insertion and deletion at both ends
Provides fast access, insertion, and deletion at both the front and back - O(1)
Supports random access like a vector

Methods:
--------
begin(): returns an iterator to the first element in the deque - O(1)
end(): returns an iterator to the position past the last element - O(1)
rbegin(): returns a reverse iterator to the last element - O(1)
rend(): returns a reverse iterator to the position before the first element - O(1)
size(): returns the number of elements in the deque - O(1)
empty(): returns true if the deque is empty, otherwise false - O(1)
push_back(value): inserts an element at the end of the deque - O(1)
push_front(value): inserts an element at the front of the deque - O(1)
pop_back(): removes the last element from the deque - O(1)
pop_front(): removes the first element from the deque - O(1)
front(): returns the first element of the deque - O(1)
back(): returns the last element of the deque - O(1)
at(index): returns the element at a specified position with bounds checking - O(1)
insert(iterator, value): inserts a value at the specified iterator position - O(N)
erase(iterator): removes element at the specified iterator position - O(N)
clear(): removes all elements from the deque - O(N)
swap(deque<T>& other): swaps the elements of two deques - O(1)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    deque<int> myDeque;
    myDeque.push_back(10);
    myDeque.push_front(20);
    myDeque.push_back(30);
    myDeque.push_front(40);

    cout << "Size: " << myDeque.size() << "\n";                    /* Prints 4 */
    cout << "Empty: " << (myDeque.empty() ? "Yes" : "No") << "\n"; /* Prints No */
    cout << "Front: " << myDeque.front() << "\n";                  /* Prints 40 */
    cout << "Back: " << myDeque.back() << "\n";                    /* Prints 30 */

    /* Traversing the deque */
    cout << "Elements: ";
    for (const int &x : myDeque)
        cout << x << " ";
    cout << "\n";

    /* Removing elements from both ends */
    myDeque.pop_front();
    myDeque.pop_back();
    cout << "After pop_front() and pop_back(): ";
    for (const int &x : myDeque)
        cout << x << " ";
    cout << "\n";

    /*
    Insert and erase

    IMPORTANT: deque::insert() invalidates ALL iterators.
    You must re-acquire any iterator after calling insert().
    Using a stale iterator after insert() is undefined behavior.
    */
    myDeque.insert(myDeque.begin() + 1, 50);
    cout << "After insert(50 at position 2): ";
    for (const int &x : myDeque)
        cout << x << " ";
    cout << "\n";

    myDeque.erase(myDeque.begin());
    cout << "After erase(first element): ";
    for (const int &x : myDeque)
        cout << x << " ";
    cout << "\n";

    myDeque.clear();
    cout << "After clear(): " << (myDeque.empty() ? "Deque is empty" : "Deque is not empty") << "\n";

    return 0;
}
