#include<iostream>
#define ll long long
using namespace std;

class node {
public:
	ll data;
	node* next;
	node(const ll d): next(NULL) {
		data = d;
	}
};

void insertAtTail(node*&head, ll data) {
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


node* reverse(node*head, ll k) {
	node*current = head;
	node*prev = NULL;
	node*Next;
	ll count = 0;
	while (current != NULL and count < k) {
		Next = current->next;
		current->next = prev;
		prev = current;
		current = Next;
		count += 1;
	}
	// K reverse
	if (Next != NULL) head->next = reverse(Next, k);
	return prev;
}

int main(int argc, char const *argv[]) {
	/* code */
	ll n, k;
	node*head = NULL;
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		ll no;
		cin >> no;
		insertAtTail(head, no);
	}
	node* reversed_head = reverse(head, k);
	Print(reversed_head);
	return 0;
}