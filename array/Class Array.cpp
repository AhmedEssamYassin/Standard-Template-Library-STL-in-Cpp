#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Fixed-size Array Implementation (STL array)

Size is constant (must be known at compile-time)
Supports Random Access (Fast element access like built-in arrays)
Supports Iterators (begin, end, rbegin, rend)
Supports various utility functions for ease of use

Methods:
--------
begin(): returns an iterator to the first element in the array - O(1)
end(): returns an iterator to the position past the last element - O(1)
rbegin(): returns a reverse iterator to the last element - O(1)
rend(): returns a reverse iterator to the position before the first element - O(1)
front(): returns the first element in the array - O(1)
back(): returns the last element in the array - O(1)
size(): returns the size of the array - O(1)
empty(): returns true if the array is empty, otherwise false - O(1)
at(index): returns the element at a specified position with bounds checking - O(1)
swap(array<T, N>& other): swaps the contents of two arrays - O(N)
fill(value): fills the entire array with a specific value - O(N)
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	array<int, 5> arr{1, 8, -2, 12, 5};
	cout << "Front: " << arr.front() << endl;				   // Prints 1
	cout << "Back: " << arr.back() << endl;					   // Prints 5
	cout << "Size: " << arr.size() << endl;					   // Prints 5
	cout << "Empty: " << (arr.empty() ? "Yes" : "No") << endl; // Prints No

	// Traversing using iterators
	cout << "Elements: ";
	for (auto it = arr.begin(); it != arr.end(); ++it)
		cout << *it << " ";
	cout << endl;

	sort(arr.begin(), arr.end()); // Sorting the array
	cout << "After sorting: ";
	for (const int &x : arr)
		cout << x << " ";
	cout << endl;

	cout << "Element at index 2: " << arr.at(2) << endl; // Prints third element

	array<int, 5> newArr{1, 2, 0, -4, 7};
	arr.swap(newArr);

	cout << "Elements of arr after swap: ";
	for (const int &x : arr)
		cout << x << " ";
	cout << endl;

	cout << "Elements of newArr after swap: ";
	for (const int &x : newArr)
		cout << x << " ";
	cout << endl;

	arr.fill(9); // Filling entire array with 9
	cout << "After fill(9): ";
	for (const int &x : arr)
		cout << x << " ";
	cout << endl;

	return 0;
}
