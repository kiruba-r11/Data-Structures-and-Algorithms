#include <iostream>
#include <stack>

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

bool isPalindrome(sll_node* head) {

	if(head == NULL || head->next == NULL)
		return true;

	stack <int> s;

	sll_node* slow = head;
	sll_node* fast = head;

	s.push(slow->data);

	while(fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		s.push(slow->data);
	}

	if(fast->next == NULL) {
		s.pop();
		slow = slow->next;
		while(slow != NULL) {
			if(s.top() != slow->data)
				return false;
			s.pop();
			slow = slow->next;
		}
		return true;
	} 

	slow = slow->next;
	while(slow != NULL) {
		if(s.top() != slow->data)
			return false;
		s.pop();
		slow = slow->next;
	}
	return true;

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

	bool check = isPalindrome(head);
	if(check) {
		cout << "The list is Palindrome";
	} else {
		cout << "The list is not Palindrome";
	}
	cout << endl;

	return 0;
}