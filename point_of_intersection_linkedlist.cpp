/*
get number of nodes of each linked list
say c1 of first and c2 of second
then find difference of list:-
d=c1-c2;
traverse d nodes from longer list then traverse both list subseuqntially
and compare address of both nodes is same we got the intersection point;
*/
#include<iostream>
#include<bits/stdc++.h>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	int num1=0,num2=0;
    	ListNode* nav1=headA;
    	ListNode* nav2=headB;
    	while(nav1!=NULL){
    		num1++;
    		nav1=nav1->next;
    	}
    	while(nav2!=NULL){
    		num2++;
    		nav2=nav2->next;
    	}
    	nav1=headA;//resetting our iterator
    	nav2=headB;
    	int diff=num1-num2;
    	if(diff>0){
    		//first node is longer
    		while(diff>0){
    			nav1=nav1->next;
    			diff--;
    		}
    	}else{
    		diff=abs(diff);
    		while(diff>0){
    			nav2=nav2->next;
    			diff--;
    		}
    	}
    	//now we can traverse all list together
    	while(nav1!=NULL&& nav2!=NULL){
    		if(nav1->next==nav2->next)
    			return nav1->next;
    		nav1=nav1->next;
    		nav2=nav2->next;
    	}
    	return NULL;    	
    }
};