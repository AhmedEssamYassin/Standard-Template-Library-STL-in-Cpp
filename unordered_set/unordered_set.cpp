#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Unordered Set Implementation (STL unordered_set)

- Stores unique elements (Associative container).
- Uses Hash Table for fast lookup.
- Provides **average O(1) complexity** for insertion, deletion, and search.
- Elements are stored **unordered** (No specific order).
- **No duplicate values allowed** (Use unordered_multiset for duplicates).
- Collision handling is done via **chaining** (linked lists in buckets).

Methods:
--------
begin(): returns an iterator to the first element in the unordered_set - O(1)
end(): returns an iterator to the position past the last element - O(1)
size(): returns the number of elements in the set - O(1)
empty(): returns true if the set is empty, otherwise false - O(1)
insert(value): inserts a unique value into the set - O(1) (amortized)
erase(value): removes the element with the given value - O(1) (amortized)
find(value): returns an iterator to the element if found, otherwise end() - O(1) (amortized)
count(value): returns 1 if value exists, otherwise 0 - O(1)
swap(other): swaps the contents with another unordered_set - O(N)
clear(): removes all elements from the set - O(N)
bucket_count(): returns the number of hash buckets - O(1)
load_factor(): returns the load factor (size / bucket_count) - O(1)
rehash(n): resizes the hash table to have at least n buckets - O(N)
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// Declaration and Initialization
	unordered_set<int> uset;

	// Inserting elements
	uset.insert(10);
	uset.insert(20);
	uset.insert(30);
	uset.insert(40);
	uset.insert(10); // Duplicate values are ignored

	// Traversing unordered_set (No order)
	cout << "Unordered Set Elements:\n";
	for (const int &x : uset)
		cout << x << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Checking if an element exists
	if (uset.find(20) != uset.end())
		cout << "20 exists in the set\n";

	if (uset.count(50) == 0)
		cout << "50 does not exist in the set\n";
	cout << "--------------------------------------------------------" << endl;

	// Erasing Elements
	uset.erase(30);
	cout << "After erasing 30:\n";
	for (const int &x : uset)
		cout << x << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Swapping with another unordered_set
	unordered_set<int> newUset = {100, 200, 300};
	uset.swap(newUset);

	cout << "Elements of uset after swap: ";
	for (const int &x : uset)
		cout << x << " ";
	cout << endl;

	cout << "Elements of newUset after swap: ";
	for (const int &x : newUset)
		cout << x << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Size, Clear, Empty
	cout << "Size of set: " << uset.size() << endl;
	uset.clear();
	cout << "After clearing, is empty? " << (uset.empty() ? "Yes" : "No") << endl;
	cout << "--------------------------------------------------------" << endl;

	// Hash Table Properties
	unordered_set<int> uset2 = {1, 2, 3, 4, 5};

	cout << "Number of Buckets: " << uset2.bucket_count() << endl;
	cout << "Load Factor: " << uset2.load_factor() << endl;
	cout << "Rehashing to 10 buckets...\n";
	uset2.rehash(10);
	cout << "New Bucket Count: " << uset2.bucket_count() << endl;
	cout << "--------------------------------------------------------" << endl;

	return 0;
}
