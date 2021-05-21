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

void delete_at_position(dcll_node* &head , int pos) {

	if(head == NULL)
		return;

	if(pos == 1) {
		if(head->next == head) {
			head = NULL;
			delete head;
			return;
		}
		dcll_node* temp = head;
		head = head->next;
		head->prev = temp->prev;
		temp->prev->next = head;
		delete temp;
		return;
	} 

	int length = 1;
	dcll_node* temp = head->next;
	while(length < pos - 1 && temp != head) {
		length++;
		temp = temp->next;
	}

	if(temp == head)
		return;

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
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

	cout << "Before deletion : " << endl;
	display(head);

	int pos;
	cout << "Enter the position to delete (1 indexing) : ";
	cin >> pos;

	delete_at_position(head , pos);

	cout << "After deletion : " << endl;
	display(head);

	return 0;
}