#pragma once

class LinkedList
{
	struct node {
		node *prev;                 // previous node 
		node *next;                 // next node 
		int value;               // stored value 
	};
	node* head;         // Wska�nik do pierwszego w�z�a
	int length;

public:

	LinkedList();
	~LinkedList();
	void push_front(int value);
	int pop_front();
	void push_back(int value);
	int pop_back();
	int* find(int value);
	int front() {return head->next->value;}
	void push(int value) { push_back(value); }
	int pop() { return pop_front(); }
	int size();
	void display();
	int getValue(int i);
	bool empty()
	{
		return head->next == head;
	}
};

