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

int find_length(sll_node* head) {
	if(head == NULL)
		return 0;
	return 1 + find_length(head->next);
}

int find_intersection(sll_node* head1 , sll_node* head2) {

	int length1 = find_length(head1);
	int length2 = find_length(head2);

	if(length1 == 0 || length2 == 0)
		return -1;

	if(length1 > length2) {

		// 1 -> 2 -> 3 -> 4 -> 5/
		// 3 -> 4 -> 5/

		int length = length1 - length2;
		while(length != 0 && head1 != NULL) {
			length--;
			head1 = head1->next;
		}	

		while(head1 != NULL && head2 != NULL) {
			if(head1 == head2)
				return head1->data;
			head1 = head1->next;
			head2 = head2->next;
		}	

	} else {

		int length = length2 - length;
		while(length != 0 && head2 != NULL) {
			length--;
			head2 = head2->next;
		}
		while(head1 != NULL && head2 != NULL) {
			if(head1 == head2)
				return head1->data;
			head1 = head1->next;
			head2 = head2->next;
		}

	}
	return -1;
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

	sll_node* head1 = NULL;
	sll_node* head2 = NULL;

	// cout << "Create SLL - 1: " << endl << endl;
	// createSLL(head1);

	// cout << "Create SLL - 2: " << endl << endl;
	// createSLL(head2);

	// cout << endl << "SLL - 1: " << endl << endl;
	// display(head1);

	// cout << endl << "SLL - 2: " << endl << endl;
	// display(head2);

	int check = find_intersection(head1 , head2);
	if(check == -1) {
		cout << "No intersection";
	} else {
		cout << "The intersection is at: " << check;
	}
	cout << endl;

	return 0;
}