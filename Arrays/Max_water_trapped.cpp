#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to return thr maximum amount of water that can be trapped
int find_max_water_trapped(vector <int> arr) {

	int n = arr.size();

	// The left and right most element of the array cannot trap water because there are no bounds for it and water would flow down
	// Therefore, traverse the array from index 1 to size - 2
	// The maximum bound for an element is the minimum of maximum element of left and right of that element 
	// Subtracting the current element from the maximum bound gives the maximum amount of water that can be trapped for that particular index

	// We precompute the left and right max for every index
	vector <int> left_max(n) , right_max(n);

	left_max[0] = arr[0];
	right_max[0] = arr[n - 1];

	int max_water_trapped = 0;

	for(int i = 1; i < n; i++) {
		left_max[i] = max(left_max[i - 1] , arr[i]);
		right_max[i] = max(right_max[i - 1] , arr[n - i - 1]);
	}

	for(int i = 1; i < n - 1; i++) {
		int trapped = (min(left_max[i - 1] , right_max[n - i - 2]) - arr[i]) > 0 ? (min(left_max[i - 1] , right_max[n - i - 2]) - arr[i]) : 0;
		max_water_trapped += trapped;
	}

	// Return the maximum amount of water trapped
	return max_water_trapped;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the maximum amount of water that can be trapped
	int max_water_trapped = find_max_water_trapped(arr);

	cout << "The maximum amount of water that can be trapped is : " << max_water_trapped << endl;

	return 0;
}