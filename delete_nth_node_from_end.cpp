#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node *next;
};
class linked_list {
private:
	Node *head;
public:
	linked_list() {
		head = NULL;
	}
	Node* head_() {
		Node* temp = head;
		return temp;
	}
	void Modify_head(Node* h1) {
		head = h1;
	}
	void InsertAtBeginning(int value) {
		Node* temp = new Node();
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void InsertAtEnd(int value) {
		Node* temp = head;
		Node* temp1 = new Node();
		temp1->data = value;
		temp1->next = NULL;
		if (head == NULL) {
			temp1->next = head;
			head = temp1;
			return;
		}
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = temp1;
	}
	void InsertAtSomePosition(int value, int pos) {
		//we are using 1-based indexing thus first element will be treated as 1 not 0
		Node* temp = new Node();
		temp->data = value;
		if (pos == 1) {
			temp->next = head;
			head = temp;
			return;
		}
		Node* temp2 = head;
		for (int i = 0; i < pos - 2; i++) {
			temp2 = temp2->next;
		}
		temp->next = temp2->next;
		temp2->next = temp;
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
	void Print() {
		Node* temp = head;
		cout << "The list is :" << "\n";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
	void DeleteAtPosition(int pos) {
		if (pos == 1) {
			Node* temp = new Node();
			temp = head;
			head = temp->next;
			delete temp;
			return;
		}
		Node* temp1 = new Node();
		temp1 = head;
		for (int i = 0; i < pos - 2; i++)
			temp1 = temp1->next;
		Node* temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
	}
	void PrintByRecursion(Node* p) {
		if (p == NULL) {
			cout << "\n";
			return;
		}
		cout << p->data << " ";
		PrintByRecursion(p->next);
	}
	void PrintReverseByRecursion(Node* p) {
		if (p == NULL) {
			return;
		}
		PrintReverseByRecursion(p->next);
		cout << p->data << " ";
	}
	void ReverseByRecursion(Node *p) {
		if (p->next == NULL) {
			head = p;
			return;
		}
		ReverseByRecursion(p->next);
		Node* q = p->next;
		q->next = p;
		p->next = NULL;
	}
};
Node* removeNthFromEnd(Node* head, int n) {
	int count = 0;
	Node* temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	if (count == n) {
		Node* temp1 = head;
		head = temp1->next;
		delete temp1;
		return head;
	}
	temp = head;
	for (int i = 0; i < count - n - 1; i++)
		temp = temp->next;
	cout << temp->data << endl;
	cout << "hola" << endl;
	Node* temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
	return head;
}
int main() {
	linked_list a;
	a.InsertAtBeginning(5);
	a.InsertAtBeginning(4);
	a.InsertAtBeginning(3);
	a.InsertAtBeginning(2);
	a.InsertAtBeginning(1);
	a.Print();
	a.Modify_head(removeNthFromEnd(a.head_(), 5));
	a.Print();
}