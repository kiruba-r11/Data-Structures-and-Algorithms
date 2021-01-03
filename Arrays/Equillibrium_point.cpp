#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

// Approach : Prefix Sum

*/

// Function to return the equillibrium point if it exists, else -1
int find_equillibrium_point(vector <int> arr) {

	int index = -1;
	int n = arr.size();

	// Equillibrium point is a point at which sum of elements before and after that point is equal

	// Traverse the array from index 0 to size - 1
	// Store the prefix sum till index i - 1 and check whether it is equal to total sum - prefix sum - current element

	int left_sum = 0 , sum = 0 , i = 0;

	for(; i < n; i++) 
		sum += arr[i];

	for(i = 0; i < n; i++) {
		if(left_sum == sum - (left_sum + arr[i])) {
			index = i;
			break;
		}
		else {
			left_sum += arr[i];
		}
	}

	if(left_sum == sum - left_sum)
		index = i;

	// Return the index
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

	// Function Call to find the equillibrium point in the array if it exists
	int index = find_equillibrium_point(arr);

	// Invalid index
	if(index == -1)
		cout << "There is no equillibrium point" << endl;
	else
		cout << "The equillibrium point is at index : " << index << endl; 

	return 0;
}