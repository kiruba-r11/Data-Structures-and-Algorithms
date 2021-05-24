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

int find_length(sll_node* head) {

	if(head == NULL) {
		return 0;
	}

	return find_length(head->next) + 1;

}

void display(sll_node* head) {
	cout << "The elements are : ";
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}

void rotate_anticlockwise(sll_node* &head , int k) {

	int length = find_length(head);
	if(length == 0 || length == 1)
		return;

	k = k % length;
	if(k == 0)
		return;

	// 1 -> 2 -> 3 -> 4 -> 5 /
	int start = 1;

	sll_node* temp = head;
	sll_node* temp1 = head;

	while(start < k) {
		temp = temp->next;
		start++;
	}

	temp1 = temp->next;
	temp->next = NULL;

	temp = temp1;

	while(temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = head;
	head = temp1;
}

int main() {

	sll_node* head = NULL;
	createSLL(head);

	int choice;

	do {

		cout << "Before Rotation : ";
		display(head);

		int k;
		cout << "Enter the no. of nodes to rotate : ";
		cin >> k;

		rotate_anticlockwise(head , k);

		cout << "After Rotation : ";
		display(head);

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

	return 0;
}