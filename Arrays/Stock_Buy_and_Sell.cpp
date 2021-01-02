#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Buy the stock at Local Minima and Sell it at Local Maxima

*/

// Function to return the maximum profit
int find_max_profit(vector <int> arr) {

	int profit = 0;

	// Traverse the array from index 1 to size - 1
	for(int i = 1; i < arr.size(); i++) {

		// If the price of the stock in the current day is greater than the previous day, then add their difference
		if(arr[i] > arr[i - 1])
			profit += arr[i] - arr[i - 1];
	}

	// Return the maximum profit
	return profit;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the maximum profit 
	int max_profit = find_max_profit(arr);

	cout << "The maximum profit that can be achieved is : " << max_profit << endl;

	return 0;
}