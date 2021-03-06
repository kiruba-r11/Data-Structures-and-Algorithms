#include <iostream>

using namespace std;

class dll_node {
public:
	dll_node* prev;
	int data;
	dll_node* next;
};

void createDLL(dll_node* &head) {

	int choice;

	dll_node* temp = head;

	do {

		int data;

		cout << "Enter Data : ";
		cin >> data;

		dll_node* newNode = new dll_node();
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;

		if(head == NULL) {
			head = newNode;
			temp = head;
		} else {
			temp->next = newNode;
			newNode->prev = temp;
			temp = newNode;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);


}

void reverse(dll_node* &head) {

	if(head == NULL || head->next == NULL)
		return;

	dll_node *p = NULL , *q = head , *r = head->next;
	while(r != NULL) {
		q->next = p;
		q->prev = r;
		p = q;
		q = r;
		r = r->next;
	}

	q->next = p;
	q->prev = r;
	head = q;
}

void display(dll_node* head) {
	cout << "The elements are : ";
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	dll_node* head = NULL;

	createDLL(head);

	cout << "Before reversal : " << endl;
	display(head);

	reverse(head);

	cout << "After reversal : " << endl;
	display(head);

	return 0;
}