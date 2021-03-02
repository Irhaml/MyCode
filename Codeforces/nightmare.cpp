

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

const int M=6e5;

long long mod=1e9+7;
long long fak[M];

long long modex(long long x, long long y){
	long long h=1;
	while(y){
		if(y&1) h=(h*x)%mod;
		x=(x*x)%mod;
		y/=2;
	}
	return h;
}

long long kombin(long long n, long long k){
	return (((fak[n]*modex(fak[k],mod-2))%mod)*modex(fak[n-k], mod-2))%mod;
}

int main(){
	/* Fast IO */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	int n,m;
	cin>>n>>m;
	fak[0]=1;
	for(int i=1; i<=m; i++){
		fak[i]=(fak[i-1]*i)%mod;
	}
	int sta[m+1],p[m+1];
	vector<int> an[m+1];
	for(int i=1; i<=m; i++){
		p[i]=i;
		an[i].push_back(i);
	}
	
	memset(sta, 0, sizeof sta);
	vector<int> v;
	for(int i=1; i<=n; i++){
		int dum;
		cin>>dum;
		if(dum==1){
			int x;
			cin>>x;
			if(sta[x]==0){
				v.push_back(i);
			}else{
				continue;
			}
			int y=p[x];
			vector<int> sem=an[y];
			for(int j=0; j<sem.size(); j++){
				sta[sem[j]]=1;
				p[sem[j]]=sem[j];
				an[sem[j]].clear();
				an[sem[j]].push_back(sem[j]);
			}
			
		}else{
			int x,y;
			cin>>x>>y;
			if(sta[x]&&sta[y]) continue;
			
			
			
			
			int parx=p[x], pary=p[y];
			if(parx==pary) continue;
			v.push_back(i);
			
			
			if(an[parx].size()<an[pary].size()){
				swap(parx,pary);
			}
			for(int j=0; j<an[pary].size(); j++){
				int now=an[pary][j];
				p[now]=parx;
				an[parx].push_back(now);
			}
			
			if(sta[x]||sta[y]){
				int par=p[x];
				vector<int> sem=an[par];
				for(int j=0; j<sem.size(); j++){
					sta[sem[j]]=1;
					p[sem[j]]=sem[j];
					an[sem[j]].clear();
					an[sem[j]].push_back(sem[j]);
				}
			//	an[par].clear();
			}
		}
	}
	
	
	long long jaw=1;
	for(int i=1; i<=m; i++){
		if(sta[i]==1){
			jaw=(jaw*2)%mod;
		}else if(sta[i]==0){
			long long sum=1;
			int par=p[i];
			for(int j=2; j<=an[par].size(); j+=2){
				sum+=kombin(an[par].size(),j);
				sum%=mod;
			}
			jaw=(jaw*sum)%mod;
			
			for(int j=0; j<an[par].size(); j++){
				sta[an[par][j]]=2;
			}
		}
	}
	cout<<jaw<<' '<<v.size()<<endl;
	for(int i=0; i<v.size(); i++){
		if(i>0) cout<<' ';
		cout<<v[i];
	}
	cout<<endl;
}
