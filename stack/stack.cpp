#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Stack Implementation (STL stack)

LIFO (Last In, First Out) Data Structure
Elements are inserted and removed from the top
Provides constant-time complexity for insertion and deletion - O(1)

Methods:
--------
empty(): returns true if the stack is empty, otherwise false - O(1)
size(): returns the number of elements in the stack - O(1)
push(value): inserts an element at the top of the stack - O(1)
pop(): removes the element from the top of the stack - O(1)
top(): returns the top element of the stack - O(1)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Size: " << myStack.size() << "\n";                    /* Prints 3 */
    cout << "Empty: " << (myStack.empty() ? "Yes" : "No") << "\n"; /* Prints No */
    cout << "Top: " << myStack.top() << "\n";                      /* Prints 30 */

    /* Removing elements from the stack */
    myStack.pop();
    cout << "After pop(): " << "\n";
    cout << "Top: " << myStack.top() << "\n";   /* Prints 20 */
    cout << "Size: " << myStack.size() << "\n"; /* Prints 2 */

    /* Clearing the stack */
    while (!myStack.empty())
        myStack.pop();

    cout << "After clearing: " << (myStack.empty() ? "Stack is empty" : "Stack is not empty") << "\n";

    return 0;
}
