#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Sliding Window

Constraints of this question : The given array is unsorted and consists of non-negative integers

*/

// Function to return true if there exists a subarray with given sum
bool is_subarray_with_given_sum(vector <int> arr , int sum) {

	// Starting and ending index of the subarray
	int start = 0 , end = 1;

	int subarray_sum = arr[0];

	for(; end < arr.size(); end++) {

		// Cleaning the reduntant elements from the sum
		while(subarray_sum > sum && start < end) {
			subarray_sum -= arr[start];
			start++;
		}

		// If the subarray sum is less, add the current element
		if(subarray_sum < sum) {
			subarray_sum += arr[end];
		} 

		// Valid Case
		if(subarray_sum == sum)
			return true;
	}

	// Cleaning the reduntant elements from the sum
	while(subarray_sum > sum && start < end) {
		subarray_sum -= arr[start];
		start++;
	}

	// Valid Case
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

	int sum;

	cout << "Enter the sum to find if such a subarray exists : " << endl;
	cin >> sum;

	// Function Call to find if there exists a subarray with given sum
	bool check = is_subarray_with_given_sum(arr , sum);

	if(check)
		cout << "There exists such a subarray with given sum" << endl;
	else
		cout << "There is no such subarray with given sum" << endl;

	return 0;
}