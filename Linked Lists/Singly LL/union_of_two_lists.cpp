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

sll_node* union_of_two_lists(sll_node* head1 , sll_node* head2) {

	if(head1 == NULL && head2 == NULL)
		return NULL;
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;

	sll_node* head3 = NULL;
	sll_node* temp = NULL;

	while(head1 != NULL && head2 != NULL) {
		if(head1->data < head2->data) {
			if(head3 == NULL) {
				head3 = head1;
				temp = head3;
			} else {
				temp->next = head1;
				temp = head1;
			}
			head1 = head1->next;
		} else if(head1->data > head2->data) {
			if(head3 == NULL) {
				head3 = head2;
				temp = head3;
			} else {
				temp->next = head2;
				temp = head2;
			}
			head2 = head2->next;
		} else {
			if(head3 == NULL) {
				head3 = head2;
				temp = head3;
			} else {
				temp->next = head2;
				temp = head2;
			}
			head1 = head1->next;
			head2 = head2->next;
		}
	}

	if(head1 != NULL) {
		temp->next = head1;
	}
	if(head2 != NULL) {
		temp->next = head2;
	}

	return head3;
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

	cout << "SLL - 1" << endl;
	display(head1);

	cout << "SLL - 2" << endl;
	display(head2);

	sll_node* head3 = union_of_two_lists(head1 , head2);
	cout << "Union is : " << endl;
	display(head3);

	return 0;
}