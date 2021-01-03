#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to sort the binary array
void sort_binary_array(vector <int> &arr) {

	// Sorting technique is not used, because it takes O(nlogn) time. This question needs to be solved in O(n)
	// It is very similar to the problem of moving the zeroes to the end. But instead moving it to end, we can move it to the beginning

	int index = -1;
	if(arr[0] == 0)
		index = 0;

	for(int i = 1; i < arr.size(); i++) {
		if(arr[i] == 0) {
			index++;
			swap(arr[i] , arr[index]);
		}
	}
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to sort the binary array
	sort_binary_array(arr);

	cout << "The modified array is : ";

	// Displaying the modified array
	for(auto i: arr)
		cout << i << " ";
	cout << endl;

	return 0;
}