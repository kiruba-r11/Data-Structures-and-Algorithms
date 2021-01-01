#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Insertion at End : Constant Time - O(1)
Insertion at Beginning : Linear Time - O(n)

*/

// Function to insert the key at a given position if space is available and return the modified size
int insert_at_a_pos(vector <int> &arr , int n , int key , int pos) {

	// If the array is already full
	if(arr.size() == n)
		return n;

	// Right Shift the elements from index pos to size - 1
	for(int i = arr.size(); i >= pos; i--) {
		arr[i] = arr[i - 1];
	}

	// Insert the key at the given position
	arr[pos - 1] = key;

	// Return the modified array size
	return n + 1;
}

int main() {

	int max_capacity;

	cout << "Enter the maximum capacity of the array : " << endl;
	cin >> max_capacity;

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(max_capacity);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int key;

	cout << "Enter the key to insert : " << endl;
	cin >> key;

	int pos;

	cout << "Enter the position to insert : " << endl;
	cin >> pos;

	// Function Call to insert the key at the given position
	int size = insert_at_a_pos(arr , n , key , pos);

	// If size is unchanged
	if(size == n)
		cout << "The array was already full and the element can't be inserted" << endl;
	else {
		cout << "The modified array is : ";

		// Displaying the modified array
		for(int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	return 0;
}