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
    bool isPalindrome(ListNode* head) {
    	vector<int> arr;
    	ListNode* temp=head;
    	while(temp!=NULL){
    		arr.push_back(temp->val);
    		temp=temp->next;
    	}
    	int n=arr.size();
    	if(n%2==0){
    		for(int i=0;i<n/2;i++)
    			if(arr[i]!=arr[n-i-1])
    				return false;
    	}else{
    		for(int i=0;i<n/2+1;i++)
    			if(arr[i]!=arr[n-i-1])
    				return false;
    	}
    	return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
       ListNode* slow = head;
       while(fast != NULL && fast -> next != NULL){
           slow = slow->next;
           fast = fast -> next -> next;
       }
       
       //reversing last half linked list
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != slow)
        {
           ListNode* temp = curr->next;
           curr->next = prev;
           prev = curr;
           curr = temp;  
        }
       //for odd LL
       if(fast)
           slow = slow->next;
       
       while(slow!=NULL && prev != NULL){
           if(slow -> val != prev->val)
               return false;
           slow = slow->next;
           prev = prev->next;
       }
       return true;
   }

};