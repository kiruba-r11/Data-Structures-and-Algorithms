#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<bitset>
#include<cmath>
#include<iomanip>
#define vint vector<int>
#define ll long long
#define mod 1000000007
#define vll vector<long long>
#define ld long double
#define mii map<int,int>
#define miv map<int,vector<int>>
#define vf vector<float>
#define vd vector<double>

/*

Time Complexity: O(N), N -> Number of elements
Space Complexity: O(N), N -> Number of elements

*/

using namespace std;

void findMaxMin(vint arr,int start,int end,int &max,int &min)
{
	if(start==end) // Sub-array with one element
	{
		max=arr[start];
		min=arr[start];
		return;
	}
	if(start==end-1) // Sub-array with two elements
	{
		if(arr[start]>arr[end])
		{
			max=arr[start];
			min=arr[end];
			return;
		}
		else
		{
			max=arr[end];
			min=arr[start];
			return;
		}
	}
	int max1,max2,min1,min2;
	int mid=(start+end)/2;
	findMaxMin(arr,start,mid,max1,min1); // Max and Min of left sub-array
	findMaxMin(arr,mid+1,end,max2,min2); // Max and Min of right sub-array
	if(max1>max2)
	{
		max=max1;
	}
	else
	{
		max=max2;
	}
	if(min1<min2)
	{
		min=min1;
	}
	else
	{
		min=min2;
	}
	return;
}

void solve()
{
	//Input
	int n,max,min;
	cin>>n;
	vint arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	// Finding maximum and minimum
	findMaxMin(arr,0,n-1,max,min);

	cout<<"Maximum : "<<max<<endl;
	cout<<"Minimum : "<<min<<endl;
	return;
}

int main()
{
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
