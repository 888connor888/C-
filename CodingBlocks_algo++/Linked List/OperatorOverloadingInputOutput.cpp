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
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new node(data);
	return;
}

void Print(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	return;
}

void buildList(node*&head){
	int data;
	cin>>data;
	while(data != -1){
		insertAtTail(head,data);
		cin>>data;
	}
}

istream& operator >> (istream &is,node* &head){
	buildList(head);
	return is;
}

ostream& operator << (ostream &is,node* head){
	Print(head);
	return is;
}

int main(){
	node* head1 = NULL;
	node* head2 = NULL;
	cin>>head1>>head2;
	cout<<head1<<head2;
	return 0;
}