#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(nlogn)
Space Complexity : O(1)

Approach - Binary Search

*/

// Function to return true if a pair with given difference exists, else false
bool find_pair_with_difference(vector <int> arr , int diff) {

	// The approach is to sort the array first, then for every element, binary search for the second element
	// such that the difference between the two is the given difference

	sort(arr.begin() , arr.end());
	for(int i = 0; i < arr.size(); i++) {

		// For every element, binary search the second element
		int low = i + 1 , high = arr.size() - 1;
		while(low <= high) {
			int mid = low + (high - low) / 2;

			// If the pair with given difference is found
			if(arr[mid] - arr[i] == diff)
				return true;

			// If the difference is greater, then the second element should be small, therefore we need to traverse to the left part 
			else if(arr[mid] - arr[i] > diff)
				high = mid - 1;

			// If the difference is smaller, then the second element should be large, therefore we need to traverse to the right part
			else
				low = mid + 1;
		}
	}

	// Return the invalid case
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

	int diff;

	cout << "Enter the difference : " << endl;
	cin >> diff;

	// Function Call to find if a pair exists with given difference
	bool check = find_pair_with_difference(arr , diff);

	// Invalid Case
	if(!check)
		cout << "There is no pair with given difference" << endl;
	else
		cout << "There exists a pair with given difference" << endl;

	return 0;
}