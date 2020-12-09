

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

struct node{
	int mini;
	node *l;
	node *r;
};

const int N=2e5;
int a[N];
node *root;

node* buat(int l, int r){
	node *pnode = new node;
	pnode->l=NULL;
	pnode->r=NULL;
	if(l==r){
		pnode->mini=a[l];
	}else{
		int mid=(l+r)/2;
		pnode->l=buat(l, mid);
		pnode->r=buat(mid+1,r);
		pnode->mini=min(pnode->l->mini,pnode->r->mini);
	}
	return pnode;
}

void upd(int u, int ki, int ka, node* pnode, int val){
	if(ki>u||ka<u) return;
	if(ki==ka){
		pnode->mini=val;
	}else{
		int mid=(ki+ka)/2;
		upd(u,ki,mid,pnode->l,val);
		upd(u,mid+1,ka,pnode->r,val);
		pnode->mini=min(pnode->l->mini,pnode->r->mini);
	}
}

int cari(int u, int ki, int ka, node* pnode){
	if(ki>u) return 1e9+1;
	if(ka<=u){
		return pnode->mini;
	}else{
		int mid=(ki+ka)/2;
		return min(cari(u,ki,mid,pnode->l),cari(u,mid+1,ka,pnode->r));
	}
}

int main(){
	/* Fast IO */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
		a[i]--;
	}
	root=buat(1,n);
	
	int b[n+1],jaw=0;
	memset(b,0,sizeof b);
	int m;
	cin>>m;
	for(int i=1; i<=m; i++){
		int x;
		cin>>x;
		int l=1,r=n+1;
		while(l<r){
			int mid=(l+r)/2;
			int val=cari(mid, 1, n, root);
		//	cout<<l<<' '<<r<<' '<<val<<endl;
			if(val<x){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		if(r==n+1) continue;
		if(b[l]==0){
			jaw++;
		}
		b[l]=1;
		upd(l,1,n,root,x);
		//cout<<l<<endl;
	}
	cout<<jaw<<endl;
}
