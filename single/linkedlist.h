#include <iostream>
#include <string>
using namespace std;

#pragma once

struct node{
	double data;
	node* next;
};

class linkedlist{
private:
	node* head;
	int size;
public:
	linkedlist();
	linkedlist(double val);
	~linkedlist();
	linkedlist(const linkedlist& rhs);
	linkedlist& operator=(const linkedlist& rhs);
	void printList() const;
	void pushFront(double value);
	void pushBack(double value);
	void popFront();
	void popBack();
	void insert(int index, double value);
	void deleteDuplicates(double value);
	double mtoLastElement(int m) const;
	int Size() const;
	friend ostream& operator<<(ostream& out, const linkedlist& rhs);
	void reverseList();

};