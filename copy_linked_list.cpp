#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//tle but gives o(1)
class Solution {
    map<Node*,Node*>h1;
public:
    Node* copyRandomList(Node* head){
        Node* temp=head;
        Node* new_head=new Node(-1);
        Node* new_temp=new_head;
        while(temp!=NULL){
            Node *node=new Node(temp->val);
            new_temp->next=node;
            new_temp=new_temp->next;
            h1[temp]=node;
            temp=temp->next;
        }
        temp=head;
        new_temp=new_head->next;
        while(temp!=NULL){
            new_temp->random=temp->random?h1[temp->random]:temp->random;
            new_temp=new_temp->next;
            temp=temp->next;
        }
        return  new_head->next;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head){
    	Node* temp= head;
    	Node* next=temp->next;
    	while(temp!=NULL){
    		Node* ele=new Node(temp->val);
    		temp->next=ele;
    		ele->next=next;
    		temp=next;
    	}
    	temp=head;
    	while(temp!=NULL){
    		if(temp->next!=NULL)
    			temp->next->random=temp->random?temp->random->next:temp->random;
    		temp=temp->next?temp->next->next:temp->next;
    	}
    	Node *original=head,*copy=head->next;
    	temp=copy;
    	while(original && copy){
    		original->next=original->next?original->next->next:original->next;
    		copy->next=copy->next?copy->next->next:copy->next;
    		original=original->next;
    		copy=copy->next;
    	}
    	return temp;   
    }
};