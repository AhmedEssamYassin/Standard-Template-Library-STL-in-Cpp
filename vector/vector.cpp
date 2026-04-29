#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Dynamic Array Implementation (STL vector)

Vectors are dynamic arrays that grow automatically when needed.
They provide fast random access, efficient insertions/deletions at the end, and various utility functions.
Unlike arrays, their size is not fixed and can change at runtime.

Time Complexity:
----------------
- Random access (operator[]): O(1)
- Insertion/Deletion at the end: O(1) amortized (due to dynamic resizing)
- Insertion/Deletion at any position: O(N) (due to shifting elements)
- Search (if unsorted): O(N), Binary Search (if sorted): O(log N)
- Resizing (push_back() when full): O(N), but amortized to O(1) per operation

Why Amortized O(1) for push_back?
--------------------------------
When a vector runs out of capacity, it allocates a larger memory block (usually 2x its current size)
and copies all existing elements. While this reallocation is expensive (O(N)),
most push_back operations are O(1). Over multiple operations, the average cost per operation is O(1).

Methods:
--------
begin(): returns an iterator to the first element - O(1)
end(): returns an iterator past the last element - O(1)
rbegin(): returns a reverse iterator to the last element - O(1)
rend(): returns a reverse iterator before the first element - O(1)
size(): returns the number of elements - O(1)
capacity(): returns the total allocated storage - O(1)
empty(): checks if vector is empty - O(1)
resize(n): resizes vector to contain n elements - O(N)
push_back(value): adds an element at the end - O(1) amortized
emplace_back(args): constructs an element directly at the end (faster for complex types) - O(1) amortized
pop_back(): removes the last element - O(1)
front(): returns the first element - O(1)
back(): returns the last element - O(1)
at(index): returns element at given index with bounds checking - O(1)
insert(iterator, value): inserts value at iterator position - O(N)
erase(iterator): removes element at iterator position - O(N)
clear(): removes all elements - O(N)
swap(vector<T>& other): swaps contents with another vector - O(1)
assign(n, value): assigns new values to vector - O(N)
reserve(n): allocates memory for at least n elements (prevents reallocations) - O(N)
shrink_to_fit(): reduces capacity to fit size - O(N)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    /* Initializing a vector with values */
    vector<int> myVector{10, 5, 20, 15, 25};
    cout << "Size: " << myVector.size() << "\n";
    cout << "Capacity: " << myVector.capacity() << "\n";
    cout << "Empty: " << (myVector.empty() ? "Yes" : "No") << "\n";

    /* Traversing the vector */
    cout << "Elements: ";
    for (const int &x : myVector)
        cout << x << " ";
    cout << "\n";

    /* Adding an element at the end */
    myVector.push_back(30);
    cout << "After push_back(30): ";
    for (const int &x : myVector)
        cout << x << " ";
    cout << "\n";

    /* Removing the last element */
    myVector.pop_back();
    cout << "After pop_back(): ";
    for (const int &x : myVector)
        cout << x << " ";
    cout << "\n";

    /* Inserting an element at a specific position */
    myVector.insert(myVector.begin() + 2, 50);
    cout << "After insert(50 at index 2): ";
    for (const int &x : myVector)
        cout << x << " ";
    cout << "\n";

    /* Erasing an element at a specific position */
    myVector.erase(myVector.begin() + 2);
    cout << "After erase(index 2): ";
    for (const int &x : myVector)
        cout << x << " ";
    cout << "\n";

    /* Resizing the vector (shrinks it to 3 elements) */
    myVector.resize(3);
    cout << "After resize(3): ";
    for (const int &x : myVector)
        cout << x << " ";
    cout << "\n";

    /* Reducing capacity to fit size exactly */
    myVector.shrink_to_fit();
    cout << "After shrink_to_fit(), capacity: " << myVector.capacity() << "\n";

    /* Clearing the vector */
    myVector.clear();
    cout << "After clear(), empty: " << (myVector.empty() ? "Yes" : "No") << "\n";

    /* --- Reserve vs Resize --- */
    vector<int> resVec;
    resVec.reserve(100); /* Allocates memory for 100 elements, but size is still 0 */
    cout << "\nAfter reserve(100) -> Size: " << resVec.size() << ", Capacity: " << resVec.capacity() << "\n";
    resVec.resize(50); /* Changes size to 50, filling with 0s */
    cout << "After resize(50) -> Size: " << resVec.size() << ", Capacity: " << resVec.capacity() << "\n";

    /* --- emplace_back vs push_back --- */
    vector<pair<int, string>> pairVec;
    pairVec.push_back({1, "Alice"}); /* Creates a temporary pair, then copies/moves it */
    pairVec.emplace_back(2, "Bob");  /* Constructs the pair directly in place (more efficient) */

    /* --- Erase-Remove Idiom --- */
    vector<int> nums = {1, 2, 3, 2, 4, 2, 5};
    /* remove() shifts non-matching elements to the front and returns an iterator to the new logical end. */
    /* erase() then deletes the physical elements from that new end to the actual end. */
    nums.erase(remove(nums.begin(), nums.end(), 2), nums.end());
    cout << "\nAfter erase-remove idiom (removing 2s): ";
    for (const int &x : nums)
        cout << x << " ";
    cout << "\n\n"; /* 2D Vector (Matrix-like structure) */
    vector<vector<int>> matrix(3, vector<int>(4, 1));
    cout << "2D Vector (3x4 filled with 1s): " << "\n";
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
            cout << elem << " ";
        cout << "\n";
    }

    /* Array of Vectors (Different-sized rows) */
    vector<int> arrVec[3];
    arrVec[0].push_back(10);
    arrVec[0].push_back(12);
    arrVec[0].push_back(40);
    arrVec[1].push_back(20);
    arrVec[2].push_back(30);
    arrVec[2].push_back(55);
    cout << "Array of Vectors: " << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (const int &x : arrVec[i])
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
