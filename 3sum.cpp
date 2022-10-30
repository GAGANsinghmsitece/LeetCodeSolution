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

/*vector<vector<int>> threeSum(vector<int> nums){
	//this method is correct but it may return same triplets
	vector<vector<int>> res;
	for(int i=0;i<nums.size();i++){
		set<int> s;
		for(int j=i+1;j<nums.size();j++){
			if(s.find(0-nums[i]-nums[j])!=s.end()){;
				vector<int> arr;
				arr.push_back(nums[i]);
				arr.push_back(nums[j]);
				arr.push_back(0-nums[i]-nums[j]);
				res.push_back(arr);
			}
			s.insert(nums[j]);
		}
	}
	return res;
}*/
vector<vector<int>> threeSum(vector<int> nums){
	//2 pointer approach
	vector<vector<int>> res;
	sort(nums.begin(),nums.end());
	int n=nums.size();
	set<vector<int>>s;
	for(int i=0;i<n-2;i++){
		int l=i+1;int r=n-1;
		while(l<r){
			int sum=nums[i]+nums[l]+nums[r];
			if(sum==0){
				s.insert(vector<int>({nums[i],nums[l],nums[r]}));
				l++;
				r--;
			}
			else if(sum>0)
				r--;
			else 
				l++;
		}
	}
	return vector<vector<int>>(s.begin(),s.end());
}
int main(){
	vector<int> arr={-1,0,1,2,-1,-4};
	vector<vector<int>> res=threeSum(arr);
	Print2DVector(res);
}