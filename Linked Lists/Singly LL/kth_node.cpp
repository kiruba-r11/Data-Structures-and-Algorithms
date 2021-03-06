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


int find_kth_node(sll_node* head , int k) {

	if(head == NULL)
		return -1;

	k--;

	while(head != NULL && k != 0) {
		k--;
		head = head->next;
	}

	if(k == 0 && head != NULL)
		return head->data;

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

	sll_node* head = NULL;

	createSLL(head);

	display(head);

	int k;
	cout << "Enter the value of k : ";
	cin >> k;

	int node = find_kth_node(head , k);

	cout << "The kth node is : " << node << endl;

	return 0;
}