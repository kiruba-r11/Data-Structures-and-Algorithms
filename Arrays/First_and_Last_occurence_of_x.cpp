#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Binary Search

*/

// Function to perform binary search to find the lower bound of an element
int binary_search(vector <int> arr , int key , int low , int high) {

	int index = arr.size();

	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] >= key) {
			index = mid;
			high = mid - 1;
		}
		else 
			low = mid + 1;
	}

	// Return the index
	return index;
}

// Function to return the first and last occurence of an element if it is present, else -1
vector <int> first_and_last_occurence(vector <int> arr , int x) {

	// The approach is to simply find the lower bound of x and x + 1
	// If lower bound of x is i, then the first occurence of x is i
	// If lower bound of x + 1 is j, then the last occurence of x is j - 1
	// If the element doesn't exist, return -1

	int i = binary_search(arr , x , 0 , arr.size() - 1);
	int j = binary_search(arr , x + 1 , 0 , arr.size() - 1) - 1;

	// Invalid index
	if(i > j)
		return {-1};
	return {i , j};
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	// The array should be sorted
	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int x;

	cout << "Enter the element to find its first and last occurence : " << endl;
	cin >> x;

	// Function Call to return the first and last occurence of the element
	vector <int> index = first_and_last_occurence(arr , x);

	// If element is not present in the array
	if(index.size() == 1)
		cout << "The element is not present in the array" << endl;
	else
		cout << "The first and last occurence of the array is at the index : " << index[0] << " " << index[1] << endl;

	return 0;
}