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

sll_node* reverse_in_k(sll_node* head , int k) {

	if(head == NULL || head->next == NULL)
		return head;

	int start = 2;
	sll_node *p = NULL , *q = head , *r = head->next;

	while(start <= k) {
		start++;
		if(r == NULL)
			return head;
		r = r->next;
	}

	start = 2;
	r = head->next;

	while(start <= k) {
		start++;
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;
	p = reverse_in_k(r , k);
	head->next = p;
	return q;
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

	int k;
	cout << "Enter the value of K : ";
	cin >> k;

	head = reverse_in_k(head , k);

	cout << "After Reversing : " << endl;
	display(head);
	return 0;
}