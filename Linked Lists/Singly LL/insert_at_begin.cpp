#include <iostream>

using namespace std;

class sll_node {

public:
	int data;
	sll_node* next;

};

void insert_at_begin(sll_node* &head , int data) {

	sll_node* newNode = new sll_node();
	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL) {
		head = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
}

void display(sll_node* head) {
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	int choice;

	sll_node *head = NULL;

	do {

		int data;

		cout << "Enter the data to insert : ";
		cin >> data;

		insert_at_begin(head , data);

		cout << "The elements is : ";
		display(head);

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

	return 0;
}