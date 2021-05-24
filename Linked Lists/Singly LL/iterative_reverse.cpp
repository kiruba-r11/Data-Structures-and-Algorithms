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

void reverseSLL(sll_node* &head) {

	if(head == NULL)
		return;


	sll_node* p = NULL;
	sll_node* q = head;
	sll_node* r = head->next;

	while(r != NULL) {
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}

	q->next = p;
	head = q;
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

	cout << "Before reversing : " << endl;

	display(head);

	reverseSLL(head);

	cout << "After reversing : " << endl;

	display(head);

	return 0;
}