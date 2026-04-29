#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Multiset Implementation (STL multiset)

- Stores multiple occurrences of the same value (Associative container).
- Uses a **Balanced Binary Search Tree (Red-Black Tree)** internally.
- Elements are stored **in sorted order**.
- Allows **duplicate values** (Unlike `set` which enforces unique values).
- Provides **O(log N) complexity** for insertion, deletion, and search.

Methods:
--------
begin(): returns an iterator to the first element in the multiset - O(1)
end(): returns an iterator to the position past the last element - O(1)
size(): returns the number of elements in the multiset - O(1)
empty(): returns true if the multiset is empty, otherwise false - O(1)
insert(value): inserts a value into the multiset (duplicates allowed) - O(log N)
erase(value): removes **all occurrences** of the given value - O(log N)
find(value): returns an iterator to the first occurrence of value, or end() if not found - O(log N)
count(value): returns the number of occurrences of a value - O(log N)
lower_bound(value): returns an iterator to the first element not less than value - O(log N)
upper_bound(value): returns an iterator to the first element greater than value - O(log N)
equal_range(value): returns a pair of iterators {lower_bound, upper_bound} - O(log N)
swap(other): swaps the contents with another multiset - O(N)
clear(): removes all elements from the multiset - O(N)
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	// Declaration and Initialization
	multiset<int> mset;

	// Inserting elements (Duplicates allowed)
	mset.insert(10);
	mset.insert(20);
	mset.insert(10);
	mset.insert(30);
	mset.insert(20);
	mset.insert(10);

	// Traversing multiset (Sorted order, keeps duplicates)
	cout << "Multiset Elements:\n";
	for (const int &x : mset)
		cout << x << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Finding an element
	auto it = mset.find(20);
	if (it != mset.end())
		cout << "First occurrence of 20: " << *it << endl;

	// Counting occurrences of an element
	cout << "Count of 10: " << mset.count(10) << endl;
	cout << "--------------------------------------------------------" << endl;

	// Getting range of elements with the same value
	cout << "All occurrences of 10: ";
	auto range = mset.equal_range(10);
	for (auto it = range.first; it != range.second; ++it)
		cout << *it << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Erasing elements (Removes all occurrences of 20)
	mset.erase(20);
	cout << "After erasing 20:\n";
	for (const int &x : mset)
		cout << x << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Lower bound and Upper bound
	cout << "Lower bound of 10: " << *mset.lower_bound(10) << endl;
	cout << "Upper bound of 10: " << *mset.upper_bound(10) << endl;
	cout << "--------------------------------------------------------" << endl;

	// Swapping with another multiset
	multiset<int> newMset = {100, 200, 300};
	mset.swap(newMset);

	cout << "Elements of mset after swap: ";
	for (const int &x : mset)
		cout << x << " ";
	cout << endl;

	cout << "Elements of newMset after swap: ";
	for (const int &x : newMset)
		cout << x << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Size, Clear, Empty
	cout << "Size of multiset: " << mset.size() << endl;
	mset.clear();
	cout << "After clearing, is empty? " << (mset.empty() ? "Yes" : "No") << endl;
	cout << "--------------------------------------------------------" << endl;

	return 0;
}
