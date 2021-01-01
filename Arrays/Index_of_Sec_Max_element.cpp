#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to return the index of second maximum element if its exists, else -1
int index_of_sec_max(vector <int> arr) {

	// Consider the first element to be the max
	int max_index = 0;

	int sec_max_index = -1;

	// Traverse the array from index 1 to size - 1
	for(int i = 1; i < arr.size(); i++) {

		if(arr[i] > arr[max_index]) {

			// Update the max_index and sec_max_index
			sec_max_index = max_index;
			max_index = i;
		}
		else if(arr[i] == arr[max_index]) 
			continue;
		else {
			if(sec_max_index == -1)
				// Update the sec_max_index
				sec_max_index = i;
			else if(arr[i] > arr[sec_max_index])
				// Update the sec_max_index
				sec_max_index = i;
		}
	}

	// Return the index of second maximum element
	return sec_max_index;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the index of the second max element
	int index = index_of_sec_max(arr);

	// Invalid index
	if(index == -1)
		cout << "There is no second maximum element in the array" << endl;
	else
		cout << "The second maximum element is located at the index : " << index << endl;

	return 0;
}