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
/*bool Search2DMatrix(vector<vector <int>>arr,int target){
	bruteforce
	int n=arr.size(),TargetRow=-1;
	bool isFounded=false;
	if(n==0)return false;
	if(arr[0].size()==0)return false;
	if(n==1)
		TargetRow=0;
	else
	for(int i=1;i<n;i++){
		if(arr[i][0]>target){
			TargetRow=i-1;
			break;
		}
		if(arr[i][0]==target){
			isFounded=true;
			return isFounded;
		}
	}
	if(TargetRow!=-1)
	for(int j=0;j<arr[0].size();j++){
		if(arr[TargetRow][j]==target){
			isFounded=true;
			break;
		}
	}
    if(isFounded==false){
        TargetRow=n-1;
	for(int j=0;j<arr[0].size();j++){
		if(arr[TargetRow][j]==target){
			isFounded=true;
			break;
		}
	}
    }
	return isFounded;
}*/
bool Search2DMatrix(vector<vector <int>>arr,int target){
	int i=0,n=arr.size();
    if(n>0){
    	int j=arr[0].size()-1;
    	while(i<n && j>=0){
    		if(arr[i][j]==target)
    			return true;
    		if(arr[i][j]>target)
    			j--;
    		else
    			i++;
    	}
    }
	return false;
}
int main(){
	vector<vector<int>> arr={{1},{3}};
	int target=4;
	cout<<"Original vector"<<endl;
	Print2DVector(arr);
	int var=Search2DMatrix(arr,target);
	if(var==true)
		cout<<"is Present: true"<<endl;
	else
		cout<<"is Present: false"<<endl;
}