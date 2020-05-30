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



node* K_Append(node*head, int k) {
	node*fast = head;
	node*slow = head;
	node*prev = slow;
	for (int i = 1; i <= k; i++) fast = fast->next;
	while (fast != NULL) {
		fast = fast->next;
		prev = slow;
		slow = slow->next;
	}
	prev->next = NULL;
	node*new_head = slow;
	while (slow->next != NULL) slow = slow->next;
	slow->next = head;
	return new_head;
}

int main(int argc, char const *argv[]) {
	//system("CLS");
	/* code */
	node*head = NULL;
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int no;
		cin >> no;
		insertAtTail(head, no);
	}
	cin >> k;
	k %= n;
	node*new_list = K_Append(head, k);
	Print(new_list);
	return 0;
}