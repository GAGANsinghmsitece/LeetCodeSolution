#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>


using namespace std;

class CircularDynamicQueue {
private:
	int *data, front, length, maxsize;
public:
	CircularDynamicQueue(int cap) {
		maxsize = cap;
		data = new int[cap];
		front = 0;
		length = 0;
	}
	void enqueue(int value) {
		if (length == maxsize) {
			int* data1 = new int[2 * maxsize];
			for (int i = 0; i < length; ++i)
			{
				cout << data[(front + i) % length] << " ";
				data1[i] = data[(front + i) % length];
			}

			front = 0;
			maxsize = 2 * maxsize;
			data = data1;
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
	CircularDynamicQueue q(2);
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
