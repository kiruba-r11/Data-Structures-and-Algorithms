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

int find_middle_2(sll_node* head) {

	// it will consider the ceil(n / 2) th as the middle element

	if(head == NULL)
		return 0;

	sll_node* slow = head;
	sll_node* fast = head->next;

	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow->data;
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

	display(head);

	int middle = find_middle_2(head);
	cout << "The middle element is : " << middle << endl;

	return 0;
}