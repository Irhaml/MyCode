

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
		long long n,u,v;
		cin>>n>>u>>v;
		
		long long bef;
		cin>>bef;
		bool ya=1,gk=0;
		for(int i=2; i<=n; i++){
			long long now;
			cin>>now;
			if(abs(now-bef)==0){
				bef=now;
			}
			else if(abs(now-bef)==1){
				bef=now;
				gk=1;
			}else{
				bef=now;
				ya=0;
			}
		}
		
		if(!ya){
			cout<<0<<endl;
		}else if(gk){
			cout<<min(u,v)<<endl;
		}else{
			cout<<min(v+v,u+v)<<endl;
		}
	}
}
