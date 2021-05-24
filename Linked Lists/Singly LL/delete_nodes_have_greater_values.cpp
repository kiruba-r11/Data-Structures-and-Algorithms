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

void reverse(sll_node* &head) {

	if(head == NULL || head->next == NULL)
		return;

	sll_node *p = NULL , *q = head , *r = q->next;
	while(r != NULL) {
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}

	q->next = p;
	head = q;
}

void delete_nodes(sll_node* &head) {

	reverse(head);

	if(head == NULL || head->next == NULL)
		return;

	sll_node* slow = head;
	sll_node* fast = head;

	while(fast != NULL) {
		while(fast->next != NULL && fast->next->data < slow->data) {
			fast = fast->next;
		}
		slow->next = fast->next;
		fast = fast->next;
		slow = fast;
	}

	reverse(head);

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

	cout << "Before deletion : " << endl;
	display(head);

	delete_nodes(head);

	cout << "After deletion : " << endl;
	display(head);

	return 0;
}