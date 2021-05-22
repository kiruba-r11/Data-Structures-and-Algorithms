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

void alternate_even_odd(sll_node* &head) {

	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return;

	sll_node *temp = head , *temp1 = NULL , *head1;

	int check = head->data % 2;

	while(temp != NULL && temp->next != NULL) {
		while(temp != NULL && temp->next != NULL && (temp->next->data % 2) != check) {
			if(temp1 == NULL) {
				temp1 = temp->next;
				head1 = temp1;
			} else {
				temp1->next = temp->next;
				temp1 = temp1->next;
			}
			temp->next = temp->next->next;
		}
		temp = temp->next;
	}

	temp1->next = NULL;
	temp1 = head;
	temp = head;
	
	sll_node *temp2 = head1;

	while(temp != NULL) {
		temp1 = temp1->next;
		temp->next = temp2;
		temp = temp->next;
		if(temp1 == NULL)
			return;
		temp2 = temp2->next;
		temp->next = temp1;
		temp = temp->next;
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

	sll_node* head = NULL;

	createSLL(head);

	cout << "Before rearrangement : " << endl;
	display(head);

	alternate_even_odd(head);

	cout << "After rearrangement : " << endl;
	display(head);

	return 0;
}