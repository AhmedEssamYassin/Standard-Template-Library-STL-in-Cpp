#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Ordered Set Implementation (STL set)

Stores unique elements in sorted order
Implemented as a balanced binary search tree (typically Red-Black Tree)
Lookup, insertion, and deletion are logarithmic time O(log N)
Supports bidirectional iterators

Methods:
--------
begin(): returns an iterator to the first element in the set - O(1)
end(): returns an iterator to the position past the last element - O(1)
rbegin(): returns a reverse iterator to the last element - O(1)
rend(): returns a reverse iterator to the position before the first element - O(1)
size(): returns the number of elements in the set - O(1)
empty(): returns true if the set is empty, otherwise false - O(1)
insert(value): inserts an element (only if it does not already exist) - O(log N)
erase(iterator/value): removes an element by iterator or value - O(log N)
find(value): returns an iterator to the value if found, otherwise set.end() - O(log N)
count(value): returns 1 if the value exists, otherwise 0 - O(log N)
lower_bound(value): returns an iterator to the first element not less than value - O(log N)
upper_bound(value): returns an iterator to the first element greater than value - O(log N)
clear(): removes all elements from the set - O(N)
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	set<int> mySet{10, 5, 20, 15, 25};
	cout << "Size: " << mySet.size() << endl;					 // Prints 5
	cout << "Empty: " << (mySet.empty() ? "Yes" : "No") << endl; // Prints No

	// Traversing the set
	cout << "Elements: ";
	for (const int &x : mySet)
		cout << x << " ";
	cout << endl;

	// Inserting elements
	mySet.insert(12);
	mySet.insert(5); // Duplicate, won't be added
	cout << "After insert(12 and duplicate 5): ";
	for (const int &x : mySet)
		cout << x << " ";
	cout << endl;

	// Finding an element
	int searchValue = 15;
	if (mySet.find(searchValue) != mySet.end())
		cout << searchValue << " found in set" << endl;
	else
		cout << searchValue << " not found in set" << endl;

	// Erasing an element
	mySet.erase(10);
	cout << "After erase(10): ";
	for (const int &x : mySet)
		cout << x << " ";
	cout << endl;

	// Checking lower_bound and upper_bound
	auto lb = mySet.lower_bound(15);
	auto ub = mySet.upper_bound(15);
	if (lb != mySet.end())
		cout << "Lower bound of 15: " << *lb << endl;
	if (ub != mySet.end())
		cout << "Upper bound of 15: " << *ub << endl;

	mySet.clear();
	cout << "After clear(): " << (mySet.empty() ? "Set is empty" : "Set is not empty") << endl;

	return 0;
}
