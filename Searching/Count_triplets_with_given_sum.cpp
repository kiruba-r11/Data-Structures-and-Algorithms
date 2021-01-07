#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n ^ 2)
Space Complexity : O(1)

Approach : Two Pointer Algorithm

*/

// Function to return the count of the triplets with given sum
int find_triplet_count(vector <int> arr , int sum) {

	int count = 0;

	// The approach to is just find the triplets using the two pointer method and increment the count
	for(int i = 0; i < arr.size() - 2; i++) {

		// Two pointers, one is first and one is last
		int j = i + 1 , k = arr.size() - 1;

		// Modified sum
		int m_sum = sum - arr[i];

		while(j < k) {
			if(arr[j] + arr[k] < m_sum)
				j++;
			else if(arr[j] + arr[k] > m_sum)
				k--;
			else {

				int x = j , y = k , xx = arr[j] , yy = arr[k];

				// Moving the i pointer until it reaches a different element
				while(j < k && arr[j] == xx)
					j++;

				// Moving the j pointer until it reaches a different element
				while(k >= j && arr[k] == yy)
					k--;

				// If both xx and yy are element, we need to decrease one extra count
				if(xx == yy) {
					int temp = (j - x) + (y - k) - 1;
					count += temp * (temp + 1) / 2;
				}
				else
					count += (j - x) * (y - k);
			}
		}
	}

	// Return the count of the triplets with given sum
	return count;
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

	cout << "Enter the sum : " << endl;
	cin >> sum;

	// Function Call to find the count of the triplet with given sum
	int triplet_count = find_triplet_count(arr , sum);

	cout << "The count of the triplets with given sum : " << triplet_count << endl;

	return 0;
}