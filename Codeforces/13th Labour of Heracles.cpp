

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
		int n;
		cin>>n;
		
		long long jaw =0;
		long long w[n+1];
		long long ban[n+1];
		memset(ban, 0, sizeof ban);
		for(int i=1; i<=n; i++){
			cin>>w[i];
			jaw+=w[i];
		}
		
		for(int i=1; i<n; i++){
			int x,y;
			cin>>x>>y;
			ban[x]++;
			ban[y]++;
		}
		priority_queue<pair<long long, long long> > pq;
		for(int i=1; i<=n; i++){
			pq.push(mp(w[i],ban[i]-1));
		}
		cout<<jaw;
		for(int i=2; i<n; i++){
			while(1){
				long long x=pq.top().fi, y=pq.top().se;
				pq.pop();
				
				if(y==0) continue;
				y--;
				jaw+=x;
				cout<<' '<<jaw;
				pq.push(mp(x,y));
				break;
			}
		}
		cout<<endl;
	}
	
}
