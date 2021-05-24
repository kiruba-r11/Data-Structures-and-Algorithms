#include <iostream>

using namespace std;

class sll_node {
public:
	int data;
	sll_node *next;
};

bool isValidPosition(sll_node* head , int pos) {

	int length = 0;
	while(head != NULL) {
		length++;
		head = head->next;
	}

	if(length == 0) {
		if(pos != 0)
			return false;
		return true;
	}

	if(pos <= length)
		return true;
	return false;
}

void insert_at_position(sll_node* &head , int data , int pos) {


	if(isValidPosition(head , pos)) {

		sll_node* newNode = new sll_node();
		newNode->data = data;
		newNode->next = NULL;

		if(head == NULL) {

			head = newNode;

		} else {

			if(pos == 0) {
				newNode->next = head;
				head = newNode;
			} else {
				int start = 0;
				sll_node* temp = head;
				while(start < pos - 1 && temp->next) {
					start++;
					temp = temp->next;
				}
				newNode->next = temp->next;
				temp->next = newNode;

			}

		}

	} else {
		cout << "Invalid Position" << endl;
	}
}

void display(sll_node* head) {
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	int choice;

	sll_node* head = NULL;

	do {

		int data , pos;

		cout << "Enter the data to insert : ";
		cin >> data; 

		cout << "Enter the position to insert (0-based indexing) : ";
		cin >> pos;

		insert_at_position(head , data , pos);

		cout << "The elements is : ";
		display(head);

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;  

	} while(choice == 1);

	return 0;
}