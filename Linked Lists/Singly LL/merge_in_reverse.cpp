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

sll_node* merge_in_reverse(sll_node* head1 , sll_node* head2) {
	if(head1 == NULL && head2 == NULL)
		return NULL;

	sll_node* head = new sll_node();
	head->data = -1;
	head->next = NULL;

	sll_node* temp = head;

	while(head1 != NULL && head2 != NULL) {
		if(head1->data < head2->data) {
			temp = head1;
			head1 = head1->next;
		} else {
			temp = head2;
			head2 = head2->next;
		}
		temp->next = head->next;
		head->next = temp;
	}

	while(head1 != NULL) {
		temp = head1;
		head1 = head1->next;
		temp->next = head->next;
		head->next = temp;
	}

	while(head2 != NULL) {
		temp = head2;
		head2 = head2->next;
		temp->next = head->next;
		head->next = temp;
	}

	return head->next;
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

	cout << "SLL - 1" << endl;
	createSLL(head1);

	cout << "SLL - 2" << endl;
	createSLL(head2);

	cout << "Before Merging : " << endl;
	display(head1);
	display(head2);

	cout << "After Merging : " << endl;
	sll_node* head = merge_in_reverse(head1 , head2);
	display(head);

	return 0;
}