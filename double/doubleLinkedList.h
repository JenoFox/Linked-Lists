#include <iostream>
using namespace std;

#pragma once

struct node{
	int data;
	node* next;
	node* previous;
};

class doubleLinkedList{
private:
	node* head;
	node* tail;
	int size;
public:
	doubleLinkedList();
	doubleLinkedList(int val);
	~doubleLinkedList();
	doubleLinkedList(const doubleLinkedList& rhs);
	doubleLinkedList& operator=(const doubleLinkedList& rhs);
	void printList() const;
	void pushFront(int value);
	void pushBack(int value);
	void popFront();
	void popBack();
	void insert(int index, int value);
	void deleteDuplicates(int value);
	int mtoLastElement(int m) const;
	int Size() const;
	friend ostream& operator<<(ostream& out, const doubleLinkedList& rhs);
	void reverseList();
};