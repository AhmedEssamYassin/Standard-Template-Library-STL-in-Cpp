#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Doubly Linked List Implementation

Dynamic Size (Can grow and shrink as needed)
Efficient Insertions and Deletions (O(1) for adding/removing from front/back)
Bidirectional Iteration (Forward and Reverse Traversal)
No Random Access (Unlike array or vector, elements are not stored sequentially)

Methods:
--------
begin(): returns an iterator to the first element in the list - O(1)
end(): returns an iterator to the last element in the list (past-the-end) - O(1)
rbegin(): returns a reverse iterator to the last element - O(1)
rend(): returns a reverse iterator to the position before the first element - O(1)
front(): returns the first element in the list - O(1)
back(): returns the last element in the list - O(1)
size(): returns the size of the list - O(1)
empty(): returns true if the list is empty, otherwise, returns false - O(1)
push_back(value): adds an element to the end of the list - O(1)
push_front(value): adds an element to the front of the list - O(1)
pop_back(): removes the last element from the list - O(1)
pop_front(): removes the first element from the list - O(1)
insert(iterator, value): inserts a value at the specified iterator position - O(1)
erase(iterator): removes element at the specified iterator position - O(1)
remove(value): removes all elements with the given value - O(N)
reverse(): reverses the list - O(N)
sort(): sorts the list in ascending order - O(N log N)
swap(list<T>& other): swaps the elements of two lists - O(1)
clear(): removes all elements from the list - O(N)
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	list<int> myList{10, 10, 5, 20, 15, 25};
	cout << "Front: " << myList.front() << endl;				  // Prints 10
	cout << "Back: " << myList.back() << endl;					  // Prints 25
	cout << "Size: " << myList.size() << endl;					  // Prints 6
	cout << "Empty: " << (myList.empty() ? "Yes" : "No") << endl; // Prints No

	// Traversing the list using iterators
	cout << "Elements: ";
	for (auto it = myList.begin(); it != myList.end(); ++it)
		cout << *it << " ";
	cout << endl;

	myList.sort(); // Sorting the list
	cout << "After sorting: ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	myList.push_front(99);
	myList.push_back(-1);
	cout << "After push_front(99) and push_back(-1): ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	myList.reverse(); // Reversing the list
	cout << "After reverse(): ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	auto it = myList.begin();
	advance(it, 2);
	myList.insert(it, 42); // Insert 42 at the 3rd position
	cout << "After insert(42 at 3rd position): ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	it = myList.begin();
	advance(it, 4);
	myList.erase(it); // Erase the 5th element
	cout << "After erase(5th element): ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	myList.remove(10); // Remove all occurrences of 10
	cout << "After remove(10): ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	myList.pop_front();
	cout << "After pop_front(): ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	myList.pop_back();
	cout << "After pop_back(): ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	list<int> newList{1, 2, 3};
	myList.swap(newList);

	cout << "Elements of myList after swap: ";
	for (const int &x : myList)
		cout << x << " ";
	cout << endl;

	cout << "Elements of newList after swap: ";
	for (const int &x : newList)
		cout << x << " ";
	cout << endl;

	myList.clear();
	cout << "After clear(): " << (myList.empty() ? "List is empty" : "List is not empty") << endl;

	return 0;
}
