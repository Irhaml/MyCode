#include<bits/stdc++.h>
using namespace std;

// Menggunakan Euclidean Algorithm
long long fpb(long long x, long long y){
	if(x==0) return y;
	else return fpb(y%x,x);
}

int main(){
	long long a,b,c,d;
	cout<<"Masukkan pembilang angka pertama: ";
	cin>>a;
	cout<<"Masukkan penyebut angka pertama: ";
	cin>>b;
	cout<<"Masukkan pembilang angka kedua: ";
	cin>>c;
	cout<<"Masukkan penyebut angka kedua: ";
	cin>>d;
	
	long long pembilang = a*d + c*b;
	long long penyebut = b*d;
	
	long long faktor = fpb(pembilang, penyebut);
	pembilang /= faktor;
	penyebut /= faktor;
	
	cout<<"Jumlah kedua pecahan adalah "<<pembilang<<'/'<<penyebut<<'.'<<endl;
	
	
}
