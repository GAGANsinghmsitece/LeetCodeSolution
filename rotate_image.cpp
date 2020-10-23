#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void Print2DVector(vector<vector <int>>arr){
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[i].size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
vector<vector<int>> RotateMatrix(vector<vector <int>>arr){
	int n=arr.size();
	for(int i=0;i<n;i++){//generating transpose
		for(int j=0;j<i;j++){
			cout<<i<<" "<<j<<endl;
			swap(arr[i][j],arr[j][i]);
		}
	}
	for(int i=0;i<n;i++)
		reverse(arr[i].begin(),arr[i].end());
	return arr;
}
int main(){
	vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
	cout<<"Original vector"<<endl;
	Print2DVector(arr);
	arr=RotateMatrix(arr);
	cout<<"New Matrix"<<endl;
	Print2DVector(arr);
}