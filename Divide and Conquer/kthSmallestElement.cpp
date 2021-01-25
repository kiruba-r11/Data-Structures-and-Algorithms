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

Median of Medians Algorithms for kth smallest element

Time Complexity : O(N), N -> Number of elements
Space Complexity : O(N), N -> Number of elements

*/

using namespace std;

void swap(vint &arr,int i,int j) // Function to Swap elements in an array
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	return;
}

// Partitioning with respect to pivot
int partition(vint &arr,int start,int end,int pivot)
{
	for(int i=start;i<end;i++)
	{
		if(arr[i]==pivot)
		{
			swap(arr,i,end);
			break;
		}
	}
	int insert=start;
	for(int i=start;i<=end;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr,insert,i);
			insert++;
		}
	}
	return insert;
}

int kthSmallestElement(vint arr,int start,int end,int k)
{
	int n=end-start+1;
	vint medians;
	int mcount=0;
	for(int i=0;i<n/5;i++)
	{
		vint group;
		for(int j=0;j<5;j++) // Grouping
		{
			group.push_back(arr[start+(5*i)+j]);
		}
		sort(group.begin(),group.end());
		medians.push_back(group[2]); // Finding medians of groups
		mcount++;
	}
	if(n%5)
	{
		vint group;
		int size;
		for(int i=start+(n/5)*5;i<=end;i++)
		{
			size++;
			group.push_back(arr[i]);
		}
		sort(group.begin(),group.end());
		medians.push_back(group[size/2]);
		mcount++;
	}

	int m; // Finding median of medians
	if(mcount==1)
	{
		m=medians[0];
	}
	else
	{
		m=kthSmallestElement(medians,0,mcount-1,mcount/2);
	}

	int position=partition(arr,start,end,m);

	if(position==k+start)
	{
		return arr[position-1];
	}
	else if(position>k+start) // Search in left sub-array
	{
		return kthSmallestElement(arr,start,position-2,k);
	}
	else // Search in right sub-array
	{
		return kthSmallestElement(arr,position,end,k+start-position);
	}
	return -1;
}

void solve()
{
	//Input
	int n,k,result;
	cin>>n;
	vint arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>k;

	//Finding k-th smallest element
	result=kthSmallestElement(arr,0,n-1,k);

	//Print result
	cout<<result<<endl;
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
