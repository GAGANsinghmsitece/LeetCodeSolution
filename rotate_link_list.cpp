#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		int prevdata = head->val;
		int temp1 = 0;
		ListNode* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			temp1 = temp->val;
			temp->val = prevdata;
			prevdata = temp1;
		}
		head->val = prevdata;
	}
};