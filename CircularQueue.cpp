#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>


using namespace std;

class CircularQueue {
private:
	int *data, front, length, maxsize;
public:
	CircularQueue(int cap) {
		maxsize = cap;
		data = new int[cap];
		front = 0;
		length = 0;
	}
	void enqueue(int value) {
		if (length == maxsize) {
			cout << "Queue overflow" << endl;
			return;
		}
		int index = (front + length) % maxsize;
		data[index] = value;
		length++;
	}
	int dequeue() {
		if (length == 0) {
			cout << "Queue underflow" << endl;
			return -1;
		}
		int value = data[front];
		front = (front + 1) % maxsize;
		length--;
		return value;
	}
	int size() {
		return length;
	}
	void display() {
		cout << "The Queue is:" << endl;
		for (int i = 0; i < length; i++) {
			int index = (front + i) % maxsize;
			cout << data[index] << " ";
		}
		cout << endl;
	}
	int peek() {
		return data[front];
	}
};

int main()
{
	cin >> ws;
	string str;
	getline(cin, str);
	CircularQueue q(10);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display();
	cout << q.dequeue() << endl;
	q.display();
	q.enqueue(10);
	q.display();
	cout << q.peek() << endl;

}
