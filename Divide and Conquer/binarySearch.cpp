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

Time Complexity: O(logN), N -> Number of elements
Space Complexity: O(N), N -> Number of elements

*/

using namespace std;

void solve()
{
	//Input
	int n,s;
	cin>>n;
	vint arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>s;

	//Binary Search Algorithm
	int start=0,end=n-1,flag=-1;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(arr[mid]==s) // Searching middle element
		{
			flag=mid;
			break;
		}
		if(arr[mid]<s) // Moving to right sub-array
		{
			start=mid+1;
		}
		else // Moving to left sub-array
		{
			end=mid-1;
		}
	}
	if(flag+1)
	{
		cout<<"Found at position : "<<flag+1<<endl;
	}
	else
	{
		cout<<"Not found\n";
	}
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
