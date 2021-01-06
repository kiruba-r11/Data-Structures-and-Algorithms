#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

/*

Time Complexity : O(logn)
Auxiliary Space Complexity : O(1)

Approach : Binary Search (Divide and Conquer) 

*/

// Function to return the maximum element in a bitonic array
int find_max_in_bitonic_array(vector <int> arr) {

	// A bitonic array is an array which increases monotonically first and then decreases
	// Therefore, there exists a point where the element starts decreasing
	// That point will be the peak element of the bitonic array
	// Proof : [a1 , a2 , .... ai , ai+1 , ai+2 , ... an]
	// Here, a1 <= a2 <= a3 <= .... <= ai, then ai >= ai+1 >= ai+2 >= .... >= an
	// It is observed that ai is the max element because, the series increases till ai and then starts decreasing from ai+1
	// Hence, it can be proved that ai >= ai-1 and ai>= ai+1 which is the max element, and of course the peak element

	// So, the approach is to just find the peak element in the bitonic array
	int low = 0 , high = arr.size() - 1;
	int n = arr.size();

	while(low <= high) {
		int mid = low + (high - low) / 2;
		
		// Corner elements
		if(mid == 0) {
			if(arr[mid] >= arr[mid + 1])
				return arr[mid];
		}
		else if(mid == n - 1) {
			if(arr[mid] >= arr[mid - 1])
				return arr[mid];
		}
		else {
			if(arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
				return arr[mid];
		}

		// Move to left half of the array
		if(mid > 0 && arr[mid - 1] >= arr[mid])
			high = mid - 1;
		// Move to right half of the array
		else
			low = mid + 1;
	}

	// Invalid case, but it never occurs since every bitonic array, or array in general will surely have a peak element
	return -1;
}

int main() {

	int n;

	cout << "Enter the size of the array : " << endl;
	cin >> n;

	vector <int> arr(n);

	cout << "Enter the values of the bitonic array : " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	// Function Call to find the maximum element in a bitonic array
	int max_element = find_max_in_bitonic_array(arr);

	cout << "The maximum element in the bitonic array is : " << max_element << endl;

	return 0;
}