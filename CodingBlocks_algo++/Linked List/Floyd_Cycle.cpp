#include<iostream>
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
	node*n = new node(data);
	temp->next = n;
}

void buildList(node*&head) {
	int data;
	cin >> data;
	while (data != -1) {
		insertAtTail(head, data);
		cin >> data;
	}
}

void Print(node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	return;
}

istream& operator >> (istream &is, node* &head) {
	buildList(head);
	return is;
}

ostream& operator << (ostream &is, node* head) {
	Print(head);
	return is;
}

int length(node*head) {
	if (head == NULL) return 0;
	int jump = 0;
	while (head != NULL) {
		head = head->next;
		jump += 1;
	}
	return jump;
}

node* KthNode_from_last(node*head, int k) {
	if (k > length(head)) return NULL;
	node*fast = head;
	node*slow = head;
	int jump = 1;
	while (jump <= k) {
		fast = fast->next;
		jump += 1;
	}
	while (fast != NULL ) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

bool detectCycle(node*head) {
	node*fast = head;
	node*slow = head;
	// To Detect initially fast takes 2 steps
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)  return true;
	}
	return false;
}

void FloydCycle(node*&head) {
	node*fast = head;
	node*slow = head;
	// To Detect initially fast takes 2 steps
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)  break;
	}
	// Cycle Removal
	slow = head;
	node*prev = fast;
	while (fast != NULL) {
		prev = fast ;//added line.. this is because when finally the cycling element will be found it will the element where the cycle is formed so u need to keep track of one element before that
		fast = fast->next;
		slow = slow->next;
		//prev->next = fast; this does not update prev this simply loses the pointer to the current fast
		if (fast == slow) {
			prev->next = NULL; // u need thus to break the cycle
			break;
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	node*head = NULL;
	cin >> head;
	node*end = KthNode_from_last(head, 1);
	end->next = head->next->next->next;
	cout << detectCycle(head);
	if (detectCycle(head)) FloydCycle(head);
	cout << detectCycle(head);
	return 0;
}