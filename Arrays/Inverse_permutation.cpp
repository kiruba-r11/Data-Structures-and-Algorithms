#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to perform inverse permutation
vector <int> inverse_permutation(vector <int> arr) {

	// An array with permutation of n integers is given
	// Inverse permutation means, the arr[i]th element in index i, should be as ith element in arr[i]th index

	vector <int> inv(arr.size());

	for(int i = 0; i < arr.size(); i++)
		inv[arr[i] - 1] = i + 1;

	return inv;
}

int main() {

	int n;
	
	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to perform inverse permutation
	vector <int> inv = inverse_permutation(arr);

	cout << "The array is : ";

	// Displaying the array elements
	for(auto i: inv)
		cout << i << " ";
	cout << endl;

	return 0;
}