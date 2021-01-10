#include <iostream>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Auxiliary space

*/

// Function to return the pairs that result in zero when xor is performed
int count_zero_xor_pairs(vector <int> arr) {

	int pairs = 0;

	// Property of XOR
	// 0 ^ 0 or 1 ^ 1 = 0
	// 1 ^ 0 or 0 ^ 1 = 1
	// For zero, all bits should be zero. Which means we need a pair such that all bits should be same to get xor as zero
	// Therefore, we just need to find count of duplicates for a number

	// To store the count of each number
	map <int , int> m;

	int even = 0 , odd = 0;
	for(int i = 0; i < arr.size(); i++) {
		m[arr[i]]++;
	}

	for(auto it = m.begin(); it != m.end(); it++) {
		pairs += it->second * (it->second - 1) / 2;
	}

	// Return the pair count
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

	// Function Call to find the pairs that result in zero when xor is performed
	int cnt_pairs = count_zero_xor_pairs(arr);

	cout << "The no. of pairs resulting zero when XOR is performed is : " << cnt_pairs << endl;

	return 0;
}