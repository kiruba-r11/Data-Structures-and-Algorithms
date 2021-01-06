#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer) - Lower Bound

*/

// Function to return the index of transition point if it exists, else -1
int find_transition_point(vector <int> arr) {

	// We have to find the transition point, the point in the sorted binary array when 0 changed to 1
	// In simpler terms, we need to find the first occurence of 1 in the array which we can find using the lower bound approach

	int transition_point = arr.size();

	int low = 0 , high = arr.size() - 1;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(arr[mid] >= 1) {
			transition_point = mid;
			high = mid - 1;
		}
		else 
			low = mid + 1;
	}

	// Invalid Case
	if(transition_point == arr.size())
		return -1;

	// Return the valid transition point
	return transition_point;

}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	// The array is sorted and binary, i.e. contains values [0 , 1] only
	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the transition of binary array from 0 to 1
	int index = find_transition_point(arr);

	// Invalid Case
	if(index == -1)
		cout << "There is no transistion point present in the array" << endl;
	else
		cout << "The transition point of the array is at the index : " << index << endl;

	return 0;
}