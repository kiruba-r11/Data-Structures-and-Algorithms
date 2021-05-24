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

sll_node* reverse_recursive(sll_node* head) {
	if(head == NULL || head->next == NULL)
		return head;

	sll_node *prev = head , *cur = head;
	while(cur != NULL && cur->next != NULL) {
		prev = cur;
		cur = cur->next;
	}

	prev->next = NULL;
	prev = reverse_recursive(head);
	cur->next = prev;
	return cur;
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

	cout << "Before reversing : " << endl;
	display(head);

	head = reverse_recursive(head);

	cout << "After reversing : " << endl;
	display(head);

	return 0;
}