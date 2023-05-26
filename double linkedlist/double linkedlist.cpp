#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class DoubleLinkedList {
private:
	node* START = NULL;
public:
	void addnode();
	bool search(int rollNo, node** previous, node** current);
	bool deletenode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

void DoubleLinkedList::addnode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;

	node* newnode = new node(); //step 1
	newnode->noMhs = nim; //step 2
	newnode->name = nm; //step 2

	/*insert a node in the begining of a doubly - list*/
	if (START == NULL || nim <= START->noMhs) { //check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newnode->next=START; //step 3
		if (START != NULL)
			START->prev = newnode; //step 4
		newnode->prev = NULL; //step 5
		START = newnode; //step 6
		return;
	}

	/*inserting a node between two nodes in the list*/
	node* current = START; //1.a
	node* previous = NULL; //1.b
	while (current->next != NULL && current->next->noMhs < nim) //step1.c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newnode->next = current->next; // step 4
	newnode->prev = current; //step 5
	if (current->next != NULL)
		current->next->prev = newnode; //step 6
	current->next = newnode; //step 7
}

bool DoubleLinkedList::search(int rollNo, node** previous, node** current) {
	*previous = NULL; //step 1.a
	*current = START; //step 1.b
	while (*current != NULL && (*current)->noMhs != rollNo) { //step 1.c
		*previous = *current; //step 1.d
		*current = (*current); //step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deletenode(int rollNo) {
	node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; //step 2
	if (previous != NULL)
		previous->next = current->next; //step 3
	else
		START = current->next;

	delete current; //step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are: " << endl;
		node* currentnode = START;
		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << currentnode->name << endl;
			currentnode = currentnode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	} 
	else {
		cout << "\nRecords in descending order of roll number are: " << endl;
		node* currentnode = START;
		while (currentnode->next != NULL)
			currentnode = currentnode->next;
		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << currentnode->name << endl;
			currentnode = currentnode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deletenode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << " deleted" << endl;
}
void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;

	}
	node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRecord number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all record in the ascending order of roll numbers" << endl;
			cout << "4. View all record in the descending order of roll numbers" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter tour choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addnode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.searchData();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "check for the values entered." << endl;
		}
	}
}

