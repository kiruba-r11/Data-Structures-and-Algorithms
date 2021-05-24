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

int searchSLL(sll_node* head , int key) {

	int index = -1;
	while(head != NULL) {
		index++;
		if(head->data == key)
			return index;
		head = head->next;
	}
	return -1;
}

void display(sll_node* head) {

	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	int choice;

	sll_node* head = NULL;
	createSLL(head);

	do {

		display(head);
		int key;
		cout << "Enter key to search in SLL : ";
		cin >> key;

		int index = searchSLL(head , key);
		if(index == -1) {
			cout << "Element not present in SLL" << endl;
		} else {
			cout << "Element is present at : " << index << endl;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);


	return 0;
}