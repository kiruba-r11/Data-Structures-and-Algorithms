#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(1)

Approach : Two Pointer Algorithm

*/

// Function to return the count of pairs with given sum
int count_pairs_with_given_sum(vector <int> arr , int sum) {

	int count = 0;

	// The approach is to find the pair with given sum using two pointer method and add them to the count

	// Two pointers, one is first and the other is last pointer
	int i = 0 , j = arr.size() - 1;

	while(i < j) {
		if(arr[i] + arr[j] < sum)
			i++;
		else if(arr[i] + arr[j] > sum)
			j--;
		else {
			int x = i , y = j , xx = arr[i] , yy = arr[j];

			// Moving the i pointer until it reaches a different element
			while(i < j && arr[i] == xx)
				i++;

			// Moving the j pointer until it reaches a different element
			while(j >= i && arr[j] == yy)
				j--;

			// If both xx and yy are element, we need to decrease one extra count
			if(xx == yy) {
				int temp = i - x + y - j - 1;
				count += temp * (temp + 1) / 2;
			}
			else 
				count += (i - x) * (y - j);
		}
	}

	// Return the count of the pairs with given sum
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

	// Function Call to find the no. of pairs with given sum
	int pair_count = count_pairs_with_given_sum(arr , sum);

	cout << "The count of pairs with given sum is : " << pair_count << endl;

	return 0;
}