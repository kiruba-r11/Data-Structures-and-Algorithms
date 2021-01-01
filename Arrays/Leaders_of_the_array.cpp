#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Leader : An element is a leader if it does not have any elements greater than it to its right in the array
Approach : Traverse the array from right to left

*/

// Function to print the leaders of the array
void print_leaders(vector <int> arr) {

	// Rightmost element in the array is always a leader
	int curr_leader = arr[arr.size() - 1];

	cout << "Leaders of the array are : " << curr_leader << " ";

	// Traversing the array from right to left and if an element is greater than the curr_leader, than it also a leader and update new curr_leader
	for(int i = arr.size() - 2; i >= 0; i--) {

		if(arr[i] > curr_leader) {
			curr_leader = arr[i];
			cout << curr_leader << " ";
		}
	}

	cout << endl;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to print the leaders of the array
	print_leaders(arr);

	return 0;
}