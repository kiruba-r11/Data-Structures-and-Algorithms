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

void insert_at_pos(dll_node* &head , int elem , int pos) {

	dll_node* newNode = new dll_node();
	newNode->data = elem;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(head == NULL) {
		if(pos == 0) {
			head = newNode;
			return;
		}
		return;
	}

	int start = 1;
	dll_node* temp = head;

	while(start < pos && temp != NULL) {
		start++;
		temp = temp->next;
	}

	if(temp == NULL)
		return;
	if(pos == 0) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	} 

	dll_node* temp1 = NULL;
	if(temp->next != NULL)
		temp1 = temp->next;
	temp->next = newNode;
	newNode->prev = temp;

	if(temp1 == NULL)
		return;

	temp1->prev = newNode;
	newNode->next = temp1;

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

	int pos , elem;
	cout << "Enter the position and element to insert (from 0) : " << endl;
	cin >> pos >> elem;

	insert_at_pos(head , elem , pos);

	display(head);

	return 0;
}