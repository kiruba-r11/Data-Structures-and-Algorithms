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

sll_node* find_mid(sll_node* head) {

	if(head == NULL || head->next == NULL)
		return head;

	sll_node* fast = head->next;
	sll_node* slow = head;

	while(fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

sll_node* merge(sll_node* head1 , sll_node* head2) {
	if(head1 == NULL && head2 == NULL)
		return NULL;
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;

	sll_node* head = new sll_node();
	head->data = -1;
	head->next = NULL;

	sll_node* temp = head;
	while(head1 != NULL && head2 != NULL) {
		if(head1->data < head2->data) {
			temp->next = head1;
			head1 = head1->next;
		} else {
			temp->next = head2;
			head2 = head2->next;
		}
		temp = temp->next;
	}

	if(head1 != NULL)
		temp->next = head1;
	if(head2 != NULL)
		temp->next = head2;


	return head->next;
}

sll_node* merge_sort(sll_node* head) {

	if(head == NULL || head->next == NULL)
		return head;


	sll_node* mid = find_mid(head);
	sll_node* head1 = mid->next;

	cout << mid->data << endl;

	mid->next = NULL;
	head = merge_sort(head);
	head1 = merge_sort(head1);
	head = merge(head , head1);
	return head;
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

	cout << "Before sorting : " << endl;
	display(head);

	head = merge_sort(head);

	cout << "After sorting : " << endl;
	display(head);

	return 0;
}