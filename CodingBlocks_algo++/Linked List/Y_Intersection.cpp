#include<iostream>
#include<stdlib.h>
#define ll long
using namespace std;

class node {
public:
	int data;
	node* next;
	node(const int d): next(NULL) {
		data = d;
	}
};

void insertAtTail(node*&head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}
	node*temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new node(data);
	return;
}


void Print(node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	return;
}

int Intersection(node*head1, node*head2, int n1, int n2) {
	node*temp = head1;
	node*temp1 = head2;
	int d = abs(n1 - n2);
	if (n2 > n1) {
		while (d > 0) {
			temp1 = temp1->next;
			d--;
		}
	}
	else {
		while (d > 0) {
			temp = temp->next;
			d--;
		}
	}
	while (temp != NULL and temp1 != NULL) {
		if (temp->data == temp1->data) {
			return temp->data;
		}
		temp = temp->next;
		temp1 = temp1->next;
	}
}



int main(int argc, char const *argv[]) {
	//system("CLS");
	/* code */
	node*head1 = NULL;
	node*head2 = NULL;
	int n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		int no;
		cin >> no;
		insertAtTail(head1, no);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		int no;
		cin >> no;
		insertAtTail(head2, no);
	}
	cout << Intersection(head1, head2, n1, n2);
	return 0;
}