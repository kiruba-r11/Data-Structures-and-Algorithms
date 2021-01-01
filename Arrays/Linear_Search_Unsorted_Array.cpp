#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Linear Search

*/

// Function to return the index of the key if found, else -1
int linear_search(vector <int> arr , int key) {

	// Traverse the array to search the key
	for(int i = 0; i < arr.size(); i++) {

		// If the key is found, return its index
		if(key == arr[i])
			return i;
	} 

	// If key was not found
	return -1;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int key;

	cout << "Enter the key to search : " << endl;
	cin >> key;

	// Function Call to search the index of the key
	int index = linear_search(arr , key);

	// Invalid index
	if(index == -1)
		cout << "Key was not found in the array" << endl;
	else
		cout << "Key was found in the array at the index : " << index << endl;

	return 0;
} 