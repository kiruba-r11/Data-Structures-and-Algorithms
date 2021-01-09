#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(nlogn)
Space Complexity : O(1)

Approach : Binary Search

*/

// Function to return the count of pairs with given difference
int find_count_of_pairs(vector <int> arr , int diff) {

	int pair_count = 0;

	// Sort the array first, and for each element, binary search the second element such that the difference of that pair is equal to the given difference
	// If such a pair is found, increment the count and proceed further

	sort(arr.begin() , arr.end());

	for(int i = 0; i < arr.size(); i++) {

		// For every element, binary search the second element
		int low = 0 , high = arr.size() - 1;
		while(low <= high) {
			int mid = low + (high - low) / 2;

			// If such pair is found, increment the count
			if(arr[mid] - arr[i] == diff) {
				pair_count++;
				break;
			}

			// If the difference is greater, then the second element should be small, therefore we need to traverse to the left part 
			else if(arr[mid] - arr[i] > diff)
				high = mid - 1;

			// If the difference is smaller, then the second element should be large, therefore we need to traverse to the right part
			else
				low = mid + 1;
		}
	}

	// Return the count
	return pair_count;
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

	// Function Call to find the count of pairs with given difference
	int pair_count = find_count_of_pairs(arr , diff);

	cout << "The count of pairs with given difference is : " << pair_count << endl;

	return 0;
}