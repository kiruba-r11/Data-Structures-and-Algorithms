#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer) - Lower Bound

*/

// Function to find the lower bound of the key
int find_lower_bound(vector <int> arr , int key) {

	int first_occurence = arr.size();
	int low = 0 , high = arr.size() - 1;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] >= key) {
			first_occurence = mid;
			high = mid - 1;
		}
		else 
			low = mid + 1;
	}

	if(first_occurence == arr.size())
		return -1;
	return first_occurence;
}

// Function to find the upper bound of the key
int find_upper_bound(vector <int> arr , int key) {

	int first_occurence = arr.size();
	int low = 0 , high = arr.size() - 1;

	key++;
	bool check = false;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] == key - 1)
			check = true;
		if(arr[mid] >= key) {
			first_occurence = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	if(!check)
		return -1;
	return first_occurence - 1;
}

// Function to return the count of occurence of key
int find_count_of_occurence(vector <int> arr , int key) {

	// The approach is to simply find the lower and upper bound of key in the array
	// The count will then be equal to upper bound - lower bound + 1

	int lower_bound = find_lower_bound(arr , key);
	int upper_bound = find_upper_bound(arr , key);

	int count_occurence = 0;

	if(lower_bound != -1 && upper_bound != -1)
		count_occurence = upper_bound - lower_bound + 1;

	// Return the count of occurence of key
	return count_occurence;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	// The array is sorted
	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int key;

	cout << "Enter the key to count its occurence : " << endl;
	cin >> key;

	// Function Call to find the count of occurence of key
	int count_occurence = find_count_of_occurence(arr , key);

	cout << "The count of key is : " << count_occurence << endl;

	return 0;
}