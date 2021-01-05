#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer)

*/

// Function to perform iterative binary search
int iterative_binary_search(vector <int> arr , int key) {

	int low = 0 , high = arr.size() - 1;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		// Key is found
		if(arr[mid] == key)
			return mid;

		// Move to left half of the array
		else if(arr[mid] > key)
			high = mid - 1;

		// Move to right half of the array
		else
			low = mid + 1;
	}

	// Return the invalid case
	return -1;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	// The array is sorted
	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int key;

	cout << "Enter the key to search : " << endl;
	cin >> key;

	// Function call to search for key using iterative Binary Search
	int index = iterative_binary_search(arr , key);

	// Invalid index
	if(index == -1)
		cout << "The key is not present in the array" << endl;
	else
		cout << "The key is present in the index : " << index << endl;

	return 0;
}