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

bool first_and_second_half(sll_node* head) {

	if(head == NULL || head->next == NULL)
		return true;

	sll_node* fast = head->next;
	sll_node* slow = head;

	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
	}

	slow = slow->next;

	while(slow != NULL) {
		if(slow->data != head->data)
			return false;
		slow = slow->next;
		head = head->next;
	}

	return true;

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

	bool check = first_and_second_half(head);
	if(check)
		cout << "First and second half are matching";
	else
		cout << "First and second half are not matching";
	cout << endl;

	return 0;
}