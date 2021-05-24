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

void delete_val(sll_node* &head , int val) {

	if(head == NULL)
		return;
	if(head->next == NULL) {
		if(head->data == val) {
			head = NULL;
			return;
		} else {
			return;
		}
	}

	bool isFound = false;

	sll_node* slow = NULL;
	sll_node* fast = head;

	if(head->data == val) {
		isFound = true;
		while(fast != NULL && fast->next != NULL) {
			if(fast->next->data == val) {
				isFound = true;
				slow = fast;
			} else {
				if(isFound) {
					//
				} else {
					slow = fast;
				}
			}
			fast = fast->next;
		}
		if(slow != NULL) {
			slow->next = slow->next->next;
		} else {
			head = head->next;
		}

	} else {
		while(fast != NULL && fast->next != NULL) {
			if(fast->next->data == val) {
				isFound = true;
				slow = fast;
			} else {
				if(isFound) {
					//
				} else {
					slow = fast;
				}
			}
			fast = fast->next;
		}
		if(isFound) {
			slow->next = slow->next->next;
		}
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

	cout << "Before Deletion : " << endl;
	display(head);

	int val;
	cout << "Enter the value to delete : ";
	cin >> val;

	delete_val(head , val);

	cout << "After Deletion : " << endl;
	display(head);

	return 0;
}