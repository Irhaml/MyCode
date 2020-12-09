

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


int main(){
	/* Fast IO */
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	
	
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1], cnt=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout<<"Masukkan A["<<i<<"]["<<j<<"] = ";
			cin>>a[i][j];
			if(a[i][j]>0) cnt++;
		}
	}
	
	cout<<"Ada "<<cnt<<" bilangan positif di matriks"<<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
