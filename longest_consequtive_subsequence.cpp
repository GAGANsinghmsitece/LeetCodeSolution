#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longest_subsequence(vector<int> arr) {
	if (arr.size() == 0)
		return 0;
	set<int> s;
	for (int i = 0; i < arr.size(); i++)
		s.insert(arr[i]);
	set<int>::iterator itr, prev;
	itr = s.begin();
	prev = itr;
	++itr;
	int count = 1, maxcount = 1;
	for (; itr != s.end(); ++itr) {
		if (abs(*itr - *prev) == 1)
			count++;
		else {
			if (maxcount < count)
				maxcount = count;
			count = 1;
		}
		prev = itr;
	}
	if (count > 1 && maxcount < count)
		maxcount = count;
	return maxcount;
}
int main() {
	vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
	sort(arr.begin(), arr.end());
	cout << longest_subsequence(arr);
	return 0;
}