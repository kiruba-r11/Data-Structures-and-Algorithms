#include <iostream>

using namespace std;

class sll_node {
public: 
	int data;
	sll_node* next;
};

void display(sll_node*);

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

void reverse(sll_node* &head) {

	if(head == NULL || head->next == NULL)
		return;

	sll_node *p = NULL , *q = head , *r = head->next;
	while(r != NULL) {
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}

	q->next = p;
	head = q;
}

void min_max(sll_node* &head) {

	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return;

	sll_node *slow = head , *fast = head->next;
	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
	}

	fast = slow->next;
	slow->next = NULL;
	slow = head;
	reverse(fast);
	display(fast);
	sll_node *temp = head;

	while(temp != NULL) {
		slow = slow->next;
		temp->next = fast;
		temp = temp->next;
		if(slow == NULL)
			return;
		fast = fast->next;
		temp->next = slow;
		temp = temp->next;
		if(fast == NULL)
			return;
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

	cout << "Before modification : " << endl;
	display(head);

	min_max(head);

	cout << "After modification : " << endl;
	display(head);

	return 0;
}