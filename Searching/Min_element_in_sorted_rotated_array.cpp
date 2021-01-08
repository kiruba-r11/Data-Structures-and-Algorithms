#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Space Complexity : O(1)

Approach : Binary Search

*/

// Function to return the minimum element of the sorted rotated array
int find_min_element(vector <int> arr) {

	// The approach is to operate into the unsorted part of the array, 
	// as it is evident that the first element of the sorted part is always going to be the min,
	// so we can skip that half of the array

	int low = 0 , high = arr.size() - 1;

	// Considering the first element to the min element
	int min_element = arr[0];

	while(low <= high) {
		int mid = low + (high - low) / 2;
		min_element = min(min_element , arr[mid]);

		// If left part is the sorted one
		if(arr[low] <= arr[mid]) {
			min_element = min(arr[low] , min_element);

			// Move to the right part of the array
			low = mid + 1;
		}

		// If the right part is the sorted one
		else {
			min_element = min(arr[high] , min_element);

			// Move to the left part of the array
			high = mid - 1;
		}
	}

	// Return the minimum element of the sorted rotated array
	return min_element;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the sorted rotated array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the minimum element of the sorted rotated array 
	int min_element = find_min_element(arr);

	cout << "The minimum element in the sorted rotated array is : " << min_element << endl;

	return 0;
}