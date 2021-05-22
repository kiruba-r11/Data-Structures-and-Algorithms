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

bool isIdentical(sll_node* head1 , sll_node* head2) {

	if(head1 == NULL && head2 == NULL)
		return true;

	if(head1 == NULL || head2 == NULL)
		return false;

	while(head1 != NULL && head2 != NULL) {
		if(head1->data != head2->data)
			return false;
		head1 = head1->next;
		head2 = head2->next;
	}

	if(head1 != NULL)
		return false;
	if(head2 != NULL)
		return false;

	return true;
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

	cout << "Create SLL - 1" << endl << endl;
	createSLL(head1);

	cout << endl;
	cout << "Create SLL - 2" << endl << endl;
	createSLL(head2);

	cout << "SLL - 1 is : " << endl << endl;
	display(head1);

	cout << "SLL - 2 is : " << endl << endl;
	display(head2);

	bool check = isIdentical(head1 , head2);
	if(check) 
		cout << "The SLL - 1 and 2 are identical";
	else
		cout << "The SLL - 1 and 2 are not identical";
	cout << endl;

	return 0;
}