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

void delete_at_pos(dll_node* &head , int pos) {

	if(head == NULL)
		return;
	if(head->next == NULL) {
		if(pos == 0) {
			head = NULL;
			return;
		}
		return;
	}

	int start = 1;
	dll_node* temp = head;

	while(start <= pos && temp != NULL) {
		start++;
		temp = temp->next;
	}

	if(temp == NULL)
		return;

	if(temp == head) {
		head = head->next;
		head->prev = NULL;
		delete temp;
		return;
	}

	temp->prev->next = temp->next;
	if(temp->next) {
		temp->next->prev = temp->prev;
	}
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

	cout << "Before Deletion : " << endl;
	display(head);

	int pos;
	cout << "Enter Position to delete (from 0) : ";
	cin >> pos;

	delete_at_pos(head , pos);

	cout << "After Deletion : " << endl;
	display(head);

	return 0;
}