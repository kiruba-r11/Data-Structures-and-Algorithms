#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to return the index of the max element
int index_of_max_element(vector <int> arr) {

	// Considering the first element to be the max element
	int index = 0;

	// Traverse through the array and update the max element if possible
	for(int i = 1; i < arr.size(); i++) {

		if(arr[i] > arr[index]) 
			index = i;
	}

	// Return the index of the max element
	return index;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the index of the max element
	int index = index_of_max_element(arr);

	cout << "The maximum element is located at the index : " << index << endl;  

	return 0;
}