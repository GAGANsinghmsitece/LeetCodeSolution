#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<vector>
using namespace std;
vector<vector<int>> PascalTriangle(int numrows){
	vector<vector<int>> res;
	if(numrows>0){
		vector<int> first;
		first.push_back(1);
		res.push_back(first);
	}
	for(int i=0;i<numrows-1;i++){
		vector<int> row;
		row.push_back(1);
		for(int j=1;j<=i;j++){
			int temp=res[i][j]+res[i][j-1];
			row.push_back(temp);
		}
		row.push_back(1);
		res.push_back(row);
	}
	return res;
}
void Print2DVector(vector<vector <int>>arr){
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[i].size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int r;
	cin>>r;
	vector<vector<int>> res=PascalTriangle(r);
	Print2DVector(res);
	return 0;
}