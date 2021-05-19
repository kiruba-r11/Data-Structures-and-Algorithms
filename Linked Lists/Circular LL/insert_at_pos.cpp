#include <iostream>

using namespace std;

class cll_node {
public: 
	int data;
	cll_node* next;
};

void createCLL(cll_node* &head) {

	int choice;

	cll_node* temp = head;

	do {
		int data;

		cout << "Enter Data : ";
		cin >> data;

		cll_node* newNode = new cll_node();
		newNode->data = data;
		newNode->next = NULL;

		if(head == NULL) {
			head = newNode;
			newNode->next = head;
			temp = head;
		} else {
			temp->next = newNode;
			temp = newNode;
			temp->next = head;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

}

void insert_at_pos(cll_node* &head , int element , int pos) {

	cll_node* newNode = new cll_node();
	newNode->data = element;
	newNode->next = NULL;

	if(head == NULL) {
		head = newNode;
		newNode->next = head;
		return;
	}

	int start = 1;
	cll_node* temp = head;

	if(pos == 1) {
		while(temp->next != head) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
		head = newNode;
		return;
	}

	while(start < pos - 1) {
		start++;
		temp = temp->next;
	}

	newNode->next = temp->next;
	temp->next = newNode;

}

void display(cll_node* head) {
	cout << "The elements are : ";
	if(head == NULL)
		return;
	cll_node* temp = head;

	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while(temp != head);
	cout << endl;
}

int main() {

	cll_node* head = NULL;

	createCLL(head);

	cout << "Before Insertion : " << endl;
	display(head);

	int pos , element;

	cout << "Enter the element and position to insert : ";
	cin >> element >> pos;

	insert_at_pos(head , element , pos);

	cout << "After Insertion : " << endl;
	display(head);

	return 0;
}