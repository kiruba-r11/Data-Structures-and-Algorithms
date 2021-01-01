#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Two Pointer

*/

// Function to reverse the array
void reverse_array(vector <int> &arr) {

	// Two pointers are used for this approach, one pointing to first and other pointing to last element of the array
	int i = 0 , j = arr.size() - 1;

	while(i < j) {

		// Swap the contents of both the pointers
		swap(arr[i] , arr[j]);

		// Update the pointers
		i++;
		j--;
	}

	// Note : i == j occurs only when size of array is odd
	// Interestingly we need not handle this case separately because middle element remains unchanged in both original and reversed array
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to reverse the array
	reverse_array(arr);

	cout << "The modified array is : ";

	// Displaying the array elements
	for(auto i: arr)
		cout << i << " ";
	cout << endl;

	return 0;
}