#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<bitset>
#include<cmath>
#define vint vector<int>
#define ll long long
#define mod 1000000007
#define vll vector<long long>
#define ld long double
#define mii map<int,int>
#define miv map<int,vector<int>>

/*

Time Complexity: O(NlogN)
Space Complexity: O(N) -> Input Array

Click on the link below for Visualization:
https://barathkumarbk-15.github.io/SortingAlgorithms/

*/

using namespace std;

void Merge(vint &arr, int start, int middle, int end)
{
	vint new_arr(end-start);
	int x=start;
	int y=middle;
	int z=0;

	while(x<middle && y<end)// Merging element by element
	{
		if(arr[x]>arr[y])
		{
			new_arr[z++]=arr[y++];
		}
		else
		{
			new_arr[z++]=arr[x++];
		}
	}
	if(x==middle && y!=end)//copying remaining
	{
		while(y!=end)
		{
			new_arr[z++]=arr[y++];
		}
	}
	if(x!=middle && y==end)//copying remaining
	{
		while(x!=middle)
		{
			new_arr[z++]=arr[x++];
		}
	}
	for(int i=start;i<end;i++) //Copying Back to the main array
	{
		arr[i]=new_arr[i-start];
	}
	return;
}

void MergeSort(vint &arr,int start,int end)
{
	if(end<=start)
	{
		return;
	}
	//cout<<start<<" "<<end<<endl;
	if(end-start==1)
	{
		return;
	}
	int middle=(end+start)/2;// Finding the mid-term
	MergeSort(arr,start,middle);// Sorting the first half
	MergeSort(arr,middle,end); //Sorting second half
	Merge(arr,start,middle,end); //Merging sorted subarrays
	return;
}

int main()
{
    //Input
	int n;
	cin>>n;
	vint arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	MergeSort(arr,0,n);

	//Printing Sorted Array
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
