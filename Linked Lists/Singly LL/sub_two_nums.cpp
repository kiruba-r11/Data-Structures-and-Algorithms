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

sll_node* sub_two_nums(sll_node* head1 , sll_node* head2) {

	sll_node* dummy = new sll_node();
	dummy->data = -1;
	dummy->next = NULL;

	sll_node* temp = dummy;
	temp->next = head1;

	int borrow = 0;
	while(head1 != NULL && head2 != NULL) {
		int val = (head1->data - head2->data) + borrow;
		if(val < 0) {
			borrow = -1;
			val += 10;
		} else {
			borrow = 0;
		}
		head1->data = val;
		head1 = head1->next;
		head2 = head2->next;
	}

	while(head1 != NULL) {
		int val = (head1->data) + borrow;
		if(val < 0) {
			borrow = -1;
			val += 10;
		} else {
			borrow = 0;
		}
		head1->data = val;
		head1 = head1->next;
	}
	return dummy->next;
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

	head1 = sub_two_nums(head1 , head2);

	cout << "The result is : ";
	display(head1);

	return 0;
}