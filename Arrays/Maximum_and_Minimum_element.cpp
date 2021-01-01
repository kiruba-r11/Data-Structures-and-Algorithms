#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to return the maximum element
int find_max(vector <int> arr) {

	// Consider the first element to be the maximum element
	int max_element = arr[0];

	// Traverse through the array from index 1 to size - 1 and update the maximum element
	for(int i = 1; i < arr.size(); i++) {
		if(max_element < arr[i])
			max_element = arr[i];
	}

	// Return the maximum element
	return max_element;
}

// Function to return the minimum element
int find_min(vector <int> arr) {

	// Consider the first element to be the minimum element
	int min_element = arr[0];

	// Traverse through the array from index 1 to size - 1 and update the minimum element
	for(int i = 1; i < arr.size(); i++) {
		if(min_element > arr[i])
			min_element = arr[i];
	}

	// Return the minimum element
	return min_element;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the max element
		int max_element = find_max(arr);
	// Function Call to find the min element
		int min_element = find_min(arr);

	cout << "The maximum element in the array is : " << max_element << endl;
	cout << "The minimum element in the array is : " << min_element << endl;

	return 0;
}