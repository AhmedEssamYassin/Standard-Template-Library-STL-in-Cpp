#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Custom Hash for Unordered Map & Unordered Set

- The default hashing function in `unordered_map` and `unordered_set` is weak.
- In competitive programming (e.g., Codeforces), adversarial test cases can force worst-case O(N) performance due to hash collisions.
- This can lead to **Time Limit Exceeded (TLE)** or **unexpected behavior**.

Solution:
---------
- We use a **custom hash function** to introduce randomness and prevent hash collisions.
- Uses **SplitMix64** hashing for strong randomness properties.
- Works for **both integers and pairs**.

Methods:
--------
custom_hash: Implements the custom hashing function.
unordered_map<Key, Value, custom_hash>: Hash map using custom hash.
unordered_set<Key, custom_hash>: Hash set using custom hash.
*/

struct custom_hash
{
	static uint64_t splitmix64(uint64_t x)
	{
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const
	{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE

	// Declaration of unordered_map with custom hash
	unordered_map<ll, ll, custom_hash> umap;
	umap[1] = 100;
	umap[2] = 200;
	umap[3] = 300;

	cout << "Unordered Map Elements:\n";
	for (const auto &p : umap)
		cout << p.first << ": " << p.second << endl;
	cout << "--------------------------------------------------------" << endl;

	// Declaration of unordered_set with custom hash
	unordered_set<ll, custom_hash> uset;
	uset.insert(5);
	uset.insert(10);
	uset.insert(15);

	cout << "Unordered Set Elements:\n";
	for (const ll &x : uset)
		cout << x << " ";
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	return 0;
}
