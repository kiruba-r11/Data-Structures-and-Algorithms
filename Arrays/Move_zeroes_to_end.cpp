#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to move all the zeroes to end 
void move_zeroes_to_end(vector <int> &arr) {

	int index = -1;

	// Traverse through the array
	for(int i = 0; i < arr.size(); i++) {

		// If a non-zero element occurs, swap it with the (index + 1)th element
		if(arr[i] != 0) {
			index++;
			swap(arr[i] , arr[index]);
		}
	}
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to move all the zeroes to end without replcaing the relative order of elements
	move_zeroes_to_end(arr);

	cout << "The modified array is : ";

	// Displaying the array elements
	for(auto i: arr)
		cout << i << " ";
	cout << endl;

	return 0;
}