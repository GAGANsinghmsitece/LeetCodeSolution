#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> intervals) {
	//nlogn time complexity 
	vector<vector<int>> result;
	vector<int> temp;
	if(intervals.size()>0){
		sort(intervals.begin(),intervals.end());
    	temp.push_back(intervals[0][0]);
    	temp.push_back(intervals[0][1]);
    	result.push_back(temp);
    	for(int i=1;i<intervals.size();i++){
    		if(result.back()[1]>=intervals[i][0]){
    			result.back()[1]=max(result.back()[1],intervals[i][1]);
    		}else{
    			temp.clear();
    			temp.push_back(intervals[i][0]);
    			temp.push_back(intervals[i][1]);
    			result.push_back(temp);
    		}
    	}
    }
    return result;
}
int main(){
	vector<vector<int>> temp {{2,3},{4,5},{6,7},{8,9},{1,10}};//{{1,3},{2,6},{8,10},{15,18}};
	temp=merge(temp);
	for(int i=0;i<temp.size();i++){
		for(int j=0;j<temp[i].size();j++){
			cout<<temp[i][j]<<" ";
		}
		cout<<endl;
	}
}