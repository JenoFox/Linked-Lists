#include "doubleLinkedList.h"

doubleLinkedList::doubleLinkedList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

doubleLinkedList::doubleLinkedList(int val){
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	temp->previous = NULL;
	head = temp;
	tail = temp;
	size = 1;
	cout << "head: " << head << "	tail: " << tail << endl;
}

doubleLinkedList::doubleLinkedList(const doubleLinkedList& rhs){
	if (rhs.head == NULL || rhs.tail == NULL){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	else{
		head = NULL;
		tail = NULL;
		size = 0;
		node* rhshead = rhs.head;
		node* temp = new node;
		head = temp;
		head->data = rhshead->data;
		head->next = NULL;
		head->previous = NULL;
		tail = head;
		rhshead = rhshead->next;
		size = 1;
		while (rhshead != NULL){
			pushBack(rhshead->data);
			rhshead = rhshead->next;
		}
	}
}

doubleLinkedList::~doubleLinkedList(){
	//cout << "in destructor" << endl;
	if (head == NULL || tail == NULL)
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

doubleLinkedList& doubleLinkedList::operator=(const doubleLinkedList& rhs){
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
		tail = NULL;
		size = 0;
		node* rhshead = rhs.head;
		node* temp = new node;
		head = temp;
		head->data = rhshead->data;
		head->next = NULL;
		head->previous = NULL;
		tail = head;
		rhshead = rhshead->next;
		size = 1;
		while (rhshead != NULL){
			pushBack(rhshead->data);
			rhshead = rhshead->next;
		}
	}
	return *this;
}

void doubleLinkedList::printList()const{
	node* walk = head;
	if (size == 1)
		cout << walk->data << " ";
	else if (size == 0)
		cout << "No elements within list." << endl;
	else{
		while (walk != NULL){
			cout << walk->data << " ";
			//walk->data = 4;
			walk = walk->next;
		}
	}
	cout << endl;
	//cout << "this-> " << this << "	size: " << size << endl;
}

void doubleLinkedList::pushFront(int val){
	if (size == 0){
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->previous = NULL;
		head = temp;
		tail = temp;
		size++;
	}
	else{
		node* first = new node;
		first->data = val;
		first->next = head;
		first->previous = NULL;
		head->previous = first;
		head = first;
		size++;
	}
}

void doubleLinkedList::pushBack(int val){
	if (size == 0){
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->previous = NULL;
		head = temp;
		tail = temp;
		size++;
	}
	else{
		node* last = new node;
		last->data = val;
		last->next = NULL;
		last->previous = tail;
		tail->next = last;
		tail = last;
		size++;
	}
}

void doubleLinkedList::popFront(){
	if (head == NULL || tail == NULL)
		return;
	else if (size == 1){
		delete head;
		tail = NULL;
		head = NULL;
		size--;
	}
	else{
		node* first = head;
		head = head->next;
		delete first;
		first = NULL;
		head->previous = NULL;
		size--;
	}
}

void doubleLinkedList::popBack(){
	if (tail == NULL || head == NULL)
		return;
	else if (size == 1){
		delete tail;
		tail = NULL;
		head = NULL;
		size--;
	}
	else{
		node* last = tail;
		tail = tail->previous;
		delete last;
		last = NULL;
		tail->next = NULL;
		size--;
	}
}

void doubleLinkedList::insert(int index, int value){
	node* temp = new node;
	temp->data = value;
	node* previous = head;
	node* after;
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
				after = temp->next;
				after->previous = temp;
				previous->next = temp;
				temp->previous = previous;
				size++;
			}
			else
				previous = previous->next;
		}
	}
}

void doubleLinkedList::deleteDuplicates(int value){
	while (head->data == value){
		popFront();
		if (size == 0)
			return;
	}
	node* temp = head;
	node* deleter = new node;
	deleter = head;
	node* frontOfDeleter;

	if (head == NULL)
		return;
	while (temp->next != NULL){
		deleter = deleter->next;
		if (deleter->next == NULL && deleter->data == value){
			deleter = NULL;
			popBack();
		}
		else if (deleter->data == value){
			frontOfDeleter = deleter->next;
			temp->next = frontOfDeleter;
			frontOfDeleter->previous = temp;
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

int doubleLinkedList::mtoLastElement(int m) const{
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

int doubleLinkedList::Size() const{
	return size;
}

ostream& operator<<(ostream& out, const doubleLinkedList& rhs){
	rhs.printList();
	return out;
}

void doubleLinkedList::reverseList(){
	if (head == NULL || tail == NULL)
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