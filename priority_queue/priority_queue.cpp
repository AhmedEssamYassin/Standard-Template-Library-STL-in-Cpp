#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Priority Queue (Max Heap & Min Heap) using STL

- A priority queue is a container that provides constant time retrieval of the largest (or smallest) element.
- Internally, it is implemented as a **heap (binary heap)**.
- By default, `priority_queue` is a **max heap** (largest element at the top).
- A **min heap** can be created using `greater<T>` comparator.

Methods:
--------
push(value): Inserts a value into the priority queue - O(log N)
pop(): Removes the top element - O(log N)
top(): Returns the top element without removing it - O(1)
size(): Returns the number of elements - O(1)
empty(): Returns true if the priority queue is empty, otherwise false - O(1)
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE

	// Max Heap (Default)
	priority_queue<int> maxHeap;

	maxHeap.push(10);
	maxHeap.push(30);
	maxHeap.push(20);
	maxHeap.push(5);

	cout << "Max Heap Elements (largest to smallest):\n";
	while (!maxHeap.empty())
	{
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Min Heap (Using greater<int>)
	priority_queue<int, vector<int>, greater<int>> minHeap;

	minHeap.push(10);
	minHeap.push(30);
	minHeap.push(20);
	minHeap.push(5);

	cout << "Min Heap Elements (smallest to largest):\n";
	while (!minHeap.empty())
	{
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Custom Comparator (Max Heap using Pair)
	priority_queue<pair<int, int>> pairMaxHeap;

	pairMaxHeap.push({1, 100});
	pairMaxHeap.push({2, 200});
	pairMaxHeap.push({3, 50});

	cout << "Max Heap (Pairs):\n";
	while (!pairMaxHeap.empty())
	{
		cout << "(" << pairMaxHeap.top().first << ", " << pairMaxHeap.top().second << ") ";
		pairMaxHeap.pop();
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// Custom Comparator (Min Heap using Pair)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pairMinHeap;

	pairMinHeap.push({1, 200});
	pairMinHeap.push({2, 50});
	pairMinHeap.push({3, 100});

	cout << "Min Heap (Pairs):\n";
	while (!pairMinHeap.empty())
	{
		cout << "(" << pairMinHeap.top().first << ", " << pairMinHeap.top().second << ") ";
		pairMinHeap.pop();
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	return 0;
}
