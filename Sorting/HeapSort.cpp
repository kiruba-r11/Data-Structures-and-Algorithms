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

void heapify(vint &arr,int n,int i) //function to move the root to the required position
{
	int max=i;
	int left=2*i+1;
	int right=2*i+2;

	//Comparison with child nodes
	if(left<n && arr[left]>arr[max])
	{
		max=left;
	}
	if(right<n && arr[right]>arr[max])
	{
		max=right;
	}

	if(max!=i) // Swapping nodes if parent is smaller than child nodes
	{
		int temp=arr[i];
		arr[i]=arr[max];
		arr[max]=temp;
		heapify(arr,n,max);
	}
}

void solve()
{
    //Input
	int n;
	cin>>n;
	vint arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	//Conversion to heap tree
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(arr,n,i);
	}

	//Sorting
	for(int i=n-1;i>0;i--)
	{
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(arr,i,0);
	}

	//Printing Sorted Elements
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return;
}

int main()
{
    //FastIO
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	*/

	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
