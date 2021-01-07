#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n ^ 2)
Space Complexity : O(1)

Approach : Two Pointer Algorithm

*/

// Function to return true if a triplet exists with given sum, else false
bool find_triplet_with_given_sum(vector <int> arr , int sum) {

	// The approach is to have two pointers, one at index i + 1 and the other at index n - 1. 
	// We need to find a pair for every element such that, 
	// Modified sum = given_sum - arr[i]
	// 		1. If sum(arr[i] , arr[j]) < modified_sum
	// 			Move first pointer to the next position
	// 		2. If sum(arr[i] , arr[j]) > modified_sum
	//			Move the last pointer to the previous position
	// 		3. If sum(arr[i] , arr[j]) == modified_sum
	// 			The pair is found, therefore return true
	// Since the array is sorted, following properties are always valid

	for(int i = 0; i < arr.size() - 2; i++) {

		// Two pointers, l is first and r is last pointer
		int j = i + 1 , k = arr.size() - 1;

		// Modified Sum
		int m_sum = sum - arr[i];
		while(j < k) {
			if(arr[j] + arr[k] > m_sum)
				k--;
			else if(arr[j] + arr[k] < m_sum)
				j++;
			else
				return true;
		}
	}

	// If a triplet doesn't exists
	return false;
}


int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the sorted array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int sum;

	cout << "Enter the sum to find the triplet : " << endl;
	cin >> sum;

	// Function Call to find if there exists a triplet with the given sum
	bool is_triplet = find_triplet_with_given_sum(arr , sum);

	if(is_triplet)
		cout << "There exists a triplet with given sum" << endl;
	else
		cout << "There is no triplet with given sum" << endl;

	return 0;
}