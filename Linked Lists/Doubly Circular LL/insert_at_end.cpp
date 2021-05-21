#include <iostream>

using namespace std;

class dcll_node {
	public:
		dcll_node* prev;
		int data;
		dcll_node* next;
};

void createDCLL(dcll_node* &head) {

	int choice;
	dcll_node* temp = head;

	do {

		int data;

		cout << "Enter Data : ";
		cin >> data;

		dcll_node* newNode = new dcll_node();
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;

		if(head == NULL) {
			head = newNode;
			temp = head;
			head->next = head;
			head->prev = head;
		} else {
			newNode->prev = temp;
			temp->next = newNode;
			temp = newNode;
			temp->next = head;
			head->prev = temp;
		}


		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);

}

void display(dcll_node* head) {
	cout << "The elements are : ";

	dcll_node* temp = head;
	do {

		cout << temp->data << " ";
		temp = temp->next;

	} while(temp != head);
	cout << endl;
}

int main() {

	dcll_node* head = NULL;

	createDCLL(head);
	display(head);

	return 0;
}