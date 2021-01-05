#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer) - Lower Bound

*/

// Function to return the count of 1's
int find_ones_count(vector <int> arr) {

	// The approach is to find the lower bound of 1 in the array
	// Since the array is binary and sorted, if 1 exists in the array, the last element of the array will also be 1

	int lower_bound = arr.size();

	int low = 0 , high = arr.size() - 1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] >= 1) {
			lower_bound = mid;
			high = mid - 1;
		}
		else 
			low = mid + 1;
	}

	int count_ones = 0;

	// If 1 is present in the array
	if(lower_bound != arr.size())
		count_ones = arr.size() - lower_bound;

	// Return the count of 1's
	return count_ones;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	// The array is sorted
	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to count the no. of 1's in sorted array
	int count_ones = find_ones_count(arr);

	cout << "The count of 1's in the sorted array is : " << count_ones << endl;

	return 0;
}