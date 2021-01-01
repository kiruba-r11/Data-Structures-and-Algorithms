#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Deletion at End : Constant Time - O(1)
Deletion at Beginning : Linear Time - O(n)

*/

// Function to delete the key if found and return the modified size of the array
int delete_element(vector <int> &arr , int key) {

	int index = -1;

	// Search for the key
	for(int i = 0; i < arr.size(); i++) {

		// If key is found, update the index
		if(key == arr[i]) {
			index = i;
			break;
		}
	}

	// If key is not found, return the original array size
	if(index == -1)
		return arr.size();

	// Left Shift the element from index to size - 1
	for(int i = index; i < arr.size() - 1; i++) {
		arr[i] = arr[i + 1];
	}

	// Return the modified array size
	return arr.size() - 1;
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

	cout << "Enter the key to delete from the array : " << endl;
	cin >> key;

	// Function Call to delete the key if found
	int size = delete_element(arr , key);

	// If size is unchanged
	if(size == n)
		cout << "The key was not found in the array" << endl;
	else {

		cout << "The key was deleted and the modified array is : ";

		// Displaying the modified array
		for(int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	return 0; 
}  