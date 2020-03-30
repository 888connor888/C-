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

node* KthNode_from_last(node*head,int k){
	if(k>length(head)) return NULL;
	node*fast = head;
	node*slow = head;
	int jump = 1;
	while(jump<=k){
		fast = fast->next;
		jump += 1;
	}
	while(fast != NULL ){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main(){
	node*head = NULL;
	int k;
	cin>>head;
	cin>>k;
	cout<<head;
	cout<<KthNode_from_last(head,k)->data<<endl;
	return 0;
}