

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

const int N = 2e5;

vector<int> adj[N],jal[N];
int disc[N];
int tim, low[N],ins[N],kod[N];
stack<int> s;

void dfs(int now, int par){
//	cout<<now<<endl;
	for(int i=0; i<jal[now].size(); i++){
		int nex=jal[now][i];
		if(nex==par) continue;
		if(disc[nex]==1) {
//			cout<<now<<' '<<nex<<endl;
			adj[now].push_back(nex);
			continue;
		}
		disc[nex]=1;
		adj[now].push_back(nex);
		dfs(nex,now);
	}
}

void tar(int now, int par){
//	cout<<now<<endl;
	low[now]=disc[now]=tim++;
	s.push(now);
	ins[now]=1;
	for(int i=0; i<adj[now].size(); i++){
		int v=adj[now][i];
		if(disc[v]==-1){
			tar(v,now);
			low[now]=min(low[now], low[v]);
		}else if(ins[v]){
			low[now]=min(low[now], disc[v]);
		}
	}
	
	if(low[now]==disc[now]){
		tim++;
		int v;
//		cout<<"baru"<<endl;
		do{
			v = s.top();
			s.pop();
			ins[v]=0;
///			cout<<v<<endl;
			kod[v]=tim;
		}while(now!=v);
	}
}

int main(){
	/* Fast IO */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1; i<=m; i++){
		int x,y;
		cin>>x>>y;
		jal[x].push_back(y);
		jal[y].push_back(x);
	}
	memset(disc,-1,sizeof disc);
	disc[1]=1;
	dfs(1,-1);
	memset(disc,-1,sizeof disc);
	tar(1,-1);
	while(q--){
		int x,y;
		cin>>x>>y;
	//	cout<<kod[x]<<' '<<kod[y]<<endl;
		if(kod[x]==kod[y]){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
