#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Unordered Map Implementation (STL unordered_map)

- Stores key-value pairs (Associative container).
- Uses Hash Table for fast lookup.
- Provides **average O(1) complexity** for insertion, deletion, and search.
- Elements are stored **unordered** (No specific order).
- **Keys must be unique** (Use unordered_multimap for duplicate keys).
- Collision handling is done via **chaining** (linked lists in buckets).

Methods:
--------
begin(): returns an iterator to the first element in the unordered_map - O(1)
end(): returns an iterator to the position past the last element - O(1)
size(): returns the number of key-value pairs in the map - O(1)
empty(): returns true if the map is empty, otherwise false - O(1)
at(key): returns the value associated with the given key (throws error if key does not exist) - O(1)
operator[](key): returns reference to value, inserts default if key does not exist - O(1)
insert({key, value}): inserts a key-value pair into the map - O(1) (amortized)
erase(key): removes the element with the given key - O(1) (amortized)
find(key): returns an iterator to the key-value pair if found, otherwise end() - O(1) (amortized)
count(key): returns 1 if key exists, otherwise 0 - O(1)
swap(other): swaps the contents with another unordered_map - O(N)
clear(): removes all elements from the map - O(N)
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
	unordered_map<string, int> umap;

	// Inserting elements
	umap["apple"] = 50;
	umap["banana"] = 30;
	umap.insert({"cherry", 20});
	umap.insert({"date", 40});

	// Traversing unordered_map (No order)
	cout << "Unordered Map Elements:\n";
	for (const auto &p : umap)
		cout << p.first << ": " << p.second << endl;
	cout << "--------------------------------------------------------" << endl;

	// Accessing Elements
	cout << "Price of Apple: " << umap["apple"] << endl;
	cout << "Price of Cherry: " << umap.at("cherry") << endl;

	// Handling non-existent keys
	// cout << umap.at("mango"); // Throws exception (out_of_range)
	cout << "--------------------------------------------------------" << endl;

	// Checking if key exists
	if (umap.find("banana") != umap.end())
		cout << "Banana exists in map\n";

	if (umap.count("mango") == 0)
		cout << "Mango does not exist\n";
	cout << "--------------------------------------------------------" << endl;

	// Erasing Elements
	umap.erase("banana");
	cout << "After erasing banana:\n";
	for (const auto &p : umap)
		cout << p.first << ": " << p.second << endl;
	cout << "--------------------------------------------------------" << endl;

	// Swapping with another unordered_map
	unordered_map<string, int> newUmap = {{"grape", 60}, {"orange", 45}};
	umap.swap(newUmap);

	cout << "Elements of umap after swap: ";
	for (const auto &p : umap)
		cout << p.first << ": " << p.second << endl;
	cout << endl;

	cout << "Elements of newUmap after swap: ";
	for (const auto &p : newUmap)
		cout << p.first << ": " << p.second << endl;
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Size, Clear, Empty
	cout << "Size of map: " << umap.size() << endl;
	umap.clear();
	cout << "After clearing, is empty? " << (umap.empty() ? "Yes" : "No") << endl;
	cout << "--------------------------------------------------------" << endl;

	// Hash Table Properties
	unordered_map<int, string> umap2 = {{1, "One"}, {2, "Two"}, {3, "Three"}};

	cout << "Number of Buckets: " << umap2.bucket_count() << endl;
	cout << "Load Factor: " << umap2.load_factor() << endl;
	cout << "Rehashing to 10 buckets...\n";
	umap2.rehash(10);
	cout << "New Bucket Count: " << umap2.bucket_count() << endl;
	cout << "--------------------------------------------------------" << endl;

	return 0;
}
