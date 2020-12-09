#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cout<<"Masukkan N: ";
	cin>>n;
	cout<<"Masukkan M: ";
	cin>>m;
	
	char a[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	
	cout<<"Hasil:"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<a[i][j];
		}
		for(int j=m-1; j>=0; j--){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<m; j++){
			cout<<a[i][j];
		}
		for(int j=m-1; j>=0; j--){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
