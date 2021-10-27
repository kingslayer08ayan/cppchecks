#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define dd double
void addedge(vector<pair<ll,ll>> adj[],ll u,ll v,ll wt)
{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}
void printgraph(vector<pair<ll,ll>>adj[],ll V)
{
	ll f,s;
	for(ll i=0;i<V;i++)
	{
		cout<<"vertex "<<i<<endl;
		for(auto it=adj[i].begin();it!=adj[i].end();it++)
		{
			f=it->first;
			s=it->second;
			cout<<"edge=  "<<f<<" weight="<<s<<endl;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt","w",stdout);
   #endif
	ll V=6;
	vector<pair<ll,ll>>adj[V];
	addedge(adj,0,1,40);
	addedge(adj,0,2,10);
	addedge(adj,1,4,30);
	addedge(adj,1,3,40);
	addedge(adj,2,3,80);
	addedge(adj,2,5,60);
	addedge(adj,3,5,50);
	addedge(adj,4,5,70);
	printgraph(adj,V);
	return 0;

}
