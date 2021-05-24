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

void delete_m_after_n_nodes(sll_node* head , int m , int n) {

	sll_node* ptr1 = head;
	sll_node* ptr2 = head;

	int start = 1;

	while(ptr1 != NULL && start < n) {
		start++;
		ptr1 = ptr1->next;
	}

	if(ptr1 == NULL)
		return;

	start = 1;
	ptr2 = ptr1->next;
	while(start <= m && ptr2 != NULL) {
		start++;
		ptr2 = ptr2->next;
	}

	ptr1->next = ptr2;

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

	cout << "List before deletion : " << endl;
	display(head);

	int m , n;
	cout << "Enter the value of m and n : ";
	cin >> m >> n;

	delete_m_after_n_nodes(head , m , n);

	cout << "List after deletion : " << endl;
	display(head);

	return 0;
}