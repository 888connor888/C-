#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*next;
	//Constructor
	node(const int d):next(NULL){
		data = d;
	}
};

void insertAtHead(node*&head,int data){
	node*n = new node(data);
	n->next = head;
	head = n;
}

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

int length(node*head){
	int len = 0;
	while(head != NULL){
		head = head->next;
		len += 1;
	}
	return len;
}

void insertAtMiddle(node*&head,int data,int p){
	if(head == NULL||p == 0){
		insertAtHead(head,data);
		return;
	}
	else if(p>=length(head)){
		insertAtTail(head,data);
		return;
	}
	else{
		// move to the p-1 position
		int jump = 0;
		node*temp = head;
		while(jump<=p-1){
			temp = temp->next;
			jump += 1;
		}
		node*n = new node(data);
		n->next = temp->next;
		temp->next = n;
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

void TakeInput(node*&head){
	int data;
	cin>>data;
	// take input a series of numbers
	while(data != -1){ // stop when no. is -1 ex:- 1 3 3 4 6 2 8 -1
		insertAtTail(head,data);
		cin>>data;
	}
}

int main(){
	node*head = NULL;
	TakeInput(head); // 1 3 3 4 6 2 8 -1
	Print(head); // 1 3 3 4 6 2 8
	return 0;
}