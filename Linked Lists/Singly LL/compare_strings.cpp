#include <iostream>

using namespace std;

class sll_node {
public: 
	char data;
	sll_node* next;
};

void createSLL(sll_node* &head) {

	int choice;
	sll_node* temp = head;

	do {

		char data;

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

int compare_strings(sll_node* head1 , sll_node* head2) {

	while(head1 != NULL && head2 != NULL) {
		if(head1->data > head2->data)
			return 1;
		if(head1->data < head2->data)
			return -1;
		head1 = head1->next;
		head2 = head2->next;
	}

	if(head1 == NULL && head2 == NULL)
		return 0;
	if(head1 == NULL)
		return -1;
	if(head2 == NULL)
		return 1;
	return 0;
}

void display(sll_node* head) {
	cout << "The elements are : ";
	while(head != NULL) {
		cout << head->data << "";
		head = head->next;
	}

	cout << endl;
}

int main() {

	sll_node *head1 = NULL , *head2 = NULL;

	cout << "Create String - 1 " << endl;
	createSLL(head1);

	cout << endl;

	cout << "Create String - 2 : " << endl;
	createSLL(head2);

	cout << endl;

	cout << "String - 1 : ";
	display(head1);

	cout << endl; 

	cout << "String - 2 : ";
	display(head2);

	cout << endl;

	int result = compare_strings(head1 , head2);

	cout << "Result : " << result << endl;

	return 0;
}