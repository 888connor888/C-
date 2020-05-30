#include<iostream>
#include<stdlib.h>
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

node* mergeEndToEnd(node*head1, node*head2) {
	node*temp = head1;
	while (temp->next != NULL)  temp = temp->next;
	temp->next = head2;
	return head1;
}

node* EvenAfterOdd(node*head) {
	node*odd_list = NULL;
	node*even_list = NULL;
	node*temp = head;
	while (temp != NULL) {
		if (temp->data % 2 == 0) {
			insertAtTail(even_list, temp->data);
			temp = temp->next;
		}
		else {
			insertAtTail(odd_list, temp->data);
			temp = temp->next;
		}
	}
	node*final_list = mergeEndToEnd(odd_list, even_list);
	return final_list;
}

int main(int argc, char const *argv[]) {
	system("CLS");
	/* code */
	node*head = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int no;
		cin >> no;
		insertAtTail(head, no);
	}
	node*new_list = EvenAfterOdd(head);
	Print(new_list);
	return 0;
}