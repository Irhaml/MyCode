

/*******************************************************
** This program was written by Muhammad Irham Luthfi. **
** Intended for educational use.                      **
** No rights reserved.                                **
*******************************************************/


/* All library and pragma */
#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
/* For PBDS */ 
typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
 
/* For pair */ 
#define mp make_pair
#define fi first
#define se second

/* For Random number generator */ 
//mt19937 rng(time(NULL)); //int
//mt19937_64 rng(time(NULL)); //Long Long
//shuffle(a.begin(),a.end(),rng); //shuffle
//rng(); //random

const int N= 2e3;
vector<pair<int,int> > adj[N];

int main(){
	/* Fast IO */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		adj[x].push_back(mp(y,z));
		adj[y].push_back(mp(x,z));
	}
	
	priority_queue<pair<int,int> > pq;
	pq.push(mp(0,1));
	int jar[n+1];
	for(int i=1; i<=n; i++){
		jar[i]=1e9+1;
	}
	jar[1]=0;
	while(!pq.empty()){
		int x=-pq.top().fi,y=pq.top().se;
		pq.pop();
		if(x!=jar[y]) continue;
		for(int i=0; i<adj[y].size(); i++){
			int z= adj[y][i].fi;
			int cost= adj[y][i].se;
			if(jar[z]>x+cost){
				jar[z]=x+cost;
				pq.push(mp(-jar[z],z));
			}
		}
	}
	
	int mini = jar[n];
	int vis[n+1];
	memset(vis,-1,sizeof vis);
	
	vis[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0; i<adj[x].size(); i++){
			int 
		}
	}
	
}
