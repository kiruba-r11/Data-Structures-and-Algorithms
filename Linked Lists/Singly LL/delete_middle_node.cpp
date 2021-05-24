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

void delete_mid(sll_node* &head) {

	if(head == NULL || head->next == NULL) {
		head = NULL;
		delete head;
		return;
	}

	sll_node* slow = NULL;
	sll_node* fast = head;

	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			fast = fast->next;
			if(slow == NULL)
				slow = head;
			else
				slow = slow->next;
		}
	}

	sll_node* temp = slow->next;
	slow->next = slow->next->next;
	delete temp;
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

	cout << "Before deletion : " << endl;
	display(head);

	delete_mid(head);

	cout << "After deletion : " << endl;
	display(head);

	return 0;
}