#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Space Complexity : O(1)

Approach : Binary Search

*/

// Function to return the maximum element in the sorted rotated array
int find_max_element(vector <int> arr) {

	// The approach is to operate into the unsorted part of the array, 
	// as it is evident that the first element of the sorted part is always going to be the min,
	// so we can skip that half of the array

	int low = 0 , high = arr.size() - 1;

	// Considering the first element to the max element
	int max_element = arr[0];

	while(low <= high) {
		int mid = low + (high - low) / 2;
		max_element = max(max_element , arr[mid]);

		// If left part is the sorted one
		if(arr[low] <= arr[mid]) {
			max_element = max(max_element , arr[low]);

			// Move to the right part of the array
			low = mid + 1;
		}

		// If right part is the sorted one
		else {
			max_element = max(max_element , arr[high]);

			// Move to the left part of the array
			high = mid - 1;
		}
	}

	// Return the maximum element of the sorted rotated array
	return max_element;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the sorted rotated array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the maximum element in the sorted rotated array
	int max_element = find_max_element(arr);

	cout << "The maximum element in the sorted rotated array is : " << max_element << endl;

	return 0;
}