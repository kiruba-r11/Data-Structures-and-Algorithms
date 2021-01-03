#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

// Approach : Prefix Sum

*/

// Function to return the sum of the given range
int find_sum_of_range(vector <int> prefix_sum , int l , int r) {

	// The can be found using the simple formula, prefix_sum[r] - prefix_sum[l - 1]
	// Now, when l = 0, its a edge case and shoudl be handled separately

	// If l = 0, it means prefix_sum till index r itself, so we don't have to subtract anything
	int sum = prefix_sum[r] - (l == 0 ? 0 : prefix_sum[l - 1]); 

	// Return the sum of the given range
	return sum;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int q;

	cout << "Enter the no. of queries to process : " << endl;
	cin >> q;

	// Here prefix sum method is used to find the sum of a range
	// Just processing the queries and traversing the array to find the sum would take O(n * q) time
	// But instead we would preprocess the array once, and find their prefix sum so that each query would take only constant time to find the sum of the range
	// Therefore, this would take only O(q) time

	vector <int> prefix_sum(n);
	prefix_sum[0] = arr[0];

	for(int i = 1; i < n; i++)
		prefix_sum[i] = arr[i] + prefix_sum[i - 1];

	// Processing queries
	for(int i = 0; i < q; i++) {	

		int l , r;

		cout << "Enter the range (l , r) to find the sum : " << endl;
		cin >> l >> r;

		// Function Call to find the sum for a given range from l , r (inclusive)
		int get_sum = find_sum_of_range(prefix_sum , l , r);

		cout << "The sum of the given range is : " << get_sum << endl;
	}

	return 0;
}