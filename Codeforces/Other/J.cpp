

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

const int N=2e5;

int main(){
	/* Fast IO */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int bat=201;
	int n,m;
	cin>>n>>m;
	long long laz[N], val[N],nan[N];
	vector<int> cek[N],waj[N];
	for(int i=1; i<=n; i++){
		cin>>val[i];
		laz[i]=0;
	}
	
	long long sum[N],lis[N];
	vector<int> an[N];
	vector<int> v[N]; 
	for(int i=1; i<=m; i++){
		sum[i]=0;
		lis[i]=0;
		int x;
		cin>>x;
		for(int j=1; j<=x; j++){
			int y;
			cin>>y;
			an[y].push_back(i);
			v[i].push_back(y);
			lis[i]+=sum[i]*val[y];
			sum[i]+=val[y];
		}
	}
//	return 0;
	for(int i=1; i<=n; i++){
		if(an[i].size()>=bat){
			for(int j=0; j<an[i].size(); j++){
				waj[an[i][j]].push_back(i);
			}
		}
	}
	
	
	vector<int> sem;
	int gan=0;
	int q;
	cin>>q;
	while(q--){
		int dum;
		cin>>dum;
		if(dum==1){
			int x,y;
			cin>>x>>y;
			
			if(an[x].size()>=bat){
				if(laz[x]==0){
					sem.push_back(x);
				}
			}else{
				if(laz[x]==0){
					sem.push_back(x);
					for(int i=0; i<an[x].size(); i++){
						cek[an[x][i]].push_back(x);
					}
				}
			}
			laz[x]=1;
			nan[x]=y;
			if(sem.size()>=bat){
				for(int i=0; i<sem.size(); i++){
					int a=sem[i];
					val[a]=nan[a];
					laz[a]=0;
				}
				sem.clear();
				for(int i=1; i<=m; i++){
			//		cout<<i<<endl;
					sum[i]=0;
					lis[i]=0;
					for(int j=0; j<v[i].size(); j++){
						int a=v[i][j];
						lis[i]+=sum[i]*val[a];
						sum[i]+=val[a];
					}
					cek[i].clear();
				}
		//		cout<<"ya"<<endl;
			}
		}else{
			int x;
			cin>>x;
			long long jaw=lis[x],lol=sum[x];
			for(int i=0; i<waj[x].size(); i++){
				int y=waj[x][i];
				if(laz[y]==0) continue;
				lol-=val[y];
				jaw-=lol*val[y];
				jaw+=lol*nan[y];
				lol+=nan[y];
			}
			
			for(int i=0; i<cek[x].size(); i++){
				int y=cek[x][i];
				if(laz[y]==0) continue;
				lol-=val[y];
				jaw-=lol*val[y];
				jaw+=lol*nan[y];
				lol+=nan[y];
			}
			cout<<jaw<<endl;
		}
	}
}
