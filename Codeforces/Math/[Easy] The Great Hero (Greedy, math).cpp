

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
		long long a,b,n;
		cin>>a>>b>>n;
		
		long long x[n+1],y[n+1];
		for(int i=1; i<=n; i++){
			cin>>x[i];
		}
		for(int i=1; i<=n; i++){
			cin>>y[i];
		}
		
		vector<pair<long long, long long> > lol;
		for(int i=1; i<=n; i++){
			
			long long but = (y[i]+a-1)/a;
			long long dam = but*x[i];
			lol.push_back(mp(x[i],dam-x[i]));
		}
		
		sort(lol.begin(),lol.end());
		
		for(int i=0; i<n; i++){
			if(b<=0){
				cout<<"NO"<<endl;
				break;
			}
			b-=lol[i].se;
			if(b<=0){
				cout<<"NO"<<endl;
				break;
			}
			b-=lol[i].fi;
			if(i==n-1){
				cout<<"YES"<<endl;
				break;
			}
		}
	}
}
