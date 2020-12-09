#include<bits/stdc++.h>
using namespace std;


int main(){
	
	double m1,m2,c1,c2;
	
	m1 = 213.755;
	c1 = -1118166.707;
	m2 = -175.385;
	c2 = -223521;
	
	// Suhu dalam kelvin
	double k = (c2-c1)/(m1-m2);
	
	// Suhu dalam celcius
	double c = k-273;
	
	cout<<k<<endl;
	cout<<c<<endl;
}
