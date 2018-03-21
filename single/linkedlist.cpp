#include "linkedlist.h"

linkedlist::linkedlist(){
	head = NULL;
	size = 0;
}

linkedlist::linkedlist(double val){
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	head = temp;
	size = 1;
}

linkedlist::linkedlist(const linkedlist& rhs){
	if (rhs.head == NULL){
		head = NULL;
		size = 0;
	}
	else{
		node* rhshead = rhs.head;
		node* temp = new node;
		head = temp;
		head->data = rhshead->data;
		head->next = NULL;
		rhshead = rhshead->next;
		size = 1;

		while (rhshead != NULL){
			node* second = new node;
			second->data = rhshead->data;
			second->next = NULL;
			temp->next = second;
			temp = temp->next;
			rhshead = rhshead->next;
			size++;
		}
	}
}

linkedlist::~linkedlist(){
	
	//cout << "in destructor" << endl;
	if (head == NULL)
		return;
	node* temp;
	while (head != NULL){
		temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
	}
	head = NULL;
	size = 0;
}

linkedlist& linkedlist::operator=(const linkedlist& rhs){
	if (rhs.head == NULL){
		node* tempDelete;
		while (head != NULL){
			tempDelete = head;
			head = head->next;
			delete tempDelete;
			tempDelete = NULL;
		}
		head = NULL;
		size = 0;
	}

	else{
		node* tempDelete;
		while (head != NULL){
			tempDelete = head;
			head = head->next;
			delete tempDelete;
			tempDelete = NULL;
		}
		head = NULL;
		size = 0;
		node* rhshead = rhs.head;
		node* temp = new node;
		//temp->data = rhshead->data;
		head = temp;
		head->data = rhshead->data;
		head->next = NULL;
		rhshead = rhshead->next;
		//node* link = head;
		size = 1;

		while (rhshead != NULL){
			node* second = new node;
			second->data = rhshead->data;
			second->next = NULL;
			temp->next = second;
			temp = temp->next;
			rhshead = rhshead->next;
			size++;
		}
	}
	return *this;
}

void linkedlist::printList()const{
	node* walk = head;
	if (size == 0)
		cout << "List is empy." << endl;
	else{
		while (walk != NULL){
			cout << walk->data << " ";
			//walk->data = 4;
			walk = walk->next;
		}
	}
	cout << endl;
	//cout << "this-> " << this << endl;
}

void linkedlist::pushFront(double val){
	node* first = new node;
	first->data = val;
	first->next = head;
	head = first;
	size++;
}

void linkedlist::pushBack(double val){
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;

	if (head == NULL)
		head = temp;
	else{
		node* last = head;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
	}
	size++;
}

void linkedlist::popFront(){
	if (head == NULL)
		return;
	else if (size == 1){
		delete head;
		head = NULL;
		size--;
	}
	else{
		node* first = head;
		head = head->next;
		delete first;
		first = NULL;
		size--;
	}
}

void linkedlist::popBack(){
	node* temp = new node;

	if (head == NULL)
		return;
	else if (size == 1){
		delete head;
		head = NULL;
		size--;
	}
	else{
		node* last = head;
		while (last->next->next != NULL)
			last = last->next;
		temp = last->next;
		delete temp;
		temp = NULL;
		size--;
		last->next = NULL;
	}
}

void linkedlist::insert(int index, double value){
	node* temp = new node;
	temp->data = value;
	node* previous = head;
	int counter = 0;

	if (index == 0)
		pushFront(value);
	else if (index > (size - 1))
		pushBack(value);
	else{
		while (counter != index){
			counter++;
			if (counter == index){
				temp->next = previous->next;
				previous->next = temp;
				size++;
			}
			else
				previous = previous->next;
		}
	}
}

void linkedlist::deleteDuplicates(double value){
	while (head->data == value){
		popFront();
		if (size == 0)
			return;
	}
	node* temp = head;
	node* deleter = head;

	if (head == NULL)
		return;
	while (temp->next != NULL){
		deleter = deleter->next;
		if (deleter->data == value){
			temp->next = deleter->next;
			delete deleter;
			deleter = temp;
			size--;
		}
		else{
			temp = temp->next;
		}
	}
	deleter = NULL;
}

double linkedlist::mtoLastElement(int m) const{
	node* temp = head;
	int counter = 0;
	if (m >= size || m < 0)
		cout << "m is invalid" << endl;
	else{
		while (counter != (size - m)){
			if (counter == ((size - 1) - m)){
				return temp->data;
			}
			else{
				temp = temp->next;
				counter++;
			}
		}
	}
}

int linkedlist::Size() const{
	return size;
}

ostream& operator<<(ostream& out, const linkedlist& rhs){
	rhs.printList();
	return out;
}

void linkedlist::reverseList(){
	if (head == NULL)
		cout << "List is empty, nothing to reverse." << endl;
	else{
		node* temp = head;
		node* swap = head;
		double tempData;
		int counter1 = size - 1;
		int counter2 = size - 1;

		for (int i = 0; i != (size / 2); i++){
			counter1 = counter2;
			while (counter1 != 0){
				temp = temp->next;
				counter1--;
			}
			counter2--; // Used to put temp in correct spot each iteration of traversing
			//Algorithm for swapping values
			tempData = temp->data;
			temp->data = swap->data;
			swap->data = tempData;

			swap = swap->next; // Moves swap forward by one each time data is swapped
			temp = head; // Sets temp back to beginning to reiterate to the the spot before last temp spot
		}
	}
}