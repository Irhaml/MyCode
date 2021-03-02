

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
		long long n,k;
		cin>>n>>k;
		long long l = 1, r=k;
		long long a[n+1];
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		
		bool bisa =1;
		l = a[1]+1;
		r = a[1]+k;
		for(int i=2; i<n; i++){
			long long x=a[i]+1, y=a[i]+k+k-1;
			if(r<x || l>y){
				bisa = 0;
				break;
			}
			
			l=max(x, l-k+1);
			r=min(y, r+k-1);
		}
		if(l>a[n]+k||r<a[n]+1){
			bisa = 0;
		}
		
		if(bisa){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
