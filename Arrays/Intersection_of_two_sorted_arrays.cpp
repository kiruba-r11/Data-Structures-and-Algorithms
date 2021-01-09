#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(n + m) -> n , m - size of two sorted arrays
Space Complexity : O(n + m) -> n , m - size of two sorted arrays

*/

// Function to return the intersection of the two sorted arrays
vector <int> intersection_of_two_sorted_arrays(vector <int> arr1 , vector <int> arr2) {

	vector <int> arr;

	int i = 0 , j = 0;

	while(i < arr1.size() && j < arr2.size()) {
		if(arr1[i] < arr2[j]) {
			i++;
		}
		else if(arr1[i] > arr2[j]) {
			j++;
		}
		else {
			if(arr.size() != 0) {
				if(arr.back() != arr1[i])
					arr.push_back(arr1[i]);
			}
			else {
				arr.push_back(arr1[i]);
			}
			i++;
			j++;
		}
	}

	// Return the intersection array
	return arr;
}

int main() {

	int n1;

	cout << "Enter the size of the first array : " << endl;
	cin >> n1;

	vector <int> arr1(n1);

	cout << "Enter the values of the first sorted array : " << endl;
	for(int i = 0; i < n1; i++)
		cin >> arr1[i];

	int n2;

	cout << "Enter the size of the second array : " << endl;
	cin >> n2;

	vector <int> arr2(n2);

	cout << "Enter the values of the second sorted array : " << endl;
	for(int i = 0; i < n2; i++)
		cin >> arr2[i];

	// Function Call to perform intersection of two sorted arrays
	vector <int> arr = intersection_of_two_sorted_arrays(arr1 , arr2);

	cout << "The intersection is : ";

	// Displaying the elements of the intersection of two sorted arrays
	for(auto i: arr)
		cout << i << " ";
	cout << endl;

	return 0;
}