#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

It is required to compute the maximum value of (arr[j] - arr[i]) such that j > i

*/

// Function to compute and return the maximum difference
int maximum_diff(vector <int> arr) {

	// Considering the first element to be the minimum value
	int min_value = arr[0];

	int res = arr[1] - arr[0];

	// Traverse the array from index 1 to size - 1
	for(int i = 1; i < arr.size(); i++) {

		res = max(res , arr[i] - min_value);

		// It is the minimum value from index 0 to i
		min_value = min(min_value , arr[i]);
	}

	// Return the result
	return res;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to compute the maximum difference
	int max_value = maximum_diff(arr);

	cout << "The maximum difference is : " << max_value << endl;

	return 0;
}