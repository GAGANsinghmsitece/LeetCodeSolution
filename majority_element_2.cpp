#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/*int majority_element(vector<int>arr){
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
}*/
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
	vector<int> arr={1};
	vector<int> result=majority_element(arr);
	PrintVector(result);
}