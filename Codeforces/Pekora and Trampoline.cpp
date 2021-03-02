

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
		int a[n+12];
		int sel[n+12];
		for(int i=1; i<=n; i++){
			cin>>a[i];
			sel[i]=i;
		}
		a[n+1]=1e9+10;
		sel[n+1]=n+1;
		for(int i=2; i<=n+1; i++){
			int now=i-1;
			while(a[now]==1&&now>0){
				sel[now]=i;
				now--;
			}
		}
		
		long long jaw=0;
		int l=1;
		while(l<=n){
			
			for(int i=l; i<=n; i++){
				if(a[i]<=1) l++;
				else break;
			}
			if(l>n) break;
			int now=a[l];
			int kur=1;
			if(now>n-l+1){
				kur = now-(n-l)-1;
				jaw+=kur;
				a[l]-=kur;
				continue;
			}
		//	cout<<"now "<<l<<endl;
			jaw++;
			for(int i=l; i<=n;){
		//		cout<<i<<endl;
				int nex=i+a[i];
				if(a[i]==1){
					nex=sel[i];
					i=nex;
					continue;
				}
				a[i]=max(1,a[i]-1);
				if(a[i]==1){
					int now=i;
					while(a[now]==1&&now>0){
						sel[now]=sel[now+1];
						now--;
					}
				}
				i=nex;
			}
		}
		cout<<jaw<<endl;
	}
}
