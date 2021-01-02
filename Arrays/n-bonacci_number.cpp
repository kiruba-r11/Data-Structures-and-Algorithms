#include <iostream>
#include <vector>
#define endl "\n";
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Sliding Window

*/

// Function to print n-bonacci numbers
void print_n_bonacci(int n , int m) {

	// Create a vector of size m
	vector <int> arr(m);

	// First n - 1 numbers are 0 and nth number is 1
	for(int i = 0; i < n - 1; i++)
		arr[i] = 0;
	arr[n - 1] = 1;

	// Current sum of the window is 1
	int curr_sum = 1;

	int start = 0;

	// Use the sliding window technique
	for(int i = n; i < m; i++) {
		arr[i] = curr_sum;
		curr_sum += arr[i] - arr[start];
		start++;
	}

	// Print the elements of n-bonacci terms
	for(auto i: arr)
		cout << i << " ";
	cout << endl;
}

int main() {

	int n;

	cout << "Enter the value of n to perform n-bonacci : " << endl;
	cin >> n;

	int m;

	cout << "Enter the no. of terms to print : " << endl;
	cin >> m;

	// Function call to print n-bonacci numbers
	print_n_bonacci(n , m);

	return 0;
}