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

void pairwise_swap(sll_node* &head) {
	if(head == NULL || head->next == NULL)
		return;

	sll_node *temp1 = head , *temp2 = head->next , *temp3 = NULL;

	while(temp1 != NULL && temp1->next != NULL) {

		temp1->next = temp2->next;
		temp2->next = temp1;
		if(temp3 == NULL) {
			head = temp2;
		} else {
			temp3->next = temp2;
		}
		temp3 = temp1;
		temp1 = temp1->next;
		if(temp1 == NULL)
			return;
		temp2 = temp1->next;
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

	cout << "Before Swapping : " << endl;
	display(head);

	pairwise_swap(head);

	cout << "After Swapping : " << endl;
	display(head);

	return 0;
}