#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
    	if(head==NULL)
            return false;
        ListNode* tortoise=head;
    	ListNode* hare=head->next;
    	while(tortoise!=hare){
    		if(hare==NULL || hare->next==NULL)
    			return false;
    		hare=hare->next->next;
    		tortoise=tortoise->next;
    	}
    	return true;
    }
};