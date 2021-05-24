#include <iostream>

using namespace std;

class sll_node {
public:
	int data;
	sll_node* next;
};

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

int delete_at_begin(sll_node* &head) {

	if(head == NULL) {
		return -1;
	}

	int data = head->data;
	sll_node* temp = head;
	head = head->next;

	delete temp;
	return data;

}

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

int main() {

	sll_node* head = NULL;
	int choice;

	createSLL(head);

	do {

		cout << "Performing deletion at begin if possible" << endl;
		int data = delete_at_begin(head);

		if(data == -1) {
			cout << "Nothing to delete" << endl;
		} else {
			cout << "The deleted element is : " << data << endl;
		}

		cout << "The elements are : ";
		display(head);

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

	return 0;
}