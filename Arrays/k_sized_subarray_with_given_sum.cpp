#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Sliding Window

*/

// Function to return true if there exists a subarray with length k such that its sum is equal to the given sum
bool is_subarray_with_given_sum(vector <int> arr , int k , int sum) {

	int subarray_sum = 0;

	// A window is considered to be k - sized block.
	// The elements of this block ranges from 0 to k - 1, then 1 to k, then 2 to k + 1, so on....
	// For each window we find the current sum and we find the maximum sum of all those current sums
	// Since, this window is moving towards right, step by step, it is visualised as sliding 
	// Therefore, this approach is called as Sliding Window Approach

	// Traverse the array from 0 to k - 1 and find the current sum of the window
	for(int i = 0; i < k; i++)
		subarray_sum += arr[i];

	// Starting index of the window currently
	int start = 0;

	// Traverse the array from k to size - 1 and slide the window
	for(int i = k; i < arr.size(); i++) {

		// If such a subarray sum exists
		if(subarray_sum == sum)
			return true;
		
		subarray_sum += arr[i] - arr[start];
		start++;
	}

	// If such a subarray sum exists
	if(subarray_sum == sum)
		return true;

	// Invalid case
	return false;
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

	int sum;

	cout << "Enter the sum of find the if there exists such a subarray : " << endl;
	cin >> sum;

	// Function Call to find whether there exists a subarray with length k and its sum equal to given sum
	bool check = is_subarray_with_given_sum(arr , k , sum);

	if(check)
		cout << "There exists such a subarray" << endl;
	else
		cout << "There is no such subarray" << endl;

	return 0;
}