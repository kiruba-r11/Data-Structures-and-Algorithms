#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer) - Lower Bound

*/

// Function to return the floor of the square root of a number
int find_square_root(int n) {

	// The approach is to find the lower bound of a number, such that number * number is less than n

	int sq_root = -1;

	int low = 1 , high = n;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(mid * mid == n) {
			return mid;
		}
		else if(mid * mid > n)
			high = mid - 1;
		else {
			low = mid + 1;
			sq_root = mid;
		}
	}

	// Return the floor of square root of the number
	return sq_root;

}

int main() {

	int n;

	cout << "Enter the number to find the floor value of square root : " << endl;
	cin >> n;

	// Function Call to find the floor of square root of a number
	int sq_root = find_square_root(n);

	cout << "The floor of square root of the number is : " << sq_root << endl;

	return 0;
}