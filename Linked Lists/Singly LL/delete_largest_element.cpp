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

int find_largest(sll_node* head) {

	int largest = INT_MIN;

	while(head != NULL) {
		largest = max(largest , head->data);
		head = head->next;
	}
	return largest;
}

void delete_largest(sll_node* &head) {

	if(head == NULL)
		return;
	if(head->next == NULL) {
		head = NULL;
		delete head;
		return;
	}

	sll_node* slow = head;
	sll_node* fast = head;

	while(fast != NULL && fast->next != NULL) {
		if(fast->next->data > slow->data) {
			slow = fast;
		}
		fast = fast->next;
	}

	if(slow == head && slow->data > slow->next->data) {
		head = head->next;
		delete slow;
	}

	fast = slow->next;
	slow->next = fast->next;
	delete fast;

	// int largest = find_largest(head);
	// sll_node* temp = head;
	// if(head->data == largest) {
	// 	head = head->next;
	// 	delete temp;
	// 	return;
	// }

	// while(temp != NULL && temp->next != NULL && temp->next->data != largest) {
	// 	temp = temp->next;
	// }

	// sll_node* temp1 = temp->next;
	// temp->next = temp1->next;
	// delete temp1;

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

	cout << "Before Deletion : " << endl;
	display(head);

	delete_largest(head);

	cout << "After Deletion : " << endl;
	display(head);

	return 0;
}