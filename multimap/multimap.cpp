#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Multimap Implementation (STL multimap)

- Stores key-value pairs (Associative container).
- Uses a **Balanced Binary Search Tree (Red-Black Tree)** internally.
- Allows **duplicate keys** (Unlike `map` which enforces unique keys).
- Keys are stored **in sorted order**.
- Provides **O(log N) complexity** for insertion, deletion, and search.

Methods:
--------
begin(): returns an iterator to the first element in the multimap - O(1)
end(): returns an iterator to the position past the last element - O(1)
size(): returns the number of key-value pairs in the multimap - O(1)
empty(): returns true if the multimap is empty, otherwise false - O(1)
insert({key, value}): inserts a key-value pair into the multimap (duplicates allowed) - O(log N)
erase(key): removes all elements with the given key - O(log N)
find(key): returns an iterator to the first occurrence of key, or end() if not found - O(log N)
count(key): returns the number of occurrences of a key - O(log N)
lower_bound(key): returns an iterator to the first element not less than key - O(log N)
upper_bound(key): returns an iterator to the first element greater than key - O(log N)
equal_range(key): returns a pair of iterators {lower_bound, upper_bound} - O(log N)
swap(other): swaps the contents with another multimap - O(N)
clear(): removes all elements from the multimap - O(N)
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
	multimap<string, int> mmap;

	// Inserting elements (Duplicate keys allowed)
	mmap.insert({"apple", 50});
	mmap.insert({"banana", 30});
	mmap.insert({"cherry", 20});
	mmap.insert({"banana", 40}); // Duplicate key
	mmap.insert({"apple", 60});	 // Duplicate key

	// Traversing multimap (Sorted by key, duplicates kept in insertion order)
	cout << "Multimap Elements:\n";
	for (const auto &p : mmap)
		cout << p.first << ": " << p.second << endl;
	cout << "--------------------------------------------------------" << endl;

	// Finding elements
	auto it = mmap.find("banana");
	if (it != mmap.end())
		cout << "First occurrence of banana: " << it->second << endl;

	// Counting occurrences of a key
	cout << "Count of 'apple': " << mmap.count("apple") << endl;
	cout << "--------------------------------------------------------" << endl;

	// Getting range of elements with the same key
	cout << "All values for 'banana': ";
	auto range = mmap.equal_range("banana");
	for (auto it = range.first; it != range.second; ++it)
		cout << it->second << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Erasing all occurrences of a key
	mmap.erase("apple");
	cout << "After erasing 'apple':\n";
	for (const auto &p : mmap)
		cout << p.first << ": " << p.second << endl;
	cout << "--------------------------------------------------------" << endl;

	// Lower bound and Upper bound
	cout << "Lower bound of 'banana': " << mmap.lower_bound("banana")->second << endl;
	cout << "Upper bound of 'banana': " << mmap.upper_bound("banana")->second << endl;
	cout << "--------------------------------------------------------" << endl;

	// Swapping with another multimap
	multimap<string, int> newMmap = {{"grape", 70}, {"orange", 90}};
	mmap.swap(newMmap);

	cout << "Elements of mmap after swap: ";
	for (const auto &p : mmap)
		cout << p.first << ": " << p.second << " ";
	cout << endl;

	cout << "Elements of newMmap after swap: ";
	for (const auto &p : newMmap)
		cout << p.first << ": " << p.second << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Size, Clear, Empty
	cout << "Size of multimap: " << mmap.size() << endl;
	mmap.clear();
	cout << "After clearing, is empty? " << (mmap.empty() ? "Yes" : "No") << endl;
	cout << "--------------------------------------------------------" << endl;

	return 0;
}
