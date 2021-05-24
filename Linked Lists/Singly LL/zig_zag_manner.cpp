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

		cout << "Enter Data : ";
		cin >> data;

		sll_node* newNode = new sll_node();
		newNode->data = data;
		newNode->next =  NULL;

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

void zig_zag(sll_node* &head) {

	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return;

	sll_node *temp = head , *temp1;
	while(temp != NULL && temp->next != NULL && temp->next->next != NULL) {
		temp1 = temp->next->next->next;
		temp->next->next->next = temp->next;
		temp->next = temp->next->next;
		temp->next->next->next = temp1;
		temp = temp->next->next;
	}
}

void display(sll_node* head) {
	cout << "The elements are : ";
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}

int main() {

	sll_node* head = NULL;

	createSLL(head);

	cout << "Before swapping : " << endl;
	display(head);

	zig_zag(head);

	cout << "After swapping : " << endl;
	display(head);

	return 0;
}