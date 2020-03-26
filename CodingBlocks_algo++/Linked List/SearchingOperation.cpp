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

bool recursiveSearch(node*head,const int key){
	if(head == NULL) return false;
	if(head->data == key) return true;
    return recursiveSearch(head->next,key);
}

bool iterativeSearch(node*head,const int key){
	while(head != NULL){
		if(head->data == key) return true;
		else if(head->next == NULL && head->data != key) return false;
	    head = head->next;
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

int main(){
	node*head = NULL;
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtTail(head,5);
	insertAtTail(head,7);
	insertAtMiddle(head,9,2);
	Print(head);
	if(recursiveSearch(head,5)) cout<<"Element Present"<<endl;
    if(iterativeSearch(head,5)) cout<<"Element Found"<<endl;
    return 0;
}