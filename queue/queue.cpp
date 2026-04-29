#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Queue Implementation (STL queue)

FIFO (First In, First Out) Data Structure
Elements are inserted at the back and removed from the front
Provides constant-time complexity for insertion and deletion - O(1)

Methods:
--------
empty(): returns true if the queue is empty, otherwise false - O(1)
size(): returns the number of elements in the queue - O(1)
push(value): inserts an element at the back of the queue - O(1)
pop(): removes the element from the front of the queue - O(1)
front(): returns the front element of the queue - O(1)
back(): returns the last element of the queue - O(1)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    queue<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    cout << "Size: " << myQueue.size() << "\n";                    /* Prints 3 */
    cout << "Empty: " << (myQueue.empty() ? "Yes" : "No") << "\n"; /* Prints No */
    cout << "Front: " << myQueue.front() << "\n";                  /* Prints 10 */
    cout << "Back: " << myQueue.back() << "\n";                    /* Prints 30 */

    /* Removing elements from the queue */
    myQueue.pop();
    cout << "After pop(): " << "\n";
    cout << "Front: " << myQueue.front() << "\n"; /* Prints 20 */
    cout << "Size: " << myQueue.size() << "\n";   /* Prints 2 */

    /* Clearing the queue */
    while (!myQueue.empty())
        myQueue.pop();

    cout << "After clearing: " << (myQueue.empty() ? "Queue is empty" : "Queue is not empty") << "\n";

    return 0;
}
