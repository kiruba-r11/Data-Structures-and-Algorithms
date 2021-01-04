#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

*/

// Function to return the pairs that result in odd when xor is performed
int count_odd_xor_pairs(vector <int> arr) {

	int pairs = 0;

	// Property of XOR
	// 0 ^ 0 or 1 ^ 1 = 0
	// 1 ^ 0 or 0 ^ 1 = 1
	// Now, for an odd number, the LSB should be set, which means a pair results in odd XOR is one number is even and other is odd

	int even = 0 , odd = 0;
	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] & 1)
			odd++;
		else
			even++;
	}

	// Return the pair count
	pairs = odd * even;
	return pairs;
}

int main() {

	int n;
	
	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the pairs that result in odd when xor is performed
	int cnt_pairs = count_odd_xor_pairs(arr);

	cout << "The no. of pairs resulting odd when XOR is performed is : " << cnt_pairs << endl;

	return 0;
}