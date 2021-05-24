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

void merge_alternatively(sll_node* &head1 , sll_node* head2) {

	if(head1 == NULL && head2 == NULL)
		return;

	if(head1 == NULL) {
		head1 = head2;
		return;
	}

	if(head2 == NULL) {
		return;
	}

	sll_node* temp = head1;
	sll_node* temp1 = head1;
	sll_node* temp2 = head2;

	while(temp != NULL) {
		temp1 = temp->next;
		temp->next = temp2;
		temp = temp2;
		if(temp1 == NULL)
			return;
		temp2 = temp->next;
		temp->next = temp1;
		temp = temp1;
		if(temp2 == NULL)
			return;
	}

}

void display(sll_node* head) {
	cout << "The elements are : ";
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}

int main() {

	sll_node* head1 = NULL;
	sll_node* head2 = NULL;

	cout << "Create SLL - 1 : ";
	createSLL(head1);

	cout << "Create SLL - 2 : ";
	createSLL(head2);

	cout << "SLL - 1 : " << endl;
	display(head1);

	cout << "SLL - 2 : " << endl;
	display(head2);

	merge_alternatively(head1 , head2);

	cout << "After Merging : " << endl;
	display(head1);

	return 0;
}