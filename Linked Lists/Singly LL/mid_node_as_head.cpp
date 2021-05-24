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

void make_mid_head1(sll_node* &head) {

	if(head == NULL || head->next == NULL)
		return;

	sll_node *prev = NULL , *slow = head , *fast = head;
	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			fast = fast->next;
			prev = slow;
			slow = slow->next;
		}
	}

	fast = slow->next;
	slow->next = head;
	prev->next = fast;
	head = slow;

}

void make_mid_head2(sll_node* &head) {

	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return;

	sll_node *prev = NULL , *slow = head , *fast = head->next;
	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			fast = fast->next;
			prev = slow;
			slow = slow->next;
		}
	}

	fast = slow->next;
	slow->next = head;
	prev->next = fast;
	head = slow;

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

	// make_mid_head1(head);
	make_mid_head2(head);

	cout << "After Swapping : " << endl;
	display(head);

	return 0;
}