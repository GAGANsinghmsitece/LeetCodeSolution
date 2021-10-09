#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>


using namespace std;

/* Implementing Stack */
template<typename T>
struct Node{
	T data;
	Node* next;
};
template<typename T>
class Queue{
private:
	Node<T> *front,*back;
public:
	Queue(){
		Node<T>* l=new Node<T>();
		front=l;
		back=l;
	}
	bool is_segment(){
		Node<T>* p=front;
		while(p!=back){
			if(p==NULL)return false;
			p=p->next;
		}
		return true;
	}
	bool is_Queue(){
		if(front==NULL || back==NULL)return false;
		return is_segment();
	}
	bool is_empty(){
		return front==back;
	}
	void enque(T ele){
		back->data=ele;
		Node<T>* l=new Node<T>();
		back->next=l;
		back=l;
	}
	T dequeue(){
		if(!is_empty()){
			T ele=front->data;
			front=front->next;
			return ele;
		}else{
			throw invalid_argument("Cannot delete!!! Queue is empty");
		}
	}
	void print(){
		Node<T>* l=front;
		while(l!=back){
			cout<<l->data<<" ";
			l=l->next;
		}
		cout<<endl;
	}
	int size(){
		int count=0;
		Node<T>* l=front;
		while(l!=back){
			count++;
			l=l->next;
		}
		return count;
	}
	T peek(){
		if(!is_empty()){
			return front->data;
		}
		throw invalid_argument("Cannot peek !!! Queue is empty");
	}
	bool is_circular(){
		Node<T>* t=front;
		Node<T>* h=front->next;
		while(t!=h){
			if(h==NULL || h->next==NULL)return false;
			t=t->next;
			h=h->next->next;
		}
		return true;
	}
};
int main()
{
	Queue<string> q;
	cout<<q.size()<<endl;
	q.enque("ab");
	q.enque("bb");
	q.enque("cb");
	q.print();
	cout<<q.size()<<endl;
	q.dequeue();
	q.print();
}
