#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer) 

*/

// Function to return the index of the peak element
int find_peak_element(vector <int> arr) {

	int low = 0 , high = arr.size() - 1;
	int n = arr.size();

	while(low <= high) {
		int mid = low + (high - low) / 2;

		// Corner elements
		if(mid == 0) {
			if(arr[mid] >= arr[mid + 1])
				return mid;
		}
		else if(mid == n - 1) {
			if(arr[mid] >= arr[mid - 1])
				return mid;
		}
		else {
			if(arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
				return mid;
		}

		// Move to the left part of the array
		if(mid > 0 && arr[mid - 1] >= arr[mid])
			high = mid - 1;	
		// Move to the right part of the array
		else
			low = mid + 1;
	}

	// Return an invalid index, but this will be executed
	return -1;
}

// Function to return the index of the key in the bitonic array if it is present, else -1
int find_key_in_bitonic_array(vector <int> arr , int key) {

	// A bitonic array is an array which increases monotonically first and then decreases
	// Therefore, there exists a point where the element starts decreasing
	// That point will be the peak element of the bitonic array
	// Proof : [a1 , a2 , .... ai , ai+1 , ai+2 , ... an]
	// Here, a1 <= a2 <= a3 <= .... <= ai, then ai >= ai+1 >= ai+2 >= .... >= an
	// It is observed that ai is the max element because, the series increases till ai and then starts decreasing from ai+1
	// Hence, it can be proved that ai >= ai-1 and ai>= ai+1 which is the max element, and of course the peak element

	// So the approach is to split the array into two parts based on the peak such that the first part is sorted in non-decreasing order and the other in non-increasing order

	int index = find_peak_element(arr);

	// Now, perform Binary Search for both parts

	// This is for first part, where the array is sorted in non-decreasing order
	int low = 0 , high = index;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(arr[mid] == key)
			return mid;
		else if(arr[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}

	// This is for second part, where the array is sorted in non-increasing order
	low = index + 1 , high = arr.size() - 1;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(arr[mid] == key)
			return mid;
		else if(arr[mid] > key)
			low = mid + 1;
		else
			high = mid - 1;
	}

	// Return invalid index, if the key is not found
	return -1; 
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the bitonic array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int key;

	cout << "Enter the key to search : " << endl;
	cin >> key;

	// Function Call to search for a key in a bitonic array 
	int index = find_key_in_bitonic_array(arr , key);

	// Invalid index
	if(index == -1)
		cout << "The key is not found in the array" << endl;
	else
		cout << "The key is found in the array at the index : " << index << endl;

	return 0;
}