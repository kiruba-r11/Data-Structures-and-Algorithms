#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(1)

*/

// Function to rearrange the array, with all negative elements on the left side
void rearrange_array(vector <int> &arr) {

	// The approach is the same which is used for moving all the zeroes to the end
	int index = -1;

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] < 0) {
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

	// Function Call to rearrange the array, with all negative elements on the left side
	rearrange_array(arr);

	cout << "The modified array is : ";

	// Displaying the elements of the array
	for(auto i: arr)
		cout << i << " ";
	cout << endl;

	return 0;
}