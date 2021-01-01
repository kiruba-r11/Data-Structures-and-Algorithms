#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Reversal

*/

void reverse(vector <int> &arr , int i , int j) {

	// Two pointer approach
	while(i < j) {

		// Swap the values of the pointers
		swap(arr[i] , arr[j]);

		// Update the pointers
		i++;
		j--;
	}
}

// Function to left rotate the array by d
void left_rotate_by_d(vector <int> &arr , int d) {

	int n = arr.size();

	// If d >= n, it can always be proved that the changes made is always equal to the changes made when d = d % n
	if(d >= n)
		d = d % n;

	// If d == 0, there is not going to be any changes
	if(d != 0) {

		// Reverse the first d elements
		reverse(arr , 0 , d - 1);

		// Reverse the next n - d elements
		reverse(arr , d , n - 1);

		// Reverse the whole array
		reverse(arr , 0 , n - 1);
	}

}

// Function to right rotate the array by d
void right_rotate_by_d(vector <int> &arr , int d) {

	int n = arr.size();

	// If d >= n, it can always be proved that the changes made is always equal to the changes made when d = d % n
	if(d >= n)
		d = d % n;

	// If d == 0, there is not going to be any changes
	if(d != 0) {

		// Reverse the last d elements
		reverse(arr , n - d , n - 1);

		// Reverse the first n - d elements
		reverse(arr , 0 , n - d - 1);

		// Reverse the whole array
		reverse(arr , 0 , n - 1);
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

	int d;

	cout << "Enter the value of d : " << endl;
	cin >> d;

	int choice;

	cout << "Choose your choice of input : " << endl;
	cout << "	1. Left Rotate Array by One" << endl;
	cout << " 	2. Right Rotate Array by One" << endl;
	cout << "Input here : ";
	cin >> choice;

	if(choice == 1)
		// Function Call to Left Rotate the array
		left_rotate_by_d(arr , d);
	else if(choice == 2)
		// Function Call to Right Rotate the array
		right_rotate_by_d(arr , d);
	else
		cout << "Invalid option choosed" << endl;

	cout << "The modified array is : ";

	// Displaying the modified array
	for(auto i: arr)
		cout << i << " ";
	cout << endl;

	return 0;
}