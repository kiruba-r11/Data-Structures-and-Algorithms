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

void quicksort( vint &arr, int start, int end)
{
	if(start>=end) //subarray with one or no elements
	{
		return;
	}

	int pivot=arr[end]; //set last element as pivot
	int insert=start;

	for(int i=start;i<end;i++)
	{
		if(arr[i]<pivot) //push all elements lesser than the pivot in the beginning
		{
			int temp=arr[i];
			arr[i]=arr[insert];
			arr[insert]=temp;
			insert++;
		}
	}
	//push pivot value after the smaller values
	int temp=arr[end];
	arr[end]=arr[insert];
	arr[insert]=temp;

	// Same operation on subarray before and after the pivot
	quicksort(arr,start,insert-1);
	quicksort(arr,insert+1,end);
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


	quicksort(arr,0,n-1);

    //Printing Sorted Array
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}

int main()
{
    // fastIO
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
