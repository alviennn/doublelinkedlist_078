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