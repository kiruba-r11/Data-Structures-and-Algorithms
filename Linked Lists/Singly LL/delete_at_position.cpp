#include <iostream>

using namespace std;

class sll_node {

public:
	int data;
	sll_node* next;

};

void display(sll_node* head) {

	int length = 0;

	while(head != NULL) {
		length++;
		cout << head->data << " ";
		head = head->next;
	}

	if(length == 0)
		cout << "SLL is empty" << endl;
	else
		cout << endl;
}

void createSLL(sll_node* &head) {
	cout << "Enter the elements of SLL : " << endl;

	int choice;
	sll_node* temp = head;

	do {

		sll_node* newNode = new sll_node();

		int data;

		cout << "Enter data : ";
		cin >> data;

		newNode->data = data;
		newNode->next = NULL;

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

int delete_at_position(sll_node* &head , int pos) {

	if(head->next == NULL) {
		int data = head->data;
		head = NULL;
		delete head;
		return data;
	} else if(pos == 0) {
		int data = head->data;
		sll_node* temp = head;
		head = head->next;
		delete temp;
		return data;
	} else {
		int start = 0;
		sll_node* temp1 = head;
		sll_node* temp2 = NULL;
		while(start < pos) {
			start++;
			temp2 = temp1;
			temp1 = temp1->next;
		}

		temp2->next = temp1->next;
		int data = temp1->data;
		delete temp1;
		return data;
	}
}

bool isValidPosition(sll_node* head , int pos) {

	int length = 0;

	while(head != NULL) {
		length++;
		head = head->next;
	}

	if(length == 0)
		return false;

	if(pos >= 0 && pos <= length - 1)
		return true;
	return false;

}

int main() {

	sll_node* head = NULL;
	int choice;

	createSLL(head);

	do {

		int pos;
		cout << "Enter the position to delete : ";
		cin >> pos;

		if(isValidPosition(head , pos)) {
			cout << "Performing deletion" << endl;
			int data = delete_at_position(head , pos);

			cout << "The deleted element is : " << data << endl;

			cout << "The elements are : ";
			display(head);
		} else {
			cout << "Invalid position to delete" << endl;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

	return 0;
}