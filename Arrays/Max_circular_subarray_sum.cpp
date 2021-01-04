#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Kadane's Algorithm

*/

// Function to return the maximum sum of the normal subarray
int find_max_subarray_sum(vector <int> arr) {

	// Kadane's Algorithm
	int max_sum = arr[0];
	int cur_sum = arr[0];
	int n = arr.size();

	for(int i = 1; i < n; i++) {
		cur_sum = max(cur_sum + arr[i] , arr[i]);
		max_sum = max(max_sum , cur_sum);
	}

	// Return the sum
	return max_sum;
}

// Function to return the maximum circular subarray sum
int find_max_circular_subarray_sum(vector <int> arr) {

	// The problem is split into two parts
	// Part 1 : Find the maximum sum of the normal subarray
	// Part 2 : Find the maximum sum of the circular subarray
	// Return the maximum of both the sums

	// The maximum sum of the circular subarray can always be proven as (sum of the total array - minimum sum of the normal subarray)
	// The minimum sum can also be found using the Kadane's Algorithm

	int max_normal_subarray_sum = find_max_subarray_sum(arr);
	int n = arr.size();
	
	// If all the elements in the array are negative
	if(max_normal_subarray_sum < 0)
		return max_normal_subarray_sum;

	int arr_sum = 0;

	// Now instead of writing another modified function to find the minimum sum of the normal subarray, we can invert the elements of the array
	// and find the maximum sum of the normal subarray and then add it to the sum of the total array

	for(int i = 0; i < n; i++) {

		// Calculating the array sum
		arr_sum += arr[i];
		arr[i] *= -1;
	}

	int max_circular_subarray_sum = find_max_subarray_sum(arr) + arr_sum;

	// Return the maximum of normal and circular subarray sum
	return max(max_circular_subarray_sum , max_normal_subarray_sum); 
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to return the maximum circular subarray sum
	int max_sum = find_max_circular_subarray_sum(arr);

	cout << "The maximum circular subarray sum is : " << max_sum << endl;
 
	return 0;
}