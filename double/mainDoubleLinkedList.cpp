#include "doubleLinkedList.h"

void menu(){
	cout << "1) CopyConstructor\t" << "2) PushFront\t\t" << "3) PushBack\n" << "4) PrintUsingOperator\t";
	cout << "5) PopFront\t\t" << "6) PopBack\n" << "7) Insert(index, value)\t" << "8) DeleteDuplicates\t";
	cout << "9) mtoLastElement(m)\n" << "10) Size\t\t" << "11) ReverseList\t\t" << "12) AssignmentOperator\n";
	cout << "0) quit\t";
	cout << "\n\nPlease enter option number: ";
}

int main(){
	int index = 0;
	int option = 0;
	double value = 0;
	doubleLinkedList x;
	doubleLinkedList z;

	while (true){
		menu();
		cin >> option;
		if (option == 1)
		{
			cout << "Copy constructor called." << endl;
			doubleLinkedList y(x);
			cout << "First list contains: " << x;
			cout << "Copied list contains: " << y;
			continue;
		}
		switch (option)
		{
		case 0:
			cout << "Destructor called";
			exit(0);
			break;
		case 2: cout << "Insert the value in front: ";
			cin >> value;
			x.pushFront(value);
			break;;
		case 3: cout << "Insert values in the back: ";
			cin >> value;
			x.pushBack(value);
			break;
		case 5: cout << "Front value popped." << endl;
			x.popFront();
			break;
		case 6:cout << "Back value popped." << endl;
			x.popBack();
			break;
		case 7:cout << "Insert the index value: ";
			cin >> index;
			cout << "Enter the value to be inserted: ";
			cin >> value;
			x.insert(index, value);
			break;
		case 8: if (x.Size() == 0)
			cout << "List is empty, nothing to delete." << endl;
				else{
					cout << "Enter the value to be deleted along with all its copies: ";
					cin >> value;
					x.deleteDuplicates(value);
				}
			break;
		case 9: if (x.Size() == 0)
			cout << "List is empty, no mth element exists." << endl;
				else{
					cout << "Enter the mth value: ";
					cin >> index;
					x.mtoLastElement(index);
					cout << "Value is: " << x.mtoLastElement(index);
				}
			break;
		case 10:cout << "Size is: " << x.Size();
			break;
		case 11: if(x.Size() != 0)
			cout << "List reversed. ";
			x.reverseList();
			break;
		case 4: cout << "List 1: ";
			cout << x;
			break;
		case 12:cout << "Overloaded= called." << endl;
			z = x;
			cout << "rhs list is: " << x;
			cout << "assigned list is: " << z;
			break;
		default: cout << "Wrong input.Please try again." << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}