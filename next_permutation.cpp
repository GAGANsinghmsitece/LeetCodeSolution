#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> nextPermutation(vector<int> arr){
	int index1=-1,index2;
	for(int i=arr.size()-2;i>=0;i--)
		if(arr[i]<arr[i+1]){
			index1=i;
			break;
		}
	if(index1>=0){
	for(int i=arr.size()-1;i>=0;i--)
		if(arr[index1]<arr[i]){
			index2=i;
			break;
		}
	swap(arr[index1],arr[index2]);
	reverse(arr.begin()+index1+1,arr.end());
	}else{
	reverse(arr.begin(),arr.end());
	}
	return arr;
}
void PrintVector(vector<int> arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
}
int main(){
	vector<int> arr={1};
	arr=nextPermutation(arr);
	PrintVector(arr);
	return 0;
}