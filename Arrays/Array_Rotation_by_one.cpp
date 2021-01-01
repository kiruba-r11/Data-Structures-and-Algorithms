#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to left rotate the array
void left_rotate_by_one(vector <int> &arr) {

	// Store the first element of the array
	int cache = arr[0];

	// Left Shift the array by one from index 1 to size - 1
	for(int i = 1; i < arr.size(); i++) {
		arr[i - 1] = arr[i];
	}

	// Store the cache in the last element of the array
	arr[arr.size() - 1] = cache;
}

// Function to right rotate the array
void right_rotate_by_one(vector <int> &arr) {

	// Store the last element of the array
	int cache = arr[arr.size() - 1];

	// Rigth Shift the array by one from index 1 to size - 1
	for(int i = arr.size() - 1; i >= 0; i--) {
		arr[i] = arr[i - 1];
	}

	// Store the cache in the first element of the array
	arr[0] = cache;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int choice;

	cout << "Choose your choice of input : " << endl;
	cout << "	1. Left Rotate Array by One" << endl;
	cout << " 	2. Right Rotate Array by One" << endl;
	cout << "Input here : ";
	cin >> choice;

	if(choice == 1)
		// Function Call to Left Rotate the array
		left_rotate_by_one(arr);
	else if(choice == 2)
		// Function Call to Right Rotate the array
		right_rotate_by_one(arr);
	else
		cout << "Invalid option choosed" << endl;

	cout << "The modified array is : ";

	// Displaying the modified array
	for(auto i: arr)
		cout << i << " ";
	cout << endl;

	return 0;
}