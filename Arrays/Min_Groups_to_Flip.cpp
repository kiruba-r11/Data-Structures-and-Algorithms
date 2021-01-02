#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to return the minimum flips required to make the binary array contain same elements
int find_min_group_flips(vector <int> arr) {

	// There are two conditions to note here :
	// Case - 1 : If the starting and ending element of the array is equal, 
	// 			  then that element group occurs for one extra time
	// Case - 2 : If the starting and ending element of the array is different,
	// 			  then both element groups occurs same no. of times

	// Example for case - 1 : 111001100111 -> Here, 1 has 3 groups and 0 has 2 groups
	// Example for case - 2 : 000111100011 -> Here, 1 has 2 groups and 0 has 2 groups 

	// Therefore, 
	// 		for case - 1 : we have to flip the groups that is not starting
	// 		for case - 2 : we can flip any group

	int min_flips = 0;

	// Let it be the element to flip (either 0 or 1)
	int element;

	// Case - 1 :
	if(arr[0] == arr[arr.size() - 1]) {
		element = arr[0] == 0 ? 1 : 0;
	}
	// Case - 2 :
	else {
		element = arr[0];
	}

	// Traverse the array from index 1 to size - 1
	for(int i = 1; i < arr.size(); i++) {

		if(arr[i] != arr[i - 1] && arr[i] != element)
			min_flips++;
	}

	// Return the minimum flips
	return min_flips;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the minimum group flips required to make the binary array contain same elements
	int min_flips = find_min_group_flips(arr);

	cout << "The minimum group flips required is : " << min_flips << endl;

	return 0;
}