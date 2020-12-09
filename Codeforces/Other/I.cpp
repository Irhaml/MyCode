

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
	long long n,q;
	cin>>n>>q;
	long long a[n+1], bat=1e12;
	for(long long i=1; i<=n; i++){
		cin>>a[i];
	}
	
	map<long long, long long> m;
	map<long long, long long>::iterator it;
	for(long long i=1; i<=n; i++){
		for(long long j=i+1; j<=n; j++){
			long long x=a[i],y=a[j];
			if(x>y) swap(x,y);
			long long fp=__gcd(x,y);
			x=x/fp;
			y=y/fp;
			long long akhir = bat/fp;
			long long cnt = akhir-(x+(x+1)*(y-1)/2);
		///	cout<<i<<' '<<j<<' '<<cnt<<endl;
			m[cnt]++;
	//		cout<<cnt<<endl;
		}
	}
	long long b[500000],seb[500000];
	memset(b,0,sizeof b);
	memset(seb,-1,sizeof seb);
	b[0]=1;
	vector<long long> tam;
	for (it=m.begin(); it!=m.end(); it++ ){
		long long now = it->second;
		tam.push_back(now);
	//	cout<<"ada "<<now<<endl;
	}
	sort(tam.begin(),tam.end());
	
//	tam.clear();
//	tam.push_back(1);
//	tam.push_back(2);
//	tam.push_back(3);
	
	long long sum=0,awal=0;
	long long batas= n*(n-1)/2;
	for(long long i=1; i<=batas; i++){
		while(tam[awal]+sum<i){
			sum+=tam[awal];
			awal++;
			
		}
	//	cout<<sum<<endl;
	//	cout<<"lagi di "<<i<<endl;
		for(long long j=awal; j<tam.size(); j++){
			long long now=tam[j];
			if(now>i) break;
			if(b[i-now]&&seb[i-now]!=j){
				seb[i]=j;
			//	cout<<now<<endl;
				b[i]=1;
				break;
			}
		}
	}
	
	while(q--){
		long long x;
		cin>>x;
		if(b[x]){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	
	
}
