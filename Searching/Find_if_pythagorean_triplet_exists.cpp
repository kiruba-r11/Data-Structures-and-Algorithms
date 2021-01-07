#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n ^ 2)
Space Complexity : O(1)

Approach : Two Pointer Algorithm

*/

// Function to return true if a pythagorean triplet exist in the array, else false
bool find_pythagorean_triplet(vector <int> arr) {

	// A pythagorean triplet is three numbers of the form a ^ 2 + b ^ 2 = c ^ 2
	// The approach is to traverse the array from size - 1 to 2 and find a pair using the two pointer method such that the sum is arr[i] ^ 2

	for(int i = arr.size() - 1; i >= 2; i--) {

		// Two pointers, one is first and one is last pointer. 
		// When finding a triplet, we traverse the array from left to right.
		// But here we traverse from right to left so that in each iteration we make sure what the sum of pair is
		int j = 0 , k = i - 1;
		int sum = arr[i] * arr[i];

		while(j < k) {
			int temp = arr[j] * arr[j] + arr[k] * arr[k];
			if(temp < sum)
				j++;
			else if(temp > sum)
				k--;
			else
				return true;
		}
	}

	// If a valid pythagorean triplet doesn't exist
	return false;
} 

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find if there exists a pythagorean triplet
	bool is_pythagorean_triplet = find_pythagorean_triplet(arr);

	if(is_pythagorean_triplet)
		cout << "There exists a pythagorean triplet in the array" << endl;
	else
		cout << "There is no pythagorean triplet in the array" << endl;

	return 0;
}