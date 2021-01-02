#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to return the maximum consecutive ones in a Binary array
int find_max_consecutive_ones(vector <int> arr) {

	int max_ones = 0 , curr_max = 0;

	// Traverse the array
	for(int i = 0; i < arr.size(); i++) {

		// If 1 is encountered increment the curr_max
		if(arr[i] == 1) 
			curr_max++;
		// If not, set curr_max to zero
		else
			curr_max = 0;

		// Overall max values if maximum of curr_max and max_ones
		max_ones = max(max_ones , curr_max);
	} 

	// Return the maximum consecutive ones
	return max_ones;
} 

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the maximum consecutive ones in and array
	int max_ones = find_max_consecutive_ones(arr);

	cout << "The maximum consecutive ones in the given array is : " << max_ones << endl;

	return 0;
}