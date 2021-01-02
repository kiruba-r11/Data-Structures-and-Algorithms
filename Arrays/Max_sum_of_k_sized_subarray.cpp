#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Sliding Window

*/

// Function to return the maximum sum of the k sized subarray
int find_max_sum(vector <int> arr , int k) {

	int max_sum = 0;

	int curr_sum = 0;

	// A window is considered to be k - sized block.
	// The elements of this block ranges from 0 to k - 1, then 1 to k, then 2 to k + 1, so on....
	// For each window we find the current sum and we find the maximum sum of all those current sums
	// Since, this window is moving towards right, step by step, it is visualised as sliding 
	// Therefore, this approach is called as Sliding Window Approach

	// Traverse the array from 0 to k - 1 and find the current sum of the window
	for(int i = 0; i < k; i++)
		curr_sum += arr[i];

	max_sum = max(max_sum , curr_sum);

	// Starting index of the window currently
	int start = 0;

	// Traverse the array from k to size - 1 and slide the window
	for(int i = k; i < arr.size(); i++) {
		curr_sum += arr[i] - arr[start];
		max_sum = max(max_sum , curr_sum);
		start++;
	}

	// Return the maximum sum
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

	int k;

	cout << "Enter the value of k : " << endl;
	cin >> k;

	// Function Call to find the max sum of k sized subarray
	int max_sum = find_max_sum(arr , k);

	cout << "The maximum sum of the k sized subarray is : " << max_sum << endl;

	return 0;
}