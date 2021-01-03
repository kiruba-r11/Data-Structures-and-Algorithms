#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n ^ 2)
Space Complexity : O(n) -> Input array

Approach : Two pointer

*/

// Function Call to return true if a triplet with zero sum exists, else false
bool is_three_number_with_zero_sum(vector <int> arr) {

	// Sort the array in ascending to use the concept of two pointer
	sort(arr.begin() , arr.end());

	// Traverse the array from 0 to size - 3 (This loop denotes the first number of the triplet)
	for(int i = 0; i < arr.size() - 2; i++) {
		// Now we have to find two numbers which gives sum as negative of the first number chosen
		// If it is found, there exists such triplet. These two numbers with required sum can be found using two pointer algorithm

		// The sum of both numbers should be negative of chosen number, as the triplet overall sum shoudl be zero
		int sum = -1 * (arr[i]);

		// Two pointers
		int j = i + 1 , k = arr.size() - 1;

		while(j < k) {
			// This approach below works because the array is sorted in ascending order
			if((arr[j] + arr[k]) < sum) {
				j++;
			}
			else if((arr[j] + arr[k]) > sum) {
				k--;
			}
			else 
				return true;
		}
	}
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

	// Function Call to check whether three numbers exists with zero sum
	bool check = is_three_number_with_zero_sum(arr);

	if(check)
		cout << "There exists such a triplet with zero sum" << endl;
	else
		cout << "There is no such triplet" << endl;

	return 0;
}