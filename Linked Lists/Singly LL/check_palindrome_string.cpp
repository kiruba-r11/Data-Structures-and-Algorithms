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

bool checkPalindrome(sll_node* head) {

	if(head == NULL || head->next == NULL)
		return true;

	sll_node *slow = head , *fast = head;
	stack <int> s;

	int length = 0;

	while(fast != NULL) {
		fast = fast->next;
		if(fast != NULL) {
			fast = fast->next;
			length++;
			s.push(slow->data);
			slow = slow->next;
		}
		length++;
	}

	if(length & 1)
		slow = slow->next;

	while(slow != NULL) {
		int data = slow->data;
		if(data != s.top())
			return false;
		slow = slow->next;
		s.pop();
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

	bool isPalindrome = checkPalindrome(head);
	if(isPalindrome)
		cout << "It is Palindrome";
	else
		cout << "It is not Palindrome";
	cout << endl;

	return 0;
}