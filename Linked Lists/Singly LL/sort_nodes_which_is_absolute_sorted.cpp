#include <iostream>

using namespace std;

class sll_node {
public: 
	int data;
	sll_node* next;
};

void display(sll_node* head);

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

void reverse(sll_node* &head) {

	if(head == NULL && head->next == NULL)
		return;

	sll_node *p = NULL , *q = head , *r = head->next;
	while(r != NULL) {
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;
	head = q;
}

void sort_nodes(sll_node* &head) {

	if(head == NULL || head->next == NULL)
		return;

	sll_node *temp , *temp1 = NULL , *head1;

	if(head->data < 0) {
		temp1 = head;
		while(head != NULL && head->next != NULL && head->next->data < 0) {
			head = head->next;
		}
		head1 = temp1;
		temp1 = head;
		if(head != NULL)
			head = head->next;
	} 
	temp = head;
	while(temp != NULL && temp->next != NULL) {
		while(temp != NULL && temp->next != NULL && temp->next->data < 0) {
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
	temp = head1;
	reverse(head1);
	temp->next = head;
	head = head1;
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

	cout << "Before sorting : " << endl;
	display(head);

	sort_nodes(head);

	cout << "After sorting : " << endl;
	display(head);

	return 0;
}