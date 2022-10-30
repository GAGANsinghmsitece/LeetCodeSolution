#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>


using namespace std;

/* Implementing Stack */
template<typename T>
struct Node {
	T data;
	Node* next;
};
template<typename T>
class Stack {
private:
	Node<T> *front, *bottom;
	int length;
public:
	Stack() {
		Node<T>* l = new Node<T>();
		front = l;
		bottom = l;
		length = 0;
	}
	bool is_segment() {
		Node<T>* p = front;
		while (p != bottom) {
			if (p == NULL)return false;
			p = p->next;
		}
		return true;
	}
	bool is_stack() {
		if (front == NULL || bottom == NULL)return false;
		return is_segment();
	}
	bool is_empty() {
		return front == bottom;
	}
	void push(int ele) {
		Node<T>* l = new Node<T>();
		l->data = ele;
		l->next = front;
		front = l;
		length++;//Incrementing size
	}
	T pop() {
		if (!is_empty()) {
			T ele = front->data;
			front = front->next;
			length--;
			return ele;
		} else {
			throw invalid_argument("Cannot delete!!! Stack is empty");
		}
	}
	void print() {
		if (!is_empty()) {
			cout << "The stack is " << endl;
			Node<T>* p = front;
			while (p != bottom) {
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
	int size() {
		/*O(1) */
		return length;
		/*  O(N) approach

			T count=0;
			Node<T>* p= front;
			while(p!=bottom){
				count++;
				p=p->next;
			}
			return count;
		*/
	}
	T top() {
		if (!is_empty())
			return front->data;
		else
			throw invalid_argument("Cannot peek!!! Stack is empty");
	}
	bool is_circular() {
		Node<T>* t = front;
		Node<T>* h = front->next;
		while (t != h) {
			if (h == NULL || h->next == NULL)return false;
			t = t->next;
			h = h->next->next;
		}
		return true;
	}
};

int main()
{
	Stack<char> s;
	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.print();
	cout << s.size() << endl;
	s.pop();
	s.print();
	cout << s.size() << endl;
}
