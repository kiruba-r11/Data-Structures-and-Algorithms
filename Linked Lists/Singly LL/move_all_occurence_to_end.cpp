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

void move_all_occurence_to_end(sll_node* &head , int key) {
	if(head == NULL || head->next == NULL)
		return;

	sll_node *tail = head;
	sll_node *temp , *temp1 = NULL , *head1;
	while(tail->next != NULL) {
		tail = tail->next;
	}

	if(head->data == key) {
		temp1 = head;
		head1 = temp1;
		while(head != NULL && head != tail && head->next->data == key) {
			head = head->next;
		}
		temp1 = head;
		if(head != NULL)
			head = head->next;
	}
	temp = head;
	while(temp != NULL && temp->next != NULL) {
		while(temp != NULL && temp->next != NULL && temp->next != tail && temp->next->data == key) {
			if(temp1 == NULL) {
				temp1 = temp->next;
				head1 = temp1;
			} else {
				temp1->next = temp->next;
				temp1 = temp1->next;
			}
			temp->next = temp->next->next;
		}
		temp = temp->next;
	}
	if(temp1 != NULL) {
		temp1->next = NULL;
		tail->next = head1;
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

	int key;

	cout << "Enter the key : ";
	cin >> key;

	cout << "Before Modification : " << endl;
	display(head);

	move_all_occurence_to_end(head , key);

	cout << "After Modification : " << endl;
	display(head);

	return 0;
}