

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
	
	
	int q;
	cin>>q;
	while(q--){
		long long x,y;
		cin>>x>>y;
		if(x>y){
			cout<<"NO"<<endl;
			continue;
		}
		stack<long long> a,b;
		int now=1;
		while(x>0||y>0){
			if(x&1) a.push(now);
			if(y&1) b.push(now);
			now++;
			x/=2;
			y/=2;
		}
		
		while(1){
			if(a.empty()){
				cout<<"NO"<<endl;
				break;
			}
			
			if(a.top()>b.top()){
				cout<<"NO"<<endl;
				break;
			}
			
			b.pop();
			if(b.empty()){
				cout<<"YES"<<endl;
				break;
			}
			a.pop();
			while(!a.empty()){
				if(a.top()>b.top()){
					a.pop();
				}else{
					break;
				}
			}
		}
	}
}
