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
#define N 10001

/*

Time Complexity: O(V+E), V->Number of Nodes, E->Number of Edges 
Space Complexity: O(V^2), Each node may have a maximum of V neighbouring nodes

*/

using namespace std;

void solve()
{
	//input n->Number of edges
	int n;
	cin>>n;
	vint ch[N];
	vint path[N];
	vint visited(N,1);
	
	for(int i=0;i<n;i++)
	{
		int x,y;// Undirected edge between x and y
		cin>>x>>y;
		ch[x].push_back(y);
		ch[y].push_back(x);
	}
	
	int a,b;
	cin>>a>>b; // Find path between a and b

	//Finding BFS using Queue
	int flag=0;
	vint queue;
	queue.push_back(a);
	visited[a]=0;
	path[a].push_back(a);
	int length=1;
	
	if(a==b)
	{
		cout<<a<<endl;
		return;
	}
	
	while(length)
	{
		int x=queue[0];
		cout<<x<<endl;
		length--;
		queue.erase(queue.begin()+0);
		for(auto c : ch[x])
		{
			if(visited[c]) // Pushing child nodes to queue
			{
				queue.push_back(c);
				visited[c]=0;
				length++;
				path[c]=path[x];
				path[c].push_back(c);
				if(c==b)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)
		{
			break;
		}
	}
	
	if(flag)// Printing path
	{
		for(auto i:path[b])
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
	else // If a and b are not connected
	{
		cout<<"No Path Possible";
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
