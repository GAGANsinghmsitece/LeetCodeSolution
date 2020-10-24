#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib.h>
using namespace std;
double findPower(double x, int n){
	//brute force
	double result=x;
	while(n>1){
		result*=x;
		n--;
	}
	return result;
}
double findPower(double x, long int n){
	//optimal
	if(n==1)return x;
	double result;
	if(n%2==0){
		result=findPower(x*x,n/2);
	}else{
		result=x*findPower(x*x,n/2);
	}
	return result;
}
double myPow(double x, int n) {
	if (n==0)return 1.00000;
	if(n<0){
		long int num=n;
		return 1/findPower(x,0-num);
	}
	else return findPower(x,n);
}
int main(){
	double x=2.00000;
	int n=-2;
	cout<<"value of x is "<<x<<" and value of n is "<<n<<"\n";
	cout<<"The final answer is "<<myPow(x,n);
}