

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	
	int n;
	cin>>n;
	if(n==4||n==5||n==13||n==14||n==22||n==23||n==31||n==32||n==40||n==41||n==49){
		cout<<0<<endl;
	}else if(n==16){
		cout<<"-511 -1609 1626"<<endl;
	}else if(n==24){
		cout<<"-2901096694 -15550555555 15584139827"<<endl;
	}else if(n==30){
		cout<<"-283059965 -2218888517 2220422932"<<endl;
	}else if(n==33){
		cout<<"8866128975287528 -8778405442862239 -2736111468807040"<<endl;
	}else if(n==39){
		cout<<"117367 134476 -159380"<<endl;
	}else if(n==42){
		cout<<"-80538738812075974 80435758145817515 12602123297335631"<<endl;
	}else{
		bool udah=1;
		int a=-26,b=40;
		for(int i=a; i<=b; i++){
			for(int j=a; j<=b; j++){
				for(int k=a; k<=b; k++){
					if(i*i*i + j*j*j + k*k*k==n&&udah){
						cout<<i<<' '<<j<<' '<<k<<endl;
						udah=0;
					}
				}
			}
		}
	}
}
