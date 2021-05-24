#include <iostream>

using namespace std;

class sll_node {

public:
	int data;
	sll_node *next;

};

void insert_at_end(sll_node* &head , int data) {

	sll_node* newNode = new sll_node;
	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL) {
		head = newNode;
	} else {

		sll_node* temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newNode;
		temp = newNode;

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

	sll_node *head = NULL;

	int choice;

	do {

		int data;
		cout << "Enter the data to insert : ";
		cin >> data;

		insert_at_end(head , data);

		cout << "The data is : ";
		display(head);

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);


	return 0;
}