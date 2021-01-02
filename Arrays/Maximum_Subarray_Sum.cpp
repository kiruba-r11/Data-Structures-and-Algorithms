#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Kadane's Algorithm

*/

// Function to return the maximum subarray sum
int find_max_subarray_sum(vector <int> arr) {

	int max_sum = INT_MIN;

	int curr_sum = 0;

	// Traverse the array
	for(int i = 0; i < arr.size(); i++) {

		// curr_sum is maximum of current element and the subarray with some starting index till i
		curr_sum = max(arr[i] , curr_sum + arr[i]);

		// Maximum of max_sum and curr_sum
		max_sum = max(max_sum , curr_sum);
	}

	// Return the maximum subarray sum
	return max_sum; 
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the maximum subarray sum
	int max_sum = find_max_subarray_sum(arr);

	cout << "The maximum subarray sum is : " << max_sum << endl;

	return 0;
}