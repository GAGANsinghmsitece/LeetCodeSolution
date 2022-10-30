#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int value;
	Node* next;
};
Node* head = NULL;
void Insert(int val) {
	Node* temp = new Node();
	temp->value = val;
	temp->next = head;
	head = temp;
}
void Print() {
	Node* temp = new Node();
	temp = head;
	while (temp != NULL) {
		cout << temp->value << "->";
		temp = temp->next;
	}
}
void Reverse() {
	Node* prev = NULL;
	Node* current = head;
	Node* next = new Node();
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}
int main() {
	Insert(1);
	Insert(2);
	Insert(5);
	Insert(6);
	Print();
}