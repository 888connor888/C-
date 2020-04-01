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

int main(){
	node*head = NULL;
	cin>>head;
	cout<<head;
	node*MidPoint = midPoint(head);
	cout<<MidPoint->data<<endl;
	return 0;
}