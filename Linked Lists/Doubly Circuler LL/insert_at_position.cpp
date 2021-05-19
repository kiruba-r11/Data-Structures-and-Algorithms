#include <iostream>

using namespace std;

class dcll_node {
public:
	dcll_node* prev;
	int data;
	dcll_node* next;
};

void createDCLL(dcll_node* &head) {

	dcll_node* temp = head;

	int choice;

	do {

		int data;

		cout << "Enter Data : ";
		cin >> data;

		dcll_node* newNode = new dcll_node();
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;

		if(head == NULL) {
			head = newNode;
			temp = head;
			head->next = head;
			head->prev = head;
		} else {
			temp->next = newNode;
			newNode->prev = temp;
			temp = newNode;
			newNode->next = head;
			head->prev = newNode;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

}

void insert_at_position(dcll_node* &head , int element , int pos) {

	dcll_node* newNode = new dcll_node();
	newNode->data = element;
	newNode->prev = NULL;
	newNode->next = NULL;

	if(pos == 1) {
		if(head == NULL) {
			head = newNode;
			head->next = newNode;
			head->prev = newNode;
			return;
		} else {
			newNode->next = head;
			newNode->prev = head->prev;
			head->prev->next = newNode;
			head->prev = newNode;
			head = newNode;
			return;
		}
	} else {
		int length = 1;
		dcll_node* temp = head->next;
		while(length < pos - 1 && temp != head) {
			length++;
			temp = temp->next;
		}
		
		temp->prev->next = newNode;
		newNode->prev = temp->prev;
		newNode->next = temp;
		temp->prev = newNode;
	}
}

void display(dcll_node* head) {

	if(head == NULL)
		return;

	cout << "The elements are : ";
	dcll_node* temp = head;

	do {

		cout << temp->data << " ";
		temp = temp->next;

	} while(temp != head);
	cout << endl;
}

int main() {

	dcll_node* head = NULL;

	createDCLL(head);

	cout << "Before Insertion : " << endl;
	display(head);

	int element , pos;
	cout << "Enter element and position (1-based indexing) to insert : ";
	cin >> element >> pos;

	insert_at_position(head , element , pos);

	cout << "After Insertion : " << endl;
	display(head);

	return 0;
}