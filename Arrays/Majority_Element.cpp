#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n)
Space Complexity : O(n) -> Input array

Approach : Murray's Voting Algorithm (Performed in two phase)

Majority Element : It is an element in the array that occurs more than n / 2 times

*/

// Function to return the any valid index of the majority element, else -1
int find_majority_element_index(vector <int> arr) {

	// Considering the first element to be the majority element
	int index = 0 , count = 1;

	// Phase - 1 -> To find the majority element
	// Traverse the array from index 1 to size - 1
	for(int i = 1; i < arr.size(); i++) {

		// Now if the current element is not equal to the previous element, decrement count, else increment count
		if(arr[i] == arr[i - 1])
			count++;
		else 
			count--;

		// If count becomes 0, reassign it to 1 and lets consider the current element to be the majority element
		if(count == 0) {
			count = 1;
			index = i;
		}
	}

	// Phase - 2 -> To confirm whether the found element is majority or not
	// Note : This phase is not required if there will surely be a majority element in the array
	// Now we have got the index of the majority element, but we have to test it that whether this element is majority element or not
	count = 0;

	// Counting the frequency of the found element
	for(int i = 0; i < arr.size(); i++) {
		if(arr[index] == arr[i])
			count++;
	}

	// If the found element is not majority element, then make the index invalid
	if(count <= arr.size() / 2)
		index = -1;

	// Return the index
	return index;
}

int main() {

	int n;

	cout << "Enter the size of the array: " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the index of the majority element
	int index = find_majority_element_index(arr);

	// Invalid index
	if(index == -1)
		cout << "There is no majority element in the array" << endl;
	else 
		cout << "Majority element occurs at the index : " << index << endl;

	return 0;
}