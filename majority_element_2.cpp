#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> majority_element(vector<int>arr){
	//Boyor's Voting algorithm(Optimised approach)
	int c1=0,c2=0,ele1=-1,ele2=-1,n=arr.size();
	vector<int> result;
	for(int i=0;i<arr.size();i++){
		if(arr[i]==ele1)c1++;
		else if(arr[i]==ele2)c2++;
		else if(c1==0){
			ele1=arr[i];
			c1=1;
		}
		else if(c2==0){
			ele2=arr[i];
			c2=1;
		}else{
			c1--;c2--;
		}
	}
	c1=0;c2=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]==ele1)c1++;
		if(arr[i]==ele2)c2++;
	}
	if(c1>n/3)
		result.push_back(ele1);
	if(c2>n/3)
		result.push_back(ele2);
	return result;
}
vector<int> majority_element(vector<int>arr){
	//brute force
	int n=arr.size();
	vector<int> result;
	sort(arr.begin(),arr.end());
	int count=1,maxcount=1;
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1])
			count++;
		else{
			if(count>n/3){
				result.push_back(arr[i]);
			}
			count=1;
		}
	}
	if(count!=1 || n/3==0){
		if(count>n/3)result.push_back(arr[n-1]);
	}
	if(arr.size()==1)
		return arr;
	return result;
}
void PrintVector(vector<int> arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
}
int main(){
	vector<int> arr={3,2,3};
	vector<int> result=majority_element(arr);
	PrintVector(result);
}