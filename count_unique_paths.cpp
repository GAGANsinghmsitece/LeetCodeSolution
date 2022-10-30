#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/*int CountUniquePaths(int i,int j,int n,int m){
	//recursive solution
	if(i>=n || j>=m)return 0;
	else if(i==n-1 && j==m-1) return 1;
	else return CountUniquePaths(i+1,j,n,m)+CountUniquePaths(i,j+1,n,m);
}*/
int CountUniquePaths(int i, int j, int n, int m, vector<vector<int>> dp) {
	//recursive solution with dp
	if (i >= n || j >= m)return 0;
	else if (i == (n - 1) && j == m - 1)return 1;
	if (dp[i][j] == -1)
		return dp[i][j] = CountUniquePaths(i + 1, j, n, m, dp) + CountUniquePaths(i, j + 1, n, m, dp);
	else
		return dp[i][j];
}
int Combinations(int n, int r) {
	//optimised approach
	double res = 1;
	for (int i = 1; i <= r; i++)
		res = res * (n - r + i) / i;
	return (int)res;
}
int main() {
	int m = 3, n = 7;
	cout << "Total number of unique paths is " << Combinations(n + m - 2, m - 1);
}