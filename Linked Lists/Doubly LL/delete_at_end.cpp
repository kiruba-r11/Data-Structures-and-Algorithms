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

void delete_at_end(dll_node* &head) {
	
	if(head == NULL)
		return;

	dll_node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}

	temp->prev->next = NULL;
	delete temp;
	return;

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

	delete_at_end(head);

	cout << "After Deletion : " << endl;
	display(head);

	return 0;
}