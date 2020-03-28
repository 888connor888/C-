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

void reverse(node*&head){
	node*current = head;
	node*previous = NULL;
	node*Next;
	while(current != NULL){
		// First Save The Next Node.
		Next = current->next;
		// Make Current Node Point to Previous.
		current->next = previous;
		// Update Previous and Current.
		previous = current;
		current = Next;
	}
	head = previous;
}

int main(){
	node* head1 = NULL;
	cin>>head1;
	cout<<head1;
	reverse(head1);
	cout<<head1;
	return 0;
}