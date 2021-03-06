

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
		int a[n+1];
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		
		int m;
		cin>>m;
		int b[m+1];
		a[0]=0;
		b[0]=0;
		for(int i=1; i<=m; i++){
			cin>>b[i];
		}
		
		int sum1 =0, sum2=0, maxi=0;
		for(int i=0; i<=n; i++){
			sum2=0;
			sum1+=a[i];
			for(int j=0; j<=m; j++){
				sum2+=b[j];
				if(sum1+sum2>maxi){
					maxi=sum1+sum2;
				}
			}
		}
		
		cout<<maxi<<endl;
	}
	
}
