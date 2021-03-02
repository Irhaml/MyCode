

/*******************************************************
** This program was written by *Sakamoto.             **
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


int main(){
	/* Fast IO */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int now[n+5],e[n+5];
		now[0]=0;
		int a[n+5];
		int b[n+5],c[n+5],d[n+5];
		a[0]=b[0]=c[n+1]=d[n+1]=0;
		e[n+1]=0;
		char x[n+1];
		for(int i=1; i<=n; i++){
			cin>>x[i];
			if(x[i]=='+'){
				now[i]=now[i-1]+1;
			}else{
				now[i]=now[i-1]-1;
			}
			a[i]=max(a[i-1],now[i]);
			b[i]=min(b[i-1], now[i]);
		}
		
		for(int i=n; i>=1; i--){
			if(x[i]=='+'){
				e[i]=e[i+1]-1;
			}else{
				e[i]=e[i+1]+1;
			}
			c[i]=max(c[i+1],e[i]);
			d[i]=min(d[i+1],e[i]);
		}
		
		for(int i=1; i<=m; i++){
			int l,r;
			cin>>l>>r;
			int y=c[r+1]-e[r+1];
			int z=e[r+1]-d[r+1];
			int u=a[l-1];
			int v=b[l-1];
			u=max(u, now[l-1]+y);
			v=min(v, now[l-1]-z);
			cout<<u-v+1<<endl;
		}
	}
}
