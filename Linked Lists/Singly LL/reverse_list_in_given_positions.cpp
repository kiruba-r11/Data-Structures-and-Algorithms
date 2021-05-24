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

void reverse(sll_node* &head , sll_node* &tail) {

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
	tail = head;
	head = q;
}

void reverse_in_range(sll_node* &head , int a , int b) {

	if(head == NULL || head->next == NULL)
		return;

	int start = 1;

	sll_node *slow = head , *fast = head;

	while(start < a - 1 && slow != NULL) {
		start++;
		slow = slow->next;
	}

	if(slow == NULL || slow->next == NULL)
		return;

	start = 1;
	while(start < b && fast != NULL) {
		fast = fast->next;
		start++;
	}

	sll_node* temp;
	if(fast != NULL) {
		temp = fast->next;
		fast->next = NULL;
	}
	else
		temp = NULL;

	if(a != 1) {
		sll_node* head1 = slow->next;
		reverse(head1 , fast);
		slow->next = head1;
		if(temp != NULL)
			fast->next = temp;
		else 
			fast->next = NULL;
	} else {
		reverse(head , fast);
		if(temp != NULL)
			fast->next = temp;
		else 
			fast->next = NULL;
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

	cout << "Before Reversing : " << endl;
	display(head);

	int a , b;
	cout << "Enter the value of A and B : ";
	cin >> a >> b;

	reverse_in_range(head , a , b);

	cout << "After Reversing : " << endl;
	display(head);

	return 0;
}