#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int majority_element(vector<int>arr){
	//Moore's Voting algorithm(Optimised approach)
	int count=0,ele=0;
	for(int i=0;i<arr.size();i++){
		if(count==0)
			ele=arr[i];
		if(arr[i]==ele)
			count++;
		else
			count--;
	}
	return ele;
}
int majority_element(vector<int>arr){
	//brute force
	int n=arr.size();
	sort(arr.begin(),arr.end());
	int count=1,maxcount=1;
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1])
			count++;
		else{
			if(count>n/2)return arr[i];
		}
	}
	if(count!=1){
		if(count>n/2)return arr[n-1];
	}
	return arr[0];
}
int main(){
	vector<int> arr={2,2,1,1,1,2,2};
	int result=majority_element(arr);
	cout<<"The majority occurring element is "<<result;
}