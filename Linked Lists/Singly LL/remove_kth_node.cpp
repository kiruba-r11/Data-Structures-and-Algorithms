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

void remove_kth_node(sll_node* &head , int k) {
	if(head == NULL)
		return;
	if(head->next == NULL && k == 1) {
		head = NULL;
		delete head;
		return;
	}

	if(head->next == NULL)
		return;

	int start = 1;
	sll_node* temp = head;
	while(true) {
		while(start < k - 1 && temp != NULL) {
			start++;
			temp = temp->next;
		}
		if(temp == NULL)
			return;
		temp->next = temp->next->next;
		temp = temp->next;
		start = 1;
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

	int k;

	createSLL(head);

	cout << "Before removing : " << endl;
	display(head);

	cout << "Enter the value of k to delete : ";
	cin >> k;

	remove_kth_node(head , k);

	cout << "After removing : " << endl;
	display(head);

	return 0;
}