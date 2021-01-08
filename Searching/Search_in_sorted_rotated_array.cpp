#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Space Complexity : O(1)

Approach : Binary Search

*/

// Function to return the index of the key in the sorted rotated array, else -1
int search_in_sorted_rotated_array(vector <int> arr , int key) {

	// It is always guaranteed that any one part of the array is always sorted, (sometimes both the parts can also be sorted)
	// With the above proof, our approach is to find the sorted part of the array.
	// If the key to search is in the range of the sorted part, continue to operate in that range. 
	// Else if the element is present it should surely be present in the other part

	int low = 0 , high = arr.size() - 1;

	while(low <= high) {

		int mid = low + (high - low) / 2;
		if(arr[mid] == key)
			return mid;

		// If left part of the array is sorted
		if(arr[low] <= arr[mid]) {

			// If the key is in the range of the sorted part, continue there
			if(key >= arr[low] && key < arr[mid])
				high = mid - 1;

			// Else continue in the other part
			else
				low = mid + 1;

		}

		// If the right part of the array is sorted
		else {

			// If the key is in the range of the sorted part, continue there
			if(key > arr[mid] && key <= arr[high])
				low = mid + 1;

			// Else continue in the other part
			else
				high = mid - 1;
		}
	}

	// Return the invalid index if the key is not found
	return -1;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the sorted rotated array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int key;

	cout << "Enter the key to search : " << endl;
	cin >> key;

	// Function Call to search the key in the sorted rotated array
	int index = search_in_sorted_rotated_array(arr , key);

	// Invalid index
	if(index == -1)
		cout << "The key is not found in the array" << endl;
	else
		cout << "The key is found at the index : " << index << endl;

	return 0;
}