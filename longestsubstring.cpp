#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longest_subsequence(string arr){
	string res="";
	map<char,int> mp;
	int maxlen=0,start=0,end=0;
	while(end<arr.size()){
	if(mp.find(arr[end])!=mp.end()){
		//character is repeating;
		start=max(mp[arr[end]]+1,start);
	}
	mp[arr[end]]=end;
	maxlen=max(maxlen,end-start+1);
	end++;
	}
	return maxlen;
}
int main(){
	string str="bbtablud";
	cout<<longest_subsequence(str);
	return 0;
}