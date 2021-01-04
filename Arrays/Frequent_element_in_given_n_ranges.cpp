#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Prefix Sum

*/

// Function to find the frequent occuring element in the ranges
void frequent_occuring_in_range(vector <int> &count , int l , int r) {

	// The concept is to add 1 in the index l and add -1 int the index r + 1
	// After the overall changes in the count array, perform prefix sum on this array, and the index with max element will be the frequent element
	// If r == size - 1, it is the edge case and should be handled separately

	// This concept works because. when we assign 1 to the starting index of the range and perform prefix sum it will affect till the end of the array
	// But, we want it to affect only till the ending index of the range. Therefore, we assign -1 to the index after the ending index to nullify the change

	count[l] += 1;

	if(r < count.size() - 1)
		count[r + 1] -= 1;

}

int main() {

	int n;

	cout << "Enter the no. of ranges : " << endl;
	cin >> n;

	// Array with size 1000 initialised with 0 
	vector <int> count(1000 , 0);

	for(int i = 0; i < n; i++) {

		// Consider the range constraints as 1 <= l , r <= 1000 and l <= r
		int l , r;
		cout << "Enter the start and end of the range : " << endl;
		cin >> l >> r;

		// Function Call to find the frequent occuring element in the ranges
		frequent_occuring_in_range(count , l , r);
	}

	// Perform prefix sum on the array
	vector <int> prefix_sum(1000);
	prefix_sum[0] = count[0];

	for(int i = 1; i < 1000; i++) 
		prefix_sum[i] = count[i] + prefix_sum[i - 1];

	// The index of the max occuring element is the most frequent occuring element
	int frequent = -1;
	int max_element = -1;

	for(auto i: count)
		cout << i << " ";
	cout << endl;

	for(int i = 0; i < 1000; i++) {
		if(prefix_sum[i] > max_element) {
			frequent = i;
			max_element = prefix_sum[i];
		}
	}

	// Note if there are more than 1 most frequent elements with same count, it will print only the smallest of those
	cout << "The most frequent occuring element in the given ranges is : " << frequent << endl;

	return 0;
}