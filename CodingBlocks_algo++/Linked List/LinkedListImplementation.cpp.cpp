#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	// constructor
	node(int d){
		data = d;
		next = NULL;
	}
};

//Delete Operations

void deleteAtHead(node*&head){
	if(head == NULL){
		return;
	}
	node*temp = head;
	head = head->next;
	delete temp;
	return;
}

void deleteAtTail(node*&head){
	node*temp = head;
	node*prev = NULL;
	while(temp->next != NULL){
		prev = temp;
		temp = temp->next;
	}
    delete temp;
    prev->next = NULL;
    return;
}

void deleteAtMiddle(node*&head,int p){
	node*temp = head;
	node*prev = NULL;
    int jump = 1;
    while(jump<=p-1){
    	prev = temp;
    	temp = temp->next;
    	jump += 1;
    }
    prev->next = temp->next;
    delete temp;
    return;
}

//Insertion Operations

// Passing a pointer variable by reference
void insertAtHead(node*&head,int data){
	node*n = new node(data);  // we are doing dynamic allocation because we want our node to persist even after function call
	n->next = head;
	head = n;
}

void insertAtTail(node*&head,int data){
	if(head == NULL){
		head = new node(data);
		return;
	}
	node*tail = head;
	while(tail->next!=NULL){
		tail = tail->next;
	}
	tail->next = new node(data); 
    return;
}

int length(node*head){
	int len = 0;
	while(head!=NULL){
		head = head->next;
		len += 1;
	}
	return len;
}

void insertAtMiddle(node*&head,int data,int p){
	if(head == NULL||p==0){
		insertAtHead(head,data);
	}
	else if(p>length(head)){
		insertAtTail(head,data);
	}
	else{
		// First Travel to the position(node)
		// Take p-1 jumps
		int jump = 1;
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

void print(node* head){
	node*temp = head;

	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

 int main(){
 	node* head = NULL;
 	insertAtHead(head,5);
 	insertAtHead(head,4);
 	insertAtHead(head,3);
 	insertAtMiddle(head,7,1);
 	insertAtTail(head,6);
 	deleteAtMiddle(head,2);
 	deleteAtTail(head);
 	deleteAtHead(head);
 	print(head);
 	return 0;
 }