#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(const int d):next(NULL){
		data = d;
	}
};

void insertAtTail(node*&head,int data){
	if(head == NULL){
		head = new node(data);
		return;
	}
	node*temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node*n = new node(data);
	temp->next = n;
}

void buildList(node*&head){
	int data;
	cin>>data;
	while(data != -1){
		insertAtTail(head,data);
		cin>>data;
	}
}

void Print(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	return;
}

istream& operator >> (istream &is,node* &head){
	buildList(head);
	return is;
}

ostream& operator << (ostream &is,node* head){
	Print(head);
	return is;
}

int length(node*head){
	if(head == NULL) return 0;
	int jump = 0;
	while(head != NULL){
		head = head->next;
		jump += 1;
	}
	return jump;
}

node* Merge(node*a,node*b){
	// Base Cases
	if(a == NULL) return b;
	else if(b == NULL) return a;
	// Recursive Cases
	node*c;
	if(a->data < b->data){
		c = a;
		c->next = Merge(a->next,b);
	}
	else{
		c = b;
		c->next = Merge(a,b->next);
	}
	return c;
}

node* midPoint(node*head){
	if(head == NULL || head->next == NULL)    return head;
	node*fast = head;
	node*slow = head;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* MergeSort(node*head){
	// Base Case
	if(head == NULL||head->next == NULL)  return head;
	// Recursive Case
	// 1. Find Midpoint
	node*mid = midPoint(head);
	node*a = head;
	node*b = mid->next;
	mid->next = NULL;
	//2. Recusive Sorting
	a = MergeSort(a);
	b = MergeSort(b);
	//3. Merge The two parts
	node*c = Merge(a,b);
	return c;
}

int main(){
	node*head = NULL;
	cin>>head;
	cout<<head;
	MergeSort(head);
	cout<<head;
	return 0;
}