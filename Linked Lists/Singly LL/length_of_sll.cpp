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

int find_length(sll_node* head) {
	int length = 0;

	while(head != NULL) {
		length++;
		head = head->next;
	}

	return length;
}

int main() {

	sll_node* head = NULL;
	createSLL(head);

	int length = find_length(head);
	cout << "The length of SLL is : " << length << endl;

	return 0;
}