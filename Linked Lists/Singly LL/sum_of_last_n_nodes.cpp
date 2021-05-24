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

int find_sum(sll_node* head , int n) {

	// 1 -> 2 -> 3 -> 4 -> 5 /


	int start = 1;
	sll_node* temp = head;
	while(head != NULL && start <= n) {
		start++;
		head = head->next;
	}

	while(head != NULL) {
		temp = temp->next;
		head = head->next;
	}

	int sum = 0;
	while(temp != NULL) {
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
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

	int n;
	cout << "Enter the value of n to find sum : ";
	cin >> n;

	int sum = find_sum(head , n);
	cout << "The sum is : " << sum << endl;

	return 0;
}