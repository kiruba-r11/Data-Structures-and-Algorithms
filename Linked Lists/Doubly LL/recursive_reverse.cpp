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

dll_node* recursive_reverse(dll_node* head) {

	if(head == NULL || head->next == NULL)
		return head;

	dll_node* temp = head->next;
	temp->prev = NULL;

	dll_node* newHead = recursive_reverse(temp);
	temp->next = head;
	head->prev = temp;
	head->next = NULL;
	return newHead;
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

	cout << "Before reversing : " << endl;
	display(head);

	head = recursive_reverse(head);

	cout << "After reversing : " << endl;
	display(head);

	return 0;
}