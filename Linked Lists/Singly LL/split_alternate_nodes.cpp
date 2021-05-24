#include <iostream>

using namespace std;

class sll_node {
public: 
	int data;
	sll_node* next;
};

void createSLL(sll_node* &head) {

	int choice;
	sll_node* temp = head;

	do {

		int data;

		cout << "Enter Data : ";
		cin >> data;

		sll_node* newNode = new sll_node();
		newNode->data = data;
		newNode->next =  NULL;

		if(head == NULL) {
			head = newNode;
			temp = head;
		} else {
			temp->next = newNode;
			temp = newNode;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

}

void split_alternate_nodes(sll_node* head , sll_node* &head1) {

	if(head == NULL || head->next == NULL)
		return;

	head1 = head->next;
	sll_node* temp = head1;

	while(head != NULL && temp != NULL) {
		head->next = temp->next;
		if(head->next != NULL) {
			temp->next = head->next->next;
		} else {
			temp->next = NULL;
		}
		head = head->next;
		temp = temp->next;
	}

}

void display(sll_node* head) {

	int length = 0;
	cout << "The elements are : ";
	while(head != NULL) {
		length++;
		cout << head->data << " ";
		head = head->next;
	}

	if(length == 0)
		cout << "SLL is empty";
	cout << endl;
}

int main() {

	sll_node* head = NULL;

	createSLL(head);
	display(head);

	sll_node* head1 = NULL;
	split_alternate_nodes(head , head1);

	cout << "SLL - 1 : " << endl;
	display(head);

	cout << "SLL - 2 : " << endl;
	display(head1);

	return 0;
}