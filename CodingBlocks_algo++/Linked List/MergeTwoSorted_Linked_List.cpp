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

int main(){
	node*head1=NULL;
	node*head2=NULL;
	cin>>head1>>head2;
	cout<<head1<<head2;
	node*head3 = Merge(head1,head2);
	cout<<head3;
	return 0;
}