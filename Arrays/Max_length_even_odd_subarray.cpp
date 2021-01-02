#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Kadane's Algorithm (Modification)

*/

// Function ro return the maximum length of alternating even odd subarray
int find_alternating_subarray_max_length(vector <int> arr) {

	// Max Length's minimum value is always 1
	int max_length = 1;

	int curr_length = 1;

	// Traverse the array from index 1 to size - 1
	for(int i = 1; i < arr.size(); i++) {

		// If the previous element is odd, then the current element should be even and vice verse.
		// If this is the case, increment the curr_length
		if((arr[i - 1] & 1 && !(arr[i] & 1)) || (!(arr[i - 1] & 1) && arr[i] & 1))
			curr_length++;
		// Else, it is the start of another subarray
		else
			curr_length = 1;

		// Find the maximum of all the current values
		max_length = max(max_length , curr_length);
	}

	// Return the maximum length
	return max_length;
} 


int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the max length of alternating even odd subarray
	int max_length = find_alternating_subarray_max_length(arr);

	cout << "The maximum length of the alternating even odd subarray is : " << max_length << endl;

	return 0;
}