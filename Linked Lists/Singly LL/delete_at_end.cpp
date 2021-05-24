#include <iostream>

using namespace std;

class sll_node {
public:
	int data;
	sll_node* next;
};

void createSLL(sll_node* &head) {

	int choice;
	sll_node* temp = head;

	do {

		int data;

		sll_node* newNode = new sll_node();

		cout << "Enter Data : ";
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

int delete_at_end(sll_node* &head) {

	if(head == NULL) {
		return -1;
	}

	if(head->next == NULL) {
		int data = head->data;
		head = NULL;
		delete head;
		return data;
	}

	sll_node* temp1 = head;
	sll_node* temp2 = NULL;
	while(temp1->next != NULL) {
		temp2 = temp1;
		temp1 = temp1->next;
	}

	temp2->next = NULL;

	int data = temp1->data;
	delete temp1;

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
		cout << "SLL is Empty" << endl;
	else
		cout << endl;

}

int main() {

	int choice;
	sll_node* head = NULL;

	createSLL(head);

	do {

		cout << "Deleting the last node if possible" << endl;
		int data = delete_at_end(head);

		if(data == -1) {
			cout << "Nothing to delete" << endl;
		} else {
			cout << "The deleted element is : " << data << endl;
		}

		display(head);

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

	return 0;
}