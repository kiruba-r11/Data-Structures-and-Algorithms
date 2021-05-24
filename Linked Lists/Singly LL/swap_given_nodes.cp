
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

void swap_nodes(sll_node* &head , int a , int b) {

	if(head == NULL || head->next == NULL)
		return;

	sll_node *pf = NULL , *pl = head , *cf = NULL , *cl = head;

	bool check1 = true , check2 = true;

	while(pl != NULL && cl != NULL && (check1 || check2)) {
		if(pl->data != a) {
			pf = pl;
			pl = pl->next;
		} else {
			check1 = false;
		}
		if(cl->data != b) {
			cf = cl;
			cl = cl->next;
		} else {
			check2 = false;
		}
	}

	if(pl == NULL || cl == NULL || cf == NULL)
		return;

	if(pf == NULL) {
		if(cf == pl) {
			pl->next = cl->next;
			cl->next = pl;
			head = cl;
		} else {
			sll_node* temp = pl->next;
			pl->next = cl->next;
			cl->next = temp;
			cf->next = pl;
			head = cl;
		}
	} else if(cf == pl) {
		pf->next = cl;
		pl->next = cl->next;
		cl->next = cf;
	} else {
		pf->next = cl;
		pl->next = cl->next;
		cl->next = cf;
		cf->next = pl;
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

	cout << "Before Swapping : " << endl;
	display(head);

	int a , b;
	cout << "Enter values to swap : ";
	cin >> a >> b;

	swap_nodes(head , a , b);

	cout << "After Swapping : " << endl;
	display(head);

	return 0;
}