#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer) - Lower Bound

*/

// Function to return the last occurence of the key if present, else -1
int find_first_occurence(vector <int> arr , int key) {

	// Considering the size of array is the last occurence initially
	int last_occurence = arr.size();

	// Here the simple approach is to find the lower bound of key + 1 which will be the last occurence + 1 of the key
	key++;

	// Perform Binary Search (Iterative)
	int low = 0 , high = arr.size() - 1;

	// To check whether original key is found
	bool check = false;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] == key - 1)
			check = true;
		if(arr[mid] >= key) {
			last_occurence = mid;

			// Skipping the right part of the array
			high = mid - 1;
		}
		else 
			// Skipping the left part of the array
			low = mid + 1;
	}

	// Return the valid last occurence index
	if(!check)
		return -1;
	return last_occurence - 1;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	// The array is sorted
	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int key;

	cout << "Enter the key to search its last occurence : " << endl;
	cin >> key;

	// Function Call to find the last occurence of key if its present in the array
	int index = find_first_occurence(arr , key);

	// Invalid index
	if(index == -1)
		cout << "The key is not present in the array" << endl;
	else
		cout << "The last occurence of the key is at index : " << index << endl;

	return 0;
}