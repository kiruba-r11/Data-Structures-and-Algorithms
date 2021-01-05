#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer) - Lower Bound

*/

// Function to return the first occurence of the key if present, else -1
int find_first_occurence(vector <int> arr , int key) {

	// Considering the size of array is the first occurence initially
	int first_occurence = arr.size();

	// Perform Binary Search (Iterative)
	int low = 0 , high = arr.size() - 1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] >= key) {
			first_occurence = mid;

			// Skipping the right part of the array
			high = mid - 1;
		}
		else 
			// Skipping the left part of the array
			low = mid + 1;
	}

	// Return the valid first occurence index
	if(first_occurence == arr.size())
		return -1;
	return first_occurence;
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

	cout << "Enter the key to search its first occurence : " << endl;
	cin >> key;

	// Function Call to find the first occurence of key if its present in the array
	int index = find_first_occurence(arr , key);

	// Invalid index
	if(index == -1)
		cout << "The key is not present in the array" << endl;
	else
		cout << "The first occurence of the key is at index : " << index << endl;

	return 0;
}